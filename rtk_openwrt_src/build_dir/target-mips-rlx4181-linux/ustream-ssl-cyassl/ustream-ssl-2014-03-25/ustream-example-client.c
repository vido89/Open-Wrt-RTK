#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <libubox/usock.h>
#include <libubox/uloop.h>
#include "ustream-ssl.h"

static struct uloop_fd fd;

static struct ustream_fd stream, s_input;
static struct ustream_ssl ssl;
static const char *host, *port;

static void *ctx;

static void client_teardown(void)
{
	if (s_input.fd.registered)
		ustream_free(&s_input.stream);

	ustream_free(&ssl.stream);
	ustream_free(&stream.stream);
	close(stream.fd.fd);
	uloop_end();
}

static void client_input_notify_read(struct ustream *s, int bytes)
{
	char *buf;
	int len;

	buf = ustream_get_read_buf(s, &len);
	ustream_write(&ssl.stream, buf, len, false);
	ustream_consume(s, len);
}

static void client_ssl_notify_read(struct ustream *s, int bytes)
{
	char *buf;
	int len;

	buf = ustream_get_read_buf(s, &len);
	fwrite(buf, len, 1, stdout);
	fflush(stdout);
	ustream_consume(s, len);
}

static void client_notify_connected(struct ustream_ssl *ssl)
{
	fprintf(stderr, "SSL connection established (CN verified: %d)\n", ssl->valid_cn);
	s_input.stream.notify_read = client_input_notify_read;
	ustream_fd_init(&s_input, 0);
}

static void client_notify_error(struct ustream_ssl *ssl, int error, const char *str)
{
	fprintf(stderr, "SSL connection error(%d): %s\n", error, str);
	client_teardown();
}

static void client_notify_verify_error(struct ustream_ssl *ssl, int error, const char *str)
{
	fprintf(stderr, "WARNING: SSL certificate error(%d): %s\n", error, str);
}

static void client_notify_state(struct ustream *us)
{
	if (!us->write_error && !us->eof)
		return;

	fprintf(stderr, "Connection closed\n");
	client_teardown();
}

static void example_connect_ssl(int fd)
{
	fprintf(stderr, "Starting SSL negnotiation\n");

	ssl.notify_error = client_notify_error;
	ssl.notify_verify_error = client_notify_verify_error;
	ssl.notify_connected = client_notify_connected;
	ssl.stream.notify_read = client_ssl_notify_read;
	ssl.stream.notify_state = client_notify_state;

	ustream_fd_init(&stream, fd);
	ustream_ssl_init(&ssl, &stream.stream, ctx, false);
	ustream_ssl_set_peer_cn(&ssl, host);
}

static void example_connect_cb(struct uloop_fd *f, unsigned int events)
{
	if (fd.eof || fd.error) {
		fprintf(stderr, "Connection failed\n");
		uloop_end();
		return;
	}

	fprintf(stderr, "Connection established\n");
	uloop_fd_delete(&fd);
	example_connect_ssl(fd.fd);
}

static void connect_client(void)
{
	fd.fd = usock(USOCK_TCP | USOCK_NONBLOCK, host, port);
	fd.cb = example_connect_cb;
	uloop_fd_add(&fd, ULOOP_WRITE | ULOOP_EDGE_TRIGGER);
}

static int usage(const char *progname)
{
	fprintf(stderr,
		"Usage: %s [options] <hostname> <port>\n"
		"Options:\n"
		"	-c <cert>:         Load CA certificates from file <cert>\n"
		"\n", progname);
	return 1;
}

int main(int argc, char **argv)
{
	const char *progname = argv[0];
	int ch;

	ctx = ustream_ssl_context_new(false);

	while ((ch = getopt(argc, argv, "c:")) != -1) {
		switch(ch) {
		case 'c':
			ustream_ssl_context_add_ca_crt_file(ctx, optarg);
			break;
		default:
			return usage(progname);
		}
	}

	argv += optind;
	argc -= optind;

	if (argc != 2)
		return usage(progname);

	uloop_init();
	host = argv[0];
	port = argv[1];
	connect_client();
	uloop_run();

	close(fd.fd);
	uloop_done();
	return 0;
}

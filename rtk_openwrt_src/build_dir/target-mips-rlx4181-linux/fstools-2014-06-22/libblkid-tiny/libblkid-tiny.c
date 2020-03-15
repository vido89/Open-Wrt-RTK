#include <stdio.h>
#include <sys/utsname.h>

#include "superblocks.h"
#include "linux_version.h"

#if 0
#define DEBUG(fmt, ...)	printf(fmt, __VA_ARGS__)
#else
#define DEBUG(fmt, ...)
#endif

int blkid_debug_mask = 0;

static unsigned char *probe_buffer;
static unsigned int probe_buffer_size = 0;

int get_linux_version (void)
{
	static int kver = -1;
	struct utsname uts;
	int major = 0;
	int minor = 0;
	int teeny = 0;
	int n;

	if (kver != -1)
		return kver;
	if (uname (&uts))
		return kver = 0;

	n = sscanf(uts.release, "%d.%d.%d", &major, &minor, &teeny);
	if (n < 1 || n > 3)
		return kver = 0;

	return kver = KERNEL_VERSION(major, minor, teeny);
}

int blkid_probe_is_tiny(blkid_probe pr)
{
	/* never true ? */
	return 0;
}

int blkid_probe_set_value(blkid_probe pr, const char *name,
                unsigned char *data, size_t len)
{
	/* empty stub */
	return 0;
}

int blkid_probe_set_version(blkid_probe pr, const char *version)
{
	int len = strlen(version);
	if (len > (sizeof(pr->version) - 1)) {
		fprintf(stderr, "version buffer too small %d\n", len);
		return -1;
	}

	strncpy(pr->version, version, sizeof(pr->version));

	return 0;
}

int blkid_probe_sprintf_version(blkid_probe pr, const char *fmt, ...)
{
	va_list ap;
	int n;

	va_start(ap, fmt);
	n = vsnprintf(pr->version, sizeof(pr->version), fmt, ap);
	va_end(ap);

	if (n >= sizeof(pr->version))
		fprintf(stderr, "version buffer too small %d\n", n);

	return 0;
}

unsigned char *blkid_probe_get_buffer(blkid_probe pr,
				blkid_loff_t off, blkid_loff_t len)
{
	int ret;
	unsigned char *buf;

	if (len > probe_buffer_size) {
		buf = realloc(probe_buffer, len);

		if (!buf) {
			fprintf(stderr, "failed to allocate %d byte buffer\n",
			        (int)len);

			return NULL;
		}

		probe_buffer = buf;
		probe_buffer_size = len;
	}

	memset(probe_buffer, 0, probe_buffer_size);

	lseek(pr->fd, off, SEEK_SET);
	ret = read(pr->fd, probe_buffer, len);

	if (ret != len)
		fprintf(stderr, "faile to read blkid\n");

	return probe_buffer;
}

int blkid_probe_set_label(blkid_probe pr, unsigned char *label, size_t len)
{
	if (len > (sizeof(pr->label) - 1)) {
		fprintf(stderr, "label buffer too small %d > %d\n",
			(int) len, (int) sizeof(pr->label) - 1);
		return -1;
	}
	memcpy(pr->label, label, len + 1);

	return 0;
}

int blkid_probe_set_uuid_as(blkid_probe pr, unsigned char *uuid, const char *name)
{
	short unsigned int*u = (short unsigned int*) uuid;

	if (u[0])
		sprintf(pr->uuid,
			"%04x%04x-%04x-%04x-%04x-%04x%04x%04x",
			be16_to_cpu(u[0]), be16_to_cpu(u[1]), be16_to_cpu(u[2]), be16_to_cpu(u[3]),
			be16_to_cpu(u[4]), be16_to_cpu(u[5]), be16_to_cpu(u[6]), be16_to_cpu(u[7]));
	if (name)
		strncpy(pr->name, name, sizeof(pr->name));

	return 0;
}

int blkid_probe_set_uuid(blkid_probe pr, unsigned char *uuid)
{
	return blkid_probe_set_uuid_as(pr, uuid, NULL);
}

int blkid_probe_sprintf_uuid(blkid_probe pr, unsigned char *uuid,
			     size_t len, const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	vsnprintf(pr->uuid, sizeof(pr->uuid), fmt, ap);
	va_end(ap);

	return 0;
}

static const struct blkid_idinfo *idinfos[] =
{
	&vfat_idinfo,
	&swsuspend_idinfo,
	&swap_idinfo,
	&ext4dev_idinfo,
	&ext4_idinfo,
	&ext3_idinfo,
	&ext2_idinfo,
	&jbd_idinfo,
	&squashfs_idinfo,
	&ubifs_idinfo,
	&jffs2_idinfo,
	&hfsplus_idinfo,
	&hfs_idinfo,
};

int probe_block(char *block, struct blkid_struct_probe *pr)
{
	struct stat s;
	int i;

	if (stat(block, &s) || (!S_ISBLK(s.st_mode) && !S_ISREG(s.st_mode)))
		return -1;

	pr->err = -1;
	pr->fd = open(block, O_RDONLY);
	if (!pr->fd)
		return -1;

	for (i = 0; i < ARRAY_SIZE(idinfos); i++) {
		/* loop over all magic handlers */
		const struct blkid_idmag *mag;

		/* loop over all probe handlers */
		DEBUG("scanning %s\n", idinfos[i]->name);

		mag = &idinfos[i]->magics[0];

		while (mag->magic) {
			int off = (mag->kboff * 1024) + mag->sboff;
			char magic[32] = { 0 };

			lseek(pr->fd, off, SEEK_SET);
			read(pr->fd, magic, mag->len);

			DEBUG("magic: %s %s %d\n", mag->magic, magic, mag->len);
			if (!memcmp(mag->magic, magic, mag->len))
				break;
			mag++;
		}

		if (mag && mag->magic) {
			DEBUG("probing %s\n", idinfos[i]->name);
			pr->err = idinfos[i]->probefunc(pr, mag);
			pr->id = idinfos[i];
			strcpy(pr->dev, block);
			if (!pr->err)
				break;
		}
	}

	close(pr->fd);

	return 0;
}

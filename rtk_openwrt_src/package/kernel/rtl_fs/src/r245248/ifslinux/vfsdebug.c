/*++


Module Name:

    vfsdebug.c

Abstract:

    This module implements UFSD debug subsystem

Author:

    Ahdrey Shedel

Revision History:

    18/09/2000 - Andrey Shedel - Created
    Since 29/07/2005 - Alexander Mamaev

--*/

#include <linux/version.h>
#include <linux/kernel.h>
#include <linux/string.h>
#include <linux/fs.h>
#include <linux/slab.h>
#include <linux/mm.h>
#include <asm/uaccess.h>
#include <linux/sched.h>

#include "config.h"
#include "ufsdapi.h"

//
// Endianess test
//
static const unsigned short szTstEnd[3] __attribute__ ((used)) = {0x694C,0x4274,0x6769};

#ifdef UFSD_TRACE

char ufsd_trace_level_[16] = {0};

//
// Activate this define to build driver with predefined trace and log
//
// #define UFSD_DEFAULT_LOGTO  "/ufsd/ufsd.log"

#ifdef UFSD_DEFAULT_LOGTO
  char ufsd_trace_file[128]       = UFSD_DEFAULT_LOGTO;
  unsigned long ufsd_trace_level  = ~(UFSD_LEVEL_VFS_WBWE|UFSD_LEVEL_MEMMNGR|UFSD_LEVEL_IO|UFSD_LEVEL_UFSDAPI);
  unsigned long ufsd_cycle_mb     = 25;
#else
  char ufsd_trace_file[128]       = "";
  unsigned long ufsd_trace_level  = UFSD_LEVEL_DEFAULT;
  unsigned long ufsd_cycle_mb     = 0;
#endif

static atomic_t ufsd_trace_indent;
static struct file *log_file;
static int log_file_opened;
static int log_file_error;
static int indent_printed;

static void ufsd_vlog( const char *fmt, va_list ap );
static void ufsd_log( const char *fmt, int len );

//
// Function implemented in ufsdvfs.c
//
void trace_hdr( void );

//#define UFSD_ACTIVATE_KEEP_TRACE_ON

#ifdef UFSD_ACTIVATE_KEEP_TRACE_ON

extern struct mutex   s_MountMutex;
static int        s_KeepLogs;
static atomic_t   s_LogCnt;
#define MAX_LOG_CNT   10000
static LIST_HEAD( s_MountStr );
static DEFINE_SPINLOCK( s_TraceSpin ); // to protect s_MountStr

struct str_entry{
  struct list_head entry;
  int     len;
  char    buf[1];
};


///////////////////////////////////////////////////////////
// ufsd_keep_trace_on
//
// activate trace keep. Called from fill_super after locking s_MountMutex
///////////////////////////////////////////////////////////
void
ufsd_keep_trace_on( void )
{
  assert( mutex_is_locked( &s_MountMutex ) );
  assert( 0 == s_KeepLogs );
  s_KeepLogs  = 1;
  atomic_set( &s_LogCnt, 0 );
}


///////////////////////////////////////////////////////////
// ufsd_keep_trace_off
//
// deactivate trace keep. Called from fill_super before unlocking s_MountMutex
///////////////////////////////////////////////////////////
void
ufsd_keep_trace_off(
    IN int print_logs
    )
{
  assert( mutex_is_locked( &s_MountMutex ) );
  s_KeepLogs = 0;

  spin_lock( &s_TraceSpin );
  while( !list_empty( &s_MountStr ) ) {
    struct str_entry* e = list_entry( s_MountStr.next, struct str_entry, entry );
    list_del( &e->entry );
    spin_unlock( &s_TraceSpin );

    if ( print_logs )
      ufsd_log( e->buf, e->len );

    kfree( e );
    spin_lock( &s_TraceSpin );
  }

  spin_unlock( &s_TraceSpin );
}
#endif // #ifdef UFSD_ACTIVATE_KEEP_TRACE_ON


///////////////////////////////////////////////////////////
// ufsd_trace_inc
//
//
///////////////////////////////////////////////////////////
UFSDAPI_CALL void
ufsd_trace_inc(
    IN int indent
    )
{
  atomic_add( indent, &ufsd_trace_indent );
}


///////////////////////////////////////////////////////////
// ufsd_log
//
// The main logging function
///////////////////////////////////////////////////////////
static void
ufsd_log(
    IN const char *fmt,
    IN int len
    )
{
  if ( len <= 0 || 0 == fmt[0] )
    return;

#ifdef UFSD_ACTIVATE_KEEP_TRACE_ON
  if ( s_KeepLogs && mutex_is_locked( &s_MountMutex ) ) {
    //
    // This function may be called from different threads
    //
    if ( atomic_inc_return( &s_LogCnt ) < MAX_LOG_CNT ) {
      struct str_entry* e = (struct str_entry*)kmalloc( len + offsetof(struct str_entry, buf) + 1, GFP_KERNEL );
      if ( NULL != e ) {
        spin_lock( &s_TraceSpin );
        list_add_tail( &e->entry, &s_MountStr );
        spin_unlock( &s_TraceSpin );
        e->len = len;
        memcpy( e->buf, fmt, len );
        e->buf[len] = 0;
      }
    }
    return;
  }
#endif

  if ( !log_file_opened && 0 != ufsd_trace_file[0] ) {
    log_file_opened = 1;
    log_file = filp_open( ufsd_trace_file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUGO | S_IWUGO );
    if ( IS_ERR(log_file) ) {
      long error = PTR_ERR(log_file);
      log_file = NULL;
      printk( KERN_NOTICE  QUOTED_UFSD_DEVICE": failed to start log to '%s' (errno=%ld), using system log\n", ufsd_trace_file, -error );
    } else {
      assert(NULL != log_file);
      trace_hdr();
    }
  }

  if ( NULL != log_file && NULL != log_file->f_op && NULL != log_file->f_op->write && !log_file_error && !( current->flags & (PF_MEMALLOC|PF_KSWAPD) ) ) {

    mm_segment_t old_limit = get_fs();
    long error = 0;

    set_fs( KERNEL_DS );

    if ( 0 != ufsd_cycle_mb ) {
      size_t bytes = ufsd_cycle_mb << 20;
      int to_write = log_file->f_pos + len > bytes? (bytes - log_file->f_pos) : len;
      assert( to_write >= 0 );
      if ( to_write <= 0 )
        to_write = 0;
      else {
        error = log_file->f_op->write(log_file, fmt, to_write, &log_file->f_pos);
        if ( error < 0 )
          log_file_error = error;
        fmt += to_write;
        len -= to_write;
      }

      if ( 0 != len )
        log_file->f_pos = 0;
    }

    if ( 0 != len ) {
      error = log_file->f_op->write(log_file, fmt, len, &log_file->f_pos );
      if ( error < 0 )
        log_file_error = error;
    }

    set_fs( old_limit );

    if ( error < 0 )
      printk( "log write failed: %ld\n", -error );
  } else {
//    printk( KERN_NOTICE  QUOTED_UFSD_DEVICE":%*.s", len, fmt );
    printk( KERN_NOTICE  QUOTED_UFSD_DEVICE":%s", fmt );
  }
}


///////////////////////////////////////////////////////////
// ufsd_close_trace
//
//
///////////////////////////////////////////////////////////
void
ufsd_close_trace( void )
{
  if ( NULL != log_file ){
    filp_close( log_file, NULL );
    log_file = NULL;
    log_file_error = 0;
    log_file_opened = 0;
    indent_printed = 0;
    atomic_set( &ufsd_trace_indent, 0 );
  }
}


///////////////////////////////////////////////////////////
// _UFSDTrace
//
//
///////////////////////////////////////////////////////////
UFSDAPI_CALLv void
_UFSDTrace( const char *fmt, ... )
{
  va_list ap;
  va_start( ap,fmt );
  ufsd_vlog( fmt, ap );

  // bug on asserts
//  BUG_ON( '*' == fmt[0] && '*' == fmt[1] && '*' == fmt[2] && '*' == fmt[3] );
  if ( '*' == fmt[0] && '*' == fmt[1] && '*' == fmt[2] && '*' == fmt[3] ) {
    printk( "%s: ", current->comm );
    //
    // sometimes it is required to init 'ap' again
    // I have no ideas why it is necessary but this solution works in all cases
    //
    va_end( ap );
    va_start( ap,fmt );
    vprintk( fmt, ap );
  }
  va_end( ap );
}


///////////////////////////////////////////////////////////
// UFSDError
//
//
///////////////////////////////////////////////////////////
UFSDAPI_CALL void
UFSDError( int Err, const char *FileName, int Line )
{
  long Level = ufsd_trace_level;
  const char *Name = strrchr( FileName, '/' );
  if ( NULL == Name )
    Name = FileName - 1;

  ufsd_trace_level |= UFSD_LEVEL_ERROR | UFSD_LEVEL_UFSD;
  // Print the line number first 'cause the full name can be too long
  DebugTrace(0, UFSD_LEVEL_ERROR, ("\"%s\": UFSD error 0x%x, %d, %s\n", current->comm, Err, Line, Name + 1));
  ufsd_trace_level = Level;
//  BUG_ON( 1 );
}


///////////////////////////////////////////////////////////
// ufsd_vlog
//
//
///////////////////////////////////////////////////////////
static void
ufsd_vlog(
    IN const char *fmt,
    IN va_list    ap
    )
{
  char buf[160];
  int len = atomic_read( &ufsd_trace_indent );

  if ( len < 0 ) {
    //
    // Don't assert( len < 0 ): - it calls _UFSDTrace -> ufsd_vlog -> assert -> _UFSDTrace -> ufsd_vlog ->....
    //
    if ( !indent_printed ) {
      indent_printed = 1;
      ufsd_log( "*** trace_indent < 0\n", sizeof("*** trace_indent < 0\n")-1 );
    }
    len = 0;
  } else if ( len > 0 ) {
    len %= 20;
    memset( buf, ' ', len );
  }

  len += vsnprintf( buf + len, sizeof(buf) - len, fmt, ap );

  if ( len > sizeof(buf) ) {
    len = sizeof(buf);
    buf[sizeof(buf)-3] = '.';
    buf[sizeof(buf)-2] = '.';
    buf[sizeof(buf)-1] = '\n';
  }

  if ( '\5' == fmt[0] )
    printk( KERN_NOTICE  QUOTED_UFSD_DEVICE":%s", fmt + 1 );
  else {

    if ( '*' == fmt[0] && '*' == fmt[1] && '*' == fmt[2] && '*' == fmt[3] && len < sizeof(buf) ) {
      int ln = strlen( current->comm );
      if ( ln + len >= sizeof(buf) )
        ln = sizeof(buf) - len - 1;
      if ( ln > 0 ) {
        memmove( buf + ln, buf, len + 1 );
        memcpy( buf, current->comm, ln );
        len += ln;
      }
    }

    ufsd_log( buf, len );
  }
}

#endif // #ifdef UFSD_TRACE


#ifdef UFSD_DEBUG

///////////////////////////////////////////////////////////
// ufsd_dump_stack
//
// Sometimes it is usefull to call this function from library
///////////////////////////////////////////////////////////
UFSDAPI_CALL void
ufsd_dump_stack( void )
{
  dump_stack();
}


static long ufsd_trace_level_Old;
///////////////////////////////////////////////////////////
// ufsd_turn_on_trace_level
//
//
///////////////////////////////////////////////////////////
UFSDAPI_CALL void
ufsd_turn_on_trace_level( void )
{
  ufsd_trace_level_Old = ufsd_trace_level;
  ufsd_trace_level = -1;
}


///////////////////////////////////////////////////////////
// ufsd_revert_trace_level
//
//
///////////////////////////////////////////////////////////
void UFSDAPI_CALL
ufsd_revert_trace_level( void )
{
  ufsd_trace_level  = ufsd_trace_level_Old;
}


///////////////////////////////////////////////////////////
// is_zero
//
//
///////////////////////////////////////////////////////////
int
is_zero(
    IN const char *data,
    IN size_t     bytes
    )
{
  if ( 0 == (((size_t)data)%sizeof(int)) ) {
    while( bytes >= sizeof(int) ) {
      if ( 0 != *(int*)data )
        return 0;
      bytes -= sizeof(int);
      data  += sizeof(int);
    }
  }

  while( 0 != bytes-- ) {
    if ( 0 != *data++ )
      return 0;
  }
  return 1;
}

#if 0
#include <linux/buffer_head.h>
///////////////////////////////////////////////////////////
// ufsd_trace_page_buffers
//
//
///////////////////////////////////////////////////////////
void
ufsd_trace_page_buffers(
    IN struct page  *page,
    IN int          hdr
    )
{
  if ( hdr ) {
    DebugTrace(+1, UFSD_LEVEL_PAGE_BH, ("p=%p f=%lx:\n", page, page->flags ));
  } else if ( ufsd_trace_level & UFSD_LEVEL_PAGE_BH ) {
    ufsd_trace_inc( +1 );
  }

  if ( page_has_buffers( page ) ) {
    struct buffer_head *head  = page_buffers(page);
    struct buffer_head *bh    = head;
    char*d = kmap_atomic( page, KM_USER0 );

    do {
      int zero = is_zero( d + bh_offset( bh ), bh->b_size );
      if ( (sector_t)-1 == bh->b_blocknr ) {
        DebugTrace( 0, UFSD_LEVEL_PAGE_BH, ("bh=%p,%lx%s\n", bh, bh->b_state, zero? ", z":"") );
      } else {
        DebugTrace( 0, UFSD_LEVEL_PAGE_BH, ("bh=%p,%lx,%"PSCT"x%s\n", bh, bh->b_state, bh->b_blocknr, zero? ", z":"" ) );
      }
      bh = bh->b_this_page;
    } while( bh != head );

    kunmap_atomic( d, KM_USER0 );
  } else {
    DebugTrace(0, UFSD_LEVEL_PAGE_BH, ("no buffers\n" ));
  }

  if ( ufsd_trace_level & UFSD_LEVEL_PAGE_BH )
    ufsd_trace_inc( -1 );
}

#include <linux/pagevec.h>
///////////////////////////////////////////////////////////
// trace_pages
//
//
///////////////////////////////////////////////////////////
unsigned
trace_pages(
    IN struct address_space *mapping
    )
{
  struct pagevec pvec;
  pgoff_t next = 0;
  unsigned Ret = 0;
  unsigned long i;

  pagevec_init( &pvec, 0 );

  while ( pagevec_lookup( &pvec, mapping, next, PAGEVEC_SIZE ) ) {
    for ( i = 0; i < pvec.nr; i++ ) {
      struct page *page = pvec.pages[i];
      void *d = kmap_atomic( page, KM_USER0 );
      DebugTrace( 0, UFSD_LEVEL_VFS, ("p=%p o=%llx f=%lx%s\n", page, (UINT64)page->index << PAGE_CACHE_SHIFT, page->flags, is_zero( d, PAGE_CACHE_SIZE )?", zero" : "" ));
      ufsd_trace_page_buffers( page, 0 );
      kunmap_atomic( d, KM_USER0 );
      if ( page->index > next )
        next = page->index;
      Ret += 1;
      next += 1;
    }
    pagevec_release(&pvec);
  }
  if ( 0 == next )
    DebugTrace( 0, UFSD_LEVEL_VFS, ("no pages\n"));
  return Ret;
}


///////////////////////////////////////////////////////////
// trace_page
//
//
///////////////////////////////////////////////////////////
void
trace_page(
    IN struct address_space *mapping,
    IN pgoff_t index
    )
{
  struct pagevec pvec;
  unsigned long i;

  pagevec_init( &pvec, 0 );

  if ( pagevec_lookup( &pvec, mapping, index, PAGEVEC_SIZE ) ) {
    for ( i = 0; i < pvec.nr; i++ ) {
      struct page *page = pvec.pages[i];
      if ( page->index == index ) {
        char *d = kmap_atomic( page, KM_USER0 );
        DebugTrace( 0, UFSD_LEVEL_VFS, ("p=%p o=%llx f=%lx%s\n", page, (UINT64)page->index << PAGE_CACHE_SHIFT, page->flags, is_zero( d, PAGE_CACHE_SIZE )?", zero" : "" ));
        ufsd_trace_page_buffers( page, 0 );
        kunmap_atomic( d, KM_USER0 );
      }
    }
    pagevec_release(&pvec);
  }
}


///////////////////////////////////////////////////////////
// ufsd_drop_pages
//
//
///////////////////////////////////////////////////////////
void
ufsd_drop_pages(
    IN struct address_space *m
    )
{
  filemap_fdatawrite( m );
  unmap_mapping_range( m, 0, 0, 1 );
  truncate_inode_pages( m, 0 );
  unmap_mapping_range( m, 0, 0, 1 );
}


struct bio_batch {
  atomic_t          done;
  unsigned long     flags;
  struct completion *wait;
};

static void bio_end_io( struct bio *bio, int err )
{
  struct bio_batch *bb = bio->bi_private;
  struct bio_vec *bvec = &bio->bi_io_vec[bio->bi_vcnt-1];
  int error  = !test_bit( BIO_UPTODATE, &bio->bi_flags );
  if ( error ){
    ufsd_printk( NULL, "bio read I/O error." );
  }

  do {
    struct page *page = bvec->bv_page;
    if ( !error ) {
      SetPageUptodate( page );
    } else {
      ClearPageDirty( page );
      SetPageError( page );
    }
    unlock_page( page );
  } while ( --bvec >= bio->bi_io_vec );

  if ( err && EOPNOTSUPP != err )
    clear_bit( BIO_UPTODATE, &bb->flags );
  if ( atomic_dec_and_test( &bb->done ) )
    complete( bb->wait );

  bio_put( bio );

  printk( "bio_end_io %d\n", error );
}


///////////////////////////////////////////////////////////
// ufsd_bd_check
//
///////////////////////////////////////////////////////////
int
UFSDAPI_CALL
ufsd_bd_check(
    IN struct super_block *sb
    )
{
  int err;
  struct bio_batch bb;
  struct page *page = alloc_page( GFP_KERNEL | __GFP_ZERO );
  struct bio *bio;
#ifdef DECLARE_COMPLETION_ONSTACK
  DECLARE_COMPLETION_ONSTACK( wait );
#else
  DECLARE_COMPLETION( wait );
#endif

  if ( NULL == page )
    return -ENOMEM;

  atomic_set( &bb.done, 1 );
  err       = 0;
  bb.flags  = 1 << BIO_UPTODATE;
  bb.wait   = &wait;

  bio = bio_alloc( GFP_NOFS, 1 );
  if ( !bio ) {
    err = -ENOMEM;
    goto out;
  }

  bio->bi_sector  = 0x7379;
  bio->bi_bdev    = sb->s_bdev;
  bio->bi_end_io  = bio_end_io;
  bio->bi_private = &bb;

  {
    char* kmap = atomic_kmap( page );
    memset( kmap, -1, PAGE_SIZE );
    atomic_kunmap( kmap );
  }

  bio_add_page( bio, page, 0x200, 0 );

  atomic_inc( &bb.done );
  submit_bio( READ, bio );

  if ( !atomic_dec_and_test( &bb.done ) )
    wait_for_completion( &wait );

  err = 0;
  {
    unsigned char* kmap = atomic_kmap( page );
    ufsdapi_dump_memory( kmap, 0x20 );
    if ( 0xC0 == kmap[0] )
      err = 1;
    atomic_kunmap( kmap );
  }

out:
  __free_page( page );
  return err;
}

#endif

#endif // #ifdef UFSD_DEBUG



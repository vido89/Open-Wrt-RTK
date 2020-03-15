/* config.h.  Generated from config.h.in by configure.  */
/* config.h.in.  Generated from configure.in by autoheader.  */

/* Allow UNI 3.0 backwards-compatible extensions (if using UNI 3.1) */
/* #undef ALLOW_UNI30 */

/* Default config file location for atmsigd */
#define ATMSIGD_CONF "/etc/atmsigd.conf"

/* Use select() instead of poll() with MPOA */
#define BROKEN_POLL /**/

/* If you're using a Cisco LS100 or LS7010 switch, you should add the
   following line to work around a bug in their point-to-multipoint signaling
   (it got confused when receiving a CALL PROCEEDING, so we don't send it,
   which of course makes our clearing procedure slightly non-conformant): */
/* #undef CISCO */

/* The UNI version can be configured at run time. Dynamic is the default. Use
   the explicit version selections only in case of problems. */
#define DYNAMIC_UNI 1

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the `mpr' library (-lmpr). */
/* #undef HAVE_LIBMPR */

/* Define to 1 if you have the `resolv' library (-lresolv). */
#define HAVE_LIBRESOLV 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to the sub-directory in which libtool stores uninstalled libraries.
   */
#define LT_OBJDIR ".libs/"

/* Use proposed MPOA 1.1 features */
/* #undef MPOA_1_1 */

/* Point to multipoint signalling support for atmsigd. */
/* #undef MULTIPOINT */

/* Name of package */
#define PACKAGE "linux-atm"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT ""

/* Define to the full name of this package. */
#define PACKAGE_NAME ""

/* Define to the full name and version of this package. */
#define PACKAGE_STRING ""

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME ""

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION ""

/* If using UNI40, you can also enable peak cell rate modification as
   specified in Q.2963.1 */
/* #undef Q2963_1 */

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Some versions of the Thomson Thomflex 5000 won't do any signaling before
   they get a RESTART. Uncomment the next line to enable sending of a RESTART
   whenever SAAL comes up. Note that the RESTART ACKNOWLEDGE sent in response
   to the RESTART will yield a warning, because we don't implement the full
   RESTART state machine. */
/* #undef THOMFLEX */

/* */
/* #undef UNI30 */

/* Note: some UNI 3.0 switches will show really strange behaviour if
   confronted with using 3.1 signaling, so be sure to test your network *very*
   carefully before permanently configuring machines to use UNI 3.1. */
/* #undef UNI31 */

/* Some partial support for UNI 4.0 can be enabled by using UNI40 */
/* #undef UNI40 */

/* Version number of package */
#define VERSION "2.5.2"

/* Define to 1 if `lex' declares `yytext' as a `char *' by default, not a
   `char[]'. */
/* #undef YYTEXT_POINTER */

/* */
#define YY_USE_CONST /**/

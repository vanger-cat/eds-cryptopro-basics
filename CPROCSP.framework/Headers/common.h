#ifndef _COMMON_H_INCLUDED_
#define _COMMON_H_INCLUDED_

/* Code types for USE_CODE #define */
#define USE_CODE_C        1
#define USE_CODE_ASM_MSP5 2
#define USE_CODE_ASM_ATT  3

#ifdef HAVE_CONFIG_H
#include<CPROCSP/myconfig.h>
#elif !defined DEVL && !defined CSP_LITE && !defined _WIN64 && !defined WINCE/* no config.h :Windows или примеры из doxygen*/
# define USE_CODE USE_CODE_ASM_MSP5
/*# define USE_CODE USE_CODE_C*/
#if !defined(UNIX)
# define PATH_MAX MAX_PATH
#endif
# define HAVE_STDLIB_H 1
# define HAVE_LIMITS_H 1
#else
#if defined _WIN64 || defined WINCE
# define PATH_MAX MAX_PATH
# define USE_CODE USE_CODE_C
# define HAVE_STDLIB_H 1
# define HAVE_LIMITS_H 1 
#elif defined CSP_LITE
#if defined _WIN32
# define USE_CODE USE_CODE_ASM_MSP5
#else
# define USE_CODE USE_CODE_C
#endif
#else
# define USE_CODE USE_CODE_ASM_MSP5
#endif
#endif /* хотели Windows */

//TODO: У нас определений UNUSED(x) штук 20-30, и некоторые кривые
#ifndef UNUSED
    #define UNUSED(x) (void)(x)
#endif

#if defined DEBUG && !defined _DEBUG
#   define _DEBUG 1
#endif
#if defined _DEBUG && !defined DEBUG
# define DEBUG 1
#endif

/*#define UNICODE
#define _UNICODE
*/
#ifdef UNIX
#define _ANTI_STR _TEXT("%s")
#else
#define _ANTI_STR _TEXT("%S")
#endif

/* Security levels for SECURITY_LEVEL #define
 * Упорядочены по возрастанию. Так что нужно делать, например, так:
 *   #if SECURITY_LEVEL >= KB1
 */

#define KC1 1
#define KC2 2
#define KC3 3
#define KB1 4
#define KB2 5
#define KA1 6

#ifndef SECURITY_LEVEL
#define SECURITY_LEVEL KC1
#endif

/* Processor types for PROCESSOR_TYPE #define */
#define PROC_TYPE_SPARC 1
#define PROC_TYPE_I386  2
#define PROC_TYPE_X64	3
#define PROC_TYPE_PPC32	4
#define PROC_TYPE_PPC64	5
#define PROC_TYPE_ARM	6

#ifdef UNIX
# define PROCESS_TESTER 1
# define _POSIX_PTHREAD_SEMANTICS 1 /* Must be defined for pthreads */
# if !defined _REENTRANT
#   define _REENTRANT 1 /* Must be defined for pthreads */
# endif	/* !_REENTRANT */
# define CSP_NO_GUI 1 /* We don't have GUI writen yet */
# define SUPPORT_RESOURCE_STD 1 /* Should be default on UNIX */
# undef  CONFORMITY_SILENT /* we need bio rndm in TEST_CPdll/Conformity ... */
# define MAX_PATH PATH_MAX
# define Sleep(a) usleep(a*1000)
/* Some kind of cheating?  For pthread...settype __USE_UNIX98 must be defined */
# if defined LINUX
#  if !defined _XOPEN_SOURCE
#   define _XOPEN_SOURCE 700
#  endif /* !_XOPEN_SOURCE */
# endif /* LINUX */
#else /* UNIX */
# define X_DISPLAY_MISSING 1 /* We don't have X, do we? */
/* Компиляторы для _Win32 поддерживают MMX*/
# if USE_CODE==USE_CODE_ASM_MSP5
#   define HAVE_MMX_INSTRUCTIONS 1
# endif
#endif /* UNIX */

#if defined DEVL && !defined CSP_LITE
# define CSP_LITE 1
#endif
#ifdef CSP_LITE
# define EXCLUDE_READER 1
#endif

#define USE_CODE_ASM ((USE_CODE == USE_CODE_ASM_MSP5) || (USE_CODE == USE_CODE_ASM_ATT))
#ifdef UNIX
typedef struct __TSupCSPPaths__
{
    const char * csp_static_root;   /* CSP_STATIC_ROOT */
    const char * csp_etc_dir;       /* CSP_ETC_DIR */
    const char * csp_volatile_dir;  /* CSP_VOLATILE_ROOT */
    const char * csp_floppy_root;   /* CSP_FLOPPY_ROOT */
    const char * csp_users_dir;     /* CSP_USERS_DIR */
    const char * csp_dsrf_dir;	    /* CSP_DSRF_DIR */
    const char * csp_protected_dir; /* CSP_PROTECTED_DIR */
    const char * csp_bin_dir;	    /* CSP_BIN_DIR */
    const char * csp_cp1251_ldir;   /* CSP_CP1251_LDIR */
    const char * csp_cp866_ldir;    /* CSP_CP866_LDIR */
    const char * csp_def_ldir;	    /* CSP_DEF_LDIR */
    const char * csp_iso8859_ldir;  /* CSP_ISO88595_LDIR */
    const char * csp_koi8r_ldir;    /* CSP_KOI8R_LDIR */
    const char * csp_utf8_ldir;	    /* CSP_UTF8_LDIR */
    const char * csp_lib_dir;	    /* CSP_LIB_DIR */
    const char * csp_sbin_dir;	    /* CSP_SBIN_DIR */
} TSupCSPPaths;
#ifdef __cplusplus
extern "C" {
#endif
extern const TSupCSPPaths * csp_get_paths(void);
#ifdef __cplusplus
}
#endif
#define CSP_STATIC_ROOT	(csp_get_paths()->csp_static_root)
#define CSP_ETC_DIR	(csp_get_paths()->csp_etc_dir)
#define CSP_VOLATILE_ROOT	(csp_get_paths()->csp_volatile_dir)
#define CSP_FLOPPY_ROOT	(csp_get_paths()->csp_floppy_root)
#define CSP_USERS_DIR	(csp_get_paths()->csp_users_dir)
#define CSP_DSRF_DIR	(csp_get_paths()->csp_dsrf_dir)
#define CSP_PROTECTED_DIR	(csp_get_paths()->csp_protected_dir)
#define CSP_BIN_DIR	(csp_get_paths()->csp_bin_dir)
#define CSP_CP1251_LDIR	(csp_get_paths()->csp_cp1251_ldir)
#define CSP_CP866_LDIR	(csp_get_paths()->csp_cp866_ldir)
#define CSP_DEF_LDIR	(csp_get_paths()->csp_def_ldir)
#define CSP_ETC_DIR	(csp_get_paths()->csp_etc_dir)
#define CSP_ISO88595_LDIR	(csp_get_paths()->csp_iso8859_ldir)
#define CSP_KOI8R_LDIR	(csp_get_paths()->csp_koi8r_ldir)
#define CSP_UTF8_LDIR	(csp_get_paths()->csp_utf8_ldir)
#define CSP_LIB_DIR	(csp_get_paths()->csp_lib_dir)
#define CSP_SBIN_DIR	(csp_get_paths()->csp_sbin_dir)
#endif 

#endif /* _COMMON_H_INCLUDED_ */

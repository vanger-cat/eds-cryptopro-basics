/*
 * Copyright(C) 2000 Проект ИОК
 *
 * Этот файл содержит информацию, являющуюся
 * собственностью компании Крипто Про.
 *
 * Любая часть этого файла не может быть скопирована,
 * исправлена, переведена на другие языки,
 * локализована или модифицирована любым способом,
 * откомпилирована, передана по сети с или на
 * любую компьютерную систему без предварительного
 * заключения соглашения с компанией Крипто Про.
 */

/****
 * tchar.h: v.1.00
 *
 * Определения для работы со строками.
 *
 ****/

#if defined( _WIN32 ) && !defined ( CSP_LITE )
    #if defined ( WINCE )
	#define _TEXT(x)    __TEXT(x)
    #endif
    #include <tchar.h>
#elif !defined( _TCHAR_H )
#define _TCHAR_H


#ifndef CSP_LITE
    #include <string.h> /*+ Std include. +*/
    #if defined HAVE_STDLIB_H
	#include <stdlib.h>
	#include <stdarg.h>
    #endif
#endif /* CSP_LITE */

// Удалили не документированные _T() и __T()
#define TEXT(quote)	__TEXT(quote)
// TODO: переходить на
#define SUP_T(quote)	__TEXT(quote)
// TODO: TEXT(), _TEXT(), _T() и __T() объявить deprecated

#if !defined( UNICODE )

    #ifdef UNIX
	#ifndef CSP_LITE
	    #include <ctype.h>
	    #include <strings.h>
	#endif
	#define _tmain main
    #endif /* UNIX */

    /*+ TCHAR is char +*/
    #ifndef __TCHAR_DEFINED
    #define __TCHAR_DEFINED
	typedef char TCHAR;
	typedef int _TINT;
    #endif /* __TCHAR_DEFINED */

    /*+ _TEXT(x) defined as x +*/
    #define _TEXT( x /*+ (i) constant string +*/ ) x
    #define __TEXT(x) x

    #define _tcscpy strcpy
    #define _tcsncpy strncpy
    #define _tcslen strlen
    #define _tcsnlen strnlen
    #define _tcscat strcat
    #define _tcsncat strncat
    #define _tcscmp strcmp
    #define _tcsicmp _stricmp
    #define _tcsncmp strncmp
    #define _tcsnicmp _strnicmp
    #define _ttoi atoi
    #define _tcsstr strstr
    #define _tcsdup _strdup
    #define _tcschr strchr
    #define _tcsrchr strrchr
    #define _tcslwr strlwr
    #define _getts gets
    #if defined(WIN32)
       	#define _stprintf _sprintf
    #else
       	#define _stprintf sprintf
    #endif /* WIN32 */
    #define _vtprintf vprintf
    #define _vftprintf vfprintf
    #define _tcstol strtol
    #define _tcstok strtok
    #define _ttol atol
    #define _tcstoul strtoul
    #define _tasctime asctime
    #define _stscanf sscanf
    #define _tcsupr _strupr

    #if defined( _WIN32 ) && defined ( CSP_LITE )
       	#define support_vsntprintf support_vsnprintf
       	#define support_sntprintf support_snprintf
       	#define _vsntprintf support_vsntprintf
       	#define _sntprintf support_sntprintf
    #else
       	#define _vsntprintf _vsnprintf
    #endif

    #if defined( CSP_LITE ) && defined( UNIX )
	#define _sntprintf _snprintf
    #elif defined ( CSP_LITE ) && defined( _WIN32 )
	#define _sntprintf support_sntprintf
    #else
	#define _sntprintf snprintf
    #endif

    #ifdef UNIX
       	#define _tcstoi64 strtoll
    #else /* UNIX */
	#define _tcstoi64 _strtoi64
    #endif /* UNIX */
    #define _istdigit isdigit
    #define _istxdigit isxdigit
    #define _istlower islower
    #define _totlower tolower
    #define _totupper toupper
    #define _tprintf printf
    #define _fgetts fgets
    #define _istspace isspace
    #define _istascii isascii
    #define _istprint isprint
    #define _fputts fputs
    #define _putts puts
    #define _tremove remove
    #define _trename rename
    #define _tgetenv getenv
    #define _tfopen fopen
    #define _ftprintf fprintf
    #define _tchmod _chmod
    #define _gettchar getchar
    #define _trmdir _rmdir
    #ifdef UNIX
       	#define _ltot(l, str, radix) sprintf((str),"%ld",(l))
       	#define _i64tot(ll, str, radix) sprintf((str),"%lld",(ll))
    #else /* UNIX */
       	#define _ltot _ltoa
       	#define _i64tot _i64toa
    #endif /* UNIX */
    #define _istalnum isalnum
    #define _tfdopen _fdopen
    #define _ttmpnam tmpnam

    #ifdef UNIX
       	#define _stricmp strcasecmp
       	#define _strnicmp strncasecmp
       	#define _strdup strdup
       	#ifndef CSP_LITE
	    static inline char *strlwr(char *a) {
		char *res = a;
		
		if(NULL == a){
		    return NULL;
		}
		while(*a){
		    *a = (char)tolower( (*a) & 0xff );
		    a++;
		}
		return res;
	    }
	    #define _vsnprintf vsnprintf
	    #define _snprintf snprintf
       	#endif /* CSP_LITE */

       	#define _chmod chmod
       	#define _strlwr strlwr
       	#define _fdopen fdopen
       	#define _rmdir rmdir
       	#define _tmkdir(p, mode) mkdir(p, mode)
       	#define _tstat stat

		/* MS VS TCHAR of ISO/IEC TR 24731-1 */
	#define _stprintf_s	sprintf_s
	#define _tcsncpy_s	strncpy_s
	#define _tcscpy_s	strcpy_s
    #else /* UNIX */
       	#define _tmkdir(p, mode) _mkdir(p)
       	#define _tfinddata_t _finddata_t
       	#define _tfindfirst _findfirst
       	#define _tfindnext _findnext
       	#define _tfindclose _findclose
    #endif /* UNIX */

#else /* _UNICODE */
    #ifndef CSP_LITE
	#include <wchar.h>
    #endif

    /*+ TCHAR is char +*/
    #ifndef __TCHAR_DEFINED
    #define __TCHAR_DEFINED
       	typedef wchar_t TCHAR;
       	typedef wint_t _TINT;
    #endif /* __TCHAR_DEFINED */

    /*+ _TEXT(x) defined as x +*/
    #define _TEXT( x /*+ (i) constant string +*/ ) L ## x
    #define __TEXT(x) L##x

    #if defined( _WIN32 ) && defined ( CSP_LITE )
	#define support_vsntprintf support_vsnwprintf
	#define support_sntprintf support_snwprintf
	#define _vsntprintf support_vsntprintf
	#define _sntprintf support_sntprintf
	extern int support_vsnwprintf( wchar_t * str, size_t size, const wchar_t * format, va_list ap );
	extern int support_snwprintf( wchar_t * str, size_t size, const wchar_t * format, ... );
    #else
	#define _sntprintf _snwprintf
	#define _vsntprintf _vsnwprintf
    #endif

    #define _tcscpy wcscpy
    #define _tcsncpy wcsncpy
    #define _tcslen wcslen
    #define _tcsnlen wcsnlen
    #define _tcscat wcscat
    #define _tcsncat wcsncat
    #define _tcscmp wcscmp
    #define _tcsicmp _wcsicmp
    #define _tcsncmp wcsncmp
    #define _tcsnicmp _wcsnicmp
    #define _ttoi wtoi
    #define _tcsstr wcsstr
    #define _tcsdup wcsdup
    #define _tcschr wcschr
    #define _tcsrchr wcsrchr
    #define _tcslwr wcslwr
    #define _getts wgets
    #define _stprintf swprintf
    #define _vtprintf vwprintf
    #define _vftprintf vfwprintf
    #define _tcstol wcstol
    #define _ttol _wtol
    #define _tcstoul wcstoul
    #define _tasctime _wasctime


    #define _tcstoi64 _wcstoi64
    #define _istdigit isdigit
    #define _istxdigit iswdigit
    #define _istlower iswlower
    #define _totlower towlower
    #define _totupper towupper
    #define _tprintf wprintf
    #define _fgetts fgetws
    #define _istspace iswspace
    #define _istascii iswascii
    #define _istprint iswprint
    #define _fputts fputws
    #define _putts putws
    #define _tremove _wremove
    #define _trename _wrename
    #define _tgetenv _wgetenv
    #define _tfopen _wfopen
    #define _ftprintf fwprintf
    #define _tchmod _wchmod
    #define _gettchar getwchar
    #define _trmdir _wrmdir
    #define _ltot _ltow
    #define _i64tot _i64tow
    #define _istalnum iswalnum
    #define _tfdopen _wfdopen
    #define _ttmpnam _wtmpnam

    #ifdef UNIX 
		/* MS VS TCHAR of ISO/IEC TR 24731-1 */
	#define _stprintf_s	swprintf_s
	#define _tcsncpy_s	wcsncpy_s
	#define _tcscpy_s	wcscpy_s
    #else
	#define _tmkdir(p, mode) _wmkdir(p)
    #endif

#endif

#if !defined( UNIX )
    #define S_IRWXU 0
    #define S_IRWXG 0
    #define S_IRWXO 0
#endif

#endif /* !defined( _TCHAR_H ) */

#ifndef _TCHAR_H_WCEDEFS_INCLUDED
#define _TCHAR_H_WCEDEFS_INCLUDED
    #ifdef UNDER_CE//давно хотел макрос для ascii везде кроме CE
	#define _WCET(text) _WCET2(text)
	#define _WCET2(text) L ## text
	#define _wcestrcpy wcscpy
	#define _wcestrlen wcslen
	#define _wcestrchr wcschr

	typedef wchar_t WCECHAR;
	typedef wchar_t *PWCECHAR;
    //    typedef WCHAR *LPWCECH, *PWCECH;
    //    typedef CONST WCHAR *LPCWCECH, *PCWCECH;
    //    typedef WCHAR *NPWCESTR;
    //    typedef WCHAR *LPWCESTR, *PWCESTR;
    //    typedef CONST WCHAR *LPCWCESTR, *PCWCESTR;
    #else
	#define _WCET(text) text
	#define _wcestrcpy strcpy
	#define _wcestrlen strlen
	#define _wcestrchr strchr

	typedef char WCECHAR;
	typedef char *PWCECHAR;
    //    typedef CHAR *LPWCECH, *PWCECH;
    //    typedef CONST CHAR *LPCWCECH, *PCWCECH;
    //    typedef CHAR *NPWCESTR;
    //    typedef CHAR *LPWCESTR, *PWCESTR;
    //    typedef CONST CHAR *LPCWCESTR, *PCWCESTR;
    #endif
#endif // !defined _TCHAR_H_WCEDEFS_INCLUDED
/*+ end of file: tchar.h +*/

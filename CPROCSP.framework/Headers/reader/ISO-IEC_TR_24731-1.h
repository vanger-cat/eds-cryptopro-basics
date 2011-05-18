/*
 * Copyright(C) 2009 Проект ИОК
 *
 * Этот файл содержит информацию, являющуюся
 * собственностью компании Крипто-Про.
 *
 * Любая часть этого файла не может быть скопирована,
 * исправлена, переведена на другие языки,
 * локализована или модифицирована любым способом,
 * откомпилирована, передана по сети с или на
 * любую компьютерную систему без предварительного
 * заключения соглашения с компанией Крипто-Про.
 */

/*!
 * \file $RCSfile$
 * \version $Revision: 61696 $
 * \date $Date: 2010-05-12 11:27:42 +0400 (СЃСЂ, 12 РјР°Р№ 2010) $
 * \author $Author: dim $
 *
 * \brief Описание общей организации тестов маршалинга
 */

#ifndef ISO_IEC_TR_24731_1_H_
#define ISO_IEC_TR_24731_1_H_

	// TODO: ??Убрать или нет??
//#define __EXTENSIONS__	1
//#define _GNU_SOURCE	1
//#define _POSIX_C_SOURCE	200809L
//#define _ISOC99_SOURCE	1
//#define __USE_GNU
//#define _GNU_SOURCE

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <wchar.h>

#ifdef UNIX
#include<CPROCSP/reader/tchar.h>
#else
    #include <tchar.h>
#endif

#include<CPROCSP/reader/dprint.h>
#ifdef UNIX
    #define _wcsdup wcsdup
#endif

#ifndef _len_of
    #define _len_of(a)    (sizeof(a)/sizeof(*(a)))
#endif

/* XXX dim: на фазе "Code Review" необходимо проверить реализации */
#ifdef UNIX
    // MS VS form of ISO/IEC TR 24731-1
    // <http://www.open-std.org/JTC1/SC22/WG14/www/projects#24731-1>
    // See \\cp.ru\dfs\home\lse\doc\C\n1225.pdf
    // See \\cp.ru\dfs\home\lse\doc\C\n1173.pdf
    //
    // strnlen
    
    // wcscpy_s // TODO: check s1 & s2
	#define wcscpy_s(s1, s1max, s2) ( \
			&(s1)[s1max] == wcsncpy((s1), (s2), (s1max)) \
			    ? ((s1)[(s1max)-1] = '\0' ? -1 : -1) \
			    : 0 \
		    )
	#define wcsncpy_s(s1, s1max, s2, n) ( \
			(n) >= (s1max) \
			    ? wcscpy_s((s1), (s1max), (s2)) \
			    : (wcsncpy((s1), (s2), (n)), (s1)[n] = '\0') \
		    )
	
    // strcpy_s // TODO: check s1 & s2
	#define strcpy_s(s1, s1max, s2) ( \
			&(s1)[s1max] == strncpy((s1), (s2), (s1max)) \
			    ? ((s1)[(s1max)-1] = '\0' ? -1 : -1) \
			    : 0 \
		    )
	#define strncpy_s(s1, s1max, s2, n) ( \
			(n) >= (s1max) \
			    ? strcpy_s((s1), (s1max), (s2)) \
			    : (strncpy((s1), (s2), (n)), (s1)[n] = '\0') \
		    )
    // sprintf_s // TODO: check s & format
	#define sprintf_s(s, n, format, ...)  ( \
		       (memset(s,0,n), /* XXX dim: valgrind want to be happy */ \
			0 > snprintf((s), (n), format, ##__VA_ARGS__) \
			? -1 \
			: ( (s)[(n)-1] \
			    ? (s)[(n)-1] = '\0' \
			    : (int)strnlen((s), (n)) \
			  ) \
		       ) \
		    )
    // vsprintf_s // TODO: check s & format
	#define vsprintf_s(s, n, format, arg)  ( \
			( 0 > vsnprintf((s), (n), (format), (arg)) \
			? -1 \
			: ( (s)[(n)-1] \
			    ? (s)[(n)-1] = '\0' \
			    : (int)strnlen((s), (n)) \
			  ) \
			) \
		    )
    // gmtime_s // TODO check TR & MS Doc & __STDC_LIB_EXT1_ _ The integer constant 200509L
	#define gmtime_s(tm, time) ( \
			gmtime_r((time), (tm)) \
		    )
    // asctime_s // TODO check s1 & maxsize < 26
	#define asctime_s(s, maxsize, timerptr) ( \
			strcpy_s((s), (maxsize), asctime(timerptr)) \
		    )

	#define strerror_s(buf, num, errnum) ( \
			strerror_r((errnum), (buf), (num)) \
		    )
	#define localtime_s(presult, cptimer) ( \
			localtime_r((cptimer), (presult)) \
			    ? 0 \
			    : errno \
		    )

    #if !defined WIN32 && !defined HAVE_STRNLEN
	static SUP_INLINE size_t 
	strnlen(const char *s, size_t maxlen)
	{
	    size_t i;
	    
	    for(i = 0; i < maxlen && s[i]; i++)
		;
	    return i;
	}
    #endif /* !WIN32 && !HAVE_STRNLEN */
    #if !defined WIN32 && !defined HAVE_WCSNLEN
	static SUP_INLINE size_t 
	wcsnlen(const wchar_t *ws, size_t maxlen)
	{
	    size_t i;
	    
	    for(i = 0; i < maxlen && ws[i]; i++)
		;
	    return i;
	}
    #endif /* !WIN32 && !HAVE_WCSNLEN */
#endif

#endif /*ISO_IEC_TR_24731_1_H_*/

/* $Id: ISO-IEC_TR_24731-1.h 61696 2010-05-12 07:27:42Z dim $ */

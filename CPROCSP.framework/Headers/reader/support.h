/*
 * Copyright(C) 2000-2010 Проект ИОК
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

#if !defined( _READER_SUPPORT_SUPPORT_H )
#define _READER_SUPPORT_SUPPORT_H

#include<CPROCSP/common.h>
#include<CPROCSP/reader/tchar.h>

/* --------------- INCLUDE --------------- */
#if defined(CSP_LITE)
#elif defined( WIN32 )
#   include <stdlib.h>
#   pragma warning( push )
#   pragma warning( disable: 4100 4115 4201 4214 )
#   include <windows.h>
#   include <time.h>
#   pragma warning( pop )
#elif defined UNIX
#   include <stdlib.h>
#   include <stdarg.h>
# ifdef HAVE_STDINT_H
#   include <stdint.h>
# elif defined(HAVE_INTTYPES_H)
#   include <inttypes.h>
# elif defined(HAVE_SYS_INTTYPES_H)
#   include <sys/inttypes.h>
# endif
#   include <time.h>
#   include <sys/time.h>
#   include <pthread.h>
#   include <nl_types.h>
#include<CPROCSP/reader/ubi_mutex.h>
#else
#   error !UNIX && !_WIN32
#endif

#include<CPROCSP/reader/std_decl.h>

#if !defined( _SUPPORT_DECL )
#   if defined( SUPPORT_IMPORTS )
#        define _SUPPORT_DECL _STDIMPL_DECL
#   else /* defined( SUPPORT_IMPORTS ) */
#        define _SUPPORT_DECL
#   endif /* !defined( SUPPORT_IMPORTS ) */
#endif /* !defined( _SUPPORT_DECL ) */

#if !defined( _SUPPORT_CALLBACK_CONV )
#   if defined( UNIX )
#	if defined( __GNUC__ ) && !defined(IOS)
#	    define _SUPPORT_CALLBACK_CONV __attribute__((regparm(0))) 
#	else // defined( __GNUC__ )
#	    define _SUPPORT_CALLBACK_CONV
#	endif // defined( __GNUC__ )
#   else // defined( UNIX )
#      define _SUPPORT_CALLBACK_CONV __cdecl
#   endif // defined( UNIX )
#endif // !defined( _SUPPORT_CALLBACK_CONV )

// Аналогичное определение есть в файлах reader/source/support/sup_def.h,
// и reader/source/rndm/rndm_def.h, их надо держать в соответствии!
#if defined( UNIX ) || defined( _WIN32 ) && defined( __STDC__ ) || defined( WINCE )
    #define NO_SUP_NOTIFICATOR
    #define NO_SUP_WIZARD
    #define NO_SUP_PROPERTIES
#endif // defined( UNIX ) || defined( _WIN32 ) && defined( __STDC__ ) || defined( WINCE )

#if !defined( LANGUAGE ) 
    /*+ Выбор строки языка WIN1251. +*/
#   define _LANGTEXT(a/*+English+*/,b/*+Win1251+*/) (const wchar_t*)L ## a
#elif ( LANGUAGE == 1251 )
    /*+ Выбор строки языка WIN1251. +*/
#   define _LANGTEXT(a/*+English+*/,b/*+Win1251+*/) (const wchar_t*)L ## b
#else /* defined( LANGUAGE ) && ( LANGUAGE == 1251 )  */
    /*+ Выбор строки языка WIN1251. +*/
#   define _LANGTEXT(a/*+English+*/,b/*+Win1251+*/) (const wchar_t*)L ## a
#endif /* !defined( LANGUAGE ) || ( LANGUAGE != 866 ) && ( LANGUAGE != 1251 ) ) */

/* --------------- DEFINE --------------- */
#if defined( WIN32 ) && !defined( CSP_LITE )
#   define safe_mbsrtowcs( dest, src, len ) MultiByteToWideChar( CP_ACP, 0, (src), (int)(len), (dest), (int)(len) )
#   define safe_wcsrtombs( dest, src, len ) WideCharToMultiByte( CP_ACP, 0, (src), (int)(len), (dest), (int)(len), NULL, NULL )
#elif defined( _WIN32 )
#   define safe_mbsrtowcs mbstowcs
#   define safe_wcsrtombs wcstombs
#endif

//не зависящие от TCHAR
#define _2un(dest, src, len) safe_mbsrtowcs(dest, src, len) //длина входного и выходного буфера в символах
#define _2u(dest, src) safe_mbsrtowcs(dest, src, strlen(src)+1)
#define _u2n(dest, src, len) safe_wcsrtombs(dest, src, len) //длина входного и выходного буфера в символах
#define _u2(dest, src) safe_wcsrtombs(dest, src, wcslen(src)+1)	

#ifdef UNICODE
#   define _2asciincpy( dest, src, len ) safe_wcsrtombs(dest, src, len)
#   define _2asciicpy( dest, src ) safe_wcsrtombs(dest, src, wcslen(src)+1)
#   define _ascii2ncpy( dest, src, len ) safe_mbsrtowcs(dest, src, len)
#   define _ascii2cpy( dest, src ) safe_mbsrtowcs(dest, src, strlen(src)+1)
#   define _2unincpy( dest, src, len ) wcsncpy( dest, src, len )
#   define _2unicpy( dest, src ) wcscpy( dest, src )
#   define _uni2ncpy( dest, src, len ) wcsncpy( dest, src, len )
#   define _uni2cpy( dest, src ) wcscpy( dest, src )
#else /* UNICODE */
#   define _2asciincpy( dest, src, len ) strncpy( dest, src, len )
#   define _2asciicpy( dest, src ) strcpy( dest, src )
#   define _ascii2ncpy( dest, src, len ) strncpy( dest, src, len )
#   define _ascii2cpy( dest, src ) strcpy( dest, src )
#   define _asciincpy( dest, src ) strcpy( dest, src )
#   define _2unincpy( dest, src, len ) safe_mbsrtowcs(dest, src, len)
#   define _2unicpy( dest, src ) safe_mbsrtowcs(dest, src, strlen(src)+1)
#   define _uni2ncpy( dest, src, len ) safe_wcsrtombs(dest, src, len)
#   define _uni2cpy( dest, src ) safe_wcsrtombs(dest, src, wcslen(src)+1)
#endif /* UNICODE */

#ifndef WINCE
#   define _2wcencpy( dest, src, len ) _2asciincpy(dest, src, len)
#   define _2wcecpy( dest, src ) _2asciicpy(dest, src)
#   define _wce2ncpy( dest, src, len ) _ascii2ncpy(dest, src, len)
#   define _wce2cpy( dest, src ) _ascii2cpy(dest, src)
#   define _u2wcen(dest, src, len) safe_wcsrtombs(dest, src, len) //длина входного и выходного буфера в символах
#   define _u2wce(dest, src) safe_wcsrtombs(dest, src, wcslen(src)+1)
#   define _wce2un(dest, src, len) safe_mbsrtowcs(dest, src, len) //длина входного и выходного буфера в символах
#   define _wce2u(dest, src) safe_mbsrtowcs(dest, src, strlen(src)+1)	
#   define _a2wcen(dest, src, len) strncpy(dest, src, len) //длина входного и выходного буфера в символах
#   define _a2wce(dest, src) strcpy(dest, src)
#   define _wce2an(dest, src, len) strncpy(dest, src, len) //длина входного и выходного буфера в символах
#   define _wce2a(dest, src) strcpy(dest, src)	
#else /* WINCE */
#   define _2wcencpy( dest, src, len ) _2unincpy(dest, src, len)
#   define _2wcecpy( dest, src ) _2unicpy(dest, src)
#   define _wce2ncpy( dest, src, len ) _uni2ncpy(dest, src, len)
#   define _wce2cpy( dest, src ) _uni2cpy(dest, src)
#   define _u2wcen(dest, src, len) wcsncpy(dest, src, len) //длина входного и выходного буфера в символах
#   define _u2wce(dest, src) wcscpy(dest, src)
#   define _wce2un(dest, src, len) wcsncpy(dest, src, len) //длина входного и выходного буфера в символах
#   define _wce2u(dest, src) wcscpy(dest, src)	
#   define _a2wcen(dest, src, len) safe_mbsrtowcs(dest, src, len) //длина входного и выходного буфера в символах
#   define _a2wce(dest, src) safe_mbsrtowcs(dest, src, strlen(src)+1)
#   define _wce2an(dest, src, len) safe_wcsrtombs(dest, src, len) //длина входного и выходного буфера в символах
#   define _wce2a(dest, src) safe_wcsrtombs(dest, src, wcslen(src)+1)
#endif /* WINCE */

#define SUPPORT_MUTEX_RECURSIVE 1
#define SUPPORT_MUTEX_PRIVATE 2

#if !defined CSP_LITE
#if !defined UNIX
/* Mutex - блокирующий межнитевой и межпроцессный объект.
   Блокировка или отсутствие блокировки внутри одной нити зависит от
   реализации */
#   define support_mutex_init( mutex ) *mutex = INVALID_HANDLE_VALUE;
#   define support_mutex_open( mutex, name, flags ) support_mutex_open_fun( mutex, name, flags )
#   define support_mutex_lock( mutex ) WaitForSingleObject( (mutex), INFINITE )
#   define support_mutex_unlock( mutex ) { if(mutex != INVALID_HANDLE_VALUE) ReleaseMutex( mutex ); }
#   define support_mutex_trylock( mutex ) (WaitForSingleObject( (mutex), 0 ) == WAIT_TIMEOUT ? SUP_ERR_CANCEL : SUP_ERR_NO )
#   define support_mutex_close( mutex ) { if( *mutex != INVALID_HANDLE_VALUE ) { CloseHandle( *mutex ); *mutex = INVALID_HANDLE_VALUE; } }
# ifndef _M_ARM
#   define support_try __try {
#   define support_finally } __finally {
# else
#   define support_try {
#   define support_finally } {
# endif
#   define support_finally_end }
#   define support_finally_return

/* Critical Section блокирующий межнитевой объект. Блокировки между процессами
    нет. Блокировка внутри одной нити зависит от реализации. */
#   define support_section_init( section, arg ) (InitializeCriticalSection(section),0)
#   define support_section_init_recursive(section) (InitializeCriticalSection(section),0)
#   define support_section_done( section ) (DeleteCriticalSection(section),0)
#   define support_section_enter( section ) (EnterCriticalSection(&section),0)
#   define support_section_leave( section ) (LeaveCriticalSection(&section),0)

/* Event блокирующий межпроцессный, межнитевой и внутринитевой объект. */
#   define support_event_init( event ) *event = INVALID_HANDLE_VALUE;
#   define support_event_open( event, name ) support_event_open_fun( event, name )
#   define support_event_lock( event ) WaitForSingleObject( (event), INFINITE )
#   define support_event_unlock( event ) { if(event != INVALID_HANDLE_VALUE) SetEvent( event ); }
#   define support_event_trylock( event ) (WaitForSingleObject( (event), 0 ) == WAIT_TIMEOUT ? SUP_ERR_CANCEL : SUP_ERR_NO )
#   define support_event_close( event ) { if( *event != INVALID_HANDLE_VALUE ) { CloseHandle( *event ); *event = INVALID_HANDLE_VALUE; } }

/* RWLock блокирующий межнитевой объект. Разрешен доступ нескольких reader или
    одного writer. Блокировки между процессами нет.
    Блокировка внутри одной нити зависит от реализации. */

#else /* UNIX */
#define support_mutex_init( m ) \
            ((m)->inited = 0)
#define support_mutex_open( m, name, flags ) \
            ( ubi_mutex_open(&((m)->ubi_mutex),name,flags) \
                ? SUP_ERR_VERIFY \
                : ((((m)->inited = 1)), 0) \
            )
#define support_mutex_lock( m ) \
            (ubi_mutex_lock(&((m).ubi_mutex)))
#define support_mutex_trylock( m ) \
            ( ((m).inited) \
                ? (ubi_mutex_trylock( &((m).ubi_mutex) ) \
                    ? SUP_ERR_CANCEL \
                    : SUP_ERR_NO ) \
                : SUP_ERR_PARAM \
            )
#define support_mutex_unlock( m ) \
            { if((m).inited) { \
                ubi_mutex_unlock(&((m).ubi_mutex)); \
              } \
            }
#define support_mutex_close( m ) \
            { if((m)->inited) { \
                ubi_mutex_close(&((m)->ubi_mutex)); \
              } \
              (m)->inited = 0; \
            }
#define support_mutex_copy( m1, m2 ) \
            { if(0 != ((m1)->inited = (m2).inited)) { \
                ubi_mutex_copy(&(m1)->ubi_mutex, &(m2).ubi_mutex); \
              } \
            }

# define support_section_init( section, arg ) pthread_mutex_init( section,NULL )
# define support_section_init_recursive(section) support_mutex_init_recursive(section)
# define support_section_done( section ) pthread_mutex_destroy( section )
# define support_section_enter( section ) pthread_mutex_lock( &section )
# define support_section_leave( section ) pthread_mutex_unlock( &section )

# define support_event_init( event ) support_mutex_init( event )
# define support_event_open( event, name ) support_mutex_open( event, name, 0 )
# define support_event_lock( event ) support_mutex_lock( event )
# define support_event_unlock( event ) support_mutex_unlock( event )
# define support_event_trylock( event ) support_mutex_trylock( event )
# define support_event_close( event ) support_mutex_close( event )

# define support_try {
# define support_finally }
# define support_finally_end

#endif /* UNIX */

#elif defined CSP_LITE

# define support_try __try {
# define support_finally } __finally {
# define support_finally_end }
# define support_finally_return

# define support_section_init( section, arg )
# define support_section_init_recursive(section)
# define support_section_done( section )
# define support_section_enter( section ) (void) 1
# define support_section_leave( section )

#endif /* CSP_LITE */

#define support_mutex_try_lock( mutex ) \
    support_mutex_lock( mutex ); support_try
#define support_mutex_finally_unlock( mutex ) \
    support_finally support_mutex_unlock( mutex ); support_finally_end
#define support_section_try_enter( section ) \
    support_section_enter( section ); support_try
#define support_section_finally_leave( section ) \
    support_finally support_section_leave( section ); support_finally_end
#define support_event_try_lock( event ) \
    support_event_lock( event ); support_try
#define support_event_finally_unlock( event ) \
    support_finally support_event_unlock( event ); support_finally_end
#define RWLOCK_CLAIM(lock,mode) \
    CRWLock_Claim (lock, mode); support_try
#define RWLOCK_RELEASE(lock,mode) \
    support_finally CRWLock_Release (lock, mode); support_finally_end

#if !defined support_finally_return
#   define support_mutex_finally_return( mutex ) support_mutex_unlock( mutex );
#   define support_section_return_leave( section ) support_section_leave( section );
#   define support_event_finally_return( event ) support_event_unlock( event );
#else
#   define support_mutex_finally_return( mutex )
#   define support_section_return_leave( section )
#   define support_event_finally_return( event )
#endif

#if defined _WIN64
#   define support_registry_get_time_t(p,t) \
    support_registry_get_long_long(p,(long long*)t )
#   define support_registry_put_time_t(p,t) \
    support_registry_put_long_long(p,(long long)t )
#else
#   define support_registry_get_time_t(p,t) \
    support_registry_get_long(p,(long*)t )
#   define support_registry_put_time_t(p,t) \
    support_registry_put_long(p,(long)t )
#endif

#if defined (_WIN32)
    #ifdef CSP_LITE
	#define SUP_STOP { \
		int x; \
		x=3;x=x/(3-x); \
		*(char *)(void *)(intptr_t)(x-3) = 0; \
	    }
    #else /* CSP_LITE */
	#define SUP_STOP DebugBreak();
    #endif /* CSP_LITE */
#else
    #ifdef CSP_LITE
	#define SUP_STOP { \
		int x; \
		x=3;x=x/(3-x); \
		*(char *)(void *)(intptr_t)(x-3) = 0; \
	    }
    #else
	#define SUP_STOP { abort(); }
    #endif
#endif

#if defined( WIN32 ) && !defined( CSP_LITE )
#   define IS_READ_PTRS(x,size) ( !IsBadReadPtr(x,size) )
#   define IS_WRITE_PTRS(x,size) ( !IsBadWritePtr(x,size) )
#   define IS_READ_PTR(x) ( !IsBadReadPtr(x,1) )
#   define IS_WRITE_PTR(x) ( !IsBadWritePtr(x,1) )
#   ifdef UNDER_CE
#	define IS_STRING_PTRS(x,size)	IS_READ_PTR(x)
#	define IS_STRING_PTR(x)		IS_READ_PTR(x)
#   else /*UNDER_CE*/
#	define IS_STRING_PTRS(x,size) ( !IsBadStringPtr(x,size) )
#	define IS_STRING_PTR(x) ( !IsBadStringPtr(x,(size_t)-1) )
#   endif /*UNDER_CE*/
#   define IS_FUN_PTR(x) (!IsBadCodePtr((FARPROC)x) )
#else
/* Проверка на ноль: 
   TODO: на выровненность можем проверять wchar-строки и там,
   где сами выделяем память: SUPSYS_PRE_CONTEXT(), SUPSYS_PRE_INFO */
#   define IS_READ_PTRS(x,size) (x)
#   define IS_WRITE_PTRS(x,size) (x)
#   define IS_READ_PTR(x) IS_READ_PTRS(x,1)
#   define IS_WRITE_PTR(x) IS_WRITE_PTRS(x,1)
#   define IS_STRING_PTRS(x,size) (x)
#   define IS_STRING_PTR(x) (x)
#   define IS_FUN_PTR(x) (x)
#endif

#define SUPDLL_NULL
#define SUPDLL_LOAD_PROC(nn,name,err) \
    if(!nn##_entry.name##_proc){ \
        if( !nn##_module ) { \
            if( nn##_load_library() ) return err; \
        } \
        nn##_entry.name##_proc = (T##name##Proc)support_load_library_getaddr( nn##_module, #name ); \
        if( !nn##_entry.name##_proc ) return err; \
    }

#define SUPDLL_ITEMT(nn,name,arg_list,type,conv) \
    typedef type (conv *T##name##Proc) arg_list;
#define SUPDLL_ITEMI(nn,name) \
    T##name##Proc name##_proc;

#define SUPDLL_ITEMI_B(nn) \
    static TSupModuleInstance nn##_module = NULL; \
    static int nn##_load_count = 0; \
    struct nn##Entry_ {
#define SUPDLL_ITEMI_E(nn) \
    } nn##_entry;

#define SUPDLL_ITEMI_B_INSIDE(nn) \
    static TSupModuleInstance nn##_module = NULL; \
    static int nn##_load_count = 0; \
    static struct nn##Entry_ {

#define SUPDLL_LOAD(nn,name) \
    TSupErr nn##_load_library( void ) { \
        if( nn##_load_count ) { nn##_load_count++; return 0; } \
        nn##_module = support_load_library_registry( name, \
            SUP_LOAD_LIBRARY_DEFAULT ); \
        if( nn##_module == NULL ) return SUP_ERR_VERIFY; \
        nn##_load_count++; \
        return 0; \
    }
#define SUPDLL_LOAD_NO_CALLEE_CHECK(nn,name) \
    TSupErr nn##_load_library( void ) { \
    if( nn##_load_count ) { nn##_load_count++; return 0; } \
    nn##_module = support_load_library_registry_no_callee_check( name, \
    SUP_LOAD_LIBRARY_DEFAULT ); \
    if( nn##_module == NULL ) return SUP_ERR_VERIFY; \
    nn##_load_count++; \
    return 0; \
    }
#define SUPDLL_UNLOAD(nn) \
    void nn##_unload_library( void ) { \
        if( !nn##_load_count ) return; \
        nn##_load_count--; \
        if( nn##_load_count ) return; \
        memset( &nn##_entry, 0, sizeof( nn##_entry ) ); \
        support_unload_library_registry( nn##_module ); \
    }

#define SUPDLL_ITEMR2(nn,name,arg_list,call_list,type,conv,err) \
    type conv name arg_list { \
        SUPDLL_LOAD_PROC(nn,name,err) \
        return nn##_entry.name##_proc call_list; \
    }

#define SUPDLL_ITEMV(nn,name,arg_list,call_list) \
    void name arg_list { \
        SUPDLL_LOAD_PROC(nn,name,SUPDLL_NULL) \
        nn##_entry.name##_proc call_list; \
    }

#define SUPDLL_ITEMVL(nn,name,arg_list,name2,last,call_list) \
    void name arg_list { \
        va_list valist; \
        va_start( valist, last ); \
        SUPDLL_LOAD_PROC(nn,name2,SUPDLL_NULL); \
        nn##_entry.name2##_proc call_list; \
	va_end(valist); \
    }

#define SUPDLL_ITEMRL(nn,name,arg_list,name2,last,call_list,type,err) \
    type name arg_list { \
        va_list valist; \
	type _retcode_; \
        va_start( valist, last ); \
        SUPDLL_LOAD_PROC(nn,name2,err); \
        _retcode_ = nn##_entry.name2##_proc call_list; \
        va_end(va_list); \
        return _retcode_; \
    }

#define SUPLIB_ITEMR2(nn,name,arg_list,call_list,type,conv,err) \
    type conv name arg_list { return err; }
#define SUPLIB_ITEMV(nn,name,arg_list,call_list) \
    void name arg_list { return; }
#define SUPLIB_ITEM(nn,name,arg_list,call_list) \
    SUPLIB_ITEMR2(nn,name,arg_list,call_list,TSupErr,SUPDLL_NULL,SUP_ERR_UNSUPPORTED)
#define SUPLIB_ITEMVL(nn,name,arg_list,call_list) \
    void name arg_list { return; }

//TODO: У нас определений UNUSED(x) штук 20-30, и некоторые кривые
//#if !defined UNUSED
    //#ifdef WIN32
    //    #define UNUSED(x)   UNREFERENCED_PARAMETER(x)
    //#else
    //    #define UNUSED(x)   ((void)(x))
    //#endif
//#endif /* !defined( UNUSED ) */
#if defined UNUSED
    #undef  UNUSED
#endif
#define UNUSED(x)   (void)(x)

/* Общие ошибки, которые рекомендуется повторять в верхнем интерфейсе. */

/* Общий код ошибки: отсутствие ошибок или функция завершилась успешно. +*/
#define SUP_ERR_NO 0

/* Общий код ошибки: отсутствие ошибок или функция завершилась успешно. +*/
#define SUP_ERR_CORRECT 0

/* Общий код ошибки: отсутствие ошибок или функция завершилась успешно. +*/
#define SUP_CORRECT 0

/*+ Общий код ошибки: нехватка памяти. +*/
#define SUP_ERR_MEMORY 0x1001

/*+ Общий код ошибки: ПО неправильно установлено или искажено. +*/
#define SUP_ERR_VERIFY 0x1002

/*+ Общий код ошибки: неправильно пареданы параметры. +*/
#define SUP_ERR_PARAM 0x1003

/*+ Общий код ошибки: Функция не поддерживается. +*/
#define SUP_ERR_UNSUPPORTED 0x1004

/*+ Общий код ошибки: Неизвестная ошибка. +*/
#define SUP_ERR_UNKNOWN 0x1005

/*+ Общий код ошибки: Отказ от выполнения операции. +*/
#define SUP_ERR_CANCEL 0x1006

/*+ Общий код ошибки: Недостаточно прав. +*/
#define SUP_ERR_RIGHTS 0x1007

#define SUP_ERR_CONNECT 0x1008

/*+ Общий код ошибки: Версия старше 1.0 не поддерживается. +*/
#define SUP_ERR_STD_VERSION_1 0x1009

/*+ Общий код ошибки: функция отключена. +*/
#define SUP_ERR_FEATURE_DISABLED 0x100A

#define SUP_ERR_STD_MAX 0x1FFF

/*+ Определение прнадлежности ошибки к ошибкам функций поддержки.
    Аргумент вычисляется дважды. +*/
#define SUP_ERR_IS_STD( err ) \
    ( ( (err) >= SUP_ERR_MEMORY ) && ( (err) <= SUP_ERR_STD_MAX ) )

/*+ Код ошибки функции поддержки: Секция, ключ или параметр не найден. +*/
#define SUP_ERR_KEY_NOT_FOUND 0x2000

/*+ Код ошибки функции поддержки: Секция, ключ или параметр искажены. +*/
#define SUP_ERR_KEY_INVALID 0x2001

/*+ Код ошибки функции поддержки: Неправильный язык или ресурс. +*/
#define SUP_ERR_RESOURCE 0x2002

#define SUP_ERR_INSTALL_ADD 0x2003

/* Код ошибки: Параметр содержит значение неправильного типа. */
#define SUP_ERR_KEY_TYPE 0x2004

/*+ Код ошибки функции поддержки: Версия старше 1.0 не поддерживается. +*/
#define SUP_ERR_VERSION_1 0x2005

/*+ Код ошибки функции поддержки: Последний код ошибки. +*/
#define SUP_ERR_MAX 0x2FFF

/*+ Определение прнадлежности ошибки к ошибкам функций поддержки.
    Аргумент вычисляется дважды. +*/
#define SUP_ERR_IS( err /*+ (i) Код ошибки. +*/ ) \
    ( ( (err) >= SUP_ERR_KEY_NOT_FOUND ) && ( (err) <= SUP_ERR_MAX ) )

#define SUP_TYPE_UNKNOWN 0

/* Тип параметра строка. */
#define SUP_TYPE_STRING 0x1

/* Тип параметра long. */
#define SUP_TYPE_LONG 0x2

/* Тип параметра Boolean. */
#define SUP_TYPE_CSP_BOOL 0x4

/* Тип параметра Hex. */
#define SUP_TYPE_HEX 0x8

/* Тип параметра Section. */
#define SUP_TYPE_SECTION 0x10

/* Тип параметра Section. */
#define SUP_TYPE_MULTI_SZ 0x20

/* Тип параметра long long */
#define SUP_TYPE_LONG_LONG 0x40

/* Права выдаются с учетом необходимости создания подключей. */

/* Доступ к ключу на открытие, получение значения параметров. */
#define SUP_ACCESS_READ 0x1
/* Доступ к ключу на создание, изменение и удаление параметров */
#define SUP_ACCESS_MODIFY 0x2
/* Доступ на создание подключей. */
#define SUP_ACCESS_CREATE_SUBKEY 0x4
/* Доступ на удаление подключей. */
#define SUP_ACCESS_DELETE_SUBKEY 0x8
/* Доступ на получение прав. */
#define SUP_ACCESS_GET_ACCESS 0x10
/* Доступ на установку прав. */
#define SUP_ACCESS_SET_ACCESS 0x20
/* Доступ на перечисление ключей. */
#define SUP_ACCESS_ENUM_SUBKEY 0x40
/* Доступ на уведомление об изменениях. */
#define SUP_ACCESS_NOTIFY 0x80

/* If we have bit from this mask, we need to open file for read/write */
#define SUP_ACCESS_WRITE_MASK (SUP_ACCESS_MODIFY|SUP_ACCESS_CREATE_SUBKEY|SUP_ACCESS_DELETE_SUBKEY|SUP_ACCESS_SET_ACCESS)

#define SUPPORT_NOTIFY_SUBTREE 0x1
#define SUPPORT_NOTIFY_CHANGE 0x2
#define SUPPORT_NOTIFY_RENAME 0x4
#define SUPPORT_NOTIFY_SECURITY 0x8

#define SUP_LOAD_LIBRARY_STD 0

#define SUP_LOAD_LIBRARY_DEFAULT 1
#define SUP_LOAD_LIBRARY_SEPARATE 2
#define SUP_LOAD_LIBRARY_LAZY 4

/* --------------- TYPES --------------- */

/*+ Тип кода ошибки. +*/
typedef unsigned int TSupErr;

#if defined( WIN32 )
    typedef unsigned ( __stdcall *TSupFun )( void* );
#endif

typedef enum CRWLockMode_ {
    CRWLOCK_NONE = 1,
    CRWLOCK_READ = 2,
    CRWLOCK_ANY = 3,
    CRWLOCK_WRITE = 4,
    CRWLOCK_ERROR = -1
} CRWLockMode;

#if defined UNIX && defined CSP_LITE
    typedef void * TSupportCriticalSection;
    typedef void * TSupportMutex;
    typedef TSupportMutex TSupportEvent;
#elif defined UNIX && !defined CSP_LITE
    struct CRWLock_t
    {
	pthread_mutex_t CriticalSection;
	enum {
	    CRWLockInited   = 0x74696e49,
	    CRWLockReleased = 0x656c6552
	}       Status;
	int     Recusion;
	const char *LastFile;
	int     LastLine;
	#if defined(__sparcv9)
	    int            dwReserved;
	#endif /* defined(__sparcv9)*/
	void    *Arg;
    };

    typedef struct TSupportMutex_
    {
	ubi_mutex_t ubi_mutex;
	int inited;
    } TSupportMutex;
    typedef pthread_mutex_t TSupportCriticalSection;
    typedef TSupportMutex TSupportEvent;
#elif !defined UNIX && defined CSP_LITE
    typedef struct _FAST_MUTEX *PFAST_MUTEX;
    #ifndef CSP_LITE
	typedef PVOID PSECURITY_DESCRIPTOR;     // winnt
    #endif
    typedef PFAST_MUTEX TSupportCriticalSection;
#elif defined( WIN32 )
    typedef HANDLE TSupportMutex;
    typedef CRITICAL_SECTION TSupportCriticalSection;
    typedef HANDLE TSupportEvent;
    struct CRWLock_t
    {
	LONGLONG dummy[2*13];
    };
#elif defined( _WIN32 ) && defined( __STDC__ )
    typedef volatile int TSupportMutex;
    typedef volatile int TSupportCriticalSection;
    typedef TSupportMutex TSupportEvent;
#endif

typedef struct CRWLock_t CRWLock;

struct TSupportSharedMemory_;
typedef struct TSupportSharedMemory_ TSupportSharedMemory;

typedef TSupErr (*TSupportFunAddress)( void );

/* Типы параметров. */
typedef unsigned int TSupType;

/* Типы параметров. */
typedef unsigned int TSupAccess;

/* Контекст в registry. */
struct TSupportRegistrySearchContext_;

typedef struct TSupportRegistrySearchContext_ TSupportRegistrySearchContext;

struct TSupportRegistrySearchValue_;

typedef struct TSupportRegistrySearchValue_ TSupportRegistrySearchValue;

#ifdef NO_SUP_NOTIFICATOR
    typedef int TSupRegNotificator;
#else /* !NO_SUP_NOTIFICATOR */
    struct TSupRegNotificator_;
    typedef struct TSupRegNotificator_ TSupRegNotificator;
#endif /* !NO_SUP_NOTIFICATOR */

struct TSupFileEnum_;

typedef struct TSupFileEnum_ TSupFileEnum;

typedef enum TSupFileType_ {
    SUP_FTYPE_IGNORE,
    SUP_FTYPE_FILE,
    SUP_FTYPE_DIR
} TSupFileType;

#if !defined CSP_LITE
    /* Гарантированный однократный запуск функции */
	/* TODO:X Заменить на что-то в духе:
	 * typedef boost::once_flag TSupportOnce;
	 * #define SUPPORT_ONCE_INIT BOOST_ONCE_INIT
	 * #define support_once(once_control, init_routine) boost::call_once(init_routine, once_control)
	 */
    #ifdef UNIX

	typedef pthread_once_t TSupportOnce;
	#define SUPPORT_ONCE_INIT PTHREAD_ONCE_INIT
	#define support_once(once_control, init_routine) \
			    (pthread_once((once_control), (init_routine)))
    #else
	typedef struct TSupportOnce_ {
	    LONG lLock;
	    LONG lDone;
	    LONG lInited;
	} TSupportOnce;
	#define SUPPORT_ONCE_INIT { 0, 0 }

	static __inline int
	support_once(TSupportOnce *once_control, 
		     void (*init_routine)(void))
	{
	    LONG lThreadID = GetCurrentThreadId();
	    int ret = 0;

	    if(once_control == NULL || init_routine == NULL) {
		return /*EINVAL*/22;
	    }
	    if(once_control->lDone) {	// "Стандартная" оптимизация
	    	return 0;
	    }
	    if(!InterlockedExchangeAdd(&once_control->lDone, 0)) 
	    { /* MBR fence */
		while(0 != InterlockedCompareExchange(
				&once_control->lLock, lThreadID, 0)) {
		    Sleep(100);
		}
		if(!once_control->lDone) 
		{
		    (*init_routine)();
		    if(0 != InterlockedExchangeAdd(&once_control->lDone, 1)) {
			// TODO:XX Достаточно было бы признака volatile на 
			// lDone, однако, прототип InterlockedExchangeAdd()
			// на CE странный.
			// TODO:X Добавить сообщение об обломе. Если 
			// Interlocked*() работают, то управление сюда 
			// не попадёт.
			SUP_STOP;
			ret = -1; /* Internal error */
		    }
		    once_control->lInited = lThreadID;
		}	    
		if(lThreadID != once_control->lLock) {
		    // TODO:X Добавить сообщение об обломе. Если 
		    // Interlocked*() работают, то управление сюда 
		    // не попадёт.
		    SUP_STOP;
		    ret = -1; /* Internal error */
		}
		once_control->lLock = 0;
	    }
	    return ret;
	}
    #endif
#endif

#if defined( SUPPORT_RESOURCE_STD )
    typedef struct TSupStringTableItem_
    {
	size_t num; /*!< Номер элемента. */
	const wchar_t *string; /*!< Строка. */
    } TSupStringTableItem;

    /*! Элемент версии работающего во всех операционках. */
    typedef struct TSupVersionItem_
    {
	const wchar_t *company; /*!< Компания производитель. */
	const wchar_t *copyright; /*!< Copyright */
	unsigned int version[4]; /*!< Номер версии. */
    } TSupVersionItem;

    /*! Элемент иконок работающего во всех операционках. */
    typedef struct TSupIconTableItem_
    {
	int num; /*!< Номер элемента. */
	const wchar_t *icon_name; /*!< Имя иконки. */
    } TSupIconTableItem;

    /*!
     * \brief resource работающий во всех операционках
     */
    #if defined(UNIX) && !defined(CSP_LITE)
	typedef void (* TSupOnceFunc)(void);
	typedef struct TSupInstanceCatalog_
	{
	    TSupportOnce once_control;
	    const TSupOnceFunc once_func;
	    nl_catd nl_id;
	} TSupInstanceCatalog;
    #endif
    typedef struct TSupInstanceResourceDecl_
    {
	#if defined(UNIX) && !defined(CSP_LITE)
	    TSupInstanceCatalog *catalog;
	#else
	    int string_table_max; /*!< Размер строкового ресурса. */
	    const TSupStringTableItem *string_table; /*!< Собственно string table. */
       	#endif
	const TSupVersionItem *version; /*!< Указатель на информацию о версии. */
	int icon_table_max; /*!< Размер ресурса иконок. */
	const TSupIconTableItem *icon_table; /*!< Указатель на иконки. */
    } TSupInstanceResourceDecl;

    /*!
     * \brief instance работающий во всех операционках
     */
    typedef const TSupInstanceResourceDecl * TSupResourceInstance;
#else
    /*!
     * \brief instance ресурса определяется как DLL instance.
     */
    typedef HINSTANCE TSupResourceInstance;
#endif /* !defined( SUPPORT_RESOURCE_STD ) */

#if defined WIN32 && !defined CSP_LITE
    typedef HINSTANCE TSupModuleInstance;
    typedef HICON TSupIcon;
    typedef HBITMAP TSupBitMap;
    typedef FARPROC TSupProc;
#else
    typedef void* TSupModuleInstance;
    typedef void *TSupIcon;
    typedef void *TSupBitMap;
    typedef void *TSupProc;
#endif /* !defined( WIN32 ) */

#ifdef WINCE
#   include <WinSock2.h>
#elif defined(UNIX) && !defined CSP_LITE
#   include <sys/time.h>
#endif /* UNIX && WINCE || !CSP_LITE */

typedef struct timeval support_timeval;

/* --------------- FUNCTIONS --------------- */
#if defined( __cplusplus )
extern "C" {
#endif /* defined( __cplusplus ) */

unsigned long       support_get_last_error (void);
void                support_set_last_error (unsigned long);

TSupErr support_set_impersonate (int delayed, int hsmmode, int kb2mode);

/* Thread Local Storage. Склад для данных, уникальных для каждой нити. */
TSupErr support_set_thread_specific (unsigned int key, const void * ptr, void **old_ptr);
void * support_get_thread_specific (unsigned int key);
TSupErr support_tskey_create (unsigned int* key);
TSupErr support_tskey_delete (unsigned int key);

TSupErr support_thread_actualize_uids ( void );
TSupErr support_thread_deactualize_uids ( void );

#if defined WIN32 && !defined CSP_LITE
_SUPPORT_DECL TSupErr support_mutex_open_fun(
    TSupportMutex *mutex, const TCHAR *name, unsigned flags );

_SUPPORT_DECL TSupErr support_event_open_fun(
    TSupportEvent *event, const TCHAR *name );
#endif

#if defined( _WIN32 )
_SUPPORT_DECL TSupErr support_shared_memory_create( 
    TSupportSharedMemory **shared, const TCHAR *file_name, const TCHAR *lock_name,
    size_t sizeof_shared );
_SUPPORT_DECL TSupErr support_shared_memory_remove( 
    TSupportSharedMemory *shared );
_SUPPORT_DECL void* support_shared_memory_lock( 
    TSupportSharedMemory *shared );
_SUPPORT_DECL TSupErr support_shared_memory_unlock( 
    TSupportSharedMemory *shared );
#endif /* _WIN32 */

_SUPPORT_DECL const TSupportFunAddress*
    support_get_proc_address( size_t *size );

/* Функция получения строкового параметра. */
_SUPPORT_DECL TSupErr support_registry_get_string(
    const TCHAR *path, size_t *length, TCHAR *dest );

_SUPPORT_DECL TSupErr support_registry_get_multi_string(
    const TCHAR *path, size_t *length, TCHAR *dest );

/* Функция получения long параметра. */
_SUPPORT_DECL TSupErr support_registry_get_long(
    const TCHAR *path, long *dest );

/* Функция получения long параметра. */
_SUPPORT_DECL TSupErr support_registry_get_long_long(
    const TCHAR *path, long long *dest );

/* Функция получения Boolean параметра. */
_SUPPORT_DECL TSupErr support_registry_get_bool(
    const TCHAR *path, int *dest );

/* Функция получения нетипизированного параметра. */
_SUPPORT_DECL TSupErr support_registry_get_hex(
    const TCHAR *path, size_t *size, void *dest );

/* Функция записи строкового параметра. */
_SUPPORT_DECL TSupErr support_registry_put_string(
    const TCHAR *path, const TCHAR *src );

/* Функция записи строкового параметра. */
_SUPPORT_DECL TSupErr support_registry_put_multi_string(
    const TCHAR *path, const TCHAR *src );

/* Функция записи long параметра. */
_SUPPORT_DECL TSupErr support_registry_put_long(
    const TCHAR *path, long src );

/* Функция записи long long параметра. */
_SUPPORT_DECL TSupErr support_registry_put_long_long(
    const TCHAR *path, long long src );

/* Функция записи Boolean параметра. */
_SUPPORT_DECL TSupErr support_registry_put_bool(
    const TCHAR *path, int src );

/* Функция записи нетипизированного параметра. */
_SUPPORT_DECL TSupErr support_registry_put_hex(
    const TCHAR *path, size_t size, const void *src );

#if defined _WIN32
/* Функция записи access control list на параметр или секцию. */
_SUPPORT_DECL TSupErr support_registry_put_acl(
    const TCHAR *path, const void *src );

/* Функция записи system access control list на параметр или секцию. */
_SUPPORT_DECL TSupErr support_registry_put_sacl(
	const TCHAR *path, const void *src );

#   ifndef UNDER_CE
/* Функция установки "особого" process id. */
_SUPPORT_DECL TSupErr support_current_process_id_set(unsigned int id);

/* Функция получения "особого" process id или GetCurrentProcessID, если не установлен. */
_SUPPORT_DECL unsigned int support_current_process_id_get();

#   endif/*UNDER_CE*/

#endif /* WIN32 */

#if defined (_WIN32) && !defined (CSP_LITE) && !defined (WINCE)
/* Функция получения параметра PP_KEYSET_SEC_DESCR ветки реестра где лежит ключ. */
_SUPPORT_DECL TSupErr support_get_PP_KEYSET_SEC_DESCR( BYTE *pbData, DWORD *pdwDataLen);
#endif

/* Функция записи секции. */
_SUPPORT_DECL TSupErr support_registry_put_section(
    const TCHAR *path, const TCHAR *src );

/* Функция проверки существования секции. */
_SUPPORT_DECL TSupErr support_registry_test_section( 
    const TCHAR *path );

/* Функция удаления параметра из реестра. */
_SUPPORT_DECL TSupErr support_registry_delete_param(
    const TCHAR *path, const TCHAR *src );

/* Функция удаления секции из реестра. */
_SUPPORT_DECL TSupErr support_registry_delete_section(
    const TCHAR *path, const TCHAR *src );

/* Функция открытия контекста. */
_SUPPORT_DECL TSupErr support_registry_search_open(
    const TCHAR *path, TSupportRegistrySearchContext **context,
    size_t *max_name, int subkey );

/* Функция дублирования контекста поиска. */
_SUPPORT_DECL TSupErr support_registry_search_cpy(
    TSupportRegistrySearchContext **dest,
    TSupportRegistrySearchContext *src );

/* Функция дублирования контекста поиска. */
_SUPPORT_DECL int support_registry_search_cmp(
    TSupportRegistrySearchContext *left,
    TSupportRegistrySearchContext *right );

/* Функция закрытия контекста. */
_SUPPORT_DECL TSupErr support_registry_search_close(
    TSupportRegistrySearchContext *context );

/* Функция сдвига указателя контекста поиска. */
_SUPPORT_DECL TSupErr support_registry_search_next(
    TSupportRegistrySearchContext *context,
    TSupportRegistrySearchValue **right );

/* Функция поиска значения. */
_SUPPORT_DECL TSupErr support_registry_find(
    const TCHAR *path, TSupportRegistrySearchValue **value );

_SUPPORT_DECL int support_registry_value_cmp(
    const TSupportRegistrySearchValue *left,
    const TSupportRegistrySearchValue *right );

_SUPPORT_DECL TSupErr support_registry_value_cpy(
    TSupportRegistrySearchValue **left,
    const TSupportRegistrySearchValue *right );

/* Функция освобождения значения. */
_SUPPORT_DECL TSupErr support_registry_value_free(
    TSupportRegistrySearchValue *src );

_SUPPORT_DECL TSupErr support_registry_value_string(
    const TSupportRegistrySearchValue *src, size_t *length, TCHAR *dest );

_SUPPORT_DECL TSupErr support_registry_value_multi_string(
    const TSupportRegistrySearchValue *src, size_t *length, TCHAR *dest );

/* Функция получения long параметра. */
_SUPPORT_DECL TSupErr support_registry_value_long(
    const TSupportRegistrySearchValue *src, long *dest );

_SUPPORT_DECL TSupErr support_registry_value_long_long(
    const TSupportRegistrySearchValue *src, long long *dest );

_SUPPORT_DECL TSupErr support_registry_value_bool(
    const TSupportRegistrySearchValue *src, int *dest );

_SUPPORT_DECL TSupErr support_registry_value_hex(
    const TSupportRegistrySearchValue *src, size_t *size, void *dest );

_SUPPORT_DECL TSupErr support_registry_value_type(
    const TSupportRegistrySearchValue *src, TSupType *type, size_t *size );

_SUPPORT_DECL TSupErr support_registry_value_name(
    const TSupportRegistrySearchValue *src, size_t *length, TCHAR *dest );

/* Функция получения имени секции. */
_SUPPORT_DECL TSupErr support_registry_get_section(
    TSupportRegistrySearchContext *context, size_t size, TCHAR *dest );

/* Функция получения имени параметра. */
_SUPPORT_DECL TSupErr support_registry_get_param(
    TSupportRegistrySearchContext *context, size_t length, TCHAR *dest );

/* Функция получения типа пути. */
_SUPPORT_DECL TSupErr support_registry_type(
    const TCHAR *path, TSupType *type, size_t *size );

/* Функция получения типа пути. */
_SUPPORT_DECL TSupErr support_registry_check_access(
    const TCHAR *path, TSupAccess *acc );

#ifdef NO_SUP_NOTIFICATOR
#ifdef _MSC_VER
#pragma warning (disable:4127)
#endif
#define support_registry_notify_set(a,b,n) ((*(n)=(TSupRegNotificator*)1),SUP_ERR_NO)
#define support_registry_notify_is(n) SUP_ERR_CANCEL
#define support_registry_notify_done(n) (((n)=NULL),SUP_ERR_NO)
#else /* !NO_SUP_NOTIFICATOR */
_SUPPORT_DECL TSupErr support_registry_notify_set(
    const TCHAR *path, unsigned flags, TSupRegNotificator **notificator );

_SUPPORT_DECL TSupErr support_registry_notify_is(
    TSupRegNotificator *notificator );

_SUPPORT_DECL TSupErr support_registry_notify_done(
    TSupRegNotificator *notificator );
#endif /* !NO_SUP_NOTIFICATOR */

/* Функция получения строки по коду ошибки. */
_SUPPORT_DECL TSupErr support_error_text(
    TSupErr err, size_t *length, TCHAR *dest );

/* Функция получения строки из псевдо-ресурса. */
_SUPPORT_DECL TSupErr support_resource_string(
    TSupResourceInstance instance, size_t ids, TCHAR *dest, size_t *length );

/* Функция получения произвольной именованой строки из ресурса VersionInfo */
_SUPPORT_DECL TSupErr support_resource_version_string(
    TCHAR *target,
    TSupResourceInstance instance, TCHAR *dest, size_t *length );

/* Функция получения copyright из псевдо-ресурса. */
_SUPPORT_DECL TSupErr support_resource_copyright(
    TSupResourceInstance instance, TCHAR *dest, size_t *length );

/* Функция получения компании производителя из псевдо-ресурса. */
_SUPPORT_DECL TSupErr support_resource_company(
    TSupResourceInstance instance, TCHAR *dest, size_t *length );

/* Функция получения номера версии из псевдо-ресурса. */
_SUPPORT_DECL TSupErr support_resource_version(
    TSupResourceInstance instance, unsigned int dest[4] );

/* Функция получения иконки из псевдо-ресурса. */
_SUPPORT_DECL TSupErr support_resource_icon(
    TSupResourceInstance instance, size_t idi, TSupIcon *dest );

_SUPPORT_DECL TSupErr support_icon_free(
    TSupIcon bitmap );

/* Функция получения иконки из псевдо-ресурса. */
_SUPPORT_DECL TSupErr support_resource_bitmap(
    TSupResourceInstance instance, size_t idi, TSupBitMap *dest );

_SUPPORT_DECL TSupErr support_bitmap_free(
    TSupBitMap bitmap );

_SUPPORT_DECL TSupErr support_path2dir(
    const TCHAR *src, size_t *length, TCHAR *dest );

_SUPPORT_DECL TSupErr support_opendir(
    const TCHAR *path, size_t *max_path, TSupFileEnum **ctx );

_SUPPORT_DECL TSupErr support_nextent(
    TSupFileEnum *ctx, TCHAR *name, TSupFileType *type );

_SUPPORT_DECL TSupErr support_closedir(
    TSupFileEnum *ctx );

/* Thread-safe заменители функции strtok(). */
_SUPPORT_DECL TSupErr support_strtok(
    char *strToken, const char *strDelimit, char **strResult, char **strNext );

_SUPPORT_DECL TSupErr support_tcstok(
    TCHAR *strToken, const TCHAR *strDelimit, TCHAR **strResult, TCHAR **strNext );

/* Функция получения идентификатора текущего пользователя. */
_SUPPORT_DECL TSupErr support_user_id(
    size_t *length, TCHAR *dest );

#if defined UNIX && !defined CSP_LITE
#include <unistd.h>
/* Функция получения идентификаторов текущего пользователя. */
_SUPPORT_DECL TSupErr support_user_id_ex(
    size_t *length, TCHAR *dest,
    uid_t *euid,  uid_t *egid );

/* Функция временной смены текущего пользователя. */
_SUPPORT_DECL TSupErr support_impersonate_user_by_uids (
    uid_t euid,  uid_t egid );
#endif	/* UNIX && !CSP_LITE */

/* Функция получения имени текущего пользователя. */
_SUPPORT_DECL TSupErr support_user_name(
    TCHAR *dest, size_t *length );

/* Функция временной смены текущего пользователя. */
_SUPPORT_DECL TSupErr support_impersonate_user (
    const TCHAR *id );

/* Функция возвращения исходного пользователя. */
_SUPPORT_DECL TSupErr support_revert_to_self (void);

/* Функция получения точного текущего времени. */
//_SUPPORT_DECL TSupErr
//support_compound_time(long long *lpCompoundCount);

/* Функция получения текущего времени. */
_SUPPORT_DECL TSupErr support_gettimeofday (
    support_timeval * stv);

/* Функция установки заданного в секундах времени. */
_SUPPORT_DECL TSupErr support_time_set (
    support_timeval * tv_res, long secs);

/* Функция сравнения и вычитания времени. tv_res = tv1 - tv2 */
_SUPPORT_DECL TSupErr support_time_sub (
    const support_timeval * tv1, const support_timeval * tv2,
    support_timeval * tv_res, int* cmp);

/* Функция сложения времени. tv_res = tv1 + tv2 */
_SUPPORT_DECL TSupErr support_time_add (
    const support_timeval * tv1, const support_timeval * tv2,
    support_timeval * tv_res);

/* Функция копирования времени. tv_res = tv. */
_SUPPORT_DECL TSupErr support_time_cpy (
    support_timeval * tv_res, const support_timeval * tv);

#ifndef CSP_LITE
    _SUPPORT_DECL TSupErr support_time2tm(
	support_timeval * tv_src, struct tm * tm_dest);

    _SUPPORT_DECL TSupErr support_tm2time(
	struct tm * tm_src, support_timeval * tv_dest );
#endif /* CSP_LITE */

#if defined WIN32 && !defined CSP_LITE
    _SUPPORT_DECL TSupErr create_thread_same_rights(
	TSupFun fun, void* info, HANDLE *thread );

    _SUPPORT_DECL TSupErr descriptor_get_null(
	PSECURITY_DESCRIPTOR *ppSD );

    _SUPPORT_DECL TSupErr descriptor_free(
	PSECURITY_DESCRIPTOR pSD );
#endif /* not UNIX */

_SUPPORT_DECL int CRWLock_Initialize (CRWLock * lock, void *arg);
_SUPPORT_DECL TSupErr CRWLock_Cleanup (CRWLock * lock);
_SUPPORT_DECL TSupErr CRWLock_Claim (CRWLock * lock, CRWLockMode mode);
_SUPPORT_DECL TSupErr CRWLock_Release (CRWLock * lock, CRWLockMode mode);

#if !defined _WIN32
    _SUPPORT_DECL size_t safe_mbsrtowcs( wchar_t *dest,
	const char *src, size_t len);
    _SUPPORT_DECL size_t safe_wcsrtombs( char *dest,
	const wchar_t *src, size_t len);
#endif

#if !defined CSP_LITE && defined UNIX
    /* Функция запуска внешнего приложения. */
    _SUPPORT_DECL int support_system(
	TCHAR *cmd );
#endif

TSupModuleInstance support_load_library_registry(
    const TCHAR *dll_name, int def );
TSupModuleInstance support_load_library_registry_no_callee_check(
    const TCHAR *dll_name, int def );


void support_unload_library_registry(TSupModuleInstance handle);
TSupProc support_load_library_getaddr(TSupModuleInstance handle,
    const char *name);
TSupModuleInstance support_load_dll(TCHAR *path, int mode);
void support_unload_dll( TSupModuleInstance handle );

TSupErr support_registry_get_app_path(
    const TCHAR *path, size_t *length, TCHAR *dest );
TSupErr support_registry_get_app_path_no_callee_check(
    const TCHAR *path, size_t *length, TCHAR *dest );

/* Прогрузка библиотеки. */
_SUPPORT_DECL TSupErr support_load_library( void );

/* Выгрузка библиотеки. */
_SUPPORT_DECL void support_unload_library( void );

/* нужно при сборке CAdES на Linux */
#if defined UNDER_CE || defined UNIX
# ifndef TLS_OUT_OF_INDEXES
#   define TLS_OUT_OF_INDEXES ((DWORD)0xFFFFFFFF)
# endif
#endif /* UNDER_CE || UNIX */

//поддержка Windows CE
#ifdef UNDER_CE

# ifndef GetUserName
#   define GetUserName(x,y) GetUserNameEx(NameWindowsCeLocal,x,y)
# endif

# define GetConsoleOutputCP GetACP

# define LongToPtr( l )   ((VOID *)(LONG_PTR)((long)l))
# define ULongToHandle( ul ) ((HANDLE)(ULONG_PTR) (ul) )
# define UlongToHandle(ul) ULongToHandle(ul)
#endif /*UNDER_CE*/

#if !defined(SUPPORT_ALIGN)
#   define SUPPORT_ALIGN	16
#endif

#define support__empty__

#define support_align_var(type, var)                    \
    support_align_n(type, SUPPORT_ALIGN, var, support__empty__)

#define support_align_array(type, var, add)             \
    support_align_n(type, SUPPORT_ALIGN, var, add)

#if defined(_AIX)
	// Не работает на стеке
#   define support_align_n(typ, alg, var, add)		\
	typ __align(alg) var add
#elif defined(__SUNPRO_C) || defined (__SUNPRO_CC)
	// Не работает на стеке
#   define sa_da_pragma(p)	_Pragma(#p)
#   define support_align_n(typ, alg, var, add)		\
	sa_da_pragma(align alg ( var ))			\
	typ var add
#elif defined(__GNUC__)
	// Не работает на стеке
#   define support_align_n(typ, alg, var, add)		\
	typ var add __attribute__ ((aligned (alg)))
#elif defined(_WIN32)
	// Работает на стеке
#   define support_align_n(typ, alg, var, add)		\
	__declspec(align(alg)) typ var add
#else
#   error "Can't support align"
#endif

#if defined(_AIX)
#   if defined(__STDC__) && defined __STDC_VERSION__ && __STDC_VERSION__ - 0 >= 199901L
#       define SUPPORT_RESTRICT restrict
#   else
#       define SUPPORT_RESTRICT __restrict
#   endif
#elif defined(__SUNPRO_C) || defined(__SUNPRO_CC)
#   if defined(__STDC__) && defined __STDC_VERSION__ && __STDC_VERSION__ - 0 >= 199901L
#       define SUPPORT_RESTRICT restrict
#   else
#       define SUPPORT_RESTRICT
#   endif
#elif defined(__GNUC__)
#   if defined(__STDC__) && defined __STDC_VERSION__ && __STDC_VERSION__ - 0 >= 199901L
#       define SUPPORT_RESTRICT restrict
#   else
#       define SUPPORT_RESTRICT __restrict
#   endif
#elif defined(_WIN32)
#   define SUPPORT_RESTRICT     __restrict
#else
#   error "Can't support restrict"
#endif

    /* Функции управления памятью */
enum support_mlockall_ {
    SUPPORT_MCL_CURRENT = 1,
    SUPPORT_MCL_FUTURE = 2
};
typedef int support_mlockall_t;	// TODO: подумать Оказывается нужна опреация `|'

typedef enum support_mprotect_ {
    SUPPORT_PROT_EXEC,
    SUPPORT_PROT_NONE,
    SUPPORT_PROT_READ,
    SUPPORT_PROT_WRITE
} support_mprotect_t;

typedef enum support_mmap_ {
    SUPPORT_MAP_FIXED,
    SUPPORT_MAP_PRIVATE,
    SUPPORT_MAP_SHARED
} support_mmap_t;

#if defined CSP_LITE || defined WINCE 
    typedef long support_off_t;  // TODO: нужен ptrdiff_t или intptr_t (INT_PTR не подходит тоже)
#else
    #include <sys/types.h>

    typedef off_t support_off_t;
#endif

#define SUPPORT_MAP_FAILED  (NULL)

_SUPPORT_DECL int 
support_mlockall(support_mlockall_t flags);
_SUPPORT_DECL int 
support_munlockall(void); 
_SUPPORT_DECL support_mlockall_t 
support_get_mlockall(void); 
_SUPPORT_DECL void *
support_mmap(void *addr, size_t len, 
	     support_mprotect_t prot, support_mmap_t flags,
	     int fildes, support_off_t off);
_SUPPORT_DECL int 
support_munmap(void *addr, size_t len);
_SUPPORT_DECL int 
support_mprotect(void *addr, size_t len, support_mprotect_t prot);

#ifdef UNIX
# define SUP_INLINE inline
#else
# define SUP_INLINE __inline
#endif

#if !defined(CSP_LITE) && !defined(WINCE) && !defined(BUG_IN_KERNEL_SPACE_C)
# if defined(UNIX) 
    typedef uint16_t WIN_WCHAR_T;

    static SUP_INLINE 
    size_t support_utf16le_len(const WIN_WCHAR_T * src)
    {
	size_t n;
	for (n=0;src[n];n++)
	    ;
	return n;
    }

    static SUP_INLINE 
    size_t support_utf16le_nlen(const WIN_WCHAR_T * src, 
				size_t maxlen)
    {
	size_t n;
	for (n=0; n < maxlen && src[n];n++)
	    ;
	return n;
    }

    _SUPPORT_DECL TSupErr 
    support_to_utf16le(const char * encoding, 
			WIN_WCHAR_T * dst, 
			size_t * pdlen, 
			const TCHAR * src, 
			size_t slen);

    _SUPPORT_DECL TSupErr 
    support_from_utf16le(const char * encoding, 
			 TCHAR * dst, 
			 size_t * pdlen, 
			 const WIN_WCHAR_T * src, 
			 size_t slen);
# else /* defined(UNIX) */
    typedef wchar_t WIN_WCHAR_T;

#   define support_utf16le_len(src) wcslen(src)
#   define support_utf16le_nlen(src,maxlen) wcsnlen((src),(maxlen))

#   ifdef UNICODE
	TSupErr SUP_INLINE 
	support_to_utf16le(const char * encoding, 
			   WIN_WCHAR_T * dst, 
			   size_t * pdlen, 
			   const TCHAR * src, 
			   size_t slen)
	{
	    size_t len;
	    (void)(encoding); // TODO:XXX UNUSED(encoding);
	    if (pdlen == NULL || src == NULL)
		return SUP_ERR_PARAM;
	    // TODO: wcsncpy_s(dst, 1+*pdlen, src, slen+1);
	    len = wcsnlen(src, slen);
	    if (dst == NULL)
	    {
		*pdlen=len;
		return SUP_ERR_MEMORY;
	    }
	    if (*pdlen >= len)
	    {
		wcsncpy_s(dst, 1+*pdlen, src, len+1);
		return SUP_ERR_NO;
	    }
	    else
	    {
		wcscpy_s(dst, 1+*pdlen, src);
		return SUP_ERR_MEMORY;
	    }
	}

	TSupErr SUP_INLINE 
	support_from_utf16le(const char * encoding, 
			     TCHAR * dst, 
			     size_t * pdlen, 
			     const WIN_WCHAR_T * src, 
			     size_t slen)
	{
	    size_t len;
	    (void)(encoding); // TODO:XXX UNUSED(encoding);
	    if (pdlen == NULL || src == NULL)
		return SUP_ERR_PARAM;
	    // TODO: wcsncpy_s(dst, 1+*pdlen, src, slen+1);
	    len=wcsnlen(src,slen);
	    if (dst == NULL)
	    {
		*pdlen=len;
		return SUP_ERR_MEMORY;
	    }
	    if (*pdlen >= len) 
	    {
		wcsncpy_s(dst, 1+*pdlen, src, len+1);
		return SUP_ERR_NO;
	    }
	    else
	    {
		wcscpy_s(dst, 1+*pdlen, src);
		return SUP_ERR_MEMORY;
	    }
	}
#   else
	TSupErr SUP_INLINE 
	untested_support_to_utf16le(const char * encoding, 
				    WIN_WCHAR_T * dst, 
				    size_t * pdlen, 
				    const TCHAR * src, 
				    size_t slen)
	{
	    size_t alloclen = 0;
	    (void)(encoding); // TODO:XXX UNUSED(encoding);
	    (void)(slen); // TODO:XXX UNUSED(encoding);

	    if (pdlen == NULL || src == NULL)
		return SUP_ERR_PARAM;
	    if (dst) {
		alloclen = 1 + *pdlen;
	    }
	    if(mbstowcs_s(pdlen, dst, alloclen, src, alloclen-1) ||
		NULL == dst) {
		    return SUP_ERR_MEMORY;
	    }
	    return SUP_ERR_NO;
	}

	TSupErr SUP_INLINE 
	untested_support_from_utf16le(const char * encoding, 
				      TCHAR * dst, 
				      size_t * pdlen, 
				      const WIN_WCHAR_T * src, 
				      size_t slen)
	{
	    size_t alloclen = 0;
	    (void)(encoding); // TODO:XXX UNUSED(encoding);
	    (void)(slen); // TODO:XXX UNUSED(encoding);

	    if (pdlen == NULL || src == NULL)
		return SUP_ERR_PARAM;
	    if (dst) {
		alloclen = 1 + *pdlen;
	    }
	    if(wcstombs_s(pdlen, dst, alloclen, src, alloclen-1) ||
		NULL == dst) {
		return SUP_ERR_MEMORY;
	    }
	    return SUP_ERR_NO;
	}
#   endif
# endif /* defined(UNIX) */
#endif /* defined(CSP_LITE) */




#if defined( __cplusplus )
}
#endif /* defined( __cplusplus ) */

#endif /* !defined( _READER_SUPPORT_SUPPORT_H ) */
/*+ end of file:$Id: support.h 67125 2011-03-25 11:56:59Z dim $ +*/

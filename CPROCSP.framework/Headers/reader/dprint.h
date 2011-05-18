#ifndef DPRINT_H_INCLUDED
#define DPRINT_H_INCLUDED 1

#include<CPROCSP/reader/support.h>

/* Before including this file one can set something like this: */

// Способы журналирования (постфиксы к ф-циям журналировани):
// ERRO (eprint_func)
//   Unix: Sys Log (LOG_ERR)
//   Windows: Debugger Log
//   Mobile: Debugger Log
//
// NORM (dprint_func)
//   Unix: Sys Log (LOG_INFO)
//   Windows: Debugger Log
//   Mobile: Debugger Log
//
// CONS (cprint_func)
//   Unix: Console
//   Windows: Console
//   Mobile: Console
//
// ELOG (elprint_func)
//   Unix: = ERRO = Sys Log (LOG_ERR)
//   Windows: Event Log
//   Mobile: = ERRO = Debugger Log
//
// EXCL (NULL)
//   Unix: None
//   Windows: None
//   Mobile: None
//
// TODO: видно, что в текущей реализации есть недостатки:
// в отличие от Unix на Windows нет различий событий в Event Log.
// Можно удалить уровень ELOG и сделать инициализацию на Windows
// зависимой от DEBUG:
//   в Release - всё в Event Log по ERRO и NORM - с разными событиями
//   в Debug - всё в Debugger Log - как раньше
// При этом в старые реализации надо добавить параметры ELOG,
// которые будут неиспользуемыми при старом поведении.

#ifndef DB_ERROR
# if defined _DEBUG
// В Debug пишем всё в Debugger Log - там фильтровать удобней
#      define DB_ERROR ERRO
#      define DB_TRACE NORM
#      define DB_CALL NORM
#      define DB_LOG NORM
#      define DB_UNUSUAL EXCL
# else
// В Release пишем почти всё в Event Log
#      define DB_ERROR ELOG
#      define DB_TRACE EXCL
#  ifdef UNIX
#      define DB_CALL EXCL
#      define DB_LOG NORM
#  else /* UNIX */
#      define DB_CALL EXCL
#      define DB_LOG ELOG
#  endif /* UNIX */
#      define DB_UNUSUAL EXCL
# endif /* _DEBUG */
#endif

#define SUPPORT_DBFMT_MODULE 1
#define SUPPORT_DBFMT_THREAD 2
#define SUPPORT_DBFMT_FLINE 4
#define SUPPORT_DBFMT_FUNC 8
#define SUPPORT_DBFMT_TEXT 0x10
#define SUPPORT_DBFMT_HEX 0x20
#define SUPPORT_DBFMT_ERR 0x40

#define SUPPORT_DBFMT_ALL 0x7F
#define SUPPORT_DBFMT_CLEAN 0x30
#define SUPPORT_DBLEVEL_ALL 0xffffffffU

#define NCOUNT(x) x
#define CONCAT_COUNT(x,y) NCOUNT(x)##NCOUNT(y)
#define CONCAT(x,y) x##y

#define __STR2WSTR(str)	L##str
#define _STR2WSTR(str)	__STR2WSTR(str)

#if defined( _MSC_VER ) 
# if defined UNICODE
#   define SFUNC _STR2WSTR(__FUNCTION__)
# else
#   define SFUNC __FUNCTION__
# endif
#elif defined(__GNUC__)
# if (__GNUC__ == 2)
#   define SFUNC __FUNCTION__
# else /*(__GNUC__ == 2)*/
#   define SFUNC __func__
# endif  /*(__GNUC__ == 2)*/
#else /*defined( _MSC_VER ) */
#   define SFUNC __func__
#endif /*defined( _MSC_VER ) */

#define DCHAR TCHAR
#define __DTEXT(x) _TEXT(x)
#define DTEXT(x) __DTEXT(x)
#if defined _WIN32 && defined UNICODE
#   define __DFILE__ CONCAT_COUNT(L,__FILE__)
#   define D2A "%S"
#   define D2W "%s"
#else
#   define __DFILE__ __FILE__
#   define D2A "%s"
#   define D2W "%S"
#endif

//для печати TCHAR * в ASCII функции
#ifdef _UNICODE
#define _T2A "%S"
#else
#define _T2A "%s"
#endif

//для печати WCECHAR
#if defined ( WINCE )
#define _WCE2A "%S"
#define D2WCE D2W
#else
#define _WCE2A "%s"
#define D2WCE D2A
#endif

#if defined _WIN32
#define DBSTR(x) x
#define DBSTRA(x) x
#define DBSTRW(x) x
#else
#define DBSTR(x) (x?x:_TEXT("null"))
#define DBSTRA(x) (x?x:"null")
#define DBSTRW(x) (x?x:L"null")
#endif

#if defined ( WINCE )
#define DBSTRWCE(x) DBSTRW(x)
#else
#define DBSTRWCE(x) DBSTRA(x)
#endif

#define SUPPORT_DBFTEXT_(x) x, __DFILE__, __LINE__, SFUNC
#define SUPPORT_DBFTEXTR_(x) x, DTEXT(""), __LINE__, SFUNC

#if defined _DEBUG
#define FTEXT(ctx,a) ctx,SUPPORT_DBFTEXT_(DTEXT(a))
#define FTEXT2(ctx,a,b) ctx,SUPPORT_DBFTEXT_(DTEXT(a) DTEXT(b))
#define FTEXT3(ctx,a,b,c) ctx,SUPPORT_DBFTEXT_(DTEXT(a) DTEXT(b) DTEXT(c))
#define FTEXT4(ctx,a,b,c,d) ctx,SUPPORT_DBFTEXT_(DTEXT(a) DTEXT(b) DTEXT(c) DTEXT(d))
#define FTEXT5(ctx,a,b,c,d,e) ctx,SUPPORT_DBFTEXT_(DTEXT(a) DTEXT(b) DTEXT(c) DTEXT(d) DTEXT(e))
#else
#define FTEXT(ctx,a) ctx,SUPPORT_DBFTEXTR_(DTEXT(a))
#define FTEXT2(ctx,a,b) ctx,SUPPORT_DBFTEXTR_(DTEXT(a) DTEXT(b))
#define FTEXT3(ctx,a,b,c) ctx,SUPPORT_DBFTEXTR_(DTEXT(a) DTEXT(b) DTEXT(c))
#define FTEXT4(ctx,a,b,c,d) ctx,SUPPORT_DBFTEXTR_(DTEXT(a) DTEXT(b) DTEXT(c) DTEXT(d))
#define FTEXT5(ctx,a,b,c,d,e) ctx,SUPPORT_DBFTEXTR_(DTEXT(a) DTEXT(b) DTEXT(c) DTEXT(d) DTEXT(e))
#endif

// Уровни отображения
typedef enum DBType_ {
  N_DB_ERROR = 1,
  N_DB_TRACE = 2,
  N_DB_CALL = 4,
  N_DB_LOG = 8,
  N_DB_UNUSUAL = 0x10
} DBType;

#if defined(__cplusplus) && !defined(__GNUC__)
    #define SUPPORT_DB_QPRINT_ERRO(level,param) \
        if( debug::support_print_qis_##level param ) support_eprint_print_ param
    #define SUPPORT_DB_QPRINT_NORM(level,param) \
        if( debug::support_print_qis_##level param ) support_dprint_print_ param
    #define SUPPORT_DB_QPRINT_CONS(level,param) \
        if( debug::support_print_qis_##level param ) support_cprint_print_ param
    #define SUPPORT_DB_QPRINT_ELOG(level,param) \
        if( debug::support_print_qis_##level param ) support_elprint_print_ param
    #define SUPPORT_DB_QPRINT_EXCL(level,param)
    #define SUPPORT_DB_QPRINT_HEX_ERRO(context,level,file,line,func,msg,buffer,length)\
        if( debug::support_print_qis_##level(context) ) support_eprint_hex(context,file,line,func,msg,buffer,length)
    #define SUPPORT_DB_QPRINT_HEX_NORM(context,level,file,line,func,msg,buffer,length)\
        if( debug::support_print_qis_##level(context) ) support_dprint_hex(context,file,line,func,msg,buffer,length)
    #define SUPPORT_DB_QPRINT_HEX_CONS(context,level,file,line,func,msg,buffer,length)\
        if( debug::support_print_qis_##level(context) ) support_cprint_hex(context,file,line,func,msg,buffer,length)
    #define SUPPORT_DB_QPRINT_HEX_ELOG(context,level,file,line,func,msg,buffer,length)\
        if( debug::support_print_qis_##level(context) ) support_elprint_hex(context,file,line,func,msg,buffer,length)
    #define SUPPORT_DB_QPRINT_HEX_EXCL(context,level,file,line,func,msg,buffer,length)
#else
    #define SUPPORT_DB_QPRINT_ERRO(level,param) \
        if( support_print_qis_##level param ) support_eprint_print_ param
    #define SUPPORT_DB_QPRINT_NORM(level,param) \
        if( support_print_qis_##level param ) support_dprint_print_ param
    #define SUPPORT_DB_QPRINT_CONS(level,param) \
        if( support_print_qis_##level param ) support_cprint_print_ param
    #define SUPPORT_DB_QPRINT_ELOG(level,param) \
        if( support_print_qis_##level param ) support_elprint_print_ param
    #define SUPPORT_DB_QPRINT_EXCL(level,param)
    #define SUPPORT_DB_QPRINT_HEX_ERRO(context,level,file,line,func,msg,buffer,length)\
        if( support_print_qis_##level(context) ) support_eprint_hex(context,file,line,func,msg,buffer,length)
    #define SUPPORT_DB_QPRINT_HEX_NORM(context,level,file,line,func,msg,buffer,length)\
        if( support_print_qis_##level(context) ) support_dprint_hex(context,file,line,func,msg,buffer,length)
    #define SUPPORT_DB_QPRINT_HEX_CONS(context,level,file,line,func,msg,buffer,length)\
        if( support_print_qis_##level(context) ) support_cprint_hex(context,file,line,func,msg,buffer,length)
    #define SUPPORT_DB_QPRINT_HEX_ELOG(context,level,file,line,func,msg,buffer,length)\
        if( support_print_qis_##level(context) ) support_elprint_hex(context,file,line,func,msg,buffer,length)
    #define SUPPORT_DB_QPRINT_HEX_EXCL(context,level,file,line,func,msg,buffer,length)
#endif //__cplusplus

#if defined ( WINCE ) && !defined ( _DEBUG )
// На CE для Release отключаем сообщения совсем, т.к. размер ужасно критичен!
#define NO_DB_TRACE
#endif // defined ( WINCE ) && !defined ( _DEBUG )

#if defined _WIN32 || defined UNIX
#ifdef NO_DB_TRACE
#define DbTrace(level, param) 
#define DbTraceHex(level, ctx, msg, buffer, length) 
#define DbTraceInit(ctx,info,module,level,format)
#define DbTraceDone(ctx) 
#else // !NO_DB_TRACE
#define DbTrace(level, param) CONCAT(SUPPORT_DB_QPRINT_,level)(N_##level,param)
#define DbTraceHex(level, ctx, msg, buffer, length) CONCAT(SUPPORT_DB_QPRINT_HEX_,level)(ctx,N_##level,__DFILE__,__LINE__,SFUNC,msg,buffer,length)
#define DbTraceInit(ctx,info,module,level,format) { ctx = support_print_init(info,module,level,format ); }
#define DbTraceDone(ctx) { support_print_done( ctx ); }
#endif // !NO_DB_TRACE
#endif

#ifdef __cplusplus
extern "C" {
#endif
struct TSupportDbContext_;

typedef struct TSupportDbContext_ TSupportDbContext;

extern TSupportDbContext* db_ctx;

/*!
 * \ingroup ProCPCCallbacks
 *
 * \brief Callback-функция для вывода сообщений.
 *
 * \param callback_arg [in] Параметр, переданный при регистрации callback-функции.
 *
 * \param str [in] Строка, которую нужно вывести. Не включает '\\n'.
 */
typedef void _SUPPORT_CALLBACK_CONV support_print_str_callback(void *callback_arg, const DCHAR *str);
typedef void support_print_str_ex_callback(void *callback_arg, const DCHAR *str, size_t data_size, void *raw_data);

/*!
 * \ingroup ProCPCCallbacks
 *
 * \brief Callback-функция для получения идентификатора потока.
 *
 * \return При успешном завершении функция возвращает идентификатор потока, в противном
 * случае возвращает 0.
 */
typedef unsigned long _SUPPORT_CALLBACK_CONV support_get_thread_id_callback(void);

/* DebugInfo dprint*/
_SUPPORT_DECL TSupErr _SUPPORT_CALLBACK_CONV
support_print_init_ex(TSupportDbContext* buf, size_t * sz, void *info,
		      const DCHAR *module, unsigned level, unsigned format,
		      support_print_str_callback *dprint_str, 
		      support_print_str_callback *eprint_str,
		      support_print_str_callback *cprint_str,
		      support_print_str_callback *elprint_str,
		      support_print_str_ex_callback *dprint_str_ex, 
		      support_print_str_ex_callback *eprint_str_ex,
		      support_print_str_ex_callback *cprint_str_ex,
		      support_print_str_ex_callback *elprint_str_ex,
		      support_get_thread_id_callback *get_thread_id,
		      void *callback_arg);
_SUPPORT_DECL TSupportDbContext* _SUPPORT_CALLBACK_CONV
support_print_init(void *info, const DCHAR *module, unsigned level,
		   unsigned format);
_SUPPORT_DECL TSupErr _SUPPORT_CALLBACK_CONV
support_print_done_ex(TSupportDbContext* ctx);
_SUPPORT_DECL TSupErr _SUPPORT_CALLBACK_CONV
support_print_done(TSupportDbContext* ctx);
_SUPPORT_DECL int _SUPPORT_CALLBACK_CONV
support_print_is(TSupportDbContext* ctx, unsigned when);


#if __GNUC__ /* doesn't like varargs in inline funcs */
#define support_print_qis_N_DB_ERROR(ctx, ...) (ctx && (*(unsigned*)(ctx)&N_DB_ERROR) && support_print_is(ctx, N_DB_ERROR))
#define support_print_qis_N_DB_TRACE(ctx, ...) (ctx && (*(unsigned*)(ctx)&N_DB_TRACE) && support_print_is(ctx, N_DB_TRACE))
#define support_print_qis_N_DB_CALL(ctx, ...) (ctx && (*(unsigned*)(ctx)&N_DB_CALL) && support_print_is(ctx, N_DB_CALL))
#define support_print_qis_N_DB_LOG(ctx, ...) (ctx && (*(unsigned*)(ctx)&N_DB_LOG) && support_print_is(ctx, N_DB_LOG))
#define support_print_qis_N_DB_UNUSUAL(ctx, ...) (ctx && (*(unsigned*)(ctx)&N_DB_UNUSUAL) && support_print_is(ctx, N_DB_UNUSUAL))
#else /* __GNUC__ */

#ifdef __cplusplus
    #if _DEBUG
    #define MAKE_QIS_FUNC(level) namespace debug{ static SUP_INLINE int support_print_qis_##level(TSupportDbContext *ctx, ...) {return ctx && support_print_is(ctx, level) && (*(unsigned*)(ctx)&level);}}
    #else
    #define MAKE_QIS_FUNC(level) namespace debug { static SUP_INLINE int support_print_qis_##level(TSupportDbContext *ctx, ...) {return ctx && (*(unsigned*)(ctx)&level) && support_print_is(ctx, level);}}
    #endif //_DEBUG
#else 
    #if _DEBUG
    #define MAKE_QIS_FUNC(level) static SUP_INLINE int support_print_qis_##level(TSupportDbContext *ctx, ...) {return ctx && support_print_is(ctx, level) && (*(unsigned*)(ctx)&level);}
    #else
    #define MAKE_QIS_FUNC(level) static SUP_INLINE int support_print_qis_##level(TSupportDbContext *ctx, ...) {return ctx && (*(unsigned*)(ctx)&level) && support_print_is(ctx, level);}
    #endif //_DEBUG
#endif //__cplusplus

MAKE_QIS_FUNC(N_DB_ERROR)
MAKE_QIS_FUNC(N_DB_TRACE)
MAKE_QIS_FUNC(N_DB_CALL)
MAKE_QIS_FUNC(N_DB_LOG)
MAKE_QIS_FUNC(N_DB_UNUSUAL)
#endif /* __GNUC__ */

_SUPPORT_DECL TSupErr
support_cprint_print(TSupportDbContext* ctx, const DCHAR *str,
		     const DCHAR *file, int line, const DCHAR *func,
		     va_list args);
_SUPPORT_DECL TSupErr
support_dprint_print(TSupportDbContext* ctx, const DCHAR *str,
		     const DCHAR *file, int line, const DCHAR *func,
		     va_list args);
_SUPPORT_DECL TSupErr
support_eprint_print(TSupportDbContext* ctx, const DCHAR *str,
		     const DCHAR *file, int line, const DCHAR *func,
		     va_list args);
_SUPPORT_DECL TSupErr
support_elprint_print(TSupportDbContext* ctx, const DCHAR *str,
		      const DCHAR *file, int line, const DCHAR *func,
		      va_list args);
_SUPPORT_DECL void
support_cprint_print_(TSupportDbContext* ctx, const DCHAR *str,
		      const DCHAR *file, int line, const DCHAR *func, ...);
_SUPPORT_DECL void
support_dprint_print_(TSupportDbContext* ctx, const DCHAR *str, 
		      const DCHAR *file, int line, const DCHAR *func, ...);
_SUPPORT_DECL void
support_eprint_print_(TSupportDbContext* ctx, const DCHAR *str,
		      const DCHAR *file, int line, const DCHAR *func, ...);
_SUPPORT_DECL void
support_elprint_print_(TSupportDbContext* ctx, const DCHAR *str,
		       const DCHAR *file, int line, const DCHAR *func, ...);
_SUPPORT_DECL TSupErr
support_dprint_hex(TSupportDbContext *ctx, const DCHAR *file, int line,
		   const DCHAR *func, const DCHAR *msg, void *info, size_t size);
_SUPPORT_DECL TSupErr
support_cprint_hex(TSupportDbContext *ctx, const DCHAR *file, int line,
		   const DCHAR *func, const DCHAR *msg, void *info, size_t size);
_SUPPORT_DECL TSupErr
support_eprint_hex(TSupportDbContext *ctx, const DCHAR *file, int line,
		   const DCHAR *func, const DCHAR *msg, void *info, size_t size);
_SUPPORT_DECL TSupErr
support_elprint_hex(TSupportDbContext *ctx, const DCHAR *file, int line,
		    const DCHAR *func, const DCHAR *msg, void *info, size_t size);

#ifdef __cplusplus
}
#endif

#endif /* DPRINT_H_INCLUDED */

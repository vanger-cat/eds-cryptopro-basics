#ifndef CALLCTX_H_INCLUDED
#define CALLCTX_H_INCLUDED 1
#include <reader/dprint.h>
#ifdef __cplusplus
extern "C" {
#endif


typedef struct _CP_CALL_CTX_ CP_CALL_CTX, *pCP_CALL_CTX;
typedef struct _CRYPT_CSP_ CRYPT_CSP, * LPCRYPT_CSP;

/* Реентерабельные варианты CSP_SetLastError/CSP_GetLastError */
extern	void	rCSP_SetLastError	(pCP_CALL_CTX pCallCtx, DWORD err);
extern	DWORD	rCSP_GetLastError	(pCP_CALL_CTX pCallCtx);

/* Реентерабельные варианты AllocMemory/FreeMemory */
extern	LPVOID	rAllocMemory	(pCP_CALL_CTX pCallCtx, size_t dwSize, DWORD dwMemPoolId);
extern	CSP_BOOL	rFreeMemory	(pCP_CALL_CTX pCallCtx, VOID *pMem, DWORD dwMemPoolId);

/*! Инициализация памяти */
extern	CSP_BOOL	rInitMemory	(pCP_CALL_CTX pCallCtx);

#if !defined UNIX
/*! Уничтожение всех куч */
extern	void	rDoneMemory	(pCP_CALL_CTX pCallCtx);
#endif /* !UNIX */
/*! Проверка целостности куч */
extern	void	rValidateMemory	(pCP_CALL_CTX pCallCtx);

extern	void	rInitCallCtx	(pCP_CALL_CTX pCallCtx, LPCRYPT_CSP hCSP);

struct _CP_CALL_CTX_
{
    LPCRYPT_CSP			hCSP;
    DWORD			dwError;
    DWORD			dwThreadId;
# if defined(PRO_MAP_ALLOC)
    long long			CtxId;
# endif    
};


#ifdef __cplusplus
}
#endif

#endif /* CALLCTX_H_INCLUDED */

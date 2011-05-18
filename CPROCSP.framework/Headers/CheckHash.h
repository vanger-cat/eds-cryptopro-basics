#if !defined( CHECKHASH_H )
#define CHECKHASH_H

#include<CPROCSP/serial.h>

#ifdef __cplusplus
extern "C" {
#endif

BYTE FROM_5_BIT(TCHAR x);

CSP_BOOL Decode5Bit( const TCHAR *tszSrc, DWORD cbSrc, BYTE *pbRes, DWORD dwResSize );
CSP_BOOL Encode5Bit(LPBYTE pbSrc, DWORD cbSrc, LPTSTR tszRes, DWORD dwResSize );

CSP_BOOL CheckSerialHash(pCP_CALL_CTX pCallCtx, pCSP_HASH_FUNCS HashFuncs, const SerialConfiguration *config, LPCTSTR , LPCTSTR , UINT );

CSP_BOOL CheckSerialDateHash( pCSP_HASH_FUNCS HashFuncs, const TCHAR *szTime, const TCHAR *Hash );
CSP_BOOL MakeSerialDateHash(pCSP_HASH_FUNCS HashFuncs, const TCHAR *szTime, LPTSTR res );

#ifdef __cplusplus
}
#endif
#endif

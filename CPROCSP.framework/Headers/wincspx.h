/*
 * Copyright(C) 2001 Проект ИОК
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

/*!
 * \file $RCSfile$
 * \version $Revision: 2532 $
 * \date $Date: 2001-03-05 15:28:16 +0300 (РїРЅ, 05 РјР°СЂ 2001) $
 * \author $Author: pre $
 *
 * \brief Интерфейс Microsoft Cryptography Service Provider.
 * Набор макросов, скрывающий обращения к CAPI и CPAPI
 * Позволяет переключаться без изменения кода между CAPI
 * и CPAPI (между функциями с префиксами Crypto и CP).
 */
#ifndef _WINCSPX_H_INCLUDED
#define _WINCSPX_H_INCLUDED

#ifdef USE_CPAPI
#include <atlconv.h>
#include<CPROCSP/wincsp.h>
#endif /* !USE_CPAPI */

#ifdef USE_CPAPI
#define CRYPT_AcquireContext(phProv,pszContainer,pszProvider,dwProvType,dwFlags,pVTable) \
    CPAcquireContext (phProv, T2A(pszContainer), dwFlags, pVTable)
#else /* !USE_CPAPI */
#define CRYPT_AcquireContext(phProv,pszContainer,pszProvider,dwProvType,dwFlags,pVTable) \
    CryptAcquireContext (phProv, pszContainer, pszProvider, dwProvType, dwFlags)
#endif /* !USE_CPAPI */

#ifdef USE_CPAPI
#define CRYPT_CreateHash(hProv, AlgId, hKey, dwFlags, phHash) \
    CPCreateHash(hProv, AlgId, hKey, dwFlags, phHash)
#else /* !USE_CPAPI */
#define CRYPT_CreateHash(hProv, AlgId, hKey, dwFlags, phHash) \
    CryptCreateHash(hProv, AlgId, hKey, dwFlags, phHash)
#endif /* !USE_CPAPI */

#ifdef USE_CPAPI
#define CRYPT_Decrypt(hProv, hKey, hHash, Final, dwFlags, pbData, pdwDataLen) \
    CPDecrypt(hProv, hKey, hHash, Final, dwFlags, pbData, pdwDataLen)
#else /* !USE_CPAPI */
#define CRYPT_Decrypt(hProv, hKey, hHash, Final, dwFlags, pbData, pdwDataLen) \
    CryptDecrypt(hKey, hHash, Final, dwFlags, pbData, pdwDataLen)
#endif /* !USE_CPAPI */

#ifdef USE_CPAPI
#define CRYPT_DeriveKey(hProv, AlgId, hBaseData, dwFlags, phKey) \
    CPDeriveKey(hProv, AlgId, hBaseData, dwFlags, phKey)
#else /* !USE_CPAPI */
#define CRYPT_DeriveKey(hProv, AlgId, hBaseData, dwFlags, phKey) \
    CryptDeriveKey(hProv, AlgId, hBaseData, dwFlags, phKey)
#endif /* !USE_CPAPI */

#ifdef USE_CPAPI
#define CRYPT_DestroyHash(hProv, hHash) \
    CPDestroyHash(hProv, hHash)
#else /* !USE_CPAPI */
#define CRYPT_DestroyHash(hProv, hHash) \
    CryptDestroyHash(hHash)
#endif /* !USE_CPAPI */

#ifdef USE_CPAPI
#define CRYPT_DestroyKey(hProv, hKey) \
    CPDestroyKey(hProv, hKey)
#else /* !USE_CPAPI */
#define CRYPT_DestroyKey(hProv, hKey) \
    CryptDestroyKey(hKey)
#endif /* !USE_CPAPI */

#ifdef USE_CPAPI
#define CRYPT_DuplicateKey(hProv, hKey, pdwReserved, dwFlags, phKey) \
    CPDuplicateKey(hProv, hKey, pdwReserved, dwFlags, phKey)
#else /* !USE_CPAPI */
#define CRYPT_DuplicateKey(hProv, hKey, pdwReserved, dwFlags, phKey) \
    CryptDuplicateKey(hKey, pdwReserved, dwFlags, phKey)
#endif /* !USE_CPAPI */

#ifdef USE_CPAPI
#define CRYPT_DuplicateHash(hProv, hHash, pdwReserved, dwFlags, phHash) \
    CPDuplicateHash(hProv, hHash, pdwReserved, dwFlags, phHash)
#else /* !USE_CPAPI */
#define CRYPT_DuplicateHash(hProv, hHash, pdwReserved, dwFlags, phHash) \
    CryptDuplicateHash(hHash, pdwReserved, dwFlags, phHash)
#endif /* !USE_CPAPI */

#ifdef USE_CPAPI
#define CRYPT_Encrypt(hProv, hKey, hHash, Final, dwFlags, pbData, pdwDataLen, dwBufLen) \
    CPEncrypt(hProv, hKey, hHash, Final, dwFlags, pbData, pdwDataLen, dwBufLen)
#else /* !USE_CPAPI */
#define CRYPT_Encrypt(hProv, hKey, hHash, Final, dwFlags, pbData, pdwDataLen, dwBufLen) \
    CryptEncrypt(hKey, hHash, Final, dwFlags, pbData, pdwDataLen, dwBufLen)
#endif /* !USE_CPAPI */

#ifdef USE_CPAPI
#define CRYPT_ExportKey(hProv, hKey, hExpKey, dwBlobType, dwFlags, pbData, pdwDataLen) \
    CPExportKey(hProv, hKey, hExpKey, dwBlobType, dwFlags, pbData, pdwDataLen)
#else /* !USE_CPAPI */
#define CRYPT_ExportKey(hProv, hKey, hExpKey, dwBlobType, dwFlags, pbData, pdwDataLen) \
    CryptExportKey(hKey, hExpKey, dwBlobType, dwFlags, pbData, pdwDataLen)
#endif /* !USE_CPAPI */

#ifdef USE_CPAPI
#define CRYPT_GenKey(hProv, AlgId, dwFlags, phKey) \
    CPGenKey(hProv, AlgId, dwFlags, phKey)
#else /* !USE_CPAPI */
#define CRYPT_GenKey(hProv, AlgId, dwFlags, phKey) \
    CryptGenKey(hProv, AlgId, dwFlags, phKey)
#endif /* !USE_CPAPI */

#ifdef USE_CPAPI
#define CRYPT_GenRandom(hProv, dwLen, pbBuffer) \
    CPGenRandom(hProv, dwLen, pbBuffer)
#else /* !USE_CPAPI */
#define CRYPT_GenRandom(hProv, dwLen, pbBuffer) \
    CryptGenRandom(hProv, dwLen, pbBuffer)
#endif /* !USE_CPAPI */

#ifdef USE_CPAPI
#define CRYPT_GetHashParam(hProv, hHash, dwParam, pbData, pdwDataLen, dwFlags) \
    CPGetHashParam(hProv, hHash, dwParam, pbData, pdwDataLen, dwFlags)
#else /* !USE_CPAPI */
#define CRYPT_GetHashParam(hProv, hHash, dwParam, pbData, pdwDataLen, dwFlags) \
    CryptGetHashParam(hHash, dwParam, pbData, pdwDataLen, dwFlags)
#endif /* !USE_CPAPI */

#ifdef USE_CPAPI
#define CRYPT_GetKeyParam(hProv, hKey, dwParam, pbData, pdwDataLen, dwFlags) \
    CPGetKeyParam(hProv, hKey, dwParam, pbData, pdwDataLen, dwFlags)
#else /* !USE_CPAPI */
#define CRYPT_GetKeyParam(hProv, hKey, dwParam, pbData, pdwDataLen, dwFlags) \
    CryptGetKeyParam(hKey, dwParam, pbData, pdwDataLen, dwFlags)
#endif /* !USE_CPAPI */

#ifdef USE_CPAPI
#define CRYPT_GetProvParam(hProv, dwParam, pbData, pdwDataLen, dwFlags) \
    CPGetProvParam(hProv, dwParam, pbData, pdwDataLen, dwFlags)
#else /* !USE_CPAPI */
#define CRYPT_GetProvParam(hProv, dwParam, pbData, pdwDataLen, dwFlags) \
    CryptGetProvParam(hProv, dwParam, pbData, pdwDataLen, dwFlags)
#endif /* !USE_CPAPI */

#ifdef USE_CPAPI
#define CRYPT_GetUserKey(hProv, dwKeySpec, phUserKey) \
    CPGetUserKey(hProv, dwKeySpec, phUserKey)
#else /* !USE_CPAPI */
#define CRYPT_GetUserKey(hProv, dwKeySpec, phUserKey) \
    CryptGetUserKey(hProv, dwKeySpec, phUserKey)
#endif /* !USE_CPAPI */

#ifdef USE_CPAPI
#define CRYPT_HashData(hProv, hHash, pbData, dwDataLen, dwFlags) \
    CPHashData(hProv, hHash, pbData, dwDataLen, dwFlags)
#else /* !USE_CPAPI */
#define CRYPT_HashData(hProv, hHash, pbData, dwDataLen, dwFlags) \
    CryptHashData(hHash, pbData, dwDataLen, dwFlags)
#endif /* !USE_CPAPI */

#ifdef USE_CPAPI
#define CRYPT_HashSessionKey(hProv, hHash, hKey, dwFlags) \
    CPHashSessionKey(hProv, hHash, hKey, dwFlags)
#else /* !USE_CPAPI */
#define CRYPT_HashSessionKey(hProv, hHash, hKey, dwFlags) \
    CryptHashSessionKey(hHash, hKey, dwFlags)
#endif /* !USE_CPAPI */

#ifdef USE_CPAPI
#define CRYPT_ImportKey(hProv, pbData, dwDataLen, hImpKey, dwFlags, phKey) \
    CPImportKey(hProv, pbData, dwDataLen, hImpKey, dwFlags, phKey)
#else /* !USE_CPAPI */
#define CRYPT_ImportKey(hProv, pbData, dwDataLen, hImpKey, dwFlags, phKey) \
    CryptImportKey(hProv, pbData, dwDataLen, hImpKey, dwFlags, phKey)
#endif /* !USE_CPAPI */

#ifdef USE_CPAPI
#define CRYPT_ReleaseContext(hProv, dwFlags) \
    CPReleaseContext(hProv, dwFlags)
#else /* !USE_CPAPI */
#define CRYPT_ReleaseContext(hProv, dwFlags) \
    CryptReleaseContext(hProv, dwFlags)
#endif /* !USE_CPAPI */

#ifdef USE_CPAPI
#define CRYPT_SetHashParam(hProv, hHash, dwParam, pbData, dwFlags) \
    CPSetHashParam(hProv, hHash, dwParam, pbData, dwFlags)
#else /* !USE_CPAPI */
#define CRYPT_SetHashParam(hProv, hHash, dwParam, pbData, dwFlags) \
    CryptSetHashParam(hHash, dwParam, pbData, dwFlags)
#endif /* !USE_CPAPI */

#ifdef USE_CPAPI
#define CRYPT_SetKeyParam(hProv, hKey, dwParam, pbData, dwFlags) \
    CPSetKeyParam(hProv, hKey, dwParam, pbData, dwFlags)
#else /* !USE_CPAPI */
#define CRYPT_SetKeyParam(hProv, hKey, dwParam, pbData, dwFlags) \
    CryptSetKeyParam(hKey, dwParam, pbData, dwFlags)
#endif /* !USE_CPAPI */

#ifdef USE_CPAPI
#define CRYPT_SetProvParam(hProv, dwParam, pbData, dwFlags) \
    CPSetProvParam(hProv, dwParam, pbData, dwFlags)
#else /* !USE_CPAPI */
#define CRYPT_SetProvParam(hProv, dwParam, pbData, dwFlags) \
    CryptSetProvParam(hProv, dwParam, pbData, dwFlags)
#endif /* !USE_CPAPI */

#ifdef USE_CPAPI
#define CRYPT_SignHash(hProv, hHash, dwKeySpec, sDescription, dwFlags, pbSignature, pdwSigLen) \
    CPSignHash(hProv, hHash, dwKeySpec, sDescription, dwFlags, pbSignature, pdwSigLen)
#else /* !USE_CPAPI */
#define CRYPT_SignHash(hProv, hHash, dwKeySpec, sDescription, dwFlags, pbSignature, pdwSigLen) \
    CryptSignHash(hHash, dwKeySpec, sDescription, dwFlags, pbSignature, pdwSigLen)
#endif /* !USE_CPAPI */

#ifdef USE_CPAPI
#define CRYPT_VerifySignature(hProv, hHash, pbSignature, dwSigLen, hPubKey, sDescription, dwFlags) \
    CPVerifySignature(hProv, hHash, pbSignature, dwSigLen, hPubKey, sDescription, dwFlags)
#else /* !USE_CPAPI */
#define CRYPT_VerifySignature(hProv, hHash, pbSignature, dwSigLen, hPubKey, sDescription, dwFlags) \
    CryptVerifySignature(hHash, pbSignature, dwSigLen, hPubKey, sDescription, dwFlags)
#endif /* !USE_CPAPI */

#endif /* _CPAPIX_H_INCLUDED */

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

/*!
 * \file $RCSfile$
 * \version $Revision: 64737 $
 * \date $Date: 2010-10-27 17:36:20 +0400 (СЃСЂ, 27 РѕРєС‚ 2010) $
 * \author $Author: lse $
 *
 * \brief Модуль хэшифрования
 *
 * Функции подсчета хеша. Отдельный независимый блок.
 */

#if !defined( SIMPLE_HASH_H )
#define SIMPLE_HASH_H
#include<CPROCSP/../RuNetCSP/Tumbler.h>

#if !defined( _LPCBYTE_DEFINED ) && defined (_WIN32)
    #define _LPCBYTE_DEFINED
    typedef const unsigned char * LPCBYTE;
#endif

#if defined DARWIN
    // TODO:XXX: memset()
    #include <string.h>
#endif

#define HASH_GR3411_SIZE 32
#define HASH_GR3411_STARTVECT_SIZE 32
#define GOSTHASH_TEXT02_LENGTH 50
#define HASH_IMIT_DEFAULT_SIZE 4

/*#define SIZE_HASH_DWORD			(HASH_GR3411_SIZE/sizeof(DWORD))    // не жрёт _asm*/
#define	SIZE_HASH_TEMP_BUFFER_BYTE		(480)
#define	SIZE_HASH_DWORD				(HASH_GR3411_SIZE/4)
#define SIZE_HASH_WORD				(HASH_GR3411_SIZE/sizeof(WORD))
#define	SIZE_HASH_BYTE				(HASH_GR3411_SIZE/sizeof(BYTE))

#define	ISQWORD	2

typedef struct CRYPT_DATA_BLOB_FLAGS {
#ifndef WORDS_BIGENDIAN
    unsigned int MemoryId:4;
    unsigned int FreeMem:1;
    unsigned int CheckOn:1;
    unsigned int IsQword:1;
    unsigned int nLinks:25;
#else /* WORDS_BIGENDIAN */
    unsigned int nLinks:25;
    unsigned int IsQword:1;
    unsigned int CheckOn:1;
    unsigned int FreeMem:1;
    unsigned int MemoryId:4;
#endif /* WORDS_BIGENDIAN */
} CRYPT_DATA_BLOB_FLAGS;

typedef struct _CRYPT_DATA_BLOB_EX_ {
	LPDWORD			pbData;
	DWORD			dwDataLen;
	CRYPT_DATA_BLOB_FLAGS Flags;
	DWORD			dwCheckCode;
	DWORD			dwReserved;
} CRYPT_DATA_BLOB_EX, *LPCRYPT_DATA_BLOB_EX;

typedef struct _CRYPT_SIGNATURE_ {
    BYTE r_[32];
    BYTE s[32];
} CRYPT_SIGNATURE, *LPCRYPT_SIGNATURE;
#define FKC_SHARED  1
#define SECRET_SHARED  2
#define GET_R2  1
#define SET_R2  2
#define KEYSPEC_KEYEXCHANGE 1
#define KEYSPEC_SIGNATURE   2
#define KEYSPEC_UNDEF	    0

typedef struct HASHCONEXT_FLAGS {
#ifndef WORDS_BIGENDIAN
    unsigned int SharedKyId:4;
    unsigned int PhR2:2;
    unsigned int PhR:1;
    unsigned int PhS2:1;
    unsigned int ShKeySpec:2;
#else /* WORDS_BIGENDIAN */
    unsigned int ShKeySpec:2;
    unsigned int PhS2:1;
    unsigned int PhR:1;
    unsigned int PhR2:2;
    unsigned int SharedKyId:4;
#endif /* WORDS_BIGENDIAN */
} HASHCONEXT_FLAGS;
#define dw_r	CtrlSumBuffer
#define dw_Rx	HashBuffer
#define dw_Ry	RestTextBuffer

/* Контекст хэширования */
typedef struct _CRYPT_HASH_CONTEXT_ {
	/* Текущее значение хеша*/
	DWORD				  HashBuffer[SIZE_HASH_DWORD];
	/* Текущая контрольная сумма*/
	DWORD				  CtrlSumBuffer[SIZE_HASH_DWORD];
	/* Накопленная длина текста в байтах*/
	DWORD				  dwAccTextLen;
	DWORD				  dwHiAccTextLen;
	/* Неполный последний блок*/
	BYTE				  RestTextBuffer[SIZE_HASH_BYTE];
	BYTE				  dbTempBuff[SIZE_HASH_TEMP_BUFFER_BYTE];
	BYTE*				  pbSignature2; /* was psSignature*/
	HASHCONEXT_FLAGS		  dwFlags;
	DWORD				  dwReserved;
	    /* Массив для тумблеров и его длина */
	DWORD				  kernelArrayLength;
	BYTE				  kernelArray[4];
} CRYPT_HASH_CONTEXT, *LPCRYPT_HASH_CONTEXT;


#if (defined UNIX)&&(!defined __cdecl)
#   define __cdecl
#endif /* UNIX */
typedef void (__cdecl * STEPHASHUNIVERSAL)(LPDWORD	lpdwHash,
				  LPDWORD	lpdwBlock,
				  LPDWORD	lpdwUnitSubst, 
				  LPBYTE	lpdbTempBuff);
typedef struct _CSP_HASH_FUNCS_ CSP_HASH_FUNCS,  *pCSP_HASH_FUNCS;

struct _CSP_HASH_FUNCS_ 
{
    CPC_Kernel_Fpu_Begin_Callback * CPkernel_fpu_begin; 
    CPC_Kernel_Fpu_End_Callback * CPkernel_fpu_end;

    /* Однопроходная функция хэширования ( функция не использует контекст хэширования)*/
    DWORD (*GR3411HashSinglePass)(
	pCSP_HASH_FUNCS CSPFuncs,
	LPBYTE	pbHash,						/* Указатель на буфер хеша*/
	LPCBYTE	pbData,						/* Указатель на хэшируемые данные*/
	DWORD	dwDataLen,					/* Длина хэшируемых данных*/
	LPDWORD	pdwSBox,					/* Узлы замены*/
	LPBYTE  pbStartVector,					/* Стартовый вектор хэширования*/
	STEPHASHUNIVERSAL PassMethod,
	BYTE * ArrayForTemp,
	DWORD	dbGArrayLength,  /*для тумблеров, длина массива.*/
	BYTE *	dbGArray	/*для тумблеров, массив.*/);


    /* Поточная функция хэширования */
    DWORD (*HContextGR3411Hash)(
	pCSP_HASH_FUNCS CSPFuncs,
	LPCBYTE				 pbData,		/* хэшируемые данные*/
	DWORD				 dwDataLen,		/* Длина хэшируемых данных*/
	LPCRYPT_HASH_CONTEXT pHContext,				/* Контекст хэширования*/
	LPCRYPT_DATA_BLOB_EX	pS_Box,
	STEPHASHUNIVERSAL PassMethod 				/*вариант StepHash*/);

    /* Функция возвращает значение хеша*/
    DWORD (*HContextGR3411GetHashVal)(
	pCSP_HASH_FUNCS CSPFuncs,
	LPBYTE				 pbHash,		/* Указатель на значение хеша*/
	LPCRYPT_HASH_CONTEXT pHContext,				/* Контекст хэширования*/
	LPCRYPT_DATA_BLOB_EX	pS_Box,
	STEPHASHUNIVERSAL PassMethod 				/*вариант StepHash*/	
	);

    /* Простая замена, универсальная оболочка*/
    STEPHASHUNIVERSAL StepHashUniversal;
    DWORD stackBufSize;
};


#ifdef __cplusplus
extern "C" {
#endif

/*! \internal 
 * \ingroup grpVerifyFiles
 * \brief Инициализация контекста хеша.
 *
 * \param pHContext [in]  Контекст функции хэширования.
 */
#if !defined(__inline) && !defined(WIN32)
#   define __inline     inline
#endif /* !defined(__inline) */
static __inline void
HContextGR3411InitSimple (LPCRYPT_HASH_CONTEXT pHContext)
{
    memset(pHContext, 0, sizeof(CRYPT_HASH_CONTEXT));
}

static __inline DWORD AlgId2KeySpec (ALG_ID algid)
{
    if (algid == CALG_DH_EL_SF || 
	algid == AT_KEYEXCHANGE || 
	algid == CALG_DH_EL_EPHEM )
    {
	return KEYSPEC_KEYEXCHANGE;
    } else if (algid == CALG_GR3410EL ||
	algid == AT_SIGNATURE) 
    {
	return KEYSPEC_SIGNATURE;
    }
    return KEYSPEC_UNDEF;
}

DWORD HContextGR3411HashSimple (pCSP_HASH_FUNCS	HashFuncs, 
    LPCBYTE pbData, DWORD dwDataLen, LPCRYPT_HASH_CONTEXT pHContext);
DWORD HContextGR3411GetHashValSimple (pCSP_HASH_FUNCS HashFuncs, 
    LPBYTE pbHash, LPCRYPT_HASH_CONTEXT pHContext);
CSP_BOOL HContextGR3411TestSimple (pCSP_HASH_FUNCS HashFuncs);

void WINAPI cpuident_lite(pCSP_HASH_FUNCS HashFuncs);

#ifdef __cplusplus
}
#endif

#endif

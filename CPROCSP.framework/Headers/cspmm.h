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
 * \version $Revision: 65407 $
 * \date $Date: 2010-12-14 15:13:27 +0300 (РІС‚, 14 РґРµРє 2010) $
 * \author $Author: dedal $
 *
 * \brief XXX
 *
 * XXX
 */
#ifndef _CSPMM_H_INCLUDED
#define _CSPMM_H_INCLUDED

#ifdef UNIX
#include<CPROCSP/CSP_WinDef.h>
#else // UNIX
#include <windef.h>
#endif // UNIX

#ifdef UNIX
#if defined(__GNUC__) && !defined(IOS)
#define CPCAPI __attribute__((regparm(0))) 
#else // __GNUC__
#define CPCAPI 
#endif // __GNUC__
#else // UNIX
#define CPCAPI __cdecl
#endif // UNIX

#ifdef __cplusplus
extern "C" {
#endif

typedef struct CPC_MEMORY_ARENA_ CPC_MEMORY_ARENA, *LPCPC_MEMORY_ARENA;

typedef struct CPC_MEMORY_STATS_ {
    LONG nBytes;
    LONG nChunks;
    LONG Used;
    LONG Size;
} CPC_MEMORY_STATS, *LPCPC_MEMORY_STATS;

typedef DWORD CPCAPI CPC_AllocMemory_Callback(
    LPCPC_MEMORY_ARENA pArena, 
    size_t dwSize, 
    DWORD dwMemPoolId,
    DWORD dwThreadId,
    LPVOID *pRes
);

typedef DWORD CPCAPI CPC_FreeMemory_Callback(
    LPCPC_MEMORY_ARENA pArena,
    VOID *pMem,
    DWORD dwMemPoolId
);

typedef VOID CPCAPI CPC_StatMemory_Callback(
    LPCPC_MEMORY_ARENA pArena,
    LPCPC_MEMORY_STATS pStats,
    DWORD dwMemPoolId
);

typedef VOID CPCAPI CPC_ValidateMemory_Callback(
    LPCPC_MEMORY_ARENA pArena
);

typedef VOID CPCAPI CPC_DoneMemory_Callback(
    LPCPC_MEMORY_ARENA pArena
);

typedef VOID CPCAPI CPC_MemoryException_Callback(
    LPCPC_MEMORY_ARENA pArena,
    VOID *arg
);

struct CPC_MEMORY_ARENA_ {
    CPC_ValidateMemory_Callback     *pValidateMemory;
    CPC_DoneMemory_Callback	    *pDoneMemory;
    CPC_AllocMemory_Callback	    *pAllocMemory;
    CPC_FreeMemory_Callback	    *pFreeMemory;
    CPC_StatMemory_Callback	    *pStatMemory;
    CPC_MemoryException_Callback    *pHandleException;
    LPVOID			    lpArg;
};

/* Идентификаторы рабочих куч библиотеки (memory pool id)
   для случая, когда только ключи помещаются в MP_PRIME и 
   только маски помещаются в MP_SEC*/
#define MP_WORK		3
#define MP_PRIME	MP_WORK
#define MP_SEC		MP_WORK
#define MP_PRIME_M	4
#define MP_SEC_M	5
#define MP_WORK_M	6
#if defined ( _WIN32 ) || defined ( _WIN64 )
#define MP_BIG		7
#else
#define MP_BIG		MP_WORK
#endif /* defined ( _WIN32 ) || defined ( _WIN64 ) */

#ifdef __cplusplus
}
#endif

#endif /* _CSPMM_H_INCLUDED */

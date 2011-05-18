/*
 * Copyright (C) 1997-2003 by Objective Systems, Inc.
 *
 * This software is furnished under a license and may be used and copied
 * only in accordance with the terms of such license and with the
 * inclusion of the above copyright notice. This software or any other
 * copies thereof may not be provided or otherwise made available to any
 * other person. No title to and ownership of the software is hereby
 * transferred.
 *
 * The information in this software is subject to change without notice
 * and should not be construed as a commitment by Objective Systems, Inc.
 *
 * PROPRIETARY NOTICE
 *
 * This software is an unpublished work subject to a confidentiality agreement
 * and is protected by copyright and trade secret law.  Unauthorized copying,
 * redistribution or other use of this work is prohibited.
 *
 * The above notice of copyright on this source code product does not indicate
 * any actual or intended publication of such source code.
 *
 *****************************************************************************/
/** 
 * @file rtMemory.h 
 * Memory management function and macro definitions
 */
#ifndef __RTMEMORY_H__
#define __RTMEMORY_H__

#include<CPROCSP/asn1type.h>

#define RT_MH_DONTKEEPFREE 0x1

#define OSRTMH_PROPID_DEFBLKSIZE   1
#define OSRTMH_PROPID_SETFLAGS     2
#define OSRTMH_PROPID_CLEARFLAGS   3

#define OSRTMH_PROPID_USER         10

/**
 * @addtogroup rtmem
 * @{
 */
/**
 * Allocate memory.  This macro allocates the given number of bytes.  It is 
 * similar to the C \c malloc run-time function.
 * 
 * @param pctxt - Pointer to a context block
 * @param nbytes - Number of bytes of memory to allocate
 * @return - Void pointer to allocated memory or NULL if insufficient memory 
 *   was available to fulfill the request.
 */
#define rtMemAlloc(pctxt,nbytes) \
rtMemHeapAlloc(&(pctxt)->pTypeMemHeap,nbytes)

/**
 * Allocate and zero memory.  This macro allocates the given number of bytes
 * and then initializes the memory block to zero.
 * 
 * @param pctxt - Pointer to a context block
 * @param nbytes - Number of bytes of memory to allocate
 * @return - Void pointer to allocated memory or NULL if insufficient memory 
 *   was available to fulfill the request.
 */
#define rtMemAllocZ(pctxt,nbytes) \
rtMemHeapAllocZ(&(pctxt)->pTypeMemHeap,nbytes)

/**
 * Reallocate memory.  This macro reallocates a memory block (either 
 * expands or contracts) to the given number of bytes.  It is 
 * similar to the C \c realloc run-time function.
 * 
 * @param pctxt - Pointer to a context block
 * @param mem_p - Pointer to memory block to reallocate.  This must have been 
 *   allocated using the ASN1MALLOC macro or the rtMemHeapAlloc function.
 * @param nbytes - Number of bytes of memory to which the block is to be 
 *   resized.
 * @return - Void pointer to allocated memory or NULL if insufficient memory 
 *   was available to fulfill the request.  This may be the same as the pmem 
 *   pointer that was passed in if the block did not need to be relocated.
 */
#define rtMemRealloc(pctxt,mem_p,nbytes) \
rtMemHeapRealloc(&(pctxt)->pTypeMemHeap, (void*)mem_p, nbytes)

/**
 * Free memory pointer.  This macro frees memory at the given pointer.  
 * The memory must have been allocated using the ASN1MALLOC (or similar) 
 * macros or the rtMem memory allocation macros.  This macro is 
 * similar to the C \c free function.
 * 
 * @param pctxt - Pointer to a context block
 * @param mem_p - Pointer to memory block to free.  This must have 
 *   been allocated using the ASN1MALLOC or rtMemAlloc macro or the 
 *   rtMemHeapAlloc function.
 */
#define rtMemFreePtr(pctxt,mem_p) \
if (rtMemHeapCheckPtr (&(pctxt)->pTypeMemHeap, (void*)mem_p)) \
rtMemHeapFreePtr(&(pctxt)->pTypeMemHeap, (void*)mem_p)

/**
 * Free memory associated with a context.  This macro frees all memory 
 * held within a context.  This is all memory allocated using the 
 * ASN1MALLOC (and similar macros) and the rtMem memory allocation 
 * functions using the given context variable.
 * 
 * @param pctxt - Pointer to a context block
 */
#define rtMemFree(pctxt) \
rtMemHeapFreeAll(&(pctxt)->pTypeMemHeap)

/**
 * Reset memory associated with a context.  This macro resets all memory 
 * held within a context.  This is all memory allocated using the ASN1MALLOC 
 * (and similar macros) and the rtMem memory allocation functions using the 
 * given context variable.
 *
 * <p>The difference between this and the ASN1MEMFREE macro is that the 
 * memory blocks held within the context are not actually freed.  Internal 
 * pointers are reset so the existing blocks can be reused.  This can 
 * provide a performace improvement for repetitive tasks such as decoding 
 * messages in a loop.
 * 
 * @param pctxt - Pointer to a context block
 */
#define rtMemReset(pctxt) \
rtMemHeapReset(&(pctxt)->pTypeMemHeap)

#ifdef __cplusplus
extern "C" {
#endif

/* Alias for __cdecl modifier; if __cdecl keyword is not supported, 
 * redefine it as empty macro. */

#if !defined(OSCDECL)
#if defined(_MSC_VER) || defined(__BORLANDC__)
#define OSCDECL __cdecl
#else
#define OSCDECL
#endif
#endif /* OSCDECL */

/* Pointers to C Run-Time memory allocation functions *
 * (See rtMemSetAllocFuncs)                           */

typedef void *(OSCDECL *OSMallocFunc ) (void *pCallCtx, size_t size);
typedef void *(OSCDECL *OSReallocFunc) (void *pCallCtx, void *ptr, size_t size);
typedef void  (OSCDECL *OSFreeFunc   ) (void *pCallCtx, void *ptr);

EXTERNRT void  rtMemHeapAddRef (void** ppvMemHeap);
EXTERNRT void* rtMemHeapAlloc (void** ppvMemHeap, int nbytes);
EXTERNRT void* rtMemHeapAllocZ (void** ppvMemHeap, int nbytes);
EXTERNRT int   rtMemHeapCheckPtr (void** ppvMemHeap, void* mem_p);
EXTERNRT int   rtMemHeapCreate (void** ppvMemHeap, void *pCallCtx);
EXTERNRT void  rtMemHeapFreeAll (void** ppvMemHeap);
EXTERNRT void  rtMemHeapFreePtr (void** ppvMemHeap, void* mem_p);
EXTERNRT void* rtMemHeapMarkSaved (void** ppvMemHeap, 
                                   ASN1ConstVoidPtr mem_p, 
                                   ASN1CSP_BOOL saved);

EXTERNRT void* rtMemHeapRealloc (void** ppvMemHeap, void* mem_p, int nbytes_);
EXTERNRT void  rtMemHeapRelease (void** ppvMemHeap);
EXTERNRT void  rtMemHeapReset (void** ppvMemHeap);
EXTERNRT void  rtMemHeapSetProperty (void** ppvMemHeap, 
                                     ASN1UINT propId, void* pProp);



/**
 * This function sets the pointers to standard allocation functions. These
 * functions are used to allocate/reallocate/free the memory blocks. By
 * default, standard C functions - 'malloc', 'realloc' and 'free' - are used.
 * But if some platforms do not support these functions (or some other reasons
 * exist) they can be overloaded. The functions being overloaded should have
 * the same prototypes as standard ones.
 *
 * @param malloc_func Pointer to the memory allocation function ('malloc' by
 *    default).
 * @param realloc_func Pointer to the memory reallocation function ('realloc'
 *    by default).
 * @param free_func Pointer to the memory deallocation function ('free' by
 *    default).
 */
EXTERNRT void  rtMemSetAllocFuncs (OSMallocFunc malloc_func,
                                   OSReallocFunc realloc_func,
                                   OSFreeFunc free_func);

EXTERNRT void  rtMemFreeOpenSeqExt (ASN1CTXT* pctxt, Asn1RTDList *pElemList);

/*
 * This function sets flags to a heap. May be used to control the heap's
 * behavior.
 *
 * @param pctxt        Pointer to a memory block structure that contains the
 *                       list of dynamic memory block maintained by these
 *                       functions.
 * @param flags        The flags.
 */
EXTERNRT void  rtMemHeapSetFlags (ASN1CTXT* pctxt, ASN1UINT flags);

/*
 * This function clears memory heap flags.
 *
 * @param pctxt        Pointer to a memory block structure that contains the
 *                       list of dynamic memory block maintained by these
 *                       functions.
 * @param flags        The flags
 */
EXTERNRT void  rtMemHeapClearFlags (ASN1CTXT* pctxt, ASN1UINT flags);

/**
 * This function sets the pointer to standard allocation functions. These
 * functions are used to allocate/reallocate/free the memory blocks. By
 * default, standard C functions - malloc, realloc, and free - are used. But if
 * some platforms do not support these functions or some other reasons exist)
 * they can be overloaded. The functions being overloaded should have the same
 * prototypes as standard ones.
 *
 * @param pctxt        Pointer to a context block.
 * @param blkSize      The currently used minimum size and the granularity of
 *                       memory blocks.
 */

EXTERNRT void  rtMemHeapSetDefBlkSize (ASN1CTXT* pctxt, ASN1UINT blkSize);

/**
 * This function returns the actual granularity of memory blocks.
 *
 * @param pctxt        Pointer to a context block.
 */
EXTERNRT ASN1UINT rtMemHeapGetDefBlkSize (ASN1CTXT* pctxt);

#ifdef _STATIC_HEAP
EXTERNRT void rtMemSetStaticBuf (void* memHeapBuf, ASN1UINT blkSize);
#endif

#ifdef __cplusplus
}
#endif
/**
 * @}
 */
#endif /*__RTMEMORY_H__*/

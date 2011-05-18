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
 * \version $Revision: 43347 $
 * \date $Date: 2007-11-19 12:38:56 +0300 (РїРЅ, 19 РЅРѕСЏ 2007) $
 * \author $Author: borodin $
 *
 * \brief A, P, Q, G - 512, 1024.
 *
 * Константы A, P, Q, G для ЭЦП и Diffie-Hellman'a длиной 512 и 1024 бита.
 */

#ifndef _CONSTANT_H_INCLUDED
#define _CONSTANT_H_INCLUDED
extern const OID_PARAMS mOID_Params[];

/* Константы для работы с OID */
#define HASH_OID	30
#define CIPHER_OID	31
#define SIGN_OID	32
#define DH_OID		33/* SIGN_OID */
#define SIGN64_OID	34
#define DH64_OID	35/* SIGN_OID */
#define SIGN_EL_OID	36
#define DH_EL_OID	37

#define ASNOID_Hash_Def_Def	&id_GostR3411_94_CryptoProParamSet 	/*VerbaO*/
#define ASNOID_Cipher_Def_Def	&id_Gost28147_89_CryptoPro_A_ParamSet 	/*VerbaO*/
#define ASNOID_Sign_Def_Def	&id_GostR3410_94_CryptoPro_A_ParamSet

/* Константы для ЭЦП с длинной модуля 512 бит (взяты из тестов на ГОСТ Р 34.10-94)*/
extern const DWORD R3410_64_P[16];
extern const DWORD R3410_64_Q[8];
extern const DWORD R3410_64_A[16];

/*  Для Diffie-Hellman'a с длинной модуля 1024 бита принимаются константы */
/*  X0=0x4B1A   C=0x3B8B*/
extern const DWORD DH_128_P[32];
extern const DWORD DH_128_Q[8];
extern const DWORD DH_128_A[32];
 
extern const DWORD VerbaO_128_P[32];
extern const DWORD VerbaO_128_Q[8];
extern const DWORD VerbaO_128_A[32];
 
extern const DWORD VerbaO_64_P[16];
extern const DWORD VerbaO_64_Q[8];
extern const DWORD VerbaO_64_A[16];


extern const DWORD Q_SgVar_1[8];
extern const DWORD P_SgVar_1[32];
extern const DWORD d_SgVar_1[21];
extern const DWORD A_SgVar_1[32];

extern const DWORD Q_ExVar_1[8];
extern const DWORD P_ExVar_1[32];
extern const DWORD d_ExVar_1[13];
extern const DWORD A_ExVar_1[32];
 

extern const DWORD Q_SgVar_2[8];
extern const DWORD P_SgVar_2[32];
extern const DWORD d_SgVar_2[2];
extern const DWORD A_SgVar_2[32];

extern const DWORD Q_ExVar_2[8];
extern const DWORD P_ExVar_2[32];
extern const DWORD d_ExVar_2[8];
extern const DWORD A_ExVar_2[32];


extern const DWORD Q_SgVar_3[8];
extern const DWORD P_SgVar_3[32];
extern const DWORD d_SgVar_3[7];
extern const DWORD A_SgVar_3[32];

extern const DWORD Q_ExVar_3[8];
extern const DWORD P_ExVar_3[32];
extern const DWORD d_ExVar_3[9];
extern const DWORD A_ExVar_3[32];

extern const uint64_t Elp_desimal[4];
extern const uint64_t Elb_desimal[4];
extern const uint64_t Ely_desimal[4];
extern const uint64_t Elq_desimal[4];
/*extern DWORD step_desimal;*/

extern const ASN1OBJID INVALID_OID;

#endif /* _CONSTANT_H_INCLUDED */
/* end of file: $Id: constant.h 43347 2007-11-19 09:38:56Z borodin $ */

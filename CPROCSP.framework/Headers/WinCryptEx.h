/*
 * Copyright(C) 2000-2006 Проект ИОК
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
 * \version $Revision: 2884 $
 * \date $Date: 2011-03-11 10:45:47 +0300 (РїС‚, 11 РјР°СЂ 2011) $
 * \author $Author: maxdm $
 *
 * \brief Интерфейс Крипто-Про CSP, добавление к WinCrypt.h.
 */

#ifndef _WINCRYPTEX_H_INCLUDED
#define _WINCRYPTEX_H_INCLUDED

#ifndef _WINCRYPTEX_USE_EXTERNAL_TYPES

#ifdef UNIX
#include<CPROCSP/CSP_WinCrypt.h>
#else // UNIX
#include <wincrypt.h>
#endif // UNIX

#endif // _WINCRYPTEX_USE_EXTERNAL_TYPES

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// Имена провайдеров как в CSP 1.1
#define CP_DEF_PROV_A "Crypto-Pro Cryptographic Service Provider"
#define CP_DEF_PROV_W L"Crypto-Pro Cryptographic Service Provider"
#ifdef UNICODE
#define CP_DEF_PROV CP_DEF_PROV_W
#else //!UNICODE
#define CP_DEF_PROV CP_DEF_PROV_A
#endif //!UNICODE

// Имена провайдеров как в CSP 2.0
#define CP_GR3410_94_PROV_A "Crypto-Pro GOST R 34.10-94 Cryptographic Service Provider"
#define CP_GR3410_94_PROV_W L"Crypto-Pro GOST R 34.10-94 Cryptographic Service Provider"
#ifdef UNICODE
#define CP_GR3410_94_PROV CP_GR3410_94_PROV_W
#else //!UNICODE
#define CP_GR3410_94_PROV CP_GR3410_94_PROV_A
#endif //!UNICODE

#define CP_GR3410_2001_PROV_A "Crypto-Pro GOST R 34.10-2001 Cryptographic Service Provider"
#define CP_GR3410_2001_PROV_W L"Crypto-Pro GOST R 34.10-2001 Cryptographic Service Provider"
#ifdef UNICODE
#define CP_GR3410_2001_PROV CP_GR3410_2001_PROV_W
#else //!UNICODE
#define CP_GR3410_2001_PROV CP_GR3410_2001_PROV_A
#endif //!UNICODE

#define CP_GR3410_2001_HSM_LOCAL_PROV_A "Crypto-Pro GOST R 34.10-2001 HSM Local CSP"
#define CP_GR3410_2001_HSM_LOCAL_PROV_W L"Crypto-Pro GOST R 34.10-2001 HSM Local CSP"
#ifdef UNICODE
#define CP_GR3410_2001_HSM_LOCAL_PROV CP_GR3410_2001_HSM_LOCAL_PROV_W
#else //!UNICODE
#define CP_GR3410_2001_HSM_LOCAL_PROV CP_GR3410_2001_HSM_LOCAL_PROV_A
#endif //!UNICODE

#define CP_KC1_GR3410_94_PROV_A "Crypto-Pro GOST R 34.10-94 KC1 CSP"
#define CP_KC1_GR3410_94_PROV_W L"Crypto-Pro GOST R 34.10-94 KC1 CSP"
#ifdef UNICODE
#define CP_KC1_GR3410_94_PROV CP_KC1_GR3410_94_PROV_W
#else //!UNICODE
#define CP_KC1_GR3410_94_PROV CP_KC1_GR3410_94_PROV_A
#endif //!UNICODE

#define CP_KC1_GR3410_2001_PROV_A "Crypto-Pro GOST R 34.10-2001 KC1 CSP"
#define CP_KC1_GR3410_2001_PROV_W L"Crypto-Pro GOST R 34.10-2001 KC1 CSP"
#ifdef UNICODE
#define CP_KC1_GR3410_2001_PROV CP_KC1_GR3410_2001_PROV_W
#else //!UNICODE
#define CP_KC1_GR3410_2001_PROV CP_KC1_GR3410_2001_PROV_A
#endif //!UNICODE

#define CP_KC2_GR3410_94_PROV_A "Crypto-Pro GOST R 34.10-94 KC2 CSP"
#define CP_KC2_GR3410_94_PROV_W L"Crypto-Pro GOST R 34.10-94 KC2 CSP"
#ifdef UNICODE
#define CP_KC2_GR3410_94_PROV CP_KC2_GR3410_94_PROV_W
#else //!UNICODE
#define CP_KC2_GR3410_94_PROV CP_KC2_GR3410_94_PROV_A
#endif //!UNICODE

#define CP_KC2_GR3410_2001_PROV_A "Crypto-Pro GOST R 34.10-2001 KC2 CSP"
#define CP_KC2_GR3410_2001_PROV_W L"Crypto-Pro GOST R 34.10-2001 KC2 CSP"
#ifdef UNICODE
#define CP_KC2_GR3410_2001_PROV CP_KC2_GR3410_2001_PROV_W
#else //!UNICODE
#define CP_KC2_GR3410_2001_PROV CP_KC2_GR3410_2001_PROV_A
#endif //!UNICODE

#define PH_GR3410_94_PROV_A "Phoenix-CS GOST R 34.10-94 Cryptographic Service Provider"
#define PH_GR3410_94_PROV_W L"Phoenix-CS GOST R 34.10-94 Cryptographic Service Provider"
#ifdef UNICODE
#define PH_GR3410_94_PROV PH_GR3410_94_PROV_W
#else //!UNICODE
#define PH_GR3410_94_PROV PH_GR3410_94_PROV_A
#endif //!UNICODE

#define PH_GR3410_2001_PROV_A "Phoenix-CS GOST R 34.10-2001 Cryptographic Service Provider"
#define PH_GR3410_2001_PROV_W L"Phoenix-CS GOST R 34.10-2001 Cryptographic Service Provider"
#ifdef UNICODE
#define PH_GR3410_2001_PROV PH_GR3410_2001_PROV_W
#else //!UNICODE
#define PH_GR3410_2001_PROV PH_GR3410_2001_PROV_A
#endif //!UNICODE

#define CP_KC1_GR3410_2001_MAGISTRA_PROV_A "GOST R 34.10-2001 Magistra CSP"
#define CP_KC1_GR3410_2001_MAGISTRA_PROV_W L"GOST R 34.10-2001 Magistra CSP"
#ifdef UNICODE
#define CP_KC1_GR3410_2001_MAGISTRA_PROV CP_KC1_GR3410_2001_MAGISTRA_PROV_W
#else //!UNICODE
#define CP_KC1_GR3410_2001_MAGISTRA_PROV CP_KC1_GR3410_2001_MAGISTRA_PROV_A
#endif //!UNICODE

#define CP_KC1_GR3410_2001_RUTOKEN_PROV_A "GOST R 34.10-2001 Rutoken CSP"
#define CP_KC1_GR3410_2001_RUTOKEN_PROV_W L"GOST R 34.10-2001 Rutoken CSP"
#ifdef UNICODE
#define CP_KC1_GR3410_2001_RUTOKEN_PROV CP_KC1_GR3410_2001_RUTOKEN_PROV_W
#else //!UNICODE
#define CP_KC1_GR3410_2001_RUTOKEN_PROV CP_KC1_GR3410_2001_RUTOKEN_PROV_A
#endif //!UNICODE

#define CP_KC1_GR3410_2001_ETOKEN_PROV_A "GOST R 34.10-2001 eToken CSP"
#define CP_KC1_GR3410_2001_ETOKEN_PROV_W L"GOST R 34.10-2001 eToken CSP"
#ifdef UNICODE
#define CP_KC1_GR3410_2001_ETOKEN_PROV CP_KC1_GR3410_2001_ETOKEN_PROV_W
#else //!UNICODE
#define CP_KC1_GR3410_2001_ETOKEN_PROV CP_KC1_GR3410_2001_ETOKEN_PROV_A
#endif //!UNICODE

#define CP_KC1_GR3410_2001_FLASH_PROV_A "Crypto-Pro Flash Drive KC1 CSP"
#define CP_KC1_GR3410_2001_FLASH_PROV_W L"Crypto-Pro Flash Drive KC1 CSP"
#ifdef UNICODE
#define CP_KC1_GR3410_2001_FLASH_PROV CP_KC1_GR3410_2001_FLASH_PROV_W
#else //!UNICODE
#define CP_KC1_GR3410_2001_FLASH_PROV CP_KC1_GR3410_2001_FLASH_PROV_A
#endif //!UNICODE

#define CP_KC1_GR3410_2001_REGISTRY_PROV_A "Crypto-Pro Registry KC1 CSP"
#define CP_KC1_GR3410_2001_REGISTRY_PROV_W L"Crypto-Pro Registry KC1 CSP"
#ifdef UNICODE
#define CP_KC1_GR3410_2001_REGISTRY_PROV CP_KC1_GR3410_2001_REGISTRY_PROV_W
#else //!UNICODE
#define CP_KC1_GR3410_2001_REGISTRY_PROV CP_KC1_GR3410_2001_REGISTRY_PROV_A
#endif //!UNICODE

/*
 * ???? Надо заставить PROV_GOST_DH вызывать предупреждение,
 * т.к. PROV_GOST_DH == 2 == PROV_RSA_SIG
 * Используйте PROV_GOST_94_DH или PROV_GOST_2001_DH
 */
#define PROV_GOST_DH 2

/*+
 * На 09.07.01 в Platform SDK последний зарегистрированный
 * CSP - PROV_RSA_AES == 24
 *
 * Я выбрал для  PROV_GOST_* два случайных числа из диапазона [53..89]
 */
//#pragma deprecated("PROV_GOST_94_DH")
#define PROV_GOST_94_DH 71
#define PROV_GOST_2001_DH 75

/* Дополнительные типы кодирования.
 * В Platform SDK определены только CRYPT_ASN_ENCODING (1),
 * CRYPT_NDR_ENCODING (2) и значения выше 0x10000 (PKCS7). */
#define CRYPT_XER_ENCODING (8)

/* Дополнительные флаги AcquireContext. Глобальные установки криптопровайдера. */
#define CRYPT_GENERAL				0x00004000
#define CRYPT_TOKEN_SHARED			0x00008000
#define CRYPT_NOSERIALIZE			0x00010000 // Начиная с 3.6.5327, до этого был 0x8000
#define CRYPT_REBOOT				0x00020000
/*
 * // dwFlags definitions for CryptAcquireContext
 * #define CRYPT_VERIFYCONTEXT			0xF0000000
 * #define CRYPT_NEWKEYSET			0x00000008
 * #define CRYPT_DELETEKEYSET			0x00000010
 * #define CRYPT_MACHINE_KEYSET			0x00000020
 * #define CRYPT_SILENT				0x00000040
 * #if (NTDDI_VERSION >= NTDDI_WINLH)
 * #define CRYPT_DEFAULT_CONTAINER_OPTIONAL	0x00000080
 * #endif //(NTDDI_VERSION >= NTDDI_WINLH)
 *... 
 * //  The following define must not collide with any of the
 * //  CryptAcquireContext dwFlag defines.
 * //-------------------------------------------------------
 * #define CERT_SET_KEY_PROV_HANDLE_PROP_ID	0x00000001
 * #define CERT_SET_KEY_CONTEXT_PROP_ID		0x00000001
 */

/* Дополнительные флаги CryptMsgOpenToEncode и CryptMsgControl, определяющие
 * поведение при формировании подписи CAdES-BES. */
#define CPCMSG_CADES_STRICT		    (0x00000100)
#define CPCMSG_CADES_DISABLE                (0x00000200)
#define CPCMSG_CADES_DISABLE_CERT_SEARCH    (0x00000400)

/* Дополнительные флаги CryptSignMessage, определяющие
 * поведение при формировании подписи CAdES-BES. */
#define CPCRYPT_MESSAGE_CADES_STRICT	    (CPCMSG_CADES_STRICT)
#define CPCRYPT_MESSAGE_CADES_DISABLE	    (CPCMSG_CADES_DISABLE)

/* ???? Флаг CryptGenKey, определяющий кючи, используемые совмесно с ФКН.*/
#define CRYPT_ECCNEGATIVE	0x00000400 

/* Режимы шифрования ключом EKE */
#define CRYPT_MODE_EKEXOR	11
#define CRYPT_MODE_EKEECADD	12

/* Описатели пользовательских ключей */
#define USERKEY_KEYEXCHANGE			AT_KEYEXCHANGE
#define USERKEY_SIGNATURE			AT_SIGNATURE

/* Algorithm types */
#define ALG_TYPE_GR3410				(7 << 9)
/* GR3411 sub-ids */
#define ALG_SID_GR3411				30
#define ALG_SID_GR3411_HASH			39
#define ALG_SID_GR3411_HASH34			40
/* G28147 sub_ids */
#define ALG_SID_G28147				30
#define ALG_SID_PRODIVERS			38
#define ALG_SID_RIC1DIVERS			40
/* Export Key sub_id */
#define ALG_SID_PRO_EXP				31
#define ALG_SID_SIMPLE_EXP			32
/* Hash sub ids */
#define ALG_SID_G28147_MAC			31
#define ALG_SID_TLS1_MASTER_HASH		32

/* GOST_DH sub ids */
#define ALG_SID_DH_EX_SF			30
#define ALG_SID_DH_EX_EPHEM			31
#define ALG_SID_PRO_AGREEDKEY_DH		33
#define ALG_SID_PRO_SIMMETRYKEY			34
#define ALG_SID_GR3410				30
#define ALG_SID_GR3410EL			35
#define ALG_SID_DH_EL_SF			36
#define ALG_SID_DH_EL_EPHEM			37
#define ALG_SID_GR3410_94_ESDH			39
#define ALG_SID_GR3410_01_ESDH			40
/* EKE sub ids*/
#define ALG_SID_EKE_CIPHER			41
#define ALG_SID_EKE_EXPORTPUBLIC		42
#define ALG_SID_EKEVERIFY_HASH			43
#define ALG_SID_AGREED_DEMASK			44

#define AT_KEYEXCHANGE_FKC		   0x80000001
#define AT_SIGNATURE_FKC		   0x80000002

#define CALG_GR3411 \
    (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_GR3411)

#define CALG_GR3411_HMAC \
    (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_GR3411_HASH)
#define CALG_GR3411_HMAC34 \
    (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_GR3411_HASH34)

#define CALG_G28147_MAC \
    (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_G28147_MAC)

#define CALG_G28147_IMIT \
    CALG_G28147_MAC

#define CALG_GR3410 \
    (ALG_CLASS_SIGNATURE | ALG_TYPE_GR3410 | ALG_SID_GR3410)

#define CALG_GR3410EL \
    (ALG_CLASS_SIGNATURE | ALG_TYPE_GR3410 | ALG_SID_GR3410EL)

#define CALG_G28147 \
    (ALG_CLASS_DATA_ENCRYPT | ALG_TYPE_BLOCK | ALG_SID_G28147)

#define CALG_DH_EX_SF \
    (ALG_CLASS_KEY_EXCHANGE | ALG_TYPE_DH | ALG_SID_DH_EX_SF)

#define CALG_DH_EX_EPHEM \
    (ALG_CLASS_KEY_EXCHANGE | ALG_TYPE_DH | ALG_SID_DH_EX_EPHEM)

#define CALG_DH_EX \
    CALG_DH_EX_SF

#define CALG_DH_EL_SF \
    (ALG_CLASS_KEY_EXCHANGE | ALG_TYPE_DH | ALG_SID_DH_EL_SF)

#define CALG_DH_EL_EPHEM \
    (ALG_CLASS_KEY_EXCHANGE | ALG_TYPE_DH | ALG_SID_DH_EL_EPHEM)

#define CALG_GR3410_94_ESDH \
    (ALG_CLASS_KEY_EXCHANGE | ALG_TYPE_DH | ALG_SID_GR3410_94_ESDH)

#define CALG_GR3410_01_ESDH \
    (ALG_CLASS_KEY_EXCHANGE | ALG_TYPE_DH | ALG_SID_GR3410_01_ESDH)

#define CALG_PRO_AGREEDKEY_DH \
    (ALG_CLASS_KEY_EXCHANGE | ALG_TYPE_BLOCK | ALG_SID_PRO_AGREEDKEY_DH)

#define CALG_PRO_EXPORT \
    (ALG_CLASS_DATA_ENCRYPT | ALG_TYPE_BLOCK | ALG_SID_PRO_EXP)

#define CALG_SIMPLE_EXPORT \
    (ALG_CLASS_DATA_ENCRYPT | ALG_TYPE_BLOCK | ALG_SID_SIMPLE_EXP)

#define CALG_SIMMETRYKEY \
    CALG_G28147
    /* (ALG_CLASS_DATA_ENCRYPT | ALG_TYPE_BLOCK | ALG_SID_SIMMETRYKEY) */

#define CALG_TLS1_MASTER_HASH \
    (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_TLS1_MASTER_HASH)

#define CALG_TLS1_MAC_KEY \
    (ALG_CLASS_DATA_ENCRYPT | ALG_TYPE_SECURECHANNEL | ALG_SID_SCHANNEL_MAC_KEY)

#define CALG_TLS1_ENC_KEY \
    (ALG_CLASS_DATA_ENCRYPT | ALG_TYPE_SECURECHANNEL | ALG_SID_SCHANNEL_ENC_KEY)

#define CALG_PRO_DIVERS \
    (ALG_CLASS_DATA_ENCRYPT | ALG_TYPE_BLOCK | ALG_SID_PRODIVERS)
#define CALG_RIC_DIVERS \
    (ALG_CLASS_DATA_ENCRYPT | ALG_TYPE_BLOCK | ALG_SID_RIC1DIVERS)
#define CALG_OSCAR_DIVERS CALG_RIC_DIVERS

#define CALG_EKE_CIPHER \
    (ALG_CLASS_KEY_EXCHANGE | ALG_TYPE_BLOCK | ALG_SID_EKE_CIPHER)
#define CALG_EKEVERIFY_HASH \
    (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_EKEVERIFY_HASH)

#define CALG_AGREED_DEMASK \
    (ALG_CLASS_KEY_EXCHANGE | ALG_TYPE_BLOCK | ALG_SID_AGREED_DEMASK)



#define CRYPT_ALG_PARAM_OID_GROUP_ID            20


#define CRYPT_PROMIX_MODE	0x00000001
#define CRYPT_SIMPLEMIX_MODE	0x00000000
#define CRYPT_MIXDUPLICATE	0x00000002

/*Тип ключевого блоба для диверсификации ключей с помощью
    функции CPImportKey в режиме ключа импорта CALG_PRO_EXPORT*/
#define DIVERSKEYBLOB	0x70

/*Тип ключевого блоба для передачи параметров в протоколе подписи FKC*/
#define HASHPUBLICKEYEXBLOB 0x71

/* Дополнительные параметры криптопровайдера */
#if !(defined(CPCSP_C_SOURCE ) && CPCSP_C_SOURCE - 0 < 36) 
#define PP_LAST_ERROR 90 //deprecated
#endif
#define PP_ENUMOIDS_EX 91
#define PP_HASHOID 92
#define PP_CIPHEROID 93
#define PP_SIGNATUREOID 94
#define PP_DHOID 95
#define PP_RESERVED1 96
#define PP_BIO_STATISTICA_LEN 97
//#pragma deprecated("PP_REBOOT")
#define PP_REBOOT 98
/*Следующий параметр используется для перехда на платформы, отличные от WIN32*/
/*#define PP_ANSILASTERROR 99*/
#define PP_RANDOM 100
/*#define PP_DRVCONTAINER	101*/
#define PP_MUTEX_ARG	102
#define PP_ENUM_HASHOID 103
#define PP_ENUM_CIPHEROID 104
#define PP_ENUM_SIGNATUREOID 105
#define PP_ENUM_DHOID	106
#define PP_SET_PIN 107
#define PP_CHANGE_PIN 108
#define PP_HCRYPTPROV 109
#define PP_SELECT_CONTAINER 110
#define PP_FQCN 111
#define PP_CHECKPUBLIC 112
#define PP_ADMIN_CHECKPUBLIC 113
#define PP_ENUMREADERS 114
#define PP_CACHE_SIZE 115
#define PP_NK_SYNC 117
#define PP_INFO 118
#define PP_PIN_INFO 120
#define PP_PASSWD_TERM 123
#define PP_SAME_MEDIA 124
#define PP_DELETE_KEYSET 125
#define PP_DELETE_SAVED_PASSWD 126
#define PP_VERSION_TIMESTAMP 127
#define PP_SECURITY_LEVEL 129
#define PP_FAST_CODE_FUNCS 131
#define PP_CONTAINER_EXTENSION 132
#define PP_ENUM_CONTAINER_EXTENSION 133
#define PP_CONTAINER_EXTENSION_DEL 134
#define PP_CONTAINER_DEFAULT 135
#define PP_LCD_QUERY 136
#define PP_ENUM_LOG 137
#define PP_VERSION_EX 138
#define PP_FAST_CODE_FLAGS 139
#define PP_ENCRYPTION_CARRIER 140
#define PP_FKC				141
#define PP_FRIENDLY_NAME		142
#define PP_FKC_DH_CHECK			143
#define PP_DELETE_SHORTCUT 144

/* Флаг, используемый при перечислении считывателей, для получения имени носителя
   */
#define CRYPT_MEDIA 0x20
/* Флаг, используемый при перечислении контейнеров, для получения:
    Fully Qualified Container Name */
#define CRYPT_FQCN 0x10
/* Флаг, используемый при перечислении контейнеров, для приоритета
    получения уникальных имен контейнеров перед обычными именами.
    В случае достаточно выделенной памяти под уникальный номер,
    после уникального номера копируется обычное имя контейнера. */
#define CRYPT_UNIQUE 0x08

/* Флаг используемый при перечислении записей журнала,
   для завершения перечисления и вычисления подписи. */
#define CRYPT_FINISH 0x04

/* Флаг, при вызове PP_DELETE_ERROR и удалении контейнера разделенного
    на части выдает сообщение об ошибке. */
#define CRYPT_DELETEKEYSET_PART 0x1

/* Ответ перечисления считывателей, означающий отсутствие носителя в считывателе. 
   Возвращается в виде ASCIIZ-строки. */
#define ERR_CRYPT_MEDIA_NO_MEDIA "NO_MEDIA"

/* Ответ перечисления считывателей, означающий, что вставлен не-ФКН. Для ФКН-провайдеров. 
   Возвращается в виде ASCIIZ-строки. */
#define ERR_CRYPT_MEDIA_NO_FKC "NO_FKC"

/* Ответ перечисления считывателей, означающий, что вставлен ФКН. Для не-ФКН-провайдеров.
   Возвращается в виде ASCIIZ-строки. */
#define ERR_CRYPT_MEDIA_FKC "IS_FKC"

/* Ответ перечисления считывателей, означающий отсутствие уникального номера носителя (неотчуждаемый носитель).
   Возвращается в виде ASCIIZ-строки. */
#define ERR_CRYPT_MEDIA_NO_UNIQUE "NO_UNIQUE"

/* Дополнительные параметры объекта хеша */
#define HP_HASHSTARTVECT 0x0008
#define HP_HASHCOPYVAL	 0x0009
#define HP_OID 0x000a
#define HP_OPEN 0x000B
#define HP_KEYMIXSTART 0x0011
#define HP_OPAQUEBLOB 0x000C

#define HP_R2_SIGN 0x000D
#define HP_R_SIGN 0x000E
#define HP_S2_SIGN 0x000F
#define HP_KEYSPEC_SIGN 0x0010

/* Дополнительные параметры ключа */
#define KP_SV		KP_IV
#define KP_MIXMODE	101
#define KP_MIXSTART	0x800000e0
#define KP_OID		102
#define KP_HASHOID	103
#define KP_CIPHEROID	104
#define KP_SIGNATUREOID 105
#define KP_DHOID	106
#define KP_KC1EXPORT	0x800000f0
/* Token Interfase NEW */
#define KP_MULX		0x800000f1
#define KP_MULX_INVERS  0x800000f2
#define KP_ADDX		0x800000f3
#define KP_SUBX		0x800000f4
#define KP_ECADD	0x800000f5
#define KP_ECSUB	0x800000f6
#define KP_SYNCRO	0x800000f7
#define KP_DELTA	0x800000f8

#define KP_DEMASKPUBLIC	0x800000f9

/* FKC KP_...  to delete */
#define KP_TOKENRECOVERY	0x800001fb
/* End FKC KP_...  to delete */

/* CRYPT_PRIVATE_KEYS_ALG_OID_GROUP_ID */
#define szOID_CP_GOST_PRIVATE_KEYS_V1 "1.2.643.2.2.37.1"
#define szOID_CP_GOST_PRIVATE_KEYS_V2 "1.2.643.2.2.37.2"
#define szOID_CP_GOST_PRIVATE_KEYS_V2_FULL "1.2.643.2.2.37.2.1"
#define szOID_CP_GOST_PRIVATE_KEYS_V2_PARTOF "1.2.643.2.2.37.2.2"

/* CRYPT_HASH_ALG_OID_GROUP_ID */
#define szOID_CP_GOST_R3411 "1.2.643.2.2.9"

/* CRYPT_ENCRYPT_ALG_OID_GROUP_ID */
#define szOID_CP_GOST_28147 "1.2.643.2.2.21"

/* CRYPT_PUBKEY_ALG_OID_GROUP_ID */
#define szOID_CP_GOST_R3410 "1.2.643.2.2.20"
#define szOID_CP_GOST_R3410EL "1.2.643.2.2.19"
#define szOID_CP_DH_EX "1.2.643.2.2.99"
#define szOID_CP_DH_EL "1.2.643.2.2.98"
#define szOID_CP_GOST_R3410_94_ESDH "1.2.643.2.2.97"
#define szOID_CP_GOST_R3410_01_ESDH "1.2.643.2.2.96"

/* CRYPT_SIGN_ALG_OID_GROUP_ID */
#define szOID_CP_GOST_R3411_R3410 "1.2.643.2.2.4"
#define szOID_CP_GOST_R3411_R3410EL "1.2.643.2.2.3"

/* CRYPT_ENHKEY_USAGE_OID_GROUP_ID */
#define szOID_KP_TLS_PROXY "1.2.643.2.2.34.1"
#define szOID_KP_RA_CLIENT_AUTH "1.2.643.2.2.34.2"
#define szOID_KP_WEB_CONTENT_SIGNING "1.2.643.2.2.34.3"
#define szOID_KP_RA_ADMINISTRATOR "1.2.643.2.2.34.4"
#define szOID_KP_RA_OPERATOR "1.2.643.2.2.34.5"

/* Our well-known policy ID */
#define szOID_CEP_BASE_PERSONAL	"1.2.643.2.2.38.1"
#define szOID_CEP_BASE_NETWORK	"1.2.643.2.2.38.2"

/* OIDs for HASH */
#define szOID_GostR3411_94_TestParamSet			"1.2.643.2.2.30.0"
#define szOID_GostR3411_94_CryptoProParamSet		"1.2.643.2.2.30.1"	/* ГОСТ Р 34.11-94, параметры по умолчанию */
#define szOID_GostR3411_94_CryptoPro_B_ParamSet		"1.2.643.2.2.30.2"
#define szOID_GostR3411_94_CryptoPro_C_ParamSet		"1.2.643.2.2.30.3"
#define szOID_GostR3411_94_CryptoPro_D_ParamSet		"1.2.643.2.2.30.4"

/* OIDs for Crypt */
#define szOID_Gost28147_89_TestParamSet			"1.2.643.2.2.31.0"
#define szOID_Gost28147_89_CryptoPro_A_ParamSet		"1.2.643.2.2.31.1"	/* ГОСТ 28147-89, параметры по умолчанию */
#define szOID_Gost28147_89_CryptoPro_B_ParamSet		"1.2.643.2.2.31.2"	/* ГОСТ 28147-89, параметры шифрования 1 */
#define szOID_Gost28147_89_CryptoPro_C_ParamSet		"1.2.643.2.2.31.3" 	/* ГОСТ 28147-89, параметры шифрования 2 */
#define szOID_Gost28147_89_CryptoPro_D_ParamSet		"1.2.643.2.2.31.4"	/* ГОСТ 28147-89, параметры шифрования 3 */
#define szOID_Gost28147_89_CryptoPro_Oscar_1_1_ParamSet	"1.2.643.2.2.31.5"	/* ГОСТ 28147-89, параметры Оскар 1.1 */
#define szOID_Gost28147_89_CryptoPro_Oscar_1_0_ParamSet	"1.2.643.2.2.31.6"	/* ГОСТ 28147-89, параметры Оскар 1.0 */
#define szOID_Gost28147_89_CryptoPro_RIC_1_ParamSet	"1.2.643.2.2.31.7"	/* ГОСТ 28147-89, параметры РИК 1 */

/* OID for Signature 1024*/
#define szOID_GostR3410_94_CryptoPro_A_ParamSet		"1.2.643.2.2.32.2" 	/*VerbaO*/
#define szOID_GostR3410_94_CryptoPro_B_ParamSet		"1.2.643.2.2.32.3"
#define szOID_GostR3410_94_CryptoPro_C_ParamSet		"1.2.643.2.2.32.4"
#define szOID_GostR3410_94_CryptoPro_D_ParamSet		"1.2.643.2.2.32.5"

/* OID for Signature 512*/
#define szOID_GostR3410_94_TestParamSet			"1.2.643.2.2.32.0" 	/*Test*/

/* OID for DH 1024*/
#define szOID_GostR3410_94_CryptoPro_XchA_ParamSet	"1.2.643.2.2.33.1"
#define szOID_GostR3410_94_CryptoPro_XchB_ParamSet	"1.2.643.2.2.33.2"
#define szOID_GostR3410_94_CryptoPro_XchC_ParamSet	"1.2.643.2.2.33.3"

/* OID for EC signature */
#define szOID_GostR3410_2001_TestParamSet		"1.2.643.2.2.35.0"      /* ГОСТ Р 34.10-2001, тестовые параметры */
#define szOID_GostR3410_2001_CryptoPro_A_ParamSet	"1.2.643.2.2.35.1"	/* ГОСТ Р 34.10-2001, параметры по умолчанию */
#define szOID_GostR3410_2001_CryptoPro_B_ParamSet	"1.2.643.2.2.35.2"	/* ГОСТ Р 34.10-2001, параметры Оскар 2.x */
#define szOID_GostR3410_2001_CryptoPro_C_ParamSet	"1.2.643.2.2.35.3"	/* ГОСТ Р 34.10-2001, параметры подписи 1 */

/* OID for EC DH */
#define szOID_GostR3410_2001_CryptoPro_XchA_ParamSet	"1.2.643.2.2.36.0"	/* ГОСТ Р 34.10-2001, параметры обмена по умолчанию */
#define szOID_GostR3410_2001_CryptoPro_XchB_ParamSet 	"1.2.643.2.2.36.1"	/* ГОСТ Р 34.10-2001, параметры обмена 1 */

/* OIDs for private key container extensions */
/* Расширения контейнера. Поддерживаются начиная с CSP 3.6 */
#define szOID_CryptoPro_private_keys_extension_intermediate_store "1.2.643.2.2.37.3.1"
#define szOID_CryptoPro_private_keys_extension_signature_trust_store "1.2.643.2.2.37.3.2"
#define szOID_CryptoPro_private_keys_extension_exchange_trust_store "1.2.643.2.2.37.3.3"
#define szOID_CryptoPro_private_keys_extension_container_friendly_name "1.2.643.2.2.37.3.4"

/* OIDs for certificate and CRL extensions */
/* Метод сопоставления CRL с сертификатом издателя. */
#define szOID_CryptoPro_extensions_certificate_and_crl_matching_technique "1.2.643.2.2.49.1"

/* OIDs for signing certificate attributes */
/* Группа атрибутов для хранения идентификатора сертификата ключа подписи */
#define szCPOID_RSA_SMIMEaaSigningCertificate "1.2.840.113549.1.9.16.2.12"
#define szCPOID_RSA_SMIMEaaSigningCertificateV2 "1.2.840.113549.1.9.16.2.47"
#define szCPOID_RSA_SMIMEaaETSotherSigCert "1.2.840.113549.1.9.16.2.19"

/* GUIDs for extending CryptEncodeObject/CryptDecodeObject functionality */
/* Набор уникальных идентификаторов, используемых для расширения функциональности
   функций CryptEncodeObject/CryptDecodeObject */
#define szCPGUID_RSA_SMIMEaaSigningCertificateEncode "{272ED084-4C55-42A9-AD88-A1502D9ED755}"
#define szCPGUID_RSA_SMIMEaaSigningCertificateV2Encode "{42AB327A-BE56-4899-9B81-1BF2F3C5E154}"
#define szCPGUID_RSA_SMIMEaaETSotherSigCertEncode "{410F6306-0ADE-4485-80CC-462DEB3AD109}"
#define szCPGUID_PRIVATEKEY_USAGE_PERIOD_Encode "{E36FC6F5-4880-4CB7-BA51-1FCD92CA1453}"

/*! \cond pkivalidator */
/* GUIDs for extending CertVerifyCertificateChainPolicy functionality */
/* Набор уникальных идентификаторов, используемых для расширения функциональности
   функции CertVerifyCertificateChainPolicy */
#define CPCERT_CHAIN_POLICY_PRIVATEKEY_USAGE_PERIOD "{C03D5610-26C8-4B6F-9549-245B5B3AB743}"
#define CPCERT_CHAIN_POLICY_SIGNATURE "{B52FF66F-13A5-402C-B958-A3A6B5300FB6}"
#define CPCERT_CHAIN_POLICY_TIMESTAMP_SIGNING "{AF74EE92-A059-492F-9B4B-EAD239B22A1B}"
#define CPCERT_CHAIN_POLICY_OCSP_SIGNING "{A4CC781E-04E9-425C-AAFD-1D74DA8DFAF6}"
/** \endcond */

/*! \cond csp */
/* Синонимы для совместимости с версией 3.0*/
#define OID_HashVar_Default	szOID_GostR3411_94_CryptoProParamSet
#define OID_HashTest		szOID_GostR3411_94_TestParamSet
#define OID_HashVerbaO		szOID_GostR3411_94_CryptoProParamSet
#define OID_HashVar_1		szOID_GostR3411_94_CryptoPro_B_ParamSet
#define OID_HashVar_2		szOID_GostR3411_94_CryptoPro_C_ParamSet
#define OID_HashVar_3		szOID_GostR3411_94_CryptoPro_D_ParamSet

#define OID_CipherVar_Default	szOID_Gost28147_89_CryptoPro_A_ParamSet
#define OID_CryptTest		szOID_Gost28147_89_TestParamSet
#define OID_CipherVerbaO	szOID_Gost28147_89_CryptoPro_A_ParamSet
#define OID_CipherVar_1		szOID_Gost28147_89_CryptoPro_B_ParamSet
#define OID_CipherVar_2		szOID_Gost28147_89_CryptoPro_C_ParamSet
#define OID_CipherVar_3		szOID_Gost28147_89_CryptoPro_D_ParamSet
#define OID_CipherOSCAR		szOID_Gost28147_89_CryptoPro_Oscar_1_1_ParamSet
#define OID_CipherTestHash	szOID_Gost28147_89_CryptoPro_Oscar_1_0_ParamSet
#define OID_CipherRIC1		szOID_Gost28147_89_CryptoPro_RIC_1_ParamSet

#define OID_SignDH128VerbaO	szOID_GostR3410_94_CryptoPro_A_ParamSet
#define OID_Sign128Var_1	szOID_GostR3410_94_CryptoPro_B_ParamSet
#define OID_Sign128Var_2	szOID_GostR3410_94_CryptoPro_C_ParamSet
#define OID_Sign128Var_3	szOID_GostR3410_94_CryptoPro_D_ParamSet
#define OID_DH128Var_1		szOID_GostR3410_94_CryptoPro_XchA_ParamSet
#define OID_DH128Var_2		szOID_GostR3410_94_CryptoPro_XchB_ParamSet
#define OID_DH128Var_3		szOID_GostR3410_94_CryptoPro_XchC_ParamSet

#define OID_Sg64_Test		szOID_GostR3410_94_TestParamSet

#define OID_ECCTest3410		szOID_GostR3410_2001_TestParamSet
#define OID_ECCSignDHPRO	szOID_GostR3410_2001_CryptoPro_A_ParamSet
#define OID_ECCSignDHOSCAR	szOID_GostR3410_2001_CryptoPro_B_ParamSet
#define OID_ECCSignDHVar_1	szOID_GostR3410_2001_CryptoPro_C_ParamSet

#define OID_ECCDHPRO		szOID_GostR3410_2001_CryptoPro_XchA_ParamSet
#define OID_ECCDHPVar_1		szOID_GostR3410_2001_CryptoPro_XchB_ParamSet

/* Синонимы для совместимости с версией 1.1*/
#define OID_SipherVerbaO	szOID_Gost28147_89_CryptoPro_A_ParamSet
#define OID_SipherVar_1		szOID_Gost28147_89_CryptoPro_B_ParamSet
#define OID_SipherVar_2		szOID_Gost28147_89_CryptoPro_C_ParamSet
#define OID_SipherVar_3		szOID_Gost28147_89_CryptoPro_D_ParamSet
#define OID_SipherVar_Default	szOID_Gost28147_89_CryptoPro_A_ParamSet

#define X509_GR3410_PARAMETERS ((LPCSTR) 5001)
#define OBJ_ASN1_CERT_28147_ENCRYPTION_PARAMETERS ((LPCSTR) 5007)

#define CP_GOST_R3411_ALGORITHM "GOST R 34.11-94"
#define CP_GOST_28147_ALGORITHM "GOST 28147-89"
#define CP_GOST_R3410_ALGORITHM "GOST R 34.10-94"
#define CP_GOST_R3410EL_ALGORITHM "GOST R 34.10-2001"
#define CP_GOST_HMAC_ALGORITHM "HMAC GOST 28147-89"

#define CP_GOST_R3410_ALGORITHM "GOST R 34.10-94"
#define CP_GOST_R3410EL_ALGORITHM "GOST R 34.10-2001"


#define CP_PRIMITIVE_PROVIDER   L"Crypto-Pro Primitive Provider"
#define BCRYPT_CP_GOST_R3411_ALGORITHM L#CP_GOST_R3411_ALGORITHM
#define BCRYPT_CP_GOST_28147_ALGORITHM L#CP_GOST_28147_ALGORITHM
#define BCRYPT_CP_GOST_R3410_ALGORITHM L#CP_GOST_R3410_ALGORITHM
#define BCRYPT_CP_GOST_R3410EL_ALGORITHM L#CP_GOST_R3410EL_ALGORITHM


/* Режим блочного шифрования с обратной связью на базе ГОСТ 28147-89, шифр-текст блока всегда является IV для следующего.*/
/*! \ingroup ProCSPData
*  \brief Режим блочного шифрования с обратной связью на базе ГОСТ 28147-89, шифр-текст блока всегда является IV для следующего
*/
#define CRYPT_MODE_CBCSTRICT	1 

/* Режим блочного шифрования с обратной связью на базе ГОСТ 28147-89, согласно RFC 4357.*/
/*! \ingroup ProCSPData
*  \brief Режим блочного шифрования с обратной связью на базе ГОСТ 28147-89, согласно RFC 4357
*/
#define CRYPT_MODE_CBCRFC4357	31 

/* Режим шифрования "гаммирование" по ГОСТ 28147-89.*/
/*! \ingroup ProCSPData
 *  \brief Режим шифрования "гаммированием" по ГОСТ 28147-89
 */
#define CRYPT_MODE_CNT          3      // GOST 28147-89 in "gammirovanie" (counter) mode

/* Режим шифрования "гаммирование" по ГОСТ 28147-89.*/
/*! \ingroup ProCSPData
 *  \brief Режим шифрования "гаммированием" по ГОСТ 28147-89 
 *   в режиме пакетной обработки данных
 */
#define CRYPT_MODE_CNTPACKET       0x80000100 | CRYPT_MODE_CNT

/* Длина секретного ключа для ГОСТ 28147-89, подписи и обмена.*/
/*! \ingroup ProCSPData
 *  \brief Длина в байтах ключа ГОСТ 28147-89 и закрытых ключей
 * ГОСТ Р 34.10-94 и ГОСТ Р 34.10-2001.
 */
#define SECRET_KEY_LEN		32

/*! \ingroup ProCSPData
 *  \brief Длина в байтах ключа ГОСТ 28147-89
 * \sa SECRET_KEY_LEN
 */
#define G28147_KEYLEN        SECRET_KEY_LEN

/*! \ingroup ProCSPData
 *  \brief Длина в байтах имитовставки при импорте/экспорте
 */
#define EXPORT_IMIT_SIZE		4

/*! \ingroup ProCSPData
 *  \brief Длина  в байтах вектора инциализации алгоритма
 */
#define SEANCE_VECTOR_LEN		8

/*! \ingroup ProCSPData
*  \brief Максимальная разрешенная длина имени ключевого контейнера
*/
#define MAX_CONTAINER_NAME_LEN		260

/* Константы и структуры для схем цифровой подписи и*/
/* открытого распределения ключей*/

/*! \ingroup ProCSPData
 *  \brief Признак ключей ГОСТ Р 34.10-94 и ГОСТ Р 34.10-2001
 */
#define GR3410_1_MAGIC			0x3147414D
#define GR3410_2_MAGIC			GR3410_1_MAGIC//0x3145474a

#define DH_1_MAGIC			GR3410_1_MAGIC
#define DH_2_MAGIC			GR3410_1_MAGIC
#define DH_3_MAGIC			GR3410_1_MAGIC

/*! \ingroup ProCSPData
 *  \brief Признак ключей ГОСТ 28147-89 и мастер ключей TLS
 */
#define G28147_MAGIC			0x374a51fd
#define SIMPLEBLOB_MAGIC		G28147_MAGIC
#define G28147_OPAQUEMAGIC		0x374a51fe
/*! \ingroup ProCSPData
 *  \brief Признак ключевого блоба функции диверсификации ключа
 */
#define DIVERS_MAGIC			0x31564944

/*! \ingroup ProCSPData
 *  \brief Текущее значение версии ключевого блоба
 */
#define BLOB_VERSION			(BYTE)0x20


/* Определения для */
/*! \ingroup ProCSPData
 * \brief Отладочная версия дистрибутива.
 */
#define VER_TYPE_DEBUG 1
/*! \ingroup ProCSPData
* \brief Релизная версия дистрибутива.
*/
#define VER_TYPE_RELEASE 0

/*! \ingroup ProCSPData
* \brief Архитектура IA32.
*/
#define VER_ARCH_IA32	    0
/*! \ingroup ProCSPData
* \brief Архитектура IA64.
*/
#define VER_ARCH_IA64	    1
/*! \ingroup ProCSPData
* \brief Архитектура Sparc32.
*/
#define VER_ARCH_SPARC32    2
/*! \ingroup ProCSPData
* \brief Архитектура Sparc64.
*/
#define VER_ARCH_SPARC64    3
/*! \ingroup ProCSPData
* \brief Архитектура AMD64.
*/
#define VER_ARCH_AMD64	    4
/*! \ingroup ProCSPData
* \brief Архитектура ARM.
*/
#define VER_ARCH_ARM	    5
/*! \ingroup ProCSPData
* \brief Архитектура PowerPC32.
*/
#define VER_ARCH_PPC32      6
/*! \ingroup ProCSPData
* \brief Архитектура PowerPC64.
*/
#define VER_ARCH_PPC64      7


/*! \ingroup ProCSPData
* \brief ОС Windows.
*/
#define VER_OS_WINDOWS 0
/*! \ingroup ProCSPData
* \brief ОС Solaris.
*/
#define VER_OS_SOLARIS 1
/*! \ingroup ProCSPData
* \brief ОС FreeBSD.
*/
#define VER_OS_FREEBSD 2
/*! \ingroup ProCSPData
* \brief ОС Linux.
*/
#define VER_OS_LINUX   3
/*! \ingroup ProCSPData
* \brief ОС AIX.
*/
#define VER_OS_AIX     4

/*! \ingroup ProCSPData
* \brief ОС Mac OS X.
*/
#define VER_OS_DARWIN  5
/*! \ingroup ProCSPData
* \brief Apple iOS */
#define VER_OS_IOS  6

/*! \ingroup ProCSPData
 *
 * \brief Структура описывает версию СКЗИ, ПКЗИ, тип сборки,
 * аппаратную архитектуру и ОС, для которой предназначен продукт.
 */
typedef struct _PROV_PP_VERSION_EX {
    DWORD PKZI_Build;	/*!< Версия ПКЗИ. */
    DWORD SKZI_Build;	/*!< Версия СКЗИ. */
    DWORD TypeDebRel;	/*!< Тип сборки: VER_TYPE_DEBUG, VER_TYPE_RELEASE. */
    DWORD Architecture;	/*!< Аппаратная архитектура: VER_ARCH_IA32, 
			 * VER_ARCH_IA64, VER_ARCH_SPARC32, VER_ARCH_SPARC64,
			 * VER_ARCH_AMD64, VER_ARCH_ARM, VER_ARCH_PPC32,
			 * VER_ARCH_PPC64.
			 */
    DWORD OS;		/*!< Тип ОС: VER_OS_WINDOWS, VER_OS_SOLARIS,
			 * VER_OS_FREEBSD, VER_OS_LINUX, VER_OS_AIX.
			 */
} PROV_PP_VERSION_EX;


/* Определения для структуры SIMPLEBLOB*/
/* Заголовок SIMPLEBLOB*/
/*!
 * \ingroup ProCSPData
 *
 * \brief Структура CRYPT_SIMPLEBLOB_HEADER является расширением структуры BLOBHEADER и
 * находится в начале поля \b pbData ключевого блоба типа SIMPLEBLOB для ключей "КриптоПро CSP".
 *
 * \req_wincryptex
 * \sa _PUBLICKEYSTRUC
 * \sa PCRYPT_SIMPLEBLOB
 * \sa CPExportKey
 * \sa CPGetKeyParam
 */
typedef struct _CRYPT_SIMPLEBLOB_HEADER {
    BLOBHEADER BlobHeader;
                    /*!< Общий заголовок ключевого блоба. Определяет алгоритм ключа
                     * находящегося в ключевом блобе. См. \ref _PUBLICKEYSTRUC.
                     */
    DWORD Magic;
                    /*!< Признак ключей по ГОСТ 28147-89 или мастер ключей TLS,
                     * устанавливается в \ref G28147_MAGIC.
                     */
    ALG_ID EncryptKeyAlgId;
                    /*!< Определяет алгоритм экспорта ключа. Этот алгоритм является
                     * параметром ключа экспорта. См. \ref #CPGetKeyParam.
                     */
} CRYPT_SIMPLEBLOB_HEADER;
/*!
 * \ingroup ProCSPData
 *
 * \brief Псевдоструктура (т. е. недоопределенная структура) CRYPT_SIMPLEBLOB полностью описывает ключевой блоб
 * типа SIMPLEBLOB для ключей "КриптоПро CSP". 
 *
 * \req_wincryptex
 * \sa CRYPT_SIMPLEBLOB_HEADER
 * \sa CPExportKey
 * \sa CPGetKeyParam
 */
typedef struct _CRYPT_SIMPLEBLOB {
    CRYPT_SIMPLEBLOB_HEADER tSimpleBlobHeader;
                    /*!< Общий заголовок ключевого блоба типа SIMPLEBLOB "КриптоПро CSP".
                     */
    BYTE    bSV[SEANCE_VECTOR_LEN];
                    /*!< Вектор инциализации для алгоритма CALG_PRO_EXPORT.
                     * См. \ref SEANCE_VECTOR_LEN.
                     */
    BYTE    bEncryptedKey[G28147_KEYLEN];
                    /*!< Зашифрованный ключ ГОСТ 28147-89.
                     * См. \ref G28147_KEYLEN.
                     */
    BYTE    bMacKey[EXPORT_IMIT_SIZE];
                    /*!< Имитовставка по ГОСТ 28147-89 на ключ. Рассчитывается
                     * до зашифрования и проверяется после расшифрования.
                     * См. \ref EXPORT_IMIT_SIZE.
                     */
    BYTE    bEncryptionParamSet[1];
                    /*!< Содержит ASN1 структуру в DER кодировке, определяющую
                     * параметры алгоритама шифрования ГОСТ 28147-89:
                     * \code
                     *      encryptionParamSet
                     *          OBJECT IDENTIFIER (
                     *              id-Gost28147-89-TestParamSet |      -- Only for tests use
                     *              id-Gost28147-89-CryptoPro-A-ParamSet |
                     *              id-Gost28147-89-CryptoPro-B-ParamSet |
                     *              id-Gost28147-89-CryptoPro-C-ParamSet |
                     *              id-Gost28147-89-CryptoPro-D-ParamSet |
                     *              id-Gost28147-89-CryptoPro-Simple-A-ParamSet |
                     *              id-Gost28147-89-CryptoPro-Simple-B-ParamSet |
                     *              id-Gost28147-89-CryptoPro-Simple-C-ParamSet |
                     *              id-Gost28147-89-CryptoPro-Simple-D-ParamSet
                     * \endcode
                     */
}   CRYPT_SIMPLEBLOB, *PCRYPT_SIMPLEBLOB;

/*!
 * \ingroup ProCSPData
 *
 * \brief Псевдоструктура (т. е. недоопределенная структура) CRYPT_OPAQUEBLOB полностью описывает ключевой блоб
 * типа OPAQUEKEYLOB для ключей "КриптоПро CSP". 
 *
 * \req_wincryptex
 * \sa CRYPT_SIMPLEBLOB_HEADER
 * \sa CPExportKey
 * \sa CPImportKey
 */
typedef struct _CRYPT_OPAQUEBLOB {
    CRYPT_SIMPLEBLOB_HEADER tSimpleBlobHeader;
                    /*!< Общий заголовок ключевого блоба типа SIMPLEBLOB "КриптоПро CSP".
                     */
    BYTE    bSV[SEANCE_VECTOR_LEN];
                    /*!< Вектор инциализации для алгоритма CALG_PRO_EXPORT.
                     * См. \ref SEANCE_VECTOR_LEN.
                     */
    BYTE    bEncryptedKey[G28147_KEYLEN];
                    /*!< Зашифрованный ключ ГОСТ 28147-89.
                     * См. \ref G28147_KEYLEN.
                     */
    BYTE    bMacKey[EXPORT_IMIT_SIZE];
                    /*!< Имитовставка по ГОСТ 28147-89 на ключ. Рассчитывается
                     * до зашифрования и проверяется после расшифрования.
                     * См. \ref EXPORT_IMIT_SIZE.
                     */
    BYTE    bEncryptedInitKey[G28147_KEYLEN];
                    /*!< Зашифрованный ключ ГОСТ 28147-89.
                     * См. \ref G28147_KEYLEN.
                     */
    BYTE    bMacInitKey[EXPORT_IMIT_SIZE];
                    /*!< Имитовставка по ГОСТ 28147-89 на ключ. Рассчитывается
                     * до зашифрования и проверяется после расшифрования.
                     * См. \ref EXPORT_IMIT_SIZE.
                     */
      /*Нешифруемые поля*/
   BYTE    bCurrentIV[SEANCE_VECTOR_LEN];
                    /*!< Вектор инциализации шифратора.
                     * См. \ref SEANCE_VECTOR_LEN.
                     */
    BYTE    bChainBlock[8];
                    /*!< Блок зацерления. Использование блока зависит от режима шифрования.
                     *
                     */
    BYTE    bAccCiphertextLen[sizeof(DWORD)];
                    /*!< Накопленная длина шифрованного текста.
                     *
                     */
    BYTE    bCipherMode[sizeof(DWORD)];
    BYTE    bMixMode[sizeof(DWORD)];
    BYTE    bFlags[4];
    BYTE    bPaddingMode[sizeof(DWORD)];
    BYTE    bAlgId[sizeof(ALG_ID)];
    BYTE    bCommonFlags[4];
    BYTE    bCheckSum[sizeof(DWORD)];
    BYTE    bEncryptionParamSet[1];
                    /*!< Содержит ASN1 структуру в DER кодировке, определяющую
                     * параметры алгоритама шифрования ГОСТ 28147-89:
                     * \code
                     *      encryptionParamSet
                     *          OBJECT IDENTIFIER (
                     *              id-Gost28147-89-TestParamSet |      -- Only for tests use
                     *              id-Gost28147-89-CryptoPro-A-ParamSet |
                     *              id-Gost28147-89-CryptoPro-B-ParamSet |
                     *              id-Gost28147-89-CryptoPro-C-ParamSet |
                     *              id-Gost28147-89-CryptoPro-D-ParamSet |
                     *              id-Gost28147-89-CryptoPro-Simple-A-ParamSet |
                     *              id-Gost28147-89-CryptoPro-Simple-B-ParamSet |
                     *              id-Gost28147-89-CryptoPro-Simple-C-ParamSet |
                     *              id-Gost28147-89-CryptoPro-Simple-D-ParamSet
                     * \endcode
                     */
}   CRYPT_OPAQUEBLOB, *PCRYPT_OPAQUEBLOB;


typedef struct _CRYPT_OPAQUEHASHBLOB {
    CRYPT_SIMPLEBLOB_HEADER tSimpleBlobHeader;
                    /*!< Общий заголовок ключевого блоба типа SIMPLEBLOB "КриптоПро CSP".
                     */
   BYTE    ImitVal[8];
   BYTE    bCurrKey[G28147_KEYLEN];
                    /*!< Зашифрованный ключ ГОСТ 28147-89.
                     * См. \ref G28147_KEYLEN.
                     */
      /*Нешифруемые поля*/
    BYTE    bChainBlock[8];
                    /*!< Блок зацерления. Использование блока зависит от режима шифрования.
                     *
                     */
    BYTE    bAccCiphertextLen[sizeof(DWORD)];
                    /*!< Накопленная длина шифрованного текста.
                     *
                     */
    BYTE    bFlags[4];
    BYTE    bMixMode[sizeof(DWORD)];
    BYTE    bHFlags[4];
    BYTE    bCheckSum[sizeof(DWORD)];
}   CRYPT_OPAQUEHASHBLOB;


/*!
 * \ingroup ProCSPData
 *
 * \brief Структура CRYPT_PUBKEYPARAM содержит признак ключей
 * по ГОСТ Р 34.10-94 или ГОСТ Р 34.10-2001.
 *
 * \req_wincryptex
 * \sa CRYPT_PUBKEY_INFO_HEADER
 * \sa CPExportKey
 * \sa CPGetKeyParam
 */
typedef struct _CRYPT_PUBKEYPARAM {
    DWORD Magic;
                    /*!< Признак ключей по ГОСТ Р 34.10-94 или ГОСТ Р 34.10-2001
                     * устанавливается в \ref GR3410_1_MAGIC.
                     */
    DWORD BitLen;
                    /*!< Длина открытого ключа в битах.
                     */
} CRYPT_PUBKEYPARAM, *LPCRYPT_PUBKEYPARAM;

/* Заголовок PUBLICKEYBLOB и PRIVATEKEYBLOB*/
/*!
 * \ingroup ProCSPData
 *
 * \brief Структура CRYPT_PUBKEY_INFO_HEADER содержит заголовок
 * блоба открытого ключа или блоба ключевой пары
 * по ГОСТ Р 34.10-94 или ГОСТ Р 34.10-2001.
 *
 * \req_wincryptex
 * \sa _PUBLICKEYSTRUC
 * \sa CRYPT_PUBKEYPARAM
 * \sa CPExportKey
 * \sa CPGetKeyParam
 */
typedef struct _CRYPT_PUBKEY_INFO_HEADER {
    BLOBHEADER BlobHeader;
                    /*!< Общий заголовок ключевого блоба. Определяет его тип и алгоритм ключа
                     * находящегося в ключевом блобе. Для открытых ключей алгоритм
                     * ключа всегда, либо CALG_GR3410, либо CALG_GR3410EL. Для ключевых
                     * пар алгоритм отражает её назначение. См. \ref _PUBLICKEYSTRUC.
                     */
    CRYPT_PUBKEYPARAM KeyParam;
                    /*!< Основной признак и длинна ключей ГОСТ Р 34.10-94 и ГОСТ Р 34.10-2001.
                     */
} CRYPT_PUBKEY_INFO_HEADER;

/*!
 * \ingroup ProCSPData
 *
 * \brief Псевдоструктура CRYPT_PUBLICKEYBLOB полностью описывает ключевой блоб
 * типа PUBLICKEYBLOB для ключей "КриптоПро CSP". 
 *
 * \req_wincryptex
 * \sa CRYPT_PUBKEY_INFO_HEADER
 * \sa CPExportKey
 * \sa CPGetKeyParam
 */
typedef struct _CRYPT_PUBLICKEYBLOB {
    CRYPT_PUBKEY_INFO_HEADER tPublicKeyParam;
                    /*!< Общий заголовок ключевого блоба типа PUBLICKEYBLOB "КриптоПро CSP".
                     */
    BYTE    bASN1GostR3410_94_PublicKeyParameters[1/*псевдомассив*/];
                    /*!< Содержит ASN1 структуру в DER кодировке, определяющую
                     * параметры открытого ключа, как описано типами
                     * GostR3410-2001-PublicKeyParameters и GostR3410-94-PublicKeyParameters
                     * CPPK [RFC 4491] и CPALGS [RFC 4357].
                     */
    BYTE    bPublicKey[1/*псевдомассив*/];
                    /*!< Содержит открытый ключ в сетевом представлении (ASN1 DER)
                     * как описано типами GostR3410-2001-PublicKey и GostR3410-94-PublicKey
                     * CPPK [RFC 4491].
                     * Длина массива равна tPublicKeyParam.KeyParam.BitLen/8.
                     */
}   CRYPT_PUBLICKEYBLOB, *PCRYPT_PUBLICKEYBLOB;

/*!
 * \ingroup ProCSPData
 *
 * \brief Псевдоструктура CRYPT_PRIVATEKEYBLOB полностью описывает ключевой блоб
 * типа PRIVATEKEYBLOB для ключей "КриптоПро CSP".
 *
 * \req_wincryptex
 * \sa CRYPT_PUBKEY_INFO_HEADER
 * \sa CPExportKey
 * \sa CPGetKeyParam
 */
typedef struct _CRYPT_PRIVATEKEYBLOB {
    CRYPT_PUBKEY_INFO_HEADER tPublicKeyParam;
                    /*!< Общий заголовок ключевого блоба типа PRIVATEKEYBLOB "КриптоПро CSP".
                     */
    BYTE    bExportedKeys[1/* Псевдо массив.*/];
	/*
	KeyTransferContent ::=
	SEQUENCE {
	    encryptedPrivateKey  GostR3410EncryptedKey,
	    privateKeyParameters PrivateKeyParameters,
	}
	KeyTransfer ::=
	SEQUENCE {
	    keyTransferContent       KeyTransferContent,
	    hmacKeyTransferContent   Gost28147HMAC
	}
	*/
}   CRYPT_PRIVATEKEYBLOB, *PCRYPT_PRIVATEKEYBLOB;

/* Определения для структуры DIVERSBLOB*/
/*!
 * \ingroup ProCSPData
 *
 * \brief Структура CRYPT_DIVERSBLOBHEADER описывает блоб
 * типа DIVERSBLOB для процедуры диверсификации ключей КриптоПро CSP.
 *
 * \req_wincryptex
 * \sa CRYPT_DIVERSBLOB
 * \sa CPImportKey
 */
typedef struct _CRYPT_DIVERSBLOBHEADER {
    BLOBHEADER BlobHeader;
                /*!< Общий заголовок блоба, диверсифицирующе3о ключ.
                 *  Определяет алгоритм диверсифицирумого ключа.
                 */
    ALG_ID      aiDiversAlgId;
                /*!< Определяет алгоритм диверсификации ключа.
                 */
    DWORD       dwDiversMagic;
                /*!< Признак диверсификации ключа,
                 * устанавливается в \ref DIVERS_MAGIC.
                 */
   /*    BYTE        *pbDiversData;
                !< Указатель на данные, по которым диверсифицируется ключ.
                 */
    DWORD       cbDiversData;
                /*!< Длина данных, по которым диверсифицируется ключ.
                 */
} CRYPT_DIVERSBLOBHEADER, *LPCRYPT_DIVERSBLOBHEADER;

/*!
 * \ingroup ProCSPData
 *
 * \brief Структура CRYPT_DIVERSBLOB описывает блоб
 * типа DIVERSBLOB для процедуры диверсификации ключей КриптоПро CSP.
 *
 * \req_wincryptex
 * \sa CRYPT_DIVERSBLOBHEADER
 * \sa CPImportKey
 */
typedef struct _CRYPT_DIVERSBLOB {
    CRYPT_DIVERSBLOBHEADER DiversBlobHeader;
                /*!< Общий заголовок блоба, диверсиицирующего ключ.
                 *  Определяет алгоритм диверсифицирумого ключа.
                 */
    BYTE        bDiversData[1/*массив переменной длины: [4..40] байтов*/];
                /*!< Данные, по которым диверсифицируется ключ.
                 */
} CRYPT_DIVERSBLOB, *LPCRYPT_DIVERSBLOB;

/*! \brief Тип пароля: пароль или pin */
#define CRYPT_PIN_PASSWD 0
/*! \brief Тип пароля: имя контейнера зашифрования
     Используется имя контейнера. */
#define CRYPT_PIN_ENCRYPTION 1
/*! \brief Тип пароля: разбивка контейнера на части по HANDLE.
     Используются имена контейнеров. */
#define CRYPT_PIN_NK 2
/*! \brief Тип пароля: неизвестен */
#define CRYPT_PIN_UNKNOWN 3
/*! \brief Тип пароля: тип и значение выбираются в окне. */
#define CRYPT_PIN_QUERY 4
/*! \brief Тип пароля: Очитсить пароль. */
#define CRYPT_PIN_CLEAR 5
/*! \brief Тип пароля: определяется аппаратным модулем. */
#define CRYPT_PIN_HARDWARE_PROTECTION 6
/*! \brief Тип пароля: пароль для FKC контейнера, для аутентификации по EKE */
#define CRYPT_PIN_FKC_EKE 	7

/*!
 * \ingroup ProCSPData
 *
 * \brief Структура передачи информации для слияния частей контейнера
 *
 * \req_wincryptex
 * \sa CPSetProvParam
 */
typedef struct _CRYPT_PIN_NK_PARAM {
    short n; /*!< Количество передаваемых частей. */
    short k; /*!< Количество частей для загрузки. */
    DWORD *parts; /*!< 32-битные внутренние идентификаторы частей контейнера. */
} CRYPT_PIN_NK_PARAM;

/*!
 * \brief Структура передачи пароль, pin-кода, имени контейнера,
 *  HANDLE контейнера при смене пароля.
 */
typedef union _CRYPT_PIN_SOURCE {
    char *passwd; /*!< Пароль, PIN-код, имя контейнера. */
    DWORD prov; /*!< 32-битный внутренний идентификатор контейнера. */
    CRYPT_PIN_NK_PARAM nk_handles; /*!< Разбивка на NK по идентификаторам */
} CRYPT_PIN_SOURCE;

/*!
 * \ingroup ProCSPData
 *
 * \brief Структура передачи информации для:
 *  1) смены пароля контейнера,
 *  2) указания способа доступа к контейнеру (имя, handle, пароль), на ключе которого
 *     зашифровано содержимое другого контейнера.
 *
 * \req_wincryptex
 * \sa CPSetProvParam
 */
typedef struct _CRYPT_PIN_PARAM {
    BYTE type;
    /*!< Тип данных.
 *  CRYPT_PIN_PASSWD - пароль или PIN,
 *  CRYPT_PIN_ENCRYPTION - HANDLE контейнера зашифрования.
 *  CRYPT_PIN_QUERY - тип и значение выбираются в окне,
 *  CRYPT_PIN_CLEAR - очистить пароль.
 *  CRYPT_PIN_NK - разбить на части k из n
 */
     CRYPT_PIN_SOURCE dest; /*!< Данные соответствующего типа */
} CRYPT_PIN_PARAM;

/*!
 * \ingroup ProCSPData
 *
 * \brief Структура получения информации о контейнере разделенного на части.
 *
 * \req_wincryptex
 * \sa CPGetProvParam
 */
typedef struct _CRYPT_NK_INFO_PARAM {
    short n; /*!< Количество частей, на которые разделен контейнер. */
    short k; /*!< Количество частей, достаточных для получения колюча. */
    char parts[1]; /*!< Последовательность n ASCIIZ строк. */
} CRYPT_NK_INFO_PARAM;

/*!
 * \ingroup ProCSPData
 *
 * \brief Структура для получения информации о пароле на контейнер.
 *
 * \req_wincryptex
 * \sa CPGetProvParam
 */
typedef struct _CRYPT_PASSWD_INFO_PARAM {
    unsigned min_passwd_length; /*!< Минимальный допустимый размер пароля. */
    unsigned max_passwd_length; /*!< Максимальный допустимый размер пароля. */
    unsigned passwd_type; /*!< Тип пароля. */
} CRYPT_PASSWD_INFO_PARAM;

#define CSP_INFO_SIZE sizeof(CSP_INFO)

/*!
* \ingroup ProCSPData
*
* \brief Структура для получения информации о пароле на контейнер.
*
* \req_wincryptex
* \sa CPGetProvParam, CRYPT_PASSWD_INFO_PARAM, CRYPT_NK_INFO_PARAM
*/
typedef union _CRYPT_PIN_INFO_SOURCE {
    CRYPT_PASSWD_INFO_PARAM passwd;
    CRYPT_NK_INFO_PARAM nk_info;
    char encryption[1];
} CRYPT_PIN_INFO_SOURCE;

/*!
* \ingroup ProCSPData
*
* \brief Структура для получения информации о пароле на контейнер.
*
* \req_wincryptex
* \sa CPGetProvParam, CRYPT_PIN_INFO_SOURCE
*/
typedef struct _CRYPT_PIN_INFO {
    BYTE type; /*!< Тип данных.
 *  CRYPT_PIN_UNKNOWN - тип неизвестен
 *  CRYPT_PIN_PASSWD - пароль или PIN,
 *  CRYPT_PIN_ENCRYPTION - HANDLE контейнера зашифрования.
 *  CRYPT_PIN_NK - разбить на части k из n
 *  CRYPT_PIN_HARDWARE_PROTECTION - тип защиты определяется аппаратным модулем
 */
     CRYPT_PIN_INFO_SOURCE dest; /*!< Данные соответствующего типа */
} CRYPT_PIN_INFO;

#define PROVIDER_TYPE_FKC_MAGISTRA 1


/*!
 * \ingroup ProCSPData
 *
 * \brief Структура получения информации о пароле контейнера для аутентификации по EKE
 *
 * \req_wincryptex
 * \sa CPSetProvParam
 */
typedef struct _CRYPT_FKC_EKE_AUTH_INFO_PARAM {
    unsigned min_passwd_length; /*!< Минимальный допустимый размер пароля. */
    unsigned max_passwd_length; /*!< Максимальный допустимый размер пароля. */
    unsigned count_eke; /*!< Счетчик оставшихся операций EKE. */
    unsigned count_dh; /*!< Счетчик оставшихся операций Диффи-Хеллмана. */
    unsigned count_sig; /*!< Счетчик оставшихся операций подписи. */
    unsigned count_err; /*!< Счетчик оставшихся ошибок. */
    unsigned count_cerr; /*!< Счетчик оставшихся последовательных ошибок. */
    char fname[1]; /*!< UTF8Z-строка дружественного имени. */
} CRYPT_FKC_EKE_AUTH_INFO_PARAM;

/*!
* \ingroup ProCSPData
*
* \brief Структура для получения информации о пароле на контейнер.
*
* \req_wincryptex
* \sa CPGetProvParam, CRYPT_PIN_INFO_SOURCE, CRYPT_FKC_EKE_AUTH_INFO_PARAM
*/
typedef union _CRYPT_FKC_PIN_INFO_SOURCE {
    CRYPT_PIN_INFO_SOURCE passwd; /*!< обычный пароль. */
    CRYPT_FKC_EKE_AUTH_INFO_PARAM eke_passwd; /*!< пароль по EKE. */
} CRYPT_FKC_PIN_INFO_SOURCE;

/*!
* \ingroup ProCSPData
*
* \brief Структура для получения информации о пароле на контейнер.
*
* \req_wincryptex
* \sa CPGetProvParam, CRYPT_FKC_PIN_INFO_SOURCE
*/
typedef struct _CRYPT_FKC_PIN_INFO {
    BYTE type;
    /*!< Тип данных.
     *  CRYPT_PIN_FKC_EKE - пароль передается FKC контейнеру по EKE.
     *  Другие типы как в CSP.
     */
     CRYPT_FKC_PIN_INFO_SOURCE dest; /*!< Данные соответствующего типа */
} CRYPT_FKC_PIN_INFO;

/*!
 * \ingroup ProCSPData
 *
 * \brief Значения параметра "проверка открытого ключа в операции Диффи-Хеллмана".
 * При установке параметра передается переменной типа DWORD. 
 *
 * \req_wincryptex
 * \sa CPGetProvParam
 * \sa CPSetProvParam
 * \sa CRYPT_FKC_DH_CHECK
 */
typedef enum _CRYPT_FKC_DH_CHECK_VAL
{
    dh_check_disable = 1, /*!< Проверка открытого ключа не осуществляется */
    dh_check_enable = 2 /*!< Проверка открытого ключа осуществляется */
} CRYPT_FKC_DH_CHECK_VAL;

/*!
 * \ingroup ProCSPData
 *
 * \brief Структура для получения статуса проверки открытого ключа.
 * Получает и устанавливает параметр "проверка открытого ключа в операции Диффи-Хеллмана"
 * для провайдеров FKC ( PP_FKC_DH_CHECK ). 
 *
 * \req_wincryptex
 * \sa CPGetProvParam
 * \sa CPSetProvParam
 * \sa CRYPT_FKC_DH_CHECK_VAL
 */
typedef struct _CRYPT_FKC_DH_CHECK
{
    CRYPT_FKC_DH_CHECK_VAL checkdh; /* значение параметра */
    CSP_BOOL is_writable; /*!< можно ли установить параметру новое значение */
} CRYPT_FKC_DH_CHECK;

/*!
 * \ingroup ProCSPData
 *
 * \brief Структура для получения и установки настроек кэширования контейнеров.
 *
 * \req_wincryptex
 * \sa CPGetProvParam
 * \sa CPSetProvParam
 */
typedef struct _CRYPT_CACHE_SIZE {
    DWORD cache_size; /*!< Размер кэша. */
    DWORD max_cache_size; /*!< Максимальный размер кэша. */
    CSP_BOOL is_writable; /*!< см. CACHE_RO  */
} CRYPT_CACHE_SIZE;

/*!
* \ingroup ProCSPData
*
* \brief Блоб с информацией о считывателе, представляющий собой
* сериализованную псевдоструктуру.
*
* \req_wincryptex
* \sa CPGetProvParam
*/
typedef struct _CRYPT_ENUMREADER_INFO {
    char    szNickName[1]; /*!< NickName считывателя - NULL-терминированная строка. */
    char    szName[1]; /*!< Имя считывателя - NULL-терминированная строка. */
    DWORD   Flags; /*!< Флаги считывателя. */
} CRYPT_ENUMREADER_INFO;

/*!
 * \ingroup ProCSPData
 *
 * \brief Структура передачи информации для получения и установки разделённого значения параметра R для ЭЦП 
 *  на базе функционального ключевого носителя.
 *
 * \sa CPGetHashParam
 * \sa CPSetHashParam
 */
typedef struct _CRYPT_HASH_BLOB_EX {
    CRYPT_PUBKEY_INFO_HEADER tPublicKeyParam;
    BYTE    pbData [2*SECRET_KEY_LEN];
} CRYPT_HASH_BLOB_EX, *PCRYPT_HASH_BLOB_EX;

/*!
 * \ingroup ProCSPData
 *
 * \brief Структура передачи информации функции хэширования по алгоритму CALG_EKEVERIFY_HASH.
 * 
 *
 * \sa CPGetKeyParam
 * \sa CPSetKeyParam
 */
typedef struct _TOKEN_VERIFYDATA {
    BYTE e_[3*SECRET_KEY_LEN];
    BYTE xQ_ab[SECRET_KEY_LEN];
    BYTE xQ_pw[SECRET_KEY_LEN];
    DWORD Verify;
} TOKEN_VERIFYDATA,*PTOKEN_VERIFYDATA;

#define CSP_INFO_FREE_SPACE	(0)	/* свободное место на /var в bytes */
#define CSP_INFO_NUMBER_UL	(1)	/* "\\local\\number_UL" --- количество выпущенных ключей УЛ */
#define CSP_INFO_NUMBER_SIGNS	(2)     /* "\\local\\number_signs" --- количество операций подписи */
#define CSP_INFO_KCARDS_CHANGES	(3)     /* "\\local\\Kcard_changes" --- количество смен карт канала "К" */
#define CSP_INFO_NUMBER_KCARDS	(4)     /* "\\local\\number_Kcard_sessions" --- количество выпущенных в последний раз карт канала "К" */
#define CSP_INFO_NUMBER_KEYS	(5)     /* "\\local\\number_keys" --- количество выпущенных  */
#define CSP_INFO_FUTURE_SIZE	(10)
typedef struct
{
  WORD version;		/* версия структуры */
  DWORD time;		/* time_t */
  DWORD keys_remaining;	/* остаток ДСРФ */
  DWORD future[CSP_INFO_FUTURE_SIZE];
} CSP_INFO;

/* Длина секретного ключа для ГОСТ 28147, подписи и обмена.*/

#define CPC_FAST_CODE_DEFAULT	0
#define CPC_FAST_CODE_NO	1
#define CPC_FAST_CODE_USER	2

#ifdef UNIX
#if defined(__GNUC__) && !defined(IOS)
#define CPCAPI __attribute__((regparm(0)))
#else // __GNUC__
#define CPCAPI
#endif // __GNUC__
#else // UNIX
#define CPCAPI __cdecl
#endif // UNIX


/*!
 * \ingroup ProCSPData
 * \brief Описание функции захвата FPU в режиме ядра ОС.
 * 
 *  Функция должна обеспечивать захват FPU (сохраняя
 *  значения регистров MMX (ST) и XMM ). Ей передаются
 *  буфер для сохранения регистров, его размер, 
 *  тип функции, использующей дополнительные регистры,
 *  осуществляющей ее вызов, и дополнительные параметры,
 *  по которым можно судить о целесообразности захвата.
 *
 * \param buf [in] Невыровненный буфер, предоставляемый провайдером для сохранения
 *  дополнительных регистров.
 *
 * \param sz [in] Размер буфера, переданного провайдером для сохранения
 *  дополнительных регистров.
 *
 * \param bl_len [in] Размер данных, обрабатываемых функцией, запросившей
 * сохранение регистров.
 * 
 * \param op_type [in] Тип функции, запросившей сохранение регистров.
 * Тип может быть одним из четырех:<br>
 * <table><tr><th>
 * Значение \e op_type
 * </th><th>
 *      Тип функции
 * </th></tr><tr><td>
 * #CSP_OPERATION_CIPHER1
 * </td><td>
 *      Неспараллеливаемая функция шифрования по ГОСТ 28147-89
 * </td></tr><tr><td>
 * #CSP_OPERATION_CIPHER2
 * </td><td>
 *      Спараллеленная функция шифрования по ГОСТ 28147-89
 * </td></tr><tr><td>
 * #CSP_OPERATION_IMIT
 * </td><td>
 *      Функция выработки имитовставки по ГОСТ 28147-89
 * </td></tr><tr><td>
 * #CSP_OPERATION_HASH
 * </td><td>
 *      Функция хэширования по ГОСТ Р 34.11-94
 * </td></tr></table>
 *
 * \return результат захвата сопроцессора FPU.
 *
 * \retval TRUE Захват сопроцессора был осуществлен. 
 * В этом случае провайдер вызовет функцию, использующую
 * MMX или SSE, и после нее - функцию \ref CPC_Kernel_Fpu_End_Callback .
 * Различные типы функций провайдера работают с разными скоростями,
 * и для целесообразности захвата FPU передаются как тип функции провайдера,
 * так и количество обрабатываемых данных. 
 * \retval FALSE Захват не был осуществлен. В этом случае
 * провайдер вызовет функцию, использующую только стандартный набор
 * инструкций (универсальную).
 * \sa CPC_FAST_CODE
 * \sa CPC_Kernel_Fpu_End_Callback
 * \sa CPSetProvParam()
 * \sa CPCSetProvParam()
 */
typedef CSP_BOOL CPCAPI CPC_Kernel_Fpu_Begin_Callback(
    /* [in] */ BYTE * buf,
    /* [in] */ size_t sz,
    /* [in] */DWORD bl_len,
    /* [in] */DWORD op_type);


/*!
 * \ingroup ProCSPData
 * \brief Описание функции освобождения FPU в режиме ядра ОС.
 * 
 *  Функция должна обеспечивать освобождение FPU (восстанавливая
 *  значения регистров MMX (ST) и XMM ). Ей передаются буфер 
 *  для сохранения регистров, его размер, тип функции, использовавшей
 *  в провайдере дополнительные регистры, и осуществившей вызов парной 
 *  функции \ref CPC_Kernel_Fpu_Begin_Callback .
 *
 * \param buf [in] Буфер, предоставляемый провайдером для сохранения
 *  дополнительных регистров. В нем должна была сохранить состояние
 *  сопроцессора функция \ref CPC_Kernel_Fpu_Begin_Callback .
 *
 * \param sz [in] Размер буфера, переданного провайдером для сохранения
 *  дополнительных регистров.
 *
 * \param op_type [in] Тип функции, запросившей сохранение регистров.
 * Тип может быть одним из четырех:<br>
 * <table><tr><th>
 * Значение \e op_type
 * </th><th>
 *      Тип функции
 * </th></tr><tr><td>
 * #CSP_OPERATION_CIPHER1
 * </td><td>
 *      Неспараллеливаемая функция шифрования по ГОСТ 28147-89
 * </td></tr><tr><td>
 * #CSP_OPERATION_CIPHER2
 * </td><td>
 *      Спараллеленная функция шифрования по ГОСТ 28147-89
 * </td></tr><tr><td>
 * #CSP_OPERATION_IMIT
 * </td><td>
 *      Функция выработки имитовставки по ГОСТ 28147-89
 * </td></tr><tr><td>
 * #CSP_OPERATION_HASH
 * </td><td>
 *      Функция хэширования по ГОСТ Р 34.11-94
 * </td></tr></table>
 *
 * \return результат освобождения сопроцессора FPU.
 *
 * \retval TRUE Освобождение сопроцессора было осуществлено. 
 * \retval FALSE Освобождение не было осуществлено. 
 *
 * \sa CPC_FAST_CODE_
 * \sa CPC_Kernel_Fpu_Begin_Callback
 * \sa CPSetProvParam()
 * \sa CPCSetProvParam()
 */
typedef CSP_BOOL CPCAPI CPC_Kernel_Fpu_End_Callback(
    /* [in] */ BYTE * buf,
    /* [in] */ size_t sz,
    /* [in] */ DWORD op_type);

/*!
 *  \ingroup ProCPCData
 *
 *  \brief Настройки использования SSE2.
 *
 *  На процессоре Intel Pentium 4 можно достичь ускорения алгоритмов
 *  шифрования и хэширования за счет использования инструкций расширений MMX и SSE2.
 *  Настройка захвата SSE2 осуществляется с помощью данной структуры.
 *  
 *  Криптографические функции, использующие расширения MMX и SSE2, сведены в 
 *  следующие наборы:
 *  <table><tr><th>
 * Идентификатор набора
 * </th><th>
 *      Группа
 * </th></tr><tr><td>
 * #CSP_OPERATION_CIPHER1
 * </td><td>
 *      Неспараллеливаемые функции шифрования по ГОСТ 28147-89.
 *	Для них необходимо только командное расширение MMX.
 * </td></tr><tr><td>
 * #CSP_OPERATION_CIPHER2
 * </td><td>
 *      Спараллеленные функции шифрования по ГОСТ 28147-89.
 *	Для них необходимо только командное расширение MMX.
 * </td></tr><tr><td>
 * #CSP_OPERATION_IMIT
 * </td><td>
 *      Функция выработки имитовставки по ГОСТ 28147-89.
 *	Для нее необходимо только командное расширение MMX.
 * </td></tr><tr><td>
 * #CSP_OPERATION_HASH
 * </td><td>
 *      Функции хэширования по ГОСТ Р 34.11-94.
 *	Для них необходимы командные расширения MMX и SSE2.
 * </td></tr><tr><td>
 * #CSP_OPERATION_MULT
 * </td><td>
 *      Функция умножения в поле по модулю P (Применяется в протоколах подписи 
 *	и Диффи-Хеллмана).
 *	Для нее необходимы командные расширения MMX и SSE2.
 * </td></tr></table>
 * Совокупность выборов универсальных или использующих командные расширения 
 * наборов функций будем называть сочетанием наборов. Любое сочетание наборов 
 * кодируется в одном двойном машинном слове, как логическая сумма 
 * идентификаторов наборов функций MMX и SSE.
 *
 * В связи с большим разнообразием аппаратных платформ на базе процессоров 
 * архитектуры x86 и эмуляций x86 на архитектурах x64 и IA64, нет возможности 
 * заранее определить, какой из наборов функций в группах будет работать быстрее 
 * на конкретном процессоре, с конкретной частотой шины, скоростью памяти  и т.п. 
 *
 * Настроить провайдер на использование наиболее быстрого сочетания наборов
 * можно с помощью вызова SetProvParam (PP_FAST_CODE_FUNCS), в который передается
 * данная структура, либо, на уровне CPC, при инициализации криптографического 
 * модуля, путем передачи данной структуры в инициализатор провайдера, или
 * при использовании криптопровайдера в пользовательском режиме, путем установки
 * маски оптимального набора функций в реестр с помощью утилиты csptest, с
 * параметрами '-speed -type ALL -mode REG'. Такой вызов запищет маску в реестр
 * или его эмуляцию в параметр '/Parameters/MMXFuncs'.
 * 
 * У провайдера есть три режима использования функций MMX:
 * 1. Некое стандартное сочетание, считающиеся наиболее производительным.
 * 2. Сочетание, состоящее только из наборов универсальных функций.
 * 3. Сочетание, устанавливаемое пользователем с помощью функции SetProvParam.
 * Первое из них при работе через уровени Crypt и CP устанавливаются из реестра,
 * или, если реестр недоступен или параметр неопределен, как некоторое 
 * стандартное сочетание, задаваемое провайдером для данной системы. 
 * При работе на уровне CPC первое сочетание передается пользователем при инициализации
 * провайдера, или запрашивается установка стандартного для провайдера сочетания.
 *
 * При установке нового сочетания наборов провайдер в любом случае проверит, 
 * возможно ли на данном процессоре использование таких наборов функций MMX и SSE,
 * и, если возможность есть, установит наборы. В режиме ядра, кроме того,
 * перед вызовом каждой функции, использующей MMX или SSE2, будет осуществлен
 * вызов callback'а захвата FPU, и не универсальный код будет использоваться только
 * в случае успешного захвата, после чего будет вызван callback функции 
 * освобождения FPU. Если захват не удался, будет выполняться универсальный
 * код функции.
 *
 * \sa CPC_CONFIG_
 */
typedef struct _CPC_FAST_CODE {
    DWORD UsesFunctions;
		/*!< Обязательный параметр, может быть равен CPC_FAST_CODE_DEFAULT,
		 *   CPC_FAST_CODE_NO, CPC_FAST_CODE_USER.
		 * <table><tr><th>
		 * Возможные значения:</th><th>Интерпретация:
		 * </th>
		 * </tr>
		 * <tr><td>
		 * CPC_FAST_CODE_DEFAULT</td>
			<td>Использовать сочетание наборов по умолчанию.
		 * 	</td></tr>
		 * <tr><td>
		 * CPC_FAST_CODE_NO</td><td>Использовать сочетание наборов универсальных функций.
		 * </td></tr>
		 * <tr><td>
		 * CPC_FAST_CODE_USER</td><td>Использовать сочетание наборов функций, задаваемое 
		 * параметром UsedMask.
		 * </td></tr>
		 * </table>
		 */
    CPC_Kernel_Fpu_Begin_Callback * cp_kernel_fpu_begin;
		/*!< Указатель на функцию захвата FPU.
		 *   Применяется в режиме ядра. Хранит указатель на функцию захвата FPU,
		 *   которую будут вызывать функции, использующие расширения MMX и SSE.
		 *   Устанавливается только при UsesFunctions == CPC_FAST_CODE_USER.
		 *   См. \ref CPC_Kernel_Fpu_Begin_Callback
		 *   
		 */
    CPC_Kernel_Fpu_End_Callback *cp_kernel_fpu_end;
		/*!< Указатель на функцию освобождения FPU.
		 *   Применяется в режиме ядра. Хранит указатель на функцию освобождения
		 *   FPU. 
		 *   Используется только при UsesFunctions == CPC_FAST_CODE_USER.
		 *   См. \ref CPC_Kernel_Fpu_End_Callback
		 */
    DWORD  Kernel_Buf_Size;
		/*!< Размер невыровненного буфера, который будет передаваться в функции 
		 *   захвата и осовобождения FPU для сохранения регистров. Используется 
		 *   только при UsesFunctions == CPC_FAST_CODE_USER.
		 *   Значение не может превышать 1024.
		 *   См. \ref CPC_Kernel_Fpu_Begin_Callback , \ref CPC_Kernel_Fpu_End_Callback
		 */
    DWORD   UsedMask;
		/*!< Маска, задающая сочетание наборов функций. Является логической 
		 *   суммой идентификаторов наборов функций, использующих командные расширения, 
		 *   которые следует вызывать в криптопровайдере (см. выше). В пользовательском
		 *   режиме в ней передаются любые возможные сочетания всех пяти наборов,
		 *   в режиме ядра - всех, кроме набора умножения по модулю P. 
		 */
} CPC_FAST_CODE;

/*! \ingroup ProCSPData
 * \defgroup ProCSPDataFast Переключатели кода
 * Значения переключателей кода на более быстрый (с использованием SSE2).
 *
 * При использовании в функции \ref CPGetProvParam (PP_FAST_CODE_FLAGS), в параметре pbData возвращаются
 * флаги, определяющие набор провереных на включенный код функций.
 * Указание, какие функции проверять на включенный код, передается
 * во флагах \e dwFlags.
 *
 * Если применен флаг CRYPT_FAST_CODE_GET_SETFN, при выходе
 * \ref CSP_FAST_CODE_GET_SETFN будет установлен в 1, если провайдер может использовать
 * быстрый код, и 0 - иначе. Если установлен флаг CRYPT_FAST_CODE_ALL_FUNCTIONS,
 * будут проверяться все функции, и на выходе будут установлены все флаги
 * \ref CSP_FAST_CODE_E_ECB, \ref CSP_FAST_CODE_E_CBC, \ref CSP_FAST_CODE_E_CNT,
 * \ref CSP_FAST_CODE_E_CFB, \ref CSP_FAST_CODE_D_ECB, \ref CSP_FAST_CODE_D_CBC,
 * \ref CSP_FAST_CODE_D_CNT, \ref CSP_FAST_CODE_D_CFB, \ref CSP_FAST_CODE_MD_ECB,
 * \ref CSP_FAST_CODE_GR3411SP, \ref CSP_FAST_CODE_GR3411H, \ref CSP_FAST_CODE_GR3411HV,
 * \ref CSP_FAST_CODE_HASH, \ref CSP_FAST_CODE_IMIT, \ref CSP_FAST_CODE_MULT,
 * в 1, если соответствующая функция использует быстрый код, и 0 - иначе.
 * В режиме пользователя следует вместо флага  CRYPT_FAST_CODE_ALL_FUNCTIONS
 * использовать CRYPT_FAST_CODE_ALL_USER_FUNCTIONS, а в режиме ядра ОС -
 * CRYPT_FAST_CODE_ALL_KERNEL_FUNCTIONS. На выходе флаг \ref CSP_FAST_CODE_GET_FN установлен в 1,
 * если быстрый код работает во всех выбранных функциях, и 0 если хотя бы одна
 * из выбранных функций не сработала.
 * Поведение невыбранных флагов неопределено.
 *
 * \sa #CPGetProvParam (PP_FAST_CODE_FLAGS)
 * \{
 */

/*!
 *  \brief Флаг, возвращаемый функцией \ref CPGetProvParam (PP_FAST_CODE_FLAGS).
 *  Используется для определения полноты набора установленных быстрых функций.
 */
#define CSP_FAST_CODE_GET_FN	(1<<28)


/*!
 *  \brief Флаг, возвращаемый функцией \ref CPGetProvParam (PP_FAST_CODE_FLAGS).
 *  Используется для определения, может ли провайдер .
 *  исполнять быстрый код на данной машине.
 */
#define CSP_FAST_CODE_GET_SETFN	(1<<27)

/*!
 *  \brief Флаг, возвращаемый функцией \ref CPGetProvParam (PP_FAST_CODE_FLAGS).
 *  Используется как флаг, для проверки, какой код
 *  применяется в функции зашифрования по ECB
 *  Равен 1 в случае быстрого кода данной функции,
 *  и 0 иначе.
 */
#define CSP_FAST_CODE_E_ECB	(1)

/*!
 *  \brief Флаг, возвращаемый функцией \ref CPGetProvParam (PP_FAST_CODE_FLAGS).
 *  Используется как флаг, для проверки, какой код
 *  применяется в функции зашифрования по CBC
 *  Равен 1 в случае быстрого кода данной функции,
 *  и 0 иначе.
 */
#define CSP_FAST_CODE_E_CBC	(1<<1)

/*!
 *  \brief Флаг, возвращаемый функцией \ref CPGetProvParam (PP_FAST_CODE_FLAGS).
 *  Используется как флаг, для проверки, какой код
 *  применяется в функции зашифрования по CNT
 *  Равен 1 в случае быстрого кода данной функции,
 *  и 0 иначе.
 */
#define CSP_FAST_CODE_E_CNT	(1<<2)

/*!
 *  \brief Флаг, возвращаемый функцией \ref CPGetProvParam (PP_FAST_CODE_FLAGS).
 *  Используется как флаг, для проверки, какой код
 *  применяется в функции расшифрования по CNT
 *  Равен 1 в случае быстрого кода данной функции,
 *  и 0 иначе.
 */
#define CSP_FAST_CODE_D_CNT	(1<<2)

/*!
 *  \brief Флаг, возвращаемый функцией \ref CPGetProvParam (PP_FAST_CODE_FLAGS).
 *  Используется как флаг, для проверки, какой код
 *  применяется в функции зашифрования по CFB
 *  Равен 1 в случае быстрого кода данной функции,
 *  и 0 иначе.
 */
#define CSP_FAST_CODE_E_CFB	(1<<3)

/*!
 *  \brief Флаг, возвращаемый функцией \ref CPGetProvParam (PP_FAST_CODE_FLAGS).
 *  Используется как флаг, для проверки, какой код
 *  применяется в функции расшифрования по ECB
 *  Равен 1 в случае быстрого кода данной функции,
 *  и 0 иначе.
 */
#define CSP_FAST_CODE_D_ECB	(1<<4)

/*!
 *  \brief Флаг, возвращаемый функцией \ref CPGetProvParam (PP_FAST_CODE_FLAGS).
 *  Используется как флаг, для проверки, какой код
 *  применяется в функции расшифрования по CBC
 *  Равен 1 в случае быстрого кода данной функции,
 *  и 0 иначе.
 */
#define CSP_FAST_CODE_D_CBC	(1<<5)

/*!
 *  \brief Флаг, возвращаемый функцией \ref CPGetProvParam (PP_FAST_CODE_FLAGS).
 *  Используется как флаг, для проверки, какой код
 *  применяется в функции расшифрования по CFB
 *  Равен 1 в случае быстрого кода данной функции,
 *  и 0 иначе.
 */
#define CSP_FAST_CODE_D_CFB	(1<<6)

/*!
 *  \brief Флаг, возвращаемый функцией \ref CPGetProvParam (PP_FAST_CODE_FLAGS).
 *  Используется как флаг, для проверки, какой код
 *  применяется в функции маскирования ключа
 *  Равен 1 в случае быстрого кода данной функции,
 *  и 0 иначе.
 */
#define CSP_FAST_CODE_MD_ECB	(1<<7)

/*!
 *  \brief Флаг, возвращаемый функцией \ref CPGetProvParam (PP_FAST_CODE_FLAGS).
 *  Используется как флаг, для проверки, какой код
 *  применяется в упрощенной функции хэширования.
 *  Флаг устанавливается только в режиме ядра ОС.
 *  Равен 1 в случае быстрого кода данной функции,
 *  и 0 иначе.
 */
#define CSP_FAST_CODE_GR3411SP	(1<<8)

/*!
 *  \brief Флаг, возвращаемый функцией \ref CPGetProvParam (PP_FAST_CODE_FLAGS).
 *  Используется как флаг, для проверки, какой код
 *  применяется в функции хэширования.
 *  Флаг устанавливается только в режиме ядра ОС.
 *  Равен 1 в случае быстрого кода данной функции,
 *  и 0 иначе.
 */
#define CSP_FAST_CODE_GR3411H	(1<<9)

/*!
 *  \brief Флаг, возвращаемый функцией \ref CPGetProvParam (PP_FAST_CODE_FLAGS).
 *  Используется как флаг, для проверки, какой код
 *  применяется в функции проверки хэша.
 *  Флаг устанавливается только в режиме ядра ОС.
 *  Равен 1 в случае быстрого кода данной функции,
 *  и 0 иначе.
 */
#define CSP_FAST_CODE_GR3411HV	(1<<10)

/*!
 *  \brief Флаг, возвращаемый функцией \ref CPGetProvParam (PP_FAST_CODE_FLAGS).
 *  Используется как флаг, для проверки, какой код
 *  применяется в функции хэш-преобразования.
 *  Равен 1 в случае быстрого кода данной функции,
 *  и 0 иначе.
 */
#define CSP_FAST_CODE_HASH	(1<<11)

/*!
 *  \brief Флаг, возвращаемый функцией \ref CPGetProvParam (PP_FAST_CODE_FLAGS).
 *  Используется как флаг, для проверки, какой код
 *  применяется в функции выработки имитовставки.
 *  Равен 1 в случае быстрого кода данной функции,
 *  и 0 иначе.
 */
#define CSP_FAST_CODE_IMIT	(1<<12)

/*!
 *  \brief Флаг, возвращаемый функцией \ref CPGetProvParam (PP_FAST_CODE_FLAGS).
 *  Используется как флаг, для проверки, какой код
 *  применяется в функции умножения.
 *  Равен 1 в случае быстрого кода данной функции,
 *  и 0 иначе.
 */
#define CSP_FAST_CODE_MULT	(1<<13)

/*!
 *  \brief Флаг, возвращаемый функцией \ref CPGetProvParam (PP_FAST_CODE_FLAGS).
 *  Используется как флаг, для проверки, какой код применяется
 *  в функциях умножения в UNIX-оподобных системах.
 *  Равен 1 в случае быстрого кода данной функции,
 *  и 0 иначе.
 */
#define CSP_FAST_CODE_MULT_ATT	(1<<13)

/*!
 *  \brief Набор флагов, возвращаемый функцией \ref CPGetProvParam (PP_FAST_CODE_FLAGS).
 *  Группирует все флаги функций зашифрования.
 */
#define CSP_FAST_CODE_ALL_ENCRYPT (CSP_FAST_CODE_E_ECB|CSP_FAST_CODE_E_CBC|CSP_FAST_CODE_E_CNT|CSP_FAST_CODE_E_CFB)

/*!
 *  \brief Набор флагов, возвращаемый функцией \ref CPGetProvParam (PP_FAST_CODE_FLAGS).
 *  Группирует все флаги функций расшифрования.
 */
#define CSP_FAST_CODE_ALL_DECRYPT (CSP_FAST_CODE_D_ECB|CSP_FAST_CODE_D_CBC|CSP_FAST_CODE_D_CNT|CSP_FAST_CODE_D_CFB)

/*!
 *  \brief Набор флагов, возвращаемый функцией \ref CPGetProvParam (PP_FAST_CODE_FLAGS).
 *  Группирует все флаги функций хэширования.
 */
#define CSP_FAST_CODE_ALL_HASH (CSP_FAST_CODE_HASH|CSP_FAST_CODE_GR3411SP|CSP_FAST_CODE_GR3411H|CSP_FAST_CODE_GR3411HV)

/*!
 *  \brief Набор флагов, возвращаемый функцией \ref CPGetProvParam (PP_FAST_CODE_FLAGS).
 *  Группирует все флаги функций умножения.
 */
#define CSP_FAST_CODE_ALL_MULT (CSP_FAST_CODE_MULT|CSP_FAST_CODE_MULT_ATT)

/*!
 *  \brief Набор флагов, возвращаемый функцией \ref CPGetProvParam (PP_FAST_CODE_FLAGS).
 *  Группирует все флаги функций шифрования.
 */
#define CSP_FAST_CODE_ALL_CRYPT (CSP_FAST_CODE_ALL_ENCRYPT|CSP_FAST_CODE_ALL_DECRYPT|CSP_FAST_CODE_MD_ECB|CSP_FAST_CODE_IMIT)

/*!
 *  \brief Набор флагов, возвращаемый функцией \ref CPGetProvParam (PP_FAST_CODE_FLAGS).
 *  Группирует все флаги переключаемых функций криптопровайдера.
 */
#define CSP_FAST_CODE_ALL_FUNCTIONS (CSP_FAST_CODE_ALL_CRYPT|CSP_FAST_CODE_ALL_HASH|CSP_FAST_CODE_ALL_MULT)

/*!
 *  \brief Набор флагов, возвращаемый функцией \ref CPGetProvParam (PP_FAST_CODE_FLAGS).
 *  Группирует все флаги переключаемых функций
 *  криптопровайдера режима ядра ОС.
 */
#define CSP_FAST_CODE_ALL_KERNEL_FUNCTIONS (CSP_FAST_CODE_ALL_CRYPT|CSP_FAST_CODE_ALL_HASH)

/*!
 *  \brief Набор флагов, возвращаемый функцией \ref CPGetProvParam (PP_FAST_CODE_FLAGS).
 *  Группирует все флаги переключаемых функций
 *  криптопровайдера пользовательского режима.
 */
#define CSP_FAST_CODE_ALL_USER_FUNCTIONS (CSP_FAST_CODE_ALL_CRYPT|CSP_FAST_CODE_HASH|CSP_FAST_CODE_ALL_MULT)


/*!
 * \brief Флаг, используемый при вызове \ref CPGetProvParam (PP_FAST_CODE_FLAGS), запращивает вариант кода
 *  для всех функций провайдера в режиме ядра ОС.
 */
#define CRYPT_FAST_CODE_ALL_KERNEL_FUNCTIONS	1

/*!
 * \brief Флаг, используемый при вызове \ref CPGetProvParam (PP_FAST_CODE_FLAGS), запращивает вариант кода
 * для всех функций провайдера в режиме пользователя.
 */
#define CRYPT_FAST_CODE_ALL_USER_FUNCTIONS	2

/*!
 * \brief Флаг, используемый при вызове \ref CPGetProvParam (PP_FAST_CODE_FLAGS), запращивает вариант кода
 * для всех функций провайдера.
 */
#define CRYPT_FAST_CODE_ALL_FUNCTIONS		(CRYPT_FAST_CODE_ALL_KERNEL_FUNCTIONS|CRYPT_FAST_CODE_ALL_USER_FUNCTIONS)

/*!
 * \brief Флаг, используемый при вызове \ref CPGetProvParam (PP_FAST_CODE_FLAGS), запрашивает
 * результат определения процессора.
 */
#define CRYPT_FAST_CODE_GET_SETFN		8


/*!
 *  \brief Возможное значение третьего аргумента функции \ref CPC_Kernel_Fpu_Begin_Callback .
 *  Говорит о том, что запрос захвата FPU произошел в функции неспараллеленного шифрования.
 *  Также задает значение идентификатора набора функций неспараллеливаемого шифрования, 
 *  использующих расширение MMX.
 */
#define CSP_OPERATION_CIPHER1	(CSP_FAST_CODE_E_CFB | CSP_FAST_CODE_E_CBC)

/*!
 *  \brief Возможное значение третьего аргумента функции \ref CPC_Kernel_Fpu_Begin_Callback .
 *  Говорит о том, что запрос захвата FPU произошел в функции спараллеленного шифрования.
 *  Также задает значение идентификатора набора функций спараллеленного шифрования, 
 *  использующих расширение MMX.
 */
#define CSP_OPERATION_CIPHER2	(CSP_FAST_CODE_E_ECB | CSP_FAST_CODE_E_CNT | CSP_FAST_CODE_D_ECB | CSP_FAST_CODE_D_CBC | CSP_FAST_CODE_D_CNT | CSP_FAST_CODE_D_CFB | CSP_FAST_CODE_MD_ECB)

/*!
 *  \brief Возможное значение третьего аргумента функции \ref CPC_Kernel_Fpu_Begin_Callback .
 *  Говорит о том, что запрос захвата FPU произошел в функции выработки имитовставки.
 *  Также задает значение идентификатора набора функций выработки имитовставки, 
 *  использующих расширение MMX.
 */
#define CSP_OPERATION_IMIT	(CSP_FAST_CODE_IMIT)

/*!
 *  \brief Возможное значение третьего аргумента функции \ref CPC_Kernel_Fpu_Begin_Callback .
 *  Говорит о том, что запрос захвата FPU произошел в функции вычисления хэша. В данном случае
 *  необходимо сохранять не только регистры ST0 - ST7, но и XMM0 - XMM7.
 *  Также задает значение идентификатора набора функций хэшифрования, 
 *  использующих расширения MMX и SSE2.
 */
#define CSP_OPERATION_HASH	(CSP_FAST_CODE_ALL_HASH)

/*!
 *  \brief Битовая маска для включения/выключения кода MMX в функции умножения.
 *  Задает значение идентификатора набора функций умножения по модулю P, 
 *  использующих расширения MMX и SSE2. Применяется только в пользовательском режиме.
 */
#define CSP_OPERATION_MULT	(CSP_FAST_CODE_ALL_MULT)

/*!
 *  \brief Битовая маска для включения/выключения кода MMX во всех функциях.
 *  Задает значение логической суммы всех идентификаторов наборов функций,
 *  использующих MMX и SSE2.
 */
#define CSP_OPERATION_ALL	(CSP_OPERATION_MULT | CSP_OPERATION_HASH | CSP_OPERATION_IMIT | CSP_OPERATION_CIPHER2 | CSP_OPERATION_CIPHER1)

/*!
 *  \brief Битовая маска, означающая неопределенную установку функций. Применяется, если 
 *  нужно установить набор функций по умолчанию для данного процессора.
 */
#define CSP_OPERATION_UNDEF	(0xFFFFFFFF)


/*! \} */

typedef struct _CRYPT_LCD_QUERY_PARAM {
  const char *message;
} CRYPT_LCD_QUERY_PARAM;


//Deprecated Defines
#if !(defined(CPCSP_C_SOURCE ) && CPCSP_C_SOURCE - 0 < 36) 
#undef CP_GR3410_94_PROV
#undef CP_KC1_GR3410_94_PROV
#undef CP_KC2_GR3410_94_PROV
#undef PH_GR3410_94_PROV

#undef PROV_GOST_DH
#undef PROV_GOST_94_DH
#endif

#if !defined(CPCSP_USE_NON_STANDART_OIDS) && !(defined(CPCSP_C_SOURCE ) && CPCSP_C_SOURCE - 0 < 36) 

/* Deprecated cipher mode*/
#undef CRYPT_MODE_CBC 

/* OIDs for HASH */
#undef szOID_GostR3411_94_TestParamSet
#undef szOID_GostR3411_94_CryptoPro_B_ParamSet
#undef szOID_GostR3411_94_CryptoPro_C_ParamSet
#undef szOID_GostR3411_94_CryptoPro_D_ParamSet

/* OIDs for Crypt */
#undef szOID_Gost28147_89_TestParamSet
#undef szOID_Gost28147_89_CryptoPro_Oscar_1_1_ParamSet
#undef szOID_Gost28147_89_CryptoPro_Oscar_1_0_ParamSet
#undef szOID_Gost28147_89_CryptoPro_RIC_1_ParamSet

/* OID for Signature 1024*/
#undef szOID_GostR3410_94_CryptoPro_A_ParamSet
#undef szOID_GostR3410_94_CryptoPro_B_ParamSet
#undef szOID_GostR3410_94_CryptoPro_C_ParamSet
#undef szOID_GostR3410_94_CryptoPro_D_ParamSet

/* OID for Signature 512*/
#undef szOID_GostR3410_94_TestParamSet

/* OID for DH 1024*/
#undef szOID_GostR3410_94_CryptoPro_XchA_ParamSet
#undef szOID_GostR3410_94_CryptoPro_XchB_ParamSet
#undef szOID_GostR3410_94_CryptoPro_XchC_ParamSet

/* OID for EC signature */
#undef szOID_GostR3410_2001_TestParamSet

#endif



/*! \defgroup ProCSPEx Дополнительные параметры и определения
 *\ingroup ProCSP
 * Данный раздел содержит определения идентификаторов и параметров,
 * используемых в криптопровайдере "КриптоПро CSP".
 *
 * \{
 */

/*! \page DP1 Идентификаторы алгоритмов криптопровайдера
 *
 * <table>
 * <tr><th>Идентификатор</th><th>Описание идентификатора</th></tr>
 * <tr><td>CALG_GR3411</td><td>Идентификатор алгоритма хэширования по ГОСТ Р 34.11-94.</td></tr>
 * <tr><td>CALG_G28147_MAC</td><td>Идентификатор алгоритма имитозащиты по ГОСТ 28147-89.</td></tr>
 * <tr><td>CALG_G28147_IMIT </td><td>То же самое, что и CALG_G28147_MAC (устаревшая версия).</td></tr>
 * <tr><td> CALG_GR3410 </td><td> Идентификатор алгоритма ЭЦП по ГОСТ Р 34.10-94. </td></tr>
 * <tr><td> CALG_GR3410EL </td><td> Идентификатор алгоритма ЭЦП по ГОСТ Р 34.10-2001.</td></tr>
 * <tr><td>CALG_G28147</td><td>Идентификатор алгоритма шифрования по ГОСТ 28147-89. </td></tr>
 * <tr><td>CALG_DH_EX_SF </td><td>Идентификатор алгоритма обмена ключей по Диффи-Хеллману на базе закрытого ключа пользователя. </td></tr>
 * <tr><td>CALG_DH_EX_EPHEM </td><td>Идентификатор CALG_DH_EX алгоритма обмена ключей по Диффи-Хеллману на базе закрытого ключа эфемерной пары. Открытый ключ получается по ГОСТ Р 34.10 94.</td></tr>
 * <tr><td>CALG_DH_EX </td><td>Идентификатор CALG_DH_EX алгоритма обмена ключей по Диффи-Хеллману на базе закрытого ключа пользователя. Открытый ключ получается по ГОСТ Р 34.10 94. </td></tr>
 * <tr><td>CALG_DH_EL_SF </td><td>Идентификатор алгоритма обмена ключей по Диффи-Хеллману на базе закрытого ключа пользователя. Открытый ключ получается по ГОСТ Р 34.10 2001.</td></tr>
 * <tr><td> CALG_DH_EL_EPHEM</td><td> Идентификатор алгоритма обмена ключей по Диффи-Хеллману на базе закрытого ключа эфемерной пары. Открытый ключ получается по ГОСТ Р 34.10 2001.</td></tr>
 * <tr><td>CALG_PRO_AGREEDKEY_DH</td><td>Идентификатор алгоритма выработки ключа парной связи по Диффи-Хеллману. </td></tr>
 * <tr><td>CALG_PRO_EXPORT </td><td> Идентификатор алгоритма защищённого экспорта ключа.</td></tr>
 * <tr><td>CALG_SIMPLE_EXPORT </td><td>Идентификатор алгоритма простого экспорта ключа. </td></tr>
 * <tr><td>CALG_SIMMETRYKEY </td><td> Идентификатор алгоритма шифрования по ГОСТ 28147-89.</td></tr>
 * <tr><td> CALG_TLS1_MASTER_HASH</td><td>Идентификатор алгоритма выработки объекта MASTER_HASH протокола TLS 1.0.</td></tr>
 * <tr><td> CALG_TLS1_MAC_KEY</td><td>Идентификатор алгоритма выработки ключа имитозащиты протокола TLS 1.0. </td></tr>
 * <tr><td>CALG_TLS1_ENC_KEY </td><td> Идентификатор алгоритма выработки ключа шифрования протокола TLS 1.0.</td></tr>
 * <tr><td> CALG_PRO_DIVERS</td><td>Идентификатор алгоритма КриптоПро диверсификации ключа.</td></tr>
 * <tr><td> CALG_RIC_DIVERS</td><td>Идентификатор алгоритма РИК диверсификации ключа. </td></tr>
 *</table>
 */

/*! \page DP2 Режимы шифрования
 * <table>
 * <tr><th>Параметр</th><th>Значение параметра</th></tr>
 * <tr><td>CRYPT_PROMIX_MODE </td><td>Задание режимов шифрования/расшифрования по ГОСТ 28147-89 с преобразованием ключа через каждые 1 КВ обрабатываемой информации </td></tr>
 * <tr><td>CRYPT_SIMPLEMIX_MODE </td><td>Задание режимов шифрования/расшифрования по ГОСТ 28147-89 без преобразования ключа в процессе обработки информации</td></tr>
 *</table>
*/

/*! \page DP3 Параметры криптопровайдера
 * <table>
 * <tr><th>Параметр</th><th>Значение параметра</th></tr>
 * <tr><td>PP_ENUMOIDS_EX</td><td>Получает перечень идентификаторов объектов, используемых в криптопровайдере</td></tr>
 * <tr><td>PP_HASHOID</td><td>Получает и/или устанавливает заданный в контейнере OID узла замены функции хэширования ГОСТ Р 34.11-94 для наследования криптографическими объектами</td></tr>
 * <tr><td>PP_CIPHEROID</td><td>Получает и/или устанавливает заданный в контейнере OID узла замены алгоритма шифрования ГОСТ 28147-89 для наследования криптографическими объектами </td></tr>
 * <tr><td>PP_SIGNATUREOID</td><td>Получает и/или устанавливает заданный в контейнере OID параметров цифровой подписи для наследования криптографическими объектами </td></tr>
 * <tr><td>PP_DHOID </td><td>Получает и/или устанавливает заданный в контейнере OID параметров алгоритма Диффи-Хеллмана для наследования криптографическими объектами  </td></tr>
 * <tr><td>PP_CHECKPUBLIC </td><td>Флаг контроля открытого ключа. Если флаг установлен, осуществляется проверка алгебраических свойств открытого ключа </td></tr>
 * <tr><td>PP_RANDOM</td><td>Получает и/или устанавливает блоб типа SIMPLEBLOB для инициализации ДСЧ в драйвере шифрования</td></tr>
 * <tr><td>PP_DRVCONTAINER </td><td>Получает указатель (handle) контейнера в драйвере</td></tr>
 * <tr><td>PP_MUTEX_ARG</td><td>Инициализирует синхронизацию потоков криптопровайдера в драйверном исполнении</td></tr>
 * <tr><td>PP_ENUM_HASHOID</td><td>Получает перечень идентификаторов криптографических объектов, связанных с функцией хэширования </td></tr>
 * <tr><td>PP_ENUM_CIPHEROID</td><td>Получает перечень идентификаторов криптографических объектов, связанных с функцией шифрования  </td></tr>
 * <tr><td>PP_ENUM_SIGNATUREOID</td><td>Получает перечень идентификаторов криптографических объектов, связанных с функцией цифровой подписи</td></tr>
 * <tr><td>PP_ENUM_DHOID</td><td>Получает перечень идентификаторов криптографических объектов, связанных с алгоритмом Диффи-Хеллмана  </td></tr>
 *</table>
*/

/*! \page DP4 Параметры дополнительных ключевых блобов
 * <table>
 * <tr><th>Параметр</th><th>Значение параметра</th></tr>
 * <tr><td>DIVERSKEYBLOB</td><td>Тип ключевого блоба для диверсификации ключей с помощью
    функции CPImportKey в режиме CALG_PRO_EXPORT</td></tr>
 *</table>
*/

/*! \page DP5 Дополнительные параметры объекта хэширования
 * <table>
 * <tr><th>Параметр</th><th>Значение параметра</th></tr>
 * <tr><td>HP_HASHSTARTVECT</td><td>Стартовый вектор функции хэширования, устанавливаемый приложением</td></tr>
 * <tr><td>HP_OID</td><td>Задает узел замены функции хэширования</td></tr>
 *</table>
*/

/*! \page DP6 Дополнительные параметры ключей
 * <table>
 * <tr><th>Параметр</th><th>Значение параметра</th></tr>
 * <tr><td>KP_IV </td><td>Начальный вектор инициализации алгоритма шифрования ГОСТ 28147-89</td></tr>
 * <tr><td>KP_MIXMODE</td><td>Определяет использование преобразования ключа после обработки 1КВ информации в режимах шифрования/расшифрования и вычисления имитовставки алгоритма ГОСТ 28147-89 </td></tr>
 * <tr><td>KP_OID</td><td>Задает узел замены функции хэширования</td></tr>
 * <tr><td>KP_HASHOID</td><td>Идентификатор узла замены функции хэширования ГОСТ Р 34.11-94</td></tr>
 * <tr><td>KP_CIPHEROID</td><td>Идентификатор узла замены алгоритма шифрования ГОСТ 28147-89</td></tr>
 * <tr><td>KP_SIGNATUREOID</td><td>Идентификатор параметров цифровой подписи</td></tr>
 * <tr><td>KP_DHOID</td><td>Идентификатор параметров алгоритма Диффи-Хеллмана</td></tr>
 *</table>
*/

/*! \page DP8 Групповые идентификаторы криптографических параметров алгоритмов
 * <table>
 * <tr><th>Параметр</th><th>Индекс</th><th>Значение параметра</th></tr>
 * <tr><td>szOID_CP_GOST_28147</td><td>"1.2.643.2.2.21"</td><td>Алгоритм шифрования ГОСТ 28147-89</td></tr>
 * <tr><td>szOID_CP_GOST_R3411</td><td>"1.2.643.2.2.9"</td><td>Функция хэширования ГОСТ Р 34.11-94</td></tr>
 * <tr><td>szOID_CP_GOST_R3410</td><td>"1.2.643.2.2.20"</td><td>Алгоритм ГОСТ Р 34.10-94, используемый при экспорте/импорте ключей</td></tr>
 * <tr><td>szOID_CP_GOST_R3410EL</td><td>"1.2.643.2.2.19"</td><td>Алгоритм ГОСТ Р 34.10-2001, используемый при экспорте/импорте ключей</td></tr>
 * <tr><td>szOID_CP_DH_EX</td><td>"1.2.643.2.2.99"</td><td>Алгоритм Диффи-Хеллмана на базе потенциальной функции</td></tr>
 * <tr><td>szOID_CP_DH_EL</td><td>"1.2.643.2.2.98"</td><td>Алгоритм Диффи-Хеллмана на базе эллиптической кривой</td></tr>
 * <tr><td>szOID_CP_GOST_R3411_R3410</td><td>"1.2.643.2.2.4"</td><td>Алгоритм цифровой подписи ГОСТ Р 34.10-94</td></tr>
 * <tr><td>szOID_CP_GOST_R3411_R3410EL</td><td>"1.2.643.2.2.3"</td><td>Алгоритм цифровой подписи ГОСТ Р 34.10-2001</td></tr>
 * <tr><td>szOID_KP_TLS_PROXY</td><td>"1.2.643.2.2.34.1"</td><td>Аудит TLS-трафика</td></tr>
 * <tr><td>szOID_KP_RA_CLIENT_AUTH</td><td>"1.2.643.2.2.34.2"</td><td>Идентификация пользователя на центре регистрации</td></tr>
 * <tr><td>szOID_KP_WEB_CONTENT_SIGNING</td><td>"1.2.643.2.2.34.3"</td><td>Подпись содержимого сервера Интернет</td></tr>
 *</table>
*/

/*! \ingroup ProCSPEx
 * \page CP_PARAM_OIDS Идентификаторы криптографических параметров алгоритмов
 * <table>
 * <tr><th>Параметр</th><th>Индекс</th><th>Значение параметра</th></tr>
 * <tr><td>szOID_GostR3411_94_TestParamSet</td><td>"1.2.643.2.2.30.0"</td><td>Тестовый узел замены</td></tr>
 * <tr><td>szOID_GostR3411_94_CryptoProParamSet</td><td>"1.2.643.2.2.30.1"</td><td>Узел замены функции хэширования по умолчанию, вариант "Верба-О"</td></tr>
 * <tr><td>szOID_GostR3411_94_CryptoPro_B_ParamSet</td><td>"1.2.643.2.2.30.2"</td><td>Узел замены функции хэширования, вариант 1</td></tr>
 * <tr><td>szOID_GostR3411_94_CryptoPro_C_ParamSet</td><td>"1.2.643.2.2.30.3"</td><td>Узел замены функции хэширования, вариант 2</td></tr>
 * <tr><td>szOID_GostR3411_94_CryptoPro_D_ParamSet</td><td>"1.2.643.2.2.30.4"</td><td>Узел замены функции хэширования, вариант 3</td></tr>
 * <tr><td>szOID_Gost28147_89_TestParamSet</td><td>"1.2.643.2.2.31.0"</td><td>Тестовый узел замены алгоритма шифрования</td></tr>
 * <tr><td>szOID_Gost28147_89_CryptoPro_A_ParamSet</td><td>"1.2.643.2.2.31.1"</td><td>Узел замены алгоритма шифрования по умолчанию, вариант "Верба-О"</td></tr>
 * <tr><td>szOID_Gost28147_89_CryptoPro_B_ParamSet</td><td>"1.2.643.2.2.31.2"</td><td>Узел замены алгоритма шифрования,вариант 1</td></tr>
 * <tr><td>szOID_Gost28147_89_CryptoPro_C_ParamSet</td><td>"1.2.643.2.2.31.3"</td><td>Узел замены алгоритма шифрования,вариант 2</td></tr>
 * <tr><td>szOID_Gost28147_89_CryptoPro_D_ParamSet</td><td>"1.2.643.2.2.31.4"</td><td>Узел замены алгоритма шифрования,вариант 3</td></tr>
 * <tr><td>szOID_Gost28147_89_CryptoPro_Oscar_1_1_ParamSet</td><td>"1.2.643.2.2.31.5" </td><td>Узел замены, вариант карты КриптоРИК</tr>
 * <tr><td>szOID_Gost28147_89_CryptoPro_Oscar_1_0_ParamSet</td><td>"1.2.643.2.2.31.6" </td><td>Узел замены, используемый при шифровании с хэшированием</td></tr>
 * <tr><td>szOID_GostR3410_94_CryptoPro_A_ParamSet</td><td>"1.2.643.2.2.32.2"</td><td>Параметры P,Q,A цифровой подписи ГОСТ Р 34.10-94, вариант "Верба-О". Могут использоваться также в алгоритме Диффи-Хеллмана</td></tr>
 * <tr><td>szOID_GostR3410_94_CryptoPro_B_ParamSet</td><td>"1.2.643.2.2.32.3"</td><td>Параметры P,Q,A цифровой подписи ГОСТ Р 34.10-94, вариант 1. Могут использоваться также в алгоритме Диффи-Хеллмана</td></tr>
 * <tr><td>szOID_GostR3410_94_CryptoPro_C_ParamSet</td><td>"1.2.643.2.2.32.4"</td><td>Параметры P,Q,A цифровой подписи ГОСТ Р 34.10-94, вариант 2. Могут использоваться также в алгоритме Диффи-Хеллмана</td></tr>
 * <tr><td>szOID_GostR3410_94_CryptoPro_D_ParamSet</td><td>"1.2.643.2.2.32.5"</td><td>Параметры P,Q,A цифровой подписи ГОСТ Р 34.10-94, вариант 3. Могут использоваться также 2 алгоритме Диффи-Хеллмана</td></tr>
 * <tr><td>szOID_GostR3410_94_CryptoPro_XchA_ParamSet</td><td>"1.2.643.2.2.33.1" </td><td>Параметры P,Q,A алгоритма Диффи-Хеллмана на базе экспоненциальной функции, вариант 1</td></tr>
 * <tr><td>szOID_GostR3410_94_CryptoPro_XchB_ParamSet</td><td>"1.2.643.2.2.33.2" </td><td>Параметры P,Q,A алгоритма Диффи-Хеллмана на базе экспоненциальной функции, вариант 2</td></tr>
 * <tr><td>szOID_GostR3410_94_CryptoPro_XchC_ParamSet</td><td>"1.2.643.2.2.33.3" </td><td>Параметры P,Q,A алгоритма Диффи-Хеллмана на базе экспоненциальной функции, вариант 3</td></tr>
 * <tr><td>szOID_GostR3410_2001_TestParamSet</td><td>"1.2.643.2.2.35.0"</td><td>Тестовые параметры a, b, p,q, (x,y) алгоритма ГОСТ Р 34.10-2001 </td></tr>
 * <tr><td>szOID_GostR3410_2001_CryptoPro_A_ParamSet</td><td>"1.2.643.2.2.35.1"</td><td>Параметры a, b, p,q, (x,y) цифровой подписи и алгоритма Диффи-Хеллмана на базе алгоритма ГОСТ Р 34.10-2001, вариант криптопровайдера </td></tr>
 * <tr><td>szOID_GostR3410_2001_CryptoPro_B_ParamSet</td><td>"1.2.643.2.2.35.2"</td><td>Параметры a, b, p,q, (x,y) цифровой подписи и алгоритма Диффи-Хеллмана на базе алгоритма ГОСТ Р 34.10-2001, вариант карты КриптоРИК</td></tr>
 * <tr><td>szOID_GostR3410_2001_CryptoPro_C_ParamSet</td><td>"1.2.643.2.2.35.2"</td><td>Параметры a, b, p,q, (x,y) цифровой подписи и алгоритма Диффи-Хеллмана на базе алгоритма ГОСТ Р 34.10-2001, вариант 1</td></tr>
 * <tr><td>szOID_GostR3410_2001_CryptoPro_XchA_ParamSet</td><td>"1.2.643.2.2.36.0"</td><td> Параметры a, b, p,q, (x,y) алгоритма Диффи-Хеллмана на базе алгоритма ГОСТ Р 34.10-2001, вариант криптопровайдера. Используются те же параметры, что и с идентификатором szOID_GostR3410_2001_CryptoPro_A_ParamSet</td></tr>
 * <tr><td>szOID_GostR3410_2001_CryptoPro_XchB_ParamSet</td><td>"1.2.643.2.2.35.3"</td><td>Параметры a, b, p,q, (x,y) цифровой подписи и алгоритма Диффи-Хеллмана на базе алгоритма ГОСТ Р 34.10-2001, вариант 1</td></tr>
 *</table>
 *
*/

/*! \} */

/*! 
 * \ingroup ProCSPData
 *
 * \brief Блоб с сериализованной псевдоструктурой с расширением.
 *
 * \req_wincryptex
 * \sa CPGetProvParam
 */
typedef struct _CONTAINER_EXTENSION {
    CSP_BOOL bCritical; /*!< Флаг критического расширения. */
    DWORD cbExtension; /*!< Длина данных в pbExtension. */
    BYTE pbExtension[1]; /*!< Данные. */
    char sOid[1]; /*!< Строка с OID-ом расширения (невыровненный указатель). */
} CONTAINER_EXTENSION;

//ошибка или недоработка в wincrypt.h
#ifdef CERT_FIND_SUBJECT_STR
#   undef CERT_FIND_SUBJECT_STR
#   undef CERT_FIND_ISSUER_STR
#   ifdef _UNICODE
#	define CERT_FIND_SUBJECT_STR	CERT_FIND_SUBJECT_STR_W
#	define CERT_FIND_ISSUER_STR	CERT_FIND_ISSUER_STR_W
#   else
#	define CERT_FIND_SUBJECT_STR	CERT_FIND_SUBJECT_STR_A
#	define CERT_FIND_ISSUER_STR	CERT_FIND_ISSUER_STR_A
#   endif // !UNICODE
#endif

#if !defined(_DDK_DRIVER_)

typedef struct _CPESS_CERT_ID {
    CRYPT_HASH_BLOB CertHash;
    CERT_ISSUER_SERIAL_NUMBER IssuerSerial;
} CPESS_CERT_ID, *PCPESS_CERT_ID;

typedef struct _CPESS_CERT_IDV2 {
    CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
    CRYPT_HASH_BLOB CertHash;
    CERT_ISSUER_SERIAL_NUMBER IssuerSerial;
} CPESS_CERT_IDV2, *PCPESS_CERT_IDV2,
  CPOTHER_CERT_ID, *PCPOTHER_CERT_ID;

typedef struct _CPCMSG_SIGNING_CERTIFICATE {
    DWORD cCert;
    CPESS_CERT_ID* rgCert;
    DWORD cPolicy;
    CERT_POLICY_INFO* rgPolicy;
} CPCMSG_SIGNING_CERTIFICATE, *PCPCMSG_SIGNING_CERTIFICATE;

typedef struct _CPCMSG_SIGNING_CERTIFICATEV2 {
    DWORD cCert;
    CPESS_CERT_IDV2* rgCert;
    DWORD cPolicy;
    CERT_POLICY_INFO* rgPolicy;
} CPCMSG_SIGNING_CERTIFICATEV2, *PCPCMSG_SIGNING_CERTIFICATEV2;

typedef struct _CPCMSG_OTHER_SIGNING_CERTIFICATE {
    DWORD cCert;
    CPOTHER_CERT_ID* rgCert;
    DWORD cPolicy;
    CERT_POLICY_INFO* rgPolicy;
} CPCMSG_OTHER_SIGNING_CERTIFICATE, *PCPCMSG_OTHER_SIGNING_CERTIFICATE; 

typedef struct _CPCERT_PRIVATEKEY_USAGE_PERIOD {
    FILETIME *pNotBefore;
    FILETIME *pNotAfter;
} CPCERT_PRIVATEKEY_USAGE_PERIOD, *PCPCERT_PRIVATEKEY_USAGE_PERIOD;
/*! \endcond */

#define CPPRIVATEKEY_USAGE_PERIOD_CERT_CHAIN_POLICY_SKIP_END_CERT_FLAG	    (0x00010000)
#define CPTIMESTAMP_SIGNING_CERT_CHAIN_POLICY_IGNORE_NOT_CRITICAL_EKU_FLAG  (0x00020000)
#define CPTIMESTAMP_SIGNING_CERT_CHAIN_POLICY_IGNORE_NOT_ONE_EKU_FLAG	    (0x00040000)

typedef struct _CPPRIVATEKEY_USAGE_PERIOD_EXTRA_CERT_CHAIN_POLICY_PARA {
    DWORD cbSize; 
    FILETIME* pPrivateKeyUsedTime; 
} CPPRIVATEKEY_USAGE_PERIOD_EXTRA_CERT_CHAIN_POLICY_PARA,
*PCPPRIVATEKEY_USAGE_PERIOD_EXTRA_CERT_CHAIN_POLICY_PARA,
CPSIGNATURE_EXTRA_CERT_CHAIN_POLICY_PARA,
*PCPSIGNATURE_EXTRA_CERT_CHAIN_POLICY_PARA,
CPTIMESTAMP_SIGNING_EXTRA_CERT_CHAIN_POLICY_PARA,
*PCPTIMESTAMP_SIGNING_EXTRA_CERT_CHAIN_POLICY_PARA;

#define CPCERT_TRUST_PRIVATE_KEY_IS_NOT_TIME_VALID	    (0x00000001)
#define CPCERT_TRUST_PRIVATE_KEY_IS_NOT_TIME_VALID_FOR_CRL  (0x00000002)
#define CPCERT_TRUST_IS_NOT_CRITICAL_EKU		    (0x00000004)
#define CPCERT_TRUST_IS_NOT_ONE_EKU			    (0x00000008)
#define CPCERT_TRUST_IS_NOT_VALID_FOR_USAGE		    (CERT_TRUST_IS_NOT_VALID_FOR_USAGE)
							 // (0x00000010)
#define CPCERT_TRUST_IS_NOT_VALID_BY_KEYUSAGE		    (0x00000020)
#define CPCERT_TRUST_IS_NOT_VALID_FOR_OCSP_SIGNING	    (0x00000040)

typedef struct _CPPRIVATEKEY_USAGE_PERIOD_EXTRA_CERT_CHAIN_POLICY_STATUS {
    DWORD cbSize; 
    DWORD dwError; 
    LONG lChainIndex; 
    LONG lElementIndex; 
} CPPRIVATEKEY_USAGE_PERIOD_EXTRA_CERT_CHAIN_POLICY_STATUS,
*PCPPRIVATEKEY_USAGE_PERIOD_EXTRA_CERT_CHAIN_POLICY_STATUS,
CPSIGNATURE_EXTRA_CERT_CHAIN_POLICY_STATUS,
*PCPSIGNATURE_EXTRA_CERT_CHAIN_POLICY_STATUS,
CPTIMESTAMP_SIGNING_EXTRA_CERT_CHAIN_POLICY_STATUS,
*PCPTIMESTAMP_SIGNING_EXTRA_CERT_CHAIN_POLICY_STATUS;

typedef struct _CPOCSP_SIGNING_EXTRA_CERT_CHAIN_POLICY_STATUS {
    DWORD cbSize;
    DWORD dwError;
    LONG lChainIndex;
    LONG lElementIndex;
    CSP_BOOL fNoCheck;
    CSP_BOOL* rgCertIdStatus;
} CPOCSP_SIGNING_EXTRA_CERT_CHAIN_POLICY_STATUS,
*PCPOCSP_SIGNING_EXTRA_CERT_CHAIN_POLICY_STATUS;

#ifndef OCSP_REQUEST_V1

typedef struct _OCSP_CERT_ID {
    CRYPT_ALGORITHM_IDENTIFIER  HashAlgorithm;  // Normally SHA1
    CRYPT_HASH_BLOB             IssuerNameHash; // Hash of encoded name
    CRYPT_HASH_BLOB             IssuerKeyHash;  // Hash of PublicKey bits
    CRYPT_INTEGER_BLOB          SerialNumber;
} OCSP_CERT_ID, *POCSP_CERT_ID;
#define OCSP_REQUEST_V1     0
#endif

typedef struct _CPOCSP_SIGNING_EXTRA_CERT_CHAIN_POLICY_PARA {
    DWORD cbSize;
    FILETIME* pPrivateKeyUsedTime;
    DWORD cCertId;
    POCSP_CERT_ID rgCertId;
} CPOCSP_SIGNING_EXTRA_CERT_CHAIN_POLICY_PARA,
*PCPOCSP_SIGNING_EXTRA_CERT_CHAIN_POLICY_PARA;
/*! \cond csp  */

#endif /*!defined(_DDK_DRIVER_)*/

#ifdef __cplusplus
}
#endif // __cplusplus

/*****************************************************
		    CRYPT_PACKET 
******************************************************/
/*! \ingroup ProCSPData
 * \defgroup CryptPacket  Шифрование и хэширование пакета
 *
 * Пакет - неделимый фрагмент данных, подаваемых на функции шифрования 
 * CPEncrypt(), CPCEncrypt(),CPDecrypt(), CPCDecrypt().
 * Пакет состоит из полей:
 * <table><tr><th>
 * Поле 
 * </th><th>
 *      Описание
 * </th></tr><tr><td>
 * Предзаголовок пакета (DIVERSBLOB)
 * </td><td>
 *      Опциональное поле, содержащее блоб диверсификации ключа шифрования и хеширования по алгоритму CALG_PRO_DIVERS.
 * </td></tr><tr><td>
 * Заголовок пакета (HEADER)
 * </td><td>
 *      Опциональное поле длины не более 255 байт. Не шифруется, хэшируется хеш-функцией hHash.
 * </td></tr><tr><td>
 * Вектор инициализации (IV)
 * </td><td>
 *      Опциональное поле, содержащее вектор инициализации шифрования пакета. Не шифруется, хэшируется опционально.
 * </td></tr><tr><td>
 * Тело пакета (PAYLOAD)
 * </td><td>
 *      Обязательное поле, шифруется и хэшируется.
 * </td></tr><tr><td>
 * Трейлер (TRAILER)
 * </td><td>
 *      Опциональное поле длины не более 254 байт. Не шифруется, хэшируется хеш-функцией hHash.
 * </td></tr><tr><td>
 * Знечение функции хэширования пакета (HASH)
 * </td><td>
 *      Опциональное поле, может быть зашифровано. 
 * </td></tr>
 * </table> 
 *
 * При шифровании пакетов поддерживаются режимы шифрования: CRYPT_MODE_CNT, CRYPT_MODE_CFB, CRYPT_MODE_CBCSTRICT.
 * Во всех режимах шифрования могут быть использованы флаги: CRYPT_PROMIX_MODE, CRYPT_SIMPLEMIX_MODE.
 *
 * В пакетном режиме шифрования длина пакетов остаётся неизменной.
 *
 * В режиме CBC общая длина шифруемых данных должна быть кратна 8, также должна быть кратной 8 длина 
 * каждого шифруемого элемента IOVEC, в противном случае возвращается ошибка NTE_BAD_DATA. 
 * Пакеты обрабатываются с сохранением размера полей, паддинг в режиме CBC игнорируется.
 *
 * Флаги CP_CHP_IV_RANDOM, CP_CHP_IV_USER, CP_CHP_HASH_PACKET предназначены для обработки 
 * пакетов в потоках с возможным нарушением порядка следования пакетов, с возможной потерей пакетов.
 *
 * Флаги CP_CHP_IV_CHAIN, CP_CHP_HASH_CHAIN, CP_CHP_HASH_NONE  предназначены для обработки пакетов в потоках,
 * гарантирующих доставку всех пакетов в неизменной последовательности.
 *
 * В следующей таблице приведены условия использовантя режимов ширования пакетов:
 * <table><tr><th>
 * Значение флагов
 * </th><th>
 *      Условия и ограничения режима
 * </th></tr><tr><td>
 * CRYPT_SIMPLEMIX_MODE совместно с CP_CHP_IV_RANDOM, 
 * CRYPT_SIMPLEMIX_MODE совместно с CP_CHP_IV_USER
 * </td><td>
 *	Обработка пакетов может выполняться с установленным флагом Final=FALSE.
 *	Объём данных, обрабатываемых на одном ключе, ограничен 4М. 
 * </td></tr><tr><td>
 * CRYPT_PROMIX_MODE совместно с CP_CHP_IV_RANDOM, 
 * CRYPT_PROMIX_MODE совместно с CP_CHP_IV_USER
 * </td><td>
 *	Обработка пакетов должна выполняться с установленным флагом Final=TRUE.
 *	Объём данных, обрабатываемых на одном ключе,  ограничен 4М либо числом пакетов < 4096.
 * </td></tr><tr><td>
 * CRYPT_SIMPLEMIX_MODE совместно с CP_CHP_IV_CHAIN
 * </td><td>
 *	Обработка пакета с флагом Final=TRUE означает завершение обработки цепочки пакетов.
 * 	Обработка пакета с флагом Final=FALSE означает продолжение обработки цепочки пакетов.
 *	На одном ключе последовательно может быть обработано несколько цепочек пакетов.
 *	Объём данных, обрабатываемых на одном ключе, ограничен 4М.
 * </td></tr><tr><td>
 * CRYPT_PROMIX_MODE совместно с CP_CHP_IV_CHAIN
 * </td><td>
 *	Обработка пакета с флагом Final=TRUE означает завершение обработки цепочки пакетов.
 * 	Обработка пакета с флагом Final=FALSE означает продолжение обработки цепочки пакетов.
 *	На одном ключе может обрабатываться цепочка длины не более 128000М. 
 *	Количество цепочек ограничено 4096.
 * </td></tr>
 * </table>
 * 
 * Во всех режимах объект функции хэширования после завершения обработки пакета 
 * подготовлен для обработки следующего пакета. 
 * При этом, в случае CP_CHP_HASH_CHAIN и CP_CHP_HASH_NONE объект открыт для продолжения хэширования потока, 
 * в случае CP_CHP_HASH_PACKET объект инициализирован.
 *
 * При расшифровании пакета в случае его искажения в канале, приводящего к несовпадению  
 * значения HASH, передаваемого в составе пакета, с вновь рассчитанным значением, функция CPDecrypt() 
 * возвращают ошибку (FALSE), функции CPCDecrypt() и CSP_GetLastError() возвращают NTE_BAD_HASH, 
 * объект функции хэширования функциями CPDecrypt(), CPCDecrypt() не инициализируется. 
 * В этом случае приложение может получить рассчитанное значение HASH
 * вызовом CPGetHashParam() и должно принять решение о завершении обрабатываемого потока
 * (например: поток, обрабатываемый с флагом CP_CHP_HASH_CHAIN, должен быть закрыт; 
 * поток, обрабатываемый с флагом CP_CHP_HASH_PACKET может быть продолжен). 
 * В случае продолжения обработки потока приложение должно открыть (создать новый) объект функции хэширования.
 *
 * Во входных параметрах функций шифрования и хэширования пакет может быть представлен как буфером, 
 * определяемым указателем pbData и длиной cbData, так и вектором IOVEC ввода/вывода, 
 * определяемым указателем pbData на вершину массива структур \ref CSP_iovec и числом элементов массива cbData.
 * Режим использования векторной формы представления ввода/вывода определяется флагом CP_CRYPT_DATA_IOVEC, 
 * в настоящей версии СКЗИ режим CP_CRYPT_DATA_IOVEC является подрежимом пакетной обработки.
 *
 *
 * Умолчания:
 *
 *   1. В случае hHash=0, значение функции хэширования не рассчитывается.
 *
 *   2.	Представление данных в виде IOVEC является производным от представления в виде флагов.
 *      Имеется ввиду, что IOVEC представляет данные, а описание семантики данных содержится во флагах.
 *
 *   3.	Максимальное количество элементов IOVEC зависит от реализации. 
 * Любая реализация должна предоставлять возможность использовать 16 элементов IOVEC.
 *
 *   4. Поле длины элемента IOVEC >= 0.
 *
 *
 * Структура пакета и порядок обработки полей пакета определяются 
 * значениями флагов параметра dwFlags, 
 * объединяемыми операцией OR; значения флагов зависимы, не все 
 * сочетания значений полей допустимы. Для формирования флагов 
 * рекомендуется использовать макрос CP_CHP().
 *
 * \sa #CPEncrypt (CP_CRYPT_HASH_PACKET)
 * \sa #CPDecrypt (CP_CRYPT_HASH_PACKET)
 * \sa #CP_CHP()
 * \{
 */

/*!
 *  \brief Флаг - признак пакетной обработки данных, должен быть установлен, если используется обработка пакета,
 *  в противном случае dwFlags долен быть равен нулю, что соответствут обработке простого потока данных. 
 */
#define CP_CRYPT_HASH_PACKET		(0x80)
/*!
 *  \brief Флаг определяет порядок обработки данных пакета - хэширование (имитозащита) затем шифрование.
 */
#define CP_CHP_HASH_ENCRYPT		(0x00)
/*!
 *  \brief Флаг определяет порядок обработки данных пакета - шифрование затем хэширование (имитозащита).
 */
#define CP_CHP_ENCRYPT_HASH		(0x10)
/*!
 *  \brief Флаг хэширования вектора инициализации (IV). Если установлен, IV следует за заголовком пакета и хэшируется. 
 *	 Если не установлен, IV ,если присутствует в пакете, следует за заголовком пакета, но не хэшируется.
 */
#define CP_CHP_IV_HEADER		(0x08)
/*!
 *  \brief Флаг диверсификации ключа шифрования и хеширования по алгоритму CALG_PRO_DIVERS. 
 *  Если используется представление данных в форме пакета, блоб диверсификации должен передавться 
 *  в составе пакета в его нечале.
 *  Если используется представление данных в форме вектора ввода-вывода, 
 *  блоб диверсификации должен передаваться в первой координате вектора целиком.
 */
#define CP_CHP_STARTMIX			(0x04)
/*!
 *  \brief Маска управления IV. Представляет собой поле из 2 зависимых бит. 
 *  Нулевое значение поля соответствует CP_CHP_IV_CHAIN.
 *  Ненулевые значения соответствуют CP_CHP_IV_USER, CP_CHP_IV_RANDOM.
 *  Может быть установлен только один из флагов CP_CHP_IV_CHAIN, CP_CHP_IV_USER, CP_CHP_IV_RANDOM.
 */
#define CP_CHP_IV_MASK			(0x300) 
/*!
 *  \brief  Если флаг установлен, IV генерируется функцией CPEncrypt(...,CP_CRYPT_HASH_PACKET|CP_CHP_IV_CHAIN...,...) 
 *  (CPCEncrypt()) и передаётся в пакет. Функция CPDecrypt(...,CP_CRYPT_HASH_PACKET|CP_CHP_IV_CHAIN...,...) (CPCEncrypt())
 *  считывает IV из пакета. 
 */
#define CP_CHP_IV_RANDOM		(0x100)
/*!
 *  \brief  Если флаг установлен, приложение устанавлиает IV в пакет, 
 *  функции CPEncrypt(...,CP_CRYPT_HASH_PACKET|CP_CHP_IV_CHAIN...,...) (CPCEncrypt()), 
 *  CPDecrypt(...,CP_CRYPT_HASH_PACKET|CP_CHP_IV_CHAIN...,...) (CPCEncrypt()) считывают IV из пакета. 
 */
#define CP_CHP_IV_USER			(0x200)
/*!
 *  \brief  Если флаг установлен, функциии CPEncrypt(...,CP_CRYPT_HASH_PACKET|CP_CHP_IV_CHAIN...,...) (CPCEncrypt()), 
 *  CPDecrypt(...,CP_CRYPT_HASH_PACKET|CP_CHP_IV_CHAIN...,...) (CPCDecrypt()) получают IV пакета из контекста ключа.
 */
#define CP_CHP_IV_CHAIN			(0x000)
/*!
 *  \brief Маска управления значением хеш-функции пакета. Представляет собой поле из 2 зависимых бит. 
 *  Нулевое значение поля соответствует CP_CHP_HASH_NONE.
 *  Ненулевые значения соответствуют CP_CHP_HASH_CHAIN, CP_CHP_HASH_PACKET.
 *  Может быть установлен только один из флагов CP_CHP_HASH_NONE, CP_CHP_HASH_CHAIN, CP_CHP_HASH_PACKET.
 */
 #define CP_CHP_HASH_MASK		(0xC00)
/*!
 *  \brief  Если флаг установлен, функция хэширования расчитывается на весь поток пакетов. 
 *  В пакет значение хеш-функции не передаётся.
 */
#define CP_CHP_HASH_NONE		(0x000)
/*!
 *  \brief  Если флаг установлен, функция хэширования расчитывается на поток пакетов, 
 *  текущее значение хеш-функции устанавливается в пакет функциями 
 *  CPEncrypt(...,CP_CRYPT_HASH_PACKET|CP_CHP_HASH_CHAIN...,...) (CPCEncrypt()).
 *  Функции CPDecrypt(...,CP_CRYPT_HASH_PACKET|CP_CHP_IV_CHAIN...,...) (CPCDecrypt()) сравнивают
 *  расчитанное значение хеш-функции со значением, полученным из пакета,
 *  и в случае несравнения возвращают ошибку NTE_BAD_HASH.
 */
#define CP_CHP_HASH_CHAIN		(0x400)
/*!
 *  \brief  Если флаг установлен, функция хэширования расчитывается на пакет, 
 *  значение хеш-функции устанавливается в пакет функциями 
 *  CPEncrypt(...,CP_CRYPT_HASH_PACKET|CP_CHP_HASH_CHAIN...,...) (CPCEncrypt()).
 *  Функции CPDecrypt(...,CP_CRYPT_HASH_PACKET|CP_CHP_IV_CHAIN...,...) (CPCDecrypt()) сравнивают
 *  расчитанное значение хеш-функции со значением, полученным из пакета,
 *  и в случае несравнения возвращают ошибку NTE_BAD_HASH.
 */
#define CP_CHP_HASH_PACKET		(0x800)
/*!
 *  \brief Маска размера значения хеш-функции в двойных словах (4 октета), устанавливаемого в пакет.
 *  Возможные значения: 1 (для имитозащиты) от 1 до 8 (ддя хеш-функции по ГОСТ Р34.11-94 и HMAC).
 */
#define CP_CHP_HASH_SIZE_MASK		(0xF000)
/*!
 *  \brief Маска размера трейлера в байтах, значения 0 - 254 означают длину трейлера, 
 *  значение  255 означает: длина трейлера 0, значения хеш-функции в пакете шифруется.
 */
#define CP_CHP_TRAILER_MASK		(0xFF0000)

/*!
 *  \brief Маска размера заголовка в байтах, размер может проинимать значения 0 - 255. 
 */
#define CP_CHP_HEADER_MASK		(0xFF000000)

/*! \brief Макрос для формирования параметра dwFlags (флагов) функций
 *  CPEncrypt() и CPDecrypt()
 *
 *  Флаги (dwFlags) формируются на основе параметров пакета:
 *  - флагов порядка вычисления хэш-функции и выработки синхропосылки;
 *  - размера заголовка;
 *  - размера "хвоста";
 *  - размера значения хэш-функции.
 */
#define CP_CHP(Flags,HeaderByteSize,TrailerByteSize,HashDWordSize) (\
            (Flags)|CP_CRYPT_HASH_PACKET|\
            (((HeaderByteSize)<<CP_CHP_HEADER_SHIFT)&CP_CHP_HEADER_MASK)|\
            (((TrailerByteSize)<<CP_CHP_TRAILER_SHIFT)&CP_CHP_TRAILER_MASK)|\
            (((HashDWordSize)<<CP_CHP_HASH_SIZE_SHIFT)&CP_CHP_HASH_SIZE_MASK)\
        )
/*! \} */

/*! \ingroup ProCSPData
 * \defgroup PacketMacros Вспомогательные макросы описания структуры пакета
 *
 *  В макросах приняты обозначения параметров:
 *  - параметр f сответствует dwFlags;
 *  - параметр d сответствует указателю на буфер, содержащий пакет;
 *  - параметр l сответствует длине пакета.
 *
 * \{
 */

/*!
 *  \brief Сдвиг поля для маски CP_CHP_HASH_SIZE_MASK. 
 */
#define CP_CHP_HASH_SIZE_SHIFT		(12)
/*!
 *  \brief Сдвиг поля для маски CP_CHP_TRAILER_MASK. 
 */
#define CP_CHP_TRAILER_SHIFT		(16)
/*!
 *  \brief Сдвиг поля для маски CP_CHP_HEADER_MASK. 
 */
#define CP_CHP_HEADER_SHIFT		(24)
/* 
    Aplication Packet (A-Packet, А-пакет)
    Структура Ф-пакета
    IV
    IV присутствует в А-пакете только тогда, когда он необходим для шифрования,
    т.е. IV типа RANDOM или USER присутствуют в А-пакете.
    Если CP_CHP_IV_HEADER установлен, IV входит в состав хидера и только в этом случае IV хэшируется.
    Если CP_CHP_IV_HEADER не установлен, IV не входит в состав хидера и должен присутствовать в А-пакете.
    IV типа RANDOM устанавливается в А-пакет и считывается из него функциями Encrypt()/Decrypt().
    IV типа USER устанавливается в А-пакет приложением, считывается из него функциями Encrypt()/Decrypt().
    IV типа CHAIN устанавливается приложением на ключ функцией SetKeyParam(...,KP_IV,...), 
    в А-пакет IV типа CHAIN не входит.

*/
/*!
 *  \brief Размер поля IV в пакете. 
 */
#define CP_CHP_IV_SIZE(f) (((f)&CP_CHP_IV_MASK)?(SEANCE_VECTOR_LEN):(0))

/*internal
 *  \brief Сумма указателя со смещением.
 *      p - указатель
 *      w - смещение
 */
#define _CP_CHP_ADD_(p,w) \
	    ((void *)(((char *)p) + (w)))
#define _CP_CHP_SUB_(p,w) \
	    ((void *)(((char *)p) - (w)))


/*internal
 *  \brief Проверка границ буфера.
 *	d - указатель на буфер
 *      l - длина буфера
 *      p - результирующий указатель на поле пакета
 *      w - длина поля
 */
#define _CP_CHP_SAFE_CHECK_(d,l,p,w)					\
	    (NULL != (d) && (size_t)(w) <= (size_t)(l) &&		\
	     (void *)(d) <= (void *)(p) &&					\
	     _CP_CHP_ADD_((p),(w)) <= _CP_CHP_ADD_((d),(l))		\
		? (p)							\
		: NULL							\
	    )

/*!
 *  \brief Указатель на поле IV в пакете. 
 */
#define CP_CHP_IV_DATA(f,d,l) _CP_CHP_SAFE_CHECK_((d),(l),		\
		_CP_CHP_ADD_((d),					\
		    (((f)&CP_CHP_HEADER_MASK)>>CP_CHP_HEADER_SHIFT)),	\
		CP_CHP_IV_SIZE(f)					\
	    )

/*  
    HEADER
    В размер хидера включён IV и хэшируются хидер и IV.
    Таким образом всегда выполняется 
    HashData(...,CP_CHP_HEADER_DATA(dwFlags,pbData,dwDataLen),CP_CHP_HEADER_SIZE(dwFlags));
*/
/*!
 *  \brief Указатель на поле заголовка в пакете, если заголовок присутствует. 
 */
#define CP_CHP_HEADER_DATA(f,d,l) _CP_CHP_SAFE_CHECK_((d),(l),		\
					(d), CP_CHP_PUREHEADER_SIZE(f))
/*!
 *  \brief Размер поля заголовка пакета. 
 */
#define CP_CHP_PUREHEADER_SIZE(f)					\
			(((f)&CP_CHP_HEADER_MASK)>>CP_CHP_HEADER_SHIFT)
/*!
 *  \brief Размер хэшируемого поля заголовка пакета и поля IV (если IV хэшируется). 
 */
#define CP_CHP_HEADER_SIZE(f)	    (CP_CHP_PUREHEADER_SIZE(f) +	\
					(((f)&CP_CHP_IV_HEADER)		\
					? CP_CHP_IV_SIZE(f)		\
					: 0))

/*!
 *  \brief Суммарный размер поля заголовка пакета и поля IV. 
 */
#define CP_CHP_REALHEADER_SIZE(f)   (CP_CHP_PUREHEADER_SIZE(f) +		\
					CP_CHP_IV_SIZE(f))
/*  
    HASH
    Значение Хеша присутствует в А-пакете только для типов CHAIN и PACKET.
    Для хеша типа PACKET либо CHAIN функция Encrypt() вычисляет и устанавливает значение хеша в пакет, 
    функция Decrypt() вычисляет значение хеша и сравнивает его со значением из пакета, 
    в случае несравнения возвращается ошибка NTE_BAD_HASH (CRYPT_E_HASH_VALUE). 
    Приложение само может получить значение хеша на приёме вызовом функции GetHashParam(...,HP_HASHVAL,...).
    Хеш типа NONE обрабатывается приложением, его значение в А-пакетне помещается.
    Значение хеша будет зашифрованно, еслли поле CP_CHP_TRAILER_MASK установлено в 0xff.
*/

/*!
 *  \brief Размер поля значения хеш-функции. 
 */
#define CP_CHP_HASH_SIZE(f)						\
		(sizeof(DWORD)*						\
		    (((f)&CP_CHP_HASH_MASK)				\
		    ?((f&CP_CHP_HASH_SIZE_MASK)>>CP_CHP_HASH_SIZE_SHIFT)\
		    :0))
/*!
 *  \brief Указатель на поле значения хеш-функции в пакете, если поле присутствует. 
 */
#define CP_CHP_HASH_DATA(f,d,l)	_CP_CHP_SAFE_CHECK_((d),(l),		\
		_CP_CHP_ADD_((d), (l)-CP_CHP_HASH_SIZE(f)),		\
		CP_CHP_HASH_SIZE(f)					\
	    )

/*!
 *  \brief Длина хэшируемого поля пакета(в случае, когда поле IV хэшируется). 
 */
#define CP_CHP_HASH_LEN(f,l) (l-CP_CHP_HASH_SIZE(f))
/*!
 *  \brief Длина первого хэшируемого поля (в случае, когда поле IV не хэшируется). 
 */
#define CP_CHP_HASH_LEN_1(f)  CP_CHP_PUREHEADER_SIZE(f)


/*!
 *  \brief Размер поля трейлера. 
 */
#define CP_CHP_TRAILER_SIZE(f)						\
		    ((((f)&CP_CHP_TRAILER_MASK)==CP_CHP_TRAILER_MASK)	\
		    ?(0)						\
		    :(((f)&CP_CHP_TRAILER_MASK)>>CP_CHP_TRAILER_SHIFT))	\
/*!
 *  \brief Указатель на поле трейлера в пакете, если поле присутствует. 
 */
#define CP_CHP_TRAILER_DATA(f,d,l)  _CP_CHP_SAFE_CHECK_((d),(l),	\
		_CP_CHP_SUB_(CP_CHP_HASH_DATA((f),(d),(l)),		\
					CP_CHP_TRAILER_SIZE(f)),	\
		CP_CHP_TRAILER_SIZE(f)					\
	    )

/*!
 *  \brief Размер тела пакета. 
 */
#define CP_CHP_PAYLOAD_SIZE(f,l) ((l) -					\
				    CP_CHP_REALHEADER_SIZE(f) -		\
				    CP_CHP_TRAILER_SIZE(f) -		\
				    CP_CHP_HASH_SIZE(f))

/*!
 *  \brief Размер шифруемого поля пакета. 
 */
#define CP_CHP_CIPHER_SIZE(f,l) (					\
		(l) -							\
		CP_CHP_REALHEADER_SIZE(f) -				\
		CP_CHP_TRAILER_SIZE(f) -				\
		((((f)&CP_CHP_TRAILER_MASK)==CP_CHP_TRAILER_MASK)	\
		    ?(0)						\
		    :(CP_CHP_HASH_SIZE(f)))				\
	    )
/*!
 *  \brief Указатель на шифруемое поле пакета. 
 */
#define CP_CHP_CIPHER_DATA(f,d,l)   _CP_CHP_SAFE_CHECK_((d),(l),	\
		_CP_CHP_ADD_((d), CP_CHP_REALHEADER_SIZE(f)),		\
		CP_CHP_CIPHER_SIZE(f,l)					\
	    )

/*!
 *  \brief Указатель на второе хэшируемое поле пакета (в случае, когда поле IV не хэшируется). 
 */
#define CP_CHP_HASH_DATA_2(f,d,l)   CP_CHP_CIPHER_DATA((f),(d),(l))

/*!
 *  \brief Длина второго хэшируемого поля пакета (в случае, когда поле IV не хэшируется). 
 */
#define CP_CHP_HASH_LEN_2(f,l)  (					\
		CP_CHP_CIPHER_SIZE(f,l) + CP_CHP_TRAILER_SIZE(f) -	\
		((((f)&CP_CHP_TRAILER_MASK)==CP_CHP_TRAILER_MASK)	\
		    ?(CP_CHP_HASH_SIZE(f))				\
		    :(0))						\
	    )

/*! \} */


/*! \ingroup ProCSPData
 * \defgroup CryptIOvec  Вектор ввода вывода
 *
 * Входные (и выходные) данные функций шифрования CPEncrypt(), 
 * CPCEncrypt(), CPDecrypt(), CPCDecrypt(),
 * если в параметре dwFlags устаны флаги CP_CRYPT_HASH_PACKET и 
 * CP_CRYPT_DATA_IOVEC,
 * а также входные данные функций хэширования CPHashData() и 
 * CPCHashData(),
 * если в параметре dwFlags устан флаг CP_HASH_DATA_IOVEC, могут быть 
 * представлены в форме вектора ввода вывода. 
 * В этом случае данные представляются массивом структур #CSP_iovec.
 * Последовательность структур в массиве должна соответствовать 
 * последовательности фрагментов данных в пакете.
 * 
 */

#if !defined(UNIX)
    ///*
    // * WinSock 2 extension -- WSABUF and QOS struct, include qos.h
    // * to pull in FLOWSPEC and related definitions
    // */
    //
    //typedef struct _WSABUF {
    //    u_long      len;     /* the length of the buffer */
    //    char FAR *  buf;     /* the pointer to the buffer */
    //} WSABUF, FAR * LPWSABUF;
    //
    //Проект транспорта в IDL (из C:\WINDDK\6001.18001\inc\api\ws2def.h)
    //typedef struct _WSABUF {
    //	ULONG len;     /* the length of the buffer */
    //	__field_bcount(len) CHAR FAR *buf; /* the pointer to the buffer */
    //} WSABUF, FAR * LPWSABUF;
    
    #ifndef RPC_CSP_iovec
    #define RPC_CSP_iovec

	//typedef struct _WSABUF {
	//	ULONG len;     /* the length of the buffer */
	//	[size_is (len)] CHAR FAR *buf; /* the pointer to the buffer */
	//} WSABUF, FAR * LPWSABUF;

	typedef CHAR *CSPiov_ptr_type;
	typedef ULONG CSPiov_len_type;

	#if !defined(CP_IOVEC_USE_SYSTEM) || defined(DOCUMENTATION_ONLY)
		// TODO: Ещё раз проверить, быть может, можно всегда 
		// использовать системные стуктуры
	    /*! \ingroup CryptIOvec
	    *
	    * \brief Cтруктура определяет представление фрагмента данных 
	    *	      во внешнем интерфейсе.
	    *
	    * \note На уровне приложений пользователя во всех Windows CSP_iovec 
	    * является макросом для WSABUF, 
	    * поэтому для использования CSP_iovec требуется 
	    * "#include <Winsock2.h>".
	    *
	    * \note На уровне приложений пользователя в POSIX 
	    * (Linux/Solaris/AIX/FreeBSD) системах CSP_iovec является макросом 
	    * для struct iovec, поэтому для использования CSP_iovec требуется 
	    * "#include <sys/uio.h>".
	    */
	    typedef struct CSP_iovec_ {
		CSPiov_len_type CSPiov_len; /*!< Длина фрагмента данных в байтах. */
		CSPiov_ptr_type CSPiov_ptr; /*!< Указатель на фрагмент данных. */
	    } CSP_iovec;
	#endif
	#if !defined(CSP_LITE) && !defined(CP_IOVEC_USE_SYSTEM)
		// На уровне приложений используем структуру ОС
		// Однако, представляется желательным, совпадение 
		// представлений стуктур ядра и пользователя
	    #define CSP_iovec	    WSABUF
	    #define CSPiov_len	    len
	    #define CSPiov_ptr	    buf
	#endif 

	/*! \ingroup CryptIOvec
	 *
	 * \brief Максимально допустимое число фрагментов в 
	 *        представлении пакета вектором ввода вывода.
	 * 
	 */
	#define CSP_UIO_MAXIOV 		(1024-16)

	/*! \ingroup CryptIOvec
	 *
	 * \brief Максимально допустимое число фрагментов при 
	 *        использовании библиотеки уровня ядра или в 
	 *        адресном пространстве пользователя.
	 * 
	 */
    	#define CSP_KERNEL_UIO_MAXIOV	(1024-16)

    #endif /* RPC_CSP_iovec */
#else
    // Gnu lib
    //   #define UIO_MAXIOV      1024
    //                                                                               
    //   /* Structure for scatter/gather I/O.  */
    //   struct iovec
    //     {
    //        void *iov_base;     /* Pointer to data.  */
    //        size_t iov_len;     /* Length of data.  */                                    };
    //     };

    #if defined(SOLARIS) && !defined(_XPG4_2) && !defined(CSP_LITE)
        #include <sys/types.h>
    	typedef caddr_t CSPiov_ptr_type;
	#if defined(_LP64)
	    typedef size_t CSPiov_len_type;
	#else
	    typedef long CSPiov_len_type;
	#endif
    #else
	typedef void* CSPiov_ptr_type;
	typedef size_t CSPiov_len_type;
    #endif

    #if !defined(CP_IOVEC_USE_SYSTEM) || defined(DOCUMENTATION_ONLY)
	    // TODO: Ещё раз проверить, быть может, можно всегда 
	    // использовать системные стуктуры
	typedef struct CSP_iovec_ {
	    CSPiov_ptr_type CSPiov_ptr; /*!<Указатель на фрагмент данных.*/
	    CSPiov_len_type CSPiov_len; /*!<Длина фрагмента данных в байтах.*/
	} CSP_iovec;
    #endif
    #if !defined(CSP_LITE) && !defined(CP_IOVEC_USE_SYSTEM)
	    // На уровне приложений используем структуру ОС для 
	    // упрощения взаимодействия с подсистемой В/В ОС.
	    // Однако, представляется желательным, совпадение 
	    // представлений стуктур ядра и пользователя для целей
	    // более адекватного тестирования "ядерного" кода в режиме пользователя.
	#define CSP_iovec	    struct iovec
	#define CSPiov_ptr	    iov_base
	#define CSPiov_len	    iov_len
    #endif 

    #define CSP_UIO_MAXIOV 		(IOV_MAX-2)
    #define CSP_KERNEL_UIO_MAXIOV	(1024-16)
#endif

/*! \ingroup CryptIOvec
 *
 * \brief Значение не инициализированного поля длины.
 * 
 */
#define CSP_UIOV_MAXBAD_LEN ((CSPiov_len_type)0x7fffFFFF)

/*! \ingroup CryptIOvec
 *
 * \brief Макрос возвращает указатель на фрагмент данных с номером n в векторе ввода вывода.
 *
 * Параметры:
 * - p - указатель на первый элемент в массиве структур CSP_iovec;
 * - n - номер структуры в векторе ввода вывода.
 */
#define IOVEC_PTR(p,n) (((CSP_iovec*)p)[n].CSPiov_ptr)
/*! \ingroup CryptIOvec
 *
 * \brief Макрос возвращает длину фрагмента данных с номером n в векторе ввода вывода.
 *
 * Параметры:
 * - p - указатель на первый элемент в массиве структур CSP_iovec;
 * - n - номер структуры в векторе ввода вывода.
 */
#define IOVEC_LEN(p,n) (((CSP_iovec*)p)[n].CSPiov_len)
/*! \ingroup CryptIOvec
 *
 *  \brief Флаг - признак представления пакета в форме вектора ввода/вывода. 
 *  Для функций CPEncrypt(), CPCEncrypt(),CPDecrypt(), CPCDecrypt() флаг
 *  должен быть установлен, если используется представление пакета в форме вектора ввода/вывода,
 *  в противном случае пакет представляется буфером. См. \ref CryptPacket
 */
#define CP_CRYPT_DATA_IOVEC		(0x2)
/*! \ingroup CryptIOvec
 *
 *  \brief Флаг параметра dwFlags - признак представления данных в форме вектора ввода/вывода 
 *  для функций CPHashData() и CPCHashData(). Должен быть установлен, если используется 
 *  представление данных в форме вектора ввода/вывода, в противном случае данные представляются буфером. 
 */
#define CP_HASH_DATA_IOVEC		CP_CRYPT_DATA_IOVEC

#endif /* _WINCRYPTEX_H_INCLUDED */
/** \endcond */

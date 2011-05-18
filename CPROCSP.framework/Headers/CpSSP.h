
#ifndef _CP_SSP_
#define _CP_SSP_

#include<CPROCSP/reader/support.h>
#include<CPROCSP/wincspc.h>
#include<CPROCSP/asn1type.h>
#include<CPROCSP/cryptmem.h>

#include<CPROCSP/SSPMap.h>

//нет кучи функций runtime - а тама есть
#ifdef UNDER_CE
#include<CPROCSP/wceaddon.h>
#endif

#define CPSSP_PACKAGE_COUNT			1

#define CPSSP_PACKAGE_VERSION		1

#define CPSSP_PACKAGE_NAME_A			"CryptoPro SSP"
#define CPSSP_PACKAGE_NAME_W			L"CryptoPro SSP"

#define CPSSP_PACKAGE_COMMENT_A		"CryptoPro Security Package"
#define CPSSP_PACKAGE_COMMENT_W		L"CryptoPro Security Package"

#define SCHANNEL_SPLIT_BY_MESSAGES		0x100

#define SSL3_SSL_SESSION_ID_LENGTH		32
#define SSL3_MAX_SSL_SESSION_ID_LENGTH		32

#define SSL3_MASTER_SECRET_SIZE			48
#define SSL3_RANDOM_SIZE			32
#define SSL3_SESSION_ID_SIZE			32
#define SSL3_RT_HEADER_LENGTH			5

#define SSL3_RT_MAX_EXTRA			(16384)

#define SSL3_RT_MAX_PLAIN_LENGTH		16384
#define SSL3_RT_MAX_COMPRESSED_LENGTH	(1024+SSL3_RT_MAX_PLAIN_LENGTH)
#define SSL3_RT_MAX_ENCRYPTED_LENGTH	(1024+SSL3_RT_MAX_COMPRESSED_LENGTH)
#define SSL3_RT_MAX_PACKET_SIZE		(SSL3_RT_MAX_ENCRYPTED_LENGTH+SSL3_RT_HEADER_LENGTH)
#define SSL3_RT_MAX_DATA_SIZE			(1024*1024)

#define SSL_MAX_MASTER_KEY_LENGTH		48

#define SSL3_ST_CR_CLNT_HELLO   100
#define SSL3_ST_CW_CLNT_HELLO	1
#define SSL3_ST_CR_SRVR_HELLO	2
#define SSL3_ST_CR_CERT		3
#define SSL3_ST_CR_CERT_REQ	32
#define SSL3_ST_CR_SRVR_DONE	33
#define SSL3_ST_CR_OCSP		34
#define SSL3_ST_CW_KEY_EXCH	4
#define SSL3_ST_CW_CHANGE	5
#define SSL3_ST_CW_FINISHED	6
#define SSL3_ST_CR_FINISHED	7
#define SSL3_ST_CR_HELLO_REQ	8

#define SSL_ST_RENEGOTIATE	10
#define SSL3_ST_SR_MS_SGC	11
#define SSL3_ST_SW_HELLO_REQ	12

#define SSL3_ST_SR_CLNT_HELLO	20
#define SSL3_ST_SW_SRVR_HELLO	21
#define SSL3_ST_SW_CERT		22
#define SSL3_ST_SW_OCSP		220
#define SSL3_ST_SR_CERT		232
#define SSL3_ST_SR_KEY_EXCH	23
#define SSL3_ST_SR_CERT_VRFY    231
#define SSL3_ST_SR_FINISHED	24
#define SSL3_ST_SW_CHANGE	25
#define SSL3_ST_SW_FINISHED	26

#define SSL3_ST_NORMAL		0xFF

#define SSL2_MT_CLIENT_HELLO		1

#define SSL3_MT_HELLO_REQUEST			0
#define SSL3_MT_CLIENT_HELLO			1
#define SSL3_MT_SERVER_HELLO			2
#define SSL3_MT_CERTIFICATE			11
//#define SSL3_MT_SERVER_KEY_EXCHANGE		12
#define SSL3_MT_CERTIFICATE_REQUEST		13
#define SSL3_MT_SERVER_DONE			14
#define SSL3_MT_CERTIFICATE_VERIFY		15
#define SSL3_MT_CLIENT_KEY_EXCHANGE		16
#define SSL3_MT_FINISHED			20
#define SSL3_MT_CERTIFICATE_STATUS		22

#define SSL3_MT_CCS				1

#define SSL3_MD_CLIENT_FINISHED_CONST	"\x43\x4C\x4E\x54"
#define SSL3_MD_SERVER_FINISHED_CONST	"\x53\x52\x56\x52"

#define TLS1_VERSION			0x0301
#define TLS1_VERSION_MAJOR		0x03
#define TLS1_VERSION_MINOR		0x01

#define TLS_MD_MAX_CONST_SIZE			20
#define TLS_MD_CLIENT_FINISH_CONST		"client finished"
#define TLS_MD_CLIENT_FINISH_CONST_SIZE		15
#define TLS_MD_SERVER_FINISH_CONST		"server finished"
#define TLS_MD_SERVER_FINISH_CONST_SIZE		15
#define TLS_MD_SERVER_WRITE_KEY_CONST		"server write key"
#define TLS_MD_SERVER_WRITE_KEY_CONST_SIZE	16
#define TLS_MD_KEY_EXPANSION_CONST		"key expansion"
#define TLS_MD_KEY_EXPANSION_CONST_SIZE		13
#define TLS_MD_CLIENT_WRITE_KEY_CONST		"client write key"
#define TLS_MD_CLIENT_WRITE_KEY_CONST_SIZE	16
#define TLS_MD_SERVER_WRITE_KEY_CONST		"server write key"
#define TLS_MD_SERVER_WRITE_KEY_CONST_SIZE	16
#define TLS_MD_IV_BLOCK_CONST			"IV block"
#define TLS_MD_IV_BLOCK_CONST_SIZE		8
#define TLS_MD_MASTER_SECRET_CONST		"master secret"
#define TLS_MD_MASTER_SECRET_CONST_SIZE		13

#define TLS_FINISH_MD_SIZE			12

#define SSL3_AL_WARNING			1
#define SSL3_AL_FATAL			2

#define SSL3_AD_CLOSE_NOTIFY		 0
#define SSL3_AD_UNEXPECTED_MESSAGE	10	/* fatal */
#define SSL3_AD_BAD_RECORD_MAC		20	/* fatal */
#define SSL3_AD_DECOMPRESSION_FAILURE	30	/* fatal */
#define SSL3_AD_HANDSHAKE_FAILURE	40	/* fatal */
#define SSL3_AD_NO_CERTIFICATE		41
#define SSL3_AD_BAD_CERTIFICATE		42
#define SSL3_AD_UNSUPPORTED_CERTIFICATE	43
#define SSL3_AD_CERTIFICATE_REVOKED	44
#define SSL3_AD_CERTIFICATE_EXPIRED	45
#define SSL3_AD_CERTIFICATE_UNKNOWN	46
#define SSL3_AD_ILLEGAL_PARAMETER	47	/* fatal */

#define SSL_SENT_SHUTDOWN	1
#define SSL_RECEIVED_SHUTDOWN	2
#define SSL_WANT_SHUTDOWN	4

#define SSL3_CK_GVO_COMPAT			0x0021
#define SSL3_CK_GVO				0x0031
#define SSL3_CK_GVO_KB2				0x0032

#define	SSL3_CT_GVO_SIGN			21
#define	SSL3_CT_GVO_SIGN_EL			22

#define	TLS_CIPHER_94	    			0x0080
#define	TLS_CIPHER_2001				0x0081
#define TLS_CIPHER_SCSV				0x00FF

#define TLS_CIPHER_94_SUITE_NAME	L"TLS_GOST_R_3410_94_WITH_28147_CNT_IMIT"
#define TLS_CIPHER_2001_SUITE_NAME	L"TLS_GOST_R_3410_01_WITH_28147_CNT_IMIT"
#define TLS_LEGACY_SUITE_NAME		L"TLS_GOST_R_3410_WITH_28147_LEGACY"

#define ALG_TYPE_CIPHER_SUITE                   (15 << 9)

#define SECPKG_ATTR_PATCH_CRED_HANDLE	    0x99
#define SECPKG_ATTR_WSTRUST_GENKEY	    0x98
#define SECPKG_ATTR_WSTRUST_DECRYPTKEY	    0x97

/* extension types */

#define TLS_EXT_SERVER_NAME		0
#define TLS_EXT_STATUS_REQUEST		5
#define TLS_EXT_HASH_AND_MAC_ALG_SELECT 0xfdE8
#define TLS_EXT_RENEGOTIATION_INFO	0xff01

typedef struct _SecPkgContext_WSTrustKey
{
    HCRYPTPROV	hCryptProv;
    HCRYPTKEY	hCryptKey;
    unsigned long WrappedKeyLength;
    /*__field_bcount(WrappedKeyLength)*/ unsigned char * WrappedKey;
} SecPkgContext_WSTrustKey, * PSecPkgContext_WSTrustKey;

typedef struct _CPSSP_CREDS_FLAGS_ {
    unsigned int Server:1;
    unsigned int Client:1;
    unsigned int Bad:1;
} CPSSP_CREDS_FLAGS, *PCPSSP_CREDS_FLAGS;

typedef struct _CPSSP_SESSION_ *PCPSSP_SESSION;

typedef struct _CPSSP_CREDS_ *PCPSSP_CREDS;

#ifdef _CP_SSP_AP_
typedef struct _CRYPT_USER_DATA{
    PCCERT_CONTEXT  pCertContext;
    HCRYPTPROV	    hCryptProv;
    CSP_BOOL	    bRelease;
}CRYPT_USER_DATA, *PCRYPT_USER_DATA;

typedef struct _ClientCertPolicy
{
    DWORD	    dwFlags;
    GUID	    guidPolicyId;
    DWORD	    dwCertFlags;
    DWORD	    dwUrlRetrievalTimeout;
    CSP_BOOL	    fCheckRevocationFreshnessTime;
    DWORD	    dwRevocationFreshnessTime;
    CSP_BOOL	    fOmitUsageCheck;
    PCCTL_CONTEXT    pCTLContext;
} ClientCertPolicy, *PClientCertPolicy;
#endif 

    // Для CSPNEW-887 используем предварительно мультиплицированные 
    // удостоверения 
    // Префикс: SC_  - внешнее представление в виде одного внешнего 
    //		       удостоверения;
    // Префикс: NSC_ - представление одиночной компоненты удостоверения;
    //
    // (после обеспечения масштабирования CSP на операциях 
    // CryptDecryptMessage в одном контексте, см. CSPNEW-888 префиксы 
    // можно будет опять слить)

    // Синонимы для SSP/AP (SSPI)
typedef CredHandle  SC_CredHandle;   
typedef PCredHandle PSC_CredHandle;

    // Синонимы для внутреннего использования в реализации протокола TLS
typedef struct _CPSSP_CREDS_ NSC_CPSSP_CREDS, *PNSC_CPSSP_CREDS;

    // Дескриптор мультиплицированного удостоверения
typedef struct NSC_CredHandle_ {
    ULONG_PTR dwLower ;
    ULONG_PTR dwUpper ;
} NSC_CredHandle, *PNSC_CredHandle;

    // Мультиплицированное удостоверение
typedef struct _SC_CPSSP_CREDS_ {
    size_t	    sNumCreds;	// коэффициент размножения
    volatile
    LONG            lNextCreds;	// кольцевой счётчик следующего удостоверения
    NSC_CredHandle  *ahCreds;	// [sNumCreds] дескрипторы одиночных удостоверений
}   SC_CPSSP_CREDS, *PSC_CPSSP_CREDS;

    // Функции преобразования дескриптор <-> удостоверения
void SecSetCPCredsHandle (PNSC_CredHandle pSecHandle, PNSC_CPSSP_CREDS pCPSecHandle);
PNSC_CPSSP_CREDS SecGetCPCredsHandle(PNSC_CredHandle pSecHandle);

void SC_SecSetCPCredsHandle(PSecHandle pSecHandle, PSC_CPSSP_CREDS pCPSecHandle);
PSC_CPSSP_CREDS SC_SecGetCPCredsHandle(PSC_CredHandle pSecHandle);

#define CSP_3_6_VERSION 0x00000306

    // Одиночное удостоверение
typedef struct _CPSSP_CREDS_ {
	CPSSP_CREDS_FLAGS			Flags;
	DWORD					dwFlags;
	PCCERT_CONTEXT				pCertContext;
	HCERTSTORE				hRestrictedRoot;
	PCCERT_CHAIN_CONTEXT			pChainContext;
        HCRYPTPROV				hCryptProv;
        CSP_BOOL					CPRelease;
        DWORD					dwKeySpec;
	DWORD					dwProvVersion;//0x0306
	volatile LONG				nRef;
	PCPSSP_SESSION				FirstSession;
	PCPSSP_SESSION				LastSession;
	int					nCachedSessions;
	ASN1SeqOfOctStr				CA_list;
        PNSC_CPSSP_CREDS			prev;
        PNSC_CPSSP_CREDS			next;
	DWORD					cSupportedAlgs;  
	ALG_ID*					palgSupportedAlgs;
#ifdef WIN32
#ifdef _CP_SSP_AP_	
	CRYPT_USER_DATA				CryptUserData;
	DWORD					dwCredFormat;	
	ClientCertPolicy			clientCertPolicy;
#endif
	SCHANNEL_MAPPER *			aphMapper[3];
	DWORD					cMappers;
#endif
	CPC_RWLOCK				AccessLock;
} CPSSP_CREDS;

typedef struct _CPSSP_CTX_FLAGS_ {
    unsigned int Server:1;
    unsigned int MutualAuth:1;
    unsigned int UseSupplied:1;
    unsigned int FixedDH:1;
    unsigned int SplitByMessages:1;
    unsigned int SkipNextMAC:1;
    unsigned int fOCSPSupported:1;
//флажки отвечающие за TLS extensions
//для клиента означают, что extension посылался, после получения hello от сервера - будет ли поддерживаться
//для сервера означают, что получен от клиента и будет поддерживаться
    unsigned int server_name:1;
    unsigned int renegotiation_info:1;
#ifdef _CP_SSP_AP_
    unsigned int status_request:1;
#endif /*_CP_SSP_AP_*/
} CPSSP_CTX_FLAGS, *PCPSSP_CTX_FLAGS;

#define SSL_BUFFERS_COUNT 3
#define OCSP_NONCE_CLIENT_LENGTH 8

typedef struct _CPSSP_SESSION_ {
	PCCERT_CONTEXT				pRemoteCertContext;
	HCERTSTORE				hRemoteCerts;
	SECURITY_STATUS				mapperStatus;
	HANDLE					hToken;
	DWORD					iMapper;
	HCRYPTKEY				hPreMasterSecret;
        BYTE 					session_id[SSL3_SSL_SESSION_ID_LENGTH];
        BYTE					session_id_length;
        LPWSTR					target_name;
	CSP_BOOL					is_client;
	volatile LONG				nRef;
	CSP_BOOL					bReused;
	CSP_BOOL					bExtracted;
        PCPSSP_SESSION				next;
        PCPSSP_SESSION				prev;
        time_t					start_time;
        time_t					timeout;
        PCPSSP_CREDS				pCPCredentials;
	ASN1SeqOfOctStr				CA_list;
	DWORD					CipherSuite;
#ifdef _CP_SSP_AP_
	SecPkgContext_ClientCertPolicyResult	clientCertPolicyResult;
#endif
	CPC_RWLOCK				AccessLock;
} CPSSP_SESSION;

typedef struct _CPSSP_CTX_ {
	CPSSP_CTX_FLAGS				Flags;
	CSP_BOOL					fUserHaveNewKeys;
#ifdef _CP_SSP_AP_
	PBYTE					OCSPrequest_extentions;
	DWORD					OCSPrequest_extentions_size;
	LSA_SEC_HANDLE				LsaContextHandle;//контекст родного shannela
	SCHANNEL_MAPPER *			aphMapper[3];//заполним перед вызовом SpGetContextToken
	LSA_SEC_HANDLE				Lsa64ContextHandle;//контекст lsamode при работе в 64 битном окружении
	DWORD					iMapper;
	DWORD					cMappers;
	HANDLE					hToken;//UserModeToken
#endif
	DWORD					dwContextState;
	FILETIME				tsStart;
        PCPSSP_SESSION				session;
        PCPSSP_CREDS				pCPCredentialsRd;   // Контекст чтения
        PCPSSP_CREDS				pCPCredentialsWr;   // Контекст записи
        PCPSSP_CREDS				pCPCredentialsFn;   // Контекст согласования (handshake)
	SecBufferDesc				Output;
	SecBufferDesc				Input;
	SecBuffer				Buffers[2*SSL_BUFFERS_COUNT];
        BYTE					client_random[SSL3_RANDOM_SIZE];
        BYTE					server_random[SSL3_RANDOM_SIZE];
	BYTE					finish_md_size;
	BYTE					peer_finish_md_size;
	BYTE					finish_md[TLS_FINISH_MD_SIZE];
	BYTE					peer_finish_md[TLS_FINISH_MD_SIZE];
        HCRYPTHASH				hMasterHash;
        HCRYPTHASH				hFinishHash;
        HCRYPTKEY				hReadKey;
        HCRYPTKEY				hWriteKey;
        HCRYPTKEY				hReadHMACKey;
        HCRYPTKEY				hWriteHMACKey;
        HCRYPTHASH				hReadHMACHash;
        HCRYPTHASH				hWriteHMACHash;
	CSP_BOOL					fReadHMACCummulative;
	CSP_BOOL					fWriteHMACCummulative;
        BYTE					read_sequence[8];
        BYTE					write_sequence[8];
        DWORD					dwHMACLen;
        DWORD					suite_version;
        PSecBuffer				pLastOutput;
	DWORD					cbLastOutput;
	SECURITY_STATUS				StatusLastOutput;
        DWORD					shutdown;
	DWORD					n_supported_certs;
	ALG_ID					supported_certs[2];
} CPSSP_CTX, *PCPSSP_CTX;

#define IsKB2CipherSuite(CipherSuite) (SSL3_CK_GVO != CipherSuite)
#define IsNewCipherSuite(CipherSuite) (TLS_CIPHER_94 == CipherSuite || TLS_CIPHER_2001 == CipherSuite)

extern void SecSetCPCtxHandle (PSecHandle pSecHandle, PCPSSP_CTX pCPSecHandle);
extern PCPSSP_CTX SecGetCPCtxHandle (PSecHandle pSecHandle);
extern void CPInitializeBuffers (PSecBufferDesc InBuffer, PSecBuffer InBuffers, unsigned num, const PSecBufferDesc src);

extern SECURITY_STATUS	MapperStatus2SecStatus (DWORD SecStatus);

void
InitializeSecurityPackage (void);

SECURITY_STATUS
SEC_ENTRY
CPAcceptSecurityContext(
	PCredHandle		phCredential,		/* handle to the credentials*/
	PCtxtHandle		phContext,			/* handle of partially formed context*/
	PSecBufferDesc	pInput,				/* pointer to the input buffers*/
	ULONG			fContextReq,        /* required context attributes*/
	ULONG			TargetDataRep,      /* data representation on the target*/
	PCtxtHandle		phNewContext,		/* receives the new context handle*/
	PSecBufferDesc	pOutput,			/* pointer to the output buffers*/
	PULONG			pfContextAttr,      /* receives the context attributes*/
	PTimeStamp		ptsTimeStamp		/* receives the life span of the security context*/
	);

SECURITY_STATUS
SEC_ENTRY
CPAcquireCredentialsHandleA(
	SEC_CHAR	*pszPrincipal,			/* name of principal*/
	SEC_CHAR	*pszPackage,			/* name of package*/
	ULONG		fCredentialUse,			/* flags indicating use*/
	PLUID		pvLogonID,				/* pointer to logon identifier*/
	PVOID		pAuthData,				/* package-specific data*/
	PVOID		pGetKeyFn,				/* pointer to GetKey function*/
	PVOID		pvGetKeyArgument,		/* value to pass to GetKey*/
	PCredHandle phCredential,			/* credential handle*/
	PTimeStamp	ptsExpiry				/* lifetime of the returned credentials*/
	);

SECURITY_STATUS
SEC_ENTRY
CPAcquireCredentialsHandleW(
	SEC_WCHAR	*pwszPrincipal,			/* name of principal*/
	SEC_WCHAR	*pwszPackage,			/* name of package*/
	ULONG		fCredentialUse,			/* flags indicating use*/
	PLUID		pvLogonID,				/* pointer to logon identifier*/
	PVOID		pAuthData,				/* package-specific data*/
	PVOID		pGetKeyFn,				/* pointer to GetKey function*/
	PVOID		pvGetKeyArgument,		/* value to pass to GetKey*/
	PCredHandle phCredential,			/* credential handle*/
	PTimeStamp	ptsExpiry				/* lifetime of the returned credentials*/
	);

SECURITY_STATUS
SEC_ENTRY
CPApplyControlToken(
	PCtxtHandle		phContext,			/* handle of the context to modify*/
	PSecBufferDesc	pInput				/* input token to apply*/
	);

SECURITY_STATUS
SEC_ENTRY
CPCompleteAuthToken(
	PCtxtHandle		phContext,			/* handle of the context to complete*/
	PSecBufferDesc	pToken				/* token to complete*/
	);

SECURITY_STATUS
SEC_ENTRY
CPDecryptMessage(
	PCtxtHandle phContext,				/* context to use*/
	PSecBufferDesc pMessage,			/* buffer containing the message to decrypt*/
	ULONG MessageSeqNo,					/* expected sequence number*/
	PULONG pfQOP						/* quality of protection*/
	);

SECURITY_STATUS
SEC_ENTRY
CPDeleteSecurityContext(
	PCtxtHandle	phContext				/* handle of the context to delete*/
	);

SECURITY_STATUS
SEC_ENTRY
CPEnumerateSecurityPackagesA(
	PULONG		pcPackages,				/* receives the number of packages*/
	PSecPkgInfoA *ppPackageInfo			/* receives array of information*/
	);

SECURITY_STATUS
SEC_ENTRY
CPEnumerateSecurityPackagesW(
	PULONG			pcPackages,			/* receives the number of packages*/
	PSecPkgInfoW	*ppPackageInfo		/* receives array of information*/
	);

SECURITY_STATUS
SEC_ENTRY
CPEncryptMessage(
	PCtxtHandle		phContext,			/* context to use*/
	ULONG			fQOP,               /* quality of protection*/
	PSecBufferDesc	pMessage,			/* message to encrypt*/
	ULONG			MessageSeqNo        /* message sequence number*/
	);

SECURITY_STATUS
SEC_ENTRY
CPExportSecurityContext(
	PCtxtHandle		phContext,
	ULONG			fFlags,
	PSecBuffer		pPackedContext,
	void SEC_FAR * SEC_FAR * pToken                 // (out, optional) token handle for impersonation
	);

SECURITY_STATUS
SEC_ENTRY
CPFreeContextBuffer(
	PVOID	pvContextBuffer				/* buffer to free*/
	);

SECURITY_STATUS
SEC_ENTRY
CPFreeCredentialsHandle(
	PCredHandle	phCredential			/* handle to free*/
	);

SECURITY_STATUS
SEC_ENTRY
CPImpersonateSecurityContext(
	PCtxtHandle	phContext				/* handle of context to impersonate	*/
	);

SECURITY_STATUS
SEC_ENTRY
CPImportSecurityContextA(
	SEC_CHAR SEC_FAR	*pszPackage, 
	PSecBuffer			pPackedContext, 
	void SEC_FAR		*pToken, 
	PCtxtHandle			phContext 
	);

SECURITY_STATUS
SEC_ENTRY
CPImportSecurityContextW(
	SEC_WCHAR SEC_FAR	*pszPackage, 
	PSecBuffer			pPackedContext, 
	void SEC_FAR		*pToken, 
	PCtxtHandle			phContext 
	);

PSecurityFunctionTableA
SEC_ENTRY
CPInitSecurityInterfaceA(
	void);

PSecurityFunctionTableW
SEC_ENTRY
CPInitSecurityInterfaceW(
	void);

SECURITY_STATUS
SEC_ENTRY
CPInitializeSecurityContextA(
	PCredHandle		phCredential,		/* handle to the credentials*/
	PCtxtHandle		phContext,			/* handle of partially formed context*/
	SEC_CHAR		*pszTargetName,		/* name of the target of the context*/
	ULONG			fContextReq,        /* required context attributes*/
	ULONG			Reserved1,          /* reserved; must be zero*/
	ULONG			TargetDataRep,      /* data representation on the target*/
	PSecBufferDesc	pInput,				/* pointer to the input buffers*/
	ULONG			Reserved2,          /* reserved; must be zero*/
	PCtxtHandle		phNewContext,		/* receives the new context handle*/
	PSecBufferDesc	pOutput,			/* pointer to the output buffers*/
	PULONG			pfContextAttr,      /* receives the context attributes*/
	PTimeStamp		ptsExpiry			/* receives the life span of the security context*/
	);

SECURITY_STATUS
SEC_ENTRY
CPInitializeSecurityContextW(
	PCredHandle		phCredential,		/* handle to the credentials*/
	PCtxtHandle		phContext,			/* handle of partially formed context*/
	SEC_WCHAR		*pwszTargetName,	/* name of the target of the context*/
	ULONG			fContextReq,        /* required context attributes*/
	ULONG			Reserved1,          /* reserved; must be zero*/
	ULONG			TargetDataRep,      /* data representation on the target*/
	PSecBufferDesc	pInput,				/* pointer to the input buffers*/
	ULONG			Reserved2,          /* reserved; must be zero*/
	PCtxtHandle		phNewContext,		/* receives the new context handle*/
	PSecBufferDesc	pOutput,			/* pointer to the output buffers*/
	PULONG			pfContextAttr,      /* receives the context attributes*/
	PTimeStamp		ptsExpiry			/* receives the life span of the security context*/
	);

SECURITY_STATUS
SEC_ENTRY
CPMakeSignature(
	PCtxtHandle		phContext,			/* context to use*/
	ULONG			fQOP,               /* quality of protection*/
	PSecBufferDesc	pMessage,			/* message to sign*/
	ULONG			MessageSeqNo        /* message sequence number*/
	);

SECURITY_STATUS
SEC_ENTRY
CPQueryCredentialsAttributesA(
    PCredHandle		phCredential,        /* Credential to query*/
    unsigned long	ulAttribute,         /* Attribute to query*/
    void SEC_FAR	*pBuffer             /* Buffer for attributes*/
    );

SECURITY_STATUS
SEC_ENTRY
CPQueryCredentialsAttributesW(
    PCredHandle		phCredential,        /* Credential to query*/
    unsigned long	ulAttribute,         /* Attribute to query*/
    void SEC_FAR	*pBuffer             /* Buffer for attributes*/
    );

SECURITY_STATUS
SEC_ENTRY
CPSetCredentialsAttributesA(
    PCredHandle		phCredential,        /* Credential to query*/
    unsigned long	ulAttribute,         /* Attribute to query*/
    void SEC_FAR	*pBuffer,            /* Buffer for attributes*/
    unsigned long	ulBufferSize
    );

SECURITY_STATUS
SEC_ENTRY
CPQueryContextAttributesA(
	PCtxtHandle phContext,				/* handle of the context to query*/
	ULONG		ulAttribute,			/* attribute to query*/
	PVOID		pBuffer					/* buffer for attributes*/
	);

SECURITY_STATUS
SEC_ENTRY
CPQueryContextAttributesW(
	PCtxtHandle phContext,				/* handle of the context to query*/
	ULONG		ulAttribute,			/* attribute to query*/
	PVOID		pBuffer					/* buffer for attributes*/
	);

SECURITY_STATUS
SEC_ENTRY
CPQueryCredentialsAttributes(
	PCredHandle phCredential,			/* credential to query*/
	ULONG		ulAttribute,			/* attribute to query*/
	PVOID		pBuffer					/* buffer that receives attributes*/
	);

SECURITY_STATUS
SEC_ENTRY
CPQuerySecurityContextToken(
	PCtxtHandle phContext,
	HANDLE		*phToken
	);

SECURITY_STATUS
SEC_ENTRY
CPQuerySecurityPackageInfoA(
	SEC_CHAR		*pszPackageName,	/* name of package*/
	PSecPkgInfoA	*ppPackageInfo		/* receives package information*/
	);

SECURITY_STATUS
SEC_ENTRY
CPQuerySecurityPackageInfoW(
	SEC_WCHAR		*pszPackageName,	/* name of package*/
	PSecPkgInfoW	*ppPackageInfo		/* receives package information*/
	);

SECURITY_STATUS
SEC_ENTRY
CPRevertSecurityContext(
	PCtxtHandle	phContext				/* handle of the context being impersonated*/
	);

SECURITY_STATUS
SEC_ENTRY
CP_VerifySignature(
	PCtxtHandle		phContext,			/* context to use*/
	PSecBufferDesc	pMessage,			/* message to verify*/
	ULONG			MessageSeqNo,       /* sequence number*/
	PULONG			pfQOP				/* quality of protection*/
	);

CSP_BOOL CPSSPInitialize (void);

extern CPC_RWLOCK	CPSecHandleTableLock;
extern DWORD	CPSecHandleTableSize;

#include<CPROCSP/CpSChl.h>

extern PSECURITY_HANDLE	*	CPSecHandleTable;

#ifdef _CP_SSP_AP_
extern PUSER_SECURITY_HANDLE *	CPUserSecHandleTable;
#endif

#endif /* _CP_SSP_ */

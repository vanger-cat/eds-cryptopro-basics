
#ifndef _CP_SCHANNEL_
#define _CP_SCHANNEL_

#define CPSSP_PACKAGE_CAPABILITIES	SECPKG_FLAG_INTEGRITY		|	\
					SECPKG_FLAG_PRIVACY		|	\
					SECPKG_FLAG_CONNECTION		|	\
					SECPKG_FLAG_MULTI_REQUIRED	|	\
					SECPKG_FLAG_EXTENDED_ERROR	|	\
					SECPKG_FLAG_IMPERSONATION	|	\
					SECPKG_FLAG_ACCEPT_WIN32_NAME   |	\
					SECPKG_FLAG_STREAM		|	\
					SECPKG_FLAG_MUTUAL_AUTH

#define CPSSP_PACKAGE_HEADER_SIZE	0x5U
#define CPSSP_PACKAGE_MAX_TOKEN		(0x4000-CPSSP_PACKAGE_HEADER_SIZE)
#define CPSSP_PACKAGE_TRAILER_SIZE	0x4U

#define SSL3_VERSION			0x0300
#define SSL3_VERSION_MAJOR		0x03
#define SSL3_VERSION_MINOR		0x00

#define SSL3_RT_CHANGE_CIPHER_SPEC	20
#define SSL3_RT_ALERT			21
#define SSL3_RT_HANDSHAKE		22
#define SSL3_RT_APPLICATION_DATA	23

typedef struct _PROTOCOL_VERSION_ {
	BYTE	Major;
	BYTE	Minor;
} PROTOCOL_VERSION, *PPROTOCOL_VERSION;

typedef struct _TLS1_RECORD_HEADER_ {
	BYTE				Type;
	PROTOCOL_VERSION		Version;
	BYTE				HiLength;
	BYTE				LoLength;
} TLS1_RECORD_HEADER, *PTLS1_RECORD_HEADER;

typedef struct _SECURITY_HANDLE_FLAGS_  {
	DWORD	dwFlags;
} SECURITY_HANDLE_FLAGS, *PSECURITY_HANDLE_FLAGS;

#ifdef KSP_LITE
typedef struct _SECURIY_HANDLE_{    
    //наш контекст
    LSA_SEC_HANDLE				CPSecHandle;
    //Контекст родного schannel
    LSA_SEC_HANDLE				PatchSecHandle;
    //Контекст LSA, который дернул KSP
    LSA_SEC_HANDLE				LsaContextId;
    //Обрезанный до ULONG Контекст Schannel в LSA
    ULONG   					LsaPatchContextId;    
    ULONG_PTR					Id;
} SECURITY_HANDLE, *PSECURITY_HANDLE;
#else
typedef struct _SECURIY_HANDLE_{
    DWORD					dwHandleStatus;
    SecHandle					CPSecHandle;
#if defined (_CP_SSP_AP_)
    //Контекст родного schannel
    LSA_SEC_HANDLE				PatchSecHandle;
#else
    SecHandle					PatchSecHandle;
#endif /* _CP_SSP_AP_ */
    ULONG_PTR					Id;	
} SECURITY_HANDLE, *PSECURITY_HANDLE;
#endif

#ifdef _CP_SSP_AP_

typedef struct _USER_SECURIY_HANDLE_{//сделаю пока корявку такую, иначе не получается пока
	LSA_SEC_HANDLE				LsaCtxHandle;
	PSecHandle				pUserCtxHandle;
} USER_SECURITY_HANDLE, *PUSER_SECURITY_HANDLE;
extern void SecSetCPUserHandle (LSA_SEC_HANDLE LsaCtxHandle, PSecHandle pSecUserHandle);
extern void SecDelCPUserHandle (LSA_SEC_HANDLE  LsaCtxHandle);
extern PSecHandle SecGetCPUserHandle (LSA_SEC_HANDLE LsaCtxHandle);
extern PSecHandle SecGetCPUserHandle64 (LSA_SEC_HANDLE LsaCtxHandle);
LSA_SEC_HANDLE FindLsaCtxByUserCtx(LSA_SEC_HANDLE  LsaCtxHandle);

#endif

#ifndef KSP_LITE
extern ULONG_PTR SecSetCPHandle (PSecHandle pSecHandle, PSECURITY_HANDLE pCPSecHandle);
extern void SecDelCPHandleLsa (PSECURITY_HANDLE pCPSecHandle);
extern void SecDelCPHandle (PSecHandle pSecHandle, PSECURITY_HANDLE pCPSecHandle);
extern PSECURITY_HANDLE SecGetCPHandle (PSecHandle pSecHandle);
extern PSECURITY_HANDLE SecGetCPHandleLsa (ULONG_PTR ContextId);
#endif

#endif /* _CP_SCHANNEL_ */

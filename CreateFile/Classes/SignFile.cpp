/*
 *  SignFile.cpp
 *  CreateFile
 *
 *  Created by Кондакова Татьяна Андреевна on 10.12.10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "SignFile.h"
DWORD VerifyCertificate(PCCERT_CONTEXT pCert,DWORD *CheckResult)
{
    CERT_CHAIN_PARA ChainPara;
    PCCERT_CHAIN_CONTEXT Chain=NULL;
	
    ChainPara.cbSize=sizeof(ChainPara);
    ChainPara.RequestedUsage.dwType=USAGE_MATCH_TYPE_AND;
    ChainPara.RequestedUsage.Usage.cUsageIdentifier=0;
    ChainPara.RequestedUsage.Usage.rgpszUsageIdentifier=NULL;
    //ChainPara.RequestedIssuancePolicy=NULL;
    //ChainPara.fCheckRevocationFreshnessTime=FALSE;
    //ChainPara.dwUrlRetrievalTimeout=0;
	
    if(!CertGetCertificateChain(
								NULL,
								pCert,
								NULL,
								NULL,//?
								&ChainPara,
								CERT_CHAIN_REVOCATION_CHECK_CHAIN_EXCLUDE_ROOT,
								NULL,
								&Chain))
        return CSP_GetLastError();
    *CheckResult=Chain->TrustStatus.dwErrorStatus;
    if(Chain)
        CertFreeCertificateChain(Chain);
    return 0;
}


DWORD do_low_sign (const char *infile, const char *outfile)
{
	char OID[64] = szOID_CP_GOST_R3411;
    int include = 1;
    HCRYPTPROV hCryptProv = 0;               // CSP handle
    PCCERT_CONTEXT pUserCert = NULL;		// User certificate to be used
	
    DWORD keytype = 0;
    CSP_BOOL should_release_ctx = FALSE;
    DWORD ret = 1;
    FILE *tbs = NULL;
    BYTE *mem_tbs = NULL;
    DWORD mem_len = 0;
    
    HCRYPTMSG hMsg = 0;
    
    DWORD			HashAlgSize;
	DWORD			dwSize;
    CRYPT_ALGORITHM_IDENTIFIER	HashAlgorithm;
    CMSG_SIGNER_ENCODE_INFO	SignerEncodeInfo;
    CERT_BLOB			SignerCertBlob;
    CERT_BLOB			SignerCertBlobArray[1];
    DWORD			cbEncodedBlob;
    BYTE			*pbEncodedBlob = NULL;
    CMSG_SIGNER_ENCODE_INFO	SignerEncodeInfoArray[1];
    CMSG_SIGNED_ENCODE_INFO	SignedMsgEncodeInfo;
	CSP_BOOL bResult = FALSE;
	CRYPT_KEY_PROV_INFO *pProvInfo = NULL;
	
	HCERTSTORE hCertStore = 0;
	
	hCertStore = CertOpenSystemStore(0, "My");
	if(!hCertStore){
		ret = CSP_GetLastError();
		fprintf (stderr, "CertOpenSystemStore failed.");
		goto err;
	}
	
	while( !bResult){
		pUserCert= CertEnumCertificatesInStore(hCertStore, pUserCert);
		if(!pUserCert){
			break;
		}
		bResult = CertGetCertificateContextProperty(
													pUserCert, CERT_KEY_PROV_INFO_PROP_ID, NULL, &dwSize);
		if (bResult) {
			
			free(pProvInfo);
			pProvInfo = (CRYPT_KEY_PROV_INFO *)malloc(dwSize);
			if (pProvInfo) {
				bResult = CertGetCertificateContextProperty(
															pUserCert, CERT_KEY_PROV_INFO_PROP_ID, pProvInfo, &dwSize);
			}
			
		}
	}
	if(!bResult){
		fprintf (stderr, "No certificates with private key link.");
		goto err;
	}
	
    if (! infile) {
		fprintf (stderr, "No input file was specified\n");
		goto err;
    }
	
    if (CryptAcquireCertificatePrivateKey(
										  pUserCert,        
										  0,		//DWORD dwFlags,               
										  NULL,            
										  &hCryptProv,     
										  &keytype,           // returned key type AT_SIGNATURE ! AT_KEYEXCAHGE
										  &should_release_ctx  // if FALSE DO NOT Release CTX
										  )) {
		printf("A CSP has been acquired. \n");
    }
    else {
		ret = CSP_GetLastError();
		fprintf (stderr, "Cryptographic context could not be acquired.");
		goto err;
    }
	
	
    tbs = fopen (infile, "rb");
    if (!tbs) {
		fprintf (stderr, "Cannot open input file\n");
		goto err;
    }
	
    
    mem_len = 0;
    while (!feof(tbs)) {
		int r = 0;
		BYTE tmp[1024];
		r = fread (tmp, 1, 1024, tbs);
		mem_tbs = (BYTE *)realloc(mem_tbs, mem_len+r);
		memcpy (&mem_tbs[mem_len], tmp, r);
		mem_len += r;
    }
    fclose (tbs);
    tbs = NULL;
	
	
	//--------------------------------------------------------------------
	// Initialize the algorithm identifier structure.
    
    HashAlgSize = sizeof(HashAlgorithm);
    memset(&HashAlgorithm, 0, HashAlgSize); // Init. to zero.
    HashAlgorithm.pszObjId = OID;	    // Initialize the necessary member.
    
    //--------------------------------------------------------------------
    // Initialize the CMSG_SIGNER_ENCODE_INFO structure.
    
    memset(&SignerEncodeInfo, 0, sizeof(CMSG_SIGNER_ENCODE_INFO));
    SignerEncodeInfo.cbSize = sizeof(CMSG_SIGNER_ENCODE_INFO);
    SignerEncodeInfo.pCertInfo = pUserCert->pCertInfo;
    SignerEncodeInfo.hCryptProv = hCryptProv;
    SignerEncodeInfo.dwKeySpec = keytype;
    SignerEncodeInfo.HashAlgorithm = HashAlgorithm;
    SignerEncodeInfo.pvHashAuxInfo = NULL;
    
    //--------------------------------------------------------------------
    // Create an array of one. Note: Currently, there can be only one
    // signer.
    
    SignerEncodeInfoArray[0] = SignerEncodeInfo;
    
    //--------------------------------------------------------------------
    // Initialize the CMSG_SIGNED_ENCODE_INFO structure.
    
    SignerCertBlob.cbData = pUserCert->cbCertEncoded;
    SignerCertBlob.pbData = pUserCert->pbCertEncoded;
    
    //--------------------------------------------------------------------
    // Initialize the array of one CertBlob.
    
    SignerCertBlobArray[0] = SignerCertBlob;
    memset(&SignedMsgEncodeInfo, 0, sizeof(CMSG_SIGNED_ENCODE_INFO));
    SignedMsgEncodeInfo.cbSize = sizeof(CMSG_SIGNED_ENCODE_INFO);
    SignedMsgEncodeInfo.cSigners = 1;
    SignedMsgEncodeInfo.rgSigners = SignerEncodeInfoArray;
    SignedMsgEncodeInfo.cCertEncoded = include;
    if (include)
		SignedMsgEncodeInfo.rgCertEncoded = SignerCertBlobArray;
    else
		SignedMsgEncodeInfo.rgCertEncoded = NULL;
    SignedMsgEncodeInfo.rgCrlEncoded = NULL;
    
    //--------------------------------------------------------------------
    // Get the size of the encoded message blob.
    
    if(cbEncodedBlob = CryptMsgCalculateEncodedLength(
													  TYPE_DER,       // Message encoding type
													  0,                      // Flags
													  CMSG_SIGNED,            // Message type
													  &SignedMsgEncodeInfo,   // Pointer to structure
													  NULL,                   // Inner content object ID
													  mem_len))		// Size of content */
	{
		printf("The length of the data has been calculated. \n");
    }
    else
    {
		ret = CSP_GetLastError();
		fprintf (stderr, "Getting cbEncodedBlob length failed");
		goto err;		
    }
    //--------------------------------------------------------------------
    // Allocate memory for the encoded blob.
    
    pbEncodedBlob = (BYTE *) malloc(cbEncodedBlob);
    if (!pbEncodedBlob){
		ret = CSP_GetLastError();
		fprintf (stderr, "Memory allocation failed");
		goto err;
	}
    //--------------------------------------------------------------------
    // Open a message to encode.
    
    if(hMsg = CryptMsgOpenToEncode(
								   TYPE_DER,        // Encoding type
								   0,                       // Flags
								   CMSG_SIGNED,             // Message type
								   &SignedMsgEncodeInfo,    // Pointer to structure
								   NULL,                    // Inner content object ID
								   NULL))                   // Stream information (not used)
    {
		printf("The message to be encoded has been opened. \n");
    }
    else
    {
		ret = CSP_GetLastError();
		fprintf (stderr, "OpenToEncode failed");
		goto err;
    }
    //--------------------------------------------------------------------
    // Update the message with the data.
    
    if(CryptMsgUpdate(
					  hMsg,		// Handle to the message
					  mem_tbs,		// Pointer to the content
					  mem_len,	// Size of the content
					  TRUE))		// Last call
    {
		printf("Content has been added to the encoded message. \n");
    }
    else
    {
		ret = CSP_GetLastError();
		fprintf (stderr, "MsgUpdate failed");
		goto err;
    }
    //--------------------------------------------------------------------
    // Get the resulting message.
    
    if(CryptMsgGetParam(
						hMsg,                      // Handle to the message
						CMSG_CONTENT_PARAM,        // Parameter type
						0,                         // Index
						pbEncodedBlob,             // Pointer to the blob
						&cbEncodedBlob))           // Size of the blob
    {
		printf("Message encoded successfully. \n");
    }
    else
    {
		ret = CSP_GetLastError();
		fprintf (stderr, "MsgGetParam failed");
		goto err;
    }
    //--------------------------------------------------------------------
    // pbEncodedBlob now points to the encoded, signed content.
    //--------------------------------------------------------------------
    if (outfile) {
		FILE *out = NULL;
		out = fopen (outfile, "wb");
		if (out) {
			fwrite (pbEncodedBlob, cbEncodedBlob, 1, out);
			fclose (out);
			printf ("Output file (%s) has been saved\n", outfile);
			
		}
		else
			perror ("Cannot open out file\n");
	}
    
	ret = 0;
    //--------------------------------------------------------------------
    // Clean up.
err:
    if(pbEncodedBlob)
		free(pbEncodedBlob);
    if(hMsg)
		CryptMsgClose(hMsg);
    if(hCryptProv) 
		CryptReleaseContext(hCryptProv,0);
	if(hCertStore)
		CertCloseStore(hCertStore, 0);
	
    return ret;
} 



DWORD do_low_verify (const char *infile, const char *outfile)
{
    HCRYPTPROV hCryptProv = 0;               // CSP handle
    PCCERT_CONTEXT pUserCert = NULL;		// User certificate to be used
    DWORD ret = 1;
    FILE *tbs = NULL;
    BYTE *mem_tbs = NULL;
    DWORD mem_len = 0;
    FILE *signature = NULL;
    BYTE *mem_signature = NULL;
    DWORD signature_len = 0;
	HCRYPTMSG hMsg = 0;
	
    DWORD cbDecoded;
    BYTE *pbDecoded;
    DWORD cbSignerCertInfo;
    PCERT_INFO pSignerCertInfo;
    PCCERT_CONTEXT pSignerCertContext;
    PCERT_INFO pSignerCertificateInfo;
    HCERTSTORE hStoreHandle = NULL;
	
    if (! infile) {
		fprintf (stderr, "No input file was specified\n");
		goto err;
    }
	
	
    tbs = fopen (infile, "rb");
    if (!tbs) {
		fprintf (stderr, "Cannot open input file\n");
		goto err;
    }
	
    mem_len = 0;
    while (!feof(tbs)) {
		int r = 0;
		BYTE tmp[1024];
		r = fread (tmp, 1, 1024, tbs);
		mem_tbs = (BYTE *)realloc (mem_tbs, mem_len+r);
		memcpy (&mem_tbs[mem_len], tmp, r);
		mem_len += r;
    }
    fclose (tbs);
    tbs = NULL;
	
	
    if (signature) {
		signature_len = 0;
		while (!feof(signature)) {
			int r = 0;
			BYTE tmp[1024];
			r = fread (tmp, 1, 1024, signature);
			mem_signature = (BYTE *)realloc (mem_signature , signature_len+r);
			memcpy (&mem_signature [signature_len], tmp, r);
			signature_len += r;
		}
		fclose (signature);
		signature = NULL;
    }
	
    //--------------------------------------------------------------------
    // Open a message for decoding.
    
    hMsg = CryptMsgOpenToDecode(
								TYPE_DER,      // Encoding type.
								0,                     // Flags.
								0,                     // Use the default message type.
								hCryptProv,            // Cryptographic provider.
								NULL,                  // Recipient information.
								NULL);                 // Stream information.
    if (hMsg) 
		printf("The message to decode is open. \n");
    else{
    	fprintf (stderr, "OpenToDecode failed");
		ret = CSP_GetLastError();
		goto err;
	}
    //--------------------------------------------------------------------
    // Update the message with an encoded blob.
    // Both pbEncodedBlob, the encoded data, 
    // and cbEnclodeBlob, the length of the encoded data,
    // must be available. 
    
	
    if (CryptMsgUpdate(
					   hMsg,                 // Handle to the message
					   mem_tbs,        // Pointer to the encoded blob
					   mem_len,        // Size of the encoded blob
					   TRUE)){               // Last call) 
		printf("The encoded blob has been added to the message. \n");
	}
    else { 
		
		fprintf (stderr, "Decode MsgUpdate failed");
		ret = CSP_GetLastError();
		goto err;
    }
    //--------------------------------------------------------------------
    // Get the size of the content.
    
    ret = CryptMsgGetParam(
						   hMsg,                  // Handle to the message
						   CMSG_CONTENT_PARAM,    // Parameter type
						   0,                     // Index
						   NULL,                  // Address for returned info
						   &cbDecoded);           // Size of the returned info
    if (ret)
		printf("The message parameter (CMSG_CONTENT_PARAM) has been acquired. Message size: %d\n", cbDecoded);
    else{
		fprintf (stderr, "Decode CMSG_CONTENT_PARAM failed");
		ret = CSP_GetLastError();
		goto err;
	}
    //--------------------------------------------------------------------
    // Allocate memory.
    
    pbDecoded = (BYTE *) malloc(cbDecoded);
    if (!pbDecoded){
		
		fprintf (stderr, "Decode memory allocation failed");
		ret = CSP_GetLastError();
		goto err;
	}
    //--------------------------------------------------------------------
    // Get a pointer to the content.
    
    ret = CryptMsgGetParam(
						   hMsg,                 // Handle to the message
						   CMSG_CONTENT_PARAM,   // Parameter type
						   0,                    // Index
						   pbDecoded,            // Address for returned 
						   &cbDecoded);          // Size of the returned        
    if (ret)
		printf("The message param (CMSG_CONTENT_PARAM) updated. Length is %lu.\n",(unsigned long)cbDecoded);
    else{
		
		fprintf (stderr, "Decode CMSG_CONTENT_PARAM #2 failed");
		ret = CSP_GetLastError();
		goto err;
	}
    //--------------------------------------------------------------------
    // Verify the signature.
    // First, get the signer CERT_INFO from the message.
    
    //--------------------------------------------------------------------
    // Get the size of memory required.
	
    if (! pUserCert) { 
		ret = CryptMsgGetParam(
							   hMsg,                         // Handle to the message
							   CMSG_SIGNER_CERT_INFO_PARAM,  // Parameter type
							   0,                            // Index
							   NULL,                        // Address for returned 
							   &cbSignerCertInfo);          // Size of the returned 
		if (ret)
			printf("Try to get user cert. OK. Length %d.\n",cbSignerCertInfo);
		else {
			printf("No user certificate found in message.\n");
		}
    }
	
    if (pUserCert) {
		hStoreHandle = CertOpenStore(CERT_STORE_PROV_MEMORY, TYPE_DER, 0, CERT_STORE_CREATE_NEW_FLAG,NULL);
		if (!hStoreHandle){
			printf("Cannot create temporary store in memory.");
		    return CSP_GetLastError();
		}
		if (pUserCert) {
			ret = CertAddCertificateContextToStore(hStoreHandle, pUserCert, CERT_STORE_ADD_ALWAYS, NULL);
			pSignerCertInfo = pUserCert->pCertInfo;
		}
		else
			ret = 0;
		if (!ret){
			printf("Cannot add user certificate to store.");
			return CSP_GetLastError();
		}
    }
    
    //--------------------------------------------------------------------
    // Allocate memory.
    
    if (!pUserCert) {
		pSignerCertInfo = (PCERT_INFO) malloc(cbSignerCertInfo);
		if (!pSignerCertInfo){
			printf("Verify memory allocation failed");
			return CSP_GetLastError();
		}
    }
    
    //--------------------------------------------------------------------
    // Get the message certificate information (CERT_INFO
    // structure).
    
    if (! pUserCert) {
		ret = CryptMsgGetParam(
							   hMsg,                         // Handle to the message
							   CMSG_SIGNER_CERT_INFO_PARAM,  // Parameter type
							   0,                            // Index
							   pSignerCertInfo,              // Address for returned 
							   &cbSignerCertInfo);           // Size of the returned 
	    if (ret) 
			printf("The signer info has been returned. \n");
	    else{
			printf("Verify SIGNER_CERT_INFO #2 failed");
			return CSP_GetLastError();
		}
    }
    //--------------------------------------------------------------------
    // Open a certificate store in memory using CERT_STORE_PROV_MSG,
    // which initializes it with the certificates from the message.
    
    if (! hStoreHandle) {
		hStoreHandle = CertOpenStore(
									 CERT_STORE_PROV_MSG,        // Store provider type 
									 TYPE_DER,		    // Encoding type
									 hCryptProv,                 // Cryptographic provider
									 0,                          // Flags
									 hMsg);                      // Handle to the message
		if (hStoreHandle)
			printf("The message certificate store be used for verifying\n");
    }
	
    if (! hStoreHandle) {
	    printf("Cannot open certificate store form message\n");
		return CSP_GetLastError();
    }
    //--------------------------------------------------------------------
    // Find the signer's certificate in the store.
    
    if(pSignerCertContext = CertGetSubjectCertificateFromStore(
															   hStoreHandle,       // Handle to store
															   TYPE_DER,   // Encoding type
															   pSignerCertInfo))   // Pointer to retrieved CERT_CONTEXT
    {
		DWORD errCode=0;
		DWORD err;
		printf("A signer certificate has been retrieved. \n");
		err=VerifyCertificate(pSignerCertContext,&errCode);
		if (err)
		{
			printf("Subject cert verification failed: err=%x\n",err);
			return err;
		}
		if (errCode)
		{
			printf("Subject cert BAD: errCode=%x\n",errCode);
			return errCode;
		}
	}
    else
    {
		printf("Verify GetSubjectCert failed");
		return CSP_GetLastError();
    }
    //--------------------------------------------------------------------
    // Use the CERT_INFO from the signer certificate to verify
    // the signature.

    
    pSignerCertificateInfo = pSignerCertContext->pCertInfo;
    if(CryptMsgControl(
					   hMsg,                       // Handle to the message
					   0,                          // Flags
					   CMSG_CTRL_VERIFY_SIGNATURE, // Control type
					   pSignerCertificateInfo))    // Pointer to the CERT_INFO
    {
		printf("\nSignature was VERIFIED.\n");
    }
    else
    {
		printf("\nThe signature was NOT VEIFIED.\n");
    }
    if(hStoreHandle)
		CertCloseStore(hStoreHandle, CERT_CLOSE_STORE_FORCE_FLAG);
	
	ret = 0;
err:
    return ret;
	
}

/*@}*/

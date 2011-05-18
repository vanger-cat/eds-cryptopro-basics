/*
 *  SignFile.h
 *  CreateFile
 *
 *  Created by Кондакова Татьяна Андреевна on 10.12.10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */
#import <CPROCSP/CPROCSP.h>
#import "stdlib.h"
#import "stdio.h"
#define MY_ENCODING_TYPE  (PKCS_7_ASN_ENCODING | X509_ASN_ENCODING)
#define TYPE_DER  (PKCS_7_ASN_ENCODING | X509_ASN_ENCODING)

#ifdef __cplusplus
extern "C" {
#endif
DWORD do_low_sign(const char *in_filename, const char *out_filename);
DWORD do_low_verify(const char *in_filename, const char *out_filename);

#ifdef __cplusplus
}
#endif
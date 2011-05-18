#if !defined _CSP_LIC_H
#define _CSP_LIC_H

#define LIC_CLASS_CSP 0
#define LIC_CLASS_TLS 1
#define LIC_CLASS_DRV 2
#define LIC_CLASS_NORTEL  3

#define LicIsCsp(x) (/*(x)>=0 && */(x)<=2)
#define LicIsTls(x) ((x)==1 || (x)==2)
#define LicIsDrv(x) ((x)==2)
#define LicIsSignOnly(x) ((x)==4)

#define LicIsValid(x) LicIsCsp(x)

#ifdef __cplusplus
extern "C" {
#endif

extern const SerialConfiguration csp_serial_config;
#ifdef SERIAL_3_0
extern const SerialConfiguration csp_serial_config_30;
#endif

#ifdef __cplusplus
}
#endif

#endif

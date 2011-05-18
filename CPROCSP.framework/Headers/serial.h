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
 * \version $Revision: 65593 $
 * \date $Date: 2010-12-28 16:58:32 +0300 (РІС‚, 28 РґРµРє 2010) $
 * \author $Author: raa $
 *
 * \brief Интерфейс к модулю генерации и изготовления серийного номера продукта.
 */

#ifndef _SERIAL_H_INCLUDED
#define _SERIAL_H_INCLUDED

#include<CPROCSP/reader/tchar.h>
#include<CPROCSP/reader/support.h>
#include<CPROCSP/wincspc.h>
#include<CPROCSP/serial_def.h>

#ifdef __cplusplus
extern "C" {
#endif

UINT GetProductType( const SerialConfiguration *config, LPCTSTR tszPIDKey, CSP_BOOL Process36 );
CSP_BOOL ParseDate( const TCHAR *date_string, support_timeval *sv );

int WINAPI
VerifyLicTimes(const pCP_CALL_CTX pCallCtx, 
	       const pCSP_HASH_FUNCS HashFuncs,
	       CPC_GetTimeOfDay_Callback get_time_of_day,
	       const SerialConfiguration *config,
	       int *expired_through_days, UINT *uProductType,
	       const TCHAR *ProductID, const TCHAR *DateStr, 
	       const TCHAR *CompanyName, TCHAR *NotifyTime,
	       support_timeval *time_end);

int
VerifyLicTimesEx(pCP_CALL_CTX pCallCtx, 
	         pCSP_HASH_FUNCS HashFuncs,
		 CPC_GetTimeOfDay_Callback get_time_of_day,
		 const SerialConfiguration *config,
		 int *expired_through_days, UINT *uProductType,
		 TCHAR *ProductIDOut, TCHAR *DateStrOut,
		 TCHAR *CompanyNameOut, CSP_BOOL CheckOnly, CSP_BOOL Server,
		 CSP_BOOL ReadOnly, support_timeval *time_end);

extern const TCHAR REG_LICENCEINFO_CSP30_UNIX[];
extern const TCHAR PARAM_PRODID[];
extern const TCHAR PARAM_DATA[];

#ifdef __cplusplus
}
#endif

#endif /* _SERIAL_H_INCLUDED */
/* end of file: $Id: serial.h 65593 2010-12-28 13:58:32Z raa $ */

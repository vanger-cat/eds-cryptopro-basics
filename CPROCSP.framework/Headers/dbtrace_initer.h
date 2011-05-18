/*
 * Copyright(C) 2004 Проект ИОК
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
 * \version $Revision: 42695 $
 * \date $Date: 2007-10-05 09:20:31 +0400 (РїС‚, 05 РѕРєС‚ 2007) $
 * \author $Author: dim $
 *
 * \brief Функции и макросы для отладочной печати.
 */

#ifndef _DBTRACE_INITER_H_INCLUDED
#define _DBTRACE_INITER_H_INCLUDED

#include<CPROCSP/reader/dprint.h>

class DbTraceInitializer
{
    TSupportDbContext ** m_ptr_db_ctx;
  public:
    DbTraceInitializer (const TCHAR *name, TSupportDbContext *& ref_db_ctx);
    ~DbTraceInitializer (void);
  private:
    DbTraceInitializer(const DbTraceInitializer&);
    DbTraceInitializer& operator=(const DbTraceInitializer&);
};

#endif /* _DBTRACE_INITER_H_INCLUDED */

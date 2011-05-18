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
 * \version $Revision: 57277 $
 * \date $Date: 2009-09-25 19:37:44 +0400 (РїС‚, 25 СЃРµРЅ 2009) $
 * \author $Author: raa $
 *
 * \brief Интерфейс к модулю генерации и изготовления серийного номера продукта.
 */

#ifndef _SERIAL_DEF_H_INCLUDED
#define _SERIAL_DEF_H_INCLUDED

// Размер даты в закодированном 5бит виде 
#define SERIAL_DATE_5BIT_DATE_LEN 13
// Размер хеш на дату
#define SERIAL_DATE_5BIT_HASH_LEN 52
// Размер полного поля дата 
#define SERIAL_DATE_5BIT_LEN (SERIAL_DATE_5BIT_DATE_LEN + SERIAL_DATE_5BIT_HASH_LEN)

// Максимальный размер имени компании
/* XXX test */
#ifdef LINUX 
#define SERIAL_COMPANY_MAX 20
#else
#define SERIAL_COMPANY_MAX 255
#endif

// Размер серийного номера
#define SERIAL_PRODUCTID_DATA_LEN 17
// Размер контрольной суммы серийного номера
#define SERIAL_PRODUCTID_CONTROL_LEN 8
// Полный размер серийного номера 
#define SERIAL_PRODUCTID_LEN (SERIAL_PRODUCTID_DATA_LEN+SERIAL_PRODUCTID_CONTROL_LEN)
// Размер серийного номера с -
#define SERIAL_PRODUCTID_DATA_DASH_LEN 20
// Размер контрольной суммы серийного номера с -
#define SERIAL_PRODUCTID_CONTROL_DASH_LEN 9
// Полный размер серийного номера с -
#define SERIAL_PRODUCTID_DASH_LEN (SERIAL_PRODUCTID_DATA_DASH_LEN + SERIAL_PRODUCTID_CONTROL_DASH_LEN )
// Маска файлов с лицензиями
#define LICENSE_FILES_MASK _TEXT("*.lic")

/* Лицензия, запрещающая всё, то есть неинициализированная. */
#define LIC_ALLOW_NOTHING   0
/* Флаг в лицензии, позволяющий подписывать. */
#define LIC_ALLOW_SIGN	    1<<0
/* Флаг в лицензии, позволяющий согласовывать ключи. */
#define LIC_ALLOW_DH	    1<<1
/* Флаг в лицензии, позволяющий зашифровывать. */
#define LIC_ALLOW_ENCRYPT   1<<2
/* Флаг в лицензии, позволяющий расшифровывать. */
#define LIC_ALLOW_DECRYPT   1<<3
/* Флаг в лицензии, позволяющий любые операции. */
#define LIC_ALLOW_ALL	    0xffff

#ifdef __cplusplus
extern "C" {
#endif

typedef struct SerialConfiguration_
{
    const TCHAR *PRODUCT_CODES;
    const unsigned *SECRET;
    size_t PRODUCT_LEN;
    const TCHAR *PRODUCT_ID;
    const TCHAR *PRODUCT_ID_PATH;
    const TCHAR *DATE_PATH;
    const TCHAR *LAST_SHOW_DIALOG_PATH;
#if defined _WIN32
    const TCHAR *SECRET_PATH;
#endif
} SerialConfiguration;

#ifdef __cplusplus
}
#endif


#endif /* _SERIAL_DEF_H_INCLUDED */

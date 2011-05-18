/* [Windows 1251]
 * [Use `iconv -f WINDOWS-1251', if needed]
 */
/*
 * Copyright(C) 2005-2011
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
 *
 * This is proprietary information of
 * Crypto-Pro company.
 *
 * Any part of this file can not be copied, 
 * corrected, translated into other languages,
 * localized or modified by any means,
 * compiled, transferred over a network from or to
 * any computer system without preliminary
 * agreement with Crypto-Pro company
 */

/*!
 * \version $Revision: 67479 $
 * \date $Date: 2011-04-14 17:24:49 +0400 (С‡С‚, 14 Р°РїСЂ 2011) $
 * \author $Author: dedal $
 *
 * \brief Интерфейс запросов на сертификат
 *
 */

#ifndef _UNIXENROLL_H
#define _UNIXENROLL_H

#include <string>
#include <memory>
#include <list>
#include <vector>
#include<CPROCSP/CSP_WinCrypt.h>
#include<CPROCSP/SecureBuffer.h>
#include<CPROCSP/BSTR.h>

#if __GNUC__==2
typedef std::basic_string <wchar_t> std::wstring;
#endif

// TODO:X Есть вероятность конфликта MonoTouch и пр. вероятно нужно 
// внести всё в namespace ru::CryptoPro

#define XECR_PKCS10_V2_0     0x1
#define XECR_PKCS7           0x2
#define XECR_CMC             0x3
#define XECR_PKCS10_V1_5     0x4

// BSTR SysAllocStringLen( const wchar_t *str, unsigned int cch);

// TODO:X cpcrypt_store_handle - приватный интерфейс, его следует 
// переместить в приватную часть UnixEnroll
struct cpcrypt_store_handle
{
    cpcrypt_store_handle(): store_(0), trust_(false) {}
    ~cpcrypt_store_handle();

    bool open(
	const std::wstring & store,
        bool issystem,
	unsigned long flags = CERT_STORE_OPEN_EXISTING_FLAG | CERT_STORE_READONLY_FLAG );

    bool open(
	const std::wstring & store,
	unsigned long flags = CERT_STORE_OPEN_EXISTING_FLAG | CERT_STORE_READONLY_FLAG | CERT_SYSTEM_STORE_CURRENT_USER);
    HANDLE store_;
    bool trust_;
private:
    // копирование запрещено
    cpcrypt_store_handle& operator=( const cpcrypt_store_handle& handle);
    cpcrypt_store_handle( const cpcrypt_store_handle& handle);
};

/*! \ingroup EnrollAPI
 *  \brief Создание запросов на сертификат и установка 
 *	   полученных сертификатов
 *
 *  \xmlonly <locfile><header>UnixEnroll.h</header> <ulib>libenroll.so</ulib></locfile>\endxmlonly
 * 
 * Является урезанным аналогом ICertEnroll из Microsoft CryptoAPI.
 */
class UnixEnroll
{
public:
    /*! \ingroup EnrollAPI
     *  \brief Интерфейс запросов пользователя
     *
     *  \xmlonly <locfile><header>UnixEnroll.h</header><ulib>libenroll.so</ulib></locfile>\endxmlonly
     */
    class UserCallbacks
    {
    public:
	/*! 
	 *  \brief Запрос на разрешение установки сертификата в 
	 *         хранилище доверенных сертификатов
	 *
	 *  \param pbCert   [in] Устанавливаемый сертификат
	 *  \param cbCert   [in] Длина сертификата
	 *
	 *  \return true - в случае согласия на установку сертификата
	 *
	 *  \note Реализовывать не обязательно, если используется 
	 *        put_SupressAddRootUI()
	 */
	virtual bool askPermissionToAddToRootStore( 
		const BYTE* pbCert, DWORD cbCert, bool = false) const=0;

	/*! 
	 *  \brief Клонирование
	 */
	virtual UserCallbacks* clone() const=0;

	/*! 
	 *  \brief Деструктор
	 */
	virtual ~UserCallbacks() {}
    };
public:
    /*! 
     *  \brief Конструктор
     *
     *  \param callbacks    [in] Функции запроса у пользователя
     *  \param handlePKCS7  [in] В данной версии не используется
     */
    UnixEnroll(
	const UserCallbacks& callbacks,
	bool handlePKCS7 = false);

    /*! 
     *  \fn UnixEnroll::~UnixEnroll
     *  \brief Деструктор
     */
    ~UnixEnroll();

    /*!
     *  \brief Установить атрибуты S/MIME в запрос PKCS#10 (не реализовано)
     *
     *  \param value	[in] TRUE - установить.
     *
     *	\return S_OK - в случае успеха 
     */
    HRESULT put_EnableSMIMECapabilities( bool value)
    { (void)(value); return S_OK; }
    
    /*! 
     *  \brief Использовать существующий ключ в контейнере (не реализовано)
     *
     *  \param value	[in] TRUE - существующий, FALSE - создать новый.
     *
     *	\return S_OK - в случае успеха 
     */
    HRESULT put_UseExistingKeySet(bool value);
    
    /*! 
     *  \brief Задать алгоритм хэш-функции для PKCS#10 (не реализовано)
     *
     *  \param hashOid	[in] OID хэш-функции.
     *
     *	\return S_OK - в случае успеха 
     */
    HRESULT put_HashAlgorithm( BSTR hashOid)
    { hashAlgorithm_ = hashOid; return S_OK; }
    
    /*! 
     *  \brief Задать имя контейнера
     *
     *  Если имя контейнера не задано, то оно генерируется как 
     *  случайный GUID. 
     *
     *  \param cName	[in] Имя контейнера.
     *
     *	\return S_OK - в случае успеха 
     *
     *  \note
     *  При использовании UseExistingKeySet, требуется
     *  задавать имя контейнера.
     */
    HRESULT put_ContainerName( BSTR cName)
    { containerName_ = cName; return S_OK; }
    
    /*! 
     *  \brief Задать тип CSP для создания ключа
     *
     *  Тип CSP определяет алгоритм закрытого ключа.
     *
     *  \param pType	[in] Тип CSP.
     *
     *	\return S_OK - в случае успеха 
     */
    HRESULT put_ProviderType( DWORD pType)
    { providerType_ = pType; return S_OK; }
    
    /*! 
     *  \brief Задать имя CSP для создания ключа
     *
     *  Определяет CSP в котором создаётся закрытый ключ.
     *
     *  \param pName	[in] Имя CSP.
     *
     *	\return S_OK - в случае успеха 
     */
    HRESULT put_ProviderName( BSTR pName)
    { providerName_ = pName; return S_OK; }
    
    /*! 
     *  \brief Задать свойства закрытого ключа
     *
     *  По умолчанию экспорт закрытого ключа запрещён, для его
     *  разрешения можно задать CRYPT_EXPORTABLE. 
     *
     *  \param keyFlags	[in] Флаги создания закрытого ключа.
     *
     *	\return S_OK - в случае успеха 
     *
     *  \note
     *  Полный список флагов смотри в описании CPGenKey() и CryptGenKey().
     */
    HRESULT put_GenKeyFlags( DWORD keyFlags)
    { keyFlags_ = keyFlags; return S_OK; }
    
    /*! 
     *  \brief Задать хранилище запроса и флаги его открытия 
     *
     *  Значение по умолчанию CERT_SYSTEM_STORE_CURRENT_USER.
     *
     *  \param storeFlags [in] Флаги открытия хранилища.
     *
     *	\return S_OK - в случае успеха 
     *
     *  \note
     *  Для Unix систем допустимые значения хранилищ:
     *	    - CERT_SYSTEM_STORE_CURRENT_USER
     *	    - CERT_SYSTEM_STORE_LOCAL_MACHINE
     *  
     *  Описания дополнительных флагов открытия хранилища 
     *  смотри в описании CertOpenStore().
     */
    HRESULT put_RequestStoreFlags( DWORD storeFlags)
    { requestStoreFlags_ = storeFlags; return S_OK; };
    
    /*! 
     *  \brief Задать флаги открытия CSP
     *
     *  Значение по умолчанию 0.
     *
     *  \param provFlags [in] Флаги открытия CSP.
     *
     *	\return S_OK - в случае успеха 
     *  
     *  \note
     *  Описания дополнительных флагов открытия CSP
     *  смотри в описании CPAcquireContext() и CryptAcquireContext().
     */
    HRESULT put_ProviderFlags( DWORD provFlags)
    { provFlags_ |= provFlags; /* TODO:XXX почему OR ??? */ return S_OK; }
    
    /*! 
     *  \brief Задать тип закрытого ключа
     *
     *  \param _dwKeySpec [in] Тип закрытого ключа.
     *
     *	\return S_OK - в случае успеха 
     *
     *  \note
     *  Обычно используемые типы:
     *	    - AT_KEYEXCHANGE - и согласование сессионных ключей 
     *		шифрования, и ЭЦП;
     *	    - AT_SIGNATURE - только ЭЦП;
     *  
     *  \note
     *  Смотри так же описания CPGenKey() и CryptGenKey().
     *
     *  \todo
     *  TODO:XXX В отличии от ICertEnroll нет значения по умолчанию ???
     */
    HRESULT put_KeySpec( DWORD _dwKeySpec)
    { dwKeySpec = _dwKeySpec; return S_OK; }
    
    /*! 
     *  \brief Задать ограничения ключа AT_KEYEXCHANGE
     *
     *  \param value [in] Ограничения ключа AT_KEYEXCHANGE.
     *
     *	\return S_OK - в случае успеха 
     *
     *  \note
     *  Это свойство относится только к ключам типа AT_KEYEXCHANGE. Для
     *  ключей типа AT_SIGNATURE его значение может быть произвольным.
     *
     *  \note
     *  Если значения свойства FALSE (0), то запрос содержит следующие 
     *  значение KeyUsage:
     *	    - CERT_DATA_ENCIPHERMENT_KEY_USAGE
     *	    - CERT_KEY_ENCIPHERMENT_KEY_USAGE
     *	    - CERT_DIGITAL_SIGNATURE_KEY_USAGE
     *	    - CERT_NON_REPUDIATION_KEY_USAGE
     *
     *  \note
     *  Если значения свойства TRUE (!=0), то запрос содержит следующие 
     *  значение KeyUsage:
     *	    - CERT_DATA_ENCIPHERMENT_KEY_USAGE
     *	    - CERT_KEY_ENCIPHERMENT_KEY_USAGE
     */
    HRESULT put_LimitExchangeKeyToEncipherment( int value)
    { limitExchangeKeyToEncipherment_ = value?true:false; return S_OK; }
    
    /*! 
     *  \brief Задать хранилище промежуточных УЦ и флаги его открытия 
     *
     *  Значение по умолчанию CERT_SYSTEM_STORE_CURRENT_USER.
     *
     *  \param flags [in] Флаги открытия хранилища.
     *
     *	\return S_OK - в случае успеха 
     *
     *  \note
     *  Для Unix систем допустимые значения хранилищ:
     *	    - CERT_SYSTEM_STORE_CURRENT_USER
     *	    - CERT_SYSTEM_STORE_LOCAL_MACHINE
     *  
     *  Описания дополнительных флагов открытия хранилища 
     *  смотри в описании CertOpenStore().
     */
    HRESULT put_CAStoreFlags( DWORD flags)
    { caStoreFlags_ = flags; return S_OK; }
    
    /*! 
     *  \brief Задать хранилище сертификатов пользователя и флаги 
     *		его открытия 
     *
     *  Значение по умолчанию CERT_SYSTEM_STORE_CURRENT_USER.
     *
     *  \param flags [in] Флаги открытия хранилища.
     *
     *	\return S_OK - в случае успеха 
     *
     *  \note
     *  Для Unix систем допустимые значения хранилищ:
     *	    - CERT_SYSTEM_STORE_CURRENT_USER
     *	    - CERT_SYSTEM_STORE_LOCAL_MACHINE
     *  
     *  Описания дополнительных флагов открытия хранилища 
     *  смотри в описании CertOpenStore().
     */
    HRESULT put_MyStoreFlags( DWORD flags)
    { myStoreFlags_ = flags; return S_OK;  }
    
    /*! 
     *  \brief Задать доверенное хранилище корневых сертификатов и 
     *		флаги его открытия 
     *
     *  Значение по умолчанию CERT_SYSTEM_STORE_CURRENT_USER.
     *
     *  \param flags [in] Флаги открытия хранилища.
     *
     *	\return S_OK - в случае успеха 
     *
     *  \note
     *  Для Unix систем допустимые значения хранилищ:
     *	    - CERT_SYSTEM_STORE_CURRENT_USER
     *	    - CERT_SYSTEM_STORE_LOCAL_MACHINE
     *  
     *  Описания дополнительных флагов открытия хранилища 
     *  смотри в описании CertOpenStore().
     */
    HRESULT put_RootStoreFlags( DWORD flags)
    { rootStoreFlags_ = flags; return S_OK;  }
    
    /*! 
     *  \brief Задать имя хранилища сертификатов пользователя
     *
     *  Значение по умолчанию "My".
     *
     *  \param name [in] Имя хранилища.
     *
     *	\return S_OK - в случае успеха 
     *
     *  \note
     *  Описания возможных имён хранилища 
     *  смотри в описании CertOpenStore().
     */
    HRESULT put_MyStoreName( BSTR name)
    { myStoreName_ = name; return S_OK;  }
    
    /*! 
     *  \brief Требуется ли удалять псевдосертификат в хранилище 
     *		запросов на сертификат
     *
     *  Значение по умолчанию true.
     *
     *  \param value [in] Требуется ли удалять.
     *
     *	\return S_OK - в случае успеха 
     *
     *  \note
     *  При создании ключа и запроса PKCS#10 создаётся псевдосертификат
     *  в хранилище запросов. Он служит для ссылки на закрытый ключ и др.
     *  до тех пор, пока УЦ не обработает запрос и не вернёт PKCS#7
     *  ответ. По получении PKCS#7 ответа и успешной установки 
     *  запрошенного сертификата, псевдосертификат удаляется. Однако,
     *  для целей отладки или тестирования можно запретить удаление 
     *  этого псевдосертификата установкой свойства DeleteRequestCert
     *  в значение false.
     */
    HRESULT put_DeleteRequestCert( bool value)
    { deleteRequest_ = value; return S_OK; }
    
    /*!
     *  \brief Требуется ли устанавливать сертификат в ключевой контейнер
     *
     *  Значение по умолчанию false.
     *  \todo TODO:XXX В отличии от ICertEnroll, у которого оно true ???
     *
     *  \param value [in] Требуется ли устанавливать.
     *
     *	\return S_OK - в случае успеха 
     *
     *  \note
     *  Установка сертификата в контейнер дополнительно к его 
     *  установке в хранилище "My", в основном, предназначено
     *  для отделяемых ключевых носителей. При задании значения true,
     *  происходит попытка записи сертификата в контейнер, но операция 
     *  не будет возвращать ошибку даже, если ключевой носитель не 
     *  сможет сохранить сертификат. В частности, если это значение
     *  true, но ключевой носитель (смарт-карта, USB-токен, 
     *  USB-флэш и т.п.) не подключен, то ошибки ключевого носителя 
     *  будут проигнорированны.
     * 
     *  \note
     *  Для того, что бы не вызывалась функция записи сертификата 
     *  требуется установить значение false.
     *
     *  \note
     *  Используется методами:
     *	    - acceptPKCS7()
     *
     *  \note
     *  Смотри также описания CPSetKeyParam() и CryptSetKeyParam().
     */
    HRESULT put_WriteCertToCSP( bool value)
    { writeToCSP_ = value; return S_OK; }
    
    /*!
     *  \brief Задать PIN (пароль) контейнера
     *
     *  Значение по умолчанию - не задан.
     *
     *  \param pin [in] PIN (пароль) контейнера.
     *
     *	\return S_OK - в случае успеха 
     *
     *  \note
     *  Задаёт PIN (пароль) для создании запроса или 
     *  получении сертификата для работы в режиме CRYPT_SILENT 
     *  (или при недоступности устройства текстового или графического 
     *  интерфейса пользователя (TUI или GUI)).
     */
    HRESULT put_PIN( const CSecurePin& pin)
    { pin_.copy(pin); return S_OK; }
    
    /*!
     *  \brief Не запрашивать подтверждения при установке корневого
     *		сертификата в хранилище доверенных сертификатов
     *
     *  Значение по умолчанию - false.
     *
     *  \param value [in] PIN (пароль) контейнера.
     *
     *	\return S_OK - в случае успеха 
     *
     *  \note
     *  При установке значения true, метод 
     *  UnixEnroll::askPermissionToAddToRootStore()
     *  не будет вызываться.
     */
    HRESULT put_SupressAddRootUI( bool value)
    { supressAddRootUi_ = value; return S_OK; }

    /*!
     *  \brief Добавить расширение в запрос на сертификат
     *
     *  \param flags [in] Является ли расширение критичным (critical)
     *  \param name  [in] OID расширения
     *  \param value [in] Расширение, закодированное в BASE64
     *
     *	\return S_OK - успешно
     *
     *  \note
     *  Метод createRequest() добавляет расширения в запрос, а метод
     *  createPKCS10() нет.
     */
    HRESULT addExtensionToRequest( LONG flags, BSTR name, BSTR value) {
        std::vector<BYTE> binary;
        HRESULT hr = UnixEnroll::getMessageFromBSTR(value,binary);
        if( S_OK != hr ) {
            return hr;
        }
        
        const char *oid = ConvertBSTRToString(name);
        
        extensions_.push_back(Extension(oid, flags, binary) );

        delete[] oid;
        
        return S_OK;
    }

    /*! 
     *  \brief Возвращает код ошибки при установке сертификата в 
     *		контейнер
     *
     *  \param pdwStatus [out] код ошибки при установке сертификата в 
     *				контейнер
     *
     *	\retval S_OK		успешно (в pdwStatus скопирован код 
     *				ошибки)
     *	\retval E_INVALIDARG	pdwStatus был не задан (==NULL)
     */
    HRESULT get_InstallToContainerStatus( DWORD *pdwStatus) {
        if(!pdwStatus) {
            return E_INVALIDARG;
        }
        *pdwStatus = installToContainerStatus_;
        return S_OK;
    }
    
    /*! 
     *  \brief Создать запрос PKCS#10
     *
     *  \param rdn     [in]  Различительное имя (DN) владельца ключа
     *  \param usage   [in]  Список OID расширенного использования 
     *			     ключа (Extended Key Usage (EKU))
     *  \param request [out] Запрос, закодированный в BASE64
     *
     *	\return S_OK - успешно
     *
     *  \note
     *  Игнорирует расширения заданные методом addExtensionToRequest()
     *
     *	\note
     *	Полученная BSTR строка запроса, должна быть освобождена 
     *  функцией SysFreeString()
     */
    HRESULT createPKCS10( BSTR rdn, BSTR usage, BSTR *request) {
        return createPKCSRequest(rdn, usage, request, false,false);
    }
    
    /*! \ingroup EnrollAPI
     *  \brief Создать запрос сертификат
     *
     *  \param flags   [in]  Тип запроса на сертификат
     *  \param rdn     [in]  Различительное имя (DN) владельца ключа
     *  \param usage   [in]  Список OID расширенного использования 
     *			     ключа (Extended Key Usage (EKU))
     *  \param request [out] Запрос, закодированный в BASE64
     *
     *	\return S_OK - успешно
     *
     *  \note
     *  Поддерживаются следующие типы запросов на сертификат:
     *	    - XECR_PKCS10_V1_5
     *	    - XECR_PKCS10_V2_0
     *
     *  \note
     *  Добавляет расширения заданные методом addExtensionToRequest()
     *
     *	\note
     *	Полученная BSTR строка запроса, должна быть освобождена 
     *  функцией SysFreeString()
     */
    HRESULT createRequest( LONG flags, BSTR rdn, BSTR usage, BSTR *request) {
        if( XECR_PKCS10_V2_0 == flags || XECR_PKCS10_V1_5 == flags ) {
            return createPKCSRequest(rdn, usage, request, true, false);
        } 
	else if (flags == XECR_PKCS7)
	{
            return createPKCSRequest(rdn, usage, request, true, true);
        }
	else
            return E_NOTIMPL;
    }
    
    /*! \ingroup EnrollAPI
     *  \brief Обработать PKCS#7 ответ от УЦ
     *
     *  \param msg [in] PKCS#7 сообщение, закодированное в BASE64, 
     *		        которое содержит сертификат или цепочку 
     *		        сертификатов соответствующую запросу
     *
     *	\return S_OK - успешно
     *
     *  \note
     *  Цепочка сертификатов, как может содержать корневой сертификат, 
     *  так и нет, в зависимости от политики конкретного УЦ. Сертификат,
     *  ссылающийся на созданный закрытый ключ из запроса, помещается
     *  в хранилище MY. Корневой сертификат помещается в хранилище
     *  ROOT, остальные сертификаты промежуточных УЦ помещаются в
     *  хранилище CA. Если в сообщение PKCS#7 встречается какой-либо
     *  корневой сертификат, то у пользователя запрашивается 
     *  подтверждение.
     *  Пользователь может запретить установку самоподписанных 
     *  сертификатов, которым он не доверяет по тем или иным причинам.
     *  Отказ пользователя в установке сертификатов в хранилище ROOT
     *  не вызывает отказа для всей операции.
     *
     *  \note
     *  По умолчанию используются хранилища: MY, CA, ROOT и REQUEST, 
     *  однако пользователь может изменить имена с помощью следующих 
     *  методов:
     *	    - put_MyStoreName()
     */
    HRESULT acceptPKCS7( BSTR msg);
     /*! \ingroup EnrollAPI
     *  \brief Установить сертификат или цепочку сертификатов PKCS#7
     *
     *  Метод installPKCS7Ex в отличии от acceptPKCS7 не предназначен
     *  для установки сертификатов, выпущенных по запросу пользователя.
     *  Он предназанчен просто для установки сертификата или цепочки
     *  в стандартные хранилища сертификатов.
     *
     *  \param msg [in] PKCS#7 сообщение, закодированное в BASE64, 
     *		        которое содержит сертификат или цепочку 
     *
     *  \param plCertEncoded [out] число сертификатов, 
     *		        установленных в локальные хранилища
     *
     *	\retval S_OK            успешно
     *	\retval ERROR_CANCELLED операция прервана пользователем 
     *
     *  \note
     *  Если в сообщение PKCS#7 встречается какой-либо
     *  корневой сертификат, то у пользователя запрашивается 
     *  подтверждение на его установку.
     */
    HRESULT installPKCS7Ex( BSTR msg, LONG * plCertInstalled);
     /*! \ingroup EnrollAPI
     *  \brief Установить сертификат, на котором будет подписан запрос в PKCS#7
     *  
     *
     *  \param pSignerCert  [in]  Информация о сертификате 
     *	\retval S_OK            успешно
     */
 
    HRESULT SetSignerCertificate(
      /* [in] */  PCCERT_CONTEXT pSignerCert
      );

private:
    static HRESULT getMessageFromBSTR( BSTR msg, std::vector<BYTE>& ret );
    HRESULT getCertificatesFromPKCS7(
	const BYTE* pbCert, DWORD cbCert,
	HCERTSTORE& hStore) const;
    HRESULT findCertificateInRequestStore(
	const BYTE* pbCert, DWORD cbCert,
	std::vector<BYTE>& foundedCert,
	cpcrypt_store_handle& store) const;
    HRESULT createCerificateContextFromRequestStore(
	const BYTE* pbCert, DWORD cbCert,
	PCCERT_CONTEXT& pCertContext,
	cpcrypt_store_handle& handle) const;
    HRESULT installCertificateToStore(
	PCCERT_CONTEXT pPrivateKeyCertContext,
	const BYTE* pbCert, DWORD cbCert);
    HRESULT processPKCS7(
	const BYTE* pbMsg, DWORD cbMsg,
	std::vector<BYTE>& certificate) const;
    HRESULT findRequestedCertificate(
	HCERTSTORE hStore,
	std::vector<BYTE>& certificate) const;
    HRESULT findIssuerOf(
	const BYTE* pbCert, DWORD cbCert,
	HCERTSTORE hStore,
	std::vector<BYTE>& issuer) const;
    bool isSelfSigned( const BYTE* pbCert, DWORD cbCert) const;
    HRESULT addCertificateToRootStore( const BYTE* pbCert, DWORD cbCert) const;
    HRESULT addCertificateToCAStore( const BYTE* pbCert, DWORD cbCert) const;
    HRESULT addCertificateToStore( const BYTE* pbCert, DWORD cbCert, cpcrypt_store_handle& store) const;
    std::string prepareKeyUsageString( const std::string& usage );
    HRESULT prepareKeyUsage(
	const std::string& usage, 
	std::vector<std::string>& usageArray);
    HRESULT createPKCSRequest( BSTR rdn, BSTR usage, BSTR *request, bool includeAddedExtensions,bool encodeToPKCS7);
    HRESULT encodeRequestToPKCS7(std::vector<BYTE>& Request); 

    HCRYPTPROV hProv;
    DWORD dwKeySpec;
    BSTR hashAlgorithm_;
    BSTR containerName_;
    DWORD providerType_;
    BSTR providerName_;
    DWORD keyFlags_;
    DWORD requestStoreFlags_;
    DWORD rootStoreFlags_;
    DWORD myStoreFlags_;
    DWORD caStoreFlags_;
    DWORD provFlags_;
    bool limitExchangeKeyToEncipherment_;
    BSTR myStoreName_;
    bool deleteRequest_;
    bool writeToCSP_;
    bool useExisting_;
    bool handlePKCS7_;
    std::auto_ptr<UserCallbacks> userCallbacks_;
    CSecurePin pin_;
    DWORD installToContainerStatus_;
    bool supressAddRootUi_;
    PCCERT_CONTEXT pSignerCertificate_;

    struct Extension {
        std::string oid;
        CSP_BOOL critical;
        std::vector<BYTE> value;

        Extension() {
        }

        Extension( 
            const char* argOid,
            LONG argCritical,
            const std::vector<BYTE>& argValue)
        : oid(argOid), critical(argCritical), value(argValue) {
        }
    };

    std::list<Extension> extensions_;
};

#endif /* _UNIXENROLL_H */

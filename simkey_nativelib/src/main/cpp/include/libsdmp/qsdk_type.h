#ifndef QSDK_TYPE_H
#define QSDK_TYPE_H

#define LEN_64TYTE		64
#define QSDK_LEN_64	64
#define QSDK_LEN_32	32
#define QSDK_MAX_STRING_LEN	128

#if(defined WIN32 || defined _WIN32 || defined WINCE)
#ifndef QSDK_EXPORT
#define QSDK_EXPORT _declspec(dllexport)
#endif
#else
#define QSDK_EXPORT 
#endif

/* 接口句柄 */
typedef void * SESSIONHANDLE;
typedef void * DHANDLE;
typedef void ** DHANDLES;

//错误码
#define QSDK_OK                                 0x0000
#define QSDK_ERR_CREATE_APP_CON                 0xB000 + 1
#define QSDK_ERR_IMPORT_KEY_PAIR                0xB000 + 2
#define QSDK_ERR_EXPORT_CERT_REQUEST            0xB000 + 3
#define QSDK_ERR_IMPORT_CRET                    0xB000 + 4
#define QSDK_ERR_WRITE_INIT_INFO                0xB000 + 5
#define QSDK_ERR_HTTP_CONNECT                   0xB000 + 6
#define QSDK_ERR_SIGN_DATA                      0xB000 + 7
#define QSDK_ERR_WRITE_KEY                      0xB000 + 8
#define QSDK_ERR_WRITE_KEY_UNIT                 0xB000 + 9
#define QSDK_ERR_DEVICE_SCAN                    0xB000 + 10
#define QSDK_ERR_SHORT_DEVICE_ID                0xB000 + 11
#define QSDK_ERR_EXPORT_CERT_REQUEST_LEN        0xB000 + 12
#define QSDK_ERR_INIT_RESOURCE                  0xB000 + 14
#define QSDK_ERR_UPDATE_RESOURCE                0xB000 + 15
#define QSDK_ERR_FIND_SYSTEM                    0xB000 + 16
#define QSDK_ERR_DELETE_INIT_INFO               0xB000 + 17
#define QSDK_ERR_DELETE_APP_CON                 0xB000 + 18
#define QSDK_ERR_PIN_INCORRECT                  0xB000 + 19
#define QSDK_ERR_PIN_LOCKED                     0xB000 + 20
#define QSDK_ERR_HTTP_CERT_NULL                 0xB000 + 21
#define QSDK_ERR_HTTP_RESPONSE_NULL             0xB000 + 22
#define QSDK_ERR_DELETE_TERMINAL_BIND_INFO		0xB000 + 23
#define QSDK_ERR_ADD_TERMINAL_BIND_INFO			0xB000 + 24
#define QSDK_ERR_SYNC_SYSTEM_TERMINAL_BIND_INFO	0xB000 + 25
#define QSDK_ERR_KEY_INJECT_ONLINE				0xB000 + 26
#define QSDK_ERR_QCARD_TIMEOUT					0xB000 + 27
#define QSDK_ERR_WRITE_TERM_CHECK_FLAG	0xB000 + 28
#define QSDK_ERR_RESET_PIN							0xB000 + 29
#define QSDK_ERR_FORMAT_USERPART				0xB000 + 30
#define QSDK_ERR_GET_FORMAT_PARAM			0xB000 + 31
#define QSDK_ERR_SYNC_AUDIT							0xB000 + 32
#define QSDK_ERR_AUDIT_NOT_FOUND				0xB000 + 33
#define QSDK_ERR_APPLY_EXISTED						0xB000 + 34
#define QSDK_ERR_KEY_QUERY							0xB000 + 35
#define QSDK_ERR_KEY_SPACENOTENOUGH		0xB000 + 36
#define QSDK_ERR_GET_DEV_CAPACITY				0xB000 + 37
#define QSDK_ERR_PIN_VERIFY_FAILED				0xB000 + 38
#define QSDK_ERR_NOT_SUPPORT_SYMMKEY		0xB000 + 39
#define QSDK_ERR_KEY_INJECT_SPACENOTENOUGH			0xB000 + 40
#define QSDK_ERR_GET_BATCH_FILL_QKEY_SIZE					0xB000 + 41
#define QSDK_ERR_DEVICE_HANDLE_EXPIRED						0xB000 + 42
#define QSDK_ERR_EXPORT_CERT_TIME								0xB000 + 43
#define QSDK_ERR_GET_DEVICE_INFO									0xB000 + 44
#define QSDK_ERR_RESCAN_DEVICE									0xB000 + 45
#define QSDK_ERR_CLEAR_QKEY											0xB000 + 46

#define QSDK_ERR_SESSION_NOTINIT								0xC000 + 1
#define QSDK_ERR_FIND_DEVICE										0xC000 + 2
#define QSDK_ERR_PARAM													0xC000 + 3

typedef struct _qsdk_http_login_param_t_
{
	char hostlocal[QSDK_MAX_STRING_LEN];				/* 服务器地址 */
	char user_name[QSDK_LEN_64];							/* 用户名 */
	char password[QSDK_LEN_64];							/* 密码 */
	unsigned int connect_timeout;								/* 连接超时时间 单位（s） 0-默认超时时间 非0-设置的超时时间值 */
	unsigned int timeout;											/* 请求超时时间 单位（s） 0-默认超时时间 非0-设置的超时时间值 */
}qsdk_http_login_param_t;

typedef struct _qsdk_http_login_result_t_
{
	int error_code;													/* 错误码 */
	char hostlocal[QSDK_MAX_STRING_LEN];				/* 服务器地址 */
	char msg[QSDK_MAX_STRING_LEN];					/* 信息 */
}qsdk_http_login_result_t;

typedef struct _qsdk_enum_device_result_t_
{
	int error_code;													/* 错误码 0-成功 非0-错误码 */
	char msg[QSDK_MAX_STRING_LEN];					/* 错误信息 */
	unsigned int dev_num;										/* 设备个数 */
}qsdk_enum_device_result_t;

typedef struct _qsdk_get_devid_result_t_
{
	int error_code;													/* 错误码 0-成功 非0-错误码 */
	char msg[QSDK_MAX_STRING_LEN];					/* 错误信息 */
	char dev_id[LEN_64TYTE];									/* 设备id */
}qsdk_get_devid_result_t;

typedef struct _qsdk_load_template_result_t_
{
	int error_code;													/* 错误码 0-成功 非0-错误码 */
	char msg[QSDK_MAX_STRING_LEN];					/* 错误信息 */
	char *template_str;												/* 证书模板，使用结束后free释放 */
}qsdk_load_template_result_t;

typedef struct _qsdk_cert_t_
{
	char user_pin[LEN_64TYTE];
	char user_id[LEN_64TYTE];
	char department[LEN_64TYTE];
	char department_id[QSDK_MAX_STRING_LEN];
	char company[LEN_64TYTE];
	char city[LEN_64TYTE];
	char province[LEN_64TYTE];
	char country[LEN_64TYTE];
}qsdk_cert_t;

typedef struct _qsdk_init_system_result_t_
{
	int error_code;													/* 错误码 0-成功 非0-错误码 */
	char msg[QSDK_MAX_STRING_LEN];					/* 错误信息 */
}qsdk_init_system_result_t;

typedef struct _qsdk_unbind_system_result_t_
{
	int error_code;													/* 错误码 0-成功 非0-错误码 */
	char msg[QSDK_MAX_STRING_LEN];					/* 错误信息 */
}qsdk_unbind_system_result_t;

typedef struct _qsdk_system_info_t_
{
	char system_id[LEN_64TYTE];								/* 系统ID */
	char system_name[LEN_64TYTE];							/* 系统名称 */
}qsdk_system_info_t;

typedef struct _qsdk_system_list_t_
{
	qsdk_system_info_t **system_info_list;					/* 使用结束后释放 */
	unsigned int system_len;
}qsdk_system_list_t;

typedef struct _qsdk_get_system_list_result_t_
{
	int error_code;													/* 错误码 0-成功 非0-错误码 */
	char msg[QSDK_MAX_STRING_LEN];					/* 错误信息 */
	qsdk_system_list_t system_list;								/* 系统列表 */
}qsdk_get_system_list_result_t;

#endif

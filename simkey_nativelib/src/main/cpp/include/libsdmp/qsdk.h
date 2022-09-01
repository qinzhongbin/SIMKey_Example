#ifndef QSDK_REPLY_H
#define QSDK_REPLY_H


#ifdef __cplusplus
extern "C" {
#endif


#include "qsdk_type.h"

//extern FILE *g_sdmp_log_fp;

QSDK_EXPORT int qsdk_test_log(char *path);
QSDK_EXPORT int qsdk_error_to_string(int error_code, char *path);


/*******************************************************************************
* Function: qsdk_session_init
* Description:启动会话
* Return: 成功返回 0
* Param:
*******************************************************************************/
QSDK_EXPORT int qsdk_session_init();

/*******************************************************************************
* Function: qsdk_session_deinit
* Description:结束会话
* Return: 成功返回 0
* Param:
*******************************************************************************/
QSDK_EXPORT void qsdk_session_deinit();

/*******************************************************************************
* Function: qsdk_login
* Description:登录服务器
* Return: 成功返回 0
* Param:
* @ login_param[in]:登录参数
* @ result[out]:登录结果
*******************************************************************************/
QSDK_EXPORT int qsdk_login(qsdk_http_login_param_t *login_param, qsdk_http_login_result_t *result);


/**
 * 获取登录后的token和cookie
 */
QSDK_EXPORT int qsdk_get_login_token_and_setCookie(char token[QSDK_MAX_STRING_LEN], char set_cookie[QSDK_MAX_STRING_LEN]);


/*******************************************************************************
* Function: qsdk_enum_device
* Description:枚举设备
* Return: 成功返回 0
* Param:
* @ result[out]:枚举结果
*******************************************************************************/
QSDK_EXPORT int qsdk_enum_device(qsdk_enum_device_result_t *result);

/*******************************************************************************
* Function: qsdk_get_device_id
* Description:获取设备ID
* Return: 成功返回 0
* Param:
* @ dev_index[in]:设备index
* @ result[out]:获取设备ID结果
*******************************************************************************/
QSDK_EXPORT int qsdk_get_device_id(int dev_index, qsdk_get_devid_result_t *result);

/*******************************************************************************
* Function: qsdk_load_template
* Description: 获取证书模板
* Return: 成功返回 0
* Param:
* @ result[out]: 证书模板获取结果
*******************************************************************************/
QSDK_EXPORT int qsdk_load_template(qsdk_load_template_result_t *result);

/*******************************************************************************
* Function: qsdk_device_init_system
* Description: 初始化新系统
* Return: 成功返回 0
* Param:
* @ device_id[in]:设备ID
* @ system_id[in]:系统ID
* @ system_cert[in]:证书信息
* @ result[out]:初始化新系统结果
*******************************************************************************/
QSDK_EXPORT int qsdk_device_init_system(char *device_id, char *system_id, qsdk_cert_t *system_cert,
                                        qsdk_init_system_result_t *result);

/*******************************************************************************
* Function: qsdk_device_unbind_system
* Description: 解绑系统
* Return: 成功返回 0
* Param:
* @ device_id[in]:设备ID
* @ system_id[in]:系统ID
* @ result[out]:解绑系统结果
*******************************************************************************/
QSDK_EXPORT int qsdk_device_unbind_system(char *device_id, char *system_id,
                                          qsdk_unbind_system_result_t *result);

/*******************************************************************************
* Function: qsdk_get_server_system_list
* Description: 获取服务端系统列表
* Return: 成功返回 0
* Param:
* @ device_id[in]:设备ID
* @ result[out]:服务端系统列表获取结果
*******************************************************************************/
QSDK_EXPORT int qsdk_get_server_system_list(char *device_id, qsdk_get_system_list_result_t *result);

/*******************************************************************************
* Function: qsdk_system_list_destroy
* Description: 销毁系统列表数据
* Return: void
* Param:
* @ system_list[in]:系统列表
*******************************************************************************/
QSDK_EXPORT void qsdk_system_list_destroy(qsdk_system_list_t *system_list);

#ifdef  __cplusplus
}
#endif

#endif

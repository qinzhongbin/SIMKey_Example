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
* Description:�����Ự
* Return: �ɹ����� 0
* Param:
*******************************************************************************/
QSDK_EXPORT int qsdk_session_init();

/*******************************************************************************
* Function: qsdk_session_deinit
* Description:�����Ự
* Return: �ɹ����� 0
* Param:
*******************************************************************************/
QSDK_EXPORT void qsdk_session_deinit();

/*******************************************************************************
* Function: qsdk_login
* Description:��¼������
* Return: �ɹ����� 0
* Param:
* @ login_param[in]:��¼����
* @ result[out]:��¼���
*******************************************************************************/
QSDK_EXPORT int qsdk_login(qsdk_http_login_param_t *login_param, qsdk_http_login_result_t *result);


/**
 * ��ȡ��¼���token��cookie
 */
QSDK_EXPORT int qsdk_get_login_token_and_setCookie(char token[QSDK_MAX_STRING_LEN], char set_cookie[QSDK_MAX_STRING_LEN]);


/*******************************************************************************
* Function: qsdk_enum_device
* Description:ö���豸
* Return: �ɹ����� 0
* Param:
* @ result[out]:ö�ٽ��
*******************************************************************************/
QSDK_EXPORT int qsdk_enum_device(qsdk_enum_device_result_t *result);

/*******************************************************************************
* Function: qsdk_get_device_id
* Description:��ȡ�豸ID
* Return: �ɹ����� 0
* Param:
* @ dev_index[in]:�豸index
* @ result[out]:��ȡ�豸ID���
*******************************************************************************/
QSDK_EXPORT int qsdk_get_device_id(int dev_index, qsdk_get_devid_result_t *result);

/*******************************************************************************
* Function: qsdk_load_template
* Description: ��ȡ֤��ģ��
* Return: �ɹ����� 0
* Param:
* @ result[out]: ֤��ģ���ȡ���
*******************************************************************************/
QSDK_EXPORT int qsdk_load_template(qsdk_load_template_result_t *result);

/*******************************************************************************
* Function: qsdk_device_init_system
* Description: ��ʼ����ϵͳ
* Return: �ɹ����� 0
* Param:
* @ device_id[in]:�豸ID
* @ system_id[in]:ϵͳID
* @ system_cert[in]:֤����Ϣ
* @ result[out]:��ʼ����ϵͳ���
*******************************************************************************/
QSDK_EXPORT int qsdk_device_init_system(char *device_id, char *system_id, qsdk_cert_t *system_cert,
                                        qsdk_init_system_result_t *result);

/*******************************************************************************
* Function: qsdk_device_unbind_system
* Description: ���ϵͳ
* Return: �ɹ����� 0
* Param:
* @ device_id[in]:�豸ID
* @ system_id[in]:ϵͳID
* @ result[out]:���ϵͳ���
*******************************************************************************/
QSDK_EXPORT int qsdk_device_unbind_system(char *device_id, char *system_id,
                                          qsdk_unbind_system_result_t *result);

/*******************************************************************************
* Function: qsdk_get_server_system_list
* Description: ��ȡ�����ϵͳ�б�
* Return: �ɹ����� 0
* Param:
* @ device_id[in]:�豸ID
* @ result[out]:�����ϵͳ�б��ȡ���
*******************************************************************************/
QSDK_EXPORT int qsdk_get_server_system_list(char *device_id, qsdk_get_system_list_result_t *result);

/*******************************************************************************
* Function: qsdk_system_list_destroy
* Description: ����ϵͳ�б�����
* Return: void
* Param:
* @ system_list[in]:ϵͳ�б�
*******************************************************************************/
QSDK_EXPORT void qsdk_system_list_destroy(qsdk_system_list_t *system_list);

#ifdef  __cplusplus
}
#endif

#endif

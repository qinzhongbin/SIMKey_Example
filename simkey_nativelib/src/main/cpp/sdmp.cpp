#include <jni.h>
#include <log.h>
#include <libsdmp/qsdk.h>
#include <cJSON.h>
#include <ctime>
#include <libqhid/qcard_log.h>
#include <curl/curl.h>
#include "libqhid/qcard.h"
#include "libqhid/qcard_store.h"

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_qasky_simkey_1nativelib_sdmp_SDMP_sessionInit(JNIEnv *env, jobject thiz) {
    int ret = qsdk_session_init();
    LOGD("SDMP_sessionInit ret = 0x%08x", ret);
    return !ret;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_qasky_simkey_1nativelib_sdmp_SDMP_sessionDeInit(JNIEnv *env, jobject thiz) {
    qsdk_session_deinit();
    LOGD("SDMP_sessionDeinit");
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_qasky_simkey_1nativelib_sdmp_SDMP_enumDevice(JNIEnv *env, jobject thiz) {
    qsdk_enum_device_result_t result;
    memset(&result, 0, sizeof(qsdk_enum_device_result_t));
    int ret = qsdk_enum_device(&result);
    LOGD("qsdk_enum_device ret = 0x%08x result.dev_num = %d", ret, result.dev_num);
    return result.dev_num;
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_qasky_simkey_1nativelib_sdmp_SDMP_getDeviceId(JNIEnv *env, jobject thiz, jint index) {
    qsdk_get_devid_result_t result;
    memset(&result, 0, sizeof(qsdk_get_devid_result_t));
    int ret = qsdk_get_device_id(index, &result);
    LOGD("qsdk_get_device_id ret = 0x%08x result.dev_id = %s", ret, result.dev_id);
    return env->NewStringUTF(result.dev_id);
}

extern "C"
{
void QCard_LogSetCallBack(void (*cb)(int level, char *msg), int lverror, int lvwarn, int lvinfo, int lvdebug, int lvtrace);
}

void debug_print(int level, char *msg) {
    LOGE("%d:%s", level, msg);
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_qasky_simkey_1nativelib_sdmp_SDMP_login(JNIEnv *env, jobject thiz, jstring _host, jstring user_name, jstring _pwd) {

    QCard_LogSetCallBack(debug_print, 1, 2, 3, 4, 5);

    const char *host = env->GetStringUTFChars(_host, JNI_FALSE);
    const char *userName = env->GetStringUTFChars(user_name, JNI_FALSE);
    const char *pwd = env->GetStringUTFChars(_pwd, JNI_FALSE);

    qsdk_http_login_param_t param;
    qsdk_http_login_result_t result;
    memset(&param, 0, sizeof(qsdk_http_login_param_t));
    memset(&result, 0, sizeof(qsdk_http_login_result_t));
    param.connect_timeout = 6;
    strcpy(param.hostlocal, host);
    strcpy(param.user_name, userName);
    strcpy(param.password, pwd);

    int ret = qsdk_login(&param, &result);
    LOGD("qsdk_login ret = 0x%08x result.msg = %s", ret, result.msg);

    env->ReleaseStringUTFChars(_host, host);
    env->ReleaseStringUTFChars(user_name, userName);
    env->ReleaseStringUTFChars(_pwd, pwd);
    return !ret;
}

//extern "C"
//JNIEXPORT jstring JNICALL
//Java_com_qasky_simkey_1nativelib_sdmp_SDMP_getTokenAndCookie(JNIEnv *env, jobject thiz) {
//    char token[QSDK_MAX_STRING_LEN];
//    char cookie[QSDK_MAX_STRING_LEN];
//    int ret = qsdk_get_login_token_and_setCookie(token, cookie);
//    LOGD("qsdk_get_login_token_and_setCookie ret = 0x%08x token = %s cookie = %s", ret, token, cookie);
//
//    char dest[QSDK_MAX_STRING_LEN];
//    sprintf(dest, "%s,%s", token, cookie);
//    LOGD("qsdk_get_login_token_and_setCookie dest = %s", dest);
//
//    return env->NewStringUTF(dest);
//}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_qasky_simkey_1nativelib_sdmp_SDMP_loadTemplate(JNIEnv *env, jobject thiz) {
    qsdk_load_template_result_t result;
    memset(&result, 0, sizeof(qsdk_load_template_result_t));
    int ret = qsdk_load_template(&result);
    LOGD("qsdk_load_template ret = 0x%08x", ret);
//    LOGD("qsdk_load_template template = \n%s", result.template_str);
    jstring temp = env->NewStringUTF(result.template_str);
    free(result.template_str);
    return temp;
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_qasky_simkey_1nativelib_sdmp_SDMP_getServerSystemList(JNIEnv *env, jobject thiz, jstring dev_id) {
    char *devId = const_cast<char *>(env->GetStringUTFChars(dev_id, JNI_FALSE));
    qsdk_get_system_list_result_t result;
    memset(&result, 0, sizeof(qsdk_get_system_list_result_t));
    int ret = qsdk_get_server_system_list(devId, &result);
    LOGD("qsdk_get_server_system_list ret = 0x%08x", ret);

    cJSON *Json_OBJ_Result = cJSON_CreateObject();
    cJSON_AddNumberToObject(Json_OBJ_Result, "error_code", result.error_code);
    cJSON_AddStringToObject(Json_OBJ_Result, "msg", result.msg);
    cJSON *JSON_ARY_SYSTEM = cJSON_AddArrayToObject(Json_OBJ_Result, "system_list");

    for (int i = 0; i < result.system_list.system_len; ++i) {
        qsdk_system_info_t *systemInfo = result.system_list.system_info_list[i];
        cJSON *JSON_OBJ_SYSTEM = cJSON_CreateObject();
        cJSON_AddStringToObject(JSON_OBJ_SYSTEM, "system_id", systemInfo->system_id);
        cJSON_AddStringToObject(JSON_OBJ_SYSTEM, "system_name", systemInfo->system_name);
        cJSON_AddItemToArray(JSON_ARY_SYSTEM, JSON_OBJ_SYSTEM);
    }
    char *json = cJSON_Print(Json_OBJ_Result);
//    LOGD("qsdk_get_server_system_list system_list = \n%s", json);
    cJSON_Delete(Json_OBJ_Result);
    qsdk_system_list_destroy(&result.system_list);
    env->ReleaseStringUTFChars(dev_id, devId);
    return env->NewStringUTF(json);
}

extern "C"
JNIEXPORT jobject JNICALL
Java_com_qasky_simkey_1nativelib_sdmp_SDMP_initSystem(JNIEnv *env, jobject thiz, jstring dev_id, jstring sys_id, jobject _cert) {
    char *devId = const_cast<char *>(env->GetStringUTFChars(dev_id, JNI_FALSE));
    char *sysId = const_cast<char *>(env->GetStringUTFChars(sys_id, JNI_FALSE));
    qsdk_cert_t cert;
    memset(&cert, 0, sizeof(qsdk_cert_t));
    qsdk_init_system_result_t result;
    memset(&result, 0, sizeof(qsdk_init_system_result_t));
    jclass jclz_Cert = env->GetObjectClass(_cert);
    auto userPin = (jstring) env->GetObjectField(_cert, env->GetFieldID(jclz_Cert, "userPIN", "Ljava/lang/String;"));
    auto userId = (jstring) env->GetObjectField(_cert, env->GetFieldID(jclz_Cert, "userId", "Ljava/lang/String;"));
    auto department = (jstring) env->GetObjectField(_cert, env->GetFieldID(jclz_Cert, "department", "Ljava/lang/String;"));
    auto departmentId = (jstring) env->GetObjectField(_cert, env->GetFieldID(jclz_Cert, "departmentId", "Ljava/lang/String;"));
    auto company = (jstring) env->GetObjectField(_cert, env->GetFieldID(jclz_Cert, "company", "Ljava/lang/String;"));
    auto city = (jstring) env->GetObjectField(_cert, env->GetFieldID(jclz_Cert, "city", "Ljava/lang/String;"));
    auto province = (jstring) env->GetObjectField(_cert, env->GetFieldID(jclz_Cert, "province", "Ljava/lang/String;"));
    auto country = (jstring) env->GetObjectField(_cert, env->GetFieldID(jclz_Cert, "country", "Ljava/lang/String;"));
    strcpy(cert.user_pin, env->GetStringUTFChars(userPin, JNI_FALSE));
    strcpy(cert.user_id, env->GetStringUTFChars(userId, JNI_FALSE));
    strcpy(cert.department, env->GetStringUTFChars(department, JNI_FALSE));
    strcpy(cert.department_id, env->GetStringUTFChars(departmentId, JNI_FALSE));
    strcpy(cert.company, env->GetStringUTFChars(company, JNI_FALSE));
    strcpy(cert.city, env->GetStringUTFChars(city, JNI_FALSE));
    strcpy(cert.province, env->GetStringUTFChars(province, JNI_FALSE));
    strcpy(cert.country, env->GetStringUTFChars(country, JNI_FALSE));

    LOGD("devId = %s", devId);
    LOGD("sysId = %s", sysId);
    LOGD("cert.user_pin = %s", cert.user_pin);
    LOGD("cert.country = %s", cert.country);
    LOGD("cert.province = %s", cert.province);
    LOGD("cert.city = %s", cert.city);
    LOGD("cert.company = %s", cert.company);
    LOGD("cert.department_id = %s", cert.department_id);
    LOGD("cert.department = %s", cert.department);
    LOGD("cert.user_id = %s", cert.user_id);
    int ret = qsdk_device_init_system(devId, sysId, &cert, &result);
    LOGD("qsdk_device_init_system ret = 0x%08x result.error_code = 0x%08x result.msg = %s", ret, result.error_code, result.msg);

    jclass clz_Result = env->FindClass("com/qasky/simkey_nativelib/sdmp/Result");
    jobject obj_result = env->NewObject(clz_Result, env->GetMethodID(clz_Result, "<init>", "()V"));
    env->SetIntField(obj_result, env->GetFieldID(clz_Result, "error_code", "I"), result.error_code);
    env->SetObjectField(obj_result, env->GetFieldID(clz_Result, "msg", "Ljava/lang/String;"), env->NewStringUTF(result.msg));

    env->ReleaseStringUTFChars(dev_id, devId);
    env->ReleaseStringUTFChars(sys_id, sysId);
    return obj_result;
}

extern "C"
JNIEXPORT jobject JNICALL
Java_com_qasky_simkey_1nativelib_sdmp_SDMP_unbindSystem(JNIEnv *env, jobject thiz, jstring device_id, jstring system_id) {
    char *devId = const_cast<char *>(env->GetStringUTFChars(device_id, JNI_FALSE));
    char *sysId = const_cast<char *>(env->GetStringUTFChars(system_id, JNI_FALSE));
    qsdk_unbind_system_result_t result;
    memset(&result, 0, sizeof(result));

    int ret = qsdk_device_unbind_system(devId, sysId, &result);
    LOGD("qsdk_device_unbind_system ret = 0x%08x result.error_code = 0x%08x result.msg = %s", ret, result.error_code, result.msg);

    jclass clz_Result = env->FindClass("com/qasky/simkey_nativelib/sdmp/Result");
    jobject obj_result = env->NewObject(clz_Result, env->GetMethodID(clz_Result, "<init>", "()V"));
    env->SetIntField(obj_result, env->GetFieldID(clz_Result, "error_code", "I"), result.error_code);
    env->SetObjectField(obj_result, env->GetFieldID(clz_Result, "msg", "Ljava/lang/String;"), env->NewStringUTF(result.msg));

    env->ReleaseStringUTFChars(device_id, devId);
    env->ReleaseStringUTFChars(system_id, sysId);
    return obj_result;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_qasky_simkey_1nativelib_sdmp_SDMP_test(JNIEnv *env, jobject thiz) {
//        int ret = 0;
//        char hostlocal[QSDK_MAX_STRING_LEN] = "112.27.97.202:8890";
//        char user_name[] = "qzb";
//        char pwd[] = "QaSky1234";
//        qsdk_http_login_param_t login_param;
//        qsdk_http_login_result_t result;
//        qsdk_enum_device_result_t enum_result;
//        qsdk_get_devid_result_t devid_result;
//        qsdk_load_template_result_t template_result;
//        qsdk_cert_t system_cert;
//        qsdk_get_system_list_result_t get_syslist_result;
//        qsdk_system_info_t **syslist;
//        qsdk_init_system_result_t init_result;
//        qsdk_unbind_system_result_t unbind_result;
//
//        memset(&login_param, 0, sizeof(qsdk_http_login_param_t));
//        login_param.connect_timeout = 6;
//        memcpy(login_param.hostlocal, hostlocal, strlen(hostlocal));
//        memcpy(login_param.user_name, user_name, strlen(user_name));
//        memcpy(login_param.password, pwd, strlen(pwd));
//
//        qsdk_session_init();
//
//
//        /* 登录 */
//        memset(&result, 0, sizeof(qsdk_http_login_result_t));
//        ret = qsdk_login(&login_param, &result);
//        if(0 != ret)
//        {
//            LOGD("[%d] [%s] failed! ret@%d error_code@0x%x msg[%s] \n", __LINE__, "qsdk_login", ret, result.error_code, result.msg);
//            qsdk_session_deinit();
//            return -1;
//        }
//
//        /* 枚举设备 */
//        memset(&enum_result, 0, sizeof(qsdk_enum_device_result_t));
//        ret = qsdk_enum_device(&enum_result);
//        if(0 != ret)
//        {
//            LOGD("[%d] [%s] failed! ret@%d error_code@0x%x msg[%s] \n", __LINE__, "qsdk_enum_device", ret, enum_result.error_code, enum_result.msg);
//            qsdk_session_deinit();
//            return -1;
//        }
//
//        /* 获取设备0的设备ID */
//        memset(&devid_result, 0, sizeof(qsdk_get_devid_result_t));
//        ret = qsdk_get_device_id(0, &devid_result);
//        if(0 != ret)
//        {
//            LOGD("[%d] [%s] failed! ret@%d error_code@0x%x msg[%s] \n", __LINE__, "qsdk_get_device_id", ret, devid_result.error_code, devid_result.msg);
//            qsdk_session_deinit();
//            return -1;
//        }
//
//        /* 获取证书模板 */
//        memset(&template_result, 0, sizeof(qsdk_load_template_result_t));
//        ret = qsdk_load_template(&template_result);
//        if(0 != ret)
//        {
//            LOGD("[%d] [%s] failed! ret@%d error_code@0x%x msg[%s] \n", __LINE__, "qsdk_load_template", ret, template_result.error_code, template_result.msg);
//            qsdk_session_deinit();
//            return -1;
//        }
//        //LOGD("%s %d template_str is %s\n", __FUNCTION__,__LINE__,template_result.template_str);
//        free(template_result.template_str);
//
//        /* 获取服务端系统列表 */
//        memset(&get_syslist_result, 0, sizeof(qsdk_get_system_list_result_t));
//        ret = qsdk_get_server_system_list(devid_result.dev_id, &get_syslist_result);
//        if(0 != ret)
//        {
//            LOGD("[%d] [%s] failed! ret@%d error_code@0x%x msg[%s] \n", __LINE__, "qsdk_get_server_system_list", ret, template_result.error_code, template_result.msg);
//            qsdk_session_deinit();
//            return -1;
//        }
//        syslist = get_syslist_result.system_list.system_info_list;
//
//        /* 初始化新系统 */
//        memset(&system_cert, 1, sizeof(qsdk_cert_t));
//        strcpy(system_cert.user_pin, "20191818");
//        snprintf(system_cert.user_id, LEN_64TYTE, "test_%u", time(NULL));
//        //strcpy(system_cert.user_id, "test_init");
//        strcpy(system_cert.department, "软件部");
//        strcpy(system_cert.department_id, "0fd2260c15e7409f88900d58826b2c70");
//        strcpy(system_cert.company, "qasky");
//        strcpy(system_cert.city, "wuhu");
//        strcpy(system_cert.province, "anhui");
//        strcpy(system_cert.country, "China");
//
//        memset(&init_result, 0, sizeof(qsdk_init_system_result_t));
//
//
//        ret = qsdk_device_init_system(devid_result.dev_id, "000000056", &system_cert, &init_result);
//        if(0 != ret)
//        {
//            LOGD("[%d] [%s] failed! ret@%d error_code@0x%x msg[%s] \n", __LINE__, "qsdk_device_init_system", ret, init_result.error_code, init_result.msg);
//            qsdk_system_list_destroy(&(get_syslist_result.system_list));
//            qsdk_session_deinit();
//            return -1;
//        }
//
//        LOGD("%s %d \n", __FUNCTION__,__LINE__);
//
//        qsdk_system_list_destroy(&(get_syslist_result.system_list));
//
//        qsdk_session_deinit();
//
//
//        return 0;


    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "http://www.baidu.com/");

#ifdef SKIP_PEER_VERIFICATION
        /*
     * If you want to connect to a site who isn't using a certificate that is
     * signed by one of the certs in the CA bundle you have, you can skip the
     * verification of the server's certificate. This makes the connection
     * A LOT LESS SECURE.
     *
     * If you have a CA cert for the server stored someplace else than in the
     * default bundle, then the CURLOPT_CAPATH option might come handy for
     * you.
     */
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
#endif
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
#ifdef SKIP_HOSTNAME_VERIFICATION
        /*
     * If the site you're connecting to uses a different host name that what
     * they have mentioned in their server certificate's commonName (or
     * subjectAltName) fields, libcurl will refuse to connect. You can skip
     * this check, but this will make the connection less secure.
     */
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
#endif
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        /* Perform the request, res will get the return code */
        res = curl_easy_perform(curl);
        /* Check for errors */
        if (res != CURLE_OK)
            LOGD("curl_easy_perform() failed: %s\n", curl_easy_strerror(res));


        LOGD("++++++++++++++");
        /* always cleanup */
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    return 0;

}

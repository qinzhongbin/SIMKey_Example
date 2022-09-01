#include <jni.h>
#include <string>
#include <libqhid/qcard.h>
#include <log.h>
#include <skfapi.h>
#include <libqhid/qcard_skf.h>
#include <libqhid/qcard_store.h>

QHANDLES devHandles;
QHANDLE devHandle;

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_qasky_simkey_1nativelib_qcard_QCard_enumDevice(JNIEnv *env, jobject thiz) {
    int ret = QCard_EnumStoreHandle(&devHandles);
    LOGD("QCard_EnumStoreHandle ret = 0x%08x", ret);

    if (ret > 0) {
        devHandle = devHandles[0];
    }

    return ret > 0;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_qasky_simkey_1nativelib_qcard_QCard_freeDevices(JNIEnv *env, jobject thiz) {
    QCard_FreeStoreHandle(devHandles);
    LOGD("QCard_FreeStoreHandle");
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_qasky_simkey_1nativelib_qcard_QCard_loginDevice(JNIEnv *env, jobject thiz) {
    int ret = QCard_Login(devHandle);
    LOGD("QCard_Login ret = 0x%08x", ret);
    return !ret;
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_qasky_simkey_1nativelib_qcard_QCard_logoutDevice(JNIEnv *env, jobject thiz) {
    int ret = QCard_Logout(devHandle);
    LOGD("QCard_Logout ret = 0x%08x", ret);
    return !ret;
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_qasky_simkey_1nativelib_qcard_QCard_initResource(JNIEnv *env, jobject thiz) {
    int ret = QCard_InitResource(devHandle);
    LOGD("QCard_InitResource ret = 0x%08x", ret);
    return !ret;
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_qasky_simkey_1nativelib_qcard_QCard_updateResource(JNIEnv *env, jobject thiz) {
    int ret = QCard_UpdateResource(devHandle);
    LOGD("QCard_UpdateResource ret = 0x%08x", ret);
    return !ret;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_qasky_simkey_1nativelib_qcard_QCard_destroyResource(JNIEnv *env, jobject thiz) {
    QCard_DestoryResource(devHandle);
    LOGD("QCard_DestoryResource");
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_qasky_simkey_1nativelib_qcard_QCard_getDeviceId(JNIEnv *env, jobject thiz) {
    char storeId[64] = {0};
    int ret = QCard_GetStoreId(devHandle, storeId);
    LOGD("QCard_GetStoreId ret = 0x%08x storeId = %s", ret, storeId);
    return env->NewStringUTF(storeId);
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_qasky_simkey_1nativelib_qcard_QCard_getSystemId(JNIEnv *env, jobject thiz, jstring app_name, jstring con_name) {
    char *appName = const_cast<char *>(env->GetStringUTFChars(app_name, JNI_FALSE));
    char *conName = const_cast<char *>(env->GetStringUTFChars(con_name, JNI_FALSE));
    char systemId[64] = {0};
    int ret = QCard_GetSysTemId(devHandle, appName, conName, systemId);
    LOGD("QCard_GetSysTemId ret = 0x%08x systemId = %s", ret, systemId);
    env->ReleaseStringUTFChars(app_name, appName);
    env->ReleaseStringUTFChars(con_name, conName);
    return env->NewStringUTF(systemId);
}

extern "C"
JNIEXPORT jobject JNICALL
Java_com_qasky_simkey_1nativelib_qcard_QCard_getAppList(JNIEnv *env, jobject thiz) {
    QCard_APPLIST qCardApplist;
    memset(&qCardApplist, 0, sizeof(QCard_APPLIST));
    int ret = QCard_GetAppInfo(devHandle, &qCardApplist);
    LOGD("Qcard_GetAppInfo ret = 0x%08x", ret);

    char names[128];

    jclass jclz_ArrayList = env->FindClass("java/util/ArrayList");
    jobject jobj_ArrayList = env->NewObject(jclz_ArrayList, env->GetMethodID(jclz_ArrayList, "<init>", "()V"));
    jclass jclz_App = env->FindClass("com/qasky/simkey_nativelib/qcard/Application");

    for (int i = 0; i < qCardApplist.Length; ++i) {
        char *app = qCardApplist.pApplications[i].AppName;
        char *con = qCardApplist.pApplications[i].pContainers[0].ConName;
        jobject jobj_app = env->NewObject(jclz_App, env->GetMethodID(jclz_App, "<init>", "(Ljava/lang/String;Ljava/lang/String;)V"), env->NewStringUTF(app), env->NewStringUTF(con));
        env->CallBooleanMethod(jobj_ArrayList, env->GetMethodID(jclz_ArrayList, "add", "(Ljava/lang/Object;)Z"), jobj_app);
    }
    return jobj_ArrayList;
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_qasky_simkey_1nativelib_qcard_QCard_deleteApp(JNIEnv *env, jobject thiz, jstring app_name) {
    char *appName = const_cast<char *>(env->GetStringUTFChars(app_name, JNI_FALSE));
    int ret = QCard_DelectApp(devHandle, appName);
    LOGD("QCard_DelectApp ret = 0x%08x", ret);
    return !ret;
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_qasky_simkey_1nativelib_qcard_QCard_formatDevice(JNIEnv *env, jobject thiz) {
    int ret = QCard_FormatDevice(devHandle, 1);
    LOGD("QCard_FormatDevice ret = 0x%08x", ret);
    return !ret;
}


extern "C"
JNIEXPORT jlongArray JNICALL
Java_com_qasky_simkey_1nativelib_qcard_QCard_queryKeyLength(JNIEnv *env, jobject thiz, jstring app_name, jstring con_name) {
    char *appName = const_cast<char *>(env->GetStringUTFChars(app_name, JNI_FALSE));
    char *conName = const_cast<char *>(env->GetStringUTFChars(con_name, JNI_FALSE));
    unsigned long totalLen;
    unsigned long usedLen;
    char devId[64] = {0};
    int ret = 0;

    ret = QCard_GetStoreId(devHandle, devId);
    LOGD("QCard_GetStoreId ret = 0x%08x devId = %s", ret, devId);

    ret = QCard_QueryKey(devHandle, devId, appName, conName, &totalLen, &usedLen);
    LOGD("QCard_QueryKey ret = 0x%08x totalLen = %lu usedLen = %lu", ret, totalLen, usedLen);

    jlong KeyLenList[2];
    KeyLenList[0] = totalLen;
    KeyLenList[1] = usedLen;

    jlongArray longArray = env->NewLongArray(2);
    env->SetLongArrayRegion(longArray, 0, 2, KeyLenList);
    env->ReleaseStringUTFChars(app_name, appName);
    env->ReleaseStringUTFChars(con_name, conName);
    return longArray;
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_qasky_simkey_1nativelib_qcard_QCard_chargeKey(JNIEnv *env, jobject thiz, jstring _host, jstring app_name, jstring con_name, jstring user_pin) {
    char *host = const_cast<char *>(env->GetStringUTFChars(_host, JNI_FALSE));
    char *appName = const_cast<char *>(env->GetStringUTFChars(app_name, JNI_FALSE));
    char *conName = const_cast<char *>(env->GetStringUTFChars(con_name, JNI_FALSE));
    char *userPIN = const_cast<char *>(env->GetStringUTFChars(user_pin, JNI_FALSE));



//    QCard_SetSSL(0);


    int ret = QCard_ProxyOnlineChargingKey(devHandle, host, appName, conName, userPIN, 32);
    LOGD("QCard_ProxyOnlineChargingKey ret = 0x%08x", ret);

    env->ReleaseStringUTFChars(_host, host);
    env->ReleaseStringUTFChars(app_name, appName);
    env->ReleaseStringUTFChars(con_name, conName);
    env->ReleaseStringUTFChars(user_pin, userPIN);

    return !ret;
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_qasky_simkey_1nativelib_qcard_QCard_clearKey(JNIEnv *env, jobject thiz, jstring app_name) {
    char *appName = const_cast<char *>(env->GetStringUTFChars(app_name, JNI_FALSE));
    int ret = QCard_ClearAppKey(devHandle, appName);
    LOGD("QCard_ClearAppKey ret = 0x%08x", ret);
    return !ret;
}

extern "C"
JNIEXPORT jlong JNICALL
Java_com_qasky_simkey_1nativelib_qcard_QCard_getKeyHandle(JNIEnv *env, jobject thiz, jstring app_name, jstring con_name, jstring user_pin, jstring check_code, jstring _flag) {
    char *appName = const_cast<char *>(env->GetStringUTFChars(app_name, JNI_FALSE));
    char *conName = const_cast<char *>(env->GetStringUTFChars(con_name, JNI_FALSE));
    char *userPin = const_cast<char *>(env->GetStringUTFChars(user_pin, JNI_FALSE));
    char *checkCode = const_cast<char *>(env->GetStringUTFChars(check_code, JNI_FALSE));
    char *flag = const_cast<char *>(env->GetStringUTFChars(_flag, JNI_FALSE));
    QCard_BLOCKCIPHERPARAM KeyParam;
    memset(&KeyParam, 0, sizeof(KeyParam));
    KeyParam.PaddingType = 1;
    KEYHANDLE keyHandle = nullptr;

    unsigned long totalLen;
    unsigned long usedLen;
    char devId[64] = {0};
    int ret = 0;

    ret = QCard_GetStoreId(devHandle, devId);
    LOGD("QCard_GetStoreId ret = 0x%08x devId = %s", ret, devId);

    ret = QCard_QueryKey(devHandle, devId, appName, conName, &totalLen, &usedLen);
    LOGD("QCard_QueryKey ret = 0x%08x totalLen = %lu usedLen = %lu", ret, totalLen, usedLen);

    LOGD("appName = %s", appName);
    LOGD("conName = %s", conName);
    LOGD("userPin = %s", userPin);
    LOGD("checkCode = %s", checkCode);
    LOGD("flag = %s", flag);

    ret = QCard_ClientKeyInit(devHandle, checkCode, flag, SGD_SMS4_ECB, KeyParam, appName, conName, userPin, TAC_SAFE_CLEARR, &keyHandle);
    LOGD("QCard_ClientKeyInit ret = 0x%08x keyHandle = %p", ret, keyHandle);

    env->ReleaseStringUTFChars(app_name, appName);
    env->ReleaseStringUTFChars(con_name, conName);
    env->ReleaseStringUTFChars(user_pin, userPin);
    env->ReleaseStringUTFChars(check_code, checkCode);
    env->ReleaseStringUTFChars(_flag, flag);
    return reinterpret_cast<jlong>(keyHandle);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_qasky_simkey_1nativelib_qcard_QCard_freeKeyHandle(JNIEnv *env, jobject thiz, jlong key_handle) {
    QCard_KeyFinal(devHandle, reinterpret_cast<KEYHANDLE>(key_handle));
    LOGD("QCard_KeyFinal");
}

extern "C"
JNIEXPORT jbyteArray JNICALL
Java_com_qasky_simkey_1nativelib_qcard_QCard_encrypt(JNIEnv *env, jobject thiz, jlong key_handle, jbyteArray plain) {
    long srcLen = env->GetArrayLength(plain);
    jbyte *src = env->GetByteArrayElements(plain, JNI_FALSE);
    auto *srcData = (unsigned char *) src;
    unsigned long destLen = srcLen + 16;
    unsigned char destData[destLen];
    memset(destData, 0, destLen);

    int ret = QCard_Encrypt(devHandle, reinterpret_cast<KEYHANDLE>(key_handle), srcData, srcLen, destData, &destLen);
    LOGD("QCard_Encrypt ret = 0x%08x", ret);
    LOGD("QCard_Encrypt plain = %s", ByteArrayToHexStr(srcData, srcLen));
    LOGD("QCard_Encrypt cipher = %s", ByteArrayToHexStr(destData, destLen));

    jbyteArray jbyteArray_dest = env->NewByteArray(destLen);
    env->SetByteArrayRegion(jbyteArray_dest, 0, destLen, reinterpret_cast<const jbyte *>(destData));
    env->ReleaseByteArrayElements(plain, src, JNI_FALSE);
    return jbyteArray_dest;
}

extern "C"
JNIEXPORT jbyteArray JNICALL
Java_com_qasky_simkey_1nativelib_qcard_QCard_decrypt(JNIEnv *env, jobject thiz, jlong key_handle, jbyteArray cipher) {
    long srcLen = env->GetArrayLength(cipher);
    jbyte *src = env->GetByteArrayElements(cipher, JNI_FALSE);
    auto *srcData = (unsigned char *) src;
    unsigned long destLen = srcLen;
    unsigned char destData[destLen];
    memset(destData, 0, sizeof(destData));

    int ret = QCard_Decrypt(devHandle, reinterpret_cast<KEYHANDLE>(key_handle), srcData, srcLen, destData, &destLen);
    LOGD("QCard_Decrypt ret = 0x%08x", ret);
    LOGD("QCard_Decrypt cipher = %s", ByteArrayToHexStr(srcData, srcLen));
    LOGD("QCard_Decrypt plain = %s", ByteArrayToHexStr(destData, destLen));

    jbyteArray jbyteArray_dest = env->NewByteArray(destLen);
    env->SetByteArrayRegion(jbyteArray_dest, 0, destLen, reinterpret_cast<const jbyte *>(destData));

    env->ReleaseByteArrayElements(cipher, src, JNI_FALSE);
    return jbyteArray_dest;
}

extern "C"
JNIEXPORT jbyteArray JNICALL
Java_com_qasky_simkey_1nativelib_qcard_QCard_getSoftKey(JNIEnv *env, jobject thiz, jlong key_handle, jlong key_len) {
    unsigned char softKey[key_len];
    memset(softKey, 0, key_len);

    int ret = QCard_ExportKey(devHandle, reinterpret_cast<KEYHANDLE>(key_handle), softKey, reinterpret_cast<unsigned long *>(&key_len));
    LOGD("QCard_ExportKey ret = 0x%08x softKey = %s", ret, ByteArrayToHexStr(softKey, key_len));

    jbyteArray jbyteArray_softKey = env->NewByteArray(key_len);
    env->SetByteArrayRegion(jbyteArray_softKey, 0, key_len, reinterpret_cast<const jbyte *>(softKey));
    return jbyteArray_softKey;
}

extern "C"
JNIEXPORT jbyteArray JNICALL
Java_com_qasky_simkey_1nativelib_qcard_QCard_exportCert(JNIEnv *env, jobject thiz, jint type, jstring app_name, jstring con_name) {
    char *appName = const_cast<char *>(env->GetStringUTFChars(app_name, JNI_FALSE));
    char *conName = const_cast<char *>(env->GetStringUTFChars(con_name, JNI_FALSE));
    unsigned long certLen = 0, timeOut = 0;

    int ret = QCard_ExportCertificate(devHandle, appName, conName, type, nullptr, &certLen, &timeOut);
    LOGD("QCard_ExportCertificate ret = 0x%08x certLen = %lu", ret, certLen);
    unsigned char cert[certLen];
    memset(cert, 0, certLen);
    ret = QCard_ExportCertificate(devHandle, appName, conName, type, cert, &certLen, &timeOut);
    LOGD("QCard_ExportCertificate ret = 0x%08x cert = %s", ret, ByteArrayToHexStr(cert, certLen));

    jbyteArray jbyteArray_cert = env->NewByteArray(certLen - 1); // 去除末尾/0
    env->SetByteArrayRegion(jbyteArray_cert, 0, certLen - 1, reinterpret_cast<const jbyte *>(cert));

    env->ReleaseStringUTFChars(app_name, appName);
    env->ReleaseStringUTFChars(con_name, conName);
    return jbyteArray_cert;
}

extern "C"
JNIEXPORT jbyteArray JNICALL
Java_com_qasky_simkey_1nativelib_qcard_QCard_exportPubKey(JNIEnv *env, jobject thiz, jint type, jstring app_name, jstring con_name) {
    char *appName = const_cast<char *>(env->GetStringUTFChars(app_name, JNI_FALSE));
    char *conName = const_cast<char *>(env->GetStringUTFChars(con_name, JNI_FALSE));
    unsigned long keyLen = 0;

    int ret = QCard_ExportPublicKey(devHandle, appName, conName, type, nullptr, &keyLen);
    LOGD("QCard_ExportPublicKey ret = 0x%08x keyLen = %lu", ret, keyLen);
    unsigned char key[keyLen];
    memset(key, 0, keyLen);
    ret = QCard_ExportPublicKey(devHandle, appName, conName, type, key, &keyLen);
    LOGD("QCard_ExportPublicKey ret = 0x%08x key = %s", ret, ByteArrayToHexStr(key, keyLen));

    jbyteArray jbyteArray_key = env->NewByteArray(keyLen - 1); // 去除末尾/0
    env->SetByteArrayRegion(jbyteArray_key, 0, keyLen - 1, reinterpret_cast<const jbyte *>(key));

    env->ReleaseStringUTFChars(app_name, appName);
    env->ReleaseStringUTFChars(con_name, conName);
    return jbyteArray_key;
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_qasky_simkey_1nativelib_qcard_QCard_verifyAppPIN(JNIEnv *env, jobject thiz, jstring app_name, jstring _pin) {
    char *appName = const_cast<char *>(env->GetStringUTFChars(app_name, JNI_FALSE));
    char *pin = const_cast<char *>(env->GetStringUTFChars(_pin, JNI_FALSE));
    unsigned long retryCount;

    int ret = QCard_VerifyAppPIN(devHandle, appName, pin, &retryCount);
    LOGD("QCard_VerifyAppPIN ret = 0x%08x retryCount = %lu", ret, retryCount);

    env->ReleaseStringUTFChars(app_name, appName);
    return !ret;
}

extern "C"
JNIEXPORT jobject JNICALL
Java_com_qasky_simkey_1nativelib_qcard_QCard_negoOLBizKey(JNIEnv *env, jobject thiz, jstring _host, jstring device_id, jstring system_id, jstring secret_id, jstring server_id, jstring visit_key_base64, jstring protect_key) {
//    char *host = const_cast<char *>(env->GetStringUTFChars(_host, JNI_FALSE));
//    char *deviceId = const_cast<char *>(env->GetStringUTFChars(device_id, JNI_FALSE));
//    char *systemId = const_cast<char *>(env->GetStringUTFChars(system_id, JNI_FALSE));
//    char *secretId = const_cast<char *>(env->GetStringUTFChars(secret_id, JNI_FALSE));
//    char *serverId = const_cast<char *>(env->GetStringUTFChars(server_id, JNI_FALSE));
//    char *visitKeyBase64 = const_cast<char *>(env->GetStringUTFChars(visit_key_base64, JNI_FALSE));
//    char *protectKey = const_cast<char *>(env->GetStringUTFChars(protect_key, JNI_FALSE));
//    char *flag = nullptr;
//    char checkCode[64] = {0};
//
//    int ret = QCard_ClientRequestOnlineBizKey(host, deviceId, systemId, secretId, serverId, visitKeyBase64, reinterpret_cast<const unsigned char *>(protectKey), &flag, checkCode);
//    LOGD("QCard_ClientRequestOnlineBizKey ret = 0x%08x \nflag = \n%s\ncheckCode = %s", ret, flag, checkCode);
//
//    env->ReleaseStringUTFChars(_host, host);
//    env->ReleaseStringUTFChars(device_id, deviceId);
//    env->ReleaseStringUTFChars(system_id, systemId);
//    env->ReleaseStringUTFChars(secret_id, secretId);
//    env->ReleaseStringUTFChars(server_id, serverId);
//    env->ReleaseStringUTFChars(visit_key_base64, visitKeyBase64);
//    env->ReleaseStringUTFChars(protect_key, protectKey);
//
//    if (ret) {
    return nullptr;
//    } else {
//        jclass clz_NegotiateInfo = env->FindClass("com/qasky/simkeyexample/qcard/NegotiateInfo");
//        jobject obj_NegotiateInfo = env->NewObject(clz_NegotiateInfo, env->GetMethodID(clz_NegotiateInfo, "<init>", "(Ljava/lang/String;Ljava/lang/String;)V"), env->NewStringUTF(flag), env->NewStringUTF(checkCode));
//        return obj_NegotiateInfo;
//    }
}


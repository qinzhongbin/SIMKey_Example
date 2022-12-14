package com.qasky.simkey_example;

import static com.qasky.simkey_example.App.LOG_TAG;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.EditText;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.LinearLayoutCompat;

import com.blankj.utilcode.util.ConvertUtils;
import com.blankj.utilcode.util.GsonUtils;
import com.blankj.utilcode.util.LogUtils;
import com.blankj.utilcode.util.TimeUtils;
import com.blankj.utilcode.util.ToastUtils;
import com.google.android.material.dialog.MaterialAlertDialogBuilder;
import com.google.android.material.textfield.TextInputLayout;
import com.google.gson.reflect.TypeToken;
import com.qasky.simkey_example.databinding.ActivityMainBinding;
import com.qasky.simkey_example.databinding.DialogParamsBinding;
import com.qasky.simkey_example.dto.CleanOLBizKeyReq;
import com.qasky.simkey_example.dto.CleanOLBizKeyResp;
import com.qasky.simkey_example.dto.CreateOLBizKeyReq;
import com.qasky.simkey_example.dto.CreateOLBizKeyResp;
import com.qasky.simkey_example.dto.ExtServerConsultInfo;
import com.qasky.simkey_example.dto.OnLineNegoInfo;
import com.qasky.simkey_example.dto.RestResult;
import com.qasky.simkey_example.dto.SvrNegoOLBizKeyReq;
import com.qasky.simkey_example.dto.SvrNegoOLBizKeyResp;
import com.qasky.simkey_example.gm.SM3Util;
import com.qasky.simkey_example.gm.SM4Util;
import com.qasky.simkey_example.okhttp.OkHttpUtil;
import com.qasky.simkey_nativelib.qcard.Application;
import com.qasky.simkey_nativelib.qcard.NegotiateInfo;
import com.qasky.simkey_nativelib.qcard.QCard;
import com.qasky.simkey_nativelib.sdmp.Cert;
import com.qasky.simkey_nativelib.sdmp.Result;
import com.qasky.simkey_nativelib.sdmp.SDMP;

import org.bouncycastle.util.encoders.Base64;

import java.nio.charset.StandardCharsets;
import java.security.InvalidAlgorithmParameterException;
import java.security.InvalidKeyException;
import java.security.NoSuchAlgorithmException;
import java.security.NoSuchProviderException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Calendar;
import java.util.HashMap;
import java.util.List;

import javax.crypto.BadPaddingException;
import javax.crypto.IllegalBlockSizeException;
import javax.crypto.NoSuchPaddingException;

import okhttp3.FormBody;
import okhttp3.MediaType;
import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.RequestBody;
import okhttp3.Response;

public class MainActivity extends AppCompatActivity {
    private ActivityMainBinding binding;
    private DialogParamsBinding paramsBinding;

    HashMap<String, String> params = new HashMap<>();
    String host;
    String appName;
    String conName;
    String userPIN;
    String softKeyLen;
    String keyAppSvrId;
    String secAuthKey;
    String protectKey;
    String plain;

    byte[] iv = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    byte[] encryptKey;
    byte[] decryptKey;
    byte[] hmacKey;

    OkHttpClient okHttpClient;
    AlertDialog waitingDialog;
    AlertDialog paramsDialog;

    private QCard qCard;
    private SDMP sdmp;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        waitingDialog = new AlertDialog.Builder(MainActivity.this).setMessage("loading").create();

        paramsBinding = DialogParamsBinding.inflate(getLayoutInflater());
        paramsDialog = new AlertDialog.Builder(this)
                .setTitle("????????????")
                .setView(paramsBinding.getRoot())
                .setPositiveButton("??????", (dialog, which) -> resetParams())
                .setNegativeButton("??????", null)
                .create();
        resetParams();

        okHttpClient = OkHttpUtil.getClient();

        qCard = QCard.getInstance();
        sdmp = SDMP.getInstance();

        qCard.setLogCallBack();

        boolean success = qCard.setRedirectFilePath(getFilesDir().getAbsolutePath());
        ToastUtils.showLong("????????????????????????" + (success ? "??????" : "??????"));
    }

    private void resetParams() {
        params.clear();
        LinearLayoutCompat paramsView = paramsBinding.params;
        for (int i = 0; i < paramsView.getChildCount(); i++) {
            EditText et = ((TextInputLayout) paramsView.getChildAt(i)).getEditText();
            params.put(et.getResources().getResourceEntryName(et.getId()), et.getEditableText().toString());
        }

        host = params.get("host");
        appName = params.get("appName");
        conName = params.get("conName");
        userPIN = params.get("userPIN");
        softKeyLen = params.get("softKeyLen");
        keyAppSvrId = params.get("keyAppSvrId");
        secAuthKey = params.get("secAuthKey");
        protectKey = params.get("protectKey");
        plain = params.get("plain");

        String protectKey = params.get("protectKey");
        String secAuthKey = params.get("secAuthKey");
        byte[] cutProtectKey = Arrays.copyOfRange(SM3Util.hash(protectKey.getBytes(StandardCharsets.UTF_8)), 0, 16);
        byte[] keys = new byte[0];
        try {
            keys = SM4Util.decrypt_CBC_Padding(cutProtectKey, iv, Base64.decode(secAuthKey.getBytes(StandardCharsets.UTF_8)));
        } catch (IllegalBlockSizeException | BadPaddingException | InvalidKeyException | NoSuchAlgorithmException | NoSuchProviderException | NoSuchPaddingException | InvalidAlgorithmParameterException e) {
            e.printStackTrace();
        }

        encryptKey = Arrays.copyOfRange(keys, 0, 16);
        decryptKey = Arrays.copyOfRange(keys, 16, 32);
        hmacKey = Arrays.copyOfRange(keys, 32, 48);
    }

    public void resetParams(View view) {
        paramsDialog.show();
    }

    public void initSystem(View view) {
        waitingDialog.show();
        new Thread(() -> {
            if (sdmp.sessionInit()) {
                if (sdmp.login(host, "qzb", "Ql172602")) {
                    sdmp.enumDevice();
                    String deviceId = sdmp.getDeviceId(0);
                    String systemId = "000000056";
                    String userId = "test_simkey";
//                    Result unbindSystem = sdmp.unbindSystem(deviceId, appName);
//                    LogUtils.d(unbindSystem);
//                    ToastUtils.showLong("????????????" + appName + (unbindSystem.error_code == 0 ? "??????" : "??????") + "\n" + unbindSystem.msg);
                    Result initSystem = sdmp.initSystem(deviceId, systemId, new Cert(userPIN, userId, "?????????", "0fd2260c15e7409f88900d58826b2c70", "??????????????????????????????????????????", "??????", "??????", "CN"));
                    LogUtils.d(initSystem);
                    ToastUtils.showLong("???????????????" + appName + (initSystem.error_code == 0 ? "??????" : "??????") + "\n" + initSystem.msg);
                    sdmp.sessionDeInit();
                    runOnUiThread(() -> waitingDialog.dismiss());
                }
            }
        }).start();
    }

    public void enumDevice(View view) {
        new Thread(() -> {
            boolean success = qCard.enumDevice();
            ToastUtils.showLong("????????????" + (success ? "??????" : "??????"));
        }).start();
    }

    public void freeDevices(View view) {
        qCard.freeDevices();
    }

    public void loginDevice(View view) {
        boolean success = qCard.loginDevice();
        ToastUtils.showLong("????????????" + (success ? "??????" : "??????"));
    }

    public void logoutDevice(View view) {
        boolean success = qCard.logoutDevice();
        ToastUtils.showLong("????????????" + (success ? "??????" : "??????"));
    }

    public void initResource(View view) {
        boolean success = qCard.initResource();
        ToastUtils.showLong("???????????????" + (success ? "??????" : "??????"));
    }

    public void updateResource(View view) {
        boolean success = qCard.updateResource();
        ToastUtils.showLong("????????????" + (success ? "??????" : "??????"));
    }

    public void destroyResource(View view) {
        qCard.destroyResource();
        ToastUtils.showLong("????????????");

    }

    String deviceId;

    public void getDeviceId(View view) {
        deviceId = qCard.getDeviceId();
        ToastUtils.showLong("??????ID: " + deviceId);
    }

    String systemId;

    public void getSystemId(View view) {
        List<Application> appList = qCard.getAppList();

        new MaterialAlertDialogBuilder(this)
                .setTitle("????????????")
                .setItems(appList.stream().map(Application::getName).toArray(String[]::new), (dialog, which) -> {
                    Application application = appList.get(which);
                    systemId = qCard.getSystemId(application.getName(), application.getCntrName());
                    ToastUtils.showLong("??????ID: " + systemId);
                })
                .create()
                .show();
    }

    public void deleteApp(View view) {
        List<Application> appList = qCard.getAppList();

        new MaterialAlertDialogBuilder(this)
                .setTitle("????????????")
                .setItems(appList.stream().map(Application::getName).toArray(String[]::new), (dialog, which) -> {
                    Application application = appList.get(which);
                    String name = application.getName();
                    boolean success = qCard.deleteApp(name);
                    ToastUtils.showLong("????????????" + name + (success ? "??????" : "??????"));
                })
                .create()
                .show();
    }

    public void formatDevice(View view) {
        boolean success = qCard.formatDevice();
        ToastUtils.showLong("???????????????" + (success ? "??????" : "??????"));
    }

    public void queryKeyLength(View view) {
        long[] keyLenInfo = qCard.queryKeyLength(appName, conName);
        ToastUtils.showLong("????????????: " + keyLenInfo[0] + "\n" + " ?????????: " + keyLenInfo[1]);
    }

    public void chargeKey(View view) {
        new Thread(() -> {
            runOnUiThread(() -> waitingDialog.show());
            boolean success = qCard.chargeKey(host, appName, conName, userPIN);
            ToastUtils.showLong("????????????" + (success ? "??????" : "??????"));
            runOnUiThread(() -> waitingDialog.dismiss());
        }).start();
    }

    public void clearKey(View view) {
        boolean success = qCard.clearKey(appName);
        ToastUtils.showLong("????????????" + (success ? "??????" : "??????"));
    }

    List<NegotiateInfo> negoInfos = new ArrayList<>();

    public void CTSNegotiate(View view) {
        new Thread(() -> {
            runOnUiThread(() -> waitingDialog.show());
            String timestamp = String.valueOf(System.currentTimeMillis());
            String authMsg = deviceId + "," + appName + "," + conName + "," + softKeyLen + "," + keyAppSvrId + "," + timestamp;
            String hmac = Base64.toBase64String(SM3Util.hmac(hmacKey, authMsg.getBytes(StandardCharsets.UTF_8)));
            Request request = new Request.Builder()
                    .url("https://" + host + "/qkeyapply/serverConsultInfosByApp")
                    .post(new FormBody.Builder()
                            .add("storeId", deviceId)
                            .add("appName", appName)
                            .add("containerName", conName)
                            .add("keyLen", softKeyLen)
                            .add("serverId", keyAppSvrId)
                            .add("timestamp", timestamp)
                            .add("hmac", hmac)
                            .build())
                    .build();
            try {
                Response response = okHttpClient.newCall(request).execute();
                if (response.isSuccessful()) {
                    RestResult<ExtServerConsultInfo> restResult = GsonUtils.fromJson(response.body().string(), new TypeToken<RestResult<ExtServerConsultInfo>>() {
                    }.getType());
                    if (restResult.getCode() == 0) {
                        ExtServerConsultInfo data = restResult.getData();
                        String hmac_expect = Base64.toBase64String(SM3Util.hmac(hmacKey, String.join(",", data.toAuthMsgParams()).getBytes(StandardCharsets.UTF_8)));

                        boolean useKeyAppSrv = data.getTimestamp() != null && data.getHmac() != null; // ????????????????????????
                        if (useKeyAppSrv) {
                            if (!timestamp.equals(data.getTimestamp()) || !hmac_expect.equals(data.getHmac())) { // ??????????????????hmac
                                ToastUtils.showLong("????????????????????????");
                                return;
                            }
                        }
                        ToastUtils.showLong("CTS??????????????????");
                        negoInfos.add(new NegotiateInfo(data.getFlag().toOriginalOrderJson(), data.getCheckCode()));

                        String softQkey_encrypted_encoded = data.getSoftQkey();
                        byte[] softQkey_encrypted = Base64.decode(softQkey_encrypted_encoded);
                        byte[] softQkey;
                        if (useKeyAppSrv) {
                            softQkey = SM4Util.decrypt_CBC_Padding(decryptKey, iv, softQkey_encrypted);
                        } else {
                            softQkey = softQkey_encrypted;
                        }
                        LogUtils.d("?????????????????????0x" + ConvertUtils.bytes2HexString(softQkey)); // ??????????????????????????????????????????????????????
                    } else {
                        ToastUtils.showLong(restResult.getMessage());
                    }
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
            runOnUiThread(() -> waitingDialog.dismiss());
        }).start();
    }

    public void negoOLBizKey(View view) {
        new Thread(() -> {
            runOnUiThread(waitingDialog::show);

            // step 1: ?????????????????????????????????
            Calendar calendar = Calendar.getInstance();
            calendar.add(Calendar.YEAR, 1);
            CreateOLBizKeyReq createRequest = new CreateOLBizKeyReq();
            createRequest.setSecretSize(softKeyLen);
            createRequest.setValidityDate(TimeUtils.date2String(calendar.getTime()));
            createRequest.setSystemId(systemId);
            createRequest.setServerId(keyAppSvrId);
            createRequest.setTimestamp(System.currentTimeMillis());
            String authMsg_create = createRequest.getSecretSize() + "," + createRequest.getValidityDate() + "," + createRequest.getSystemId() + "," + createRequest.getServerId() + "," + createRequest.getTimestamp();
            createRequest.setHmac(Base64.toBase64String(SM3Util.hmac(hmacKey, authMsg_create.getBytes(StandardCharsets.UTF_8))));
            try {
                Response response_create = okHttpClient.newCall(new Request.Builder()
                        .url("https://" + host + "/onlinebizkey/createOnlineBizKey")
                        .post(RequestBody.create(GsonUtils.toJson(createRequest), MediaType.parse("application/json; charset=utf-8")))
                        .build()).execute();
                if (response_create.isSuccessful()) {
                    CreateOLBizKeyResp createResponse = GsonUtils.fromJson(response_create.body().string(), CreateOLBizKeyResp.class);
                    if (createResponse.getCode() == 0) {
                        String secretId = createResponse.getData().getSecretId();

                        // step 2: ?????????????????????????????????
                        SvrNegoOLBizKeyReq svrNegoReq = new SvrNegoOLBizKeyReq();
                        svrNegoReq.setSecretId(secretId);
                        svrNegoReq.setSystemId(systemId);
                        svrNegoReq.setServerId(keyAppSvrId);
                        svrNegoReq.setTimestamp(String.valueOf(System.currentTimeMillis()));
                        String authMsg_svrNego = svrNegoReq.getSecretId() + "," + svrNegoReq.getSystemId() + "," + svrNegoReq.getServerId() + "," + svrNegoReq.getTimestamp();
                        svrNegoReq.setHmac(Base64.toBase64String(SM3Util.hmac(hmacKey, authMsg_svrNego.getBytes(StandardCharsets.UTF_8))));
                        Response response_svrNego = okHttpClient.newCall(new Request.Builder()
                                .url("https://" + host + "/onlinebizkey/serverNegotiateOnlineBizKey")
                                .post(RequestBody.create(GsonUtils.toJson(svrNegoReq), MediaType.parse("application/json; charset=utf-8")))
                                .build()).execute();
                        if (response_svrNego.isSuccessful()) {
                            SvrNegoOLBizKeyResp srvNegoResponse = GsonUtils.fromJson(response_svrNego.body().string(), SvrNegoOLBizKeyResp.class);
                            if (srvNegoResponse.getCode() == 0) {
                                String secretKey_encrypted_encoded = srvNegoResponse.getData().getSecretKey();
                                byte[] secretKey_encrypted = Base64.decode(secretKey_encrypted_encoded);
                                byte[] secretKey = SM4Util.decrypt_CBC_Padding(decryptKey, iv, secretKey_encrypted);
                                LogUtils.d("??????????????????????????????0x" + ConvertUtils.bytes2HexString(secretKey));

                                // step 3: ?????????????????????????????????
                                Thread.sleep(1000L); // ???????????????????????????????????????????????????????????????????????????
                                NegotiateInfo negotiateInfo = qCard.negoOLBizKey(host, deviceId, systemId, secretId, keyAppSvrId, secAuthKey, protectKey);
                                if (negotiateInfo != null) {
                                    ToastUtils.showLong("??????????????????????????????");
                                    negoInfos.add(negotiateInfo);
                                } else {
                                    ToastUtils.showLong("??????????????????????????????");
                                }
                                // step 3.1: ??????????????????
                                // step 3.2: ???????????????
                                // step 3.3: ????????????????????????????????????????????????????????????

                                // step 4: ????????????????????????????????? (?????????????????????)
                                CleanOLBizKeyReq cleanRequest = new CleanOLBizKeyReq();
                                cleanRequest.setSecretId(secretId);
                                cleanRequest.setSystemId(systemId);
                                cleanRequest.setServerId(keyAppSvrId);
                                cleanRequest.setTimestamp(String.valueOf(System.currentTimeMillis()));
                                String authMsg_clean = cleanRequest.getSecretId() + "," + cleanRequest.getSystemId() + "," + cleanRequest.getServerId() + "," + cleanRequest.getTimestamp();
                                cleanRequest.setHmac(Base64.toBase64String(SM3Util.hmac(hmacKey, authMsg_clean.getBytes(StandardCharsets.UTF_8))));
                                Response response_clean = okHttpClient.newCall(new Request.Builder()
                                        .url("https://" + host + "/onlinebizkey/cleanNegotiateOnlineBizKey")
                                        .post(RequestBody.create(GsonUtils.toJson(cleanRequest), MediaType.parse("application/json; charset=utf-8"))).build()).execute();
                                if (response_clean.isSuccessful()) {
                                    CleanOLBizKeyResp cleanResponse = GsonUtils.fromJson(response_clean.body().string(), CleanOLBizKeyResp.class);
                                    if (cleanResponse.getCode() == 0) {
                                        LogUtils.d("??????????????????????????????");
                                    } else {
                                        ToastUtils.showLong(cleanResponse.getMessage());
                                    }
                                }
                            } else {
                                ToastUtils.showLong(srvNegoResponse.getMessage());
                            }
                        }
                    } else {
                        ToastUtils.showLong(createResponse.getMessage());
                    }
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
            runOnUiThread(waitingDialog::dismiss);
        }).start();
    }


    OnLineNegoInfo onLineNegoInfo;

    public void negoOLKey(View view) {
        new Thread(new Runnable() {
            @Override
            public void run() {
                String json = qCard.negoOLKey();
                onLineNegoInfo = GsonUtils.fromJson(json, OnLineNegoInfo.class);
                ToastUtils.showLong("???????????????????????????" + (onLineNegoInfo != null ? "??????" : "??????"));
            }
        }).start();
    }

    long keyHandle;

    public void getKeyHandle(View view) {
        new AlertDialog.Builder(this)
                .setTitle("?????????????????????????????????")
                .setItems(negoInfos.stream().map(NegotiateInfo -> NegotiateInfo.checkCode).toArray(String[]::new), (dialog, which) -> {
                    NegotiateInfo negotiateInfo = negoInfos.get(which);
                    keyHandle = qCard.getKeyHandle(appName, conName, userPIN, negotiateInfo.checkCode, negotiateInfo.flag);
                    ToastUtils.showLong("????????????: 0x" + Long.toHexString(keyHandle));
                })
                .setCancelable(false)
                .create().show();
    }


    public void getOLKeyHandle(View view) {
        String hexFlagChkV = onLineNegoInfo.getFlagChkV();
        String hexCipherQKey = onLineNegoInfo.getCipherQKey();
        byte[] flagChkV = ConvertUtils.hexString2Bytes(hexFlagChkV);
        byte[] cipherQKey = ConvertUtils.hexString2Bytes(hexCipherQKey);

        new Thread(new Runnable() {
            @Override
            public void run() {
                keyHandle = qCard.getOLKeyHandle(onLineNegoInfo.getQccsId(), onLineNegoInfo.getSysId(), onLineNegoInfo.getAppName(), onLineNegoInfo.getConName(), flagChkV, onLineNegoInfo.getFlag(), onLineNegoInfo.getOfferSoftKey(), cipherQKey, onLineNegoInfo.getCipherQKeyLen(), userPIN);
                ToastUtils.showLong("????????????????????????: 0x" + Long.toHexString(keyHandle));
            }
        }).start();

    }

    public void freeKeyHandle(View view) {
        qCard.freeKeyHandle(keyHandle);
        ToastUtils.showLong("??????????????????");
    }

    public void getSoftKey(View view) {
        byte[] softKey = qCard.getSoftKey(keyHandle, Long.parseLong(softKeyLen));
        ToastUtils.showLong(ConvertUtils.bytes2HexString(softKey));
    }

    public void getOLSoftKey(View view) {
        String hexFlagChkV = onLineNegoInfo.getFlagChkV();
        String hexCipherQKey = onLineNegoInfo.getCipherQKey();
        byte[] flagChkV = ConvertUtils.hexString2Bytes(hexFlagChkV);
        byte[] cipherQKey = ConvertUtils.hexString2Bytes(hexCipherQKey);

        new Thread(new Runnable() {
            @Override
            public void run() {
                byte[] softKey = qCard.getOLSoftKey(onLineNegoInfo.getQccsId(), onLineNegoInfo.getSysId(), flagChkV, onLineNegoInfo.getFlag(), onLineNegoInfo.getOfferSoftKey(), cipherQKey, onLineNegoInfo.getCipherQKeyLen(), userPIN);
                ToastUtils.showLong(ConvertUtils.bytes2HexString(softKey));
            }
        }).start();
    }

    byte[] cipher;

    public void encrypt(View view) {
        cipher = qCard.encrypt(keyHandle, plain.getBytes(StandardCharsets.UTF_8));
        ToastUtils.showLong("????????????");
    }

    public void decrypt(View view) {
        byte[] plain = qCard.decrypt(keyHandle, cipher);
        ToastUtils.showLong(new String(plain, StandardCharsets.UTF_8));
    }

    public void exportEncCert(View view) {
        byte[] encCert = qCard.exportCert(0, appName, conName);

        String encCertPem = new String(encCert, StandardCharsets.UTF_8);
        Log.d(LOG_TAG, "???????????????\n" + encCertPem);
    }

    public void exportSignCert(View view) {
        byte[] signCert = qCard.exportCert(1, appName, conName);
        String signCertPem = new String(signCert, StandardCharsets.UTF_8);
        Log.d(LOG_TAG, "???????????????\n" + signCertPem);
    }

    public void exportEncPubKey(View view) {
        byte[] encPubKey = qCard.exportPubKey(0, appName, conName);
        String encPubKeyPem = new String(encPubKey, StandardCharsets.UTF_8);
        Log.d(LOG_TAG, "???????????????\n" + encPubKeyPem);
    }

    public void exportSignPubKey(View view) {
        byte[] signPubKey = qCard.exportPubKey(1, appName, conName);
        String signPubKeyPem = new String(signPubKey, StandardCharsets.UTF_8);
        Log.d(LOG_TAG, "???????????????\n" + signPubKeyPem);
    }

    public void verifyAppPIN(View view) {
        boolean success = qCard.verifyAppPIN(appName, userPIN);
        ToastUtils.showLong("????????????PIN: " + (success ? "??????" : "??????"));
    }
}
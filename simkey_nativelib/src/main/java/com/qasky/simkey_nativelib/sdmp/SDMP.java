package com.qasky.simkey_nativelib.sdmp;

public class SDMP {
    private SDMP() {
    }

    private static final SDMP instance = new SDMP();

    public static SDMP getInstance() {
        return instance;
    }

    static {
        System.loadLibrary("native-sdmp");
    }


    /**
     * 打开会话
     */
    public native boolean sessionInit();

    /**
     * 结束会话
     */
    public native void sessionDeInit();

    /**
     * 枚举设备
     */
    public native int enumDevice();

    /**
     * 获取设备ID
     */
    public native String getDeviceId(int index);

    public native boolean login(String host, String userName, String pwd);

//    public native String getTokenAndCookie();

    /**
     * 获取证书模板
     */
    public native String loadTemplate();

    /**
     * 获取服务端系统列表
     */
    public native String getServerSystemList(String deviceId);

    /**
     * 初始化应用系统
     */
    public native Result initSystem(String devId, String sysId, Cert cert);

    /**
     * 解绑应用系统
     */
    public native Result unbindSystem(String deviceId, String systemId);

    public native int test();
}

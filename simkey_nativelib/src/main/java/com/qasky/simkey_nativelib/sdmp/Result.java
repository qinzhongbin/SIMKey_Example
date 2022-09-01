package com.qasky.simkey_nativelib.sdmp;

public class Result {
    public int error_code;/* 错误码 */
    public String msg;/* 信息 */

    public int getError_code() {
        return error_code;
    }

    public void setError_code(int error_code) {
        this.error_code = error_code;
    }

    public String getMsg() {
        return msg;
    }

    public void setMsg(String msg) {
        this.msg = msg;
    }

    @Override
    public String toString() {
        return "Result{" +
                "error_code=" + error_code +
                ", msg='" + msg + '\'' +
                '}';
    }
}

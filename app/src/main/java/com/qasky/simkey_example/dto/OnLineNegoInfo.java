package com.qasky.simkey_example.dto;

public class OnLineNegoInfo {

    private String qccsId;
    private String sysId;
    private String appName;
    private String conName;
    private String flagChkV;
    private String flag;
    private int offerSoftKey;
    private String cipherQKey;
    private int cipherQKeyLen;

    public String getQccsId() {
        return qccsId;
    }

    public void setQccsId(String qccsId) {
        this.qccsId = qccsId;
    }

    public String getSysId() {
        return sysId;
    }

    public void setSysId(String sysId) {
        this.sysId = sysId;
    }

    public String getAppName() {
        return appName;
    }

    public void setAppName(String appName) {
        this.appName = appName;
    }

    public String getConName() {
        return conName;
    }

    public void setConName(String conName) {
        this.conName = conName;
    }

    public String getFlagChkV() {
        return flagChkV;
    }

    public void setFlagChkV(String flagChkV) {
        this.flagChkV = flagChkV;
    }

    public String getFlag() {
        return flag;
    }

    public void setFlag(String flag) {
        this.flag = flag;
    }

    public int getOfferSoftKey() {
        return offerSoftKey;
    }

    public void setOfferSoftKey(int offerSoftKey) {
        this.offerSoftKey = offerSoftKey;
    }

    public String getCipherQKey() {
        return cipherQKey;
    }

    public void setCipherQKey(String cipherQKey) {
        this.cipherQKey = cipherQKey;
    }

    public int getCipherQKeyLen() {
        return cipherQKeyLen;
    }

    public void setCipherQKeyLen(int cipherQKeyLen) {
        this.cipherQKeyLen = cipherQKeyLen;
    }
}

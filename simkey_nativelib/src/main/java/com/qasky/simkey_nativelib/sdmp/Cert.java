package com.qasky.simkey_nativelib.sdmp;

public class Cert {
    public String userPIN;
    public String userId;
    public String department;
    public String departmentId;
    public String company;
    public String city;
    public String province;
    public String country;

    public Cert(String userPIN, String userId, String department, String departmentId, String company, String city, String province, String country) {
        this.userPIN = userPIN;
        this.userId = userId;
        this.department = department;
        this.departmentId = departmentId;
        this.company = company;
        this.city = city;
        this.province = province;
        this.country = country;
    }
}

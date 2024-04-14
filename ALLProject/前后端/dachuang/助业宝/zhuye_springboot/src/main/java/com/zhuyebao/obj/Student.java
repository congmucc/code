package com.zhuyebao.obj;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class Student {
    private String username;
    private String openid;
    private String name;
    private String avatar;
    private String university;
    private String college;
    private String major;
    private String idCard;
    private String phone;
    private String ability;
    private Integer stuId;
    private String volunteer;
    private String volunCertify;
    private String profess;
    private String professCertify;
    private Integer blacklist;
    private String stuAct;
}

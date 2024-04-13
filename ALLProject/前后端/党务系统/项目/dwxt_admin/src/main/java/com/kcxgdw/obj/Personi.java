package com.kcxgdw.obj;

import cn.hutool.core.codec.Base64;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import lombok.extern.slf4j.Slf4j;

import java.io.UnsupportedEncodingException;
import java.net.URLDecoder;
import java.time.LocalDate;
@Slf4j
@Data
@NoArgsConstructor
@AllArgsConstructor
public class Personi {
    private String id;
    private String name;
    private String status;
//    private Integer age=getAge();

    private String sex;
    private String grade;
    private String major;
    private String classNum;
    private String idNum ;
    private String birthday;
    private String hometown;
    private String phoneNum;
    private LocalDate joiningTime;
    private String joiningSchool;
    private String homeAddress;
    private LocalDate subTime;
    private String pubTime;
    private LocalDate detTime;
    private LocalDate delTime;
    private String filTime;
    private String culPeople;
    private String condition;
    private String traTime;
    private String comTime;
    private String qua;
    public String getBirthday2(String idNum){
        String year = "";
        String month = "";
        String day = "";
        year = idNum.substring(6, 10);
        month = idNum.substring(10,12);
        day = idNum.substring(12,14);
        return year + "-" + month + "-" + day;

    }



    public void setId(String id) {
        this.id = id;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getId() {
        return id;
    }

    public String getName() {
        return name;
    }
}
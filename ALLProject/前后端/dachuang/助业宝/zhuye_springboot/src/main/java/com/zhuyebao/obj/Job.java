package com.zhuyebao.obj;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class Job {
    private Integer id;
    private String name;
    private String time;
    private String content;
    private String place;
    private String demand;
    private String phone;
    //机构id
    private Integer institutionId;
    private String state;
    private String salary;
}

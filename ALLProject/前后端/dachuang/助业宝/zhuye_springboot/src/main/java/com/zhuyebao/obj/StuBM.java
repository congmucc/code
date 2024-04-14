package com.zhuyebao.obj;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;


/**
 * 报名表
 */
@Data
@NoArgsConstructor
@AllArgsConstructor
public class StuBM {
    private Integer id;
    private String  username;
    private Integer institutionId;
    private Integer campusId;
    private String  content;
    private Integer  state;
}

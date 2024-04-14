package com.zhuyebao.obj;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class StuCampus {
    private Integer id;
    private String username;
    private Integer institutionId;
    private Integer campusId;
    private String content;
    private String feedbackStu;
    private String feedbackInstitution;
}

package com.zhuyebao.obj;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class StuJob {
    private Integer id;
    private String username;
    private Integer institutionId;
    private Integer jobId;
    private String content;
    private String feedbackStu;
    private String feedbackInstitution;
}

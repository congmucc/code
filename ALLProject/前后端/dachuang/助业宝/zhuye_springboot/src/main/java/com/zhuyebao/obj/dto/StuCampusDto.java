package com.zhuyebao.obj.dto;


import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class StuCampusDto {
    private Integer id;
    private String username;
    // 这里我机构反馈哪里写错了，应该campusId改为活动名字，但是没啥错误，毕竟回显也就改个机构反馈
    private String institutionId;
    private Integer campusId;
    private String content;
    private String feedbackStu;
    private String feedbackInstitution;
}

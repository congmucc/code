package com.zhuyebao.service;

import com.zhuyebao.obj.Campus;
import com.zhuyebao.obj.StuBM;
import com.zhuyebao.obj.Student;
import org.springframework.web.multipart.MultipartFile;

import java.io.IOException;
import java.util.List;
import java.util.Map;

public interface StudentService{
    //查找学生信息
    //修改
    void update(Student student);
    //删除
    void deleteById(Long id);
    List<Student> findAll(String useranme);
    //学生认证
    void authentication(String username, Integer stuId);
    //未认证学生
    String unauthorized(String username);



    //活动报名
    void application(StuBM stuBM);
    //查找未审核的报名请求
    List<StuBM> weiShenHe();
    //审核通过
    void tongGuo(Long id, Long state);

    //校内活动 校内发起活动表 campus_will state=0 待审核
    void addActivity(Campus campus);
    //查看活动进度
    String findAct(Long id);
    //活动数据
    String assess(Long id);
    //添加活动证明
    void addActZ(String username, String stuAct);
    //查看活动证明
    String activityProof(String username);
    //下载活动证明
    void downloadActivity(Student student);



}

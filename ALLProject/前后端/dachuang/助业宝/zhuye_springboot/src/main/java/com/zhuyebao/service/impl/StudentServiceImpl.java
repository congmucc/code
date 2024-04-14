package com.zhuyebao.service.impl;

//import com.rjgc.mapper.StudentMapper;
import com.zhuyebao.mapper.StudentMapper;
import com.zhuyebao.obj.Campus;
import com.zhuyebao.obj.StuBM;
import com.zhuyebao.obj.Student;
import com.zhuyebao.service.StudentService;
import com.zhuyebao.utils.FileUtils;
import lombok.extern.slf4j.Slf4j;
//import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.util.CollectionUtils;
import org.springframework.util.StringUtils;
import org.springframework.web.multipart.MultipartFile;

import java.io.File;
import java.io.IOException;
import java.util.*;

@Service
@Slf4j
public class StudentServiceImpl implements StudentService {

    @Autowired
    private StudentMapper studentMapper;
    @Override
    public List<Student> findAll(String username) {
        return studentMapper.findAll(username);
    }
    //学生认证
    @Override
    public void authentication(String username, Integer stuId) {
        studentMapper.authentication(username,stuId);
    }
    //查找未认证学生
    @Override
    public String unauthorized(String username) {
        Student students =  studentMapper.unauthorized(username);
        if(students.getStuId() == 1){
            return "认证成功";
        }else return "还未认证";
    }

    //活动报名
    @Override
    public void application(StuBM stuBM) {
        stuBM.setState(0);
        studentMapper.application(stuBM);
    }
    //查找未审核的报名请求
    @Override
    public List<StuBM> weiShenHe() {
        List<StuBM> stuBMS = studentMapper.weiShenHe();
        return stuBMS;
    }
    //审核通过
    @Override
    public void tongGuo(Long id, Long state) {
        studentMapper.tongGuo(id,state);
    }


    @Override
    public void update(Student student) {
        studentMapper.update(student);
    }
    //删除
    @Override
    public void deleteById(Long id) {
        studentMapper.deleteById(id);
    }





    //校内活动 校内发起活动表 campus_will state=0 待审核
    @Override
    public void addActivity(Campus campus) {
        //设置状态值
        campus.setState("0");
        //存入数据库
        studentMapper.addActivity(campus);
    }
    //查看活动进度
    @Override
    public String findAct(Long id) {
        return studentMapper.findAct(id);
    }
    //活动数据
    @Override
    public String assess(Long id) {
        return studentMapper.assess(id);
    }
    //添加活动证明
    @Override
    public void addActZ(String username, String stuAct) {
        studentMapper.addActZ(username,stuAct);
    }
    //查看活动证明
    @Override
    public String activityProof(String username) {
        return studentMapper.activityProof(username);
    }
    //下载活动证明
    @Override
    public void downloadActivity(Student student) {
        //先查询到活动证明地址
        List<Student> all = studentMapper.findAll(student.getUsername());
        String volunCertify = all.get(0).getStuAct();
        //调用工具类
        FileUtils.download(volunCertify);
    }

}

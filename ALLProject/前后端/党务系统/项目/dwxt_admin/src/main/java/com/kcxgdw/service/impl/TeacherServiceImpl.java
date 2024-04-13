package com.kcxgdw.service.impl;

import cn.hutool.core.codec.Base64;
import com.kcxgdw.mapper.TeacherMapper;
import com.kcxgdw.obj.Administrator;
import com.kcxgdw.service.TeacherService;
import lombok.extern.slf4j.Slf4j;
import org.apache.commons.lang3.RandomStringUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.mail.SimpleMailMessage;
import org.springframework.mail.javamail.JavaMailSender;
import org.springframework.stereotype.Service;

import java.nio.charset.StandardCharsets;
import java.util.Map;
@Slf4j
@Service
public class TeacherServiceImpl implements TeacherService {

    @Autowired
    private TeacherMapper teacherMapper;
    @Autowired
    private JavaMailSender javaMailSender;
    @Value("${spring.mail.username}")
    private String from;
    @Override
    public Administrator login(Administrator administrator) {
        administrator.setPassword(Base64.encode(administrator.getPassword().getBytes(StandardCharsets.UTF_8)));
        return teacherMapper.getByUsernameAndPassword(administrator);
    }

    @Override
    public Administrator getUser(String username) {
        return teacherMapper.getUserInformation(username);
    }

    @Override
    public void upload(Administrator administrator) {
        teacherMapper.upload(administrator);
    }



    @Override
    public String getCode(String username, String email) {
        log.info(teacherMapper.existEmail(username,email)+"");
        if (teacherMapper.existEmail(username,email)){

            SimpleMailMessage message = new SimpleMailMessage();
            message.setFrom(from);  //发送人
            message.setSubject("信工党务系统重置密码服务");
            //调用commons工具包RandomStringUtils
            String code = RandomStringUtils.randomNumeric(5);
            message.setText("您本次的验证码是:"+code);
            message.setTo(email);
            javaMailSender.send(message);
            log.info(code);
            //生成的数据返回给前端做校验
            return code;
        }
        return "";
    }

    @Override
    public void updateTeaPsw(String username, String password) {
        //密码加密
        password = Base64.encode(password.getBytes(StandardCharsets.UTF_8));
        teacherMapper.updateTeaPsw(username,password);

    }

    /**
     * 修改老师的登录状态
     * @param t
     * @param username
     */
    @Override
    public void changeSatus(Integer t, String username) {
        teacherMapper.changeStatus(t, username);
    }

}

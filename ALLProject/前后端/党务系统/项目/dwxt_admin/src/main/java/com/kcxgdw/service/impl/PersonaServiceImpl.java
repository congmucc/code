package com.kcxgdw.service.impl;

import cn.hutool.core.codec.Base64;
import com.github.pagehelper.Page;
import com.github.pagehelper.PageHelper;
import com.kcxgdw.mapper.PersonaMapper;
import com.kcxgdw.mapper.StudentMapper;
import com.kcxgdw.obj.PageBean;
import com.kcxgdw.obj.Persona;
import com.kcxgdw.service.PersonaService;
import lombok.extern.slf4j.Slf4j;
import org.apache.commons.lang3.RandomStringUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.mail.SimpleMailMessage;
import org.springframework.mail.javamail.JavaMailSender;
import org.springframework.stereotype.Service;

import java.nio.charset.StandardCharsets;
import java.util.List;

@Service
@Slf4j
public class PersonaServiceImpl implements PersonaService {

    @Autowired
    private PersonaMapper personaMapper;
    @Autowired
    private StudentMapper studentMapper;
    @Autowired
    private JavaMailSender javaMailSender;
    @Value("${spring.mail.username}")
    private String from;

    @Override
    public PageBean page(Integer pagenum, Integer pagesize,String username) {
        PageHelper.startPage(pagenum,pagesize);
        List<Persona>personaList= personaMapper.list(username);
        Page<Persona>p= (Page<Persona>) personaList;
        PageBean pageBean=new PageBean(p.getTotal(),p.getResult());
        return pageBean;
    }

    @Override
    public void delete(String username) {
        personaMapper.delete(username);
    }

    @Override
    public void updata(List<Integer> ids, Integer t) {
        personaMapper.updata(ids, t);
    }

    @Override
    public void save(Persona persona) {
        personaMapper.insert(persona);
    }

    @Override
    public boolean exist(String username) {
        return personaMapper.exist(username);
    }

    @Override
    public Persona login(Persona persona) {
        log.info(persona.getPassword());
        if(!persona.getPassword().equals("123456")) {
            persona.setPassword(Base64.encode(persona.getPassword().getBytes(StandardCharsets.UTF_8)));
        }
        log.info(persona.getPassword());
        return studentMapper.getByUsernameAndPassword(persona);
    }
    //学生邮箱修改
    @Override
    public void emailupdate(Persona persona){
        studentMapper.emailupdate(persona);
    }
    @Override
    public  Persona getStudentPersona(String username){
        return studentMapper.getByStudentPersona(username);
    }

    /**
     * 修改学生密码
     * @param username
     * @param password
     */
    @Override
    public void updateStuPsw(String username, String password) {
        //密码加密
        password = Base64.encode(password.getBytes(StandardCharsets.UTF_8));
        studentMapper.updateStuPsw(username,password);
    }

    @Override
    public String getCode(String username, String email) {

        if (studentMapper.existEmail(username,email)){

            SimpleMailMessage message = new SimpleMailMessage();
            //log.info(from+"");
            message.setFrom(from);  //发送人
            message.setSubject("信工党务系统重置密码服务");
            //调用commons工具包RandomStringUtils
            String code = RandomStringUtils.randomNumeric(5);
            message.setText("您本次修改密码的验证码是:"+code);
            message.setTo(email);
            javaMailSender.send(message);
            log.info(code);
            //生成的数据返回给前端做校验
            return code;
        }
        return "";
    }

    @Override
    public void changeSatus(Integer t, String username) {
        personaMapper.changeStatus(t, username);
    }
}

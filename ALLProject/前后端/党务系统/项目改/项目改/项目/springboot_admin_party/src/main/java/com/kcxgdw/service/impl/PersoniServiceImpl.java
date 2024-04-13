package com.kcxgdw.service.impl;
import cn.hutool.core.codec.Base64;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.github.pagehelper.Page;
import com.github.pagehelper.PageHelper;
import com.kcxgdw.mapper.PersonaMapper;
import com.kcxgdw.mapper.PersoniMapper;
import com.kcxgdw.mapper.StudentMapper;
import com.kcxgdw.obj.PageBean;
import com.kcxgdw.obj.Persona;
import com.kcxgdw.obj.Personi;
import com.kcxgdw.service.PersoniService;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.io.UnsupportedEncodingException;
import java.net.URLDecoder;
import java.nio.charset.StandardCharsets;
import java.time.LocalDate;
import java.util.List;
@Slf4j
@Service
public class PersoniServiceImpl  implements PersoniService {

    @Autowired
    private PersoniMapper personiMapper;
    @Autowired
    private StudentMapper studentMapper;


    @Override
    public PageBean page(Integer pagenum, Integer pagesize, String id, String grade, String major, String name, String status,LocalDate det_time, String cul_people, String qua ,LocalDate birthday) throws UnsupportedEncodingException {
        PageHelper.startPage(pagenum,pagesize);
        List<Personi>personiList=personiMapper.list(id, grade, major, name,status, det_time, cul_people, qua , birthday);
        for (int i = 0; i < personiList.size(); i++) {
            if(personiList.get(i).getPhoneNum() != null && personiList.get(i).getPhoneNum().length() != 11){
                personiList.get(i).setPhoneNum(URLDecoder.decode(new String(new Base64().decode(personiList.get(i).getPhoneNum()), "utf-8"), "utf-8"));
            }
            if (personiList.get(i).getIdNum() != null && personiList.get(i).getIdNum() != "") {
                if (personiList.get(i).getIdNum().length() == 18) {
                    personiList.get(i).setIdNum(Base64.encode(personiList.get(i).getIdNum().getBytes(StandardCharsets.UTF_8)));
                    update(personiList.get(i));
                }
            }
        }
        Page<Personi>p=(Page<Personi>)personiList;
        PageBean pageBean =new PageBean(p.getTotal(),p.getResult());
        return pageBean;
    }

    @Override
    public List<Personi> list(Integer pagenum, Integer pagesize, String id, String grade, String major, String name, String status, LocalDate det_time, String cul_people, String qua ,LocalDate birthday) throws UnsupportedEncodingException {
        List<Personi>personiList=personiMapper.list(id, grade, major, name,status, det_time, cul_people, qua , birthday);
        for (int i = 0; i < personiList.size(); i++) {

            if(personiList.get(i).getPhoneNum() != null && personiList.get(i).getPhoneNum().length()!= 11){
                personiList.get(i).setPhoneNum(URLDecoder.decode(new String(new Base64().decode(personiList.get(i).getPhoneNum()), "utf-8"), "utf-8"));
            }
            if (personiList.get(i).getIdNum() != null) {
                if (personiList.get(i).getIdNum().length() == 18) {
                    personiList.get(i).setIdNum(Base64.encode(personiList.get(i).getIdNum().getBytes(StandardCharsets.UTF_8)));
                    update(personiList.get(i));
                }
            }
        }
        return personiList;

    }
    @Override
    public Personi selectOne(String id) throws UnsupportedEncodingException {
        Personi personi = personiMapper.getOne(id);
        if(personi.getPhoneNum().length() != 11 && personi.getPhoneNum() != null){
            personi.setPhoneNum(URLDecoder.decode(new String(new Base64().decode(personi.getPhoneNum()), "utf-8"), "utf-8"));
        }
        return personi;
    }
    @Override
    public void save(Personi personi) {
        personiMapper.insert(personi);
    }
    //根据学生学号查找信息
    @Override
    public Personi getByStudentPersoni(String username) throws UnsupportedEncodingException {
        Personi personi = studentMapper.getByStudentPersoni(username);
        if(personi.getPhoneNum().length() != 11 && personi.getPhoneNum() != null){
            personi.setPhoneNum(URLDecoder.decode(new String(new Base64().decode(personi.getPhoneNum()), "utf-8"), "utf-8"));
        }
        return personi;
    }
    //更新学生信息
    @Override
    public void update(Personi personi){
        if(personi.getIdNum() != null){
            personi.setBirthday(personi.getBirthday2(personi.getIdNum()));
            personi.setIdNum(Base64.encode(personi.getIdNum().getBytes(StandardCharsets.UTF_8)));
        }
        if (personi.getPhoneNum() != null){
            personi.setPhoneNum(Base64.encode(personi.getPhoneNum().getBytes(StandardCharsets.UTF_8)));
        }
        studentMapper.update(personi);
    }
    @Override
    public void delete(String username){ personiMapper.delete(username);}
}

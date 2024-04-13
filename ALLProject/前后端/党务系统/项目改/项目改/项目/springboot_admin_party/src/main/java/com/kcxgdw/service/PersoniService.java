package com.kcxgdw.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.kcxgdw.obj.PageBean;
import com.kcxgdw.obj.Personi;
import org.springframework.format.annotation.DateTimeFormat;

import java.io.UnsupportedEncodingException;
import java.time.LocalDate;
import java.util.List;

public interface PersoniService  {
    PageBean page(Integer pagenum, Integer pagesize,
                  String id, String grade, String major, String name, String status,LocalDate det_time, String cul_people, String qua,LocalDate birthday) throws UnsupportedEncodingException;

    List<Personi> list(Integer pagenum, Integer pagesize, String id, String grade, String major, String name, String status, LocalDate detTime, String culPeople, String qua,LocalDate birthday) throws UnsupportedEncodingException;

    Personi selectOne(String id) throws UnsupportedEncodingException;
    /**
     * 新增
     * @param personi
     */
    void save(Personi personi);

    /**
     * 新增
     * @param
     */
    Personi getByStudentPersoni(String username) throws UnsupportedEncodingException;
    /**
     * 更新学生信息
     * @param
     */
    void update(Personi student) ;
    void delete(String username);

}

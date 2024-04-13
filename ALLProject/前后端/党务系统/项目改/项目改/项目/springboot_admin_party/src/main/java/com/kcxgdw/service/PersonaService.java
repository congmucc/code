package com.kcxgdw.service;

import com.kcxgdw.mapper.PersonaMapper;
import com.kcxgdw.obj.PageBean;
import com.kcxgdw.obj.Persona;
import org.springframework.beans.factory.annotation.Autowired;

import java.util.List;
import java.util.Map;

public interface PersonaService {
    /**
     * 分页查询人员账号
     * @return
     */
    PageBean page(Integer pagenum, Integer pagesize,String username);


    /**
     * 批量删除
     * @param
     */
    void delete(String username);

    /**
     * 重置
     * @param ids
     */
    void updata(List<Integer> ids, Integer t);

    /**
     * 新增
     * @param persona
     */
    void save(Persona persona);


    /**
     * 存在判断
     * @param username
     * @return
     */
    boolean exist(String username);

    /**
     * 学生登录
     * @param persona
     * @return
     */
    Persona login(Persona persona);

    //学生邮箱修改
    void emailupdate(Persona persona);

    Persona getStudentPersona(String username);


    void updateStuPsw(String username, String password);

    String getCode(String username, String email);

    /**
     * 权限管理
     */
    void changeSatus(Integer t, String username);
}

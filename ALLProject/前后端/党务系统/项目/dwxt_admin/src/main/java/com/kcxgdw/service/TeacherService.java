package com.kcxgdw.service;

import com.kcxgdw.obj.Administrator;

import java.util.Map;

public interface TeacherService {

    /**
     * 登录
     * @param administrator
     * @return
     */
    Administrator login(Administrator administrator);

    /**
     * 刷新
     * @param username
     * @return
     */
    Administrator getUser(String username);
    /**
     * 更新
     * @param administrator
     * @return
     */
    void upload(Administrator administrator);

    /**
     * 修改密码
     * @param administrator
     */
    /**
     *
     * @param username
     * @param email
     * @return
     */
    String getCode(String username, String email);



    void updateTeaPsw(String username, String password);

    /**
     * 修改老师的登录状态
     * @param t
     * @param username
     */
    void changeSatus(Integer t, String username);
}

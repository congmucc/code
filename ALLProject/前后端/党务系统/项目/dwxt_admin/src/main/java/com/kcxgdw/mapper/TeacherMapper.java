package com.kcxgdw.mapper;

import com.kcxgdw.obj.Administrator;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;
import org.apache.ibatis.annotations.Update;

import java.util.Map;

@Mapper
public interface TeacherMapper {

    /**
     * 根据用户名密码查询
     * @param administrator
     * @return
     */
    @Select("select * from administrator where username=#{username} and password=#{password}")
    Administrator getByUsernameAndPassword(Administrator administrator);

    /**
     * 刷新
     * @return
     */
    @Select("select * from administrator where username=#{username}")
    Administrator getUserInformation(String username);

    /**
     * 更新邮箱
     * @param administrator
     */
    @Update("update administrator set email=#{email} where username=#{username}")
    void upload(Administrator administrator);

    /**
     * 验证邮箱正确
     * @param username
     * @param email
     * @return
     */
    boolean existEmail(String username, String email);

    /**
     * 更新密码
     * @param username
     * @param password
     */
    @Update("update administrator set password=#{password} where username=#{username}")
    void updateTeaPsw(String username, String password);

    /**
     * 修改老师的登录状态
     * @param t
     * @param username
     */
    void changeStatus(Integer t, String username);
}

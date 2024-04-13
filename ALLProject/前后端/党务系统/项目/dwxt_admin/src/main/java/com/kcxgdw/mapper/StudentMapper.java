package com.kcxgdw.mapper;

import com.kcxgdw.obj.Administrator;
import com.kcxgdw.obj.Persona;
import com.kcxgdw.obj.Personi;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;
import org.apache.ibatis.annotations.Update;

import java.util.Map;

@Mapper
public interface StudentMapper {
    /**
     * 根据学号查询学生账号信息
     * @param
     *
     */
    @Select("select * from persona where username=#{username} and password=#{password}")
    Persona getByUsernameAndPassword(Persona persona);
    /**
     * 修改密码
     * @param
     */
    @Update("update personi set password=#{new_pwd} where id=#{id}")
    void uploadpwd(Map<String, Object> params);
    /**
     * 根据学号查询学生信息
     * @param
     *
     */
    @Select("select * from personi where id=#{username}")
    Personi getByStudentPersoni(String username);
    /**
     * 学生修改信息
     * @param
     */
    @Update("UPDATE personi " +
            "SET name=#{name}, " +
            "status=#{status}, " +
            "grade=#{grade}, " +
            "major=#{major}, " +
            "class_num=#{classNum}, " +
            "id_num=#{idNum}, " +
            "hometown=#{hometown}, " +
            "phone_num=#{phoneNum}, " +
            "joining_time=#{joiningTime}, " +
            "joining_school=#{joiningSchool}, " +
            "home_address=#{homeAddress}, " +
            "pub_time=#{pubTime}, " +
            "sub_time=#{subTime}, " +
            "det_time=#{detTime}, " +
            "del_time=#{delTime}, " +
            "fil_time=#{filTime}, " +
            "cul_people=#{culPeople}, " +
            "`condition`=#{condition}, " +
            "tra_time=#{traTime}, " +
            "com_time=#{comTime}, " +
            "qua=#{qua}, " +
            "birthday=#{birthday} " +
            "WHERE id=#{id}")
    void update(Personi student);
    /**
     * 根据学号查询学生账号信息
     * @param
     *
     */
    @Select("select * from persona where username=#{username}")
    Persona getByStudentPersona(String username);
    /**
     * 学生修改邮箱
     * @param
     *
     */
    @Update("update persona set email=#{email} where username=#{username}")
    void emailupdate(Persona persona);
    /**
     * 修改密码
     * @param
     */
    @Update("update persona set password=#{password} where username=#{username}")
    void updateStuPsw(String username, String password);

    boolean existEmail(String username, String email);
}
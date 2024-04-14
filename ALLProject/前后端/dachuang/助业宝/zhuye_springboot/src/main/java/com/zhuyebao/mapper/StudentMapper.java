package com.zhuyebao.mapper;

import com.zhuyebao.obj.Campus;
import com.zhuyebao.obj.StuBM;
import com.zhuyebao.obj.Student;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;
import org.apache.ibatis.annotations.Update;

import java.util.List;

@Mapper
public interface StudentMapper {

     //查找学生信息
    List<Student> findAll(String username);
    //修改
    @Update("update student set " +
            "name=#{name},avator=#{avator},university=#{university},college=#{college},major=#{major},phone=#{phone},id_card=#{id_card},ability=#{ability},volun_certify=#{volun_certify},profess_certify=#{profess_certify}" +
            " where username=#{username} ")
    void update(Student student);

    //删除
    void deleteById(Long id);
   //返回状态值
    Integer findByState(Integer stuId);
    //认证
    @Update("update student set stu_id=1 where username=#{username}")
    void authentication(String username, Integer stuId);

    @Select("select * from student where username = #{username}")
    Student unauthorized(String username);

    @Insert("INSERT INTO stu_activity_sh" +
            "(id,username,institution_id,campus_id,content,state)" +
            "values " +
            "(#{id},#{username},#{institutionId},#{campusId},#{content},#{state})")
    void application(StuBM stuBM);
    //报名中的信息
    @Select("SELECT * FROM stu_activity_sh WHERE state = 0")
    List<StuBM> weiShenHe();
     @Update("update stu_activity_sh set state = 1 where id =#{id}")
    void tongGuo(Long id, Long state);

    //存入数据库
    @Insert("insert into campus_will(id,name,time,content,place,goods,number,institution_id,state,group) values(#{id},#{name},#{time},#{content},#{place},#{goods},#{number},#{institutionId},#{state},#{group})")
    void addActivity(Campus campus);
    @Select("select state from campus_will where id = #{id}")
    String findAct(Long id);
    @Select("select content from stu_activity_ed where id =#{id}")
    String assess(Long id);
    @Update("update stu_activity_ed set stu_act where username =#{username}")
    void addActZ(String username, String stuAct);
    //返回地址
    @Select("select stuAct from student where username = #{username}")
    String activityProof(String username);

}

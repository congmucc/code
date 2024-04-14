package com.zhuyebao.mapper;

import com.zhuyebao.obj.*;
import org.apache.ibatis.annotations.*;

import java.util.List;

@Mapper
public interface AdministrationMapper {
    /**
     * 高校登录
     * @param username
     * @param password
     * @return
     */
    @Select("select * from administration where username=#{username} and password=#{password}")
    Administration login(String username, String password);

    @Update("update student set volunteer=#{volunteer} where username=#{username}")
    void auditVolunteer(String username, String volunteer);
    @Update("update student set profess=#{profess} where username=#{username}")
    void auditProfess(String username, String profess);
    @Update("update student set state=#{state} where id=#{id}")
    void auditInstitution(Integer id, String state);
    @Select("select * from student where volunteer = 1 and volun_certify != ''")
    List<Student> getAuditVolunteer();
    @Select("select * from student where profess = 1 and profess_certify != ''")
    List<Student> getAuditProfess();
    @Select("select * from institution where state = 0 and certify != null")
    List<Institution> getAuditInstitution();
    @Select("select * from campus_will")
    List<Campus> getCampusList();
    @Select("select * from job where state=1")
    List<Job> getJobList();
    @Select("select * from campus_will where id=#{id}")
    Campus getCampusById(Integer id);
    @Insert("insert into campus_ing(id,name,time,content,place,goods,number,institution_id) values(#{id},#{name},#{time},#{content},#{place},#{goods},#{number},#{institutionId})")
    void addCampusIng(Campus campus);
    @Delete("delete from campus_will where id=#{id} ")
    void deleteCampusWill(Integer id);
    @Update("update campus_will set state=3 where id=#{id}")
    void campusOk(Integer id);
    @Update("update campus_will set state=2,reject=#{reject} where id=#{id}")
    void campusNo(Integer id, String reject);
    @Update("update job set state=3 where id=#{id}")
    void jobOK(Integer id);
    @Update("update job set state=2,reject=#{reject} where id=#{id}")
    void jobNo(Integer id, String reject);
    @Update("update campus_will set state=4 where id=#{id}")
    void publishCampus(Integer id);
    @Update("update job set state=4 where id=#{id}")
    void publishJob(Integer id);
    @Select("select student.* from student,stu_activity_ing where stu_actiity_ing.id = #{id} and stu_actiity_ing.username = student.username")
    List<Student> getCampusStuList(Integer id);


    @Select("select * from student where volunteer = 0 and profess = 0")
    List<Student> getStudent();

    @Select("select * from institution where type = #{type}")
    List<Institution> getInstitution(String type);

    @Select("select * from administration")
    List<Administration> getAdministration(Integer id);

    /**
     * 删除act
     * @param id
     */
    @Delete("delete from institution where id = #{id}")
    void deleteInst(Integer id);

    /**
     * 删除stu
     * @param username
     */
    @Delete("delete from student where username = #{username}")
    void deleteStu(String username);

    /**
     * 禁用公司 0为正常 1为黑名单
     * @param id
     */
    @Update("update institution set blacklist = 1 where id = #{id}")
    void updateInst(Integer id);
    /**
     * 启用公司 0为正常 1为黑名单
     * @param id
     */
    @Update("update institution set blacklist = 0 where id = #{id}")
    void ApproveInst(Integer id);
    /**
     * 禁用个人
     * @param username
     */
    @Update("update student set profess = '1' where username = #{username}")
    void updateStu(String username);


    /**
     * 启用个人
     * @param username
     */
    @Update("update student set profess = '0' where username = #{username}")
    void ApproveStu(String username);


    @Select("select * from student where username = #{username}")
    Student getStuByUsername(String username);
}

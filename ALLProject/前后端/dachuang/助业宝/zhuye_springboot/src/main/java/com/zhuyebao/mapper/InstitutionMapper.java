package com.zhuyebao.mapper;

import com.zhuyebao.obj.*;
import com.zhuyebao.obj.dto.InstitutionDto;
import org.apache.ibatis.annotations.*;

import java.util.List;

@Mapper
public interface InstitutionMapper {
    /**
     * 根据学号查询学生账号信息
     * @param
     *
     */
    @Select("select * from institution where username=#{username} and password=#{password}")
    Institution login(String username, String password);

    @Update("update institution set type=#{type},certify=#{certify} where id=#{id}")
    void authen(Institution institution);
    @Select("select * from institution where id=#{id}")
    Institution getAuthenticationById(Integer id);
    @Insert("insert into campus_will(id,name,time,content,place,goods,number,institution_id,state,`group`) values(#{id},#{name},#{time},#{content},#{place},#{goods},#{number},#{institutionId},#{state},#{group})")
    void campusActivity(Campus campus);
    @Insert("insert into job(id,name,time,content,place,demand,phone,institution_id,salary,state) values(#{id},#{name},#{time},#{content},#{place},#{demand},#{phone},#{institutionId},#{salary},#{state})")

    void jobActivity(Job job);
    @Select("select * from stu_activity_end")
    List<StuCampus> getCampusFeedback();
    @Update("update stu_activity_end set feedback_institution=#{feedbackInstitution} where id=#{id}")
    void campusActivityFeedback(StuCampus stuCampus);

    /**
     * 机构根据状态请求job列表
     * @param institutionId 机构id
     * @param state 状态非空（0全部，1审核中，2驳回，3申请成功）、默认：0
     * @return
     */
    List<Job> getAllJob(@Param("institutionId") Integer institutionId, @Param("state") String state);

    /**
     * 机构根据状态请求act列表
     * @param institutionId 机构id
     * @param state 状态非空（0全部，1审核中，2驳回，3申请成功）、默认：0
     * @return
     */
    List<Campus> getAllActivity(Integer institutionId, String state);

    @Select("select * from job where id = #{id}")
    Job getJobById(Integer id);

    @Select("select * from campus_will where id = #{id}")
    Campus getActById(Integer id);


    /**
     * 修改job
     * @param job
     */
    void updateJob(Job job);

    /**
     * 修改act
     * @param campus
     */
    void updateCampus(Campus campus);

    /**
     * 删除act
     * @param id
     */
    @Delete("delete from campus_will where id = #{id}")
    void deleteCampus(Integer id);

    /**
     * 删除job
     * @param id
     */
    @Delete("delete from job where id = #{id}")
    void deleteJob(Integer id);

    @Update("update institution set name = #{name}, email = #{email}, type = #{type}, certify = #{certify} where id = #{id}")
    void updateInfo(Institution institution);

    /**
     * 更新机构信息
     * @param institution
     * @return
     */
    void updatePartInfo(Institution institution);

    /**
     * 通过id查询已完成活动反馈列表
     * @param id
     * @return
     */
    @Select("select * from stu_activity_end where institution_id = #{id}")
    List<StuCampus> getCampusFeedbackById(Integer id);

    /**
     * 通过id修改正在进行活动反馈列表
     * @return
     */
    @Update("update stu_activity_ing set feedback_institution=#{feedbackInstitution} where id=#{id}")
    void campusActIngFeedback(StuCampus stuCampus);

    /**
     * 通过id查询正在进行活动反馈列表
     * @param id
     * @return
     */
    @Select("select * from stu_activity_ing where institution_id = #{id}")
    List<StuCampus> getCampusIngFeedbackById(Integer id);

    /**
     * 通过id查询正兼职反馈列表
     * @param id
     * @return
     */
    @Select("select * from stu_job_activity where institution_id = #{id}")
    List<StuJob> getJobFeedbackById(Integer id);

    /**
     * 修改兼职活动反馈
     * @param stuCampus
     * @return
     */
    @Update("update stu_job_activity set feedback_institution=#{feedbackInstitution} where id=#{id}")
    void jobFeedback(StuCampus stuCampus);


}

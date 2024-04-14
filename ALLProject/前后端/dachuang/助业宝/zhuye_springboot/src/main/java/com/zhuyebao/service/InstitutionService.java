package com.zhuyebao.service;

import com.zhuyebao.obj.*;
import com.zhuyebao.obj.dto.InstitutionDto;
import com.zhuyebao.obj.dto.StuCampusDto;
import org.springframework.web.multipart.MultipartFile;

import java.io.IOException;
import java.util.List;

public interface InstitutionService {
    Institution login(String username, String password);

    void authen(Institution institution);

    Institution getAuthenticationById(Integer id);

    void campusActivity(Campus campus);

    void jobActivity(Job job);

    List<StuCampus> getCampusFeedback();

    void campusActivityFeedback(StuCampus stuCampus);

    /**
     * 机构根据状态请求job列表
     * @param institutionId 机构id
     * @param state 状态非空（0全部，1审核中，2驳回，3申请成功）、默认：0
     * @return
     */
    PageBean getAllJob(Integer institutionId, String state, Integer page, Integer pageSize);

    /**
     * 机构根据状态请求act列表
     * @param institutionId 机构id
     * @param state 状态非空（0全部，1审核中，2驳回，3申请成功）、默认：0
     * @return
     */
    PageBean getAllActivity(Integer institutionId, String state, Integer page, Integer pageSize);

    /**
     * 用户通过id查询单个job
     * @param id id
     * @return
     */
    Job getJobById(Integer id);

    /**
     * 修改job
     * @param job
     * @return
     */
    void updateJob(Job job);

    /**
     * 通过id查询单个act活动
     * @param id
     * @return
     */
    Campus getActById(Integer id);


    /**
     * 修改act
     * @param campus
     */
    void updateCampus(Campus campus);

    /**
     * 删除act
     * @param id
     */
    void deleteCampus(Integer id);

    /**
     * 删除job
     * @param id
     */
    void deleteJob(Integer id);

    /**
     * 更新机构信息
     * @param institutionDto
     */
    void updateInfo(InstitutionDto institutionDto) throws IOException;

    /**
     * 更新机构信息
     * @param institution
     * @return
     */
    void updatePartInfo(Institution institution);

    /**
     * 上传图片
     * @param file
     * @return
     */
    String uploadImg(MultipartFile file) throws IOException;



    /**
     * 通过id查询已完成活动反馈列表
     * @param id
     * @return
     */
    List<StuCampusDto> getCampusFeedbackById(Integer id);

    /**
     * 修改正在进行的活动反馈
     * @param stuCampus
     */
    void campusActIngFeedback(StuCampus stuCampus);

    /**
     * 通过id查询正在进行活动反馈列表
     * @param id
     * @return
     */
    List<StuCampusDto> getCampusIngFeedbackById(Integer id);

    /**
     * 通过id查询正兼职反馈列表
     * @param id
     * @return
     */
    List<StuCampusDto> getJobFeedbackById(Integer id);

    /**
     * 修改兼职活动反馈
     * @param stuCampus
     * @return
     */
    void JobFeedback(StuCampus stuCampus);


}

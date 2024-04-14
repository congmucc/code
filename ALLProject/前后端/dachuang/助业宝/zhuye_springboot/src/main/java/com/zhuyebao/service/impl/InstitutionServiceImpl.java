package com.zhuyebao.service.impl;

import com.github.pagehelper.Page;
import com.github.pagehelper.PageHelper;
import com.zhuyebao.mapper.InstitutionMapper;
import com.zhuyebao.obj.*;
import com.zhuyebao.obj.dto.InstitutionDto;
import com.zhuyebao.obj.dto.StuCampusDto;
import com.zhuyebao.service.InstitutionService;
import com.zhuyebao.utils.ZYBThreadLocal;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import com.zhuyebao.obj.PageBean;
import org.springframework.web.multipart.MultipartFile;

import java.io.File;
import java.io.IOException;
import java.util.*;


@Slf4j
@Service
public class InstitutionServiceImpl implements InstitutionService {
    @Autowired
    private InstitutionMapper institutionMapper;

    /**
     * 登录
     * @param username
     * @param password
     * @return
     */
    @Override
    public Institution login(String username, String password) {
        Institution institution = institutionMapper.login(username,password);
        return institution;
    }

    /**
     * 机构认证
     * @param institution
     */
    @Override
    public void authen(Institution institution) {
        System.out.println("修改认证" +institution);
        institutionMapper.authen(institution);
    }

    @Override
    public Institution getAuthenticationById(Integer id) {
        Institution institution = institutionMapper.getAuthenticationById(id);
        return institution;
    }

    @Override
    public void campusActivity(Campus campus) {
        institutionMapper.campusActivity(campus);
    }

    @Override
    public void jobActivity(Job job) {
        institutionMapper.jobActivity(job);
    }

    @Override
    public List<StuCampus> getCampusFeedback() {
        return institutionMapper.getCampusFeedback();
    }

    @Override
    public void campusActivityFeedback(StuCampus stuCampus) {
        institutionMapper.campusActivityFeedback(stuCampus);
    }

    /**
     * 机构根据状态请求job列表
     * @param institutionId 机构id
     * @param state 状态非空（0全部，1审核中，2驳回，3申请成功）、默认：0
     * @return
     */
    @Override
    public PageBean getAllJob(Integer institutionId, String state, Integer page, Integer pageSize) {
        // 分页
        PageHelper.startPage(page,pageSize);
        List<Job> allJob = institutionMapper.getAllJob(institutionId, state);
        Page<Job> p =  (Page<Job>) allJob;
        PageBean pageBean = new PageBean(p.getTotal(),p.getResult());
        return pageBean;
    }

    /**
     * 用户通过id查询单个job
     * @param id id
     * @return
     */
    @Override
    public Job getJobById(Integer id) {
        return institutionMapper.getJobById(id);
    }

    /**
     * 修改job
     * @param job
     */
    @Override
    public void updateJob(Job job) {
        job.setState("1");
        // 这里需要从jwt中解析出用户的id，然后插入，开发环境用 0
        Integer currentId = ZYBThreadLocal.getCurrentId();
        job.setInstitutionId(currentId);
        if (job.getId() != 0){
            institutionMapper.updateJob(job);
        } else {
            institutionMapper.jobActivity(job);
        }
    }

    /**
     * 机构根据状态请求act列表
     * @param institutionId 机构id
     * @param state 状态非空（0全部，1审核中，2驳回，3申请成功）、默认：0
     * @return
     */
    @Override
    public PageBean getAllActivity(Integer institutionId, String state, Integer page, Integer pageSize) {
        PageHelper.startPage(page,pageSize);
        List<Campus> allJob = institutionMapper.getAllActivity(institutionId, state);
        Page<Campus> p =  (Page<Campus>) allJob;
        PageBean pageBean = new PageBean(p.getTotal(),p.getResult());
        return pageBean;
    }

    /**
     * 用户通过id查询单个act
     * @param id id
     * @return
     */
    @Override
    public Campus getActById(Integer id) {
        return institutionMapper.getActById(id);
    }

    /**
     * 修改act
     * @param campus
     */
    @Override
    public void updateCampus(Campus campus) {
        campus.setState("1");
        Integer currentId = ZYBThreadLocal.getCurrentId();
        campus.setInstitutionId(currentId);
        if (campus.getId() != 0){
            institutionMapper.updateCampus(campus);
        } else {
            institutionMapper.campusActivity(campus);
        }
    }

    /**
     * 删除act
     * @param id
     */
    @Override
    public void deleteCampus(Integer id) {
        institutionMapper.deleteCampus(id);
    }

    /**
     * 删除job
     * @param id
     */
    @Override
    public void deleteJob(Integer id) {
        institutionMapper.deleteJob(id);
    }

    /**
     * 更新机构信息
     * @param institutionDto
     */
    @Override
    public void updateInfo(InstitutionDto institutionDto) throws IOException {
        /**
         * 按理来说这里的逻辑应该是使用一个审核，这里应该先新建一个属性保存用户名称和图片等信息
         * 审核之后将审核成功的信息存入这个用户上。同时存到之后再把原本的图片删除，这些都是管理端的事情。
         * TODO 这里有几种情况，
         * 1、 没认证的人认证
         * 2、 认证的人添加图片
         * 3、 认证的人删除图片
         * 4、 认证的人删除图片之后添加图片认证
         *
         * 现在这里先写成只添加，不考虑删除。
         */

        // TODO 这里写一个删除图片的操作，如果多次进行证明，需要删除之前的图片 根据id进行查询，然后进行删除
        Institution institution = new Institution();
        BeanUtils.copyProperties(institutionDto,institution);
        ArrayList<String> strings = new ArrayList<>();
        Institution authenticationById = institutionMapper.getAuthenticationById(institutionDto.getId());
        String[] certifyArray = authenticationById.getCertify().split(",");
        // 这里通过id查询图片，将图片先加入strings中。
        for (String imgPath : certifyArray) {
            if (!imgPath.isEmpty()) {
                strings.add(imgPath);
            }
        }
        for (MultipartFile file : institutionDto.getFiles()) {
            // TODO 保存到本地文件 这里先暂存到本地
            String originalFilename = file.getOriginalFilename();
            String end = originalFilename.substring(originalFilename.lastIndexOf(".") + 1);
            String uName = UUID.randomUUID().toString();
            String newName = uName + "." +  end;
            //将文件保存到本地
            file.transferTo(new File("D:\\images\\uploadimg\\" + newName));
            strings.add("http://192.168.161.164:8090/uploadimg/" + newName);
        }

        institution.setCertify(String.join(",", strings));
        institutionMapper.updateInfo(institution);
    }

    /**
     * 更新机构信息
     * @param institution
     * @return
     */
    @Override
    public void updatePartInfo(Institution institution) {
        institutionMapper.updatePartInfo(institution);
    }

    /**
     * 自动上传图片
     * @param file
     * @return
     * @throws IOException
     */
    @Override
    public String uploadImg(MultipartFile file) throws IOException {
        String originalFilename = file.getOriginalFilename();
        String end = originalFilename.substring(originalFilename.lastIndexOf(".") + 1);
        String uName = UUID.randomUUID().toString();
        String newName = uName + "." +  end;
        //将文件保存到本地
        file.transferTo(new File("D:\\images\\uploadimg\\" + newName));
        return ("http://192.168.69.164:8090/uploadimg/" + newName);
    }

    /**
     * 通过id查询已完成活动反馈列表
     * @param id
     * @return
     */
    @Override
    public List<StuCampusDto> getCampusFeedbackById(Integer id) {
        List<StuCampus> campusFeedbackById = institutionMapper.getCampusFeedbackById(id);
        List<StuCampusDto> list = new ArrayList<>();
        for (StuCampus stuCampus : campusFeedbackById) {
            Campus act = institutionMapper.getActById(stuCampus.getCampusId());
            if (act == null) continue;

            StuCampusDto stuCampusDto = new StuCampusDto();
            BeanUtils.copyProperties(stuCampus, stuCampusDto);
            stuCampusDto.setInstitutionId(act.getName());
            list.add(stuCampusDto);
        }
        return list;
    }

    /**
     * 通过id查询正在进行活动反馈列表
     * @param id
     * @return
     */
    @Override
    public List<StuCampusDto> getCampusIngFeedbackById(Integer id) {
        List<StuCampus> campusFeedbackById = institutionMapper.getCampusIngFeedbackById(id);
        List<StuCampusDto> list = new ArrayList<>();
        for (StuCampus stuCampus : campusFeedbackById) {
            Campus act = institutionMapper.getActById(stuCampus.getCampusId());
            if (act == null) continue;

            StuCampusDto stuCampusDto = new StuCampusDto();
            BeanUtils.copyProperties(stuCampus, stuCampusDto);
            stuCampusDto.setInstitutionId(act.getName());
            list.add(stuCampusDto);
        }
        return list;
    }

    /**
     * 修改正在进行的活动反馈
     * @param stuCampus
     */
    @Override
    public void campusActIngFeedback(StuCampus stuCampus) {
        institutionMapper.campusActIngFeedback(stuCampus);
    }


    /**
     * 通过id查询正兼职反馈列表
     * @param id
     * @return
     */
    @Override
    public List<StuCampusDto> getJobFeedbackById(Integer id) {
        List<StuJob> campusFeedbackById = institutionMapper.getJobFeedbackById(id);

        List<StuCampusDto> list = new ArrayList<>();
        for (StuJob stuCampus : campusFeedbackById) {
            System.out.println( "输出的值： "+ stuCampus);
            Job act = institutionMapper.getJobById(stuCampus.getJobId());
            if (act == null) continue;
            StuCampusDto stuCampusDto = new StuCampusDto();
            BeanUtils.copyProperties(stuCampus, stuCampusDto);
            stuCampusDto.setInstitutionId(act.getName());
            list.add(stuCampusDto);
        }
        return list;
    }


    /**
     * 修改兼职活动反馈
     * @param stuCampus
     * @return
     */
    @Override
    public void JobFeedback(StuCampus stuCampus) {
        institutionMapper.jobFeedback(stuCampus);
    }
}

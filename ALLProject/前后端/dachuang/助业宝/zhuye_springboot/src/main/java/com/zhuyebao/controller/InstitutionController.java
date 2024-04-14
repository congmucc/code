package com.zhuyebao.controller;


import com.zhuyebao.obj.*;
import com.zhuyebao.obj.dto.InstitutionDto;
import com.zhuyebao.obj.dto.StuCampusDto;
import com.zhuyebao.service.InstitutionService;
import com.zhuyebao.utils.JwtUtils;
import com.zhuyebao.utils.Result;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import java.io.IOException;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

@Slf4j
@RestController
@RequestMapping("/zyb/institution")
public class InstitutionController {
    @Autowired
    private InstitutionService institutionService;
    @PostMapping("/login")
    public Result login(@RequestParam("username") String username, @RequestParam("password") String password){
        Institution institution = institutionService.login(username,password);
        if(institution == null){
           return Result.error("账号不存在");
        }
        Map<String, Object> claims = new HashMap<>();
        claims.put("username", username);
        claims.put("id", institution.getId());
        String token = JwtUtils.generateJwt(claims);
        claims.put("token", token);
        return Result.success(claims);
    }
    @PutMapping("/authen")
    public Result authen(@RequestBody Institution institution){
        institutionService.authen(institution);
        return Result.success("提交成功");
    }
    @GetMapping("/authen")
    public Result getAuthenticationById(@RequestParam Integer id){
        Institution institution = institutionService.getAuthenticationById(id);
        return Result.success(institution);
    }
    @PutMapping("/campus")
    public Result campusActivity(@RequestBody Campus campus){
        institutionService.campusActivity(campus);
        return Result.success("提交成功");
    }
    @PutMapping("/job")
    public Result jobActivity(@RequestBody Job job){
        institutionService.jobActivity(job);
        return Result.success("提交成功");
    }
    @GetMapping("/activity/feedback")
    public Result getCampusFeedback(){
        List<StuCampus> stuCampusListList = institutionService.getCampusFeedback();
        return Result.success(stuCampusListList);
    }
    @PutMapping("/activity/feedback")
    public Result campusActivityFeedback(@RequestBody StuCampus stuCampus){
        institutionService.campusActivityFeedback(stuCampus);
        return Result.success("反馈成功");
    }


    /**
     * 机构根据状态请求job列表
     * @param institutionId 机构id
     * @param state 状态非空（0全部，1审核中，2驳回，3申请成功）、默认：0
     * @return
     */
    @GetMapping("/job")
     public Result getAllJob(@RequestParam(value = "institutionId", required = false) Integer institutionId, @RequestParam("state") String state,
                             @RequestParam("page") Integer page, @RequestParam("pageSize") Integer pageSize) {
        return Result.success(institutionService.getAllJob(institutionId, state, page, pageSize));
     }

    /**
     * 用户通过id查询单个job
     * @param id id
     * @return
     */
    @GetMapping("/job/{id}")
     public Result getJobById(@PathVariable Integer id) {
        return Result.success(institutionService.getJobById(id));
     }


    /**
     * 修改和插入job
     * @param job
     * @return
     */
     @PostMapping("/job/update")
     public Result updateJob(@RequestBody Job job) {
         institutionService.updateJob(job);
         return Result.success("修改成功");
     }


    /**
     * 机构根据状态请求act列表
     * @param institutionId 机构id
     * @param state 状态非空（0全部，1审核中，2驳回，3申请成功）、默认：0
     * @return
     */
    @GetMapping("/act")
    public Result getAllActivity(@RequestParam(value = "institutionId", required = false) Integer institutionId, @RequestParam("state") String state,
                            @RequestParam("page") Integer page, @RequestParam("pageSize") Integer pageSize) {
        return Result.success(institutionService.getAllActivity(institutionId, state, page, pageSize));
    }


    /**
     * 用户通过id查询单个活动
     * @param id id
     * @return
     */
    @GetMapping("/act/{id}")
    public Result getActById(@PathVariable Integer id) {
        return Result.success(institutionService.getActById(id));
    }

    /**
     * 修改和插入activity
     * @param campus act
     * @return
     */
    @PostMapping("/act/update")
    public Result updateCampus(@RequestBody Campus campus) {
        institutionService.updateCampus(campus);
        return Result.success("修改成功");
    }

    /**
     * 删除activity
     * @param id
     * @return
     */
    @DeleteMapping("/act/del")
    public Result deleteActivity(@RequestParam("id") Integer id) {
        institutionService.deleteCampus(id);
        return Result.success("删除成功");
    }

    /**
     * 删除job
     * @param id
     * @return
     */
    @DeleteMapping("/job/del")
    public Result deleteJob(@RequestParam("id") Integer id) {
        System.out.println("删除的值为： "+ id);
        institutionService.deleteJob(id);
        return Result.success("删除成功");
    }


    /**
     * 更新机构信息
     * 暂时不用
     * @param institutionDto
     * @return
     */
    @PostMapping("/update/info")
    public Result updateInfo(@ModelAttribute  InstitutionDto institutionDto) throws IOException {

        for (MultipartFile file : institutionDto.getFiles()) {
            System.out.println("过来的： " + file.getOriginalFilename());
        }
        for (String deleteFile : institutionDto.getDeleteFiles()) {
            System.out.println("删除的： " + deleteFile);
        }
        institutionService.updateInfo(institutionDto);
        return Result.success();
    }


    /**
     * 更新机构信息
     * @param institution
     * @return
     */
    @PostMapping("/update/partinfo")
    public Result updatePartInfo(@RequestBody Institution institution) {
        institutionService.updatePartInfo(institution);
        return Result.success("修改成功");
    }

    /**
     * 上传文件图片
     * @param file
     * @return
     * @throws IOException
     */
    @PostMapping("/upload")
    public Result uploadImg(@RequestParam("file") MultipartFile file) throws IOException {
        return Result.success(institutionService.uploadImg(file));
    }

    /**
     * 通过id查询已完成活动反馈列表
     * @param id
     * @return
     */
    @GetMapping("/actend/feedback")
    public Result getCampusEndFeedbackById(@RequestParam("id") Integer id){
        List<StuCampusDto> stuCampusListList = institutionService.getCampusFeedbackById(id);
        return Result.success(stuCampusListList);
    }



    /**
     * 通过id查询正在进行活动反馈列表
     * @param id
     * @return
     */
    @GetMapping("/acting/feedback")
    public Result getCampusIngFeedbackById(@RequestParam("id") Integer id){
        List<StuCampusDto> stuCampusList = institutionService.getCampusIngFeedbackById(id);
        return Result.success(stuCampusList);
    }


    /**
     * 修改正在进行的活动反馈
     * @param stuCampus
     * @return
     */
    @PutMapping("/acting/feedback")
    public Result campusActIngFeedback(@RequestBody StuCampus stuCampus){
        institutionService.campusActIngFeedback(stuCampus);
        return Result.success("反馈成功");
    }




    /**
     * 通过id查询正兼职反馈列表
     * @param id
     * @return
     */
    @GetMapping("/job/feedback")
    public Result getJobFeedbackById(@RequestParam("id") Integer id){
        List<StuCampusDto> stuCampusList = institutionService.getJobFeedbackById(id);
        return Result.success(stuCampusList);
    }


    /**
     * 修改兼职活动反馈
     * @param stuCampus
     * @return
     */
    @PutMapping("/job/feedback")
    public Result JobFeedback(@RequestBody StuCampus stuCampus){
        institutionService.JobFeedback(stuCampus);
        return Result.success("反馈成功");
    }


}

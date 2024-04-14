package com.zhuyebao.controller;

import com.zhuyebao.obj.*;
import com.zhuyebao.service.AdministrationService;
import com.zhuyebao.utils.JwtUtils;
import com.zhuyebao.utils.Result;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

@Slf4j
@RestController
@RequestMapping("/zyb/administration")
public class AdministrationController {
    @Autowired
    private AdministrationService administrationService;
    @PostMapping("/login")
    public Result login(@RequestParam("username") String username, @RequestParam("password") String password){
        Administration administration = administrationService.login(username,password);
        if(administration==null){
            return Result.error("账号不存在");
        }
        Map<String, Object> claims = new HashMap<>();
        claims.put("username", username);
        claims.put("id", administration.getId());
        String token = JwtUtils.generateJwt(claims);
        claims.put("token", token);
        return Result.success(claims);
    }
    //查询审核信息
    @GetMapping("/audit/volunteer")
    public Result getAuditVolunteer(){
        List<Student> studentList = administrationService.getAuditVolunteer();
        return Result.success(studentList);
    }
    @GetMapping("/audit/profess")
    public Result getAuditProfess(){
        List<Student> studentList = administrationService.getAuditProfess();
        return Result.success(studentList);
    }
    @GetMapping("/audit/institution")
    public Result getAuditInstitution(){
        List<Institution> institutionList = administrationService.getAuditInstitution();
        return Result.success(institutionList);
    }
    //身份审核
    @PutMapping("/audit/volunteer")
    public Result auditVolunteer(@RequestParam String username,@RequestParam String volunteer){
        administrationService.auditVolunteer(username,volunteer);
        return Result.success("审核成功");
    }
    @PutMapping("/audit/profess")
    public Result auditProfess(@RequestParam String username,@RequestParam String profess){
        administrationService.auditProfess(username,profess);
        return Result.success("审核成功");
    }
    @PutMapping("/audit/institution")
    public Result auditInstitution(@RequestParam Integer id,@RequestParam String state){
        administrationService.auditInstitution(id,state);
        return Result.success("审核成功");
    }
    //活动查询
    @GetMapping("/campus")
    public Result getCampusActivity(){
        List<Campus> campusList = administrationService.getCampusList();
        return Result.success(campusList);
    }
    @GetMapping("/job")
    public Result getJobActivity(){
        List<Job> jobList = administrationService.getJobList();
        return Result.success(jobList);
    }
    //活动审核
    @PutMapping("/audit/campus")
    public Result auditCampus(@RequestParam Integer id,@RequestParam boolean audit,@RequestParam(required = false) String reject){
        administrationService.auditCampus(id,audit,reject);
        return Result.success("审核成功");
    }
    @PutMapping("/audit/job")
    public Result auditJob(@RequestParam Integer id,@RequestParam boolean audit,@RequestParam(required = false) String reject){
        administrationService.auditJob(id,audit,reject);
        return Result.success("审核成功");
    }
    //活动发布
    @PutMapping("/publish/campus")
    public Result publishCampus(@RequestParam Integer id){
        administrationService.publishCampus(id);
        return Result.success("发布成功");
    }
    @PutMapping("/publish/job")
    public Result publishJob(@RequestParam Integer id){
        administrationService.publishJob(id);
        return Result.success("发布成功");
    }
    //人员管理
    @GetMapping("/people")
    public Result page(@RequestParam(defaultValue = "1") Integer pagenum,
                       @RequestParam(defaultValue = "10") Integer pagesize,
                       @RequestParam Integer id
    ) {
        PageBean pageBean = administrationService.pageCampusStuList(pagenum, pagesize, id);
        return Result.success(pageBean);
    }


    // 这里当你的参数只有一个的时候，后端要做处理。
    // 就是RequestParam有个参数，如果他的值没有的话
    @GetMapping("/student")
    public Result getStudent(@RequestParam(value = "newType", required = false)String newType
    ){
        return Result.success(administrationService.getStudent(newType));
    }

    //人员管理 type值
    @GetMapping("/institution")
    public Result getInstitution(@RequestParam("type") String type){
        return Result.success(administrationService.getInstitution(type));
    }

    /**
     * 删除institution
     * @param id
     * @return
     */
    @DeleteMapping("/inst/del")
    public Result deleteInst(@RequestParam("id") Integer id) {
        administrationService.deleteInst(id);
        return Result.success("删除成功");
    }

    /**
     * 更新institution
     * @param id
     * @return
     */
    @PutMapping("/inst/put")
    public Result updateInst(@RequestParam("id") Integer id) {
        administrationService.updateInst(id);
        return Result.success("禁用成功");
    }
    /**
     * 启用institution
     * @param id
     * @return
     */
    @PutMapping("/approve/put")
    public Result ApproveInst(@RequestParam("id") Integer id) {
        administrationService.ApproveInst(id);
        return Result.success("启用成功");
    }

    /**
     * 删除student
     * @param username
     * @return
     */
    @DeleteMapping("/stu/del")
    public Result deleteStu(@RequestParam("username") String username) {
        administrationService.deleteStu(username);
        return Result.success("删除成功");
    }

    /**
     * 更新student
     * @param username
     * @return
     */
    @PutMapping("/stu/put")
    public Result updateStu(@RequestParam("username") String username) {
        administrationService.updateStu(username);
        return Result.success("禁用成功");
    }

    /**
     * 启用student
     * @param username
     * @return
     */
    @PutMapping("/ApproveStu/put")
    public Result ApproveStu(@RequestParam("username") String username) {
        administrationService.ApproveStu(username);
        return Result.success("启用成功");
    }

    /**
     * 用户通过username查询单个student
     * @param username
     * @return
     */
    @GetMapping("/stu/{username}")
    public Result getStuByUsername(@PathVariable String username) {
        return Result.success(administrationService.getStuByUsername(username));
    }
    //管理员
    @GetMapping("/administration")
    public Result getAdministration(@RequestParam(value = "id",required = false) Integer id){
        return Result.success(administrationService.getAdministration(id));
    }
}

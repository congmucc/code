package com.zhuyebao.controller;

import com.zhuyebao.obj.Campus;
import com.zhuyebao.obj.StuBM;
import com.zhuyebao.obj.Student;
import com.zhuyebao.service.StudentService;
import com.zhuyebao.utils.HttpClientUtil;
import com.zhuyebao.utils.Result;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

@Slf4j
@RestController
@RequestMapping("/zyb/student")
public class StudentController {
    @Autowired
    private StudentService studentService;

    //微信登陆
    @PostMapping("/wxLogin")
    public Result wxLogin(String code) {

        String url = "https://api.weixin.qq.com/sns/jscode2session";
        Map<String, String> param = new HashMap<>();
        param.put("appid", "你的appid");
        param.put("secret", "你的开发者秘钥");
        param.put("js_code", code);
        param.put("grant_type", "authorization_code");
        //发起get请求
        String wxResult = HttpClientUtil.doGet(url, param);
        System.out.println(wxResult);
        return Result.success("登陆成功");
    }


    //查找学生详细信息
    @PostMapping("/findAll/{username}")
    public Result selectStudentInformation(@PathVariable String username){
        List<Student> student = studentService.findAll(username);
        return Result.success(student);
    }
    //查找学生是否认证
    @PostMapping("/unauthorized/{username}")
    public Result unauthorized(@PathVariable String username){
        String student =  studentService.unauthorized(username);
        return Result.success(student);
    }

    //学生认证
    @PostMapping("/authentication")
    public Result authentication(@PathVariable String username,@PathVariable Integer stuId){
        studentService.authentication(username,stuId);
        return Result.success("认证成功");
    }

    //修改学生信息
    @PostMapping("/update")
    public Result update(@RequestBody Student student){
        studentService.update(student);
        return Result.success("修改成功");
    }


    //活动报名
    @PostMapping("/application")
    public Result application(@RequestBody StuBM stuBM){
        studentService.application(stuBM);
        return Result.success("报名成功");
    }
    //查找未审核报名
    @PostMapping("/weiShenHe")
    public Result weiShenHe(){
        List<StuBM> stuBM = studentService.weiShenHe();
        return Result.success(stuBM);
    }
    //报名审核
    @PostMapping("/tongGuo/{id}/{state}")
    public Result tongGuo(@PathVariable Long id,
                          @PathVariable Long state){
        studentService.tongGuo(id,state);
        return Result.success("审核通过");
    }
    //进入活动通知群

    //删除学生信息
    @DeleteMapping("/deleteById/{id}")
    public  Result deleteById(@PathVariable("id") Long id){
        studentService.deleteById(id);
        return Result.success("删除成功");
    }

    //校内活动 校内发起活动表 campus_will state=0 待审核
    @PostMapping("/addActivity")
    public Result addActivity(@RequestBody Campus campus){
        studentService.addActivity(campus);
        return Result.success("待审核.....");
    }
    //查看活动进度
    @PostMapping("/findAct/{id}")
    public Result findAct(@PathVariable Long id){
        String findActState =  studentService.findAct(id);
        return Result.success(findActState);
    }
    //查看活动数据
    @PostMapping("/assess")
    public Result assess(@PathVariable Long id){
        String list = studentService.assess(id);
        return Result.success(list);
    }
    //添加活动证明
    @PostMapping("/addActZ")
    public Result addActZ(@PathVariable String username,
                          @PathVariable String stuAct){
        studentService.addActZ(username,stuAct);
        return Result.success("添加成功");
    }
    //查看活动证明
    @PostMapping("/activityProof/{username}")
    public Result activityProof(@PathVariable String username){
        //返回图片地址
        String proof =  studentService.activityProof(username);
        return Result.success(proof);
    }
    //下载活动证明报告
    @PostMapping("/downloadActivity")
    public Result downloadActivity(@RequestBody Student student) {
        studentService.downloadActivity(student);
        return Result.success("下载成功");
    }
}

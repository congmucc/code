package com.kcxgdw.controller;

import com.kcxgdw.obj.Administrator;
import com.kcxgdw.obj.Persona;
import com.kcxgdw.obj.Result;
import com.kcxgdw.service.TeacherService;
import com.kcxgdw.utils.JwtUtils;
import com.kcxgdw.utils.StatusConstant;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.HashMap;
import java.util.Map;

@Slf4j
@RestController
@RequestMapping("teacher")
public class TecaherController {

    @Autowired
    private TeacherService teacherService;

    @PostMapping("/login")
    public Result login(@RequestBody Administrator administrator){
        Administrator a= teacherService.login(administrator);
        if (a!=null){
            Map<String, Object> claims=new HashMap<>();
            claims.put("id",a.getId());
            claims.put("name",a.getName());
            claims.put("username",a.getName());
            a.setJwt(JwtUtils.generateJwt(claims));
            if (a.getStatus() == 0)  {
                return Result.error("您的账户被锁定，请联系超级管理员解锁");
            }
            // 每次登录后就会刷新一下登录状态
            teacherService.changeSatus(StatusConstant.TEACHER_ENABLE_STATUS, a.getUsername());
            return Result.success(a);
        }
        Administrator user = teacherService.getUser(administrator.getUsername());
        if (user != null) {
            if (user.getStatus() == 0)  {
                return Result.error("您的账户被锁定，请联系超级管理员解锁");
            }
            teacherService.changeSatus(user.getStatus() - 1, user.getUsername());
            return Result.error("密码错误, 您的登录次数剩余" + (user.getStatus() - 1) + "次");
        }
        return Result.error("账号不存在");
    }

    @GetMapping("/user/profile")
    public Result getUser(String username){
        Administrator a=teacherService.getUser(username);
        return Result.success(a);
    }
    @PutMapping("/user/profile")
    public Result upload(@RequestBody Administrator administrator){
        teacherService.upload(administrator);
        return Result.success();
    }
    /**
     * 老师邮箱发验证码
     * @param username
     * @param email
     * @return
     */
    @GetMapping("/user/getCode")
    public Result getCode(@RequestParam String username,
                          @RequestParam String email){
        log.info(email);
        String code = teacherService.getCode(username,email);
        log.info(code);
        if(code.length()==5)return Result.success(code);
        else return Result.error("用户名或邮箱错误");
    }

    /**
     * 修改老师的登录状态
     * @param t
     * @param username
     * @return
     */
    @PutMapping("/put/status")
    public Result Status(Integer t,@RequestParam(value = "username", required = false) String username) {
        teacherService.changeSatus(t, username);
        return Result.success();
    }

    /**
     * 修改老师密码
     * @param username
     * @param password
     * @return
     */
    @PutMapping("/user/password")
    public Result updateTeacherPassword(@RequestParam String username, @RequestParam String password){
        teacherService.updateTeaPsw(username,password);
        return Result.success();
    }
}

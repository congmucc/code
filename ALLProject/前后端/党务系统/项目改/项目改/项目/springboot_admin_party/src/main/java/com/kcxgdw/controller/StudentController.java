package com.kcxgdw.controller;

import com.kcxgdw.obj.Persona;
import com.kcxgdw.obj.Personi;
import com.kcxgdw.obj.Result;
import com.kcxgdw.service.PersonaService;
import com.kcxgdw.service.PersoniService;
import com.kcxgdw.utils.JwtUtils;
import com.kcxgdw.utils.StatusConstant;
import com.kcxgdw.utils.StatusTask;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.io.UnsupportedEncodingException;
import java.text.DateFormat;
import java.time.LocalDate;
import java.util.HashMap;
import java.util.Map;

@Slf4j
@RestController
@RequestMapping("student")
public class StudentController {
    @Autowired
    private PersonaService personaService;
    @Autowired
    private PersoniService personiService;

    @PostMapping("/login")
    public Result login(@RequestBody Persona persona){
        Persona a = personaService.login(persona);
        if (a!=null){
            Map<String, Object> claims=new HashMap<>();
            claims.put("id",a.getId());
            claims.put("name",a.getName());
            claims.put("username",a.getName());
            a.setJwt(JwtUtils.generateJwt(claims));
            if (a.getStatus() == 0) {
                return Result.error("您的账户被锁定，请联系管理员解锁");
            }
            // 每次登录后就会刷新一下登录状态
            personaService.changeSatus(StatusConstant.ENABLE_STATUS, a.getUsername());
            return Result.success(a);
        }
        Persona user=personaService.getStudentPersona(persona.getUsername());
        if (user != null) {
            if (user.getStatus() == 0) {
                return Result.error("您的账户被锁定，请联系管理员解锁");
            }
            personaService.changeSatus(user.getStatus() - 1, user.getUsername());
            return Result.error("密码错误, 您的登录次数剩余" + (user.getStatus() - 1) + "次");
        }
        return Result.error("账号不存在");
    }

    @GetMapping("/information")
    public Result getStudentInformation(@RequestParam String username) throws UnsupportedEncodingException {
        Personi personi=personiService.getByStudentPersoni(username);
        return Result.success(personi);
    }
    @PutMapping("/update")
    public Result studentUpdate(@RequestBody Personi personi) {
        try {
            LocalDate.parse(personi.getBirthday2(personi.getIdNum()));

        } catch (Exception e) {
            personi.setIdNum(null);
            personi.setBirthday(null);
            personiService.update(personi);
            return Result.error("身份证号有误");
        }
        personiService.update(personi);
        return Result.success();
    }
    @PutMapping("/updateEmail")
    public Result emailUpdate(@RequestBody Persona persona){
        personaService.emailupdate(persona);
        return Result.success(persona);
    }
    @GetMapping("/user/getCode")
    public Result getCode(@RequestParam String username,
                          @RequestParam String email){
        log.info(email);
        String code = personaService.getCode(username,email);
        log.info(code);
        if(code.length()==5)return Result.success(code);
        else return Result.error("用户名或邮箱错误");
    }
    @PutMapping("/user/password")
    public Result uploadpsw(@RequestParam String username,
                            @RequestParam String password){

        personaService.updateStuPsw(username,password);
        return Result.success();
    }




}

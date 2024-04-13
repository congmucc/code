package com.mun.webspringboot.controller;


import com.mun.webspringboot.service.LoginService;
import com.mun.webspringboot.utils.Result;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.util.CollectionUtils;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.Map;

@RequestMapping("/login")
@RestController
public class loginController {

    @Autowired
    private LoginService loginService;

    @PostMapping
    public Result login(@RequestBody Map<String, String> map) {
        System.out.println("接受的数据："+map);
        if (CollectionUtils.isEmpty(map)) {
            return Result.error(Result.CODE_AUTH_ERROR, "参数不对");
        }
        return Result.success(loginService.login(map));
    }


    // @PostMapping("/upload")
    // public Result postUpload(@RequestParam("username") String username,
    //                          @RequestParam("password") String password,
    //                          @RequestParam("img") MultipartFile[] img) throws IOException {
    //
    //
    //     for (MultipartFile multipartFile : img) {
    //
    //         multipartFile.transferTo(new File("C:\\Users\\Administrator\\Desktop\\Project\\web-communication\\web-springboot\\src\\main\\resources\\static",multipartFile.getOriginalFilename()));
    //     }
    //     return Result.success();
    // }
}

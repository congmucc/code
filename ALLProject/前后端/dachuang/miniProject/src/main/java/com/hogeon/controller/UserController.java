package com.hogeon.controller;

import com.alibaba.druid.util.HttpClientUtils;
import com.alibaba.fastjson.JSON;
import com.alibaba.fastjson.JSONObject;
import com.auth0.jwt.JWT;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.api.R;
import com.hogeon.common.Result;
import com.hogeon.entity.Activity;
import com.hogeon.entity.User;
import com.hogeon.properties.WeixinProperties;
import com.hogeon.service.UserService;
import com.hogeon.utils.TokenUtils;
import org.apache.http.HttpEntity;
import org.apache.http.client.methods.CloseableHttpResponse;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.CloseableHttpClient;
import org.apache.http.impl.client.HttpClients;
import org.apache.http.util.EntityUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import java.io.Closeable;
import java.io.IOException;
import java.net.http.HttpClient;
import java.util.HashMap;
import java.util.Map;

@RestController
@RequestMapping("/user")
public class UserController {
    @Autowired
    private WeixinProperties weixinProperties;

    @Autowired
    private UserService userService;



    @PostMapping("/login")
    public Result save(@RequestBody User user) throws IOException {
        System.out.println("接收的数据： " + user);
        String jscode2sessionUrl= weixinProperties.getJscode2sessionUrl()+"appid="+weixinProperties.getAppid()+"&secret="+weixinProperties.getSecret()+"&js_code="+user.getCode()+"&grant_type=authorization_code";
        System.out.println(jscode2sessionUrl);

        // 这里是进行http请求
        String openId = getOpenId(jscode2sessionUrl);
        user.setOpenId(openId);
        System.out.println(openId);

        // 插入到数据库， 1. 用户存在，插入用户， 2.用户不存在，更新用户
        userService.saveOrUpdate(user, new QueryWrapper<User>().eq("open_id", openId));
        // 利用jwt生成token返回到前端
        String token = new TokenUtils().createToken(openId);
        System.out.println("token的值: "+token);
        // 将id和token返回前端
        Map<String, Object> res = new HashMap<>();
        User user1 = userService.getOne(new QueryWrapper<User>().eq("open_id", openId));
        res.put("id", user1.getId());
        res.put("nickName", user1.getNickName());
        res.put("avatarUrl", user1.getAvatarUrl());
        res.put("token", token);
        return Result.success(res);
    }


    // 获取openid，发送网络请求
    private String getOpenId(String jscode2sessionUrl) throws IOException {
        //1.创建httpclient对象
        CloseableHttpClient client = HttpClients.createDefault();
        //2.创建get对象
        HttpGet get = new HttpGet(jscode2sessionUrl);
        //3.执行get请求，并返回响应结果
        CloseableHttpResponse response = client.execute(get);
        //4.处理结果
        //1.获取结果中的状态码
        int statusCode = response.getStatusLine().getStatusCode();
        // System.out.println(statusCode);
        //2.获取结果中内容
        HttpEntity entity = response.getEntity();//获得实体内容
        String content = EntityUtils.toString(entity, "utf-8");//通过实体工具类转换实体输出格式
        // System.out.println(entity);
        // 将json文件中的openid解析出来
        JSONObject jsonObject = JSON.parseObject(content);
        String openid = jsonObject.get("openid").toString();
        // System.out.println("openid: "+openid);
        //5.关闭连接
        client.close();
        return openid;
    }
}

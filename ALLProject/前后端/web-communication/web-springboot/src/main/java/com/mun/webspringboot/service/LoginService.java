package com.mun.webspringboot.service;

import com.mun.webspringboot.dao.UserDao;
import com.mun.webspringboot.exception.ServiceException;
import com.mun.webspringboot.pojo.User;
import com.mun.webspringboot.utils.JwtUtil;
import com.mun.webspringboot.utils.Result;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.HashMap;
import java.util.Map;

@Service
public class LoginService {
    @Autowired
    private UserDao userDao;

    public Object login(Map<String, String> map) {
        String username = map.get("username");
        String password = map.get("password");

        User user = userDao.getUserByUserName(username);

        if (user == null) {
            throw new ServiceException(Result.CODE_AUTH_ERROR, "用户不存在");
        }
        if (!user.getPassword().equals(password)) {
            throw new ServiceException(Result.CODE_AUTH_ERROR, "用户密码错误");
        }
        // 转换类型
        Map<String, Object> convertedMap = new HashMap<>(map);
        convertedMap.replaceAll((key, value) -> (Object) value);
        return JwtUtil.generateToken(convertedMap);
    }
}

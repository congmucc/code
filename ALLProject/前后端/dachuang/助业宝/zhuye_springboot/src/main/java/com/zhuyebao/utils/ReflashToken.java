package com.zhuyebao.utils;

import io.jsonwebtoken.Claims;
import jakarta.annotation.Resource;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Component;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;

import java.util.HashMap;
import java.util.Map;

@Component
public class ReflashToken {
    @PostMapping("/refreshToken")
    public Result refreshToken(@RequestBody String refreshToken) {
        // 解析刷新令牌
        Claims claims = JwtUtils.parseJwt(refreshToken);

        // 验证刷新令牌是否有效
        if (JwtUtils.isTokenExpired(claims.getExpiration())) {
            // 刷新令牌过期，返回错误响应
            return Result.error("token过期了");
        }

        // 生成新的访问令牌
        Map<String, Object> newClaims = new HashMap<>();
        // 根据解析的的username进行更新
        String username = claims.get("username", String.class);
        newClaims.put("username", username);
        String newAccessToken = JwtUtils.generateJwt(newClaims);
        return Result.success(newAccessToken);
    }
}

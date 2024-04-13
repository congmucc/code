package com.org.dto;

import lombok.Data;

/**
 * 接收亲段登录请求参数
 */

@Data
public class UserDTO {
    private String username;
    private String password;
    private String nickname;
    private String avatar;
    private String token;
}

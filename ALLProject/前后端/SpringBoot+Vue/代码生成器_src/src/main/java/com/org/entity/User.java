package com.org.entity;

// 这可以直接生成

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.fasterxml.jackson.annotation.JsonProperty;
import lombok.Data;
@Data


public class User {
    @TableId(value = "id",type = IdType.AUTO)
    private Integer id;
    private String username;
    // @JsonIgnore
    @JsonProperty(access = JsonProperty.Access.WRITE_ONLY)
    private String password;
    private String nickname;
    private String email;
    private String phone;
    private String address;
}

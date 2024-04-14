package com.zhuyebao.obj;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class Institution {
    private Integer id;
    private String username;
    private String name;
    private String password;
    private String email;
    private String state;
    private String type;
    private String certify;
    private Integer blacklist;
}

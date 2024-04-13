package com.kcxgdw.obj;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@NoArgsConstructor
@AllArgsConstructor
public class Administrator {
    private Integer id;
    private String name;
    private String username;
    private String password;
    private String email;
    private String jwt;
    private Integer status;
}

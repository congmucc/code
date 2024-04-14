package com.zhuyebao.obj;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class Administration {
    private Integer id;
    private String username;
    private String password;
    private String email;
}

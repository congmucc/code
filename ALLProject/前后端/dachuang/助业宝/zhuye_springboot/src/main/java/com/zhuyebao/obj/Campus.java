package com.zhuyebao.obj;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class Campus {
    private Integer id;
    private String name;
    private String time;
    private String content;
    private String place;
    private String goods;
    private Integer number;
    private Integer institutionId;
    private String state;
    private String group;
}

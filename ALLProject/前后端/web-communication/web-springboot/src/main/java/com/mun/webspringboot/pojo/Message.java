package com.mun.webspringboot.pojo;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.Date;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class Message {

    private Long id;
    private Long from;
    private Long to;
    private Integer type;
    private String content;
    private Date time;

}

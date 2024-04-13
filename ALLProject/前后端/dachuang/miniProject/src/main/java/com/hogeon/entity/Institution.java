package com.hogeon.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

@Data
@TableName("institution")
public class Institution {
    @TableId(value = "id", type = IdType.AUTO)
    private Integer id;
    private String unit;
    private String type;
    private Integer level;
}

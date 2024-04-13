package com.hogeon.entity;


import com.alibaba.fastjson.annotation.JSONField;
import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import com.fasterxml.jackson.annotation.JsonFormat;
import lombok.Data;

import java.util.Date;

@Data
@TableName("activity")
public class Activity {
    @TableId(value = "id", type = IdType.AUTO)
    // 主键id
    private Integer id;
    // 活动名称
    private String title;
    // 活动开始时间
    // 给前端返回一个正确的时间格式
    @JsonFormat(pattern = "yyyy-MM-dd", timezone = "GMT+8")
    private Date startTime;
    @JsonFormat(pattern = "yyyy-MM-dd", timezone = "GMT+8")
    // 活动结束时间
    private  Date endTime;
    // 活动地点
    private String site;
    // 活动场地
    private String venue;
    // 活动内容
    private String content;
    // 参与人数
    private Integer number;
    // 活动物资
    private String material;
    // 人员需求
    private String numberNeed;
    // 活动状态
    private String status;
    // 用户的id
    @TableField(select = false)
    private Integer userId;
}

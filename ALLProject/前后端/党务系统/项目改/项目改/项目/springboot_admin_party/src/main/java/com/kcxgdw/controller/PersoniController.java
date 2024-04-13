package com.kcxgdw.controller;

import cn.hutool.core.codec.Base64;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.kcxgdw.obj.PageBean;
import com.kcxgdw.obj.Personi;
import com.kcxgdw.obj.Result;
import com.kcxgdw.service.PersoniService;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.format.annotation.DateTimeFormat;
import org.springframework.web.bind.annotation.*;

import java.io.UnsupportedEncodingException;
import java.nio.charset.StandardCharsets;
import java.time.LocalDate;
import java.util.List;

/**
 * 人员信息管理
 */
@Slf4j
@RestController
@RequestMapping("teacher/person/information")
public class PersoniController {

    @Autowired
    private PersoniService personiService;

    @GetMapping
    public Result page(@RequestParam(defaultValue = "1") Integer pagenum,
                       @RequestParam(defaultValue = "10")Integer pagesize,
                       String id, String grade, String major, String name,String status,
                       @DateTimeFormat(pattern = "yyyy-MM-dd") LocalDate det_time,
                       String cul_people, String qua ,Boolean isAllInformation, LocalDate birthday) throws UnsupportedEncodingException {
        //log.info("分页查询，参数：{},{}",det_time,cul_people);
        if (isAllInformation){
            List<Personi>personiList= personiService.list(pagenum,pagesize,id,grade,major,name,status,det_time,cul_people,qua,birthday);
            return Result.success(personiList);
        }
        PageBean pageBean=personiService.page(pagenum,pagesize,id,grade,major,name,status,det_time,cul_people,qua,birthday);
        return Result.success(pageBean);
    }

    @GetMapping("/{id}")
    public Result personById(@PathVariable String id) throws UnsupportedEncodingException {
        Personi personi = personiService.selectOne(id);
        return Result.success(personi);
    }
}

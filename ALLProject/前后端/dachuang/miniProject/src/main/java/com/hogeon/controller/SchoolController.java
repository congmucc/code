package com.hogeon.controller;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.hogeon.entity.School;
import com.hogeon.mapper.SchoolMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;


import java.util.List;

@RestController
@RequestMapping("api/school")
public class SchoolController {
    @Autowired
    private SchoolMapper schoolMapper;

    @GetMapping("/get")
    public Boolean get(String name) {
        QueryWrapper queryWrapper = new QueryWrapper();
        queryWrapper.eq("name", name);
        List<School> schoolList=  schoolMapper.selectList(queryWrapper);
        System.out.println("学校名字：" + name);
        System.out.println("查询结果： "+ schoolList);
        if (schoolList.size() > 0) {
            return true;
        } {
            return false;
        }
    }

}

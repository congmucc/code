package com.kcxgdw.controller;

import com.kcxgdw.mapper.TimeMapper;
import com.kcxgdw.obj.Result;
import com.kcxgdw.obj.Time;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

@Slf4j
@RestController
@RequestMapping("/time")
public class TimeController {

    @Autowired
    private TimeMapper timeMapper;

    @GetMapping("/get")
    public Result getTime() {
        Time time1 = timeMapper.getOne();
        return Result.success(time1);
    }

    @PutMapping("/put")
    public Result updateTime(@RequestBody Time time1) {
        timeMapper.update(time1);
        return Result.success();
    }
}
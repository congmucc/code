package com.kcxgdw.utils;


import com.kcxgdw.mapper.TimeMapper;
import com.kcxgdw.obj.Result;
import com.kcxgdw.obj.Time;
import com.kcxgdw.service.PersonaService;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.scheduling.TaskScheduler;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.concurrent.ScheduledFuture;

@Slf4j
@RestController
@RequestMapping("/quartz/task")
public class StatusTask {
    @Autowired
    private TimeMapper timeMapper;
    @Autowired
    private PersonaService personaService;
    @Autowired
    private TaskScheduler taskScheduler;

    private static int[] temp;
    private ScheduledFuture<?> scheduledFuture;

    @GetMapping("/startCron")
    public Result startScheduledTask() {
        startTask();
        return Result.success();
    }

    @GetMapping("/stopCron")
    public Result stopScheduledTask() {
        int[] status = getStatus();
        if ((status[0] > 0) && (status[1] < 0)) {
            stopTask();
        }
        return Result.success();
    }


    public void startTask() {
        // 在第一次登录注册之后进行记录
        temp = getStatus();
        if (scheduledFuture == null || scheduledFuture.isCancelled()) {
            // 1000*60*60*12
            scheduledFuture = taskScheduler.scheduleWithFixedDelay(this::runTaskManually, 43200000);
        }
        // 立即执行一次任务
        runTaskManually();
        if ((temp[0] > 0) && (temp[1] < 0)) {
            // 开放状态
            personaService.changeSatus(StatusConstant.ENABLE_STATUS, "");
        }
    }

    public void stopTask() {
        if (scheduledFuture != null) {
            scheduledFuture.cancel(false);
        }
    }

    public void runTaskManually(){
        int[] status = getStatus();
        // 通过判断符号来判断现在时间和所设定的时间段边缘是否碰撞了 碰撞了就进行判断修改
        if (!(((status[0] ^ temp[0]) >= 0) && ((status[1] ^ temp[1]) >= 0))) {
            if ((status[0] > 0) && (status[1] < 0)) {
                // 开放状态
                personaService.changeSatus(StatusConstant.ENABLE_STATUS, "");
            } else {
                personaService.changeSatus(StatusConstant.DISABLE_STATUS,"");
            }
        }
    }

    public int[] getStatus() {
        Time one = timeMapper.getOne();
        String[] dateTime = one.getDate().split(",");
        // endDate.compareTo(startDate) 结果>0 说明前者 晚于 后者 说明时间超过了
        String nowDate= new SimpleDateFormat("yyyy-MM-dd HH:mm:ss").format(new Date());
        int i1 = nowDate.compareTo(dateTime[0]);  // 这个是起始时间  如果开放， 需要i1 > 0 且i2 < 0
        int i2 = nowDate.compareTo(dateTime[1]);  // 这个是结束时间
        return new int[]{i1, i2};
    }

}

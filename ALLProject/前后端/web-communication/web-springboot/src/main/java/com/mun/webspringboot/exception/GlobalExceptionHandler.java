package com.mun.webspringboot.exception;


import com.mun.webspringboot.utils.Result;
import lombok.extern.slf4j.Slf4j;
import org.springframework.web.bind.annotation.ControllerAdvice;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.bind.annotation.ResponseBody;

@ControllerAdvice
@Slf4j

public class GlobalExceptionHandler {

    /**
     * @ExceptionHandler相当于controller的@RequestMapping
     * 如果抛出的的是ServiceException，则调用该方法
     * @param se 业务异常
     * @return
     */
    @ExceptionHandler(value = ServiceException.class)
    @ResponseBody
    public Result handle(ServiceException se){
        log.info("全局异常类捕获：", se);
        return Result.error(se.getCode(), se.getMessage());
    }
}

package com.hogeon.exception;


import com.hogeon.common.Result;
import org.springframework.web.bind.annotation.ControllerAdvice;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.bind.annotation.ResponseBody;


// 将当前类标识为异常处理的组件
@ControllerAdvice
public class GlobalExceptionHandler {
    /**
     * @ExceptionHandler相当于controller的@RequestMapping
     * 如果抛出的的是ServiceException，则调用该方法
     * @param se 业务异常
     * @return
     */
    @ExceptionHandler(ServiceException.class)
    @ResponseBody  // 给前端返回一个JSON数据
    public Result handle(ServiceException se){
        return Result.error(se.getCode(), se.getMessage());
    }
}

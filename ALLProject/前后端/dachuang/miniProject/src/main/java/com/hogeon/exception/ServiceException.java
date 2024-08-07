package com.hogeon.exception;

import lombok.Data;

/**
 * RuntimeException是系统运行中的异常
 * 自定义异常
 */
@Data
public class ServiceException extends RuntimeException{
    private String code;

    public ServiceException(String code, String msg) {
        super(msg);
        this.code = code;
    }
}

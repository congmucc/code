package com.hogeon.common;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
// 无参构造
@NoArgsConstructor
// 有参构造
@AllArgsConstructor
public class Result {
    private String code;
    private String mgs;
    private Object data;

    // 成功的无消息返回
    public static Result success() {
        return new Result(Constants.CODE_200, "", null);
    }
    // 成功的有消息返回
    public static Result success(Object data) {
        return new Result(Constants.CODE_200, "", data);
    }

    // 错误返回，返回一个错误信息，和错误码
    public static Result error(String code, String msg) {
        return new Result(code, msg, null);
    }
    public static Result error() {
        return new Result(Constants.CODE_500, "系统错误", null);
    }



}

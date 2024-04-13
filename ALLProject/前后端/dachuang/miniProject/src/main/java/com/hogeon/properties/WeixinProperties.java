package com.hogeon.properties;

import lombok.Data;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.stereotype.Component;

@Component
@Data
public class WeixinProperties {
    @Value("${weixin.jscode2sessionUrl}")
    private String jscode2sessionUrl;  // 登录凭证效验请求地址
    @Value("${weixin.appid}")
    private String appid;  // 小程序appId
    @Value("${weixin.secret}")
    private String secret;  // 小程序appSecret
}

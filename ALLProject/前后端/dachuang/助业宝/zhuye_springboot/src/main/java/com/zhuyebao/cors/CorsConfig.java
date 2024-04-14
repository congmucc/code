package com.zhuyebao.cors;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.web.cors.CorsConfiguration;
import org.springframework.web.cors.UrlBasedCorsConfigurationSource;
import org.springframework.web.filter.CorsFilter;

import java.util.Arrays;

@Configuration
public class CorsConfig {
    @Bean
    public CorsFilter corsFilter() {
        // 1. 添加CORS配置信息
        CorsConfiguration configuration = new CorsConfiguration();

        // 2. 允许能请求的域名，去掉末尾的斜杠 //开发环境
        configuration.addAllowedOrigin("http://localhost:7190");
        configuration.addAllowedOrigin("http://localhost:8090");

        // 3. 是否发送cookie信息
        configuration.setAllowCredentials(true);

        // 4. 允许的请求方式
        configuration.setAllowedMethods(Arrays.asList("*"));

        // 5. 允许的头信息
        configuration.addAllowedHeader("content-type");
        configuration.addAllowedHeader("Authorization");
        configuration.addAllowedHeader("x-requested-with");

        // 6. 添加映射路径，拦截一切请求
        UrlBasedCorsConfigurationSource urlBasedCorsConfigurationSource = new UrlBasedCorsConfigurationSource();
        urlBasedCorsConfigurationSource.registerCorsConfiguration("/**", configuration);

        // 7. 返回新的CorsFilter
        return new CorsFilter(urlBasedCorsConfigurationSource);
    }
}
package com.zhuyebao;

import org.mybatis.spring.annotation.MapperScan;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
@MapperScan("com.zhuyebao.mapper")
@SpringBootApplication
public class SpringbootZhuYeApplication {

    public static void main(String[] args) {
        SpringApplication.run(SpringbootZhuYeApplication.class, args);
    }

}

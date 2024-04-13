package com.hogeon;

import com.hogeon.entity.User;
import org.mybatis.spring.annotation.MapperScan;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
@MapperScan("com.hogeon.mapper")
public class Main {
    public static void main(String[] args) {
        SpringApplication.run(Main.class, args);
        User user = new User();
        System.out.println("running");
    }
}
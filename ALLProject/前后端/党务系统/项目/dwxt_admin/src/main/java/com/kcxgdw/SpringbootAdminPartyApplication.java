package com.kcxgdw;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.scheduling.annotation.EnableScheduling;

@SpringBootApplication
@EnableScheduling
public class SpringbootAdminPartyApplication {

    public static void main(String[] args) {
        SpringApplication.run(SpringbootAdminPartyApplication.class, args);
    }

}

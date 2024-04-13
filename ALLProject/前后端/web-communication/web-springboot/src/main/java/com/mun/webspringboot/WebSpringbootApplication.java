package com.mun.webspringboot;

import com.mun.webspringboot.netty.CoordinationNettyServer;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
public class WebSpringbootApplication implements CommandLineRunner {

    public static void main(String[] args) {
        SpringApplication.run(WebSpringbootApplication.class, args);
    }

    @Autowired
    private CoordinationNettyServer nettyServer;

    @Override
    public void run(String... args) throws Exception {
        nettyServer.start();
    }
}

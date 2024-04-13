package com.mun.webspringboot;

import org.junit.jupiter.api.Test;

import java.time.LocalDate;
import java.time.LocalDateTime;
import java.util.Date;

// @SpringBootTest
class WebSpringbootApplicationTests {

    @Test
    void contextLoads() {
    }

    // @Autowired
    // private JwtProperties jwtProperties;
    @Test
    public void testjwt() {

        // HashMap<String, Object> claims = new HashMap<>();
        // claims.put("name", "jiaosdjf");
        // String s = JwtUtil.generateToken(claims);
        // System.out.println("生成jwt: "+s);
        //
        //
        // Claims claim = JwtUtil.parseJWT("secret", s);
        // System.out.println("解析后的jwt"+ claim);
        //
        // System.out.println("打印jwt");
        // System.out.println(jwtProperties.getTokenHeader());
        // System.out.println(jwtProperties.getExpiration());
        // System.out.println(jwtProperties.getSecret());
        Date date = new Date();
        System.out.println(date.toInstant());
        LocalDate localDate = LocalDate.now();
        LocalDateTime localDateTime = LocalDateTime.now();
        System.out.println("localDate： " + localDate);
        System.out.println("LocalDateTime: " + localDateTime);

    }
}

package com.zhuyebao.utils;

import com.auth0.jwt.JWT;
import com.auth0.jwt.exceptions.JWTDecodeException;
import com.auth0.jwt.interfaces.DecodedJWT;
import io.jsonwebtoken.Claims;
import io.jsonwebtoken.Jwts;
import io.jsonwebtoken.security.Keys;

import javax.crypto.SecretKey;
import java.nio.charset.StandardCharsets;
import java.sql.Timestamp;
import java.time.LocalDateTime;
import java.util.Date;
import java.util.Map;

public class JwtUtils {
    private static final String SECRET = "zxcvbnmfdasaererafafafafafafakjlkjalkfafadffdafadfafafaaafadfadfaf1234567890";
    private static final long EXPIRE = 60 * 24 * 7;
    public static final String HEADER = "Authorization";

    /**
     * 生成jwt token
     */
    public static String generateJwt(Map<String, Object> claims) {
        SecretKey signingKey = Keys.hmacShaKeyFor(SECRET.getBytes(StandardCharsets.UTF_8));
        //过期时间
        LocalDateTime tokenExpirationTime = LocalDateTime.now().plusMinutes(EXPIRE);
        return Jwts.builder()
                .signWith(signingKey, Jwts.SIG.HS512)
                .header().add("typ", "JWT").and()
                .issuedAt(Timestamp.valueOf(LocalDateTime.now()))
                .subject(claims.get("username").toString())
                .expiration(Timestamp.valueOf(tokenExpirationTime))
                .claims(claims)
                .compact();
    }

    public static Claims parseJwt(String token) {
        SecretKey signingKey = Keys.hmacShaKeyFor(SECRET.getBytes(StandardCharsets.UTF_8));
        return Jwts.parser()
                .verifyWith(signingKey)
                .build()
                .parseSignedClaims(token)
                .getPayload();
    }

    /**
     * 检查token是否过期
     *
     * @return true：过期
     */
    public static boolean isTokenExpired(Date expiration) {
        return expiration.before(new Date());
    }

    /**
     * 获得token中的自定义信息,一般是获取token的username，无需secret解密也能获得
     * @param token
     * @param filed
     * @return
     */
    public static String getClaimFiled(String token, String filed){
        try{
            DecodedJWT jwt = JWT.decode(token);
            return jwt.getClaim(filed).asString();
        } catch (JWTDecodeException e){
            return null;
        }
    }
}
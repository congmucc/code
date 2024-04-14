package com.zhuyebao.filter;

import com.zhuyebao.utils.JwtUtils;
import com.zhuyebao.utils.Result;
import com.zhuyebao.utils.ZYBThreadLocal;
import io.jsonwebtoken.Claims;
import jakarta.servlet.*;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import org.springframework.http.HttpMethod;
import org.springframework.stereotype.Component;
import org.springframework.util.StringUtils;

import java.io.IOException;
import java.io.PrintWriter;


@Component
public class AuthorizeFilter implements Filter {



    @Override
    public void doFilter(ServletRequest request, ServletResponse response, FilterChain filterChain) throws IOException, ServletException {
        HttpServletRequest httpServletRequest = (HttpServletRequest) request;
        HttpServletResponse httpServletResponse = (HttpServletResponse) response;
        httpServletResponse.setCharacterEncoding("UTF-8");


        if (HttpMethod.OPTIONS.toString().equals(httpServletRequest.getMethod())) {
            System.out.println("OPTIONS请求，放行");
            filterChain.doFilter(request,response);
            return;
        }
        //获取url
        String url = httpServletRequest.getRequestURI();
        System.out.println("拦截url: "+url);
        //判断是否包含login请求,是就放行
        if (url.contains("login") || url.contains("refreshToken") || url.contains("uploadimg")) {
            filterChain.doFilter(request,response);
            return;
        }
        //获取token
        String Authorization  = httpServletRequest.getHeader("Authorization");
        System.out.println("Authorization: " + Authorization);
        if (!StringUtils.hasLength(Authorization)) {
            // 设置401状态码
            httpServletResponse.setStatus(HttpServletResponse.SC_UNAUTHORIZED);
            return;
        }
        String token = Authorization.split(" ")[1];
        if (StringUtils.isEmpty(token)) {
            // 设置401状态码
            httpServletResponse.setStatus(HttpServletResponse.SC_UNAUTHORIZED);
            return;
        }
        // 判断token是否有效
        try {
            Claims claims = JwtUtils.parseJwt(token);
            // 是否过期
            boolean tokenExpired = JwtUtils.isTokenExpired(claims.getExpiration());
            if (tokenExpired) {
                // TODO 这里如果过期了，前端应该得到响应，一般来说应该是使用异常返回，这里直接返回了
                // 设置401状态码
                httpServletResponse.setStatus(HttpServletResponse.SC_UNAUTHORIZED);
                return;
            }
            // TODO 获取用户信息 可以添加到本地线程中。
            Integer id = Integer.valueOf(claims.get("id").toString());
            System.out.println("拦截过来的id： " + id);
            ZYBThreadLocal.setCurrentId(id);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
        filterChain.doFilter(request,response);
    }

}

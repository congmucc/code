package com.mun.webspringboot.dao;


import com.mun.webspringboot.pojo.User;
import org.apache.ibatis.annotations.Mapper;

@Mapper
public interface UserDao {

    User getUserByUserName(String username);


}

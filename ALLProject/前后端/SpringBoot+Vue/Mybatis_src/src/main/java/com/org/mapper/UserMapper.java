package com.org.mapper;

import com.org.entity.User;
import org.apache.ibatis.annotations.Delete;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Select;

import java.util.List;

public interface UserMapper {
    // 查询
    @Select("select * from user")
    List<User> findAll();
    // 增加
    @Insert("insert into user(username, password, nickname, email, phone, address) values(#{username}, #{password}, #{nickname}, #{email}, #{phone}, #{address})")
    int insert(User user);

    // 更新
    int update(User user);

    @Delete("delete from user where id = #{id}")
    Integer deleteById( Integer id);

    // 分页查询
    @Select("select * from user where username like concat('%', #{username}, '%') and email like concat('%', #{email}, '%') and address like concat('%', #{address}, '%') limit #{pageNum}, #{pageSize}")
    List<User> selectPage(Integer pageNum, Integer pageSize, String username, String email, String address);

    // 查询总条数
    @Select("select count(*) from user where username like concat('%', #{username}, '%') and email like concat('%', #{email}, '%') and address like concat('%', #{address}, '%')")
    Integer selectTotal(String username, String email, String address);

}

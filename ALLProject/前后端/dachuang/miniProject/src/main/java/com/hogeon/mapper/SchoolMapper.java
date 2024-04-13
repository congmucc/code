package com.hogeon.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.hogeon.entity.School;
import org.apache.ibatis.annotations.Select;
import org.springframework.web.bind.annotation.RequestBody;

import java.util.List;

public interface SchoolMapper extends BaseMapper<School> {
    // @Select("select * from school where name = #{name}")
    // List<School> find(String name);
}

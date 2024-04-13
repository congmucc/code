package com.kcxgdw.mapper;

import com.kcxgdw.obj.Time;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;
import org.apache.ibatis.annotations.Update;

@Mapper
public interface TimeMapper {

    @Select("select * from time")
    Time getOne();
    @Update("update time set date = #{date} where id = #{id}")
    void update(Time time1);
}

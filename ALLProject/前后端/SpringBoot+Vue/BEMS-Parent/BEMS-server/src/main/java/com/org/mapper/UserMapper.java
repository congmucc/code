package com.org.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.org.entity.User;
import org.apache.ibatis.annotations.MapKey;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

import java.util.Map;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author congmu
 * @since 2023-08-02
 */
@Mapper
public interface UserMapper extends BaseMapper<User> {
    @MapKey("id")
    Map<String, Object> getUserToMap(@Param("id") Integer id);
}

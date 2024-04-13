package com.kcxgdw.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.kcxgdw.obj.Persona;
import com.kcxgdw.obj.Personi;
import org.apache.ibatis.annotations.Delete;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.time.LocalDate;
import java.util.List;

@Mapper
public interface PersoniMapper {

    /**
     * 人员信息查询
     */
    public List<Personi> list(String id, String grade, String major, String name, String status,LocalDate det_time, String cul_people, String qua ,LocalDate birthday);

    /**
     * 通过id查询数据
     * @param id
     * @return
     */
    @Select("select * from personi where id= #{id}")
    Personi getOne(String id);

    /**
     * 新增员工
     * @param personi
     */
    @Insert("insert into personi (name,id) " +
            "VALUES (#{name}, #{id})")
    void insert(Personi personi);
    @Delete("delete from personi where id=#{username}" )
    void delete(String username);


}

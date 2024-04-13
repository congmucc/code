package com.kcxgdw.mapper;

import com.kcxgdw.obj.Persona;
import org.apache.ibatis.annotations.Delete;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

@Mapper
public interface PersonaMapper {
    /**
     * 查询人员账号
     * @return
     */
    //@Select("select * from persona")
    public List<Persona> list(String username);


    /**
     * 批量删除
     * @param ids
     */


    /**
     * 更新员工
     * @param ids
     */
    void updata(List<Integer> ids, Integer t);

    /**
     * 新增员工
     * @param persona
     */
    @Insert("insert into persona(name,username) values(#{name},#{username})")
    void insert(Persona persona);

    /**
     * 存在判断
     * @param username
     * @return
     */
    boolean exist(String username);
    @Delete("delete from persona where username=#{username}" )
    void delete(String username);


    void changeStatus(Integer t, String username);
}

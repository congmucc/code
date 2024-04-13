package com.kcxgdw.controller;

import com.kcxgdw.obj.PageBean;
import com.kcxgdw.obj.Persona;
import com.kcxgdw.obj.Personi;
import com.kcxgdw.obj.Result;
import com.kcxgdw.service.PersonaService;
import com.kcxgdw.service.PersoniService;
import com.kcxgdw.utils.StatusConstant;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import cn.hutool.poi.excel.ExcelReader;
import cn.hutool.poi.excel.ExcelUtil;
import org.springframework.web.multipart.MultipartFile;
import java.io.InputStream;
import java.util.List;


/**
 * 人员账号管理
 */
@Slf4j
@RestController
@RequestMapping("teacher/person/account")
public class PersonaController {

    @Autowired
    private PersonaService personaService;
    @Autowired
    private PersoniService personiService;


    @GetMapping
    public Result page(@RequestParam(defaultValue = "1") Integer pagenum,
                       @RequestParam(defaultValue = "10") Integer pagesize,
                       @RequestParam(value = "username", defaultValue = "") String username) {
        //log.info("分页查询，参数：{}，{},{}",pagenum,pagesize,username);
        PageBean pageBean = personaService.page(pagenum, pagesize, username);
        return Result.success(pageBean);
    }

    @PutMapping("/put/status")
    public Result Status(Integer t,@RequestParam(value = "username", required = false) String username) {
        personaService.changeSatus(t, username);
        return Result.success();
    }


    @DeleteMapping("/{usernames}")
    public Result delete(@PathVariable List<String> usernames){
        //log.info("usernames有：{}",usernames);
        //log.info("批量删除，ids：{}",ids);
        for(int i=0;i<usernames.size();i++)
        {
            String username=usernames.get(i);
            personaService.delete(username);
            personiService.delete(username);
        }

        return Result.success();
    }

    @PutMapping("/{ids}")
    public Result updata(@PathVariable List<Integer> ids) {
        personaService.updata(ids, StatusConstant.ENABLE_STATUS);
        return Result.success();
    }

    @PostMapping
    public Result save(@RequestBody Persona persona) {
        Personi user2 = new Personi();
        user2.setId(persona.getUsername());
        user2.setName(persona.getName());
        personaService.save(persona);
        personiService.save(user2);
        return Result.success();
    }

    @GetMapping("/exist")
    public Result exist(@RequestParam String username) {
        boolean flag = personaService.exist(username);

        return Result.success(flag);
    }

    @PostMapping("/import")
    public Result imp(MultipartFile file) throws Exception {
        InputStream inputStream = file.getInputStream();
        ExcelReader reader = ExcelUtil.getReader(inputStream);

        List<List<Object>> list = reader.read(1);
        for (List<Object> row : list) {
            if(row.get(0)==null && row.get(1)==null ){
                return Result.error("Excel中有空数据");
            }
            if(row.get(0)==null && row.get(1)!=null){
                return Result.error(row.get(1).toString()+"同学的学号为空");
            }
            if(row.get(0)!=null && row.get(1)==null){
                return Result.error("学号为"+row.get(0).toString()+"的同学姓名为空");
            }
            for (int i = 0; i < row.get(0).toString().length(); i++) {
                char ch =row.get(0).toString().charAt(i) ;
                if(!"0123456789".contains(ch+"")){
                    return Result.error("Excel第一列为学号，第二列为姓名");
                }
            }
            if (row.get(0).toString().length() != 10) {
                return Result.error("学号长度不对:" + row.get(0).toString());
            }
        }
        for (List<Object> row : list) {
            Persona user = new Persona();
            Personi user2 = new Personi();
            user.setUsername(row.get(0).toString());
            user.setName(row.get(1).toString());
            user2.setId(row.get(0).toString());
            user2.setName(row.get(1).toString());
            if (personaService.exist(row.get(0).toString())) {

            } else {
                personaService.save(user);
                personiService.save(user2);
            }

        }
        return Result.success(true);
    }

}

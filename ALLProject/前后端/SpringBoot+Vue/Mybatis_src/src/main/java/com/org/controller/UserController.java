package com.org.controller;

import com.org.entity.User;
import com.org.mapper.UserMapper;
import com.org.serve.UserServe;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

@RestController
@RequestMapping("/user")
public class UserController {

    @Autowired
    private UserMapper userMapper;

    @Autowired
    private UserServe userServe;

    // 从数据库中查询全部
    @GetMapping("/get")
    public List<User> get() {
        return userMapper.findAll();
    }

    // 增加
    @PostMapping("/post")
    public String save(@RequestBody User user) {
        // 新增或者更新
        int i = userServe.save(user);
        if (i > 0) {
            System.out.println("插入成功");
            return "插入成功";
        } else {
            System.out.println("插入失败");
            return "插入失败";
        }
    }

    // 删除
    @DeleteMapping("del/{id}")
    public String delete(@PathVariable Integer id) {
        Integer i = userMapper.deleteById(id);
        if (i > 0) {
            System.out.println("删除成功");
            return "删除成功";
        } else {
            System.out.println("删除失败");
            return "删除失败";
        }
    }


    // 分页查询
    // 接口路径： /user/page?pageNum=1&pageSize=10
    // pageNum 是第几页   pageSize是一页显示几个
    // limit 第一个参数 ： (pageNum - 1) * pageSize   公式推倒看视频
    // 第二个参数：pageSize
    @GetMapping("/page")
    public Map<String, Object> get(@RequestParam Integer pageNum, @RequestParam Integer pageSize
            , @RequestParam String username, @RequestParam String email, @RequestParam String address) {
        pageNum = (pageNum - 1) * pageSize;
        List<User> data = userMapper.selectPage(pageNum, pageSize, username, email, address);
        Integer total = userMapper.selectTotal(username, email, address);
        Map<String, Object> res = new HashMap<>();
        res.put("data", data);
        res.put("total", total);
        System.out.println("一共是 " + total);
        return res;
    }
}

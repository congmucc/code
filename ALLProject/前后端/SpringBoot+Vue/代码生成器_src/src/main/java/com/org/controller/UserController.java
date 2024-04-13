package com.org.controller;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.metadata.IPage;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.org.entity.User;
import com.org.service.UserService;
import org.apache.logging.log4j.util.Strings;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/user")
public class UserController {
    // 这是mybatis 要用
    // @Autowired
    // private UserMapper userMapper;

    @Autowired
    private UserService userService;

    // 从数据库中查询全部
    @GetMapping("/get")
    public List<User> get() {
        // return userMapper.findAll();
        return userService.list();
    }


    // 增加
    @PostMapping("/post")
    public Boolean save(@RequestBody User user) {
        // 新增或者更新   这里用userService
        // if (i = true) {
        //     System.out.println("插入成功");
        //     return "插入成功";
        // } else {
        //     System.out.println("插入失败");
        //     return "插入失败";
        // }
        return userService.saveUser(user);

    }

    // 删除
    @DeleteMapping("/del/{id}")
    public Boolean delete(@PathVariable Integer id) {
        // Integer i = userMapper.deleteById(id);
        // if (i) {
        //     System.out.println("删除成功");
        //     return "删除成功";
        // } else {
        //     System.out.println("删除失败");
        //     return "删除失败";
        // }
        return userService.removeById(id);
    }

    // 批量删除
    @DeleteMapping("/batch/{ids}")
    public boolean deleteBatch(@PathVariable List<Integer> ids) {
        return userService.removeByIds(ids);
    }

    // /**
    //  *
    //  *      mybatis
    //  *     分页查询
    //  *     接口路径： /user/page?pageNum=1&pageSize=10
    //  *     limit 第一个参数 ： (pageNum - 1) * pageSize   公式推倒看视频
    //  *     第二个参数：pageSize
    //  * @param pageNum  是第几页
    //  * @param pageSize  是一页显示几个
    //  * @param username
    //  * @param email
    //  * @param address
    //  * @return
    //  */
    //
    //
    // @GetMapping("/page")
    // public Map<String, Object> get(@RequestParam Integer pageNum, @RequestParam Integer pageSize
    //         , @RequestParam String username, @RequestParam String email, @RequestParam String address) {
    //     pageNum = (pageNum - 1) * pageSize;
    //     List<User> data = userMapper.selectPage(pageNum, pageSize, username, email, address);
    //     Integer total = userMapper.selectTotal(username, email, address);
    //     Map<String, Object> res = new HashMap<>();
    //     res.put("data", data);
    //     res.put("total", total);
    //     System.out.println("一共是 " + total);
    //     return res;
    // }


    /**
     *分页查询--mybatis-plus方式
     *
     * @RequestParam(defaultValue = "") 这个是前端不传数据的话把值设为为空字符串
     * 例如localhost:9090/user/page?pageNum=1&pageSize=5&username=a&email=&address= 此时对应的@RequestParam(defaultValue = "") String username,
     * username 就是空字符串
     *
     * @param pageNum
     * @param pageSize
     * @param username
     * @param email
     * @param address
     * @return
     */
    @GetMapping("/page")
    public IPage<User> get(@RequestParam Integer pageNum,
                           @RequestParam Integer pageSize,
                           @RequestParam(defaultValue = "") String username,
                           @RequestParam(defaultValue = "") String email,
                           @RequestParam(defaultValue = "") String address) {
        IPage<User> page = new Page<>(pageNum, pageSize);
        QueryWrapper<User> queryWrapper = new QueryWrapper<>();
        // 这句话的意思是，如果传过来的数据为空，因为数据库创建的时候是null默认值（可以改），所以说做一下判断如果前端传过来的数据是""的话（就是传过来一个字符串，就查。
        // 例如这个项目：localhost:9090/user/page?pageNum=1&pageSize=5&username=a&email=&address=  email和address都为空，所以说传过来的是一个空字符串
        // 则Strings.isNotEmpty(email)和Strings.isNotEmpty(address)为false，这两段代码都不会执行
        System.out.println(Strings.isNotEmpty(email));
        queryWrapper.like(Strings.isNotEmpty(username),"username", username);
        queryWrapper.like(Strings.isNotEmpty(email),"email", email);   // 上面的不会执行
        queryWrapper.like(Strings.isNotEmpty(address),"address", address);  // 上面的不会执行
        // 倒序
        queryWrapper.orderByDesc("id");

        // 或者也可以将数据库创建数据的默认值设为‘’（空字符串），这样也不用Strings.isNotEmpty(address)了
        // 原理是模糊搜索的话，like是含有，都执行，因为默认值是空，所以说不用担心
        // queryWrapper.like("username", username);
        // queryWrapper.like("email" , email);
        // queryWrapper.like("address", address);

        IPage<User> userIPage = userService.page(page, queryWrapper);
        return userIPage;
    }
}

package com.hogeon.controller;


import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.hogeon.common.Result;
import com.hogeon.entity.Activity;
import com.hogeon.service.ActivityService;
import org.apache.ibatis.annotations.Param;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;


@RestController
@RequestMapping("/form")
public class ActivityController {
    // @Autowired  // 自动注入UserMapper 实例化的对象
    // ActivityMapper activityMapper;

    @Autowired
    private ActivityService activityService;

    /**
     * 条件获取表单  对应前端的活动状态
     * type = 0， 审核中， 1， 驳回， 2， 已通过  page页码， pageSize每页的活动显示个数
      */
    @GetMapping("/list")
    public Result list(@Param("userId") Integer userId, @Param("type") Integer type, @Param("page") Integer page, @Param("pageSize") Integer pageSize) {
        // System.out.println("type= " + type);
        // System.out.println("type="+type);
        System.out.println("page="+page);
        System.out.println("pageSize="+pageSize);
        System.out.println("活动中的userId="+userId);
        // 总查询
        QueryWrapper queryWrapper = new QueryWrapper<Activity>();
        queryWrapper.eq("status", type);
        queryWrapper.eq("user_id", userId);
        // 倒序
        queryWrapper.orderByDesc("id");
        // List<Activity> list = activityFormService.list();
        // 分页查询
        Page<Activity> page1 = new Page<>(page, pageSize);
        Page<Activity> page2 = activityService.page(page1, queryWrapper);
        return Result.success(page2);
    }

    /* 增加表单 */
    @PostMapping("/add")
    public Result save(@RequestBody Activity activity) {
        activityService.saveOrUpdate(activity, new QueryWrapper<Activity>().eq("id", activity.getId()));
        return Result.success();
    }

    /**
     * 根据id查
     */
    @GetMapping("/get/{id}")
    public Result getOneId(@PathVariable Integer id) {
        return Result.success(activityService.getById(id));
    }

    /**
     * 删除表单内容
     */
    @DeleteMapping("/del/{id}")
    public Result del(@PathVariable("id") Integer id) {
        activityService.removeById(id);
        return Result.success();
    }





}

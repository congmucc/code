package com.org.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.org.common.Constants;
import com.org.dto.UserDTO;
import com.org.entity.User;
import com.org.exception.ServiceException;
import com.org.mapper.UserMapper;
import com.org.service.IUserService;
import com.org.controller.TokenUtils;
import org.springframework.stereotype.Service;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author congmu
 * @since 2023-08-02
 */
@Service
public class UserServiceImpl extends ServiceImpl<UserMapper, User> implements IUserService {
    @Override
    public UserDTO login(UserDTO userDTO) {
        User one = getUserInfo(userDTO);
        if (one != null) {
            // 从 one的数据copy到userDTO   此时one里面是获取的后端所有数据， 一对一复制，将one（User属性）的数据username，password，nickname，avatar赋值到userDTO
            BeanUtil.copyProperties(one, userDTO, true);
            // 设置token
            String token = TokenUtils.genToken(one.getId().toString(), one.getPassword());
            userDTO.setToken(token);
            return userDTO;
        } else {
            throw new ServiceException(Constants.CODE_600, "用户名或密码错误");
        }
    }

    @Override
    public UserDTO register(UserDTO userDTO) {
        User one = getUserInfo2(userDTO);
        if (one == null) {
            one = new User();
            // 因为这是注册，所以说，是从userDTO中的数据（从前端注册表单里面来的）赋值到one里面
            BeanUtil.copyProperties(userDTO,  one, true);
            // 保存one
            save(one);
        } else {
            throw new ServiceException(Constants.CODE_600, "用户已存在");
        }
        return null;
    }

    // 代码重复了，所以进行
    private User getUserInfo(UserDTO userDTO) {
        QueryWrapper<User> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("username", userDTO.getUsername());
        queryWrapper.eq("password", userDTO.getPassword());
        User one;
        try {
            one = getOne(queryWrapper);  // 从数据库中查询用户信息
        } catch (Exception e) {
            log.error(e.getMessage(), e);
            throw new ServiceException(Constants.CODE_500, "系统错误");
        }
        return one;
    }
    private User getUserInfo2(UserDTO userDTO) {
        QueryWrapper<User> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("username", userDTO.getUsername());
        // 仅仅对照姓用户名就行
        // queryWrapper.eq("password", userDTO.getPassword());
        User one;
        try {
            one = getOne(queryWrapper);  // 从数据库中查询用户信息
        } catch (Exception e) {
            log.error(e.getMessage(), e);
            throw new ServiceException(Constants.CODE_500, "系统错误");
        }
        return one;
    }

}

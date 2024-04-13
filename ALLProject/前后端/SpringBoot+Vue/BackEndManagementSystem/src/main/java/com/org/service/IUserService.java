package com.org.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.org.controller.dto.UserDTO;
import com.org.entity.User;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author congmu
 * @since 2023-08-02
 */
public interface IUserService extends IService<User> {
    public UserDTO login(UserDTO userDTO);

    UserDTO register(UserDTO userDTO);
}

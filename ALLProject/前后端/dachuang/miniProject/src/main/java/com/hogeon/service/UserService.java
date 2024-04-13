package com.hogeon.service;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.hogeon.entity.User;
import com.hogeon.mapper.UserMapper;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

@Service
@Transactional
public class UserService extends ServiceImpl<UserMapper, User> {
}

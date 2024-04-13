package com.org.service;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.org.entity.User;
import com.org.mapper.UserMapper;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

@Service
public class UserService extends ServiceImpl<UserMapper, User> {
    @Transactional
    public Boolean saveUser(User user) {
        if (user.getId() == null) {
            return save(user);  // MybatisPlus提供的方法
        } else {
            return updateById(user);
        }
        // 或者一个这个就行
        // saveOrUpdate(user);
    }

    // @Autowired
    // private UserMapper userMapper;
    //
    // public int save(User user) {
    //     if (user.getId() == null) {   // user 没有id， 则表示新增
    //         return userMapper.insert(user);
    //     } else {   // 否则则为更新
    //         return userMapper.update(user);
    //     }
    // }
}

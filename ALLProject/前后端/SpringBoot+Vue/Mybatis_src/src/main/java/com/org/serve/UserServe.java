package com.org.serve;

import com.org.entity.User;
import com.org.mapper.UserMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class UserServe {

    @Autowired
    private UserMapper userMapper;

    public int save(User user) {
        if (user.getId() == null) {   // user 没有id， 则表示新增
            return userMapper.insert(user);
        } else {   // 否则则为更新
            return userMapper.update(user);
        }
    }
}

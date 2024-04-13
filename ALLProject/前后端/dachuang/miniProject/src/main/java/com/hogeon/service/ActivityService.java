package com.hogeon.service;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.hogeon.entity.Activity;
import com.hogeon.mapper.ActivityMapper;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

@Service
@Transactional
public class ActivityService extends ServiceImpl<ActivityMapper, Activity>{
}

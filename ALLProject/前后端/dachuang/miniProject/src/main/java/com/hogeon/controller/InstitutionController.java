package com.hogeon.controller;

import com.hogeon.common.Result;
import com.hogeon.entity.Institution;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

@RestController
@RequestMapping("/institution")
public class InstitutionController {
    /**
     * 表单上传
     * @param
     * @param photos
     * @return
     */
    @PostMapping("/upload")
    public Result uploadImg(@RequestBody Institution institution,
                         @RequestPart("photos") MultipartFile[] photos){
        System.out.println("institution:"+ institution);
        System.out.println("photos长度："+ photos.length);
        System.out.println("photo第一个："+ photos);
        return Result.success();
    }

}

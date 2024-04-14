package com.zhuyebao.obj.dto;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import org.springframework.web.multipart.MultipartFile;

import java.util.List;

@Data
@NoArgsConstructor
@AllArgsConstructor
public class InstitutionDto {
    private Integer id;
    private String name;
    private String email;
    private String type;
    private List<MultipartFile> files;
    private List<String> deleteFiles;
}

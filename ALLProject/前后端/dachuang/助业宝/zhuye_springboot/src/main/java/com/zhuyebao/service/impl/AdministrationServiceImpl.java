package com.zhuyebao.service.impl;

import com.github.pagehelper.Page;
import com.github.pagehelper.PageHelper;
import com.zhuyebao.mapper.AdministrationMapper;
import com.zhuyebao.obj.*;
import com.zhuyebao.service.AdministrationService;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;


@Slf4j
@Service
public class AdministrationServiceImpl implements AdministrationService {
    @Autowired
    private AdministrationMapper administrationMapper;
    /**
     * 登录
     * @param username
     * @param password
     * @return
     */
    @Override
    public Administration login(String username, String password) {
        Administration administration = administrationMapper.login(username,password);
        return administration;
    }
    //提交审核
    @Override
    public void auditVolunteer(String username, String volunteer) {
        administrationMapper.auditVolunteer(username,volunteer);
    }

    @Override
    public void auditProfess(String username, String profess) {
        administrationMapper.auditProfess(username,profess);
    }

    @Override
    public void auditInstitution(Integer id, String state) {
        administrationMapper.auditInstitution(id,state);
    }
    //查询审核
    @Override
    public List<Student> getAuditVolunteer() {
        return administrationMapper.getAuditVolunteer();
    }

    @Override
    public List<Student> getAuditProfess() {
        return administrationMapper.getAuditProfess();
    }

    @Override
    public List<Institution> getAuditInstitution() {
        return administrationMapper.getAuditInstitution();
    }
    //活动查询
    @Override
    public List<Campus> getCampusList() {
        return administrationMapper.getCampusList();
    }

    @Override
    public List<Job> getJobList() {
        return administrationMapper.getJobList();
    }

    @Override
    public void auditCampus(Integer id, boolean audit, String reject) {
        if(audit==true){
            administrationMapper.campusOk(id);
        }else {
            administrationMapper.campusNo(id,reject);
            log.info("驳回");
        }
    }
    @Override
    public void auditJob(Integer id, boolean audit, String reject) {
        if(audit==true){
            administrationMapper.jobOK(id);
        }else {
            administrationMapper.jobNo(id,reject);
            log.info("驳回");
        }
    }
    //发布
    @Override
    public void publishCampus(Integer id) {
        administrationMapper.publishCampus(id);
        Campus campus = administrationMapper.getCampusById(id);
        //进行中
        administrationMapper.addCampusIng(campus);
        administrationMapper.deleteCampusWill(campus.getId());
    }

    @Override
    public void publishJob(Integer id) {
        administrationMapper.publishJob(id);
    }

    @Override
    public PageBean pageCampusStuList(Integer pagenum, Integer pagesize, Integer id) {
        PageHelper.startPage(pagenum,pagesize);
        List<Student> campusStuList = administrationMapper.getCampusStuList(id);
        Page<Student> p =(Page<Student>)campusStuList;
        PageBean pageBean =new PageBean(p.getTotal(),p.getResult());
        return pageBean;
    }

    @Override
    public void updateStu(String username) {
        System.out.println("修改个人：传过来的username值： " + username);
        administrationMapper.updateStu(username);
    }

    @Override
    public Student getStuByUsername(String username) {
        return administrationMapper.getStuByUsername(username);
    }

    @Override
    public void ApproveStu(String username) {
        System.out.println("启用个人：传过来的username值： " + username);
        administrationMapper.ApproveStu(username);
    }

    @Override
    public void updateInst(Integer id) {
        System.out.println("修改公司：传过来的id值： " + id);
        administrationMapper.updateInst(id);
    }

    @Override
    public void ApproveInst(Integer id) {
        System.out.println("启用公司：传过来的id值： " + id);
        administrationMapper.ApproveInst(id);
    }

    @Override
    public void deleteStu(String username) {
        System.out.println("删除个人：传过来的username值： " + username);
        administrationMapper.deleteStu(username);
    }

    @Override
    public void deleteInst(Integer id) {
        System.out.println("删除公司：传过来的id值： " + id);
        administrationMapper.deleteInst(id);
    }

    @Override
    public List<Administration> getAdministration(Integer id) {
        System.out.println("管理员：传过来的id值： " + id);
        return administrationMapper.getAdministration(id);
    }

    //人员管理
    @Override
    public List<Institution> getInstitution(String type) {
        System.out.println("传过来的type值： " + type);
        return administrationMapper.getInstitution(type);
    }

    //身份审核
    @Override
    public List<Student> getStudent(String newType) {
        if (newType.equals("1")) {
            return administrationMapper.getAuditVolunteer();
        } else if (newType.equals("2")) {
            return administrationMapper.getStudent();

        } else if (newType.equals("3")) {
            return administrationMapper.getAuditProfess();

        }
        return null;
    }

    //兼职审核

}

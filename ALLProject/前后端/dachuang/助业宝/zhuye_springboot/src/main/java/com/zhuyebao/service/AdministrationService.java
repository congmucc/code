package com.zhuyebao.service;

import com.zhuyebao.obj.*;

import java.util.List;

public interface AdministrationService {
    Administration login(String username, String password);

    void auditVolunteer(String volunteer, String s);

    void auditProfess(String profess, String s);

    void auditInstitution(Integer id,String state);

    List<Student> getAuditVolunteer();

    List<Student> getAuditProfess();

    List<Institution> getAuditInstitution();

    List<Campus> getCampusList();

    List<Job> getJobList();

    void auditCampus(Integer id, boolean audit, String reject);

    void auditJob(Integer id, boolean audit, String reject);

    void publishCampus(Integer id);

    void publishJob(Integer id);

    PageBean pageCampusStuList(Integer pagenum, Integer pagesize, Integer id);

    List<Student> getStudent(String newType);

    List<Institution> getInstitution(String type);

    List<Administration> getAdministration(Integer id);

    void deleteInst(Integer id);

    void deleteStu(String username);

    void updateInst(Integer id);

    void updateStu(String username);

    void ApproveInst(Integer id);

    void ApproveStu(String username);

    Student getStuByUsername(String username);
}

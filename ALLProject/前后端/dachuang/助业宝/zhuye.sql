-- MySQL dump 10.13  Distrib 5.7.31, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: zhuye
-- ------------------------------------------------------
-- Server version	5.7.31

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `administration`
--

DROP TABLE IF EXISTS `administration`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `administration` (
  `id` int(11) NOT NULL COMMENT '高校id',
  `username` varchar(255) NOT NULL COMMENT '帐号',
  `password` varchar(255) NOT NULL COMMENT '密码',
  `email` varchar(255) DEFAULT NULL COMMENT '邮箱',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 ROW_FORMAT=DYNAMIC;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `administration`
--

LOCK TABLES `administration` WRITE;
/*!40000 ALTER TABLE `administration` DISABLE KEYS */;
INSERT INTO `administration` VALUES (1,'admin','admin','132456789@qq.com');
/*!40000 ALTER TABLE `administration` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `campus_ed`
--

DROP TABLE IF EXISTS `campus_ed`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `campus_ed` (
  `id` int(11) NOT NULL AUTO_INCREMENT COMMENT '序号',
  `name` varchar(255) NOT NULL COMMENT '活动名称',
  `time` varchar(255) NOT NULL COMMENT '活动时间',
  `content` text NOT NULL COMMENT '活动内容',
  `place` varchar(255) NOT NULL COMMENT '活动场地',
  `goods` varchar(255) NOT NULL COMMENT '活动物资',
  `number` int(11) NOT NULL COMMENT '人员需求',
  `institution_id` varchar(255) NOT NULL COMMENT '机构id',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 ROW_FORMAT=DYNAMIC;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `campus_ed`
--

LOCK TABLES `campus_ed` WRITE;
/*!40000 ALTER TABLE `campus_ed` DISABLE KEYS */;
/*!40000 ALTER TABLE `campus_ed` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `campus_ing`
--

DROP TABLE IF EXISTS `campus_ing`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `campus_ing` (
  `id` int(11) NOT NULL AUTO_INCREMENT COMMENT '序号',
  `name` varchar(255) NOT NULL COMMENT '	活动名称',
  `time` varchar(255) NOT NULL COMMENT '活动时间',
  `content` text NOT NULL COMMENT '活动内容',
  `place` varchar(255) NOT NULL COMMENT '活动场地',
  `goods` varchar(255) NOT NULL COMMENT '活动物资',
  `number` int(11) NOT NULL COMMENT '人员需求',
  `institution_id` varchar(255) NOT NULL COMMENT '机构id',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 ROW_FORMAT=DYNAMIC;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `campus_ing`
--

LOCK TABLES `campus_ing` WRITE;
/*!40000 ALTER TABLE `campus_ing` DISABLE KEYS */;
/*!40000 ALTER TABLE `campus_ing` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `campus_will`
--

DROP TABLE IF EXISTS `campus_will`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `campus_will` (
  `id` int(11) NOT NULL AUTO_INCREMENT COMMENT '序号',
  `name` varchar(255) NOT NULL COMMENT '活动名称',
  `time` varchar(255) NOT NULL COMMENT '活动时间',
  `content` text NOT NULL COMMENT '活动内容',
  `place` varchar(255) NOT NULL COMMENT '活动场地',
  `goods` varchar(255) NOT NULL COMMENT '活动物资',
  `number` int(11) NOT NULL COMMENT '人员需求',
  `institution_id` varchar(255) NOT NULL COMMENT '机构id',
  `state` varchar(255) NOT NULL COMMENT '活动申请状态(0发起申请，1审核中，2驳回，3申请成功）、默认：0',
  `group` varchar(255) NOT NULL COMMENT '（0:只需要志愿者，1：只需要专业人才，1：都需要）',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 ROW_FORMAT=DYNAMIC;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `campus_will`
--

LOCK TABLES `campus_will` WRITE;
/*!40000 ALTER TABLE `campus_will` DISABLE KEYS */;
/*!40000 ALTER TABLE `campus_will` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `institution`
--

DROP TABLE IF EXISTS `institution`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `institution` (
  `id` int(11) NOT NULL AUTO_INCREMENT COMMENT '机构ID',
  `username` varchar(255) NOT NULL COMMENT '帐号',
  `name` varchar(255) NOT NULL COMMENT '机构名称',
  `password` varchar(255) NOT NULL COMMENT '密码',
  `email` varchar(255) DEFAULT NULL COMMENT '邮箱',
  `state` varchar(255) NOT NULL COMMENT '0:未认证，1：已认证',
  `type` varchar(255) NOT NULL COMMENT '机构类型',
  `certify` varchar(255) NOT NULL COMMENT '机构证明图片地址',
  `blacklist` int(11) NOT NULL COMMENT '黑名单标记0：正常 ，1：被列为黑名单）默认：0',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 ROW_FORMAT=DYNAMIC;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `institution`
--

LOCK TABLES `institution` WRITE;
/*!40000 ALTER TABLE `institution` DISABLE KEYS */;
/*!40000 ALTER TABLE `institution` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `job`
--

DROP TABLE IF EXISTS `job`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `job` (
  `id` int(11) NOT NULL AUTO_INCREMENT COMMENT '序号',
  `name` varchar(255) NOT NULL COMMENT '兼职名称',
  `time` varchar(255) NOT NULL COMMENT '兼职时间',
  `content` text NOT NULL COMMENT '兼职内容',
  `place` varchar(255) NOT NULL COMMENT '兼职地点',
  `demand` text NOT NULL COMMENT '兼职要求',
  `phone` varchar(255) NOT NULL COMMENT '兼职电话',
  `salary` varchar(255) NOT NULL COMMENT '薪资待遇',
  `state` varchar(255) NOT NULL COMMENT '活动申请状态（0发起申请，1审核中，2驳回，3申请成功）、默认：0	',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 ROW_FORMAT=DYNAMIC;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `job`
--

LOCK TABLES `job` WRITE;
/*!40000 ALTER TABLE `job` DISABLE KEYS */;
/*!40000 ALTER TABLE `job` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `stu_activity_end`
--

DROP TABLE IF EXISTS `stu_activity_end`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `stu_activity_end` (
  `id` int(11) NOT NULL AUTO_INCREMENT COMMENT '序号',
  `username` varchar(255) NOT NULL COMMENT '学号',
  `institution_id` varchar(255) NOT NULL,
  `campus_id` varchar(255) NOT NULL COMMENT '校园活动id',
  `content` text COMMENT '记录活动该学生干了什',
  `feedback_stu` text COMMENT '学生反馈',
  `feedback_institution` text COMMENT '机构反馈',
  `stu_act` varchar(255) DEFAULT NULL COMMENT '活动证明图片地址',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 ROW_FORMAT=DYNAMIC;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `stu_activity_end`
--

LOCK TABLES `stu_activity_end` WRITE;
/*!40000 ALTER TABLE `stu_activity_end` DISABLE KEYS */;
/*!40000 ALTER TABLE `stu_activity_end` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `stu_activity_ing`
--

DROP TABLE IF EXISTS `stu_activity_ing`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `stu_activity_ing` (
  `id` int(11) NOT NULL AUTO_INCREMENT COMMENT '序号',
  `username` varchar(255) NOT NULL COMMENT '学号',
  `institution_id` varchar(255) NOT NULL,
  `campus_id` varchar(255) NOT NULL COMMENT '校园活动id',
  `content` text COMMENT '记录活动该学生干了什',
  `feedback_stu` text COMMENT '学生反馈',
  `feedback_institution` text COMMENT '机构反馈',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 ROW_FORMAT=DYNAMIC;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `stu_activity_ing`
--

LOCK TABLES `stu_activity_ing` WRITE;
/*!40000 ALTER TABLE `stu_activity_ing` DISABLE KEYS */;
/*!40000 ALTER TABLE `stu_activity_ing` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `stu_activity_sh`
--

DROP TABLE IF EXISTS `stu_activity_sh`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `stu_activity_sh` (
  `id` int(11) NOT NULL AUTO_INCREMENT COMMENT '序号',
  `username` varchar(255) NOT NULL COMMENT '学号',
  `institution_id` int(11) NOT NULL,
  `campus_id` int(11) NOT NULL COMMENT '	校园活动id',
  `content` text COMMENT '记录活动该学生干了什',
  `state` varchar(255) NOT NULL DEFAULT '1' COMMENT '非空（1审核中，2未通过，3报名成功）、默认：1',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 ROW_FORMAT=DYNAMIC;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `stu_activity_sh`
--

LOCK TABLES `stu_activity_sh` WRITE;
/*!40000 ALTER TABLE `stu_activity_sh` DISABLE KEYS */;
/*!40000 ALTER TABLE `stu_activity_sh` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `stu_job_activity`
--

DROP TABLE IF EXISTS `stu_job_activity`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `stu_job_activity` (
  `id` int(11) NOT NULL AUTO_INCREMENT COMMENT '序号',
  `username` varchar(255) NOT NULL COMMENT '学号',
  `institution_id` varchar(255) NOT NULL COMMENT '	机构id',
  `job_id` varchar(255) NOT NULL COMMENT '	校园活动id',
  `content` text COMMENT '记录活动该学生干了什',
  `feedback_stu` text COMMENT '学生反馈',
  `feedback_institution` text COMMENT '机构反馈',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 ROW_FORMAT=DYNAMIC;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `stu_job_activity`
--

LOCK TABLES `stu_job_activity` WRITE;
/*!40000 ALTER TABLE `stu_job_activity` DISABLE KEYS */;
/*!40000 ALTER TABLE `stu_job_activity` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `student`
--

DROP TABLE IF EXISTS `student`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `student` (
  `username` varchar(255) NOT NULL COMMENT '学号',
  `openid` varchar(255) DEFAULT NULL COMMENT '微信唯一标',
  `name` varchar(255) NOT NULL COMMENT '姓名',
  `avator` varchar(255) DEFAULT NULL COMMENT '头像地址',
  `university` varchar(255) NOT NULL COMMENT '学校',
  `college` varchar(255) NOT NULL COMMENT '	学院',
  `major` varchar(255) NOT NULL COMMENT '专业',
  `phone` varchar(255) NOT NULL COMMENT '联系电话',
  `id_card` varchar(255) NOT NULL COMMENT '身份证号',
  `ability` text NOT NULL COMMENT '个人能力',
  `stu_id` int(11) DEFAULT NULL COMMENT '学生资格',
  `volunteer` varchar(255) NOT NULL COMMENT '志愿者资格（0不是志愿者、1是志愿者）',
  `volun_certify` varchar(255) DEFAULT NULL COMMENT '	志愿者证明图片地址',
  `profess` varchar(255) NOT NULL COMMENT '专业人才（0不是专业人才、1之后(包括1)为各类型专业人才代号标签）',
  `profess_certify` varchar(255) DEFAULT NULL COMMENT '	专业人才证明图片地址',
  `blacklist` int(11) NOT NULL COMMENT '黑名单标记（0：正常 ，1：被列为黑名单）默认：0',
  `stu_act` varchar(255) DEFAULT NULL COMMENT '活动证明图片地址',
  PRIMARY KEY (`username`) USING BTREE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 ROW_FORMAT=DYNAMIC;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `student`
--

LOCK TABLES `student` WRITE;
/*!40000 ALTER TABLE `student` DISABLE KEYS */;
/*!40000 ALTER TABLE `student` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2024-03-06 15:54:04

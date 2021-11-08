/*
SQLyog Ultimate v12.08 (64 bit)
MySQL - 8.0.20 : Database - lookfor
*********************************************************************
*/

/*!40101 SET NAMES utf8 */;

/*!40101 SET SQL_MODE=''*/;

/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;
CREATE DATABASE /*!32312 IF NOT EXISTS*/`lookfor` /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci */ /*!80016 DEFAULT ENCRYPTION='N' */;

USE `lookfor`;

/*Table structure for table `student` */

DROP TABLE IF EXISTS `student`;

CREATE TABLE `student` (
  `id` varchar(20) NOT NULL,
  `name` varchar(20) NOT NULL,
  `phonenumber` varchar(20) NOT NULL,
  `qqnumber` varchar(20) DEFAULT NULL,
  `mail` varchar(40) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

/*Data for the table `student` */

insert  into `student`(`id`,`name`,`phonenumber`,`qqnumber`,`mail`) values ('10001','张三四','23915631235','22345678910','777777@777.com'),('10002','李四五','25551321123','29876512321','29876512321@qq.com'),('10003','张三','12345689732',NULL,NULL),('10004','张三','25551321123',NULL,NULL),('10005','张伟','13966687501',NULL,NULL),('10006','张伟','13966687502',NULL,NULL),('10007','张伟','13966687503',NULL,NULL),('10008','张伟','13966687504',NULL,NULL),('10010','张伟','13966687506',NULL,NULL),('10011','张伟','13966687507',NULL,NULL),('10012','张伟','13966687508',NULL,NULL),('10013','张伟','13966687509',NULL,NULL),('10014','张伟','13966687510','123','321'),('10015','张伟','13966687511',NULL,NULL),('50100','test','test','test','test');

/*Table structure for table `teacher` */

DROP TABLE IF EXISTS `teacher`;

CREATE TABLE `teacher` (
  `id` varchar(20) NOT NULL,
  `name` varchar(20) NOT NULL,
  `phonenumber` varchar(20) NOT NULL,
  `qqnumber` varchar(20) DEFAULT NULL,
  `mail` varchar(40) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

/*Data for the table `teacher` */

insert  into `teacher`(`id`,`name`,`phonenumber`,`qqnumber`,`mail`) values ('10020','123','123','12345','123'),('20001','张三','13915631235','12345678910',NULL),('20002','李四','15551321123','9876512321','9876512321@qq.com'),('20003','张伟','15551321124','12345678',''),('20004','张伟','15551321125',NULL,NULL),('20005','张伟','15551321126',NULL,NULL),('20006','张伟','15551321127',NULL,NULL),('20007','张伟','15551321128','123123123',''),('20008','张伟','15551321129','11111',''),('20009','张伟','15551321130','66666666','666'),('20010','张伟','15551321131',NULL,NULL),('20011','张伟达','15551321132',NULL,NULL),('50001','test2','1111111112','456222',''),('50010','test','test','test','test');

/*Table structure for table `user` */

DROP TABLE IF EXISTS `user`;

CREATE TABLE `user` (
  `isAdmin` tinyint(1) NOT NULL DEFAULT '0',
  `username` varchar(20) NOT NULL,
  `password` varchar(20) NOT NULL,
  `isTeacher` tinyint(1) NOT NULL DEFAULT '0',
  `id` varchar(20) NOT NULL,
  `path` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
  PRIMARY KEY (`username`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

/*Data for the table `user` */

insert  into `user`(`isAdmin`,`username`,`password`,`isTeacher`,`id`,`path`) values (1,'admin','admin',0,'0',NULL),(0,'teacher1','teacher1',1,'10001','teacher1teacher1.jpg'),(0,'teacher2','teacher2',1,'10002',NULL),(0,'user1','user1',0,'10001','user1.jpg'),(0,'user2','user2',0,'10002','user2.jpg'),(0,'user3','user3',0,'10003','user3temp1.jpg');

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

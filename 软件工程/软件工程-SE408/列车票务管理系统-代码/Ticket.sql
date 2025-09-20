/*
 Navicat Premium Data Transfer

 Source Server         : mysql
 Source Server Type    : MySQL
 Source Server Version : 80200 (8.2.0)
 Source Host           : localhost:3306
 Source Schema         : ticket

 Target Server Type    : MySQL
 Target Server Version : 80200 (8.2.0)
 File Encoding         : 65001

*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for admin_user
-- ----------------------------
DROP TABLE IF EXISTS `admin_user`;
CREATE TABLE `admin_user`  (
  `user` varchar(30) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `pwd` varchar(30) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  PRIMARY KEY (`user`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of admin_user
-- ----------------------------
INSERT INTO `admin_user` VALUES ('admin', 'root');

-- ----------------------------
-- Table structure for association_table
-- ----------------------------
DROP TABLE IF EXISTS `association_table`;
CREATE TABLE `association_table`  (
  `P_id` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `P_id2` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  PRIMARY KEY (`P_id`, `P_id2`) USING BTREE,
  INDEX `P_id`(`P_id` ASC) USING BTREE,
  INDEX `P_id2`(`P_id2` ASC) USING BTREE,
  CONSTRAINT `association_table_ibfk_1` FOREIGN KEY (`P_id`) REFERENCES `user_table` (`P_id`) ON DELETE CASCADE ON UPDATE RESTRICT,
  CONSTRAINT `association_table_ibfk_2` FOREIGN KEY (`P_id2`) REFERENCES `user_table` (`P_id`) ON DELETE CASCADE ON UPDATE RESTRICT
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of association_table
-- ----------------------------
INSERT INTO `association_table` VALUES ('111111111111111112', '111111111111111112');
INSERT INTO `association_table` VALUES ('111111111111111112', '371326200111160017');
INSERT INTO `association_table` VALUES ('222222222222222222', '222222222222222222');
INSERT INTO `association_table` VALUES ('371326200111160017', '111111111111111111');
INSERT INTO `association_table` VALUES ('371326200111160017', '371326200111160017');
INSERT INTO `association_table` VALUES ('532301200303151311', '371326200111160017');
INSERT INTO `association_table` VALUES ('532301200303151311', '532301200303151311');

-- ----------------------------
-- Table structure for train
-- ----------------------------
DROP TABLE IF EXISTS `train`;
CREATE TABLE `train`  (
  `Train_number` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `Train_source_place` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `Train_arrival_place` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `Train_source_airport` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `Train_arrival_airport` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `Train_source_day` date NOT NULL,
  `Train_source_time` time NOT NULL,
  `Train_arrival_day` date NOT NULL,
  `Train_arrival_time` time NOT NULL,
  `Train_price` decimal(10, 2) NOT NULL,
  `Train_seats` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `Train_delete` varchar(2) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  PRIMARY KEY (`Train_number`) USING BTREE,
  INDEX `idx_Train_source_day`(`Train_source_day` ASC) USING BTREE,
  CONSTRAINT `chk_arrival_day_source_day` CHECK ((`Train_arrival_day` > `Train_source_day`) or ((`Train_arrival_day` = `Train_source_day`) and (`Train_arrival_time` > `Train_source_time`)))
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of train
-- ----------------------------
INSERT INTO `train` VALUES ('BF0025', '北京', '广州', '北京南站', '广州南站', '2025-01-09', '10:00:00', '2025-01-09', '12:00:00', 590.00, '41', '0');
INSERT INTO `train` VALUES ('BG0013', '北京', '广州', '北京南站', '广州南站', '2025-01-05', '10:00:00', '2025-01-05', '12:00:00', 550.00, '46', '0');
INSERT INTO `train` VALUES ('BG0037', '北京', '广州', '北京南站', '广州南站', '2025-01-13', '10:00:00', '2025-01-13', '12:00:00', 630.00, '36', '0');
INSERT INTO `train` VALUES ('BS0001', '北京', '上海', '北京西站', '上海虹桥', '2025-01-01', '08:30:00', '2025-01-01', '12:30:00', 889.00, '5', '0');
INSERT INTO `train` VALUES ('BS0005', '北京', '深圳', '北京南站', '深圳北站', '2025-01-02', '14:00:00', '2025-01-02', '16:00:00', 580.00, '42', '0');
INSERT INTO `train` VALUES ('BS0019', '北京', '深圳', '北京西站', '深圳北站', '2025-01-07', '10:00:00', '2025-01-07', '12:00:00', 570.00, '40', '0');
INSERT INTO `train` VALUES ('BS0031', '北京', '深圳', '北京西站', '深圳北站', '2025-01-11', '10:00:00', '2025-01-11', '12:00:00', 610.00, '37', '0');
INSERT INTO `train` VALUES ('BS0043', '北京', '深圳', '北京西站', '深圳北站', '2025-01-15', '10:00:00', '2025-01-15', '12:00:00', 650.00, '35', '0');
INSERT INTO `train` VALUES ('BS0049', '北京', '上海', '北京西站', '上海南站', '2025-01-17', '08:00:00', '2025-01-17', '10:00:00', 1200.00, '80', '0');
INSERT INTO `train` VALUES ('BS0050', '北京', '广州', '北京南站', '广州南站', '2025-01-17', '12:00:00', '2025-01-17', '14:00:00', 1500.00, '100', '0');
INSERT INTO `train` VALUES ('BS10000', '北京', '上海··', '北京南站', '上海虹桥', '2025-01-20', '00:00:00', '2025-01-20', '02:00:00', 100.00, '10', '0');
INSERT INTO `train` VALUES ('BS9999', '北京', '上海', '北京西站', '上海虹桥', '2025-01-01', '13:30:00', '2025-01-01', '15:30:00', 550.00, '45', '0');
INSERT INTO `train` VALUES ('CB0009', '重庆', '北京', '重庆北站', '北京南站', '2025-01-03', '20:00:00', '2025-01-03', '22:00:00', 630.00, '36', '0');
INSERT INTO `train` VALUES ('CB0016', '成都', '北京', '成都东站', '北京南站', '2025-01-06', '09:30:00', '2025-01-06', '11:30:00', 560.00, '44', '0');
INSERT INTO `train` VALUES ('CB0028', '成都', '北京', '成都东站', '北京南站', '2025-01-10', '09:30:00', '2025-01-10', '11:30:00', 600.00, '40', '1');
INSERT INTO `train` VALUES ('CB0040', '成都', '北京', '成都东站', '北京南站', '2025-01-14', '09:30:00', '2025-01-14', '11:30:00', 640.00, '36', '0');
INSERT INTO `train` VALUES ('CC0055', '成都', '重庆', '成都南站', '重庆北站', '2025-01-19', '09:00:00', '2025-01-19', '10:00:00', 400.00, '30', '0');
INSERT INTO `train` VALUES ('CC0068', '成都', '重庆', '成都东站', '重庆北站', '2025-01-23', '11:00:00', '2025-01-23', '13:00:00', 600.00, '45', '0');
INSERT INTO `train` VALUES ('CC0078', '成都', '重庆', '成都东站', '重庆北站', '2025-01-26', '11:00:00', '2025-01-26', '13:00:00', 600.00, '45', '0');
INSERT INTO `train` VALUES ('CC0088', '成都', '重庆', '成都东站', '重庆北站', '2025-01-29', '11:00:00', '2025-01-29', '13:00:00', 600.00, '45', '0');
INSERT INTO `train` VALUES ('CG0007', '成都', '广州', '成都东站', '广州南站', '2025-01-03', '10:00:00', '2025-01-03', '12:00:00', 530.00, '46', '0');
INSERT INTO `train` VALUES ('CG0020', '重庆', '广州', '重庆北站', '广州南站', '2025-01-07', '14:30:00', '2025-01-07', '16:30:00', 620.00, '35', '0');
INSERT INTO `train` VALUES ('CG0032', '重庆', '广州', '重庆北站', '广州南站', '2025-01-11', '14:30:00', '2025-01-11', '16:30:00', 660.00, '34', '0');
INSERT INTO `train` VALUES ('CG0090', '成都', '广州', '成都东站', '广州南站', '2025-01-30', '17:00:00', '2025-01-30', '19:00:00', 800.00, '55', '0');
INSERT INTO `train` VALUES ('CN0057', '重庆', '南京', '重庆北站', '南京南站', '2025-01-19', '13:30:00', '2025-01-19', '14:30:00', 500.00, '40', '0');
INSERT INTO `train` VALUES ('CN0083', '长沙', '南宁', '长沙南站', '南宁东站', '2025-01-28', '08:30:00', '2025-01-28', '10:30:00', 400.00, '30', '0');
INSERT INTO `train` VALUES ('CS0014', '重庆', '深圳', '重庆北站', '深圳北站', '2025-01-05', '14:30:00', '2025-01-05', '16:30:00', 600.00, '40', '0');
INSERT INTO `train` VALUES ('CS0026', '重庆', '深圳', '重庆北站', '深圳北站', '2025-01-09', '14:30:00', '2025-01-09', '16:30:00', 640.00, '36', '1');
INSERT INTO `train` VALUES ('CS0038', '重庆', '深圳', '重庆北站', '深圳北站', '2025-01-13', '14:30:00', '2025-01-13', '16:30:00', 680.00, '32', '0');
INSERT INTO `train` VALUES ('CS0056', '成都', '上海', '成都东站', '上海南站', '2025-01-19', '11:00:00', '2025-01-19', '12:00:00', 800.00, '55', '0');
INSERT INTO `train` VALUES ('CW0058', '重庆', '武汉', '重庆北站', '武汉站', '2025-01-20', '15:30:00', '2025-01-20', '16:30:00', 450.00, '35', '0');
INSERT INTO `train` VALUES ('CX0066', '重庆', '西安', '重庆北站', '西安北站', '2025-01-22', '17:00:00', '2025-01-22', '19:00:00', 700.00, '50', '0');
INSERT INTO `train` VALUES ('CX0072', '成都', '西安', '成都东站', '西安北站', '2025-01-24', '11:30:00', '2025-01-24', '13:30:00', 700.00, '50', '0');
INSERT INTO `train` VALUES ('CX0076', '重庆', '西安', '重庆北站', '西安北站', '2025-01-26', '17:00:00', '2025-01-26', '19:00:00', 700.00, '50', '0');
INSERT INTO `train` VALUES ('CX0082', '成都', '西安', '成都东站', '西安北站', '2025-01-28', '11:30:00', '2025-01-28', '13:30:00', 700.00, '50', '0');
INSERT INTO `train` VALUES ('CX0092', '成都', '西安', '成都东站', '西安北站', '2025-01-31', '11:30:00', '2025-01-31', '13:30:00', 700.00, '50', '0');
INSERT INTO `train` VALUES ('GB0054', '广州', '北京', '深圳北站', '北京西站', '2025-01-18', '23:00:00', '2025-01-19', '01:00:00', 1200.00, '80', '0');
INSERT INTO `train` VALUES ('GC0004', '广州', '重庆', '广州南站', '重庆北站', '2025-01-02', '09:30:00', '2025-01-02', '11:30:00', 520.00, '48', '0');
INSERT INTO `train` VALUES ('GC0067', '贵阳', '成都', '贵阳北站', '成都东站', '2025-01-23', '08:00:00', '2025-01-23', '10:00:00', 500.00, '40', '0');
INSERT INTO `train` VALUES ('GC0077', '贵阳', '成都', '贵阳北站', '成都东站', '2025-01-26', '08:00:00', '2025-01-26', '10:00:00', 500.00, '40', '0');
INSERT INTO `train` VALUES ('GC0087', '贵阳', '成都', '贵阳北站', '成都东站', '2025-01-29', '08:00:00', '2025-01-29', '10:00:00', 500.00, '40', '0');
INSERT INTO `train` VALUES ('GH0053', '广州', '杭州', '广州南站', '杭州东站', '2025-01-18', '20:00:00', '2025-01-18', '22:00:00', 600.00, '44', '0');
INSERT INTO `train` VALUES ('GS0010', '广州', '上海', '广州南站', '上海虹桥', '2025-01-04', '09:30:00', '2025-01-04', '11:30:00', 540.00, '46', '0');
INSERT INTO `train` VALUES ('GS0017', '广州', '深圳', '广州南站', '深圳北站', '2025-01-06', '14:00:00', '2025-01-06', '16:00:00', 610.00, '39', '0');
INSERT INTO `train` VALUES ('GS0022', '广州', '上海', '广州南站', '上海虹桥', '2025-01-08', '09:30:00', '2025-01-08', '11:30:00', 580.00, '42', '0');
INSERT INTO `train` VALUES ('GS0029', '广州', '深圳', '广州南站', '深圳北站', '2025-01-10', '14:00:00', '2025-01-10', '16:00:00', 650.00, '33', '0');
INSERT INTO `train` VALUES ('GS0034', '广州', '上海', '广州南站', '上海虹桥', '2025-01-12', '09:30:00', '2025-01-12', '11:30:00', 620.00, '37', '1');
INSERT INTO `train` VALUES ('GS0041', '广州', '深圳', '广州南站', '深圳北站', '2025-01-14', '14:00:00', '2025-01-14', '16:00:00', 690.00, '31', '0');
INSERT INTO `train` VALUES ('GW0070', '广州', '武汉', '广州南站', '武汉站', '2025-01-24', '17:00:00', '2025-01-24', '19:00:00', 700.00, '50', '0');
INSERT INTO `train` VALUES ('GW0080', '广州', '武汉', '广州南站', '武汉站', '2025-01-27', '17:00:00', '2025-01-27', '19:00:00', 700.00, '50', '0');
INSERT INTO `train` VALUES ('HB0001', '杭州', '北京', '杭州东站', '北京西站', '2025-01-16', '02:00:00', '2025-01-16', '04:00:00', 200.00, '10', '0');
INSERT INTO `train` VALUES ('HC0003', '杭州', '成都', '杭州东站', '成都东站', '2025-01-01', '18:00:00', '2025-01-01', '20:00:00', 600.00, '40', '0');
INSERT INTO `train` VALUES ('HC0021', '杭州', '成都', '杭州东站', '成都东站', '2025-01-07', '20:00:00', '2025-01-07', '22:00:00', 670.00, '32', '0');
INSERT INTO `train` VALUES ('HC0033', '杭州', '成都', '杭州东站', '成都东站', '2025-01-11', '20:00:00', '2025-01-11', '22:00:00', 710.00, '28', '0');
INSERT INTO `train` VALUES ('HC0044', '杭州', '长沙', '杭州东站', '长沙南站', '2025-01-15', '20:15:00', '2025-01-15', '23:50:00', 328.00, '8', '0');
INSERT INTO `train` VALUES ('HC0065', '哈尔滨', '重庆', '哈尔滨西站', '重庆北站', '2025-01-22', '14:00:00', '2025-01-22', '16:00:00', 800.00, '55', '0');
INSERT INTO `train` VALUES ('HC0075', '哈尔滨', '重庆', '哈尔滨西站', '重庆北站', '2025-01-25', '14:00:00', '2025-01-25', '16:00:00', 800.00, '55', '0');
INSERT INTO `train` VALUES ('HJ0045', '杭州', '北京', '杭州东站', '北京南站', '2025-01-15', '19:15:00', '2025-01-15', '22:20:00', 1000.00, '60', '0');
INSERT INTO `train` VALUES ('HN0059', '杭州', '南京', '杭州东站', '南京南站', '2025-01-20', '17:00:00', '2025-01-20', '18:00:00', 300.00, '25', '0');
INSERT INTO `train` VALUES ('HN0093', '哈尔滨', '南京', '哈尔滨西站', '南京南站', '2025-01-31', '08:30:00', '2025-01-31', '10:30:00', 600.00, '45', '0');
INSERT INTO `train` VALUES ('HS0008', '杭州', '深圳', '杭州东站', '深圳北站', '2025-01-03', '14:30:00', '2025-01-03', '16:30:00', 580.00, '42', '0');
INSERT INTO `train` VALUES ('HS0015', '杭州', '上海', '杭州东站', '上海虹桥', '2025-01-05', '20:00:00', '2025-01-05', '22:00:00', 650.00, '35', '0');
INSERT INTO `train` VALUES ('HS0027', '杭州', '上海', '杭州东站', '上海虹桥', '2025-01-09', '20:00:00', '2025-01-09', '22:00:00', 690.00, '31', '0');
INSERT INTO `train` VALUES ('HS0039', '杭州', '上海', '杭州东站', '上海虹桥', '2025-01-13', '20:00:00', '2025-01-13', '22:00:00', 730.00, '26', '0');
INSERT INTO `train` VALUES ('HX0046', '杭州', '西安', '杭州东站', '西安北站', '2025-01-16', '06:55:00', '2025-01-16', '09:20:00', 387.00, '9', '0');
INSERT INTO `train` VALUES ('HX0060', '杭州', '厦门', '杭州东站', '厦门北站', '2025-01-20', '19:00:00', '2025-01-20', '20:00:00', 600.00, '45', '0');
INSERT INTO `train` VALUES ('JZ0085', '济南', '郑州', '济南西站', '郑州东站', '2025-01-29', '14:00:00', '2025-01-29', '16:00:00', 500.00, '40', '0');
INSERT INTO `train` VALUES ('NC0094', '南京', '长沙', '南京南站', '长沙南站', '2025-01-31', '11:30:00', '2025-01-31', '13:30:00', 700.00, '50', '0');
INSERT INTO `train` VALUES ('NG0084', '南宁', '广州', '南宁东站', '广州南站', '2025-01-28', '11:30:00', '2025-01-28', '13:30:00', 300.00, '25', '0');
INSERT INTO `train` VALUES ('NH0064', '南京', '哈尔滨', '南京南站', '哈尔滨西站', '2025-01-22', '11:30:00', '2025-01-22', '13:30:00', 700.00, '50', '0');
INSERT INTO `train` VALUES ('NH0074', '南京', '哈尔滨', '南京南站', '哈尔滨西站', '2025-01-25', '11:30:00', '2025-01-25', '13:30:00', 700.00, '50', '0');
INSERT INTO `train` VALUES ('NS0062', '南京', '上海', '南京南站', '上海虹桥', '2025-01-21', '23:00:00', '2025-01-22', '00:00:00', 300.00, '20', '0');
INSERT INTO `train` VALUES ('NW0061', '南京', '武汉', '南京南站', '武汉站', '2025-01-21', '21:00:00', '2025-01-21', '22:00:00', 400.00, '30', '0');
INSERT INTO `train` VALUES ('QC0089', '青岛', '成都', '青岛北站', '成都东站', '2025-01-30', '14:00:00', '2025-01-30', '16:00:00', 700.00, '50', '0');
INSERT INTO `train` VALUES ('SB0011', '深圳', '北京', '深圳北站', '北京西站', '2025-01-04', '14:00:00', '2025-01-04', '16:00:00', 590.00, '40', '0');
INSERT INTO `train` VALUES ('SB0023', '深圳', '北京', '深圳北站', '北京西站', '2025-01-08', '14:00:00', '2025-01-08', '16:00:00', 630.00, '36', '0');
INSERT INTO `train` VALUES ('SB0035', '深圳', '北京', '深圳北站', '北京西站', '2025-01-12', '14:00:00', '2025-01-12', '16:00:00', 670.00, '31', '0');
INSERT INTO `train` VALUES ('SC0006', '上海', '重庆', '上海虹桥', '重庆北站', '2025-01-02', '19:30:00', '2025-01-02', '21:30:00', 620.00, '38', '0');
INSERT INTO `train` VALUES ('SC0012', '上海', '成都', '上海虹桥', '成都东站', '2025-01-04', '19:30:00', '2025-01-04', '21:30:00', 640.00, '35', '0');
INSERT INTO `train` VALUES ('SC0018', '上海', '重庆', '上海虹桥', '重庆北站', '2025-01-06', '19:30:00', '2025-01-06', '21:30:00', 660.00, '34', '0');
INSERT INTO `train` VALUES ('SC0024', '上海', '成都', '上海虹桥', '成都东站', '2025-01-08', '19:30:00', '2025-01-08', '21:30:00', 680.00, '30', '0');
INSERT INTO `train` VALUES ('SC0030', '上海', '重庆', '上海虹桥', '重庆北站', '2025-01-10', '19:30:00', '2025-01-10', '21:30:00', 700.00, '26', '0');
INSERT INTO `train` VALUES ('SC0036', '上海', '成都', '上海虹桥', '成都东站', '2025-01-12', '19:30:00', '2025-01-12', '21:30:00', 720.00, '27', '0');
INSERT INTO `train` VALUES ('SC0042', '上海', '重庆', '上海虹桥', '重庆北站', '2025-01-14', '19:30:00', '2025-01-14', '21:30:00', 740.00, '26', '0');
INSERT INTO `train` VALUES ('SC0047', '深圳', '成都', '深圳北站', '成都东站', '2025-01-16', '19:20:00', '2025-01-16', '22:15:00', 600.00, '10', '0');
INSERT INTO `train` VALUES ('SC0052', '上海', '成都', '上海虹桥', '成都东站', '2025-01-18', '17:30:00', '2025-01-18', '19:30:00', 1000.00, '70', '0');
INSERT INTO `train` VALUES ('SG0048', '上海', '广州', '上海南站', '广州南站', '2025-01-16', '21:20:00', '2025-01-17', '00:15:00', 470.00, '0', '0');
INSERT INTO `train` VALUES ('SN0063', '沈阳', '南京', '沈阳北站', '南京南站', '2025-01-21', '08:30:00', '2025-01-21', '10:30:00', 600.00, '45', '0');
INSERT INTO `train` VALUES ('SN0073', '沈阳', '南京', '沈阳北站', '南京南站', '2025-01-25', '08:30:00', '2025-01-25', '10:30:00', 600.00, '45', '0');
INSERT INTO `train` VALUES ('SS0051', '上海', '深圳', '上海南站', '深圳北站', '2025-01-17', '14:30:00', '2025-01-17', '16:30:00', 800.00, '55', '0');
INSERT INTO `train` VALUES ('XC0071', '西宁', '成都', '西宁站', '成都东站', '2025-01-24', '08:30:00', '2025-01-24', '10:30:00', 600.00, '45', '0');
INSERT INTO `train` VALUES ('XC0081', '西宁', '成都', '西宁站', '成都东站', '2025-01-27', '08:30:00', '2025-01-27', '10:30:00', 600.00, '45', '0');
INSERT INTO `train` VALUES ('XC0091', '西宁', '成都', '西宁站', '成都东站', '2025-01-30', '08:30:00', '2025-01-30', '10:30:00', 600.00, '45', '0');
INSERT INTO `train` VALUES ('ZG0069', '郑州', '广州', '郑州东站', '广州南站', '2025-01-23', '14:00:00', '2025-01-23', '16:00:00', 800.00, '55', '0');
INSERT INTO `train` VALUES ('ZG0079', '郑州', '广州', '郑州东站', '广州南站', '2025-01-27', '14:00:00', '2025-01-27', '16:00:00', 800.00, '55', '0');
INSERT INTO `train` VALUES ('ZG0080', '郑州', '广州', '郑州东站', '广州南站', '2025-01-27', '14:00:00', '2025-01-27', '16:00:00', 800.00, '55', '0');
INSERT INTO `train` VALUES ('ZT0086', '郑州', '太原', '郑州东站', '太原南站', '2025-01-29', '17:00:00', '2025-01-29', '19:00:00', 600.00, '45', '0');
INSERT INTO `train` VALUES ('ZT0087', '郑州', '太原', '郑州东站', '太原南站', '2025-01-29', '17:00:00', '2025-01-29', '19:00:00', 600.00, '45', '0');
INSERT INTO `train` VALUES ('ZT0088', '郑州', '太原', '郑州东站', '太原南站', '2025-01-29', '17:00:00', '2025-01-29', '19:00:00', 600.00, '45', '0');

-- ----------------------------
-- Table structure for ticket
-- ----------------------------
DROP TABLE IF EXISTS `ticket`;
CREATE TABLE `ticket`  (
  `Ticket_id` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `Train_number` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `Ticket_date` datetime NOT NULL,
  `Ticket_seat` varchar(10) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `P_id` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `P_id2` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `Ticket_is_pay` tinyint(1) NOT NULL,
  PRIMARY KEY (`Ticket_id`) USING BTREE,
  INDEX `Train_number`(`Train_number` ASC) USING BTREE,
  INDEX `P_id`(`P_id` ASC) USING BTREE,
  INDEX `P_id2`(`P_id2` ASC) USING BTREE,
  CONSTRAINT `ticket_ibfk_1` FOREIGN KEY (`Train_number`) REFERENCES `train` (`Train_number`) ON DELETE CASCADE ON UPDATE RESTRICT,
  CONSTRAINT `ticket_ibfk_2` FOREIGN KEY (`P_id`) REFERENCES `user_table` (`P_id`) ON DELETE CASCADE ON UPDATE RESTRICT,
  CONSTRAINT `ticket_ibfk_3` FOREIGN KEY (`P_id2`) REFERENCES `user_table` (`P_id`) ON DELETE CASCADE ON UPDATE RESTRICT
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of ticket
-- ----------------------------
INSERT INTO `ticket` VALUES ('1000000006', 'BS0019', '2025-01-07 00:00:00', 'A1', '371326200111160017', '371326200111160017', 0);
INSERT INTO `ticket` VALUES ('1000000018', 'SC0024', '2025-01-08 17:55:20', 'A1', '371326200111160017', '371326200111160017', 0);
INSERT INTO `ticket` VALUES ('1000000024', 'SC0030', '2025-01-08 18:05:23', 'A1', '371326200111160017', '371326200111160017', 1);
INSERT INTO `ticket` VALUES ('1000000027', 'GS0034', '2025-01-08 19:28:07', 'A1', '371326200111160017', '371326200111160017', 3);
INSERT INTO `ticket` VALUES ('1000000029', 'GH0053', '2025-01-09 12:15:25', 'A1', '371326200111160017', '371326200111160017', 1);
INSERT INTO `ticket` VALUES ('1000000031', 'SG0048', '2025-01-09 20:21:33', 'A1', '111111111111111111', '371326200111160017', 0);
INSERT INTO `ticket` VALUES ('1000000033', 'GS0029', '2025-01-10 12:13:35', 'A2', '371326200111160017', '371326200111160017', 0);
INSERT INTO `ticket` VALUES ('1000000035', 'BS0031', '2025-01-10 12:13:57', 'A1', '371326200111160017', '371326200111160017', 0);
INSERT INTO `ticket` VALUES ('1000000036', 'GS0029', '2025-01-10 12:29:17', 'A3', '371326200111160017', '371326200111160017', 0);
INSERT INTO `ticket` VALUES ('1000000037', 'HC0033', '2025-01-10 12:29:23', 'A1', '371326200111160017', '371326200111160017', 0);
INSERT INTO `ticket` VALUES ('1000000038', 'SC0036', '2025-01-10 12:29:28', 'A1', '371326200111160017', '371326200111160017', 0);
INSERT INTO `ticket` VALUES ('1000000045', 'SC0030', '2025-01-10 15:41:58', 'A4', '371326200111160017', '532301200303151311', 0);
INSERT INTO `ticket` VALUES ('1000000047', 'SC0030', '2025-01-10 15:42:18', 'A6', '371326200111160017', '532301200303151311', 0);
INSERT INTO `ticket` VALUES ('1000000048', 'BS0031', '2025-01-10 15:43:36', 'A2', '371326200111160017', '532301200303151311', 0);
INSERT INTO `ticket` VALUES ('1000000049', 'SB0035', '2025-01-10 15:44:44', 'A4', '532301200303151311', '532301200303151311', 1);
INSERT INTO `ticket` VALUES ('1000000051', 'SB0035', '2025-01-10 15:45:02', 'A6', '532301200303151311', '532301200303151311', 0);
INSERT INTO `ticket` VALUES ('1000000053', 'BG0037', '2025-01-10 15:45:26', 'A2', '532301200303151311', '532301200303151311', 0);
INSERT INTO `ticket` VALUES ('1000000057', 'HS0039', '2025-01-12 08:59:37', 'A1', '371326200111160017', '371326200111160017', 0);

-- ----------------------------
-- Table structure for user_table
-- ----------------------------
DROP TABLE IF EXISTS `user_table`;
CREATE TABLE `user_table`  (
  `P_id` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `P_name` varchar(30) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `P_tel` varchar(30) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `P_mail` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `P_sex` varchar(10) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `P_work` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `P_pwd` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `P_login` varchar(1) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL DEFAULT '0',
  PRIMARY KEY (`P_id`) USING BTREE,
  UNIQUE INDEX `P_tel`(`P_tel` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of user_table
-- ----------------------------
INSERT INTO `user_table` VALUES ('111111111111111111', '111', 'undefined', '11@qq.11', '男', '111111', '111111', '1');
INSERT INTO `user_table` VALUES ('111111111111111112', '11', '11111111112', 'undefined', '男', '11', '123456', '1');
INSERT INTO `user_table` VALUES ('222222222222222222', '1', '1', '1', '1', '1', '1', '0');
INSERT INTO `user_table` VALUES ('371326200111160017', '赵瑞琪', '17568119458', 'zrq011116@163.com', '男', '浙江工业大学', '123456', '1');
INSERT INTO `user_table` VALUES ('532301200303151311', 'ws', '17816163972', '1662732752@qq.com', '男', 'zjut', '123456', '1');
-- INSERT INTO `user_table` VALUES ('admin', 'admin', '111', '111', '111', '111', '111111', '1');

-- ----------------------------
-- View structure for ticket_view
-- ----------------------------
DROP VIEW IF EXISTS `ticket_view`;
CREATE ALGORITHM = UNDEFINED SQL SECURITY DEFINER VIEW `ticket_view` AS select `ticket`.`Ticket_id` AS `Ticket_id`,`ticket`.`Train_number` AS `Train_number`,`ticket`.`Ticket_date` AS `Ticket_date`,`ticket`.`P_id` AS `P_id`,`ticket`.`P_id2` AS `P_id2`,`ticket`.`Ticket_seat` AS `Ticket_seat`,`train`.`Train_source_place` AS `Train_source_place`,`train`.`Train_arrival_place` AS `Train_arrival_place`,`train`.`Train_source_airport` AS `Train_source_airport`,`train`.`Train_arrival_airport` AS `Train_arrival_airport`,`train`.`Train_source_day` AS `Train_source_day`,`train`.`Train_source_time` AS `Train_source_time`,`train`.`Train_arrival_day` AS `Train_arrival_day`,`train`.`Train_arrival_time` AS `Train_arrival_time`,`train`.`Train_price` AS `Train_price`,`train`.`Train_seats` AS `Train_seats`,`user_table`.`P_name` AS `P_name`,`user_table`.`P_tel` AS `P_tel`,`user_table`.`P_mail` AS `P_mail`,`user_table`.`P_sex` AS `P_sex`,`user_table`.`P_work` AS `P_work`,`ticket`.`Ticket_is_pay` AS `Ticket_is_pay` from ((`ticket` join `train` on((`ticket`.`Train_number` = `train`.`Train_number`))) join `user_table` on((`ticket`.`P_id` = `user_table`.`P_id`))) where ((`ticket`.`P_id` is not null) and (`ticket`.`P_id2` is not null));

SET FOREIGN_KEY_CHECKS = 1;




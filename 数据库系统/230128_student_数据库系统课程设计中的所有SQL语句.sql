-- ----------------------------
-- Table structure for student_province230128
-- ----------------------------
DROP TABLE IF EXISTS "public"."student_province230128";
CREATE TABLE "public"."student_province230128" (
  "pno230128" varchar(255) NOT NULL,
  "pname230128" varchar(255),
  PRIMARY KEY ("pno230128")
);

INSERT INTO "public"."student_province230128" VALUES ('P001', '浙江');
INSERT INTO "public"."student_province230128" VALUES ('P002', '江苏');
INSERT INTO "public"."student_province230128" VALUES ('P003', '上海');
INSERT INTO "public"."student_province230128" VALUES ('P004', '广东');
INSERT INTO "public"."student_province230128" VALUES ('P005', '北京');
INSERT INTO "public"."student_province230128" VALUES ('P006', '山东');

-- ----------------------------
-- Table structure for student_city230128
-- ----------------------------
DROP TABLE IF EXISTS "public"."student_city230128";
CREATE TABLE "public"."student_city230128" (
  "cino230128" varchar(255) NOT NULL,
  "ciname230128" varchar(255),
  "pno230128" varchar(255),
  PRIMARY KEY ("cino230128"),
  FOREIGN KEY ("pno230128") REFERENCES "public"."student_province230128" ("pno230128")
);
INSERT INTO "public"."student_city230128" VALUES ('C001', '杭州', 'P001');
INSERT INTO "public"."student_city230128" VALUES ('C002', '苏州', 'P002');
INSERT INTO "public"."student_city230128" VALUES ('C003', '宁波', 'P001');
INSERT INTO "public"."student_city230128" VALUES ('C004', '上海', 'P003');
INSERT INTO "public"."student_city230128" VALUES ('C005', '南京', 'P002');
INSERT INTO "public"."student_city230128" VALUES ('C006', '临沂', 'P006');


-- ----------------------------
-- Table structure for student_district230128
-- ----------------------------
DROP TABLE IF EXISTS "public"."student_district230128";
CREATE TABLE "public"."student_district230128" (
  "dno230128" varchar(255) NOT NULL,
  "dname230128" varchar(255),
  "cino230128" varchar(255),
  PRIMARY KEY ("dno230128"),
  FOREIGN KEY ("cino230128") REFERENCES "public"."student_city230128" ("cino230128")
);
INSERT INTO "public"."student_district230128" VALUES ('D001', '西湖区', 'C001');
INSERT INTO "public"."student_district230128" VALUES ('D002', '吴江区', 'C002');
INSERT INTO "public"."student_district230128" VALUES ('D003', '上城区', 'C001');
INSERT INTO "public"."student_district230128" VALUES ('D004', '浦东区', 'C004');
INSERT INTO "public"."student_district230128" VALUES ('D005', '海曙区', 'C003');
INSERT INTO "public"."student_district230128" VALUES ('D006', '平邑县', 'C006');




-- ----------------------------
-- Table structure for student_majors230128
-- ----------------------------
DROP TABLE IF EXISTS "public"."student_majors230128";
CREATE TABLE "public"."student_majors230128" (
  "mno230128" varchar(255) NOT NULL,
  "mname230128" varchar(255),
  PRIMARY KEY ("mno230128")
);
INSERT INTO "public"."student_majors230128" VALUES ('M004', '大数据23级');
INSERT INTO "public"."student_majors230128" VALUES ('M005', '物联网23级');
INSERT INTO "public"."student_majors230128" VALUES ('M002', '计科23级');
INSERT INTO "public"."student_majors230128" VALUES ('M003', '网工23级');
INSERT INTO "public"."student_majors230128" VALUES ('M101', '软工22级');
INSERT INTO "public"."student_majors230128" VALUES ('M102', '计科22级');
INSERT INTO "public"."student_majors230128" VALUES ('M103', '网工22级');
INSERT INTO "public"."student_majors230128" VALUES ('M104', '大数据22级');
INSERT INTO "public"."student_majors230128" VALUES ('M105', '物联网22级');
INSERT INTO "public"."student_majors230128" VALUES ('M001', '计科24级');


-- ----------------------------
-- Table structure for student_classes230128
-- ----------------------------
DROP TABLE IF EXISTS "public"."student_classes230128";
CREATE TABLE "public"."student_classes230128" (
  "clno230128" varchar(255) NOT NULL,
  "clname230128" varchar(255),
  "mno230128" varchar(255),
  PRIMARY KEY ("clno230128"),
  FOREIGN KEY ("mno230128") REFERENCES "public"."student_majors230128" ("mno230128")
);
INSERT INTO "public"."student_classes230128" VALUES ('CL002', '计科2301班', 'M002');
INSERT INTO "public"."student_classes230128" VALUES ('CL004', '网工2301班', 'M003');
INSERT INTO "public"."student_classes230128" VALUES ('CL005', '计科2302班', 'M002');
INSERT INTO "public"."student_classes230128" VALUES ('CL101', '软工2201班', 'M101');
INSERT INTO "public"."student_classes230128" VALUES ('CL102', '计科2201班', 'M102');
INSERT INTO "public"."student_classes230128" VALUES ('CL103', '软工2202班', 'M101');
INSERT INTO "public"."student_classes230128" VALUES ('CL104', '网工2201班', 'M103');
INSERT INTO "public"."student_classes230128" VALUES ('CL105', '计科2202班', 'M102');
INSERT INTO "public"."student_classes230128" VALUES ('CL007', '物联网2301班', 'M005');
INSERT INTO "public"."student_classes230128" VALUES ('CL106', '大数据2301班', 'M004');
INSERT INTO "public"."student_classes230128" VALUES ('CL107', '大数据2201班', 'M104');
INSERT INTO "public"."student_classes230128" VALUES ('CL108', '物联网2201班', 'M105');
INSERT INTO "public"."student_classes230128" VALUES ('CL006', '计科2303班', 'M002');
INSERT INTO "public"."student_classes230128" VALUES ('CL001', '计科2403班', 'M001');
INSERT INTO "public"."student_classes230128" VALUES ('CL003', '计科2402班', 'M001');



-- ----------------------------
-- Table structure for student_courses230128
-- ----------------------------
DROP TABLE IF EXISTS "public"."student_courses230128";
CREATE TABLE "public"."student_courses230128" (
  "cno230128" varchar(255) NOT NULL,
	  "clno230128" varchar(255),
  "cname230128" varchar(255),
	  "ccredit230128" float8,
  "cevaluation230128" varchar(255),
  "cterm230128" varchar(255),
  "cperiod230128" int4,
  PRIMARY KEY ("cno230128"),
  FOREIGN KEY ("clno230128") REFERENCES "public"."student_classes230128" ("clno230128")
);

INSERT INTO "public"."student_courses230128" VALUES ('CO002', 'CL002', '计算机组成原理', 4, '考试', '2024春季', 48);
INSERT INTO "public"."student_courses230128" VALUES ('CO003', 'CL003', '计算方法及实现', 2, '考查', '2023秋季', 16);
INSERT INTO "public"."student_courses230128" VALUES ('CO004', 'CL004', '网络安全', 3, '考试', '2024春季', 32);
INSERT INTO "public"."student_courses230128" VALUES ('CO005', 'CL005', '数据结构', 3, '考试', '2023秋季', 48);
INSERT INTO "public"."student_courses230128" VALUES ('CO101', 'CL101', 'JAVAWEB', 3, '考试', '2022秋季', 48);
INSERT INTO "public"."student_courses230128" VALUES ('CO102', 'CL102', '计算机组成原理', 4, '考试', '2022春季', 48);
INSERT INTO "public"."student_courses230128" VALUES ('CO103', 'CL103', '计算方法及实现', 2, '考查', '2022秋季', 16);
INSERT INTO "public"."student_courses230128" VALUES ('CO104', 'CL104', '网络安全', 3, '考试', '2022春季', 32);
INSERT INTO "public"."student_courses230128" VALUES ('CO105', 'CL105', '数据结构', 3, '考试', '2022秋季', 48);
INSERT INTO "public"."student_courses230128" VALUES ('CO007', 'CL007', '万物互联', 2, '考查', '2023秋季', 16);
INSERT INTO "public"."student_courses230128" VALUES ('CO106', 'CL106', '数据分析', 4, '考试', '2023春季', 48);
INSERT INTO "public"."student_courses230128" VALUES ('CO107', 'CL107', '数据分析', 4, '考试', '2022春季', 48);
INSERT INTO "public"."student_courses230128" VALUES ('CO108', 'CL108', '万物互联', 2, '考查', '2022秋季', 16);
INSERT INTO "public"."student_courses230128" VALUES ('CO001', 'CL001', '数据库原理', 3, '考试', '2023秋季', 48);
INSERT INTO "public"."student_courses230128" VALUES ('CO006', 'CL001', '数字电路', 2, '考试', '2023秋季', 16);



-- ----------------------------
-- Table structure for student_students230128
-- ----------------------------
DROP TABLE IF EXISTS "public"."student_students230128";
CREATE TABLE "public"."student_students230128" (
  "sno230128" varchar(255) NOT NULL,
  "sname230128" varchar(255),
  "ssex230128" varchar(255),
  "sage230128" int4,
  "scredits230128" float8,
  "slocation230128" varchar(255),
  "spassword230128" varchar(255),
  "clno230128" varchar(255),
  "sscore230128" float8,
  PRIMARY KEY ("sno230128"),
  FOREIGN KEY ("clno230128") REFERENCES "public"."student_classes230128" ("clno230128"),
	FOREIGN KEY ("slocation230128") REFERENCES "public"."student_district230128" ("dno230128")
);

INSERT INTO "public"."student_students230128" VALUES ('202203151304', '李四', '女', 19, 0, 'D002', '123456', 'CL002', 0);
INSERT INTO "public"."student_students230128" VALUES ('202203151318', '王五', '男', 24, 0, 'D005', '123456', 'CL001', 0);
INSERT INTO "public"."student_students230128" VALUES ('202203151319', '赵六', '女', 20, 0, 'D004', '123456', 'CL004',0);
INSERT INTO "public"."student_students230128" VALUES ('202203151320', '孙七', '男', 19, 0, 'D001', '123456', 'CL003', 0);
INSERT INTO "public"."student_students230128" VALUES ('202203151324', '张三二', '女', 24, 0, 'D003', '123456', 'CL101', 0);
INSERT INTO "public"."student_students230128" VALUES ('202203151322', '李四二', '男', 20, 0, 'D003', '123456', 'CL102', 0);
INSERT INTO "public"."student_students230128" VALUES ('202203151323', '王五二', '女', 22, 0, 'D005', '123456', 'CL103', 0);
INSERT INTO "public"."student_students230128" VALUES ('202203151315', '赵六二', '男', 23, 0, 'D004', '123456', 'CL104', 0);
INSERT INTO "public"."student_students230128" VALUES ('202203151325', '孙七二', '女', 22, 0, 'D002', '123456', 'CL105', 0);
INSERT INTO "public"."student_students230128" VALUES ('202203151327', '张学油', '男', 22, 0, 'D004', '123456', 'CL007', 0);
INSERT INTO "public"."student_students230128" VALUES ('202203151326', '周杰瑞', '男', 23, 0, 'D005', '123456', 'CL106', 0);
INSERT INTO "public"."student_students230128" VALUES ('202203151328', '林俊姐', '女', 22, 0, 'D003', '123456', 'CL107', 0);
INSERT INTO "public"."student_students230128" VALUES ('202203151330', '蔡某某', '男', 20, 0, 'D001', '123456', 'CL001', 0);
INSERT INTO "public"."student_students230128" VALUES ('202203151316', '张三', '男', 20, 0, 'D001', '123456', 'CL001', 0);
INSERT INTO "public"."student_students230128" VALUES ('202203151329', '瑞瑞', '男', 22, 0, 'D005', '123456', 'CL001', 0);





-- ----------------------------
-- Table structure for student_sc230128
-- ----------------------------
DROP TABLE IF EXISTS "public"."student_sc230128";
CREATE TABLE "public"."student_sc230128" (
  "sno230128" varchar(255) NOT NULL,
  "cno230128" varchar(255) NOT NULL,
  "clno230128" varchar(255) NOT NULL,
  "scyear230128" varchar(255),
  "scscore230128" int4,
  PRIMARY KEY ("sno230128", "cno230128", "clno230128"),
  FOREIGN KEY ("sno230128") REFERENCES "public"."student_students230128" ("sno230128"),
  FOREIGN KEY ("cno230128") REFERENCES "public"."student_courses230128" ("cno230128"),
  FOREIGN KEY ("clno230128") REFERENCES "public"."student_classes230128" ("clno230128")
);

INSERT INTO "public"."student_sc230128" VALUES ('202203151304', 'CO002', 'CL002', '2023-2024', 92);
INSERT INTO "public"."student_sc230128" VALUES ('202203151318', 'CO003', 'CL003', '2023-2024', 78);
INSERT INTO "public"."student_sc230128" VALUES ('202203151319', 'CO004', 'CL004', '2023-2024', 88);
INSERT INTO "public"."student_sc230128" VALUES ('202203151320', 'CO005', 'CL005', '2023-2024', 65);
INSERT INTO "public"."student_sc230128" VALUES ('202203151324', 'CO101', 'CL101', '2022-2023', 86);
INSERT INTO "public"."student_sc230128" VALUES ('202203151322', 'CO102', 'CL102', '2022-2023', 98);
INSERT INTO "public"."student_sc230128" VALUES ('202203151323', 'CO103', 'CL103', '2022-2023', 78);
INSERT INTO "public"."student_sc230128" VALUES ('202203151315', 'CO104', 'CL104', '2022-2023', 84);
INSERT INTO "public"."student_sc230128" VALUES ('202203151325', 'CO105', 'CL105', '2022-2023', 86);
INSERT INTO "public"."student_sc230128" VALUES ('202203151327', 'CO007', 'CL007', '2023-2024', 86);
INSERT INTO "public"."student_sc230128" VALUES ('202203151326', 'CO106', 'CL106', '2023-2024', 78);
INSERT INTO "public"."student_sc230128" VALUES ('202203151328', 'CO107', 'CL107', '2022-2023', 96);
INSERT INTO "public"."student_sc230128" VALUES ('202203151329', 'CO001', 'CL001', '2023-2024', 89);
INSERT INTO "public"."student_sc230128" VALUES ('202203151316', 'CO001', 'CL001', '2023-2024', 95);
INSERT INTO "public"."student_sc230128" VALUES ('202203151329', 'CO006', 'CL001', '2023-2024', 50);
-- 更新每个学生的绩点和总学分
WITH student_gpa_calculation AS (
    SELECT
        sc.Sno230128,
        SUM(c.Ccredit230128) AS total_credits,
        SUM(c.Ccredit230128 * 
            (CASE WHEN sc.SCscore230128 >= 60 
                  THEN ((sc.SCscore230128 - 50) / 10) 
                  ELSE 0 END)
        ) AS total_grade_points
    FROM
        student_Sc230128 sc
    JOIN
        student_Courses230128 c ON sc.Cno230128 = c.Cno230128
    GROUP BY
        sc.Sno230128
)
UPDATE student_Students230128 s
SET Sscore230128 = CASE 
                           WHEN sg.total_credits > 0 
                           THEN ROUND(sg.total_grade_points / sg.total_credits , 2)
                           ELSE 0 
                        END,
    Scredits230128 = sg.total_credits
FROM student_gpa_calculation sg
WHERE s.Sno230128 = sg.Sno230128;



-- ----------------------------
-- Table structure for student_teachers230128
-- ----------------------------
DROP TABLE IF EXISTS "public"."student_teachers230128";
CREATE TABLE "public"."student_teachers230128" (
  "tno230128" varchar(255) NOT NULL,
  "tname230128" varchar(255),
  "tsex230128" varchar(255),
  "tage230128" int4,
  "tphone230128" varchar(255),
  "tprof230128" varchar(255),
  "tpassword230128" varchar(255),
  PRIMARY KEY ("tno230128")
);


INSERT INTO "public"."student_teachers230128" VALUES ('T001', '教师1', '女', 35, '1234567890', '教授', '123456');
INSERT INTO "public"."student_teachers230128" VALUES ('T002', '教师2', '男', 40, '0987654324', '副教授', '123456');
INSERT INTO "public"."student_teachers230128" VALUES ('T003', '教师3', '女', 32, '9876543240', '助理教授', '123456');
INSERT INTO "public"."student_teachers230128" VALUES ('T004', '教师4', '男', 38, '0123456789', '讲师', '123456');
INSERT INTO "public"."student_teachers230128" VALUES ('T005', '教师5', '女', 42, '9876543240', '教授', '123456');
INSERT INTO "public"."student_teachers230128" VALUES ('T006', '教师6', '女', 46, '6456566544', '教授', '123456');
INSERT INTO "public"."student_teachers230128" VALUES ('T007', '教师7', '男', 39, '4546564564', '讲师', '123456');
INSERT INTO "public"."student_teachers230128" VALUES ('T008', '教师8', '男', 45, '8948894894', '副教授', '123456');
INSERT INTO "public"."student_teachers230128" VALUES ('T009', '教师9', '女', 48, '5564566455', '教授', '123456');
INSERT INTO "public"."student_teachers230128" VALUES ('T010', '教师10', '女', 52, '4844545646', '副教授', '123456');
INSERT INTO "public"."student_teachers230128" VALUES ('T011', '教师11', '男', 47, '8887555746', '教授', '123456');
INSERT INTO "public"."student_teachers230128" VALUES ('T012', '教师12', '女', 40, '7545488897', '助理教授', '123456');
INSERT INTO "public"."student_teachers230128" VALUES ('T013', '教师13', '男', 45, '3548948956', '副教授', '123456');
INSERT INTO "public"."student_teachers230128" VALUES ('T014', '教师14', '女', 46, '5798798978', '讲师', '123456');

-- ----------------------------
-- Table structure for student_tc230128
-- ----------------------------
DROP TABLE IF EXISTS "public"."student_tc230128";
CREATE TABLE "public"."student_tc230128" (
  "tno230128" varchar(255) NOT NULL,
  "cno230128" varchar(255) NOT NULL,
  "clno230128" varchar(255) NOT NULL,
  "tcyear230128" varchar(255),
  PRIMARY KEY ("tno230128", "cno230128", "clno230128"),
  FOREIGN KEY ("tno230128") REFERENCES "public"."student_teachers230128" ("tno230128"),
  FOREIGN KEY ("cno230128") REFERENCES "public"."student_courses230128" ("cno230128"),
  FOREIGN KEY ("clno230128") REFERENCES "public"."student_classes230128" ("clno230128")
);
INSERT INTO "public"."student_tc230128" VALUES ('T001', 'CO001', 'CL001', '2023-2024');
INSERT INTO "public"."student_tc230128" VALUES ('T002', 'CO002', 'CL002', '2023-2024');
INSERT INTO "public"."student_tc230128" VALUES ('T003', 'CO003', 'CL003', '2023-2024');
INSERT INTO "public"."student_tc230128" VALUES ('T004', 'CO004', 'CL004', '2023-2024');
INSERT INTO "public"."student_tc230128" VALUES ('T005', 'CO005', 'CL005', '2023-2024');
INSERT INTO "public"."student_tc230128" VALUES ('T006', 'CO101', 'CL101', '2022-2023');
INSERT INTO "public"."student_tc230128" VALUES ('T007', 'CO102', 'CL102', '2022-2023');
INSERT INTO "public"."student_tc230128" VALUES ('T008', 'CO103', 'CL103', '2022-2023');
INSERT INTO "public"."student_tc230128" VALUES ('T009', 'CO104', 'CL104', '2022-2023');
INSERT INTO "public"."student_tc230128" VALUES ('T010', 'CO105', 'CL105', '2022-2023');
INSERT INTO "public"."student_tc230128" VALUES ('T011', 'CO106', 'CL106', '2023-2024');
INSERT INTO "public"."student_tc230128" VALUES ('T012', 'CO007', 'CL007', '2023-2024');
INSERT INTO "public"."student_tc230128" VALUES ('T013', 'CO107', 'CL107', '2022-2023');
INSERT INTO "public"."student_tc230128" VALUES ('T014', 'CO108', 'CL108', '2022-2023');
INSERT INTO "public"."student_tc230128" VALUES ('T001', 'CO006', 'CL001', '2023-2024');


-- ----------------------------
-- Function structure for check_course_data
-- ----------------------------
DROP FUNCTION IF EXISTS "public"."check_course_data"();
CREATE OR REPLACE FUNCTION "public"."check_course_data"()
  RETURNS "pg_catalog"."trigger" AS $BODY$
BEGIN
    IF NEW.Ccredit230128 <= 0 OR NEW.Cperiod230128 <= 0 THEN
        RAISE EXCEPTION 'Invalid course data: Ccredit230128=%, Cperiod230128=%',
            NEW.Ccredit230128, NEW.Cperiod230128;
    END IF;
    
    RETURN NEW;
END;
$BODY$
  LANGUAGE plpgsql VOLATILE
  COST 100;
	
	-- ----------------------------
-- Triggers structure for table student_courses230128
-- 检查课程学分和课程学时的合法性
-- ----------------------------
CREATE TRIGGER "trigger_check_course_data" BEFORE INSERT OR UPDATE ON "public"."student_courses230128"
FOR EACH ROW
EXECUTE PROCEDURE "public"."check_course_data"();

	
	

-- ----------------------------
-- Function structure for check_student_age
-- ----------------------------
DROP FUNCTION IF EXISTS "public"."check_student_age"();
CREATE OR REPLACE FUNCTION "public"."check_student_age"()
  RETURNS "pg_catalog"."trigger" AS $BODY$
DECLARE
    student_age INTEGER;
BEGIN
    student_age := CAST(NEW.Sage230128 AS INTEGER);

    IF student_age <= 0 OR student_age > 100 OR student_age <> NEW.Sage230128 THEN
        RAISE EXCEPTION '年龄输入不正确: %', NEW.Sage230128;
    END IF;
    
    RETURN NEW;
END;
$BODY$
  LANGUAGE plpgsql VOLATILE
  COST 100;

-- ----------------------------
-- Triggers structure for table student_students230128
-- 确保学生的年龄修改或插入正确
-- ----------------------------
CREATE TRIGGER "validate_student_age" BEFORE INSERT OR UPDATE ON "public"."student_students230128"
FOR EACH ROW
EXECUTE PROCEDURE "public"."check_student_age"();

-- ----------------------------
-- Function structure for check_student_sex
-- ----------------------------
DROP FUNCTION IF EXISTS "public"."check_student_sex"();
CREATE OR REPLACE FUNCTION "public"."check_student_sex"()
  RETURNS "pg_catalog"."trigger" AS $BODY$
DECLARE
    student_sex VARCHAR(255);
BEGIN
    student_sex := CAST(NEW.Ssex230128 AS VARCHAR(255));

    IF student_sex != '男' AND student_sex !='女'  THEN
        RAISE EXCEPTION '性别输入不正确: %', NEW.Ssex230128;
    END IF;
    
    RETURN OLD;
END;
$BODY$
  LANGUAGE plpgsql VOLATILE
  COST 100;

-- ----------------------------
-- Triggers structure for table student_students230128
-- 确保学生的性别修改或插入正确
-- ----------------------------
CREATE TRIGGER "validate_student_sex" BEFORE INSERT OR UPDATE ON "public"."student_students230128"
FOR EACH ROW
EXECUTE PROCEDURE "public"."check_student_sex"();



-- ----------------------------
-- Function structure for update_student_gpa
-- ----------------------------
DROP FUNCTION IF EXISTS "public"."update_student_gpa"();
CREATE OR REPLACE FUNCTION "public"."update_student_gpa"()
  RETURNS "pg_catalog"."trigger" AS $BODY$
DECLARE
    total_credits DOUBLE PRECISION;
    total_grade_points DOUBLE PRECISION;
    student_GPA DOUBLE PRECISION;
BEGIN
    -- 计算总学分和总绩点
    SELECT
        SUM(c.Ccredit230128),
        SUM(c.Ccredit230128 * (CASE WHEN sc.SCscore230128 >= 60 THEN ((sc.SCscore230128 - 50) / 10) ELSE 0 END))
    INTO
        total_credits,
        total_grade_points
    FROM
        student_Sc230128 sc
        JOIN student_Courses230128 c ON sc.Cno230128 = c.Cno230128
    WHERE
        sc.Sno230128 = NEW.Sno230128;

    -- 计算学生绩点
    IF total_credits > 0 THEN
        student_GPA := total_grade_points / total_credits;
    ELSE
        student_GPA := 0;
    END IF;

    -- 更新学生绩点和总学分
    UPDATE student_Students230128
    SET Sscore230128 = student_GPA,
        Scredits230128 = total_credits
    WHERE Sno230128 = NEW.Sno230128;

    RETURN NEW;
END;
$BODY$
  LANGUAGE plpgsql VOLATILE
  COST 100;

-- 创建触发器，插入或更新 student_Sc230128 表时调用 update_student_gpa 函数
CREATE TRIGGER "update_gpa_trigger"
AFTER INSERT OR UPDATE OR DELETE ON student_Sc230128
FOR EACH ROW
EXECUTE PROCEDURE "public"."update_student_gpa"();




 
-- INSERT INTO "public"."student_sc230128" VALUES ('202203151304', 'CO006', 'CL001', '2023-2024', 92);

-- ----------------------------
-- Function structure for validate_student_score
-- ----------------------------
DROP FUNCTION IF EXISTS "public"."validate_student_score"();
CREATE OR REPLACE FUNCTION "public"."validate_student_score"()
  RETURNS "pg_catalog"."trigger" AS $BODY$
BEGIN
    IF NEW.SCscore230128 < 0 OR NEW.SCscore230128 > 100 THEN
        RAISE EXCEPTION '成绩输入有误！成绩必须在0-100之间！';
    END IF;
    
    RETURN NEW;
END;
$BODY$
  LANGUAGE plpgsql VOLATILE
  COST 100;
	
	-- ----------------------------
-- Triggers structure for table student_sc230128
-- 确保分数处于[0,100]内
-- ----------------------------
CREATE TRIGGER "check_student_score" 
BEFORE INSERT OR UPDATE ON "public"."student_sc230128"
FOR EACH ROW
EXECUTE PROCEDURE "public"."validate_student_score"();

	
	

-- ----------------------------
-- Function structure for student_select_courses_score_distribution230128
-- 传入参数：课程名和年份
-- 返回：各个分数和各个分数的学生数量
-- ----------------------------
-- DROP FUNCTION IF EXISTS "public"."student_select_courses_score_distribution230128"("cname" varchar, "year" varchar);
-- CREATE OR REPLACE FUNCTION "public"."student_select_courses_score_distribution230128"("cname" varchar, "year" varchar)
--   RETURNS TABLE("score" int, "num" bigint) AS $BODY$
-- DECLARE
--     sd RECORD;
-- BEGIN
--     FOR sd IN
--         SELECT
--             sc.SCscore230128,
--             COUNT(*) AS num_students
--         FROM
--             student_Sc230128 AS sc
--         JOIN
--             student_Courses230128 AS Courses ON sc.Cno230128 = Courses.Cno230128
--         WHERE
--             Courses.Cname230128 = Cname
--             AND sc.SCyear230128 = year
--         GROUP BY
--             sc.SCscore230128
--     LOOP
--         -- Assign the values to the result columns
--         score := sd.SCscore230128;
--         num := sd.num_students;
--         
--         -- Return the current row
--         RETURN NEXT;
--     END LOOP;
--     
--     -- End of function
--     RETURN;
-- END;
-- $BODY$
-- LANGUAGE plpgsql VOLATILE
-- COST 100
-- ROWS 1000;
-- 
-- SELECT * FROM student_select_courses_score_distribution230128('数据库原理', '2023-2024');


DROP FUNCTION IF EXISTS "public"."student_select_courses_score_distribution230128"("cname" varchar, "year" varchar);
CREATE OR REPLACE FUNCTION "public"."student_select_courses_score_distribution230128"("cname" varchar, "year" varchar)
  RETURNS TABLE("num" varchar) AS $BODY$
DECLARE
    sd RECORD;
BEGIN
    FOR sd IN
        SELECT
            COUNT(*) AS num
        FROM
            student_Sc230128 AS sc
        JOIN
            student_Courses230128 AS Courses ON sc.Cno230128 = Courses.Cno230128
        WHERE
            Courses.Cname230128 = Cname
            AND sc.SCyear230128 = year
        GROUP BY
            sc.SCscore230128
    LOOP
        num := sd.num;
        
        RETURN NEXT;
    END LOOP;
    
    RETURN;
END;
$BODY$
LANGUAGE plpgsql VOLATILE
COST 100
ROWS 1000;


-- ----------------------------
-- Function structure for student_select_courses_score_to_upload230128
-- 传入参数：课程名、班级名和年份 （查某课程某班级某学年的所有学生信息）
-- 返回：课程号、课程名、学生成绩、学生学号、学生姓名、班级号、班级名和成绩年份
-- ----------------------------
DROP FUNCTION IF EXISTS "public"."student_select_courses_score_to_upload230128"("cname" varchar, "clname" varchar, "year" varchar);
CREATE OR REPLACE FUNCTION "public"."student_select_courses_score_to_upload230128"("cname" varchar, "clname" varchar, "year" varchar)
  RETURNS TABLE("cno230128" varchar, "cname230128" varchar, "scscore230128" int4, "sno230128" varchar, "sname230128" varchar, "clno230128" varchar, "clname230128" varchar, "scyear230128" varchar) AS $BODY$
DECLARE
    ss RECORD;
BEGIN
    FOR ss IN
        SELECT DISTINCT
            Courses.Cno230128,
            Courses.Cname230128,
            sc.SCscore230128,
            sc.Sno230128,
            students.Sname230128,
            Classes.clno230128,
            Classes.clname230128,
            sc.SCyear230128
        FROM
            student_Sc230128 AS sc
        JOIN
            student_Courses230128 AS Courses ON sc.Cno230128 = Courses.Cno230128
        JOIN
            student_classes230128 AS Classes ON sc.clno230128 = Classes.clno230128
        JOIN
            student_Students230128 AS students ON sc.Sno230128 = students.Sno230128
        WHERE
            Courses.Cname230128 = Cname
            AND Classes.clname230128 = Clname
            AND sc.SCyear230128 = year
    LOOP
        Cno230128 := ss.Cno230128;
        Cname230128 := ss.Cname230128;
        SCscore230128 := ss.SCscore230128;
        Sno230128 := ss.Sno230128;
        Sname230128 := ss.Sname230128;
        clno230128 := ss.clno230128;
        clname230128 := ss.clname230128;
        SCyear230128 := ss.SCyear230128;
        
        RETURN NEXT;
    END LOOP;
	
    RETURN;
END;
$BODY$
  LANGUAGE plpgsql VOLATILE
  COST 100
  ROWS 1000;

-- SELECT * FROM student_select_courses_score_to_upload230128('数据库原理', '计科2403班','2023-2024');

-- ----------------------------
-- Function structure for student_select_place_by_classes230128
-- 输入参数：班级名称（查某班级所有学生信息）
-- 返回：学生编号、学生姓名、学生性别、学生绩点、班级编号和班级名称
-- ----------------------------
DROP FUNCTION IF EXISTS "public"."student_select_place_by_classes230128"("clname" varchar);
CREATE OR REPLACE FUNCTION "public"."student_select_place_by_classes230128"("clname" varchar)
  RETURNS TABLE("sno230128" varchar, "sname230128" varchar, "ssex230128" varchar, "sscore230128" float8, "clno230128" varchar, "clname230128" varchar) AS $BODY$
BEGIN
    RETURN QUERY
    SELECT DISTINCT
        sc.Sno230128,
        students.Sname230128,
        students.Ssex230128,
        students.Sscore230128,
        sc.clno230128,
        Classes.clname230128
    FROM
        student_Sc230128 AS sc
    JOIN
        student_Students230128 AS students ON sc.Sno230128 = students.Sno230128
    JOIN
        student_classes230128 AS Classes ON sc.clno230128 = Classes.clno230128
    WHERE
        Classes.clname230128 = Clname
    ORDER BY
        students.Sscore230128 DESC;
    RETURN;
END;
$BODY$
  LANGUAGE plpgsql VOLATILE
  COST 100
  ROWS 1000;

-- SELECT * FROM student_select_place_by_classes230128('计科2403班');


-- ----------------------------
-- Function structure for student_select_place_by_courses230128
-- 传入参数：课程名称和年份 （查某课程某学年的所有学生信息）
-- 返回结果：课程编号、课程名称、学生分数、学生编号、学生姓名、班级编号、班级名称、选课年份
-- ----------------------------
DROP FUNCTION IF EXISTS "public"."student_select_place_by_courses230128"("cname" varchar, "year" varchar);
CREATE OR REPLACE FUNCTION "public"."student_select_place_by_courses230128"("cname" varchar, "year" varchar)
  RETURNS TABLE("cno230128" varchar, "cname230128" varchar, "scscore230128" int4, "sno230128" varchar, "sname230128" varchar, "clno230128" varchar, "clname230128" varchar, "scyear230128" varchar) AS $BODY$
BEGIN
    RETURN QUERY
    SELECT DISTINCT
        Courses.Cno230128,
        Courses.Cname230128,
        sc.SCscore230128,
        sc.Sno230128,
        students.Sname230128,
        Classes.clno230128,
        Classes.clname230128,
        sc.SCyear230128
    FROM
        student_Sc230128 AS sc
    JOIN
        student_Courses230128 AS Courses ON sc.Cno230128 = Courses.Cno230128
    JOIN
        student_Students230128 AS students ON sc.Sno230128 = students.Sno230128
    JOIN
        student_classes230128 AS Classes ON sc.clno230128 = Classes.clno230128
    WHERE
        Courses.Cname230128 = Cname
        AND sc.SCyear230128 = year
    ORDER BY
        sc.SCscore230128 DESC;

    RETURN;
END;
$BODY$
  LANGUAGE plpgsql VOLATILE
  COST 100
  ROWS 1000;

-- SELECT * FROM student_select_place_by_courses230128('数据库原理', '2023-2024');


-- ----------------------------
-- Function structure for student_select_place_by_majors230128
-- 传入参数：专业名称（查某专业的所有学生信息）
-- 返回结果：学生编号、学生姓名、学生性别、学生分数、班级编号、班级名称、专业编号、专业名称
-- ----------------------------
DROP FUNCTION IF EXISTS "public"."student_select_place_by_majors230128"("mname" varchar);
CREATE OR REPLACE FUNCTION "public"."student_select_place_by_majors230128"("mname" varchar)
  RETURNS TABLE("sno230128" varchar, "sname230128" varchar, "ssex230128" varchar, "sscore230128" float8, "clno230128" varchar, "clname230128" varchar, "mno230128" varchar, "mname230128" varchar) AS $BODY$
BEGIN
    RETURN QUERY
    SELECT DISTINCT
        students.Sno230128,
        students.Sname230128,
        students.Ssex230128,
        students.Sscore230128,
        Classes.clno230128,
        Classes.clname230128,
        majors.mno230128,
        majors.Mname230128
    FROM
        student_Students230128 AS students
    JOIN
        student_classes230128 AS Classes ON students.clno230128 = Classes.clno230128
    JOIN
        student_Majors230128 AS majors ON Classes.mno230128 = majors.mno230128
    WHERE
        majors.Mname230128 = Mname
    ORDER BY
        students.Sscore230128 DESC;

    RETURN;
END;
$BODY$
  LANGUAGE plpgsql VOLATILE
  COST 100
  ROWS 1000;
	
-- SELECT * FROM student_select_place_by_majors230128('计科22级');



-- ----------------------------
-- Function structure for student_select_students_allscores230128
-- 传入参数：学号（查所有学年的成绩）
-- 返回：课程编号、班级名称、学生成绩、成绩年份、课程名称、课程学分、考查方式、课程学期、课程学时
-- ----------------------------
DROP FUNCTION IF EXISTS "public"."student_select_students_allscores230128"("sno" varchar);
CREATE OR REPLACE FUNCTION "public"."student_select_students_allscores230128"("sno" varchar)
  RETURNS TABLE("cno230128" varchar, "clname230128" varchar, "scscore230128" int4, "scyear230128" varchar, "cname230128" varchar, "ccredit230128" int4, "cevaluation230128" varchar, "cterm230128" varchar, "cperiod230128" varchar) AS $BODY$
DECLARE
    sg RECORD;
BEGIN
    FOR sg IN
        SELECT DISTINCT
            sc.Cno230128,
            Classes.clname230128,
            sc.SCscore230128,
            sc.SCyear230128,
            Courses.Cname230128,
            Courses.Ccredit230128,
            Courses.Cevaluation230128,
            Courses.Cterm230128,
            Courses.Cperiod230128
        FROM
            student_Sc230128 AS sc
        JOIN
            student_Courses230128 AS Courses ON sc.Cno230128 = Courses.Cno230128
        JOIN
            student_classes230128 AS Classes ON sc.clno230128 = Classes.clno230128
        WHERE
            sc.Sno230128 = Sno
    LOOP
        Cno230128 := sg.Cno230128;
        clname230128 := sg.clname230128;
        SCscore230128 := sg.SCscore230128;
        SCyear230128 := sg.SCyear230128;
        Cname230128 := sg.Cname230128;
        Ccredit230128 := sg.Ccredit230128;
        Cevaluation230128 := sg.Cevaluation230128;
        Cterm230128 := sg.Cterm230128;
        Cperiod230128 := sg.Cperiod230128;
        
        RETURN NEXT;
    END LOOP;
    
    RETURN;
END;
$BODY$
  LANGUAGE plpgsql VOLATILE
  COST 100
  ROWS 1000;

-- SELECT * FROM student_select_students_allscores230128('202203151329');


-- ----------------------------
-- Function structure for student_select_students_courses_and_credits230128
-- 传入参数：学号 (查所有学年的课表)
-- 返回：课程编号、班级名称、课程名称、课程学分、课程考察方式、成绩年份、课程学期、课程学时
-- ----------------------------
DROP FUNCTION IF EXISTS "public"."student_select_students_courses_and_credits230128"("sno" varchar);
CREATE OR REPLACE FUNCTION "public"."student_select_students_courses_and_credits230128"("sno" varchar)
  RETURNS TABLE("cno230128" varchar, "clname230128" varchar, "cname230128" varchar, "ccredit230128" float8, "cevaluation230128" varchar, "scyear230128" varchar, "cterm230128" varchar, "cperiod230128" int4) AS $BODY$
DECLARE
    sc RECORD;
BEGIN
    FOR sc IN
        SELECT DISTINCT
            sc.Cno230128,
            Classes.clname230128,
            Courses.Cname230128,
            Courses.Ccredit230128,
            Courses.Cevaluation230128,
            sc.SCyear230128,
            Courses.Cterm230128,
            Courses.Cperiod230128
        FROM
            student_Sc230128 AS sc
        JOIN
            student_Courses230128 AS Courses ON sc.Cno230128 = Courses.Cno230128
        JOIN
            student_classes230128 AS Classes ON sc.clno230128 = Classes.clno230128
        WHERE
            sc.Sno230128 = Sno
    LOOP
        Cno230128 := sc.Cno230128;
        clname230128 := sc.clname230128;
        Cname230128 := sc.Cname230128;
        Ccredit230128 := sc.Ccredit230128;
        Cevaluation230128 := sc.Cevaluation230128;
        SCyear230128 := sc.SCyear230128;
        Cterm230128 := sc.Cterm230128;
        Cperiod230128 := sc.Cperiod230128;
        
        RETURN NEXT;
    END LOOP;
    
    RETURN;
END;
$BODY$
  LANGUAGE plpgsql VOLATILE
  COST 100
  ROWS 1000;

-- SELECT * FROM student_select_students_courses_and_credits230128('202203151329');


-- ----------------------------
-- Function structure for student_select_students_courses_and_credits_by_year230128
-- 传入参数：学号、年份	(查某学年的课表)
-- 返回: 课程编号、班级名称、课程名称、课程学分、课程考查方式、成绩年份、课程学期、课程学时
-- ----------------------------
DROP FUNCTION IF EXISTS "public"."student_select_students_courses_and_credits_by_year230128"("sno" varchar, "year" varchar);
CREATE OR REPLACE FUNCTION "public"."student_select_students_courses_and_credits_by_year230128"("sno" varchar, "year" varchar)
  RETURNS TABLE("cno230128" varchar, "clname230128" varchar, "cname230128" varchar, "ccredit230128" float8, "cevaluation230128" varchar, "scyear230128" varchar, "cterm230128" varchar, "cperiod230128" int4) AS $BODY$
DECLARE
    sc RECORD;
BEGIN
    FOR sc IN
        SELECT DISTINCT
            sc.Cno230128,
            Classes.clname230128,
            Courses.Cname230128,
            Courses.Ccredit230128,
            Courses.Cevaluation230128,
            sc.SCyear230128,
            Courses.Cterm230128,
            Courses.Cperiod230128
        FROM
            student_Sc230128 AS sc
        JOIN
            student_Courses230128 AS Courses ON sc.Cno230128 = Courses.Cno230128
        JOIN
            student_classes230128 AS Classes ON sc.clno230128 = Classes.clno230128
        WHERE
            sc.Sno230128 = Sno AND sc.SCyear230128 = year
    LOOP
        Cno230128 := sc.Cno230128;
        clname230128 := sc.clname230128;
        Cname230128 := sc.Cname230128;
        Ccredit230128 := sc.Ccredit230128;
        Cevaluation230128 := sc.Cevaluation230128;
        SCyear230128 := sc.SCyear230128;
        Cterm230128 := sc.Cterm230128;
        Cperiod230128 := sc.Cperiod230128;
        
        RETURN NEXT;
    END LOOP;
    
    RETURN;
END;
$BODY$
  LANGUAGE plpgsql VOLATILE
  COST 100
  ROWS 1000;
	
-- SELECT * FROM student_select_students_courses_and_credits_by_year230128('202203151329', '2023-2024');

-- ---------------------------
-- Function structure for student_select_students_scores230128
-- 传入参数：学生学号和年份（查某学年的所有成绩）
-- 返回：课程编号、课程名称、成绩、学年、学分、考查方式、学期和学时
-- ----------------------------
DROP FUNCTION IF EXISTS "public"."student_select_students_scores230128"("sno" varchar, "year" varchar);
CREATE OR REPLACE FUNCTION "public"."student_select_students_scores230128"("sno" varchar, "year" varchar)
  RETURNS TABLE("cno230128" varchar, "clname230128" varchar, "scscore230128" int4, "scyear230128" varchar, "cname230128" varchar, "ccredit230128" int4, "cevaluation230128" varchar, "cterm230128" varchar, "cperiod230128" varchar) AS $BODY$
DECLARE
    sg RECORD;
BEGIN
    FOR sg IN
        SELECT DISTINCT
            sc.Cno230128,
            Classes.clname230128,
            sc.SCscore230128,
            sc.SCyear230128,
            Courses.Cname230128,
            Courses.Ccredit230128,
            Courses.Cevaluation230128,
            Courses.Cterm230128,
            Courses.Cperiod230128
        FROM
            student_Sc230128 AS sc
        JOIN
            student_Courses230128 AS Courses ON sc.Cno230128 = Courses.Cno230128
        JOIN
            student_classes230128 AS Classes ON sc.clno230128 = Classes.clno230128
        WHERE
            sc.Sno230128 = Sno AND sc.SCyear230128 = year
    LOOP
        Cno230128 := sg.Cno230128;
        clname230128 := sg.clname230128;
        SCscore230128 := sg.SCscore230128;
        SCyear230128 := sg.SCyear230128;
        Cname230128 := sg.Cname230128;
        Ccredit230128 := sg.Ccredit230128;
        Cevaluation230128 := sg.Cevaluation230128;
        Cterm230128 := sg.Cterm230128;
        Cperiod230128 := sg.Cperiod230128;
        
        RETURN NEXT;
    END LOOP;
    
    RETURN;
END;
$BODY$
  LANGUAGE plpgsql VOLATILE
  COST 100
  ROWS 1000;

-- SELECT * FROM student_select_students_scores230128('202203151329','2023-2024');

	
	

-- ----------------------------
-- Function structure for student_select_teachers_courses230128
-- 输入参数：教师姓名
-- 返回：授课信息：教师工号、教师姓名、课程号、班级号、学年、课程名称
-- ----------------------------
DROP FUNCTION IF EXISTS "public"."student_select_teachers_courses230128"("tname" varchar);
CREATE OR REPLACE FUNCTION "public"."student_select_teachers_courses230128"("tname" varchar)
  RETURNS TABLE("tno230128" varchar, "tname230128" varchar, "cno230128" varchar, "clname230128" varchar, "tcyear230128" varchar, "cname230128" varchar) AS $BODY$
DECLARE
    tc RECORD;
BEGIN
    FOR tc IN
        SELECT DISTINCT
            teachers.Tno230128,
            teachers.Tname230128,
            Courses.Cno230128,
            Classes.clname230128,
            tc.TCyear230128,
            Courses.Cname230128
        FROM
            student_Tc230128 AS tc
        JOIN
            student_Teachers230128 AS teachers ON tc.Tno230128 = teachers.Tno230128
        JOIN
            student_classes230128 AS Classes ON tc.clno230128 = Classes.clno230128
        JOIN
            student_Courses230128 AS Courses ON Classes.clno230128 = Courses.clno230128
        WHERE
            teachers.Tname230128 = Tname
    LOOP
        Tno230128 := tc.Tno230128;
        Tname230128 := tc.Tname230128;
        Cno230128 := tc.Cno230128;
        clname230128 := tc.clname230128;
        TCyear230128 := tc.TCyear230128;
        Cname230128 := tc.Cname230128;

        RETURN NEXT;
    END LOOP;

    RETURN;
END;
$BODY$
  LANGUAGE plpgsql VOLATILE
  COST 100
  ROWS 1000;
	
-- SELECT * FROM student_select_teachers_courses230128('教师1')

-- ----------------------------
-- Function structure for student_stulocation230128
-- 输入参数：省份编号，城市编号，区域编号，
-- 返回结果：学生编号、学生姓名、省份名称、城市名称、区域名称。
-- ----------------------------
DROP FUNCTION IF EXISTS "public"."student_stulocation230128"("pno" varchar, "cno" varchar, "dno" varchar);
CREATE OR REPLACE FUNCTION "public"."student_stulocation230128"("pno" varchar, "cno" varchar, "dno" varchar)
  RETURNS TABLE("sno230128" varchar, "sname230128" varchar, "pname230128" varchar, "ciname230128" varchar, "dname230128" varchar) AS $BODY$
BEGIN
    RETURN QUERY
    SELECT DISTINCT
        students.Sno230128,
        students.Sname230128,
        provinces.Pname230128,
        cities.ciname230128,
        Districts.Dname230128
    FROM
        student_Students230128 AS students
    JOIN
        student_classes230128 AS Classes ON students.clno230128 = Classes.clno230128
    JOIN
        student_District230128 AS Districts ON students.Slocation230128 = Districts.Dno230128
    JOIN
        student_city230128 AS cities ON Districts.cino230128 = cities.cino230128
    JOIN
        student_Province230128 AS provinces ON cities.pno230128 = provinces.pno230128
    WHERE
        provinces.pno230128 = Pno
        AND cities.cino230128 = Cno
        AND Districts.Dno230128 = Dno;

    RETURN;
END;
$BODY$
  LANGUAGE plpgsql VOLATILE
  COST 100
  ROWS 1000;
	
-- SELECT * FROM student_stulocation230128('P001', 'C001', 'D001');

	
----------------------------
-- View structure for student_classescourses230128
-- 创建一个包含课程编号、班级名称、课程名称、学分、考查方式、学年、学期和课时的视图
-- (所有班级所有学年的开课情况)
-- ----------------------------
DROP VIEW IF EXISTS "public"."student_classescourses230128";
CREATE VIEW "public"."student_classescourses230128" AS
SELECT DISTINCT c.cno230128, cl.clname230128, c.cname230128, c.ccredit230128, 
       c.cevaluation230128, sc.scyear230128, c.cterm230128, c.cperiod230128
FROM student_courses230128 c
JOIN student_classes230128 cl ON c.clno230128::text = cl.clno230128::text
JOIN student_sc230128 sc ON c.cno230128::text = sc.cno230128::text AND cl.clno230128::text = sc.clno230128::text;

-- SELECT * FROM student_classescourses230128;



-- ----------------------------
-- View structure for student_avgscorecount230128
-- 创建一个按课程名和开课学年的平均成绩
-- ----------------------------
DROP VIEW IF EXISTS "public"."student_avgscorecount230128";
CREATE VIEW "public"."student_avgscorecount230128" 
AS  SELECT DISTINCT
student_courses230128.cname230128, student_sc230128.scyear230128, 
    avg(student_sc230128.scscore230128) AS avgscore
   FROM student_courses230128
   JOIN student_sc230128 ON student_courses230128.cno230128::text = student_sc230128.cno230128::text
  GROUP BY student_courses230128.cname230128, student_sc230128.scyear230128;

-- SELECT * FROM student_avgscorecount230128




-- ----------------------------
-- Indexes structure for table student_classes230128
-- 在班级表 student_classes230128 表的班级名clname230128和班级号clno230128 上创建索引
-- ----------------------------
CREATE INDEX "classesidx_clname230128" ON "public"."student_classes230128" USING btree (
  "clname230128"  ASC NULLS LAST
);
CREATE INDEX "classesidx_clno230128" ON "public"."student_classes230128" USING btree (
  "clno230128"  ASC NULLS LAST
);

-- ----------------------------
-- Indexes structure for table student_courses230128
-- 在课程表 student_courses230128 的班课程号cno230128 上创建索引
-- ----------------------------
CREATE  INDEX "coursesidx_cno230128" ON "public"."student_courses230128" USING btree (
  "cno230128"  ASC NULLS LAST
);
CLUSTER student_Courses230128 USING Coursesidx_Cno230128;





-- ----------------------------
-- Checks structure for table student_courses230128
-- ----------------------------
-- ALTER TABLE "public"."student_courses230128" ADD CONSTRAINT "student_courses230128_ccredit230128_check" CHECK ((ccredit230128 >= (0)::double precision));

-- INSERT INTO "public"."student_courses230128" VALUES ('CO011', 'CL011', '计算机组成原理', -1, '考试', '2024春季', 48);



-- ----------------------------
-- Indexes structure for table student_sc230128
-- 第一条：在学生成绩表上单独对课程号建立索引
-- 第二条：在学生成绩表上对课程号和班级号一起建立索引	
-- ----------------------------
CREATE INDEX "scidx_cno230128" ON "public"."student_sc230128" USING btree (
  "cno230128"  ASC NULLS LAST
);
CREATE INDEX "scidx_cno_clno230128" ON "public"."student_sc230128" USING btree (
  "cno230128"  ASC NULLS LAST,
  "clno230128"  ASC NULLS LAST
);


CREATE INDEX "scidx_sno_cno_clno230128" ON "public"."student_sc230128" USING btree (
"sno230128"  ASC NULLS LAST,
  "cno230128"  ASC NULLS LAST,
  "clno230128"  ASC NULLS LAST
);
CLUSTER student_SC230128 USING SCidx_Sno_Cno_Clno230128;




-- -- ----------------------------
-- -- Checks structure for table student_sc230128
-- -- ----------------------------
-- ALTER TABLE "public"."student_sc230128" ADD CONSTRAINT "student_sc230128_scscore230128_check" CHECK ((scscore230128 >= 0));


-- ----------------------------
-- Indexes structure for table student_students230128
-- 为学生表的学号sno230128创建索引
-- ----------------------------
CREATE  INDEX "studentsidx_sno230128" ON "public"."student_students230128" USING btree (
  "sno230128"  ASC NULLS LAST
);

CLUSTER student_Students230128 USING Studentsidx_Sno230128;

-- ----------------------------
-- Checks structure for table student_students230128
-- ----------------------------
ALTER TABLE "public"."student_students230128" ADD CONSTRAINT "student_students230128_sscore230128_check" CHECK ((sscore230128 >= (0)::double precision));
ALTER TABLE "public"."student_students230128" ADD CONSTRAINT "student_students230128_scredits230128_check" CHECK ((scredits230128 >= (0)::double precision));
-- ALTER TABLE "public"."student_students230128" ADD CONSTRAINT "student_students230128_sage230128_check" CHECK ((sage230128 >= 0));




-- BEGIN;
-- UPDATE public.student_students230128
-- SET sname230128 = '测试名字'
-- WHERE sno230128 = '202203151304';
-- COMMIT;

-- -- 备份数据
-- CREATE TABLE public.student_students230128_backup AS
-- SELECT * FROM public.student_students230128;
-- 
-- -- 删除原表
-- DROP TABLE public.student_students230128;
-- 
-- -- 重新创建表
-- CREATE TABLE "public"."student_students230128" (
--   "sno230128" varchar(255) PRIMARY KEY,
--   "sname230128" varchar(255) ,
--   "ssex230128" varchar(255) ,
--   "sage230128" int4,
--   "scredits230128" float8,
--   "slocation230128" varchar(255) ,
--   "spassword230128" varchar(255) ,
--   "clno230128" varchar(255) ,
--   "sscore230128" float8
-- )
-- ;
-- 
-- -- 恢复数据
-- INSERT INTO public.student_students230128
-- SELECT * FROM public.student_students230128_backup;


----------------------------
-- Indexes structure for table student_tc230128
-- 在教师授课表上添加教师号、课程号、班级号的索引
-- ----------------------------
CREATE INDEX "tcidx_tno_cno_clno230128" ON "public"."student_tc230128" USING btree (
  "tno230128"  ASC NULLS LAST,
  "cno230128"  ASC NULLS LAST,
  "clno230128"  ASC NULLS LAST
);
CLUSTER student_TC230128 USING TCidx_Tno_Cno_Clno230128


-- ----------------------------
-- Indexes structure for table student_teachers230128
-- 在教师表上添加教师号的聚簇索引
-- ----------------------------
CREATE INDEX "teachersidx_tno" ON "public"."student_teachers230128" USING btree (
  "tno230128"  ASC NULLS LAST
);
CLUSTER student_Teachers230128 USING teachersidx_tno


-- ----------------------------
-- Indexes structure for table student_teachers230128
-- 在教师表上添加教师号、教师名的索引
-- ----------------------------
CREATE INDEX "teachersidx_tno_tname230128" ON "public"."student_teachers230128" USING btree (
  "tno230128"  ASC NULLS LAST,
  "tname230128"  ASC NULLS LAST
);

-- ----------------------------
-- Checks structure for table student_teachers230128
-- ----------------------------
ALTER TABLE "public"."student_teachers230128" ADD CONSTRAINT "student_teachers230128_tage230128_check" CHECK ((tage230128 >= 0));






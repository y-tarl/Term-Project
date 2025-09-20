package dao.AdminDao;

import dao.Dao;
import dao.DaoException;
import com.model.admin.*;

import java.util.ArrayList;

public interface AdminDao extends Dao {
    public boolean InsertMajors(String hjy_Mno230128, String hjy_Mname230128) throws DaoException;
    public boolean InsertClasses(String hjy_Clno230128, String hjy_Clname230128, String hjy_Mno230128) throws DaoException;
    public boolean InsertTeachers(String hjy_Tno230128, String hjy_Tname230128, String hjy_Tsex230128, int hjy_Tage230128
            , String hjy_Tphone230128, String hjy_Tprof230128, String hjy_Tpassword230128) throws DaoException;
    public boolean InsertStudents(String hjy_Sno230128, String  hjy_Sname230128, String hjy_Ssex230128, int hjy_Sage230128, double hjy_Scredits230128,
                                  String hjy_Slocation230128, String hjy_Spassword230128, String hjy_Clno230128, double hjy_Sscore230128) throws DaoException;
    public boolean InsertCourses(String hjy_Cno230128, String hjy_Clno230128, String hjy_Cname230128,
                                 double hjy_Ccredit230128, String hjy_Cevaluation230128, String hjy_Cterm230128, int hjy_Cperiod230128) throws DaoException;
    public boolean InsertSC(String hjy_Sno230128, String hjy_Cno230128, String hjy_Clno230128, String hjy_SCyear230128, int hjy_SCscore230128) throws DaoException;
    public boolean InsertTC(String hjy_Tno230128, String hjy_Cno230128, String hjy_Clno230128, String hjy_TCyear230128) throws DaoException;
    public boolean InsertProvince(String hjy_Pno230128, String hjy_Pname230128) throws DaoException;
    public boolean InsertCity(String hjy_Cino230128, String hjy_Ciname230128, String hjy_Pno230128) throws DaoException;
    public boolean InsertDistrict(String hjy_Dno230128, String hjy_Dname230128, String hjy_Cino230128) throws DaoException;



    public ArrayList<City> SelectCity() throws DaoException;
    public ArrayList<Classes> SelectClasses() throws DaoException;
    public ArrayList<Courses> SelectCourses() throws DaoException;
    public ArrayList<District> SelectDistrict() throws DaoException;
    public ArrayList<Majors> SelectMajors() throws DaoException;
    public ArrayList<Province> SelectProvince() throws DaoException;
    public ArrayList<SC> SelectSC() throws DaoException;
    public ArrayList<Students> SelectStudents() throws DaoException;
    public ArrayList<TC> SelectTC() throws DaoException;
    public ArrayList<Teachers> SelectTeachers() throws DaoException;

    public boolean DeleteCity(String hjy_Cino230128) throws DaoException;
    public boolean DeleteClasses(String hjy_Clno230128) throws DaoException;
    public boolean DeleteCourses(String hjy_Cno230128, String hjy_Clno230128) throws DaoException;
    public boolean DeleteDistrict(String hjy_Dno230128) throws DaoException;
    public boolean DeleteMajors(String hjy_Mno230128) throws DaoException;
    public boolean DeleteProvince(String hjy_Pno230128) throws DaoException;
    public boolean DeleteSC(String hjy_Sno230128, String hjy_Cno230128, String hjy_Clno230128, String hjy_SCyear230128) throws DaoException;
    public boolean DeleteStudents(String hjy_Sno230128) throws DaoException;
    public boolean DeleteTC(String hjy_Tno230128, String hjy_Cno230128, String hjy_Clno230128, String hjy_TCyear230128) throws DaoException;
    public boolean DeleteTeachers(String hjy_Tno230128) throws DaoException;


    public boolean UpdateCity(String hjy_Ciname230128 , String hjy_Pno230128,String hjy_Cino230128 ) throws DaoException;
    public boolean UpdateClasses(String hjy_Clname230128  , String hjy_Mno230128,String hjy_Clno230128 ) throws DaoException;
    public boolean UpdateCourses(String hjy_Cname230128 , double hjy_Ccredit230128 , String hjy_Cevaluation230128 , String hjy_Cterm230128 , int hjy_Cperiod230128 ,
                                 String hjy_Cno230128 , String hjy_Clno230128 ) throws DaoException;
    public boolean UpdateDistrict(String hjy_Dname230128 , String hjy_Cino230128, String hjy_Dno230128 ) throws DaoException;
    public boolean UpdateMajors(String hjy_Mname230128,String hjy_Mno230128 ) throws DaoException;
    public boolean UpdateProvince(String hjy_Pname230128,String hjy_Pno230128 ) throws DaoException;
    public boolean UpdateStudents(String hjy_Sname230128 , String hjy_Ssex230128 , int hjy_Sage230128 , double hjy_Scredits230128 , String hjy_Slocation230128 , String hjy_Spassword230128 , String hjy_Clno230128 , double hjy_Sscore230128,
                                  String hjy_Sno230128 ) throws DaoException;
    public boolean UpdateTeachers(String hjy_Tname230128  , String hjy_Tsex230128  , int hjy_Tage230128  , String hjy_Tphone230128 , String  hjy_Tprof230128 , String  hjy_Tpassword230128,
                                  String hjy_Tno230128 ) throws DaoException;

}



/*
* INSERT INTO Hejy_Majors230128 VALUES
(?,?)    hjy_Mno230128  hjy_Mname230128
INSERT INTO Hejy_classes230128 VALUES
(?,?,?)    hjy_Clno230128  hjy_Clname230128   hjy_Mno230128
INSERT INTO Hejy_Teachers230128 VALUES
(?,?,?,?,?,?,?)    hjy_Tno230128  hjy_Tname230128  hjy_Tsex230128  hjy_Tage230128  hjy_Tphone230128  hjy_Tprof230128  hjy_Tpassword230128
INSERT INTO Hejy_Students230128 VALUES
(?,?,?,?,?,?,?,?)  hjy_Sno230128    hjy_Sname230128  hjy_Ssex230128  hjy_Sage230128  hjy_Scredits230128  hjy_Slocation230128  hjy_Spassword230128  hjy_Clno230128  hjy_Sscore230128
INSERT INTO Hejy_Courses230128 VALUES
(?,?,?,?,?,?,?)    hjy_Cno230128  hjy_Clno230128  hjy_Cname230128            hjy_Ccredit230128  hjy_Cevaluation230128  hjy_Cterm230128  hjy_Cperiod230128
INSERT INTO Hejy_SC230128 VALUES
(?,?,?,?,?)      hjy_Sno230128    hjy_Cno230128  hjy_Clno230128  hjy_SCyear230128  hjy_SCscore230128
INSERT INTO Hejy_TC230128 VALUES
(?,?,?,?)       hjy_Tno230128  hjy_Cno230128  hjy_Clno230128  hjy_TCyear230128
INSERT INTO Hejy_Province230128 VALUES
(?,?)      hjy_Pno230128  hjy_Pname230128
INSERT INTO Hejy_City230128 VALUES
(?,?,?)    hjy_Cino230128  hjy_Ciname230128  hjy_Pno230128
INSERT INTO Hejy_District230128 VALUES
(?,?,?)     hjy_Dno230128  hjy_Dname230128  hjy_Cino230128

*  */
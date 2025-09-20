package dao.stuCourses;

import com.model.student.stuCourses;
import com.model.student.stuGrade;
import dao.DaoException;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

public class StuCoursesDaoImpl implements StuCoursesDao{
    public ArrayList<stuCourses> select_students_courses_and_credits(String Sno) throws DaoException
    {
        ArrayList<stuCourses> stuCoursesArrayList = new ArrayList<stuCourses>();
        String sql="CALL Hejy_select_students_courses_and_credits230128(?)";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, Sno);

            ResultSet rst = pstmt.executeQuery();
            while (rst.next())
            {
                stuCourses sc = new stuCourses();
                sc.setCno(rst.getString("hjy_Cno230128"));
                sc.setClname(rst.getString("hjy_Clname230128"));
                sc.setCname(rst.getString("hjy_Cname230128"));
                sc.setCcredit(rst.getDouble("hjy_Ccredit230128"));
                sc.setCevaluation(rst.getString("hjy_Cevaluation230128"));
                sc.setSCyear(rst.getString("hjy_SCyear230128"));
                sc.setCterm(rst.getString("hjy_Cterm230128"));
                sc.setCperiod(rst.getInt("hjy_Cperiod230128"));
                stuCoursesArrayList.add(sc);
            }
            conn.close();
            return stuCoursesArrayList;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return null;
        }
    }

    public ArrayList<stuCourses> select_students_courses_and_credits_by_year(String Sno,String year) throws DaoException
    {
        ArrayList<stuCourses> stuCoursesArrayList = new ArrayList<stuCourses>();
        String sql="CALL Hejy_select_students_courses_and_credits_by_year230128(?,?)";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, Sno);
            pstmt.setString(2, year);
            ResultSet rst = pstmt.executeQuery();
            while (rst.next())
            {
                stuCourses sc = new stuCourses();
                sc.setCno(rst.getString("hjy_Cno230128"));
                sc.setClname(rst.getString("hjy_Clname230128"));
                sc.setCname(rst.getString("hjy_Cname230128"));
                sc.setCcredit(rst.getDouble("hjy_Ccredit230128"));
                sc.setCevaluation(rst.getString("hjy_Cevaluation230128"));
                sc.setSCyear(rst.getString("hjy_SCyear230128"));
                sc.setCterm(rst.getString("hjy_Cterm230128"));
                sc.setCperiod(rst.getInt("hjy_Cperiod230128"));
                stuCoursesArrayList.add(sc);
            }
            conn.close();
            return stuCoursesArrayList;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return null;
        }
    }



    public ArrayList<stuCourses> select_students_courses_of_classes(String year,String Clname) throws DaoException
    {
        ArrayList<stuCourses> stuCoursesArrayList = new ArrayList<stuCourses>();
        String sql="SELECT * FROM Hejy_classesCourses230128 \n" +
                "WHERE hjy_SCyear230128 = ? AND hjy_Clname230128 = ?";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, year);
            pstmt.setString(2, Clname);

            ResultSet rst = pstmt.executeQuery();
            while (rst.next())
            {
                stuCourses sc = new stuCourses();
                sc.setCno(rst.getString("hjy_Cno230128"));
                sc.setClname(rst.getString("hjy_Clname230128"));
                sc.setCname(rst.getString("hjy_Cname230128"));
                sc.setCcredit(rst.getDouble("hjy_Ccredit230128"));
                sc.setCevaluation(rst.getString("hjy_Cevaluation230128"));
                sc.setSCyear(rst.getString("hjy_SCyear230128"));
                sc.setCterm(rst.getString("hjy_Cterm230128"));
                sc.setCperiod(rst.getInt("hjy_Cperiod230128"));
                stuCoursesArrayList.add(sc);
            }
            conn.close();
            return stuCoursesArrayList;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return null;
        }
    }

}

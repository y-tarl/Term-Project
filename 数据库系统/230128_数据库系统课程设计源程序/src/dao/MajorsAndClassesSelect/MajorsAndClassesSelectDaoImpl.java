package dao.MajorsAndClassesSelect;

import com.model.student.stuGrade;
import dao.DaoException;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

public class MajorsAndClassesSelectDaoImpl implements MajorsAndClassesSelectDao{
    public ArrayList<String> SelectMajors() throws DaoException
    {
        ArrayList<String> MajorsArrayList = new ArrayList<String>();
        String sql="SELECT hjy_Mname230128 FROM Hejy_Majors230128";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);

            ResultSet rst = pstmt.executeQuery();
            while (rst.next())
            {
                MajorsArrayList.add(rst.getString("hjy_Mname230128"));
            }
            conn.close();
            return MajorsArrayList;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return null;
        }

    }
    public ArrayList<String> SelectClasses(String major) throws DaoException
    {
        ArrayList<String> ClassesArrayList = new ArrayList<String>();
        String sql="SELECT hjy_Clname230128 \n" +
                "FROM Hejy_classes230128 Cl,Hejy_Majors230128 M\n" +
                "\tWHERE Cl.hjy_Mno230128 = M.hjy_Mno230128\n" +
                "\tAND M.hjy_Mname230128 = ?";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, major);

            ResultSet rst = pstmt.executeQuery();
            while (rst.next())
            {
                ClassesArrayList.add(rst.getString("hjy_Clname230128"));
            }
            conn.close();
            return ClassesArrayList;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return null;
        }
    }




    public ArrayList<String> SelectCourses() throws DaoException
    {
        ArrayList<String> CoursesArrayList = new ArrayList<String>();
        String sql="SELECT DISTINCT hjy_Cname230128 FROM Hejy_Courses230128";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);

            ResultSet rst = pstmt.executeQuery();
            while (rst.next())
            {
                CoursesArrayList.add(rst.getString("hjy_Cname230128"));
            }
            conn.close();
            return CoursesArrayList;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return null;
        }
    }
}

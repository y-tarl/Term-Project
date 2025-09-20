package dao.LogIn;

import com.model.student.stuGrade;
import com.model.student.stuInfo;
import com.model.teacher.TeaInfo;
import dao.DaoException;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

public class LogInDaoImple implements LogInDao{
    public stuInfo stuLogIn(String Sno, String Sname, String Spassword) throws DaoException
    {
        stuInfo si = null;
        String sql="SELECT S.hjy_Sno230128,S.hjy_Sname230128,Cl.hjy_Clname230128 \n" +
                " FROM Hejy_Students230128 S, Hejy_classes230128 Cl\n" +
                " WHERE  S.hjy_Clno230128 = Cl.hjy_Clno230128\n" +
                "\tAND S.hjy_Sno230128 = ? \n" +
                "\tAND S.hjy_Sname230128 = ? \n" +
                "\tAND S.hjy_Spassword230128 = ?";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, Sno);
            pstmt.setString(2, Sname);
            pstmt.setString(3, Spassword);
            ResultSet rst = pstmt.executeQuery();
            if (rst.next() == true)
            {
                si = new stuInfo();
                si.setSno(rst.getString("hjy_Sno230128"));
                si.setSname(rst.getString("hjy_Sname230128"));
                si.setClname(rst.getString("hjy_Clname230128"));
            }
            conn.close();
            return si;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return null;
        }
    }

    public ArrayList<String> stuYears() throws DaoException
    {
        ArrayList<String> stuYears = new ArrayList<String>();
        String sql="SELECT DISTINCT hjy_SCyear230128 FROM Hejy_SC230128";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            ResultSet rst = pstmt.executeQuery();
            while (rst.next())
            {
                String year = rst.getString("hjy_SCyear230128");
                stuYears.add(year);
            }
            conn.close();
            return stuYears;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return null;
        }
    }






    public TeaInfo teaLogIn(String Tno, String Tname, String Tpassword) throws DaoException
    {
        TeaInfo ti = null;
        String sql="SELECT hjy_Tno230128,hjy_Tname230128 FROM Hejy_Teachers230128\n" +
                " WHERE hjy_Tno230128 = ? \n" +
                "\tAND hjy_Tname230128 = ? \n" +
                "\tAND hjy_Tpassword230128 = ?";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, Tno);
            pstmt.setString(2, Tname);
            pstmt.setString(3, Tpassword);
            ResultSet rst = pstmt.executeQuery();
            if (rst.next() == true)
            {
                ti = new TeaInfo();
                ti.setTno(rst.getString("hjy_Tno230128"));
                ti.setTname(rst.getString("hjy_Tname230128"));
            }
            conn.close();
            return ti;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return null;
        }
    }

    public ArrayList<String> teaYears() throws DaoException
    {
        ArrayList<String> teaYears = new ArrayList<String>();
        String sql="SELECT DISTINCT hjy_TCyear230128 FROM Hejy_TC230128";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            ResultSet rst = pstmt.executeQuery();
            while (rst.next())
            {
                String year = rst.getString("hjy_TCyear230128");
                teaYears.add(year);
            }
            conn.close();
            return teaYears;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return null;
        }
    }
}

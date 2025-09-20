package dao.StuLocation;

import com.model.teacher.Region;
import com.model.teacher.StuLocation;
import com.model.teacher.TeachersCourses;
import dao.DaoException;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

public class StuLocationDaoImpl implements StuLocationDao{
    public ArrayList<StuLocation> SelectStuLocation(String p,String c,String d) throws DaoException
    {
        ArrayList<StuLocation> StuLocationArrayList = new ArrayList<StuLocation>();
        String sql="CALL Hejy_StuLocation230128(?,?,?)";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, p);
            pstmt.setString(2, c);
            pstmt.setString(3, d);
            ResultSet rst = pstmt.executeQuery();

            while (rst.next())
            {

                StuLocation sg = new StuLocation();
                sg.setSno(rst.getString("hjy_Sno230128"));
                sg.setSname(rst.getString("hjy_Sname230128"));
                sg.setPname(rst.getString("hjy_Pname230128"));
                sg.setCiname(rst.getString("hjy_Ciname230128"));
                sg.setDname(rst.getString("hjy_Dname230128"));

                StuLocationArrayList.add(sg);

            }
            conn.close();
            return StuLocationArrayList;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return null;
        }

    }




    public ArrayList<Region> SelectProvince() throws DaoException
    {
        ArrayList<Region> R = new ArrayList<Region>();
        String sql="SELECT * FROM Hejy_Province230128";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);

            ResultSet rst = pstmt.executeQuery();
            while (rst.next())
            {
                Region sg = new Region();
                sg.setNum(rst.getString("hjy_Pno230128"));
                sg.setName(rst.getString("hjy_Pname230128"));

                R.add(sg);
            }
            conn.close();
            return R;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return null;
        }
    }
    public ArrayList<Region> SelectCity(String loc) throws DaoException
    {
        ArrayList<Region> R = new ArrayList<Region>();
        String sql="SELECT hjy_Cino230128, hjy_Ciname230128 FROM Hejy_City230128 WHERE hjy_Pno230128 = ?";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, loc);

            ResultSet rst = pstmt.executeQuery();
            while (rst.next())
            {
                Region sg = new Region();
                sg.setNum(rst.getString("hjy_Cino230128"));
                sg.setName(rst.getString("hjy_Ciname230128"));

                R.add(sg);
            }
            conn.close();
            return R;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return null;
        }
    }
    public ArrayList<Region> SelectDistrict(String loc) throws DaoException
    {
        ArrayList<Region> R = new ArrayList<Region>();
        String sql="SELECT hjy_Dno230128, hjy_Dname230128 FROM Hejy_District230128 WHERE hjy_Cino230128 = ?";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, loc);

            ResultSet rst = pstmt.executeQuery();
            while (rst.next())
            {
                Region sg = new Region();
                sg.setNum(rst.getString("hjy_Dno230128"));
                sg.setName(rst.getString("hjy_Dname230128"));

                R.add(sg);
            }
            conn.close();
            return R;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return null;
        }
    }
}

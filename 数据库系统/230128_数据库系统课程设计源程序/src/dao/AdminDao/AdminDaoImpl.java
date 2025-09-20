package dao.AdminDao;

import com.model.admin.*;
import dao.DaoException;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

public class AdminDaoImpl implements AdminDao{
    public boolean InsertMajors(String hjy_Mno230128, String hjy_Mname230128) throws DaoException
    {
        String sql="INSERT INTO Hejy_Majors230128 VALUES\n" +
                "(?,?)";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, hjy_Mno230128);
            pstmt.setString(2, hjy_Mname230128);
            int n = pstmt.executeUpdate();
            conn.close();
            if(n!=0)
            {
                return true;
            }
            return false;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return false;
        }
    }
    public boolean InsertClasses(String hjy_Clno230128, String hjy_Clname230128, String hjy_Mno230128) throws DaoException
    {
        String sql="INSERT INTO Hejy_classes230128 VALUES\n" +
                "(?,?,?)";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, hjy_Clno230128);
            pstmt.setString(2, hjy_Clname230128);
            pstmt.setString(3, hjy_Mno230128);
            int n = pstmt.executeUpdate();
            conn.close();
            if(n!=0)
            {
                return true;
            }
            return false;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return false;
        }
    }
    public boolean InsertTeachers(String hjy_Tno230128, String hjy_Tname230128, String hjy_Tsex230128, int hjy_Tage230128
            , String hjy_Tphone230128, String hjy_Tprof230128, String hjy_Tpassword230128) throws DaoException
    {
        String sql="INSERT INTO Hejy_Teachers230128 VALUES\n" +
                "(?,?,?,?,?,?,?)";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, hjy_Tno230128);
            pstmt.setString(2, hjy_Tname230128);
            pstmt.setString(3, hjy_Tsex230128);
            pstmt.setInt(4, hjy_Tage230128);
            pstmt.setString(5, hjy_Tphone230128);
            pstmt.setString(6, hjy_Tprof230128);
            pstmt.setString(7, hjy_Tpassword230128);
            int n = pstmt.executeUpdate();
            conn.close();
            if(n!=0)
            {
                return true;
            }
            return false;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return false;
        }
    }
    public boolean InsertStudents(String hjy_Sno230128, String  hjy_Sname230128, String hjy_Ssex230128, int hjy_Sage230128, double hjy_Scredits230128,
                                  String hjy_Slocation230128, String hjy_Spassword230128, String hjy_Clno230128, double hjy_Sscore230128) throws DaoException
    {
        String sql="INSERT INTO Hejy_Students230128 VALUES\n" +
                "(?,?,?,?,?,?,?,?,?)";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, hjy_Sno230128);
            pstmt.setString(2, hjy_Sname230128);
            pstmt.setString(3, hjy_Ssex230128);
            pstmt.setInt(4, hjy_Sage230128);
            pstmt.setDouble(5, hjy_Scredits230128);
            pstmt.setString(6, hjy_Slocation230128);
            pstmt.setString(7, hjy_Spassword230128);
            pstmt.setString(8, hjy_Clno230128);
            pstmt.setDouble(9, hjy_Sscore230128);
            int n = pstmt.executeUpdate();
            conn.close();
            if(n!=0)
            {
                return true;
            }
            return false;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return false;
        }
    }
    public boolean InsertCourses(String hjy_Cno230128, String hjy_Clno230128, String hjy_Cname230128,
                                 double hjy_Ccredit230128, String hjy_Cevaluation230128, String hjy_Cterm230128, int hjy_Cperiod230128) throws DaoException
    {
        String sql="INSERT INTO Hejy_Courses230128 VALUES\n" +
                "(?,?,?,?,?,?,?)";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, hjy_Cno230128);
            pstmt.setString(2, hjy_Clno230128);
            pstmt.setString(3, hjy_Cname230128);
            pstmt.setDouble(4, hjy_Ccredit230128);
            pstmt.setString(5, hjy_Cevaluation230128);
            pstmt.setString(6, hjy_Cterm230128);
            pstmt.setInt(7, hjy_Cperiod230128);
            int n = pstmt.executeUpdate();
            conn.close();
            if(n!=0)
            {
                return true;
            }
            return false;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return false;
        }
    }
    public boolean InsertSC(String hjy_Sno230128, String hjy_Cno230128, String hjy_Clno230128, String hjy_SCyear230128, int hjy_SCscore230128) throws DaoException
    {
        String sql="INSERT INTO Hejy_SC230128 VALUES\n" +
                "(?,?,?,?,?)";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, hjy_Sno230128);
            pstmt.setString(2, hjy_Cno230128);
            pstmt.setString(3, hjy_Clno230128);
            pstmt.setString(4, hjy_SCyear230128);
            pstmt.setInt(5, hjy_SCscore230128);
            int n = pstmt.executeUpdate();
            conn.close();
            if(n!=0)
            {
                return true;
            }
            return false;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return false;
        }
    }
    public boolean InsertTC(String hjy_Tno230128, String hjy_Cno230128, String hjy_Clno230128, String hjy_TCyear230128) throws DaoException
    {
        String sql="INSERT INTO Hejy_TC230128 VALUES\n" +
                "(?,?,?,?)";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, hjy_Tno230128);
            pstmt.setString(2, hjy_Cno230128);
            pstmt.setString(3, hjy_Clno230128);
            pstmt.setString(4, hjy_TCyear230128);

            int n = pstmt.executeUpdate();
            conn.close();
            if(n!=0)
            {
                return true;
            }
            return false;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return false;
        }
    }
    public boolean InsertProvince(String hjy_Pno230128, String hjy_Pname230128) throws DaoException
    {
        String sql="INSERT INTO Hejy_Province230128 VALUES\n" +
                "(?,?)";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, hjy_Pno230128);
            pstmt.setString(2, hjy_Pname230128);
            int n = pstmt.executeUpdate();
            conn.close();
            if(n!=0)
            {
                return true;
            }
            return false;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return false;
        }
    }
    public boolean InsertCity(String hjy_Cino230128, String hjy_Ciname230128, String hjy_Pno230128) throws DaoException
    {
        String sql="INSERT INTO Hejy_City230128 VALUES\n" +
                "(?,?,?)";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, hjy_Cino230128);
            pstmt.setString(2, hjy_Ciname230128);
            pstmt.setString(3, hjy_Pno230128);
            int n = pstmt.executeUpdate();
            conn.close();
            if(n!=0)
            {
                return true;
            }
            return false;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return false;
        }
    }
    public boolean InsertDistrict(String hjy_Dno230128, String hjy_Dname230128, String hjy_Cino230128) throws DaoException
    {
        String sql="INSERT INTO Hejy_District230128 VALUES\n" +
                "(?,?,?)";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, hjy_Dno230128);
            pstmt.setString(2, hjy_Dname230128);
            pstmt.setString(3, hjy_Cino230128);
            int n = pstmt.executeUpdate();
            conn.close();
            if(n!=0)
            {
                return true;
            }
            return false;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return false;
        }
    }




    public ArrayList<City> SelectCity() throws DaoException
    {
        ArrayList<City> arr = new ArrayList<City>();
        String sql="SELECT * FROM Hejy_City230128";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);

            ResultSet rst = pstmt.executeQuery();
            while (rst.next())
            {
                City l = new City();
                l.sethjy_Cino230128(rst.getString("hjy_Cino230128"));
                l.sethjy_Ciname230128(rst.getString("hjy_Ciname230128"));
                l.sethjy_Pno230128(rst.getString("hjy_Pno230128"));
                arr.add(l);

            }
            conn.close();
            return arr;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return null;
        }
    }
    public ArrayList<Classes> SelectClasses() throws DaoException
    {
        ArrayList<Classes> arr = new ArrayList<Classes>();
        String sql="SELECT * FROM Hejy_classes230128";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);

            ResultSet rst = pstmt.executeQuery();
            while (rst.next())
            {
                Classes l = new Classes();
                l.sethjy_Clno230128(rst.getString("hjy_Clno230128"));
                l.sethjy_Clname230128(rst.getString("hjy_Clname230128"));
                l.sethjy_Mno230128(rst.getString("hjy_Mno230128"));
                arr.add(l);

            }
            conn.close();
            return arr;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return null;
        }
    }
    public ArrayList<Courses> SelectCourses() throws DaoException
    {
        ArrayList<Courses> arr = new ArrayList<Courses>();
        String sql="SELECT * FROM Hejy_Courses230128";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);

            ResultSet rst = pstmt.executeQuery();
            while (rst.next())
            {
                Courses l = new Courses();
                l.sethjy_Cno230128(rst.getString("hjy_Cno230128"));
                l.sethjy_Clno230128(rst.getString("hjy_Clno230128"));
                l.sethjy_Cname230128(rst.getString("hjy_Cname230128"));
                l.sethjy_Ccredit230128(rst.getDouble("hjy_Ccredit230128"));
                l.sethjy_Cevaluation230128(rst.getString("hjy_Cevaluation230128"));
                l.sethjy_Cterm230128(rst.getString("hjy_Cterm230128"));
                l.sethjy_Cperiod230128(rst.getInt("hjy_Cperiod230128"));
                arr.add(l);

            }
            conn.close();
            return arr;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return null;
        }
    }
    public ArrayList<District> SelectDistrict() throws DaoException
    {
        ArrayList<District> arr = new ArrayList<District>();
        String sql="SELECT * FROM Hejy_District230128";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);

            ResultSet rst = pstmt.executeQuery();
            while (rst.next())
            {
                District l = new District();
                l.sethjy_Dno230128(rst.getString("hjy_Dno230128"));
                l.sethjy_Dname230128(rst.getString("hjy_Dname230128"));
                l.sethjy_Cino230128(rst.getString("hjy_Cino230128"));
                arr.add(l);

            }
            conn.close();
            return arr;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return null;
        }
    }
    public ArrayList<Majors> SelectMajors() throws DaoException
    {
        ArrayList<Majors> arr = new ArrayList<Majors>();
        String sql="SELECT * FROM Hejy_Majors230128";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);

            ResultSet rst = pstmt.executeQuery();
            while (rst.next())
            {
                Majors l = new Majors();
                l.sethjy_Mno230128(rst.getString("hjy_Mno230128"));
                l.sethjy_Mname230128(rst.getString("hjy_Mname230128"));
                arr.add(l);

            }
            conn.close();
            return arr;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return null;
        }
    }
    public ArrayList<Province> SelectProvince() throws DaoException
    {
        ArrayList<Province> arr = new ArrayList<Province>();
        String sql="SELECT * FROM Hejy_Province230128";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);

            ResultSet rst = pstmt.executeQuery();
            while (rst.next())
            {
                Province l = new Province();
                l.sethjy_Pno230128(rst.getString("hjy_Pno230128"));
                l.sethjy_Pname230128(rst.getString("hjy_Pname230128"));
                arr.add(l);

            }
            conn.close();
            return arr;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return null;
        }
    }
    public ArrayList<SC> SelectSC() throws DaoException
    {
        ArrayList<SC> arr = new ArrayList<SC>();
        String sql="SELECT * FROM Hejy_SC230128";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);

            ResultSet rst = pstmt.executeQuery();
            while (rst.next())
            {
                SC l = new SC();
                l.sethjy_Sno230128(rst.getString("hjy_Sno230128"));
                l.sethjy_Cno230128(rst.getString("hjy_Cno230128"));
                l.sethjy_Clno230128(rst.getString("hjy_Clno230128"));
                l.sethjy_SCyear230128(rst.getString("hjy_SCyear230128"));
                l.sethjy_SCscore230128(rst.getInt("hjy_SCscore230128"));
                arr.add(l);

            }
            conn.close();
            return arr;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return null;
        }
    }
    public ArrayList<Students> SelectStudents() throws DaoException
    {
        ArrayList<Students> arr = new ArrayList<Students>();
        String sql="SELECT * FROM Hejy_Students230128";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);

            ResultSet rst = pstmt.executeQuery();
            while (rst.next())
            {
                Students l = new Students();

                l.sethjy_Sno230128(rst.getString("hjy_Sno230128"));
                l.sethjy_Sname230128(rst.getString("hjy_Sname230128"));
                l.sethjy_Ssex230128(rst.getString("hjy_Ssex230128"));
                l.sethjy_Sage230128(rst.getInt("hjy_Sage230128"));
                l.sethjy_Scredits230128(rst.getDouble("hjy_Scredits230128"));
                l.sethjy_Slocation230128(rst.getString("hjy_Slocation230128"));
                l.sethjy_Spassword230128(rst.getString("hjy_Spassword230128"));
                l.sethjy_Clno230128(rst.getString("hjy_Clno230128"));
//                l.sethjy_Sscore230128(rst.getDouble("hjy_Sscore230128"));
                double score = rst.getDouble("hjy_Sscore230128");
                // 乘以100后四舍五入，再除以100，以保留两位小数
                double scoreRounded = Math.round(score * 100.0) / 100.0;
                l.sethjy_Sscore230128(scoreRounded);

                arr.add(l);

            }
            conn.close();
            return arr;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return null;
        }
    }
    public ArrayList<TC> SelectTC() throws DaoException
    {
        ArrayList<TC> arr = new ArrayList<TC>();
        String sql="SELECT * FROM Hejy_TC230128";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);

            ResultSet rst = pstmt.executeQuery();
            while (rst.next())
            {
                TC l = new TC();

                l.sethjy_Tno230128(rst.getString("hjy_Tno230128"));
                l.sethjy_Cno230128(rst.getString("hjy_Cno230128"));
                l.sethjy_Clno230128(rst.getString("hjy_Clno230128"));
                l.sethjy_TCyear230128(rst.getString("hjy_TCyear230128"));
                arr.add(l);

            }
            conn.close();
            return arr;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return null;
        }
    }
    public ArrayList<Teachers> SelectTeachers() throws DaoException
    {
        ArrayList<Teachers> arr = new ArrayList<Teachers>();
        String sql="SELECT * FROM Hejy_Teachers230128";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);

            ResultSet rst = pstmt.executeQuery();
            while (rst.next())
            {
                Teachers l = new Teachers();

                 l.sethjy_Tno230128(rst.getString("hjy_Tno230128"));
                 l.sethjy_Tname230128(rst.getString("hjy_Tname230128"));
                 l.sethjy_Tsex230128(rst.getString("hjy_Tsex230128"));
                 l.sethjy_Tage230128(rst.getInt("hjy_Tage230128"));
                 l.sethjy_Tphone230128(rst.getString("hjy_Tphone230128"));
                 l.sethjy_Tprof230128(rst.getString("hjy_Tprof230128"));
                 l.sethjy_Tpassword230128(rst.getString("hjy_Tpassword230128"));
                arr.add(l);

            }
            conn.close();
            return arr;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return null;
        }
    }



    public boolean DeleteCity(String hjy_Cino230128) throws DaoException
    {
        String sql="DELETE FROM Hejy_City230128 WHERE hjy_Cino230128 =?\n";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, hjy_Cino230128);
            int n = pstmt.executeUpdate();
            conn.close();
            if(n!=0)
            {
                return true;
            }
            return false;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return false;
        }
    }
    public boolean DeleteClasses(String hjy_Clno230128) throws DaoException
    {
        String sql="DELETE FROM Hejy_classes230128 WHERE hjy_Clno230128 = ?\n";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, hjy_Clno230128);

            int n = pstmt.executeUpdate();
            conn.close();
            if(n!=0)
            {
                return true;
            }
            return false;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return false;
        }
    }
    public boolean DeleteCourses(String hjy_Cno230128, String hjy_Clno230128) throws DaoException
    {
        String sql="DELETE FROM Hejy_Courses230128 WHERE hjy_Cno230128 = ? AND hjy_Clno230128 = ? ";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, hjy_Cno230128);
            pstmt.setString(2, hjy_Clno230128);
            int n = pstmt.executeUpdate();
            conn.close();
            if(n!=0)
            {
                return true;
            }
            return false;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return false;
        }
    }
    public boolean DeleteDistrict(String hjy_Dno230128) throws DaoException
    {
        String sql="DELETE FROM Hejy_District230128 WHERE  hjy_Dno230128 = ?\n";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, hjy_Dno230128);

            int n = pstmt.executeUpdate();
            conn.close();
            if(n!=0)
            {
                return true;
            }
            return false;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return false;
        }
    }
    public boolean DeleteMajors(String hjy_Mno230128) throws DaoException
    {
        String sql="DELETE FROM Hejy_Majors230128 WHERE hjy_Mno230128 = ?\n";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, hjy_Mno230128);

            int n = pstmt.executeUpdate();
            conn.close();
            if(n!=0)
            {
                return true;
            }
            return false;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return false;
        }
    }
    public boolean DeleteProvince(String hjy_Pno230128) throws DaoException
    {
        String sql="DELETE FROM Hejy_Province230128 WHERE hjy_Pno230128 =?\n";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, hjy_Pno230128);

            int n = pstmt.executeUpdate();
            conn.close();
            if(n!=0)
            {
                return true;
            }
            return false;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return false;
        }
    }
    public boolean DeleteSC(String hjy_Sno230128, String hjy_Cno230128, String hjy_Clno230128, String hjy_SCyear230128) throws DaoException
    {
        String sql="DELETE FROM Hejy_SC230128 WHERE hjy_Sno230128 = ? AND   hjy_Cno230128 = ? AND hjy_Clno230128 = ? AND hjy_SCyear230128= ? \n";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, hjy_Sno230128);
            pstmt.setString(2, hjy_Cno230128);
            pstmt.setString(3, hjy_Clno230128);
            pstmt.setString(4, hjy_SCyear230128);
            int n = pstmt.executeUpdate();
            conn.close();
            if(n!=0)
            {
                return true;
            }
            return false;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return false;
        }
    }
    public boolean DeleteStudents(String hjy_Sno230128) throws DaoException
    {
        String sql="DELETE FROM Hejy_Students230128 WHERE hjy_Sno230128 = ?\n";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, hjy_Sno230128);

            int n = pstmt.executeUpdate();
            conn.close();
            if(n!=0)
            {
                return true;
            }
            return false;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return false;
        }
    }
    public boolean DeleteTC(String hjy_Tno230128, String hjy_Cno230128, String hjy_Clno230128, String hjy_TCyear230128) throws DaoException
    {
        String sql="DELETE FROM Hejy_TC230128 WHERE hjy_Tno230128 = ? AND hjy_Cno230128 = ? AND hjy_Clno230128 = ? AND hjy_TCyear230128= ? \n";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, hjy_Tno230128);
            pstmt.setString(2, hjy_Cno230128);
            pstmt.setString(3, hjy_Clno230128);
            pstmt.setString(4, hjy_TCyear230128);
            int n = pstmt.executeUpdate();
            conn.close();
            if(n!=0)
            {
                return true;
            }
            return false;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return false;
        }
    }
    public boolean DeleteTeachers(String hjy_Tno230128) throws DaoException
    {
        String sql="DELETE FROM Hejy_Teachers230128 WHERE hjy_Tno230128 = ?\n";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, hjy_Tno230128);

            int n = pstmt.executeUpdate();
            conn.close();
            if(n!=0)
            {
                return true;
            }
            return false;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return false;
        }
    }



    public boolean UpdateCity(String hjy_Ciname230128 , String hjy_Pno230128,String hjy_Cino230128 ) throws DaoException
    {
        String sql="UPDATE Hejy_City230128\n" +
                "SET hjy_Ciname230128= ? ,  hjy_Pno230128= ? \n" +
                "WHERE hjy_Cino230128 =?\n";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, hjy_Ciname230128);
            pstmt.setString(2, hjy_Pno230128);
            pstmt.setString(3, hjy_Cino230128);

            int n = pstmt.executeUpdate();
            conn.close();
            if(n!=0)
            {
                return true;
            }
            return false;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return false;
        }
    }
    public boolean UpdateClasses(String hjy_Clname230128  , String hjy_Mno230128,String hjy_Clno230128 ) throws DaoException
    {
        String sql="UPDATE Hejy_classes230128\n" +
                "SET hjy_Clname230128 = ? ,  hjy_Mno230128 = ?\n" +
                "where hjy_Clno230128 = ?";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, hjy_Clname230128);
            pstmt.setString(2, hjy_Mno230128);
            pstmt.setString(3, hjy_Clno230128);

            int n = pstmt.executeUpdate();
            conn.close();
            if(n!=0)
            {
                return true;
            }
            return false;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return false;
        }
    }
    public boolean UpdateCourses(String hjy_Cname230128 , double hjy_Ccredit230128 , String hjy_Cevaluation230128 , String hjy_Cterm230128 , int hjy_Cperiod230128 ,
                                 String hjy_Cno230128 , String hjy_Clno230128 ) throws DaoException
    {
        String sql="UPDATE Hejy_Courses230128\n" +
                "SET hjy_Cname230128= ? , hjy_Ccredit230128= ? ,  hjy_Cevaluation230128= ? ,  hjy_Cterm230128= ? ,  hjy_Cperiod230128= ? \n" +
                "WHERE hjy_Cno230128 = ? AND hjy_Clno230128 = ?\n";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, hjy_Cname230128);
            pstmt.setDouble(2, hjy_Ccredit230128);
            pstmt.setString(3, hjy_Cevaluation230128);
            pstmt.setString(4, hjy_Cterm230128);
            pstmt.setInt(5, hjy_Cperiod230128);
            pstmt.setString(6, hjy_Cno230128);
            pstmt.setString(7, hjy_Clno230128);

            int n = pstmt.executeUpdate();
            conn.close();
            if(n!=0)
            {
                return true;
            }
            return false;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return false;
        }
    }
    public boolean UpdateDistrict(String hjy_Dname230128 , String hjy_Cino230128, String hjy_Dno230128 ) throws DaoException
    {
        String sql="UPDATE Hejy_District230128\n" +
                "SET hjy_Dname230128= ? ,  hjy_Cino230128= ?\n" +
                "WHERE hjy_Dno230128 = ?\n";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, hjy_Dname230128);
            pstmt.setString(2, hjy_Cino230128);
            pstmt.setString(3, hjy_Dno230128);

            int n = pstmt.executeUpdate();
            conn.close();
            if(n!=0)
            {
                return true;
            }
            return false;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return false;
        }
    }
    public boolean UpdateMajors(String hjy_Mname230128,String hjy_Mno230128 ) throws DaoException
    {
        String sql="UPDATE Hejy_Majors230128\n" +
                "SET hjy_Mname230128 = ?\n" +
                "where hjy_Mno230128 = ?\n";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, hjy_Mname230128);
            pstmt.setString(2, hjy_Mno230128);

            int n = pstmt.executeUpdate();
            conn.close();
            if(n!=0)
            {
                return true;
            }
            return false;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return false;
        }
    }
    public boolean UpdateProvince(String hjy_Pname230128,String hjy_Pno230128 ) throws DaoException
    {
        String sql="UPDATE Hejy_Province230128\n" +
                "SET hjy_Pname230128=?\n" +
                "WHERE hjy_Pno230128 =?\n";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, hjy_Pname230128);
            pstmt.setString(2, hjy_Pno230128);


            int n = pstmt.executeUpdate();
            conn.close();
            if(n!=0)
            {
                return true;
            }
            return false;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return false;
        }
    }
    public boolean UpdateStudents(String hjy_Sname230128 , String hjy_Ssex230128 , int hjy_Sage230128 , double hjy_Scredits230128 , String hjy_Slocation230128 , String hjy_Spassword230128 , String hjy_Clno230128 , double hjy_Sscore230128,
                                  String hjy_Sno230128 ) throws DaoException
    {
        String sql="UPDATE Hejy_Students230128\n" +
                "SET hjy_Sname230128= ? ,  hjy_Ssex230128= ? ,  hjy_Sage230128= ? ,  hjy_Scredits230128= ? ,  hjy_Slocation230128= ? ,  hjy_Spassword230128= ? ,  hjy_Clno230128= ? ,  hjy_Sscore230128= ? \n" +
                "WHERE hjy_Sno230128 = ?\n";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, hjy_Sname230128);
            pstmt.setString(2, hjy_Ssex230128);
            pstmt.setInt(3, hjy_Sage230128);
            pstmt.setDouble(4, hjy_Scredits230128);
            pstmt.setString(5, hjy_Slocation230128);
            pstmt.setString(6, hjy_Spassword230128);
            pstmt.setString(7, hjy_Clno230128);
            pstmt.setDouble(8, hjy_Sscore230128);
            pstmt.setString(9, hjy_Sno230128);


            int n = pstmt.executeUpdate();
            conn.close();
            if(n!=0)
            {
                return true;
            }
            return false;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return false;
        }
    }
    public boolean UpdateTeachers(String hjy_Tname230128  , String hjy_Tsex230128  , int hjy_Tage230128  , String hjy_Tphone230128 , String  hjy_Tprof230128 , String  hjy_Tpassword230128,
                                  String hjy_Tno230128 ) throws DaoException
    {
        String sql="UPDATE Hejy_Teachers230128\n" +
                "SET hjy_Tname230128 = ? ,  hjy_Tsex230128 = ? ,  hjy_Tage230128 = ? ,  hjy_Tphone230128= ? ,   hjy_Tprof230128= ? ,   hjy_Tpassword230128= ? \n" +
                "where hjy_Tno230128 = ?\n";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, hjy_Tname230128);
            pstmt.setString(2, hjy_Tsex230128);
            pstmt.setInt(3, hjy_Tage230128);
            pstmt.setString(4, hjy_Tphone230128);
            pstmt.setString(5, hjy_Tprof230128);
            pstmt.setString(6, hjy_Tpassword230128);
            pstmt.setString(7, hjy_Tno230128);

            int n = pstmt.executeUpdate();
            conn.close();
            if(n!=0)
            {
                return true;
            }
            return false;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return false;
        }
    }
}

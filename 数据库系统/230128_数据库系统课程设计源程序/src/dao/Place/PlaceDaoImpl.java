package dao.Place;

import com.model.teacher.ClassesPlace;
import com.model.teacher.CoursesPlace;
import com.model.teacher.MajorPlace;
import dao.DaoException;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;


public class PlaceDaoImpl implements PlaceDao{
    public ArrayList<CoursesPlace> select_Courses_score_to_upload(String Cname,String Clname, String year) throws DaoException
    {
        ArrayList<CoursesPlace> stuCoursesArrayList = new ArrayList<CoursesPlace>();
        String sql="CALL Hejy_select_Courses_score_to_upload230128(?,?,?)";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, Cname);
            pstmt.setString(2, Clname);
            pstmt.setString(3, year);
            ResultSet rst = pstmt.executeQuery();
            while (rst.next())
            {
                CoursesPlace sc = new CoursesPlace();
                sc.setCno(rst.getString("hjy_Cno230128"));
                sc.setCname(rst.getString("hjy_Cname230128"));
                sc.setSCscore(rst.getInt("hjy_SCscore230128"));
                sc.setSno(rst.getString("hjy_Sno230128"));
                sc.setSname(rst.getString("hjy_Sname230128"));
                sc.setClno(rst.getString("hjy_Clno230128"));
                sc.setClname(rst.getString("hjy_Clname230128"));
                sc.setSCyear(rst.getString("hjy_SCyear230128"));
                stuCoursesArrayList.add(sc);
            }
            conn.close();
            return stuCoursesArrayList;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            throw new DaoException("录入学生成绩出错：" + e.getMessage()); // 抛出自定义异常信息

        }

    }

    public ArrayList<CoursesPlace> SelectCoursesPlace(String Cname,String Clname, String year) throws DaoException
    {
        ArrayList<CoursesPlace> stuCoursesArrayList = new ArrayList<CoursesPlace>();
        String sql="CALL Hejy_select_place_by_Courses230128(?,?)";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, Cname);
            pstmt.setString(2, year);
            ResultSet rst = pstmt.executeQuery();
            while (rst.next())
            {
                CoursesPlace sc = new CoursesPlace();
                sc.setCno(rst.getString("hjy_Cno230128"));
                sc.setCname(rst.getString("hjy_Cname230128"));
                sc.setSCscore(rst.getInt("hjy_SCscore230128"));
                sc.setSno(rst.getString("hjy_Sno230128"));
                sc.setSname(rst.getString("hjy_Sname230128"));
                sc.setClno(rst.getString("hjy_Clno230128"));
                sc.setClname(rst.getString("hjy_Clname230128"));
                sc.setSCyear(rst.getString("hjy_SCyear230128"));
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
    public ArrayList<String> SelectCoursesScoreDistribution(String Cname, String year) throws DaoException
    {
        ArrayList<String> csd = new ArrayList<String>();
        String sql="CALL Hejy_select_Courses_Score_Distribution230128(?,?)";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, Cname);
            pstmt.setString(2, year);
            ResultSet rst = pstmt.executeQuery();
            while (rst.next())
            {
                csd.add(rst.getString("num"));
            }
            conn.close();
            return csd;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return null;
        }
    }


    public ArrayList<ClassesPlace> SelectClassesPlace(String Cname,String Clname, String year) throws DaoException
    {
        ArrayList<ClassesPlace> stuClassesArrayList = new ArrayList<ClassesPlace>();
        String sql="CALL Hejy_select_place_by_classes230128(?)";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, Clname);

            ResultSet rst = pstmt.executeQuery();
            while (rst.next())
            {
                ClassesPlace sc = new ClassesPlace();

                sc.setSno(rst.getString("hjy_Sno230128"));
                sc.setSname(rst.getString("hjy_Sname230128"));
                sc.setSsex(rst.getString("hjy_Ssex230128"));
                double sscore = rst.getDouble("hjy_Sscore230128");
                double sscoreRounded = Math.round(sscore * 100.0) / 100.0;
                sc.setSscore(sscoreRounded);
//                sc.setSscore(rst.getDouble("hjy_Sscore230128"));
                sc.setClno(rst.getString("hjy_Clno230128"));
                sc.setClname(rst.getString("hjy_Clname230128"));

                stuClassesArrayList.add(sc);
            }
            conn.close();
            return stuClassesArrayList;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return null;
        }
    }

    public ArrayList<MajorPlace> SelectMajorPlace(String Cname,String Clname, String year) throws DaoException {
        ArrayList<MajorPlace> stuMajorArrayList = new ArrayList<MajorPlace>();

        try {
            Connection conn = getConnection();

            // 获取对应 Clname 的专业 Mname 值
            String getMajorNameSql = "SELECT m.hjy_Mname230128 FROM Hejy_classes230128 cl " +
                    "JOIN Hejy_Majors230128 m ON cl.hjy_Mno230128 = m.hjy_Mno230128 " +
                    "WHERE cl.hjy_Clname230128 = ?";

            PreparedStatement getMajorNameStmt = conn.prepareStatement(getMajorNameSql);
            getMajorNameStmt.setString(1, Clname);
            ResultSet majorNameResult = getMajorNameStmt.executeQuery();

            String Mname = null;
            if (majorNameResult.next()) {
                Mname = majorNameResult.getString("hjy_Mname230128");
            }

            // 调用存储过程 Hejy_select_place_by_Majors230128 并获取结果
            String selectPlaceSql = "SELECT * FROM Hejy_select_place_by_Majors230128(?)";
            PreparedStatement selectPlaceStmt = conn.prepareStatement(selectPlaceSql);
            selectPlaceStmt.setString(1, Mname);
            ResultSet placeResult = selectPlaceStmt.executeQuery();

            while (placeResult.next()) {
                MajorPlace sc = new MajorPlace();
                sc.setSno(placeResult.getString("hjy_Sno230128"));
                sc.setSname(placeResult.getString("hjy_Sname230128"));
                sc.setSsex(placeResult.getString("hjy_Ssex230128"));
//                sc.setSscore(placeResult.getDouble("hjy_Sscore230128"));
                double sscore = placeResult.getDouble("hjy_Sscore230128");
                // 乘以100进行四舍五入，再除以100恢复小数点位置
                double sscoreRounded = Math.round(sscore * 100.0) / 100.0;
                sc.setSscore(sscoreRounded);
                sc.setClno(placeResult.getString("hjy_Clno230128"));
                sc.setClname(placeResult.getString("hjy_Clname230128"));
                sc.setMno(placeResult.getString("hjy_Mno230128"));
                sc.setMname(placeResult.getString("hjy_Mname230128"));

                stuMajorArrayList.add(sc);
            }

            conn.close();
            return stuMajorArrayList;
        } catch (SQLException e) {
            e.printStackTrace();
            return null;
        }
    }


    public boolean UpdateScore(int score, String Sno,String Cno, String Clno, String year) throws DaoException
    {
        String sql="UPDATE Hejy_SC230128\n" +
                "SET hjy_SCscore230128 = ?\n" +
                "WHERE hjy_Sno230128 = ? AND hjy_Cno230128 = ? AND hjy_Clno230128 = ? AND hjy_SCyear230128 = ?";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setInt(1, score);
            pstmt.setString(2, Sno);
            pstmt.setString(3, Cno);
            pstmt.setString(4, Clno);
            pstmt.setString(5, year);
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

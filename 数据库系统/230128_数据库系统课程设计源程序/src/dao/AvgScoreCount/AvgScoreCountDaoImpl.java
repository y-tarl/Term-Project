package dao.AvgScoreCount;

import com.model.teacher.AvgScoreCount;
import com.model.teacher.CoursesPlace;
import dao.DaoException;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

public class AvgScoreCountDaoImpl implements AvgScoreCountDao{
    public ArrayList<AvgScoreCount> Hejy_AvgScoreCount230128(String Cname,String Clname,String year) throws DaoException
    {
        ArrayList<AvgScoreCount> AvgScoreCountArrayList = new ArrayList<AvgScoreCount>();
        String sql="SELECT * FROM Hejy_AvgScoreCount230128 WHERE hjy_SCyear230128 = ? AND hjy_Cname230128=? ";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, year);
            pstmt.setString(2,Cname);
            ResultSet rst = pstmt.executeQuery();
            while (rst.next())
            {
                AvgScoreCount sc = new AvgScoreCount();

                sc.setCname(rst.getString("hjy_Cname230128"));
                sc.setYear(rst.getString("hjy_SCyear230128"));
                sc.setAveScore(rst.getDouble("AvgScore"));
                AvgScoreCountArrayList.add(sc);
            }
            conn.close();
            return AvgScoreCountArrayList;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return null;
        }

    }

}

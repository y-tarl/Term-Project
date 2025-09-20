package dao.stuGrade;

import com.model.student.stuGrade;
import dao.DaoException;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.text.DecimalFormat;

public class StuGradeDaoImpl implements StuGradeDao{
    public ArrayList<stuGrade> selectAllScores(String Sno) throws DaoException
    {
        ArrayList<stuGrade> stuGradeArrayList = new ArrayList<stuGrade>();
        String sql="CALL Hejy_select_students_allScores230128(?)";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, Sno);

            ResultSet rst = pstmt.executeQuery();
            while (rst.next())
            {
                stuGrade sg = new stuGrade();
                sg.setCno(rst.getString("hjy_Cno230128"));
                sg.setClname(rst.getString("hjy_Clname230128"));
                sg.setSCscore(rst.getInt("hjy_SCscore230128"));
                sg.setSCyear(rst.getString("hjy_SCyear230128"));
                sg.setCname(rst.getString("hjy_Cname230128"));
                sg.setCcredit(rst.getDouble("hjy_Ccredit230128"));
                sg.setCevaluation(rst.getString("hjy_Cevaluation230128"));
                sg.setCterm(rst.getString("hjy_Cterm230128"));
                sg.setCperiod(rst.getInt("hjy_Cperiod230128"));
                stuGradeArrayList.add(sg);
            }
            conn.close();
            return stuGradeArrayList;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return null;
        }
    }

    public ArrayList<stuGrade> selectScores(String Sno,String year) throws DaoException
    {
        ArrayList<stuGrade> stuGradeArrayList = new ArrayList<stuGrade>();
        String sql="CALL Hejy_select_students_scores230128(?,?)";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, Sno);
            pstmt.setString(2, year);
            ResultSet rst = pstmt.executeQuery();
            while (rst.next())
            {
                stuGrade sg = new stuGrade();
                sg.setCno(rst.getString("hjy_Cno230128"));
                sg.setClname(rst.getString("hjy_Clname230128"));
                sg.setSCscore(rst.getInt("hjy_SCscore230128"));
                sg.setSCyear(rst.getString("hjy_SCyear230128"));
                sg.setCname(rst.getString("hjy_Cname230128"));
                sg.setCcredit(rst.getDouble("hjy_Ccredit230128"));
                sg.setCevaluation(rst.getString("hjy_Cevaluation230128"));
                sg.setCterm(rst.getString("hjy_Cterm230128"));
                sg.setCperiod(rst.getInt("hjy_Cperiod230128"));
                stuGradeArrayList.add(sg);
            }
            conn.close();
            return stuGradeArrayList;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return null;
        }

    }


    public ArrayList<String> CreditsAndScores(String Sno) throws DaoException
    {
        ArrayList<String> CS = new ArrayList<String>();
        String sql="SELECT hjy_Scredits230128, hjy_Sscore230128 FROM Hejy_Students230128 WHERE hjy_Sno230128 = ?";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, Sno);

            ResultSet rst = pstmt.executeQuery();
            DecimalFormat decimalFormat = new DecimalFormat("#0.00");
            if (rst.next())
            {
                CS.add(decimalFormat.format(rst.getDouble("hjy_Scredits230128")));
                CS.add(decimalFormat.format(rst.getDouble("hjy_Sscore230128")));
            }
            conn.close();
            return CS;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return null;
        }
    }
}

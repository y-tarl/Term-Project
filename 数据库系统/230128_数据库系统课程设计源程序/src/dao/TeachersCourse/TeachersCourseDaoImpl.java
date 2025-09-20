package dao.TeachersCourse;

import com.model.student.stuGrade;
import com.model.teacher.TeachersCourses;
import dao.DaoException;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

public class TeachersCourseDaoImpl implements TeachersCourseDao{
    public ArrayList<TeachersCourses> SelectTeachersCourses(String Tname) throws DaoException
    {
        ArrayList<TeachersCourses> TeachersCoursesArrayList = new ArrayList<TeachersCourses>();
        String sql="CALL Hejy_select_Teachers_courses230128(?)";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, Tname);

            ResultSet rst = pstmt.executeQuery();
            while (rst.next())
            {
                TeachersCourses sg = new TeachersCourses();
                sg.setTno(rst.getString("hjy_Tno230128"));
                sg.setTname(rst.getString("hjy_Tname230128"));
                sg.setCno(rst.getString("hjy_Cno230128"));
                sg.setClname(rst.getString("hjy_Clname230128"));
                sg.setTCyear(rst.getString("hjy_TCyear230128"));
                sg.setCname(rst.getString("hjy_Cname230128"));

                TeachersCoursesArrayList.add(sg);
            }
            conn.close();
            return TeachersCoursesArrayList;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return null;
        }

    }


    public ArrayList<String> SelectTeachersCoursesAsOption(String Tname) throws DaoException
    {
        ArrayList<String> TeachersCoursesArrayList = new ArrayList<String>();
        String sql="CALL Hejy_select_Teachers_courses230128(?)";
        try
        {
            Connection conn = getConnection();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, Tname);

            ResultSet rst = pstmt.executeQuery();
            while (rst.next())
            {
                TeachersCoursesArrayList.add(
                        rst.getString("hjy_Cname230128")+"——"+
                        rst.getString("hjy_Clname230128")+"——"+
                        rst.getString("hjy_TCyear230128"));

            }
            conn.close();
            return TeachersCoursesArrayList;
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            return null;
        }
    }

}

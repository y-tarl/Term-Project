package servlet.teachers;

import com.model.teacher.AvgScoreCount;
import com.model.teacher.CoursesPlace;
import com.model.teacher.MajorPlace;
import com.model.teacher.TeaInfo;
import dao.AvgScoreCount.AvgScoreCountDaoImpl;
import dao.Place.PlaceDaoImpl;
import dao.TeachersCourse.TeachersCourseDaoImpl;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;
import java.util.ArrayList;

@WebServlet(name = "MajorsPlaceServlet", value = "/MajorsPlace.do")
public class MajorsPlaceServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("UTF-8");
        response.setContentType("text/html;charset=UTF-8");

        request.setAttribute("pageName", "MajorsPlace");

        request.setAttribute("MajorsPlaceArrayList", null);

        String Tname = ((TeaInfo)request.getSession().getAttribute("teaInfomation")).getTname();
        try
        {
            ArrayList<String> teachersCourses_MajorsPlace = new TeachersCourseDaoImpl().SelectTeachersCoursesAsOption(Tname);
            request.setAttribute("teachersCourses_MajorsPlace", teachersCourses_MajorsPlace);
        }
        catch (Exception e)
        {
            System.out.println(e);
        }

        RequestDispatcher dispatcher = request.getRequestDispatcher("/WEB-INF/teaWeb.jsp");
        dispatcher.forward(request,response);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("UTF-8");
        response.setContentType("text/html;charset=UTF-8");

        request.setAttribute("pageName", "MajorsPlace");

        String tCourses_AvgScore = (String)request.getParameter("teachersClasses_Majors");
        String[] split_AvgScore = tCourses_AvgScore.split("——");
        try
        {
            ArrayList<MajorPlace> MajorsPlaceArrayList = new PlaceDaoImpl().SelectMajorPlace(split_AvgScore[0],split_AvgScore[1], split_AvgScore[2]);
            request.setAttribute("MajorsPlaceArrayList", MajorsPlaceArrayList);

        }
        catch (Exception e)
        {
            System.out.println(e);
        }

        String Tname = ((TeaInfo)request.getSession().getAttribute("teaInfomation")).getTname();
        try
        {
            ArrayList<String> teachersCourses_MajorsPlace = new TeachersCourseDaoImpl().SelectTeachersCoursesAsOption(Tname);
            request.setAttribute("teachersCourses_MajorsPlace", teachersCourses_MajorsPlace);
        }
        catch (Exception e)
        {
            System.out.println(e);
        }

        RequestDispatcher dispatcher = request.getRequestDispatcher("/WEB-INF/teaWeb.jsp");
        dispatcher.forward(request,response);
    }
}

package servlet.teachers;

import com.model.student.stuGrade;
import com.model.student.stuInfo;
import com.model.teacher.AvgScoreCount;
import com.model.teacher.CoursesPlace;
import com.model.teacher.TeaInfo;
import dao.AvgScoreCount.AvgScoreCountDaoImpl;
import dao.Place.PlaceDaoImpl;
import dao.TeachersCourse.TeachersCourseDaoImpl;
import dao.stuGrade.StuGradeDaoImpl;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;
import java.util.ArrayList;

@WebServlet(name = "CoursesPlaceServlet", value = "/CoursesPlace.do")
public class CoursesPlaceServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("UTF-8");
        response.setContentType("text/html;charset=UTF-8");

        request.setAttribute("pageName", "CoursesPlace");

        request.setAttribute("CoursesPlaceArrayList", null);
        request.setAttribute("CoursesScoreDistribution", null);

        String Tname = ((TeaInfo)request.getSession().getAttribute("teaInfomation")).getTname();
        try
        {
            ArrayList<String> teachersCourses_Courses = new TeachersCourseDaoImpl().SelectTeachersCoursesAsOption(Tname);
            request.setAttribute("teachersCourses_CoursesPlace", teachersCourses_Courses);
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

        request.setAttribute("pageName", "CoursesPlace");


        String tCourses_Courses = (String)request.getParameter("teachersCourses_CoursesPlace");
        String[] split_AvgScore = tCourses_Courses.split("——");
        try
        {
            ArrayList<CoursesPlace> CoursesPlaceArrayList_Courses = new PlaceDaoImpl().SelectCoursesPlace(split_AvgScore[0],split_AvgScore[1], split_AvgScore[2]);
            request.setAttribute("CoursesPlaceArrayList", CoursesPlaceArrayList_Courses);

        }
        catch (Exception e)
        {
            System.out.println(e);
        }

        //----------------------------------------------


        String Tname = ((TeaInfo)request.getSession().getAttribute("teaInfomation")).getTname();
        try
        {
            ArrayList<String> teachersCourses_Courses = new TeachersCourseDaoImpl().SelectTeachersCoursesAsOption(Tname);
            request.setAttribute("teachersCourses_CoursesPlace", teachersCourses_Courses);
        }
        catch (Exception e)
        {
            System.out.println(e);
        }

        RequestDispatcher dispatcher = request.getRequestDispatcher("/WEB-INF/teaWeb.jsp");
        dispatcher.forward(request,response);

    }
}

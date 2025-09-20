package servlet.teachers;

import com.model.teacher.AvgScoreCount;
import com.model.teacher.ClassesPlace;
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

@WebServlet(name = "ClassesPlaceServlet", value = "/ClassesPlace.do")
public class ClassesPlaceServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("UTF-8");
        response.setContentType("text/html;charset=UTF-8");

        request.setAttribute("pageName", "ClassesPlace");

        request.setAttribute("ClassesPlaceArrayList", null);
        String Tname = ((TeaInfo)request.getSession().getAttribute("teaInfomation")).getTname();
        try
        {
            ArrayList<String> teachersCourses_ClassesPlace = new TeachersCourseDaoImpl().SelectTeachersCoursesAsOption(Tname);
            request.setAttribute("teachersCourses_ClassesPlace", teachersCourses_ClassesPlace);
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

        request.setAttribute("pageName", "ClassesPlace");

        String tCourses_AvgScore = (String)request.getParameter("teachersClasses_Place");
        String[] split_AvgScore = tCourses_AvgScore.split("——");
        try
        {
            ArrayList<ClassesPlace> ClassesPlaceArrayList = new PlaceDaoImpl().SelectClassesPlace(split_AvgScore[0],split_AvgScore[1], split_AvgScore[2]);
            request.setAttribute("ClassesPlaceArrayList", ClassesPlaceArrayList);

        }
        catch (Exception e)
        {
            System.out.println(e);
        }

        String Tname = ((TeaInfo)request.getSession().getAttribute("teaInfomation")).getTname();
        try
        {
            ArrayList<String> teachersCourses_ClassesPlace = new TeachersCourseDaoImpl().SelectTeachersCoursesAsOption(Tname);
            request.setAttribute("teachersCourses_ClassesPlace", teachersCourses_ClassesPlace);
        }
        catch (Exception e)
        {
            System.out.println(e);
        }

        RequestDispatcher dispatcher = request.getRequestDispatcher("/WEB-INF/teaWeb.jsp");
        dispatcher.forward(request,response);
    }
}

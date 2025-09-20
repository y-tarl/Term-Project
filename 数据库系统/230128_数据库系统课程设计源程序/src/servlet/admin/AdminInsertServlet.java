package servlet.admin;

import com.model.admin.*;
import dao.AdminDao.AdminDaoImpl;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;
import java.util.ArrayList;

@WebServlet(name = "AdminInsertServlet", value = "/Admin.do")
public class AdminInsertServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("UTF-8");
        response.setContentType("text/html;charset=UTF-8");
        try {
            String pageName = request.getParameter("pageName");
            switch (pageName) {
                case "adminMyPage":
                    request.setAttribute("pageName", "adminMyPage");
                    break;
                case "Majors":
                    request.setAttribute("pageName", "Majors");
                    ArrayList<Majors> MajorsArrayList = new AdminDaoImpl().SelectMajors();
                    request.setAttribute("MajorsArrayList", MajorsArrayList);
                    break;
                case "Classes":
                    request.setAttribute("pageName", "Classes");
                    ArrayList<Classes> ClassesArrayList = new AdminDaoImpl().SelectClasses();
                    request.setAttribute("ClassesArrayList", ClassesArrayList);
                    break;
                case "Teachers":
                    request.setAttribute("pageName", "Teachers");
                    ArrayList<Teachers> TeachersArrayList = new AdminDaoImpl().SelectTeachers();
                    request.setAttribute("TeachersArrayList", TeachersArrayList);
                    break;
                case "Students":
                    request.setAttribute("pageName", "Students");
                    ArrayList<Students> StudentsArrayList = new AdminDaoImpl().SelectStudents();
                    request.setAttribute("StudentsArrayList", StudentsArrayList);
                    break;
                case "Courses":
                    request.setAttribute("pageName", "Courses");
                    ArrayList<Courses> CoursesArrayList = new AdminDaoImpl().SelectCourses();
                    request.setAttribute("CoursesArrayList", CoursesArrayList);
                    break;
                case "SC":
                    request.setAttribute("pageName", "SC");
                    ArrayList<SC> SCArrayList = new AdminDaoImpl().SelectSC();
                    request.setAttribute("SCArrayList", SCArrayList);
                    break;
                case "TC":
                    request.setAttribute("pageName", "TC");
                    ArrayList<TC> TCArrayList = new AdminDaoImpl().SelectTC();
                    request.setAttribute("TCArrayList", TCArrayList);
                    break;
                case "Province":
                    request.setAttribute("pageName", "Province");
                    ArrayList<Province> ProvinceArrayList = new AdminDaoImpl().SelectProvince();
                    request.setAttribute("ProvinceArrayList", ProvinceArrayList);
                    break;
                case "City":
                    request.setAttribute("pageName", "City");
                    ArrayList<City> CityArrayList = new AdminDaoImpl().SelectCity();
                    request.setAttribute("CityArrayList", CityArrayList);
                    break;
                case "District":
                    request.setAttribute("pageName", "District");
                    ArrayList<District> DistrictArrayList = new AdminDaoImpl().SelectDistrict();
                    request.setAttribute("DistrictArrayList", DistrictArrayList);
                    break;
            }
            RequestDispatcher dispatcher = request.getRequestDispatcher("/WEB-INF/adminWeb.jsp");
            dispatcher.forward(request, response);
        }
        catch(Exception e)
        {
            System.out.println(e);
        }
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("UTF-8");
        response.setContentType("text/html;charset=UTF-8");
        try {
            String pageName = request.getParameter("pageName");
            switch (pageName)
            {
                case "Majors":
                {String hjy_Mno230128 = request.getParameter("hjy_MnoMajors230128");
                    String hjy_Mname230128 = request.getParameter("hjy_MnameMajors230128");
                    new AdminDaoImpl().InsertMajors(hjy_Mno230128, hjy_Mname230128);}break;
                case "Classes":
                {String hjy_Clno230128 = request.getParameter("hjy_Clnoclasses230128");
                    String hjy_Clname230128 = request.getParameter("hjy_Clnameclasses230128");
                    String hjy_Mno230128 = request.getParameter("hjy_Mnoclasses230128");
                    new AdminDaoImpl().InsertClasses(hjy_Clno230128, hjy_Clname230128, hjy_Mno230128);}break;
                case "Teachers":
                {String hjy_Tno230128 = request.getParameter("hjy_TnoTeachers230128");
                    String hjy_Tname230128 = request.getParameter("hjy_TnameTeachers230128");
                    String hjy_Tsex230128 = request.getParameter("hjy_TsexTeachers230128");
                    int hjy_Tage230128 = Integer.parseInt(request.getParameter("hjy_TageTeachers230128"));
                    String hjy_Tphone230128 = request.getParameter("hjy_TphoneTeachers230128");
                    String hjy_Tprof230128 = request.getParameter("hjy_TprofTeachers230128");
                    String hjy_Tpassword230128 = request.getParameter("hjy_TpasswordTeachers230128");
                    new AdminDaoImpl().InsertTeachers(hjy_Tno230128,  hjy_Tname230128,  hjy_Tsex230128,  hjy_Tage230128
            ,  hjy_Tphone230128,  hjy_Tprof230128,  hjy_Tpassword230128);}break;
                case "Students":
                {String hjy_Sno230128 = request.getParameter("hjy_SnoStudents230128");
                    String hjy_Sname230128 = request.getParameter("hjy_SnameStudents230128");
                    String hjy_Ssex230128 = request.getParameter("hjy_SsexStudents230128");
                    int hjy_Sage230128 = Integer.parseInt(request.getParameter("hjy_SageStudents230128"));
                    double hjy_Scredits230128 = Double.parseDouble(request.getParameter("hjy_ScreditsStudents230128")) ;
                    String hjy_Slocation230128 = request.getParameter("hjy_SlocationStudents230128");
                    String hjy_Spassword230128 = request.getParameter("hjy_SpasswordStudents230128");
                    String hjy_Clno230128 = request.getParameter("hjy_ClnoStudents230128");
                    double hjy_Sscore230128 = Double.parseDouble(request.getParameter("hjy_SscoreStudents230128"));
                    new AdminDaoImpl().InsertStudents( hjy_Sno230128,   hjy_Sname230128,  hjy_Ssex230128,  hjy_Sage230128,  hjy_Scredits230128,
                     hjy_Slocation230128,  hjy_Spassword230128,  hjy_Clno230128,  hjy_Sscore230128);}break;
                case "Courses":
                {String hjy_Cno230128 = request.getParameter("hjy_CnoCourses230128");
                    String hjy_Clno230128 = request.getParameter("hjy_ClnoCourses230128");
                    String hjy_Cname230128 = request.getParameter("hjy_CnameCourses230128");
                    double hjy_Ccredit230128 = Double.parseDouble(request.getParameter("hjy_CcreditCourses230128"));
                    String hjy_Cevaluation230128 = request.getParameter("hjy_CevaluationCourses230128");
                    String hjy_Cterm230128 = request.getParameter("hjy_CtermCourses230128");
                    int hjy_Cperiod230128 = Integer.parseInt(request.getParameter("hjy_CperiodCourses230128"));
                    new AdminDaoImpl().InsertCourses( hjy_Cno230128,  hjy_Clno230128,  hjy_Cname230128,
                     hjy_Ccredit230128,  hjy_Cevaluation230128,  hjy_Cterm230128,  hjy_Cperiod230128);}break;
                case "SC":
                {String hjy_Sno230128 = request.getParameter("hjy_SnoSC230128");
                    String hjy_Cno230128 = request.getParameter("hjy_CnoSC230128");
                    String hjy_Clno230128 = request.getParameter("hjy_ClnoSC230128");
                    String hjy_SCyear230128 = request.getParameter("hjy_SCyearSC230128");
                    int hjy_SCscore230128 = Integer.parseInt(request.getParameter("hjy_SCscore230128"));
                    new AdminDaoImpl().InsertSC(hjy_Sno230128, hjy_Cno230128, hjy_Clno230128, hjy_SCyear230128, hjy_SCscore230128 );}break;
                case "TC":
                {String hjy_Tno230128 = request.getParameter("hjy_TnoTC230128");
                    String hjy_Cno230128 = request.getParameter("hjy_CnoTC230128");
                    String hjy_Clno230128 = request.getParameter("hjy_ClnoTC230128");
                    String hjy_TCyear230128 = request.getParameter("hjy_TCyearTC230128");
                    new AdminDaoImpl().InsertTC(hjy_Tno230128, hjy_Cno230128, hjy_Clno230128, hjy_TCyear230128);}break;
                case "Province":
                {String hjy_Pno230128 = request.getParameter("hjy_PnoProvince230128");
                    String hjy_Pname230128 = request.getParameter("hjy_PnameProvince230128");
                    new AdminDaoImpl().InsertProvince(hjy_Pno230128, hjy_Pname230128);}break;
                case "City":
                {String hjy_Cino230128 = request.getParameter("hjy_CinoCity230128");
                    String hjy_Ciname230128 = request.getParameter("hjy_CinameCity230128");
                    String hjy_Pno230128 = request.getParameter("hjy_PnoCity230128");
                    new AdminDaoImpl().InsertCity(hjy_Cino230128, hjy_Ciname230128, hjy_Pno230128);}break;
                case "District":
                {String hjy_Dno230128 = request.getParameter("hjy_DnoDistrict230128");
                    String hjy_Dname230128 = request.getParameter("hjy_DnameDistrict230128");
                    String hjy_Cino230128 = request.getParameter("hjy_CinoDistrict230128");
                    new AdminDaoImpl().InsertDistrict(hjy_Dno230128, hjy_Dname230128, hjy_Cino230128);}break;
            }

            request.setAttribute("pageName", "adminMyPage");
            RequestDispatcher dispatcher = request.getRequestDispatcher("/WEB-INF/adminWeb.jsp");
            dispatcher.forward(request,response);
//            String hjy_Mno230128, String hjy_Mname230128

//            String hjy_Clno230128, String hjy_Clname230128, String hjy_Mno230128

//            String hjy_Tno230128, String hjy_Tname230128, String hjy_Tsex230128,int hjy_Tage230128
//            ,String hjy_Tphone230128, String hjy_Tprof230128, String hjy_Tpassword230128

//            String hjy_Sno230128, String hjy_Sname230128, String hjy_Ssex230128,int hjy_Sage230128, double hjy_Scredits230128,
//            String hjy_Slocation230128, String hjy_Spassword230128, String hjy_Clno230128,double hjy_Sscore230128

//            String hjy_Cno230128, String hjy_Clno230128, String hjy_Cname230128,
//            double hjy_Ccredit230128, String hjy_Cevaluation230128, String hjy_Cterm230128,int hjy_Cperiod230128

//            String hjy_Sno230128, String hjy_Cno230128, String hjy_Clno230128, String hjy_SCyear230128,int hjy_SCscore230128

//            String hjy_Tno230128, String hjy_Cno230128, String hjy_Clno230128, String hjy_TCyear230128

//            String hjy_Pno230128, String hjy_Pname230128

//            String hjy_Cino230128, String hjy_Ciname230128, String hjy_Pno230128

//            String hjy_Dno230128, String hjy_Dname230128, String hjy_Cino230128
        }
        catch(Exception e)
        {
            System.out.println(e);
        }
    }
}

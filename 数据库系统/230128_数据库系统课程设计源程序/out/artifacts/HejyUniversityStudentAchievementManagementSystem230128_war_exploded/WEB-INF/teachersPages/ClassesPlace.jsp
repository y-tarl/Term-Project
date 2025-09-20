<%@ page import="com.model.student.stuGrade" %>
<%@ page import="java.util.ArrayList" %>
<%@ page import="com.model.teacher.ClassesPlace" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%
    ArrayList<ClassesPlace> ClassesArrayList =  (ArrayList<ClassesPlace>)request.getAttribute("ClassesPlaceArrayList");
    ArrayList<String> teachersCourses_ClassesPlace =  (ArrayList<String>)request.getAttribute("teachersCourses_ClassesPlace");
%>
<div class="container-fluid" id="table_class" style="margin-top: 20px" >
    <h3 class="text-dark mb-4">学生班级排名概览</h3>
    <div class="card shadow">
        <div class="card-header py-3">
            <p class="text-primary m-0 font-weight-bold"></p>
        </div>
        <div class="card-body">
            <form action="ClassesPlace.do" method="post">
                <div class="row">
                    <div class="col-md-6 text-nowrap">
                        <div id="dataTable_length" class="dataTables_length" aria-controls="dataTable">
                            <label style="margin-right: 40px">数量
                                <select class="form-control form-control-sm custom-select custom-select-sm">
                                    <option value="10" selected="">10</option>
                                    <option value="25">25</option>
                                    <option value="50">50</option>
                                    <option value="100">100</option>
                                </select>&nbsp;
                            </label>
                            <label style="margin-right: 40px">课程
                                <select name="teachersClasses_Place" class="form-control form-control-sm custom-select custom-select-sm">
                                    <option value="请选择" selected="selected">请选择</option>
                                    <% for(int i=0;i<teachersCourses_ClassesPlace.size();++i)
                                    { %>
                                    <option value="<%= teachersCourses_ClassesPlace.get(i)%>"><%= teachersCourses_ClassesPlace.get(i)%></option>
                                    <% }%>
                                </select>&nbsp;
                            </label>
                        </div>
                        <input name="operationNumber" type="hidden" value="1">
                    </div>
                    <div class="col-md-6">
                        <div class="text-md-right dataTables_filter" id="dataTable_filter">
                            <label><button type="submit" class="form-control form-control-sm">搜索</button></label>
                        </div>
                    </div>
                </div>
            </form>
            <div class="table-responsive table mt-2" id="dataTable6" role="grid" aria-describedby="dataTable_info">
                <table class="table my-0" id="dataTable">
                    <thead>
                    <tr id="form_title">
                        <th>学生学号</th>
                        <th>学生姓名</th>
                        <th>学生性别</th>
                        <th>绩点</th>
                        <th>班级号</th>
                        <th>班级名</th>
                    </tr>
                    </thead>
                    <tbody>
                    <%
                        if(ClassesArrayList!=null)
                        {
                            for(int i=0; i<ClassesArrayList.size(); ++i)
                            {
                                ClassesPlace coD = ClassesArrayList.get(i);

                    %>
                    <tr>
                        <td><%= coD.getSno()%></td>
                        <td><%= coD.getSname()%></td>
                        <td><%= coD.getSsex()%></td>
                        <td><%= coD.getSscore()%></td>
                        <td><%= coD.getClno()%></td>
                        <td><%= coD.getClname()%></td>

                    </tr>
                    <%      }
                    }else{
                    %>
                    <tr><td> </td></tr>
                    <%
                        }
                    %>
                    </tbody>
                </table>
            </div>
            <div class="row">
                <div class="col-md-6 align-self-center">
                    <p id="dataTable_info" class="dataTables_info" role="status" aria-live="polite">第1页</p>
                </div>
                <div class="col-md-6">
                    <nav class="d-lg-flex justify-content-lg-end dataTables_paginate paging_simple_numbers">
                        <ul class="pagination">
                            <li class="page-item disabled"><a class="page-link" href="#" aria-label="Previous"><span aria-hidden="true">«</span></a></li>
                            <li class="page-item active"><a class="page-link" href="#">1</a></li>
                            <li class="page-item"><a class="page-link" href="#">2</a></li>
                            <li class="page-item"><a class="page-link" href="#">3</a></li>
                            <li class="page-item"><a class="page-link" href="#" aria-label="Next"><span aria-hidden="true">»</span></a></li>
                        </ul>
                    </nav>
                </div>
            </div>
        </div>
    </div>
</div>



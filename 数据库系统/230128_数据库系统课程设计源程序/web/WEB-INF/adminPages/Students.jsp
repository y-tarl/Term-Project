<%@ page import="com.model.admin.Students" %>

<%@ page contentType="text/html;charset=UTF-8" language="java" %>

<div class="container-fluid" id="table_class" style="margin-top: 20px" >
    <h3 class="text-dark mb-4">学生表管理</h3>
    <div class="card shadow">
        <div class="card-header py-3">
            <p class="text-primary m-0 font-weight-bold">录入</p>
        </div>
        <form action="Admin.do" method="post">
        <div class="card-body">

                <div class="row">
                    <div class="col-md-6 text-nowrap">
                        <div id="dataTable_length" class="dataTables_length" aria-controls="dataTable">

                        </div>
                        <input name="pageName" type="hidden" value="Students">
                    </div>
                    <div class="col-md-6">
                        <div class="text-md-right dataTables_filter" id="dataTable_filter">
                            <label><button onclick="return confirm('确定要提交吗？');" type="submit" class="form-control form-control-sm">提交</button></label>
                        </div>
                    </div>
                </div>

            <div class="table-responsive table mt-2" id="dataTable1234" role="grid" aria-describedby="dataTable_info">
                <table class="table my-0" id="dataTable567">
                    <thead>
                    <tr id="form_title4">
                        <th>学号</th>
                        <th>姓名</th>
                        <th>性别</th>
                        <th>年龄</th>
                        <th>已修学分</th>
                        <th>生源地编号</th>
                        <th>密码</th>
                        <th>班级号</th>
                        <th>当前绩点</th>

                    </tr>
                    </thead>
                    <tbody>
                    <tr>
                        <td><input class="form-control" type="text" name="hjy_SnoStudents230128" ></td>
                        <td><input class="form-control" type="text" name="hjy_SnameStudents230128" ></td>
                        <td><input class="form-control" type="text" name="hjy_SsexStudents230128" ></td>
                        <td><input class="form-control" type="text" name="hjy_SageStudents230128" ></td>
                        <td><input class="form-control" type="text" name="hjy_ScreditsStudents230128" ></td>
                        <td><input class="form-control" type="text" name="hjy_SlocationStudents230128" ></td>
                        <td><input class="form-control" type="text" name="hjy_SpasswordStudents230128" ></td>
                        <td><input class="form-control" type="text" name="hjy_ClnoStudents230128" ></td>
                        <td><input class="form-control" type="text" name="hjy_SscoreStudents230128" ></td>
                    </tr>
                    </tbody>
                </table>
            </div>
            <div class="row">

            </div>
        </div>
        </form>


    </div>
    <h3 class="text-dark mb-4"></h3>
    <div class="card shadow">
        <div class="card-header py-3">
            <p class="text-primary m-0 font-weight-bold">更新</p>
        </div>
        <% ArrayList<Students> StudentsArrayList = (ArrayList<Students>)request.getAttribute("StudentsArrayList"); %>
        <div class="table-responsive table mt-2" id="dataTable" role="grid" aria-describedby="dataTable_info">
            <form action="AdminUpdateAndDelete.do" method="post" id="myForm">

                <table class="table my-0" id="dataTable12345">
                    <thead>
                    <tr id="form_title">
                        <th>学生学号</th>
                        <th>学生姓名</th>
                        <th>学生性别</th>
                        <th>年龄</th>
                        <th>已修学分</th>
                        <th>生源地编号</th>
                        <th>密码</th>
                        <th>班级号</th>
                        <th>绩点</th>
                        <th>操作</th>
                    </tr>
                    </thead>
                    <tbody>

                    <%
                        if(StudentsArrayList!=null)
                        {
                            for(int i=0; i<StudentsArrayList.size(); ++i)
                            {
                                Students coD = StudentsArrayList.get(i);

                    %>


                    <tr>
                        <input class="form-control" type="hidden" id="hjy_SnoStudents230128<%=i%>" name="hjy_SnoStudents230128<%=i%>" value="<%= coD.gethjy_Sno230128()%>" readOnly="true">
                        <td ><%= coD.gethjy_Sno230128()%></td>
                        <td><input class="form-control" type="text" id="hjy_SnameStudents230128<%=i%>" name="hjy_SnameStudents230128<%=i%>" value="<%= coD.gethjy_Sname230128()%>"></td>
                        <td><input class="form-control" type="text" id="hjy_SsexStudents230128<%=i%>" name="hjy_SsexStudents230128<%=i%>" value="<%= coD.gethjy_Ssex230128()%>"></td>
                        <td><input class="form-control" type="text" id="hjy_SageStudents230128<%=i%>" name="hjy_SageStudents230128<%=i%>" value="<%= coD.gethjy_Sage230128()%>"></td>
                        <td><input readOnly="true" class="form-control" type="text" id="hjy_ScreditsStudents230128<%=i%>" name="hjy_ScreditsStudents230128<%=i%>" value="<%= coD.gethjy_Scredits230128()%>"></td>
                        <td><input class="form-control" type="text" id="hjy_SlocationStudents230128<%=i%>" name="hjy_SlocationStudents230128<%=i%>" value="<%= coD.gethjy_Slocation230128()%>"></td>
                        <td><input class="form-control" type="text" id="hjy_SpasswordStudents230128<%=i%>" name="hjy_SpasswordStudents230128<%=i%>" value="<%= coD.gethjy_Spassword230128()%>"></td>
                        <td><input class="form-control" type="text" id="hjy_ClnoStudents230128<%=i%>" name="hjy_ClnoStudents230128<%=i%>" value="<%= coD.gethjy_Clno230128()%>"></td>
                        <td><input readOnly="true" class="form-control" type="text" id="hjy_SscoreStudents230128<%=i%>" name="hjy_SscoreStudents230128<%=i%>" value="<%= coD.gethjy_Sscore230128()%>"></td>
                        <td>
                            <label><input onclick="return submitFun<%=i%>('edit');" type="button" class="form-control form-control-sm" value="更新"></label>
                            <label><input onclick="return submitFun<%=i%>('del');" type="button" class="form-control form-control-sm" value="删除"></label>
                        </td>
                        <script>
                            function submitFun<%=i%>(act)
                            {
                                if(confirm('确定要提交吗？') === false)
                                {
                                    return false;
                                }
                                document.getElementById("hidden").value = act;

                                document.getElementById("hjy_SnoStudents230128").value = document.getElementById("hjy_SnoStudents230128<%=i%>").value;
                                document.getElementById("hjy_SnameStudents230128").value = document.getElementById("hjy_SnameStudents230128<%=i%>").value;
                                document.getElementById("hjy_SageStudents230128").value = document.getElementById("hjy_SageStudents230128<%=i%>").value;
                                document.getElementById("hjy_ScreditsStudents230128").value = document.getElementById("hjy_ScreditsStudents230128<%=i%>").value;
                                document.getElementById("hjy_SlocationStudents230128").value = document.getElementById("hjy_SlocationStudents230128<%=i%>").value;
                                document.getElementById("hjy_SpasswordStudents230128").value = document.getElementById("hjy_SpasswordStudents230128<%=i%>").value;
                                document.getElementById("hjy_SsexStudents230128").value = document.getElementById("hjy_SsexStudents230128<%=i%>").value;
                                document.getElementById("hjy_ClnoStudents230128").value = document.getElementById("hjy_ClnoStudents230128<%=i%>").value;
                                document.getElementById("hjy_SscoreStudents230128").value = document.getElementById("hjy_SscoreStudents230128<%=i%>").value;


                                document.getElementById("myForm").submit();
                                return true;
                            }
                        </script>
                    </tr>


                    <%      }
                    }else{
                    %>
                    <tr><td> </td></tr>
                    <%
                        }
                    %>

                    </tbody>
                    <tfoot>
                    <tr>
                        <th>学生学号</th>
                        <th>学生姓名</th>
                        <th>学生性别</th>
                        <th>年龄</th>
                        <th>已修学分</th>
                        <th>生源地编号</th>
                        <th>密码</th>
                        <th>班级号</th>
                        <th>绩点</th>
                        <th>操作</th>
                    </tr>
                    </tfoot>
                </table>
                <input name="pageName" type="hidden" value="Students">
                <input type="hidden" id="hidden" name="hidden">


                <input class="form-control" type="hidden" id="hjy_SnoStudents230128" name="hjy_SnoStudents230128"  readOnly="true">
                <input class="form-control" type="hidden" id="hjy_SnameStudents230128" name="hjy_SnameStudents230128" >
                <input class="form-control" type="hidden" id="hjy_SsexStudents230128" name="hjy_SsexStudents230128" >
                <input class="form-control" type="hidden" id="hjy_SageStudents230128" name="hjy_SageStudents230128" >
                <input class="form-control" type="hidden" id="hjy_ScreditsStudents230128" name="hjy_ScreditsStudents230128" >
                <input class="form-control" type="hidden" id="hjy_SlocationStudents230128" name="hjy_SlocationStudents230128" >
                <input class="form-control" type="hidden" id="hjy_SpasswordStudents230128" name="hjy_SpasswordStudents230128" >
                <input class="form-control" type="hidden" id="hjy_ClnoStudents230128" name="hjy_ClnoStudents230128" >
                <input class="form-control" type="hidden" id="hjy_SscoreStudents230128" name="hjy_SscoreStudents230128" >

            </form>
        </div>

    </div>
</div>


<%@ page import="com.model.admin.Teachers" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>

<div class="container-fluid" id="table_class" style="margin-top: 20px" >
    <h3 class="text-dark mb-4">教师表录入</h3>
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
                        <input name="pageName" type="hidden" value="Teachers">
                    </div>
                    <div class="col-md-6">
                        <div class="text-md-right dataTables_filter" id="dataTable_filter">
                            <label><button onclick="return confirm('确定要提交吗？');" type="submit" class="form-control form-control-sm">提交</button></label>
                        </div>
                    </div>
                </div>

            <div class="table-responsive table mt-2" id="dataTable111" role="grid" aria-describedby="dataTable_info">
                <table class="table my-0" id="dataTable1111">
                    <thead>
                    <tr id="form_title111">
                        <th>教师号</th>
                        <th>教师名</th>
                        <th>性别</th>
                        <th>年龄</th>
                        <th>电话</th>
                        <th>职称</th>
                        <th>密码</th>

                    </tr>
                    </thead>
                    <tbody>
                    <tr>
                        <td><input class="form-control" type="text" name="hjy_TnoTeachers230128" ></td>
                        <td><input class="form-control" type="text" name="hjy_TnameTeachers230128" ></td>
                        <td><input class="form-control" type="text" name="hjy_TsexTeachers230128" ></td>
                        <td><input class="form-control" type="text" name="hjy_TageTeachers230128" ></td>
                        <td><input class="form-control" type="text" name="hjy_TphoneTeachers230128" ></td>
                        <td><input class="form-control" type="text" name="hjy_TprofTeachers230128" ></td>
                        <td><input class="form-control" type="text" name="hjy_TpasswordTeachers230128" ></td>
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
        <% ArrayList<Teachers> TeachersArrayList = (ArrayList<Teachers>)request.getAttribute("TeachersArrayList"); %>
        <div class="table-responsive table mt-2" id="dataTable" role="grid" aria-describedby="dataTable_info">
            <form action="AdminUpdateAndDelete.do" method="post" id="myForm">

                <table class="table my-0" id="dataTable2222">
                    <thead>
                    <tr id="form_title">
                        <th>教师编号</th>
                        <th>教师姓名</th>
                        <th>教师性别</th>
                        <th>年龄</th>
                        <th>联系方式</th>
                        <th>职称</th>
                        <th>密码</th>
                        <th>操作</th>
                    </tr>
                    </thead>
                    <tbody>
                    <%
                        if(TeachersArrayList!=null)
                        {
                            for(int i=0; i<TeachersArrayList.size(); ++i)
                            {
                                Teachers coD = TeachersArrayList.get(i);

                    %>


                    <tr>
                        <input class="form-control" type="hidden" id="hjy_TnoTeachers230128<%=i%>" name="hjy_TnoTeachers230128<%=i%>" value="<%= coD.gethjy_Tno230128()%>" readOnly="true">
                        <td ><%= coD.gethjy_Tno230128()%></td>
                        <td><input class="form-control" type="text" id="hjy_TnameTeachers230128<%=i%>" name="hjy_TnameTeachers230128<%=i%>" value="<%= coD.gethjy_Tname230128()%>"></td>
                        <td><input class="form-control" type="text" id="hjy_TsexTeachers230128<%=i%>" name="hjy_TsexTeachers230128<%=i%>" value="<%= coD.gethjy_Tsex230128()%>"></td>
                        <td><input class="form-control" type="text" id="hjy_TageTeachers230128<%=i%>" name="hjy_TageTeachers230128<%=i%>" value="<%= coD.gethjy_Tage230128()%>"></td>
                        <td><input class="form-control" type="text" id="hjy_TphoneTeachers230128<%=i%>" name="hjy_TphoneTeachers230128<%=i%>" value="<%= coD.gethjy_Tphone230128()%>"></td>
                        <td><input class="form-control" type="text" id="hjy_TprofTeachers230128<%=i%>" name="hjy_TprofTeachers230128<%=i%>" value="<%= coD.gethjy_Tprof230128()%>"></td>
                        <td><input class="form-control" type="text" id="hjy_TpasswordTeachers230128<%=i%>" name="hjy_TpasswordTeachers230128<%=i%>" value="<%= coD.gethjy_Tpassword230128()%>"></td>
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

                                document.getElementById("hjy_TnoTeachers230128").value = document.getElementById("hjy_TnoTeachers230128<%=i%>").value;
                                document.getElementById("hjy_TnameTeachers230128").value = document.getElementById("hjy_TnameTeachers230128<%=i%>").value;
                                document.getElementById("hjy_TsexTeachers230128").value = document.getElementById("hjy_TsexTeachers230128<%=i%>").value;
                                document.getElementById("hjy_TageTeachers230128").value = document.getElementById("hjy_TageTeachers230128<%=i%>").value;
                                document.getElementById("hjy_TphoneTeachers230128").value = document.getElementById("hjy_TphoneTeachers230128<%=i%>").value;
                                document.getElementById("hjy_TprofTeachers230128").value = document.getElementById("hjy_TprofTeachers230128<%=i%>").value;
                                document.getElementById("hjy_TpasswordTeachers230128").value = document.getElementById("hjy_TpasswordTeachers230128<%=i%>").value;


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
                        <th>教师编号</th>
                        <th>教师姓名</th>
                        <th>教师性别</th>
                        <th>年龄</th>
                        <th>联系方式</th>
                        <th>职称</th>
                        <th>密码</th>
                        <th>操作</th>
                    </tr>
                    </tfoot>
                </table>
                <input name="pageName" type="hidden" value="Teachers">
                <input type="hidden" id="hidden" name="hidden">

                <input class="form-control" type="hidden" id="hjy_TnoTeachers230128" name="hjy_TnoTeachers230128"  readOnly="true">
                <input class="form-control" type="hidden" id="hjy_TnameTeachers230128" name="hjy_TnameTeachers230128" >
                <input class="form-control" type="hidden" id="hjy_TsexTeachers230128" name="hjy_TsexTeachers230128" >
                <input class="form-control" type="hidden" id="hjy_TageTeachers230128" name="hjy_TageTeachers230128" >
                <input class="form-control" type="hidden" id="hjy_TphoneTeachers230128" name="hjy_TphoneTeachers230128" >
                <input class="form-control" type="hidden" id="hjy_TprofTeachers230128" name="hjy_TprofTeachers230128" >
                <input class="form-control" type="hidden" id="hjy_TpasswordTeachers230128" name="hjy_TpasswordTeachers230128" >

            </form>
        </div>

    </div>
</div>


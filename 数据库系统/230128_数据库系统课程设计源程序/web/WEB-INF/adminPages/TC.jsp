<%@ page import="com.model.admin.TC" %><%--
  Created by IntelliJ IDEA.
  User: ASUS
  Date: 2171/7/18
  Time: 19:32
  To change this template use File | Settings | File Templates.
--%>

<%@ page contentType="text/html;charset=UTF-8" language="java" %>

<div class="container-fluid" id="table_class" style="margin-top: 20px" >
    <h3 class="text-dark mb-4">教师任课新增</h3>
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
                        <input name="pageName" type="hidden" value="TC">
                    </div>
                    <div class="col-md-6">
                        <div class="text-md-right dataTables_filter" id="dataTable_filter">
                            <label><button onclick="return confirm('确定要提交吗？');" type="submit" class="form-control form-control-sm">提交</button></label>
                        </div>
                    </div>
                </div>

            <div class="table-responsive table mt-2" id="dataTable33333" role="grid" aria-describedby="dataTable_info">
                <table class="table my-0" id="dataTable4444">
                    <thead>
                    <tr id="form_title5555">
                        <th>教师编号</th>
                        <th>课程号</th>
                        <th>班级号</th>
                        <th>授课学年</th>

                    </tr>
                    </thead>
                    <tbody>
                    <tr>
                        <td><input class="form-control" type="text" name="hjy_TnoTC230128" ></td>
                        <td><input class="form-control" type="text" name="hjy_CnoTC230128" ></td>
                        <td><input class="form-control" type="text" name="hjy_ClnoTC230128" ></td>
                        <td><input class="form-control" type="text" name="hjy_TCyearTC230128" ></td>

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
        <% ArrayList<TC> TCArrayList = (ArrayList<TC>)request.getAttribute("TCArrayList"); %>
        <div class="table-responsive table mt-2" id="dataTable" role="grid" aria-describedby="dataTable_info">
            <form action="AdminUpdateAndDelete.do" method="post" id="myForm">

                <table class="table my-0" id="dataTable6666">
                    <thead>
                    <tr id="form_title">
                        <th>教师编号</th>
                        <th>课程编号</th>
                        <th>授课班级编号</th>
                        <th>开课学年</th>
                        <th>操作</th>

                    </tr>
                    </thead>
                    <tbody>


                    <%
                        if(TCArrayList!=null)
                        {
                            for(int i=0; i<TCArrayList.size(); ++i)
                            {
                                TC coD = TCArrayList.get(i);

                    %>


                    <tr>
                        <input class="form-control" type="hidden" id="hjy_TnoTC230128<%=i%>" name="hjy_TnoTC230128<%=i%>" value="<%= coD.gethjy_Tno230128()%>" readOnly="true">
                        <input class="form-control" type="hidden" id="hjy_CnoTC230128<%=i%>" name="hjy_CnoTC230128<%=i%>" value="<%= coD.gethjy_Cno230128()%>" readOnly="true">
                        <input class="form-control" type="hidden" id="hjy_ClnoTC230128<%=i%>" name="hjy_ClnoTC230128<%=i%>" value="<%= coD.gethjy_Clno230128()%>" readOnly="true">
                        <input class="form-control" type="hidden" id="hjy_TCyearTC230128<%=i%>" name="hjy_TCyearTC230128<%=i%>" value="<%= coD.gethjy_TCyear230128()%>" readOnly="true">

                        <td ><%= coD.gethjy_Tno230128()%></td>
                        <td ><%= coD.gethjy_Cno230128()%></td>
                        <td ><%= coD.gethjy_Clno230128()%></td>
                        <td ><%= coD.gethjy_TCyear230128()%></td>
                        <td>
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

                                document.getElementById("hjy_TnoTC230128").value = document.getElementById("hjy_TnoTC230128<%=i%>").value;
                                document.getElementById("hjy_CnoTC230128").value = document.getElementById("hjy_CnoTC230128<%=i%>").value;
                                document.getElementById("hjy_ClnoTC230128").value = document.getElementById("hjy_ClnoTC230128<%=i%>").value;
                                document.getElementById("hjy_TCyearTC230128").value = document.getElementById("hjy_TCyearTC230128<%=i%>").value;


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
                        <th>课程编号</th>
                        <th>授课班级编号</th>
                        <th>开课学年</th>
                        <th>操作</th>
                    </tr>
                    </tfoot>
                </table>
                <input name="pageName" type="hidden" value="TC">
                <input type="hidden" id="hidden" name="hidden">

                <input class="form-control" type="hidden" id="hjy_TnoTC230128" name="hjy_TnoTC230128"  readOnly="true">
                <input class="form-control" type="hidden" id="hjy_CnoTC230128" name="hjy_CnoTC230128"  readOnly="true">
                <input class="form-control" type="hidden" id="hjy_ClnoTC230128" name="hjy_ClnoTC230128"  readOnly="true">
                <input class="form-control" type="hidden" id="hjy_TCyearTC230128" name="hjy_TCyearTC230128"  readOnly="true">

            </form>
        </div>

    </div>
</div>


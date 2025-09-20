<%@ page import="com.model.admin.City" %>
<%@ page import="java.util.ArrayList" %>

<%@ page contentType="text/html;charset=UTF-8" language="java" %>

<div class="container-fluid" id="table_class" style="margin-top: 20px" >
    <h3 class="text-dark mb-4">市表管理</h3>
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
                        <input name="pageName" type="hidden" value="City">
                    </div>
                    <div class="col-md-6">
                        <div class="text-md-right dataTables_filter" id="dataTable_filter">
                            <label><button onclick="return confirm('确定要提交吗？');" type="submit" class="form-control form-control-sm">提交</button></label>
                        </div>
                    </div>
                </div>

            <div class="table-responsive table mt-2" id="dataTable123" role="grid" aria-describedby="dataTable_info">
                <table class="table my-0" id="dataTable456">
                    <thead>
                    <tr id="form_title777">
                        <th>城市编号</th>
                        <th>城市名称</th>
                        <th>省份编号</th>


                    </tr>
                    </thead>
                    <tbody>
                    <tr>
                        <td><input class="form-control" type="text" name="hjy_CinoCity230128" ></td>
                        <td><input class="form-control" type="text" name="hjy_CinameCity230128" ></td>
                        <td><input class="form-control" type="text" name="hjy_PnoCity230128" ></td>

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
        <% ArrayList<City> CityArrayList = (ArrayList<City>)request.getAttribute("CityArrayList"); %>
        <div class="table-responsive table mt-2" id="dataTable" role="grid" aria-describedby="dataTable_info">
            <form action="AdminUpdateAndDelete.do" method="post" id="myForm">
                <table class="table my-0" id="dataTable789">
                    <thead>
                    <tr id="form_title">
                        <th>城市编号</th>
                        <th>城市名</th>
                        <th>所属省编号</th>
                        <th>操作</th>

                    </tr>
                    </thead>
                    <tbody>
                    <%
                        if(CityArrayList!=null)
                        {
                            for(int i=0; i<CityArrayList.size(); ++i)
                            {
                                City coD = CityArrayList.get(i);

                    %>

                    <tr>


                        <input class="form-control" type="hidden" id="hjy_CinoCity230128<%=i%>" name="hjy_CinoCity230128<%=i%>" value="<%= coD.gethjy_Cino230128()%>" readOnly="true">

                        <td ><%= coD.gethjy_Cino230128()%></td>
                        <td><input class="form-control" type="text" id="hjy_CinameCity230128<%=i%>" name="hjy_CinameCity230128<%=i%>" value="<%= coD.gethjy_Ciname230128()%>"></td>
                        <td><input class="form-control" type="text" id="hjy_PnoCity230128<%=i%>" name="hjy_PnoCity230128<%=i%>" value="<%= coD.gethjy_Pno230128()%>"></td>
                        <td>
                            <label><input onclick="return submitFun<%=i%>('edit');" type="button" class="form-control form-control-sm" value="更新"></label>
                            <label><input onclick="return submitFun<%=i%>('del');" type="button" class="form-control form-control-sm" value="删除"></label>
                        </td>




                    </tr>
                    <script>
                        function submitFun<%=i%>(act)
                        {
                            if(confirm('确定要提交吗？') === false)
                            {
                                return false;
                            }
                            document.getElementById("hidden").value = act;



                            document.getElementById("hjy_CinoCity230128").value = document.getElementById("hjy_CinoCity230128<%=i%>").value;
                            document.getElementById("hjy_CinameCity230128").value = document.getElementById("hjy_CinameCity230128<%=i%>").value;
                            document.getElementById("hjy_PnoCity230128").value = document.getElementById("hjy_PnoCity230128<%=i%>").value;


                            document.getElementById("myForm").submit();
                            return true;
                        }
                    </script>
                    <%      }
                    }else{
                    %>
                    <tr><td> </td></tr>
                    <%
                        }
                    %>
                    </tbody>

                </table>
                <input name="pageName" type="hidden" value="City">
                <input type="hidden" id="hidden" name="hidden">
                <input class="form-control" type="hidden" id="hjy_CinoCity230128" name="hjy_CinoCity230128"  readOnly="true">
                <input class="form-control" type="hidden" id="hjy_CinameCity230128" name="hjy_CinameCity230128" >
                <input class="form-control" type="hidden" id="hjy_PnoCity230128" name="hjy_PnoCity230128" >

            </form>
        </div>

    </div>
</div>


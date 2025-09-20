<%@ page import="com.model.admin.Province" %>

<%@ page contentType="text/html;charset=UTF-8" language="java" %>

<div class="container-fluid" id="table_class" style="margin-top: 20px" >
    <h3 class="text-dark mb-4">省表管理</h3>
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
                        <input name="pageName" type="hidden" value="Province">
                    </div>
                    <div class="col-md-6">
                        <div class="text-md-right dataTables_filter" id="dataTable_filter">
                            <label><button onclick="return confirm('确定要提交吗？');" type="submit" class="form-control form-control-sm">提交</button></label>
                        </div>
                    </div>
                </div>

            <div class="table-responsive table mt-2" id="dataTable555" role="grid" aria-describedby="dataTable_info">
                <table class="table my-0" id="dataTable4444">
                    <thead>
                    <tr id="form_title77">
                        <th>省份编号</th>
                        <th>省份名称</th>

                    </tr>
                    </thead>
                    <tbody>
                    <tr>
                        <td><input class="form-control" type="text" name="hjy_PnoProvince230128" ></td>
                        <td><input class="form-control" type="text" name="hjy_PnameProvince230128" ></td>


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
        <% ArrayList<Province> ProvinceArrayList = (ArrayList<Province>)request.getAttribute("ProvinceArrayList"); %>
        <div class="table-responsive table mt-2" id="dataTable" role="grid" aria-describedby="dataTable_info">
            <form action="AdminUpdateAndDelete.do" method="post" id="myForm">

                <table class="table my-0" id="dataTable888">
                    <thead>
                    <tr id="form_title">
                        <th>省份编号</th>
                        <th>省份名称</th>
                        <th>操作</th>

                    </tr>
                    </thead>
                    <tbody>
                    <%
                        if(ProvinceArrayList!=null)
                        {
                            for(int i=0; i<ProvinceArrayList.size(); ++i)
                            {
                                Province coD = ProvinceArrayList.get(i);

                    %>


                    <tr>
                        <input class="form-control" type="hidden" id="hjy_PnoProvince230128<%=i%>" name="hjy_PnoProvince230128<%=i%>" value="<%= coD.gethjy_Pno230128()%>" readOnly="true">

                        <td ><%= coD.gethjy_Pno230128()%></td>
                        <td><input class="form-control" type="text" id="hjy_PnameProvince230128<%=i%>" name="hjy_PnameProvince230128<%=i%>" value="<%= coD.gethjy_Pname230128()%>"></td>

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

                                document.getElementById("hjy_PnoProvince230128").value = document.getElementById("hjy_PnoProvince230128<%=i%>").value;
                                document.getElementById("hjy_PnameProvince230128").value = document.getElementById("hjy_PnameProvince230128<%=i%>").value;


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

                </table>
                <input name="pageName" type="hidden" value="Province">
                <input type="hidden" id="hidden" name="hidden">

                <input class="form-control" type="hidden" id="hjy_PnoProvince230128" name="hjy_PnoProvince230128"  readOnly="true">
                <input class="form-control" type="hidden" id="hjy_PnameProvince230128" name="hjy_PnameProvince230128" >

            </form>
        </div>

    </div>
</div>


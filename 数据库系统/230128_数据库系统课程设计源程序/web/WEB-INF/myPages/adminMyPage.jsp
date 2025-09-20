<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<div class="container-fluid" id="myPage" style="margin-top: 20px;">
    <div class="d-sm-flex justify-content-between align-items-center mb-4">
        <h3 class="text-dark mb-0">我的主页</h3>
    </div>
    <div class="row">
        <div class="col-md-6 col-xl-3 mb-4">
            <a href="Admin.do?pageName=Majors" id="fillTable_button1" style="text-decoration: none;">
                <div class="card shadow border-left-primary py-2">
                    <div class="card-body">
                        <div class="row align-items-center no-gutters">
                            <div class="col mr-2">
                                <div class="text-uppercase text-primary font-weight-bold text-xs mb-1">
                                    <span>专业表管理</span></div>
                                <div class="text-dark font-weight-bold h5 mb-0"><span>专业信息管理</span></div>
                            </div>
                            <div class="col-auto"><i class="fas fa-calendar fa-2x text-gray-300"></i></div>
                        </div>
                    </div>
                </div>
            </a>
        </div>
        <div class="col-md-6 col-xl-3 mb-4">
            <a href="Admin.do?pageName=Classes"  style="text-decoration: none;">
                <div class="card shadow border-left-primary py-2">
                    <div class="card-body">
                        <div class="row align-items-center no-gutters">
                            <div class="col mr-2">
                                <div class="text-uppercase text-primary font-weight-bold text-xs mb-1">
                                    <span>班级表管理</span></div>
                                <div class="text-dark font-weight-bold h5 mb-0"><span>班级信息管理</span></div>
                            </div>
                            <div class="col-auto"><i class="fas fa-calendar fa-2x text-gray-300"></i></div>
                        </div>
                    </div>
                </div>
            </a>
        </div>
        <div class="col-md-6 col-xl-3 mb-4">
            <a href="Admin.do?pageName=Teachers"  style="text-decoration: none;">
                <div class="card shadow border-left-primary py-2">
                    <div class="card-body">
                        <div class="row align-items-center no-gutters">
                            <div class="col mr-2">
                                <div class="text-uppercase text-primary font-weight-bold text-xs mb-1">
                                    <span>教师表管理</span></div>
                                <div class="text-dark font-weight-bold h5 mb-0"><span>教师信息管理</span></div>
                            </div>
                            <div class="col-auto"><i class="fas fa-calendar fa-2x text-gray-300"></i></div>
                        </div>
                    </div>
                </div>
            </a>
        </div>

    </div>

    <div class="d-sm-flex justify-content-between align-items-center mb-4">
        <h3 class="text-dark mb-0"></h3>
    </div>
    <div class="row">
        <div class="col-md-6 col-xl-3 mb-4">
            <a href="Admin.do?pageName=Students"  style="text-decoration: none;">
                <div class="card shadow border-left-success py-2">
                    <div class="card-body">
                        <div class="row align-items-center no-gutters">
                            <div class="col mr-2">
                                <div class="text-uppercase text-success font-weight-bold text-xs mb-1">
                                    <span>学生表管理</span></div>
                                <div class="text-dark font-weight-bold h5 mb-0"><span>学生信息管理</span></div>
                            </div>
                            <div class="col-auto"><i class="fas fa-dollar-sign fa-2x text-gray-300"></i>
                            </div>
                        </div>
                    </div>
                </div>
            </a>
        </div>
        <div class="col-md-6 col-xl-3 mb-4">
            <a href="Admin.do?pageName=Courses"  style="text-decoration: none;">

                <div class="card shadow border-left-success py-2">
                    <div class="card-body">
                        <div class="row align-items-center no-gutters">
                            <div class="col mr-2">
                                <div class="text-uppercase text-info font-weight-bold text-xs mb-1">
                                    <span>课程表管理</span></div>
                                <div class="text-dark font-weight-bold h5 mb-0"><span>课程信息管理</span></div>
                            </div>
                            <div class="col-auto"><i class="fas fa-clipboard-list fa-2x text-gray-300"></i>
                            </div>
                        </div>
                    </div>
                </div>
            </a>
        </div>
        <div class="col-md-6 col-xl-3 mb-4">
            <a href="Admin.do?pageName=SC"  style="text-decoration: none;">

                <div class="card shadow border-left-warning py-2">
                    <div class="card-body">
                        <div class="row align-items-center no-gutters">
                            <div class="col mr-2">
                                <div class="text-uppercase text-warning font-weight-bold text-xs mb-1">
                                    <span>学生成绩表管理</span></div>
                                <div class="text-dark font-weight-bold h5 mb-0"><span>学生成绩管理</span></div>
                            </div>
                            <div class="col-auto"><i class="fas fa-comments fa-2x text-gray-300"></i></div>
                        </div>
                    </div>
                </div>
            </a>
        </div>
        <div class="col-md-6 col-xl-3 mb-4">
            <a href="Admin.do?pageName=TC"  style="text-decoration: none;">

                <div class="card shadow border-left-warning py-2">
                    <div class="card-body">
                        <div class="row align-items-center no-gutters">
                            <div class="col mr-2">
                                <div class="text-uppercase text-warning font-weight-bold text-xs mb-1">
                                    <span>教师任课管理</span></div>
                                <div class="text-dark font-weight-bold h5 mb-0"><span>教师任课管理</span></div>
                            </div>
                            <div class="col-auto"><i class="fas fa-comments fa-2x text-gray-300"></i></div>
                        </div>
                    </div>
                </div>
            </a>
        </div>
    </div>
    <div class="d-sm-flex justify-content-between align-items-center mb-4">
        <h3 class="text-dark mb-0"></h3>
    </div>

    <div class="row">

        <div class="col-md-6 col-xl-3 mb-4">
            <a href="Admin.do?pageName=Province" id="fillTable_button" style="text-decoration: none;">
                <div class="card shadow border-left-primary py-2">
                    <div class="card-body">
                        <div class="row align-items-center no-gutters">
                            <div class="col mr-2">
                                <div class="text-uppercase text-primary font-weight-bold text-xs mb-1">
                                    <span>省表管理</span></div>
                                <div class="text-dark font-weight-bold h5 mb-0"><span>省份信息管理</span></div>
                            </div>
                            <div class="col-auto"><i class="fas fa-calendar fa-2x text-gray-300"></i></div>
                        </div>
                    </div>
                </div>
            </a>
        </div>
        <div class="col-md-6 col-xl-3 mb-4">
            <a href="Admin.do?pageName=City"  style="text-decoration: none;">
                <div class="card shadow border-left-primary py-2">
                    <div class="card-body">
                        <div class="row align-items-center no-gutters">
                            <div class="col mr-2">
                                <div class="text-uppercase text-primary font-weight-bold text-xs mb-1">
                                    <span>市表管理</span></div>
                                <div class="text-dark font-weight-bold h5 mb-0"><span>市级信息管理</span></div>
                            </div>
                            <div class="col-auto"><i class="fas fa-calendar fa-2x text-gray-300"></i></div>
                        </div>
                    </div>
                </div>
            </a>
        </div>
        <div class="col-md-6 col-xl-3 mb-4">
            <a href="Admin.do?pageName=District"  style="text-decoration: none;">
                <div class="card shadow border-left-primary py-2">
                    <div class="card-body">
                        <div class="row align-items-center no-gutters">
                            <div class="col mr-2">
                                <div class="text-uppercase text-primary font-weight-bold text-xs mb-1">
                                    <span>区表管理</span></div>
                                <div class="text-dark font-weight-bold h5 mb-0"><span>区级信息管理</span></div>
                            </div>
                            <div class="col-auto"><i class="fas fa-calendar fa-2x text-gray-300"></i></div>
                        </div>
                    </div>
                </div>
            </a>
        </div>
    </div>
</div>
</div>

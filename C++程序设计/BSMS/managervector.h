#ifndef MANAGERVECTOR
#define MANAGERVECTOR
#include <string>
#include "manager.h"
#include "vector.hpp"
using namespace std;
class ManagerVector :public Vector<Manager> {
public:
	void readFromFile(const string& in = "Manager.txt");  //从文件中读入管理员的账号信息
	Manager* find(const string s);//查找账号密码信息
	bool login();//登录系统
};
#endif
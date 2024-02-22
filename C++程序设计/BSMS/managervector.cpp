#include <string>
#include "managervector.h"
#include "vector.hpp"
#include "menu.h"
using namespace std;
void ManagerVector::readFromFile(const string& in ) {
	//从文件中读入管理员的账号信息
	ifstream inf(in);
	if (inf.is_open()) {
		string n, p;
		while (inf >> n>>p) {
			push_back(Manager(n,p));
		}
		inf.close();
		cout << "\n                   管理员信息加载成功！\n" << endl;
	}
	else {
		cout << "管理员信息文件" << in << "无法打开！\n";
		cout << "请检查文件名是否有效！\n";
	}
}
Manager* ManagerVector::find(const string s) {
	for (int i = 0; i < size(); ++i)
		if (s == (*this)[i].Name())
			return &(*this)[i];
	return 0;
}

bool ManagerVector::login() {//登陆界面
		string n, p;
		cout << "请输入管理员的用户名:\n";
		Menu::tip();
		cin >> n;
		Manager* a = this->find(n);
		if (!a) {
			cout << "用户不存在！\n";
			return 0;
		}
		cout << "请输入管理员的密码:\n";
		Menu::tip();
		cin >> p;
		if (a->Pass() != p) {
			system("cls");
			cout << "密码错误！\n";
			return 0;
		}
		system("cls");
		cout << "                       登陆成功\n\n";
		Menu::line();
		return true;
}
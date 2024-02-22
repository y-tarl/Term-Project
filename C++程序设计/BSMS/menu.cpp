#include <iostream>
#include<iomanip>
#include "menu.h"
#include "salevector.h"
#include "other.h"
#include "managervector.h"
using namespace std;
void Menu::mainMenu(){
	cout << "    ------------------------------------------------------\n";
	cout << "    |           欢迎进入面包店销售管理系统                   |" << endl;
	cout << "    |           1.查询面包信息                             |" << endl;
	cout << "    |           2.管理员登录 以获取更多权限                  |" << endl;
	cout << "    ------------------------------------------------------\n";
	cout << "               请选择（0为退出系统）：\n";
}

void Menu::managerMenu() {//管理员菜单
	cout << "    ------------------------------------------------------\n";
	cout << "               欢迎进入面包店销售管理系统  " << endl;
	cout << "               1.查询面包信息                            " << endl;
	cout << "               2.添加面包信息                            " << endl;
	cout << "               3.删除面包信息                            " << endl;
	cout << "               4.录入销售记录                               " << endl;
	cout << "               5.查询该日销售记录                              " << endl;
	cout << "               6.分类统计销售记录并导入到文件                            " << endl;
	cout << "               7.将销售记录排序                            " << endl;
	cout << "    ------------------------------------------------------\n";
	cout << "               请选择（0为返回上一级）：\n";
}

void Menu::line() {
	cout << "    ----------------我是一条分割线------------------------\n\n";
}
void Menu::tip() {
	cout << "->";
}

void Menu::findBread(BreadVector& b) {
	if (!b.size()) {
		cout << "无面包信息！\n";
		return;
	}
	cout << "请输入查询面包信息的方式：\n";
	cout << "1.按商品号查询\n";
	cout << "2.按商品名查询\n";
	cout << "请选择（0为返回主菜单）：\n";
	tip();
	int t;
	while (cin >> t, (t != 1) && (t != 2)&&t) {
		cout << "输入错误！请重新输入！\n";
	}
	if (t == 0) return;
	cout << "请输入查询的内容：\n";
	tip();
	char c[30]; 
	cin >> c;
	if (!b.find(c, t)) cout << "查找失败！该商品不存在\n";
	
	else {
		system("cls");
		cout << *(b.find(c, t));
	}
}

void Menu::sortSale(SaleVector& s) {
	cout << "请指定销售记录的排序的方式:\n";
	cout << "1.按销售日期排序\n";
	cout << "2.按总价排序\n";
	cout << "3.按数量排序\n";
	int t;
	while (tip(), cin >> t, (t != 1) && (t != 2) && (t != 3)) {
		cout << "输入错误！请重新输入！\n";
	}
	switch (t) {
	case 1:
		s.quickSort(0, s.size()-1, sortBySaleDate);
		system("cls");
		cout << "\n按销售日期排序成功！\n\n";
		break;
	case 2:
		s.quickSort(0, s.size()-1, sortBySaleTotal);
		system("cls");
		cout << "\n按总价排序成功！\n\n";
		break;
	case 3:
		s.quickSort(0, s.size()-1, sortBySaleQuantity);
		system("cls");
		cout << "\n按数量排序成功！\n\n";
		break;
	}
	cout << "排序后结果如下：\n";
	cout << fixed << left << setw(15)
		<< "销售日期" << setw(7) << "商品号" << setw(10)
		<< "商品名称" << setw(15) << "制作日期" << setw(5)
		<< fixed << setprecision(2) << "有效期" << "\t" << setw(7)
		<< fixed << setprecision(2) << "单价" << "\t" << fixed << setw(3)
		<< "折扣" << "\t" << setw(5) << "数量" << "\t" << setw(5)
		<< "总价" << "\n";
	for (int i = 0; i < s.size(); ++i)
		cout << s[i];
}

void Menu::saleStatistics(SaleVector& s) {
	if (!s.size()) {
		cout << "没有销售记录可分类统计！\n";
		return;
	}
	int mode;
	ofstream out;
	cout << "请选择分类方式（1-按商品号，2-按销售日期）：\n";
	while (tip(), cin >> mode, mode != 1 && mode != 2) { //输入非法
		cout << "输入非法！请重新输入！" << endl;
	}
	SaleVector sales;
	string i;
	if (mode == 1) 
		i = "satisticByID.txt";
	else  i = "satisticBySaleData.txt";
	sales = s.saleStatistics(mode);
	out.open(i);
	if (!out.is_open()) {
		cout << "分类信息导出到文件失败！\n";
		return;
	}
	else if (mode == 1) {
		out << "==========按商品号分类统计==========" << endl;
		out << fixed << left << setw(7) << "商品号" << setw(10)
			<< "商品名称" << setw(5) << "数量" << "\t" << setw(5)
			<< "总价" << "\n";
		for (int i = 0; i < sales.size(); ++i) { //遍历统计列表
			out << fixed << left << setw(7) << sales[i].Info().Id() << setw(10)
				<< sales[i].Info().Name()
				<< setw(3) << sales[i].Quantity() << "个\t" << setw(5)
				<< setprecision(2) << sales[i].All() << "元\n";
		}
	}
	else {
		out << "==========按销售日期分类统计==========" << endl;
		out << fixed << left << setw(15)
			<< "销售日期" << setw(5) << "数量" << "\t" << setw(5)
			<< "总价" << "\n";
		for (int i = 0; i < sales.size(); ++i) { //遍历统计列表
			out << fixed << left << setw(15)
				<< sales[i].SaleDate() << setw(3)
				<< sales[i].Quantity() << "个\t" << setw(5)
				<< setprecision(2) << sales[i].All() << "元\n";
		}
	}
	Menu::line();
	cout << "分类信息导出到" << i << "成功！\n";
	cout << "\n导出信息如下：\n\n";
	out.close();
	ifstream in(i);
	string s1;
	while (getline(in, s1))
		cout << s1 << endl;
}
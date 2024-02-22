#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
#include "breadvector.h"
#include "menu.h"
using namespace std;
Bread* BreadVector::find(const char c[30], const int t) {
	//t表示查找模式，1表示按商品号查找，2表示按商品名查找
	if (t == 1) {
		for (int i = 0; i < size(); ++i)
			if(string((*this)[i].BasicInfo().Id())==string( c))
				return &((*this)[i]);
	}
	else for (int i = 0; i < size(); ++i)
		if (string((*this)[i].BasicInfo().Name()) == string(c))
			return &((*this)[i]);
	return 0;
}

void BreadVector::readFromFile(const string& in) {
	ifstream inf(in);
	if (inf.is_open()) {
		char i[30], n[30], m[30];
		double s, p;
		int st;
		while (inf >> i >> n >> m >> s >> p >> st) {
			push_back(Bread(i, n, m, s, p, st));
		}
		inf.close();
		cout << "\n                    商品信息加载成功！\n" << endl;
	}
	else {
		cout << "读入文件" << in << "失败！\n";
		cout << "请检查文件名是否有效！\n";
	}
}

void BreadVector::addBread(Bread& b, const string& ou) {
	push_back(b);
	cout << "面包信息录入成功！\n";
	cout << "\n内容如下：\n";
	cout << b;
	ofstream out(ou,ios::app);
	if (!out.is_open())
		cout << "但信息保存至后台失败！\n";
	else {
		out << b.BasicInfo().Id() << "\t" << b.BasicInfo().Name() << "\t"
			<< b.BasicInfo().MadeDate() << "\t" << b.BasicInfo().ShelfLife() << "\t"
		    <<fixed<<setprecision(2)<< b.BasicInfo().Price() << "\t" 
			<< b.Store() << "\n";
	}
	out.close();
}

bool BreadVector::modFile(const string& ou ) {
	ofstream out(ou);
	if (!out.is_open())
	{
		cout << "打开文件" << ou << "失败！\n";
		cout << "请检查文件名是否有效！\n";
		return 0;
	}
	else {
		for (int i = 0; i < size(); ++i) {
			out << (*this)[i].BasicInfo().Id() << "\t" << (*this)[i].BasicInfo().Name() << "\t"
				<< (*this)[i].BasicInfo().MadeDate() << "\t" << (*this)[i].BasicInfo().ShelfLife() << "\t"
				<< fixed << setprecision(2) << (*this)[i].BasicInfo().Price() << "\t"
				<< (*this)[i].Store() << "\n";
		}
	}
	out.close();
	return 1;
}

void BreadVector::popBread() {
	if (!size()) return;
	bool flag = 1;
	char c[30];
	Bread* a = 0;
	int i;
	while (flag) {
		cout << "请输入想要删除的面包种类：\n\n";
		  //删除面包信息时，提供两种查找方式
		cout << "1.按商品号输入\n";
		cout << "2.按商品名输入\n";
		int t;
		while (Menu::tip(), cin >> t, (t != 1) && (t != 2)) {
			cout << "输入错误！请重新输入！\n";
		}
		cout << "请输入售出面包具体商品号/商品名：\n";
		Menu::tip();
		cin >> c;
		a = (*this).find(c, t);//a为找到的Bread
		i = (*this).findi(a);//i为a的下标
		if (!a) {
			cout << "该面包不存在！请检查信息是否有误\n";
			Menu::line();
		}
		else {
			cout << "\n该面包具体信息如下：\n";
			cout << *a;
			cout << "\n请确认这是否为欲删除的面包信息（按1确认，任意键取消）：\n";
			Menu::tip();
			cin >> t;
			if (t == 1) {
				flag = 0;
			}
		}
	}
	if ((*this).erase(i))
		cout << "\n面包删除信息成功！\n";
	if ((*this).modFile())  //更新文件中面包信息
		cout << "文件面包信息同步成功！\n\n";
}
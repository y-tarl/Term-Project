#ifndef BREADVECTOR
#define BREADVECTOR
#include<iostream>
#include<string>
#include "vector.hpp"
#include "bread.h"
using namespace std;
class BreadVector:public Vector<Bread> {
public:
	void readFromFile(const string& in = "Bread.txt");  //从文件中读入面包类信息
	void addBread(Bread& b, const string& ou="Bread.txt");  //添加面包信息并更新到文件
	bool modFile(const string& ou = "Bread.txt");  //重新更新文件中面包信息
	void popBread();//删除面包信息
	Bread* find(const char c[30], const int t);
	   //t表示查找模式，1表示按商品号查找，2表示按商品名查找
};
#endif
#pragma once
#ifndef BREAD
#define BREAD
#include<iostream>
#include"basis.h"
using namespace std;
//面包的所有信息类
class Bread {
	Basis basicInfo;  //面包的基础信息
	int store;        //库存数量
public:
	Bread(const char* i = "", const char* n = "", const char* m = "", double s = 0, double p = 0, int st = 0);
	Bread(const Bread& b);
	const int Store()const;
	void modStore(int& q); //修改面包的库存，q表示售出的面包数量
	const Basis& BasicInfo() const;
	Bread& operator=(const Bread& b);
	bool operator==(const Bread& b);//重载判断相等
	friend ostream& operator<<(ostream& out, const Bread& b);
};

#endif
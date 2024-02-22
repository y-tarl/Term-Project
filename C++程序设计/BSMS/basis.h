#ifndef BASIS
#define BASIS
#include<iostream>
using namespace std;
//面包的基础信息类
class Basis { 
public:
	char  id[10];    //商品号
	char name[30];  //商品名
	char madeDate[30];  //制作日期
	double shelfLife;  //保质期
	double price;    //售价

	Basis(const char* i = "", const char* n = "", const char* m = "", double s = 0, double p = 0);
	Basis(const Basis& b);
	const char* Id() const { return id; }
	const char* Name() const { return name; }
	const char* MadeDate() const { return madeDate; }
	const double ShelfLife() const { return shelfLife; }
	const double Price() const { return price; }
	Basis& operator =(const Basis& a);
	bool operator ==(const Basis& a);
	friend ostream& operator <<(ostream& out, const Basis& b);
};
#endif
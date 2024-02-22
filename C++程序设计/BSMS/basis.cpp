#include <iostream>
#include <cstring>
#include "basis.h"
using namespace std;
Basis::Basis(const char* i, const char* n, const char* m, double s, double p):price(p), shelfLife(s) {
	strcpy(id, i);
	strcpy(name, n);
	strcpy(madeDate, m);
}
Basis::Basis(const Basis& b) :shelfLife(b.shelfLife), price(b.price){
	strcpy(id, b.id);
	strcpy(name, b.name);
	strcpy(madeDate, b.madeDate);
}
Basis& Basis::operator =(const Basis& a) {
	strcpy(id, a.id);
	strcpy(name, a.name);
	strcpy(madeDate, a.madeDate);
	price = a.price;
	shelfLife = a.shelfLife;
	return *this;
}
bool Basis::operator ==(const Basis& b) {
	return (string(id) == string(b.id)) && (string(name) == string(b.name)) 
		&& (string(madeDate) == string(b.madeDate)) && (shelfLife == b.shelfLife)
		&& (price == b.price);
}

ostream& operator <<(ostream& out, const Basis& b) {
	out << "商品号：" << b.id << "\t";
	out << "商品名：" << b.name << "\t";
	out << "售价: " << b.price << "元\n";
	out << "制作日期：" << b.madeDate << "\t";
	out << "保质期：" << b.shelfLife << "天\n";
	return out;
}
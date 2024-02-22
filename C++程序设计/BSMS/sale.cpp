#include <iostream>
#include <iomanip>
#include<cstring>
#include "sale.h"
using namespace std;
Sale::Sale(const char* i, const char* n, const char* m, double sh, double p, const char* sa, double d, int q)
	:info(i,n,m,sh,p) {
	strcpy(saleDate, sa);
	discount = d;
	quantity = q;

	paid = discount * (this->Info().Price());
	all = (paid * quantity);
	
}

Sale::Sale(const Basis& b, const char* sa, double d, int q)
	:info(b), discount(d), quantity(q) {
	strcpy(saleDate, sa);
	paid = discount * (this->Info().Price());
	all = paid * quantity;
}

Sale::Sale(Sale& s):info(s.info), discount(s.discount), quantity(s.quantity),paid(s.paid),all(s.all) {
	strcpy(saleDate, s.saleDate);
}

const Basis Sale::Info()const { return info; }

const char* Sale::SaleDate()const { return saleDate; }

const double Sale::Discount()const { return discount; }

const int Sale::Quantity()const { return quantity; }
void Sale::setQuantity(const int& q) { quantity = q; }//设置数量

const double Sale::Paid()const { return paid; }

const double Sale::All()const { return all; }
void Sale::setAll(const int& a) { all=a; }//设置总价



void Sale::print()const {
	cout << "销售日期\t商品号\t商品名称\t制作日期\t有效期\t单价\t折扣\t数量\t总价" << endl;
	cout << (*this);
}

Sale& Sale::operator=(const Sale& s) {
	info = s.info;
	strcpy(saleDate, s.saleDate);
	quantity = s.quantity;
	discount = s.discount;

	paid = s.paid;
	all = s.all;
	return *this;
}
bool Sale::operator==(const Sale& s) {
	return (string(saleDate) == string(s.saleDate)) && (info == s.info)
		&& (discount == s.discount) && (quantity == s.quantity)
		&& (paid == s.paid) && (all == s.all);
}
ostream& operator<<(ostream& out, const Sale& b) {
	out<<fixed<<left<<setw(15)
		<< b.saleDate << setw(7) << b.info.Id() << setw(10)
		<< b.info.Name() << setw(15) << b.info.MadeDate() << setw(5)
		<< fixed << setprecision(2) << b.info.ShelfLife() << "天\t" << setw(4)
		<< fixed << setprecision(2) << b.info.Price() << "元\t" << fixed <<setw(3)
		<< b.discount <<"\t" << setw(3) << b.quantity << "个\t" << setw(5)
		<< b.all << "元\n";
	return out;
}
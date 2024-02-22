#ifndef SALE
#define SALE
#include<iostream>
#include "basis.h"
using namespace std;
//销售信息类
class Sale {
    Basis info;      //面包基础信息
    char saleDate[30];  //销售日期 
    double discount;   //折扣
    int quantity;      //数量
    double paid;      //实付价格
    double all;  //总价
public:
    Sale(const char* i = "", const char* n = "", const char* m = "", double sh = 0, double p = 0, const char* sa = "", double d = 0, int q = 0);
    Sale(const Basis&b, const char* sa = "", double d = 0, int q = 0);
    Sale(Sale& s);
    const Basis Info()const;
    const char* SaleDate()const;

    const double Discount()const;

    const int Quantity()const;

    void setQuantity(const int& q);//设置数量

    const double Paid()const;

    const double All()const;

    void setAll(const int& a);//设置总价

    void print()const;//用于单条销售记录的输出，带中文的标识说明

    Sale& operator=(const Sale& s);
    bool operator==(const Sale& s);

    friend ostream& operator<<(ostream& out, const Sale& b);
      //用于一系列sale信息的输出，不带中文标识
};
#endif

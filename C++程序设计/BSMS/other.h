#ifndef OTHER
#define OTHER
//其他类外函数
#include<iostream>
#include<string>
#include "sale.h"
using namespace std;
//闰年判断
bool leapYear(const int y);

//销售日期合法性判断，应满足以下条件
// ①格式：YYYY-MM-DD  
// ②合法  
// ③在制作日期之后
// ④在保质期之内
bool sdisvalue(const string& s1, const string& s2, int t);

//制作日期合法性判断（满足格式且合法）
bool isvalue(const string& s);

//四个比较函数：
int sortByID(const Sale& s1, const Sale& s2); //比较商品号
int sortBySaleDate(const Sale& s1, const Sale& s2); //比较销售日期
int sortBySaleTotal(const Sale& s1, const Sale& s2);//比较总价
int sortBySaleQuantity(const Sale& s1, const Sale& s2);//比较数量
#endif
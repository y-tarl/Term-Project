#include <iostream>
#include <string>
#include "other.h"
using namespace std;
//销售日期合法性判断，应满足以下条件
// ①格式：YYYY-MM-DD  
// ②合法  
// ③在制作日期之后
// ④在保质期之内
bool sdisvalue(const string& s1, const string& s2, int t) {
	if (!isvalue(s1)) return 0;
	if (s1 < s2) { 
		cout << "销售日期在制作日期之前！\n";
		return 0; 
	}

	int year1 = stoi(s1.substr(0, 4));
	int month1 = stoi(s1.substr(5, 2));
	int day1 = stoi(s1.substr(8, 2));  //将销售日期提取出来

	int Day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int year2 = stoi(s2.substr(0, 4));
	if (leapYear(year2)) Day[2] = 29;
	int month2 = stoi(s2.substr(5, 2));
	int day2 = stoi(s2.substr(8, 2));  //将制作日期提取出来
	if ((day2 += t) > Day[month2]) {
		day2 -= Day[month2];
		month2++;  //用制作日期+保质期，得到最后的销售期限
	}
	if (month2 > 12) year2++;

	if (year1 *1000+ month1*100+day1 > year2 * 1000 + month2 * 100 + day2) {
		cout << "在该销售日期当日面包已过期！\n";
		return 0;
	}
		return 1;
}

bool leapYear(const int y) {
	return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}

//制作日期合法性判断（满足格式且合法）
bool isvalue(const string& s) {
	if (s.size() != 10) {
		cout << "日期格式错误！\n";
		return 0;
	}
	if ((s[4] != '-') || (s[7] != '-')) {
		cout << "日期格式错误！\n";
		return 0;
	}
	int Day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int year = stoi(s.substr(0, 4));
	if (leapYear(year)) Day[2] = 29;
	int month = stoi(s.substr(5, 2));
	int day = stoi(s.substr(8, 2));
	if (month >= 13 || month < 0 || day < 0 || (Day[month] < day)) {
		cout << "日期不合法！\n";
		return 0;
	}
	return 1;
}

//排序函数（按商品号）
int sortByID(const Sale& s1, const Sale& s2) {
	string ss1 = s1.Info().Id(), ss2 = s2.Info().Id();
	if (ss1 > ss2) return 1;
	else if (ss1 == ss2) return 0;
	return  -1;
}

//排序函数（按销售日期）
int sortBySaleDate(const Sale& s1, const Sale& s2) {
	string ss1 = s1.SaleDate(), ss2 = s2.SaleDate();
	if (ss1 > ss2) return 1;
	else if (ss1 == ss2) return 0;
	return  -1;
}

//排序函数（按总价）
int sortBySaleTotal(const Sale& s1, const Sale& s2) {
	return s1.All() - s2.All();
}

//排序函数（按数量）
int sortBySaleQuantity(const Sale& s1, const Sale& s2) {
	return s1.Quantity() - s2.Quantity();
}
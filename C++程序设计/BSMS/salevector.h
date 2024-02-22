#ifndef SALEVECTOR
#define SALEVECTOR
#include<iostream>
#include<string>
#include "breadvector.h"
using namespace std;

class SaleVector :public Vector<Sale> {
public:
	void readFromFile(const string& in = "Sales.txt");//录入销售信息时可选择从文件中读入
	void writeToFile(const string& ou="Sale.txt"); //将销售记录写入文件
	Sale* find(const char c[30], const int t);
	 //t表示查找模式，1表示按销售日期查找，2表示按商品号查找，3表示按商品名查找
	SaleVector showToday();//查询该日销售记录
	void inSale(BreadVector& b);//录入销售记录
	SaleVector saleStatistics(int mode);//分类统计销售记录
	void quickSort(int l , int r, int(*pr)(const Sale& s1, const Sale& s2));
	 //sales的快速排序，pr表示指向函数的指针，用来传递比较依据
};
#endif

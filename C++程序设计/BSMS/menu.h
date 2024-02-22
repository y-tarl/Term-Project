#ifndef MENU
#define MENU
#include <iostream>
#include "breadvector.h"
#include "managervector.h"
#include "salevector.h"
class Menu {
public:
	static void line();//分割线
	static void tip();//输入提示符
	void mainMenu();//主菜单
	void managerMenu();//管理员菜单
	void findBread(BreadVector& b);//查找面包信息
	void saleStatistics(SaleVector& s);//分类统计销售信息
	void sortSale(SaleVector& s); //给销售记录排序
};
#endif
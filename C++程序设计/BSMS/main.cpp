#include <iostream>
#include <iomanip>
#include "breadvector.h"
#include <algorithm>
#include <fstream>
#include "salevector.h"
#include "menu.h"
#include "other.h"
using namespace std;
// 面包店销售管理系统
// 基本要求：
// 销售信息包括商品号、商品名称、制作日期、有效期、销售日期、售价、折扣、数量。
// 功能要求：
// 1、设计菜单实现功能选择；
// 2、从文件读入商品号和商品名称、制作日期，有效期，库存数量等信息；
// 3、销售记录的登记；
// 4、对当日销售信息的查询，将销售记录按日期、总价、数量等项目排序；
// 5、销售记录的分类统计（按商品号、销售日期）；
// 6、可以将当日销售记录和统计信息导出登记到文件；
int main()
{
	BreadVector breads;
	breads.readFromFile();
	ManagerVector managers;
	managers.readFromFile();
	SaleVector sales;
	Menu menu;
	menu.mainMenu(); // 通用主菜单
	int flag;
	bool t = 0;
	char i[10], n[30], m[30];
	double s, p;
	int st;
	char o;
	Bread y;
	SaleVector r;
	while (menu.tip(), cin >> flag, flag)
	{
		switch (flag)
		{
		case 1:
			menu.line();
			cout << "1.查询所有面包信息\n";
			cout << "2.查询某一面包信息\n";
			cout << "请选择（0为返回上一级）：\n";
			while ((menu.tip(), cin >> o) && (o != '1' && o != '2' && o != '0'))
			{
				cout << "输入错误！请重新输入！\n";
			}
			switch (o)
			{
			case '1':
				menu.line();
				cout << "所有面包信息如下：\n";
				for (int i = 0; i < breads.size(); ++i)
					cout << breads[i] << endl;
				break;
			case '2':
				menu.findBread(breads);
				break;
			default:
				system("cls");
				break;
			}
			break;
		case 2:
			menu.line();
			t = managers.login();
			if (!t)
			{
				cout << "登陆失败！\n";
			}
			while (t)
			{
				menu.managerMenu(); // 管理员主菜单
				int f;
				while ((menu.tip(), cin >> f) && f)
				{
					switch (f)
					{
					case 1:
						menu.line();
						cout << "1.查询所有面包信息\n";
						cout << "2.查询某一面包信息\n";
						cout << "请选择（0为返回上一级）：\n";
						while ((menu.tip(), cin >> o) && (o != '1' && o != '2' && o != '0'))
						{
							cout << "输入错误！请重新输入！\n";
						}
						switch (o)
						{
						case '1':
							menu.line();
							cout << "所有面包信息如下：\n";
							for (int i = 0; i < breads.size(); ++i)
								cout << breads[i] << endl;
							break;
						case '2':
							menu.findBread(breads);
							break;
						default:
							system("cls");
							break;
						}
						break;
					case 2:
						menu.line();
						cout << "请输入下列信息：\n\n";
						cout << "请输入商品号：(格式：10XX  例如：1001)" << endl;
						while (menu.tip(), cin >> i, (breads.find(i, 1)))
							cout << "商品号已存在！请重新输入！\n";
						cout << "请输入商品名：" << endl;
						while (menu.tip(), cin >> n, (breads.find(n, 2)))
							cout << "商品名已存在！请重新输入！\n";
						cout << "请输入该面包的制作日期（格式：YYYY-MM-DD）：" << endl;
						while (menu.tip(), cin >> m, !isvalue(m))
						{
							cout << "请重新输入!\n";
						}
						cout << "请输入该面包的保质期：（天）" << endl;
						menu.tip();
						cin >> s;
						cout << "请输入该面包的单价：（元）" << endl;
						menu.tip();
						cin >> p;
						cout << "请输入该面包的库存数量：(个)" << endl;
						menu.tip();
						cin >> st;
						y = Bread(i, n, m, s, p, st);
						Menu::line();
						breads.addBread(y);
						break;
					case 3:
						breads.popBread();
						break;
					case 4:
						Menu::line();
						cout << "1.直接读入后台销售记录\n";
						cout << "2.手动录入销售记录\n";
						cout << "请选择（0为返回上一级）：\n";
						int b;
						while (menu.tip(), cin >> b, (b != 1 && b != 2 && b))
							cout << "输入错误！请重新输入！\n";
						switch (b)
						{
						case 1:
							sales.readFromFile();
							break;
						case 2:
							sales.inSale(breads);
							break;
						default:
							break;
						}
						break;
					case 5:
					{
						Menu::line();
						r = sales.showToday();
						menu.line();
						if(!r.empty())
						{cout << "是否要将该日的销售记录导入到文件TodaySale.txt？\n";
						cout << "1.Yes.\n";
						cout << "2.No.\n";
						while ((menu.tip(), cin >> o) && (o != '1' && o != '2'))
						{
							cout << "输入错误！请重新输入！\n";
						}
						if (o == '1')
						{
							r.writeToFile("TodaySale.txt");
						}}
						break;
					}
					case 6:
						Menu::line();
						menu.saleStatistics(sales);
						break;
					case 7:
						Menu::line();
						menu.sortSale(sales);
						break;
					}
					menu.managerMenu();
				}
				if (!f)
				{
					system("cls");
					break;
				}
			}
			break;
		default:
			cout << "输入错误！请重新输入！\n";
		}
		menu.mainMenu();
	}
	system("cls");
	cout << "    ------------------------------------------------------\n";
	cout << "    |           感谢使用面包店销售管理系统，再见！       |" << endl;
	cout << "    ------------------------------------------------------\n";
}

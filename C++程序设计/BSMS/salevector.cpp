#include<iostream>
#include<iomanip>
#include<string>
#include<string.h>
#include "salevector.h"
#include "menu.h"
#include "other.h"
using namespace std;
Sale* SaleVector::find(const char c[30], const int t) {
	if (t == 1) {
		for (int i = 0; i < size(); ++i)
			if (!strcmp((*this)[i].SaleDate(), c))
				return &((*this)[i]);
	}
	else if (t == 2) {
		for (int i = 0; i < size(); ++i)
			if (!strcmp((*this)[i].Info().Id(), c))
				return &((*this)[i]);
	}
	else if (t == 3)
		for (int i = 0; i < size(); ++i)
			if (!strcmp((*this)[i].Info().Name(), c))
				return &((*this)[i]);
	return 0;
}

void SaleVector::readFromFile(const string& in ) {
	ifstream inf(in);
	string s;
	getline(inf, s);
	if (inf.is_open()) {
		char i[30], n[30], m[30], sa[30];
		double s, p, d;
		int  q;
		while (inf >> sa >> i >> n >> m >> s >> p >> d >> q ) {
			push_back(Sale(i, n, m, s, p, sa, d, q));
		}
		inf.close();
		system("cls");
		cout << "                    销售记录读取成功！内容如下所示：\n" << endl;
		cout << fixed << left << setw(15)
			<< "销售日期" << setw(7) << "商品号" << setw(10)
			<< "商品名称" << setw(15) << "制作日期" << setw(5)
			<< fixed << setprecision(2) << "有效期" << "\t" << setw(7)
			<< fixed << setprecision(2) << "单价" << "\t" << fixed << setw(3)
			<< "折扣" << "\t" << setw(5) << "数量" << "\t" << setw(5)
			<< "总价" << "\n";
		for (int i = 0; i < size(); ++i)
			cout << (*this)[i];
	}
	else {
		cout << "读取后台销售记录文件" << in << "失败！\n";
		cout << "请检查文件名是否有效！\n";
	}
}

void SaleVector::writeToFile(const string& ou) {//将销售记录写入文件
	ofstream out(ou);
	if (!out.is_open())
	{
		cout << "打开文件" << ou << "失败！\n";
		cout << "请检查文件名是否有效！\n";
	}
	else {
		out << fixed << left << setw(15)
			<< "销售日期" << setw(7) << "商品号" << setw(10)
			<< "商品名称" << setw(15) << "制作日期" << setw(5)
			<< fixed << setprecision(2) << "有效期" << "\t" << setw(7)
			<< fixed << setprecision(2) << "单价" << "\t" << fixed << setw(3)
			<< "折扣" << "\t" << setw(5) << "数量" << "\t" << setw(5)
			<< "总价" << "\n";
		for (int i = 0; i < size(); ++i) {
			out << (*this)[i];
			/*out << (*this)[i].SaleDate()<<"\t"<< (*this)[i].Info().Id() << "\t" 
				<< (*this)[i].Info().Name() << "\t\t"<< (*this)[i].Info().MadeDate() << "\t" 
				<< (*this)[i].Info().ShelfLife() << "(天)\t   "
				<< fixed << setprecision(2) << (*this)[i].Info().Price() << "(元)\t"
				<< (*this)[i].Discount() << "\t" << (*this)[i].Quantity()<<"(个)\t"
				<<(*this)[i].Paid()* (*this)[i].Quantity() <<"(天)\n";*/
		}
	}
	cout << "销售信息导出到文件" << ou << "成功！\n";
	out.close();
}

SaleVector SaleVector::showToday() {
	if (this->empty()) {
		cout << "无销售记录可查询！\n";
		SaleVector s;
		return s;
	}
	char today[30];
	cout << "请输入查询日期（格式：YYYY-MM-DD）：\n";
	while (Menu::tip(), cin >> today, !isvalue(today)) {
		cout << "日期格式错误或不合法！请重新输入！\n";
	}
	double total_price = 0; //总价
	int total_quantity = 0; //总数量
	SaleVector today_sales; //该日销售记录
	for (int i = 0; i < this->size(); ++i) {
		if (!strcmp((*this)[i].SaleDate(), today)) { //找到对应日期的销售记录
			today_sales.push_back((*this)[i]);
			total_price += (*this)[i].All();
			total_quantity += (*this)[i].Quantity();
		}
	}
	if (today_sales.empty()) { //没有销售记录
		cout << "该日未有销售记录！" << endl;
		return today_sales;
	}
	cout << "\n==========该日销售信息==========" << endl;
	cout << "查询日期：" << today << endl;
	cout << "\n当日全部销售记录如下：\n" << endl;
	cout << fixed << left << setw(15)
		<< "销售日期" << setw(7) << "商品号" << setw(10)
		<< "商品名称" << setw(15) << "制作日期" << setw(5)
		<< fixed << setprecision(2) << "有效期" << "\t" << setw(7)
		<< fixed << setprecision(2) << "单价" << "\t" << fixed << setw(3)
		<< "折扣" << "\t" << setw(5) << "数量" << "\t" << setw(5)
		<< "总价" << "\n";
	for (int i = 0; i < today_sales.size(); ++i)
		cout << (*this)[i];
	cout << "\n该日销售数量：" << total_quantity << endl;
	cout << "该日总销售额：" << fixed << setprecision(2) << total_price << endl;
	return today_sales;
}

void SaleVector::inSale(BreadVector& b) {
	bool flag = 1;
	char c[30];
	Bread* a = 0;
	while (flag) {
		Menu::line();
		cout << "请输入下列信息：\n\n";
		cout << "面包种类：\n";  //输入面包信息时，提供两种输入方式
		cout << "1.按商品号查找并录入售出面包信息\n";
		cout << "2.按商品名查找并录入售出面包信息\n";
		int t;
		while (Menu::tip(), cin >> t, (t != 1) && (t != 2)) {
			cout << "输入错误！请重新输入！\n";
		}
		cout << "请输入售出面包具体商品号(格式：10XX  例如：1001)/商品名：\n";
		Menu::tip();
		cin >> c;
		a = b.find(c, t);
		if (!a) {
			cout << "该面包不存在！请检查信息是否有误\n";
		}
		else {
			cout << "\n该面包具体信息如下：\n";
			cout << *a;
			cout << "\n请确认这是否为欲录入销售记录对应的面包信息（按1确认，任意键取消）：\n";
			Menu::tip();
			cin >> t;
			if (t == 1) {
				flag = 0;
			}
		}
	}
	char day[30];
	cout << "请输入销售日期（格式：YYYY-MM-DD）：\n";
	while (Menu::tip(), cin >> day, !sdisvalue(day, a->BasicInfo().MadeDate(), a->BasicInfo().ShelfLife())) {
		cout << "请重新输入！\n";
	}

	double discount;
	cout << "请输入折扣（0-1之间的小数）：\n";
	while (Menu::tip(), cin >> discount, discount <= 0 || discount > 1) {
		cout << "输入错误！请重新输入！\n";
	}

	int quantity;
	cout << "请输入销售数量：\n";
	int q = a->Store();
	while (Menu::tip(), cin >> quantity, quantity <= 0 || quantity > q) { //数量非法或库存不足
		cout << "销售数量不合法或库存不足！" << endl;
	}
	a->modStore(quantity);
	system("cls");
	if (b.modFile())  //更新文件中面包信息
	{
		cout << "文件面包信息同步成功！\n\n";
	}
	else cout << "文件面包信息同步失败！\n\n";
	Sale sa(a->BasicInfo(), day, discount, quantity);
	this->push_back(sa);
	cout << "销售信息录入成功！\n\n录入信息如下：\n\n";
	cout << fixed << left << setw(15)
		<< "销售日期" << setw(7) << "商品号" << setw(10)
		<< "商品名称" << setw(15) << "制作日期" << setw(5)
		<< fixed << setprecision(2) << "有效期" << "\t" << setw(7)
		<< fixed << setprecision(2) << "单价" << "\t" << fixed << setw(3)
		<< "折扣" << "\t" << setw(5) << "数量" << "\t" << setw(5)
		<< "总价" << "\n";
	/*cout << "销售日期\t商品号\t商品名称\t制作日期\t有效期\t单价\t折扣\t数量\t总价" << endl;*/
	cout << sa << endl;
}

SaleVector SaleVector::saleStatistics(int mode) {
	SaleVector sales;
	if (mode == 1) {
		for (int i = 0; i < this->size(); ++i) {//遍历销售记录
			Sale* p = sales.find((*this)[i].Info().Id(), 2);
			if (p) {//在统计列表里找到对应记录
				p->setAll(p->All() + (*this)[i].All());
				p->setQuantity(p->Quantity() + (*this)[i].Quantity());

			}
			else {//在统计列表里未找到对应记录
				sales.push_back((*this)[i]);
			}
		}
		sales.quickSort(0, sales.size() - 1, sortByID);
	}
	else {
		for (int i = 0; i < this->size(); ++i) {//遍历销售记录
			Sale* p = sales.find((*this)[i].SaleDate(), 1);
			if (p) {//在统计列表里找到对应记录
				p->setAll(p->All() + (*this)[i].All());
				p->setQuantity(p->Quantity() + (*this)[i].Quantity());
			}
			else {//在统计列表里未找到对应记录
				sales.push_back((*this)[i]);
			}
		}
		sales.quickSort(0, sales.size() - 1, sortBySaleDate);
	}
	return sales;
}

void SaleVector::quickSort(int l,int r, int(*pr)(const Sale& s1, const Sale& s2)) {
	if (l >= r) return; 
	  //如果左边界等于或大于右边界，则不需要排序
	Sale pivot = (*this)[(l+r) / 2]; 
	  //选择中间点为基准元素
	int i = l, j = r; //设置左右指针
	while (i <= j) {
		while (pr((*this)[i], pivot) < 0) i++; 
		  //从左侧找到第一个大于等于基准元素的数
		while (pr((*this)[j], pivot) > 0) j--; 
		  //从右侧找到第一个小于等于基准元素的数
		if (i <= j) { //交换左右指针指向的元素
			swap((*this)[i], (*this)[j]);
			i++;
			j--;
		}
	}
	//递归处理左右两个子序列
	if (l < j) quickSort(l, j, pr);
	if (r > i) quickSort(i, r, pr);
}
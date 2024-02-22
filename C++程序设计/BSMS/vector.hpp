#pragma once
#ifndef VECTOR
#define VECTOR
#include<iostream>
#include<fstream>
#include<string>
#include "bread.h"
#include "sale.h"
using namespace std; 
template <class T>
class Vector {//基类
	int sz; //储存数据个数
	int cap; //最大容量
	T* buf; //指向一块连续空间的指针
public:
	Vector(int size=0, int capacity=20);  //普通构造
	Vector(const Vector& v);//拷贝构造
	void print() const;//打印
	void push_back(const T& t);  //添加一个数据
	void pop_back(); //删除最后一个数据
	bool erase(int i);//删除下标为i的数据
	int findi(T* a);//通过指针找到下标
	void clear();  //清空数组
	void swap(T& a, T& b);//交换两个数据
	const int& size()const;//返回数据个数
	bool empty(); //判断是否为空
	Vector& operator=(const Vector& v);//重载=
	T& operator[](int n); //重载[]，使得Vector[] 返回被实际储存的参数类型
	const T& operator[] (int n)const;  //同上，方便const Vector类型调用
	~Vector();//析构
};

template <class T> //普通构造
Vector<T>::Vector(int size, int capacity) :sz(size), cap(capacity) {
	buf = new T[cap];
}

template <class T>  //拷贝构造
Vector<T>::Vector(const Vector& v) {
	cap = v.cap;
	sz = v.sz;
	buf = new T[cap];
	memcpy(buf, v.buf, sz * sizeof(T));
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector& v) { //重载=
	if (buf != v.buf) {
		this->~Vector();
		new(this) Vector(v);
	}
	return *this;
}

template <class T>
void Vector<T>::print() const {
	for (int i = 0; i < sz; ++i)
		cout << buf[i];
}

template <class T>
void Vector<T>::push_back(const T& t) {
	if (sz >= cap) {  //当容量不足时
		if (!cap) cap = 20;  //容量等于0则初始化
		else cap *= 2;  //容量不等于0则翻倍
		T* p = new T[cap];  //new出新的存储空间
		memcpy(p, buf, sz * sizeof(T));  //将原存储信息拷贝
		delete[]buf;  //释放原有空间
		buf = p;  
		}
	buf[sz++] = t; //新的赋值
	}

template <class T>
void Vector<T>::swap(T& a, T& b) {
	T c = a;
	a = b;
	b = c;
}

template <class T>
void Vector<T>::pop_back() {
	sz--;
}

template <class T>
bool Vector<T>::erase(int i) {
	if (i > sz - 1 || i < 0) return 0;//不合法，删除失败
	if (i < sz - 1) {
		for (int j = i; j < sz - 1; ++j) {
			buf[j] = buf[j + 1];  
			//被删除下标后的数据都往前移动
		}
	}
	sz--;
	return 1; //删除成功1
}

template <class T>
int Vector<T>::findi(T* a) {//通过指针找到下标
	if (a) //判断a是否为NULL
	{
		for (int i = 0; i < sz; ++i)
			if (buf[i] == (*a)) return i; //找到返回下标
	}
	return -1;//未找到返回-1
}

template <class T>
const int& Vector<T>::size()const {
	return sz;
}

template <class T>
bool Vector<T>::empty() {
	return sz == 0;
}

template <class T>
void Vector<T>::clear() {
	delete[] buf;
	sz = 0;
	cap = 20;
	buf = new T[cap];
}

template <class T>
T& Vector<T>::operator[](int n) {
	return buf[n];
}

template <class T>
const T& Vector<T>::operator[] (int n) const {
	return buf[n];
}

template <class T>
Vector<T>::~Vector() {
	delete[]buf;
}


#endif

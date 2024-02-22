#include <iostream>
#include <cstring>
#include "bread.h"
using namespace std;
Bread::Bread(const char* i, const char* n , const char* m , double s , double p, int st ) 
	:basicInfo(i,n,m,s,p), store(st) {
}
Bread::Bread(const Bread& b):basicInfo(b.basicInfo),store(b.store){}
const int Bread::Store()const{ return store; }
void Bread::modStore(int& q) { store -= q; }
const Basis& Bread::BasicInfo() const { return basicInfo; }
Bread& Bread::operator=(const Bread& b) {
	basicInfo = b.basicInfo;
	store = b.store;
	return *this;
}
bool Bread::operator==(const Bread& b) {
	return (basicInfo == b.basicInfo) && (store == b.store);
}
ostream& operator<<(ostream& out, const Bread& b) {
	out << b.basicInfo;
	out << "库存数量：" << b.store << endl;
	return out;
}
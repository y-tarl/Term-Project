#include<string>
#include"manager.h"
Manager::Manager(const string n , const string p )
	:name(n), pass(p) {}

const string& Manager::Pass()const {
	return pass;
}

const string& Manager::Name()const {
	return name;
}


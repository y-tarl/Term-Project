#ifndef MANAGER
#define MANAGER
#include <string>
using namespace std;
class Manager {
    string name;
    string pass;
public:
    Manager(const string n="", const string p="");
    const string& Name()const;
    const string& Pass()const;

};
#endif 
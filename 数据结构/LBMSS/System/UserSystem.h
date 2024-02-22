//
// Created by Tarl on 2023-12-30.
//

#ifndef LBMSS_USERSYSTEM_H
#define LBMSS_USERSYSTEM_H

#include <string>
#include "../AVLTree/AVLTree.hpp"
#include "../Object/User.h"

using namespace std;

// UserSystem类定义
class UserSystem {
private:

public:
    AVLTree<User> interaction;  // 存储用户信息的AVL树

    //初始化
    void Initialization(const string &file = "../data/User.txt");

    //返回用户数
    int getNum();

    // 注册新用户
    bool Register();

    // 登陆
    Node<User> *Login();

    // 修改用户密码
    bool changePassword(Node<User> *user);

    // 查看所有用户信息
    void display();

    //保存至文件中
    void Save(const string &file = "../data/User.txt");

    // 析构函数
    ~UserSystem();
};


#endif //LBMSS_USERSYSTEM_H

//
// Created by Tarl on 2023-12-30.
//
#include <iostream>
#include <fstream>
#include <iterator>
#include "UserSystem.h"
#include "../Object/User.h"

using namespace std;


bool UserSystem::changePassword(Node<User> *user) {
    string oldPassword, newPassword, rePassword;
    cout << "请输入旧密码：" << endl;
    cin >> oldPassword;
    while ((user->data.getPassword() != oldPassword)) {
        cout << "密码错误" << endl;
        cout << "请重新输入旧密码：" << endl;
        cin >> oldPassword;
    }
    cout << "请输入新密码: ";
    cin >> newPassword;
    cout << "请再次输入新密码: ";
    cin >> rePassword;
    while (newPassword != rePassword) {
        cout << "密码不一致" << endl;
        cout << "请输入新密码: ";
        cin >> newPassword;
        cout << "请再次输入新密码: ";
        cin >> rePassword;
    }
    user->data.setPassword(newPassword);
    Save();
    cout << "密码修改成功" << endl;
    return true;
}

UserSystem::~UserSystem() {
    // 释放用户信息
    interaction.clear(interaction.root);
}

void UserSystem::Initialization(const string &file) {
    ifstream in;
    in.open(file, ios::in);
    if (!in.is_open()) {
        ofstream out;
        out.open(file, ios::out | ios::app);
        out.close();
        in.open(file, ios::in);
    } // 如果文件不存在则创建文件

    User *user = new User();
    while (in >> *user) {//只有这样才能不重复读入
        interaction.add(*user);
        user = new User();//缺点是最后新new出来的User因为最后并没有添加进树中所以无法正常析构
    }
    delete user;//添加一个析构函数
    in.close();
}

int UserSystem::getNum() {
    return interaction.num;
}

void UserSystem::Save(const string &file) {
    string Temp = "../data/User1.temp";
    //使用临时文件是更安全和可靠的文件写入方法。
    // 它可以确保在保存数据时不会丢失原始文件内容，
    // 并在写入完成后才替换原始文件，避免了意外中断或错误导致的文件损坏。
    ofstream out;
    out.open(Temp, ios::out | ios::app);
    if (!out.is_open()) {
        cout << "文件打开失败" << endl;
        return;
    }

    Node<User> *node = interaction.begin();
    while (node) {
        out << node->data << endl;
        node = node->next();
    }

    out.close();
    remove(file.c_str());
    rename(Temp.c_str(), file.c_str());
}


bool UserSystem::Register() {
    string name, password, rePassword;
    User user;
    cout << "请输入用户名: ";
    cin >> name;
    user.setUsername(name);
    if (interaction.find(user)) {
        cout << "该用户名已注册" << endl;
        return false;
    }

    cout << "请输入密码: ";
    cin >> password;
    cout << "请再次输入密码: ";
    cin >> rePassword;
    if (password != rePassword) {
        cout << "密码不一致" << endl;
        return false;
    }

    user.setPassword(password);
    interaction.add(user);
    Save();
    cout << "注册成功" << endl;
    return true;
}

Node<User> *UserSystem::Login() {
    string name, password;
    User user;
    cout << "请输入用户名: ";
    cin >> name;
    user.setUsername(name);
    Node<User> *it = interaction.find(user);
    if (!it) {
        cout << "该用户不存在" << endl;
        return nullptr;
    }
    cout << "请输入密码: ";
    cin >> password;
    if (it->data.getPassword() != password) {
        cout << "密码错误" << endl;
        return nullptr;
    }
    if (it->data.getUserType() == UserType::ADMIN) {
        cout << "管理员";
    } else {
        cout << "读者";
    }
    cout << "登录成功" << endl;
    return it;
}

void UserSystem::display() {
    interaction.show();
    cin.get();
}


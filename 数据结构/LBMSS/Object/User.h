//
// Created by Tarl on 2023-12-30.
//

#ifndef LBMSS_USERNODE_H
#define LBMSS_USERNODE_H

#include <string>
#include "../AVLTree/AVLTree.hpp"
#include "Book.h"

using namespace std;
// 定义用户类型的枚举
enum class UserType {
    ADMIN,
    GENERAL_USER
};

// 用户信息 User 类定义
class User {
private:
    string username;  // 用户名
    string password;  // 密码
    UserType userType;     // 用户类型
    AVLTree<Book> borrowedBooks;  //借阅的书  不超过10本
public:
    User() : userType(UserType::GENERAL_USER), borrowedBooks() {}

    // 构造函数
    User(string uname, string pword = "", UserType utype = UserType::GENERAL_USER);

    // 获取用户名
    string getUsername() const;

    bool lend(const Book &book);

    bool back(Node<Book> *book);

    Node<Book> *find(const Book &book);

    // 获取密码
    string getPassword() const;

    // 获取用户类型
    UserType getUserType() const;

    //获取所借书籍数
    int getNum();

    //展示已借阅书籍
    void disBook();

    //展示用户信息
    void display(ostream &os);

    // 设置用户名
    void setUsername(const string &uname);

    // 设置密码
    void setPassword(const string &pword);

    // 设置用户类型
    void setUserType(UserType utype);

    bool operator==(const User &user) const;

    bool operator<(const User &user) const;

    bool operator>(const User &user) const;

    bool operator<=(const User &user) const;

    bool operator>=(const User &user) const;

    friend ostream &operator<<(ostream &os, const User &user);

    friend istream &operator>>(istream &is, User &user);

    ~User();
};

#endif // LBMSS_USERNODE_H


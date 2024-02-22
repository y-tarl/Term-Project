//
// Created by Tarl on 2023-12-30.
//
// 构造函数
#include <iostream>
#include <string>
#include "User.h"

User::User(string uname, string pword, UserType utype)
        : username(uname), password(pword), userType(utype), borrowedBooks() {}

// 获取用户名
string User::getUsername() const {
    return username;
}

// 获取密码（通常不推荐直接返回密码，这里仅作为示例）
string User::getPassword() const {
    return password;
}

// 获取用户类型
UserType User::getUserType() const {
    return userType;
}

// 设置用户名
void User::setUsername(const string &uname) {
    username = uname;
}

// 设置密码
void User::setPassword(const string &pword) {
    password = pword;
}

// 设置用户类型
void User::setUserType(UserType utype) {
    userType = utype;
}

bool User::operator==(const User &user) const {
    return username == user.username;
}

bool User::operator<(const User &user) const {
    return username < user.username;
}

bool User::operator>(const User &user) const {
    return username > user.username;
}

bool User::operator<=(const User &user) const {
    return username <= user.username;
}

bool User::operator>=(const User &user) const {
    return username >= user.username;
}

ostream &operator<<(ostream &os, const User &user) {
    os << user.username << "   "
       << user.password << "    ";
    if (user.userType == UserType::ADMIN) {
        os << "ADMIN\n";
    } else {
        os << "GENERAL_USER" << "  "
           << "借阅书籍共 " << user.borrowedBooks.getNum() << " 册\n";
        if (user.borrowedBooks.getNum()) {
//            os<<endl;
            user.borrowedBooks.show(os);
        }
    }
    return os;
}

istream &operator>>(istream &is, User &user) {
    string utypy, info;
    int n;
    is >> user.username >> user.password >> utypy;
    if (utypy == "ADMIN") user.userType = UserType::ADMIN;
    else {
        user.userType = UserType::GENERAL_USER;
        is >> info >> n >> info;
        if (n) {
            Book book;
            while (n--) {
                is >> book;
                user.borrowedBooks.add(book);
            }
        }
    }
    return is;
}

User::~User() {
    borrowedBooks.clear(borrowedBooks.root);
}

bool User::lend(const Book &book) {
    if (borrowedBooks.num < 10) {
        if (borrowedBooks.add(book)) {
            cout << "借阅成功" << endl;
            return true;
        } else {
            cout << "您已借阅过该书籍，借阅失败" << endl;
        }
    } else {
        cout << "借阅图书已达最大上限10本  借阅失败\n";
        return false;
    }
}

bool User::back(Node<Book> *book) {
    borrowedBooks.remove(book);
    cout << "归还成功" << endl;
    return true;

}

Node<Book> *User::find(const Book &book) {
    return borrowedBooks.find(book);
}

int User::getNum() {
    return borrowedBooks.getNum();
}

void User::disBook() {
//    borrowedBooks.show();
    if (!borrowedBooks.getNum()) {
        cout << "用户：" << getUsername() << " 无借阅书籍\n";
    } else {
        cout << "用户：" << getUsername() << " 共借阅书籍 " << borrowedBooks.getNum() << " 本：\n";
        Node<Book> *book = borrowedBooks.begin();
        while (book) {
            book->data.display(cout);
            book = book->next();
        }
    }
}

void User::display(ostream &os) {
    cout
            << "*************************************************************************************************************************\n";
    os << "用户名：" << username << "   "
       << "密码：" << password << "    ";
    if (userType == UserType::ADMIN) {
        os << "用户类型：" << "ADMIN\n";
    } else {
        os << "GENERAL_USER" << "  "
           << "借阅书籍共 " << borrowedBooks.getNum() << " 册\n";
        if (borrowedBooks.getNum()) {
//            os<<endl;
            borrowedBooks.show();//带书籍信息提示符
        }
    }
}

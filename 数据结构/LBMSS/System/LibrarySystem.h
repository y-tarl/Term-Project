//
// Created by Tarl on 2023-12-30.
//

#ifndef LBMSS_LIBRARYSYSTEM_H
#define LBMSS_LIBRARYSYSTEM_H

#include "../AVLTree/AVLTree.hpp"
#include "../Object/Book.h"
#include "../Object/User.h"

class LibrarySystem {
    void printIDAUX(int indent, const Node<Book> *root) const;

    Node<Book> *findByOther(const Book &book);//根据ISBN和标题查找辅助函数
public:
    AVLTree<Book> library;

    void initialization(const string &file = "../data/Library.txt");

    void add();

    void save(const string &file = "../data/Library.txt");

    void display();

    void printID() const;

    Node<Book> *findByID();

    Node<Book> *findByISBN();

    Node<Book> *findByTitle();

    //修改图书信息,choice表示查找书籍的方式，1表示图书ID，2表示图书IBSN，3表示图书标题
    void Change(int choice);

    //删除图书,choice表示查找书籍的方式，1表示图书ID，2表示图书IBSN，3表示图书标题
    void Remove(int choice);

    // 借出书籍
    void Lend(Node<User> *user);

    // 归还书籍
    void Return(Node<User> *user);

    ~LibrarySystem();
};


#endif //LBMSS_LIBRARYSYSTEM_H

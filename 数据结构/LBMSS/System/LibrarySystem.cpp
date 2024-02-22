//
// Created by Tarl on 2023-12-30.
//
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
#include "LibrarySystem.h"
#include "../Menu/Menu.h"

using namespace std;

void LibrarySystem::initialization(const string &file) {

    ifstream in;
    in.open(file, ios::in);
    if (!in.is_open()) {
        ofstream out;
        out.open(file, ios::out | ios::app);
        out.close();
        in.open(file, ios::in);
    } // 如果文件不存在则创建文件

    Book book;
    while (in >> book) {
//        in >> book;
        library.add(book);
    }
    in.close();
}

void LibrarySystem::save(const string &file) {
    string Temp = "../data/temp.txt";
    //使用临时文件是更安全和可靠的文件写入方法。
    // 它可以确保在保存数据时不会丢失原始文件内容，
    // 并在写入完成后才替换原始文件，避免了意外中断或错误导致的文件损坏。
    ofstream out;
    out.open(Temp, ios::out | ios::app);
    if (!out.is_open()) {
        cout << "文件打开失败" << endl;
        return;
    }

    Node<Book> *node = library.begin();
    while (node) {
        out << node->data << endl;
        node = node->next();
    }

    out.close();
    remove(file.c_str());
    rename(Temp.c_str(), file.c_str());

}

void LibrarySystem::display() {
    Node<Book> *book = library.begin();
    while (book) {
        book->data.display();
        book = book->next();
    }
    cin.get();
}


void LibrarySystem::printID() const {
    printIDAUX(0, library.Root());
}

void LibrarySystem::printIDAUX(int indent, const Node<Book> *root) const {
    if (root) {
        printIDAUX(indent + 8, root->right);
        cout << setw(indent) << " " << root->data.getBookID() << endl;
        printIDAUX(indent + 8, root->left);
    } else return;
}

Node<Book> *LibrarySystem::findByID() {
    cout << "----------------------------------------------------------------"
         << endl;
    int id;
    cout << "请输入查询书籍编号: ";
    cin >> id;

    Book book(id);
    Node<Book> *iter = library.find(book);

    if (!iter) {
        cout << "未找到该书籍" << endl;
    } else {
        cout << "该书信息如下：\n\n";
        iter->data.display();
    }

    cout << "是否继续查询 (输入y/yes继续)\n->  ";
    string flag;
    cin.get();
    getline(cin, flag);
    if (flag == "y" || flag == "yes") {
        findByID();
    }
    return iter;
}

Node<Book> *LibrarySystem::findByISBN() {
    cout << "----------------------------------------------------------------"
         << endl;
    string ISBN;
    cout << "请输入查询书籍ISBN: ";
    cin >> ISBN;
    Book book;
    book.setISBN(ISBN);
    Node<Book> *node = findByOther(book);
    if (node) {
        cout << "该书信息如下：\n\n";
        node->data.display();
    } else {
        cout << "该ISBN码不存在" << endl;
    }
    cout << "是否继续查询 (输入y/yes继续)\n->  ";
    string confirm;
    cin.get();
    getline(cin, confirm);
    if (confirm == "y" || confirm == "yes") {
        findByISBN();
    }
}

Node<Book> *LibrarySystem::findByTitle() {
    cout << "----------------------------------------------------------------"
         << endl;
    string title;
    cout << "请输入查询书籍的标题: ";
    cin >> title;
    Book book;
    book.setTitle("《" + title + "》");
    Node<Book> *node = findByOther(book);
    if (node) {
        cout << "该书信息如下：\n\n";
        node->data.display();
    } else {
        cout << "未找到该书籍" << endl;
    }
    cout << "是否继续查询 (输入y/yes继续)\n->  ";
    string confirm;
    cin.get();
    getline(cin, confirm);
    if (confirm == "y" || confirm == "yes") {
        findByTitle();
    }
}

Node<Book> *LibrarySystem::findByOther(const Book &book) {
    Node<Book> *node = library.begin();
    while (node && node->data != book) {
        node = node->next();
    }
    return node;
}

void LibrarySystem::add() {
    Book book;
    book.input();

    cout << "添加书籍信息: " << endl << "书籍ID: " << book.getBookID()
         << "ISBN: " << book.getISBN() << "  书籍名称: " << book.getTitle() << "  作者: " << book.getAuthor()
         << "  出版社: " << book.getPublisher() << "  出版年份: " << book.getPublicationDate()
         << "  书籍库存数量: " << book.getQuantity() << endl;
    cout << "------------------" << endl;
    cout << "请确认添加书籍信息(输入y/yes确认)\n-> ";

    string flag;
    cin.get();
    getline(cin, flag);
    if (flag == "y" || flag == "yes") {
        if (library.add(book)) {
            save();
            cout << "添加成功" << endl;
        }
    } else {
        cout << "取消添加" << endl;
    }
    cout << "是否继续添加书籍 (输入y/yes确认)\n->   ";
    getline(cin, flag);
    if (flag == "y" || flag == "yes") {
        add();
    }
}

LibrarySystem::~LibrarySystem() {
    library.clear(library.root);
}

void LibrarySystem::Return(Node<User> *user) {
    if (user->data.getNum() == 0) {
        cout << "该用户未借阅过书籍\n";
        return;
    }
    int id;
    cout << "请输入待归还的书籍编号: ";
    cin >> id;
    Book book(id);
    Node<Book> *iter = library.find(book);//图书馆里的图书
    Node<Book> *bookOfUser = user->data.find(book);//用户借阅的图书
    if (iter) {
        if (!bookOfUser) {
            cout << "用户" << user->data.getUsername() << "所借书籍中并未找到该书籍" << endl;
            cin.get();
        } else {
            cout << "待归还书籍信息: " << endl;
            cout << "书籍编号: " << iter->data.getBookID() << "  ISBN: " << iter->data.getISBN()
                 << "  书籍名称: " << iter->data.getTitle() << "  作者: " << iter->data.getAuthor()
                 << "  出版社: " << iter->data.getPublisher()
                 << "  出版日期: " << iter->data.getPublicationDate() << "  借阅人: " << user->data.getUsername()
                 << endl;
            cout << "请确认归还书籍(输入y/yes确认)\n-> ";
            string confirm;
            cin.get();
            getline(cin, confirm);
            if (confirm == "y" || confirm == "yes") {
                iter->data.increaseQuantity();
                user->data.back(bookOfUser);
                save();
            } else {
                cout << "取消归还" << endl;
            }
        }
    } else {
        cout << "图书馆中未找到该书籍" << endl;
        cin.get();
    }

    cout << "是否继续归还书籍 (输入y/yes继续)\n->   ";
    string confirm;
    getline(cin, confirm);
    if (confirm == "y" || confirm == "yes") {
        Return(user);
    }
}

void LibrarySystem::Lend(Node<User> *user) {
    int id;
    string borrower;

    cout << "请输入待借阅的书籍编号: ";
    cin >> id;
    Book book(id);
    Node<Book> *iter = library.find(book);
    if (iter) {
        if (!iter->data.getBorrowedStatus()) {
            cout << "该书籍暂时不可被借阅" << endl;
            cin.get();
        } else {
            cout << "待借阅书籍信息: " << endl; // 书籍编号  ISBN  书籍名称  作者  出版社  出版年份  借阅人
            cout << "书籍编号: " << iter->data.getBookID() << "  ISBN: " << iter->data.getISBN()
                 << "  书籍名称: " << iter->data.getTitle() << "  作者: " << iter->data.getAuthor()
                 << "  出版社: " << iter->data.getPublisher()
                 << "  出版日期: " << iter->data.getPublicationDate() << "  借阅人: " << user->data.getUsername()
                 << endl;
            cout << "------------------" << endl;
            cout << "请确认借阅书籍(输入y/yes确认)\n-> ";
            string confirm;
            cin.get();
            getline(cin, confirm);
            if (confirm == "y" || confirm == "yes") {
                iter->data.decreaseQuantity();
                book = iter->data;
                book.setQuantity(1);
                user->data.lend(book);
                save();
            } else {
                cout << "取消借阅" << endl;
            }
        }
    } else {
        cout << "未找到该书籍" << endl;
        cin.get();
    }

    cout << "是否继续借阅书籍 (输入y/yes继续)\n-> ";
    string confirm;
    getline(cin, confirm);
    if (confirm == "y" || confirm == "yes") {
        Lend(user);
    }
}

void LibrarySystem::Change(int choice) {
    Book book;
    Node<Book> *iter;
    switch (choice) {
        case 1: {
            int id;
            cout << "请输入待修改的书籍编号: ";
            cin >> id;
            book.setBookID(id);
            iter = library.find(book);
            break;
        }
        case 2: {
            string ISBN;
            cout << "请输入待修改的书籍ISBN: ";
            cin >> ISBN;
            book.setISBN(ISBN);
            iter = findByOther(book);
            break;
        }
        case 3: {
            string title;
            cout << "请输入待修改的书籍标题: ";
            cin >> title;
            book.setTitle("《" + title + "》");
            iter = findByOther(book);
            break;
        }
    }


    if (iter) {
        cout << "原书籍信息: " << endl
             << "书籍编号: " << iter->data.getBookID() << "  ISBN: " << iter->data.getISBN()
             << "  书籍名称: " << iter->data.getTitle() << "  作者: " << iter->data.getAuthor()
             << "  出版社: " << iter->data.getPublisher() << "  出版日期: " << iter->data.getPublicationDate()
             << "  书籍库存数量: " << iter->data.getQuantity() << endl
             << "确认是否修改(输入y/yes确认)\n-> ";
        string flag;
        cin.get();
        getline(cin, flag);
        if (flag == "y" || flag == "yes") {
            string name, author, ISBN, publisher, date;
            int qty;

            cout << "请输入修改后的ISBN码(若不修改，输入0): ";
            cin >> ISBN;
            if (ISBN == "0") {
                ISBN = iter->data.getISBN();
            }
            cout << "请输入修改后的书籍名称(若不修改，输入0): ";
            cin >> name;
            if (name == "0") {
                name = iter->data.getTitle();
            } else {
                name = "《" + name + "》";
            }

            cout << "请输入修改后的作者(若不修改，输入0): ";
            cin >> author;
            if (author == "0") {
                author = iter->data.getAuthor();
            }

            cout << "请输入修改后的出版社(若不修改，输入0): ";
            cin >> publisher;
            if (publisher == "0") {
                publisher = iter->data.getPublisher();
            }

            cout << "请输入修改后的出版日期(若不修改，输入0): ";
            cin >> date;
            book.setPublicationDate(date);
            while (date != "0" && !book.dataIsValue()) {//出版日期合法性判断（满足格式且日期合法）
                Menu::reenter();
                cout << "请输入修改后的出版日期(格式：yyyy-mm-dd  若不修改，输入0): ";
                cin >> date;
                book.setPublicationDate(date);
            }
            if (date == "0") {
                date = iter->data.getPublicationDate();
            }

            bool f = true;
            cout << "请输入修改后的书籍库存数量(若不修改，输入-1): ";
            cin >> qty;
            if (qty == -1) {
                qty = iter->data.getQuantity();
            } else if (qty == 0) {
                cout << "数量为0书籍将不可借阅\n";
                f = false;
            } else if (iter->data.getQuantity() == 0 && qty) {
                cout << "书籍将重新可被借阅\n";
            }

            cout << "------------------" << endl;
            cout << "修改后的书籍信息:" << endl;
            cout << "书籍编号: " << iter->data.getBookID() << "  ISBN: " << ISBN << "   书籍名称: " << name << "  作者: "
                 << author
                 << "  出版社: " << publisher << "  出版日期: " << date << " 书籍库存数量： " << qty << endl;
            cout << "请确认修改后的书籍信息(输入y/yes确认)\n-> ";

            cin.get();
            getline(cin, flag);
            if (flag == "y" || flag == "yes") {
                iter->data.setISBN(ISBN);
                iter->data.setTitle(name);
                iter->data.setAuthor(author);
                iter->data.setPublisher(publisher);
                iter->data.setPublicationDate(date);
                iter->data.setQuantity(qty);
                iter->data.setBorrowedStatus(f);
                cout << "修改成功" << endl;
                save();
            } else {
                cout << "取消修改" << endl;
            }
        } else {
            cout << "取消修改" << endl;
        }
    } else {
        cout << "未找到该书籍" << endl;
//        cin.get();
    }

    cout << "是否继续修改书籍信息 (输入y/yes继续)\n-> ";
    cin.get();
    string confirm;
    getline(cin, confirm);
    if (confirm == "y" || confirm == "yes") {
        Change(choice);
    }

}

void LibrarySystem::Remove(int choice) {
    Book book;
    Node<Book> *iter;
    switch (choice) {
        case 1: {
            int id;
            cout << "请输入待删除的书籍编号: ";
            cin >> id;
            book.setBookID(id);
            iter = library.find(book);
            break;
        }
        case 2: {
            string ISBN;
            cout << "请输入待删除的书籍ISBN: ";
            cin >> ISBN;
            book.setISBN(ISBN);
            iter = findByOther(book);
            break;
        }
        case 3: {
            string title;
            cout << "请输入待删除的书籍标题: ";
            cin >> title;
            book.setTitle("《" + title + "》");
            iter = findByOther(book);
            break;
        }
    }


    if (iter) {
        cout << "书籍信息: " << endl;
        iter->data.display();
        cout << "确认是否删除(输入y/yes确认)\n-> ";
        string flag;
        cin.get();
        getline(cin, flag);
        if (flag == "y" || flag == "yes") {
            library.remove(iter);
            cout << "删除成功" << endl;
            save();
        } else {
            cout << "取消删除" << endl;
        }
    } else {
        cout << "未找到该书籍" << endl;
        cin.get();
    }
    cout << "是否继续删除书籍 (输入y/yes继续)\n-> ";
    string confirm;
    getline(cin, confirm);
    if (confirm == "y" || confirm == "yes") {
        Remove(choice);
    }
}








//
// Created by Tarl on 2023-12-30.
//
#include <iostream>
#include <fstream>
#include "Book.h"
#include "../Menu/Menu.h"

using namespace std;

//出版日期合法性判断（满足格式且合法）
bool Book::dataIsValue() {
    if (publicationDate.size() != 10) {
        cout << "日期格式错误！\n";
        return 0;
    }
    if ((publicationDate[4] != '-') || (publicationDate[7] != '-')) {
        cout << "日期格式错误！\n";
        return 0;
    }
    int Day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year = stoi(publicationDate.substr(0, 4));
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) Day[2] = 29;
    int month = stoi(publicationDate.substr(5, 2));
    int day = stoi(publicationDate.substr(8, 2));
    if (month >= 13 || month < 0 || day < 0 || (Day[month] < day)) {
        cout << "日期不合法！\n";
        return 0;
    }
    return 1;
}

// Constructor
Book::Book(int id, const string &bookTitle, const string &bookAuthor,
           const string &bookPublisher, const string &date, const string &isbn,
           int qty)
        : bookID(id), title(bookTitle), author(bookAuthor), publisher(bookPublisher),
          publicationDate(date), ISBN(isbn), quantity(qty) {
    if (qty > 0) borrowingStatus = true;
}

// Getters
int Book::getBookID() const {
    return bookID;
}

string Book::getTitle() const {
    return title;
}

string Book::getAuthor() const {
    return author;
}

string Book::getPublisher() const {
    return publisher;
}

string Book::getPublicationDate() const {
    return publicationDate;
}

string Book::getISBN() const {
    return ISBN;
}

bool Book::getBorrowedStatus() const {
    return borrowingStatus;
}

int Book::getQuantity() const {
    return quantity;
}

// Setters
void Book::setBookID(int id) {
    bookID = id;
}

void Book::setBorrowedStatus(bool status) {
    borrowingStatus = status;
}

void Book::setTitle(const std::string &newTitle) {
    title = newTitle;
}

void Book::setAuthor(const std::string &newAuthor) {
    author = newAuthor;
}

void Book::setPublisher(const std::string &newPublisher) {
    publisher = newPublisher;
}

void Book::setPublicationDate(const std::string &newPublicationDate) {
    publicationDate = newPublicationDate;
}

void Book::setISBN(const std::string &newISBN) {
    ISBN = newISBN;
}


void Book::setQuantity(int newQuantity) {
    quantity = newQuantity;
}

void Book::decreaseQuantity() {
    if (quantity > 0) {
        quantity--;
    }
    if (quantity == 0)
        setBorrowedStatus(false);
}

void Book::increaseQuantity() {
    quantity++;
}

bool Book::operator==(const Book &book) const {
    return book.bookID == bookID || book.title == title || book.ISBN == ISBN;
}

bool Book::operator!=(const Book &book) const {
    return !(book == *this);
}


bool Book::operator<(const Book &book) const {
    return bookID < book.bookID;
}

bool Book::operator>(const Book &book) const {
    return bookID > book.bookID;
}

bool Book::operator<=(const Book &book) const {
    return bookID <= book.bookID;
}


bool Book::operator>=(const Book &book) const {
    return bookID >= book.bookID;
}

ostream &operator<<(ostream &os, const Book &book) {
    os << book.bookID << "    "
       << book.title << "    "
       << book.author << "    "
       << book.publisher << "    "
       << book.publicationDate << "    "
       << book.ISBN << "    "
       << book.quantity << "    \n";
    return os;
}

istream &operator>>(istream &is, Book &book) {
    is >> book.bookID >> book.title >> book.author >> book.publisher >> book.publicationDate >> book.ISBN
       >> book.quantity;
    if (book.quantity > 0) {
        book.borrowingStatus = true;
    } else {
        book.borrowingStatus = false;
    }
    return is;
}

void Book::input() {
    cout << "请输入图书ID: ";
//    Menu::pointer();
    cin >> bookID;

    cout << "请输入图书标题: ";
    cin.ignore(); // 忽略上一个输入流中的换行符
//    Menu::pointer();
    getline(cin, title);
    title = "《" + title + "》";
    cout << "请输入作者: ";
//    Menu::pointer();
    getline(cin, author);

    cout << "请输入出版社: ";
//    Menu::pointer();
    getline(cin, publisher);

    cout << "请输入出版日期（格式:yyyy-mm-dd）: ";
//    Menu::pointer();
    cin >> publicationDate;
    while (!dataIsValue()) {
        Menu::reenter();
//        Menu::pointer();
        cout << "请输入出版日期（格式:yyyy-mm-dd）: ";
        cin >> publicationDate;
    }
//     getline(cin,  publicationDate);

    cout << "请输入ISBN: ";
//    Menu::pointer();
    cin.ignore(); // 忽略上一个输入流中的换行符
    getline(cin, ISBN);

    cout << "请输入可借状态 (是/否): ";
//    Menu::pointer();
    string borrowed;
    cin >> borrowed;
    while (borrowed != "是" && borrowed != "否") {
        Menu::reenter();
//        Menu::pointer();
        cout << "请输入可借状态 (是/否): ";
        cin >> borrowed;
    }
    borrowingStatus = (borrowed == "是");

    if (borrowingStatus) {
        cout << "请输入库存数量（单位：本）: ";
//        Menu::pointer();
        cin >> quantity;
        while (quantity < 0) {
            Menu::reenter();
//            Menu::pointer();
            cout << "请输入库存数量（单位：本）: ";
            cin >> quantity;
        }
    } else quantity = 0;
}

void Book::display() {//图书馆中的图书信息
    cout << "图书ID: " << bookID << "\n"
         << "标题: " << title << "\n"
         << "作者: " << author << "\n"
         << "出版社: " << publisher << "\n"
         << "出版日期: " << publicationDate << "\n"
         << "ISBN: " << ISBN << "\n"
         << "可借状态: " << (borrowingStatus ? "是" : "否") << "\n"
         << "库存数量: " << quantity << "\n\n";
}

void Book::display(ostream &ou) {//用户信息下的图书信息
    ou << "图书ID: " << bookID << "   "
       << "标题: " << title << "   "
       << "作者: " << author << "   "
       << "出版社: " << publisher << "   "
       << "出版日期: " << publicationDate << "   "
       << "ISBN: " << ISBN << "   "
       << "借阅数量：" << quantity << "\n";
}






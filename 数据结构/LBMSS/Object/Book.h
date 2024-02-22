
#ifndef LBMSS_BOOK_H
#define LBMSS_BOOK_H

#include <string>

using namespace std;

class Book {
private:
    int bookID; //图书ID
    string title; //标题
    string author;//作者
    string publisher;//出版社
    string publicationDate;//出版日期
    string ISBN;//ISBN码
    bool borrowingStatus;//可借状态，当书籍数量被置为0时，为不可借阅
    int quantity;//库存数量

public:
    Book() = default;

    // Constructor
    Book(int id, const string &bookTitle = "", const string &bookAuthor = "",
         const string &bookPublisher = "", const string &date = "", const string &isbn = "",
         int qty = 0);

    void input();//从键盘输入

    void display();//图书馆中的展示的图书信息

    void display(ostream &ou);//读者中的展示的图书信息

    // Getters
    int getBookID() const;

    string getTitle() const;

    string getAuthor() const;

    string getPublisher() const;

    string getPublicationDate() const;

    string getISBN() const;

    bool getBorrowedStatus() const;

    int getQuantity() const;

    // Setters
    void setBookID(int id);

    // 设置书的标题
    void setTitle(const std::string &newTitle);

    // 设置书的作者
    void setAuthor(const std::string &newAuthor);

    // 设置书的出版社
    void setPublisher(const std::string &newPublisher);

    // 设置书的出版日期
    void setPublicationDate(const std::string &newPublicationDate);

    // 设置书的ISBN
    void setISBN(const std::string &newISBN);

    // 设置书的数量
    void setQuantity(int newQuantity);

    // 设置书的借阅状态
    void setBorrowedStatus(bool status);

    void decreaseQuantity();

    void increaseQuantity();

    bool dataIsValue();//出版日期合法性判断（满足格式且合法）

    //operator
    bool operator==(const Book &book) const;

    bool operator!=(const Book &book) const;

    bool operator<(const Book &book) const;

    bool operator>(const Book &book) const;

    bool operator<=(const Book &book) const;

    bool operator>=(const Book &book) const;

    friend ostream &operator<<(ostream &os, const Book &book);//输出到文件

    friend istream &operator>>(istream &is, Book &book);//读入文件

    ~Book() = default;
};


#endif //LBMSS_BOOK_H

#include <iostream>
using namespace std;

class Book
{
private:
    string BookName;        //书名
    string Published;       //出版社
    double Price;           //价格

public:
    Book(string name, string pub, double pri = 0):BookName(name),Published(pub),Price(pri){}
    string getBookName() {return BookName;}
    string getPublished() {return Published;}
    double getPrice() {return Price;}
    void setBookName(string name);
    void setPublished(string pub);
    void setPrice(double pri);
};
class ChildrenBook:public Book  //儿童图书
{
private:
    string AgeRange;
public:
    ChildrenBook(string c_name, string c_pub, double c_pri, string range):Book(c_name, c_pub, c_pri),AgeRange(range){}
    string getAgeRange() {return AgeRange;}
    void setgetAgeRange(string range);
};
class TeachBook:public Book     //教科书
{
private:
    int ApplicableGrade;    //适用年级
    string Category;
public:
    TeachBook(string t_name, string t_pub, double t_pri, int grade, string cate):Book(t_name, t_pub, t_pri),ApplicableGrade(grade),Category(cate){}
    int getApplicableGrade(){return ApplicableGrade;}
    string getCategory(){return Category;}
    void setApplicableGrade(int grade);
    void setCategory(string cate);
};
void Book::setBookName(string name){
    this->BookName = name;
}
void Book::setPrice(double pri){
    this->Price = pri;
}
void Book::setPublished(string pub){
    this->Published = pub;
}
void ChildrenBook::setgetAgeRange(string range){
    this->AgeRange = range;
}
void TeachBook::setApplicableGrade(int grade){
    this->ApplicableGrade = grade;
}
void TeachBook::setCategory(string cate){
    this->Category = cate;
}


int main(){
    Book b("《海底两万里》","新华出版社",30.20);
    ChildrenBook cb("《小猪佩奇》","新华出版社",23.80,"6-8岁"); 
    TeachBook tb("《中国上下五千年》","清华出版社",63.10,9,"历史");  
    
    //test for Book
    cout << "书名: " << b.getBookName() << endl;
    cout << "出版社: " << b.getPublished() << endl;
    cout << "价格: " << b.getPrice() << endl;
    cout << "-------------------------" << endl;

    //test for ChildrenBook
    cout << "书名: " << cb.getBookName() << endl;
    cout << "出版社: " << cb.getPublished() << endl;
    cout << "价格: " << cb.getPrice() << endl;
    cout << "适用年龄段: " << cb.getAgeRange() << endl;
    cout << "-------------------------" << endl;
    cb.setBookName("《算法设计与分析》");
    cb.setgetAgeRange("18-24");
    cb.setPrice(28.9);
    cout << "书名: " << cb.getBookName() << endl;
    cout << "出版社: " << cb.getPublished() << endl;
    cout << "价格: " << cb.getPrice() << endl;
    cout << "适用年龄段: " << cb.getAgeRange() << endl;
    cout << "-------------------------" << endl;
    //test for TeachBook
    cout << "书名: " << tb.getBookName() << endl;
    cout << "出版社: " << tb.getPublished() << endl;
    cout << "价格: " << tb.getPrice() << endl;
    cout << "类别: " << tb.getCategory() << endl;
    cout << "适用年级: " << tb.getApplicableGrade() << endl;
    system("pause");
    return 0;
}

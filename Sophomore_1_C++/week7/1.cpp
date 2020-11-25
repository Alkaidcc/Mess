#include <iostream>
using namespace std;

class Book
{
private:
    string BookName;        //����
    string Published;       //������
    double Price;           //�۸�

public:
    Book(string name, string pub, double pri = 0):BookName(name),Published(pub),Price(pri){}
    string getBookName() {return BookName;}
    string getPublished() {return Published;}
    double getPrice() {return Price;}
    void setBookName(string name);
    void setPublished(string pub);
    void setPrice(double pri);
};
class ChildrenBook:public Book  //��ͯͼ��
{
private:
    string AgeRange;
public:
    ChildrenBook(string c_name, string c_pub, double c_pri, string range):Book(c_name, c_pub, c_pri),AgeRange(range){}
    string getAgeRange() {return AgeRange;}
    void setgetAgeRange(string range);
};
class TeachBook:public Book     //�̿���
{
private:
    int ApplicableGrade;    //�����꼶
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
    Book b("�����������","�»�������",30.20);
    ChildrenBook cb("��С�����桷","�»�������",23.80,"6-8��"); 
    TeachBook tb("���й�������ǧ�꡷","�廪������",63.10,9,"��ʷ");  
    
    //test for Book
    cout << "����: " << b.getBookName() << endl;
    cout << "������: " << b.getPublished() << endl;
    cout << "�۸�: " << b.getPrice() << endl;
    cout << "-------------------------" << endl;

    //test for ChildrenBook
    cout << "����: " << cb.getBookName() << endl;
    cout << "������: " << cb.getPublished() << endl;
    cout << "�۸�: " << cb.getPrice() << endl;
    cout << "���������: " << cb.getAgeRange() << endl;
    cout << "-------------------------" << endl;
    cb.setBookName("���㷨����������");
    cb.setgetAgeRange("18-24");
    cb.setPrice(28.9);
    cout << "����: " << cb.getBookName() << endl;
    cout << "������: " << cb.getPublished() << endl;
    cout << "�۸�: " << cb.getPrice() << endl;
    cout << "���������: " << cb.getAgeRange() << endl;
    cout << "-------------------------" << endl;
    //test for TeachBook
    cout << "����: " << tb.getBookName() << endl;
    cout << "������: " << tb.getPublished() << endl;
    cout << "�۸�: " << tb.getPrice() << endl;
    cout << "���: " << tb.getCategory() << endl;
    cout << "�����꼶: " << tb.getApplicableGrade() << endl;
    system("pause");
    return 0;
}

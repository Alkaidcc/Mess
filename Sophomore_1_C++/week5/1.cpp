#include <iostream>
using namespace std;

class BookSale
{
private:
    string No;
    string Name;
    double Price;
    static int Num;
    static int Sum;
public:
    BookSale();
    BookSale(string no, string name, double price);
    void disp();
    ~BookSale();
    static double sum();
    
};

void BookSale::disp(){
    cout << "���: " << No << endl;
    cout << "����: " << Name << endl;
    cout << "�۸�: " << Price << endl;
}

double BookSale::sum(){
    return Sum;
}
BookSale::BookSale()
{
    Num++;
}
BookSale::BookSale(string no, string name, double price){
    Num++;
    No = no;
    Name = name;
    Price = price;
    Sum += Price;
}

BookSale::~BookSale()
{
}

int BookSale::Num = 0;
int BookSale::Sum = 0;
int main(){
    BookSale b1("11192", "������СŮ��", 29.8);
    BookSale b2("12584", "�����뺣",30.6);
    b1.disp();
    b2.disp();
    cout << "���������ܽ� " << BookSale::sum() << endl;
    system("pause");
    return 0;
}

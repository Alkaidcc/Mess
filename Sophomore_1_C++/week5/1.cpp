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
    cout << "编号: " << No << endl;
    cout << "姓名: " << Name << endl;
    cout << "价格: " << Price << endl;
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
    BookSale b1("11192", "卖火柴的小女孩", 29.8);
    BookSale b2("12584", "老人与海",30.6);
    b1.disp();
    b2.disp();
    cout << "已卖出的总金额： " << BookSale::sum() << endl;
    system("pause");
    return 0;
}

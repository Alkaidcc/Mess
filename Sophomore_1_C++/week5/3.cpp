#include <iostream>
using namespace std;

class Restaurant
{
private:
    string productName;
    double Price;
    int Num;
    static int customerNumber;
    static double Sum;
public:
    Restaurant();
    Restaurant(string name, double price,int num=1);
    static int getCustomerNumber(){return customerNumber;}
    void disp();
    static double getAveragePrice(){return Sum/customerNumber;}
    ~Restaurant();
};

Restaurant::Restaurant(string name, double price,int num){
    productName = name;
    Num = num;
    Price = price;
    customerNumber++;
    Sum+=price * num;
}
int Restaurant::customerNumber = 0;
double Restaurant::Sum = 0;
void Restaurant::disp(){
    cout << productName << endl;
    cout << "价格: " << Price << "元" << endl;
    cout << "购买了 " << Num << " 件" << endl;
}
Restaurant::Restaurant()
{
}
Restaurant::~Restaurant()
{
}
int main(){
    Restaurant a("红烧猪蹄",15);
    Restaurant b("关东煮",20,2);
    Restaurant c("西红柿炒蛋",7,2);
    a.disp();
    b.disp();
    c.disp();
    cout << "今天共接待 " << Restaurant::getCustomerNumber() << " 位顾客";
    cout << "人均消费额为：";
    cout << Restaurant::getAveragePrice() << endl;
    system("pause");
    return 0;
}

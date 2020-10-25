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
    cout << "�۸�: " << Price << "Ԫ" << endl;
    cout << "������ " << Num << " ��" << endl;
}
Restaurant::Restaurant()
{
}
Restaurant::~Restaurant()
{
}
int main(){
    Restaurant a("��������",15);
    Restaurant b("�ض���",20,2);
    Restaurant c("����������",7,2);
    a.disp();
    b.disp();
    c.disp();
    cout << "���칲�Ӵ� " << Restaurant::getCustomerNumber() << " λ�˿�";
    cout << "�˾����Ѷ�Ϊ��";
    cout << Restaurant::getAveragePrice() << endl;
    system("pause");
    return 0;
}

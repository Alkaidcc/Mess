#include <iostream>
using namespace std;

class MilkTeaShop
{
private:
    string Milktea;
    double Price;
    int Num;
    static double Sum;
public:
    MilkTeaShop();
    MilkTeaShop(string name, double price,int num=1);
    void disp();
    static double getSum(){return Sum;}
    ~MilkTeaShop();
};

MilkTeaShop::MilkTeaShop(string name, double price,int num){
    Milktea = name;
    Price = price;
    Num = num;
    Sum+=price * num;
}
double MilkTeaShop::Sum = 0;
void MilkTeaShop::disp(){
    cout << Milktea << endl;;
    cout << "价格: " << Price << "元" << endl;
    cout << "共" << Num << "杯" << endl;
}
MilkTeaShop::MilkTeaShop()
{
}
MilkTeaShop::~MilkTeaShop()
{
}
int main(){
    MilkTeaShop a("卡布奇诺",28.7);
    MilkTeaShop b("星冰乐",52,2);
    MilkTeaShop c("杨枝甘露",18,4);
    a.disp();
    b.disp();
    c.disp();
    cout << "今天的营业额为：";
    cout << MilkTeaShop::getSum() << endl;
    system("pause");
    return 0;
}

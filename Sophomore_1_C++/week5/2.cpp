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
    cout << "�۸�: " << Price << "Ԫ" << endl;
    cout << "��" << Num << "��" << endl;
}
MilkTeaShop::MilkTeaShop()
{
}
MilkTeaShop::~MilkTeaShop()
{
}
int main(){
    MilkTeaShop a("������ŵ",28.7);
    MilkTeaShop b("�Ǳ���",52,2);
    MilkTeaShop c("��֦��¶",18,4);
    a.disp();
    b.disp();
    c.disp();
    cout << "�����Ӫҵ��Ϊ��";
    cout << MilkTeaShop::getSum() << endl;
    system("pause");
    return 0;
}

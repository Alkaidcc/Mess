//��һ����ͨ������vehicle��������Ϊ����������С����car���ִ���boat���붨����Щ�ಢͨ���麯������ʾ�������Ϣ��
#include <iostream>
#include <string.h>
using namespace std;

class vehicle
{
protected:
    string Name;
public:
    vehicle(string name):Name(name){}
    virtual void showInfo() = 0;
};
class car:public vehicle
{
private:

public:
    car(string s):vehicle(s){}
    virtual void showInfo(){cout << Name << endl;}
};
class boat:public vehicle
{
private:

public:
    boat(string s):vehicle(s){}
    virtual void showInfo(){cout << Name << endl;}
};




int main(){
    vehicle* p;
    car c("����");
    boat b("�ִ�");
    //test for car boat
    c.showInfo();
    b.showInfo();
    //test for vehicle*
    p = &c;
    p->showInfo();
    p = &b;
    p->showInfo();
    system("pause");
    return 0;
}

//有一个交通工具类vehicle，将它作为基类派生出小车类car和轮船类boat，请定义这些类并通过虚函数来显示各类的信息。
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
    car c("汽车");
    boat b("轮船");
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

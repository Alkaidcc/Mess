//请抽象出一个共同基类员工类，在员工类中声明一个虚函数，用来求月薪。在销售人员子类和工程师子类中分别重写求月薪的虚函数。
#include <iostream>
using namespace std;
class Employee
{
protected:
    double salary;
public:
    Employee(double s):salary(s){}
    virtual double getSalary() = 0;
};
class SaleStuff:public Employee
{
private:

public:
    SaleStuff(double s):Employee(s){}
    virtual double getSalary(){return salary;}
};
class Engineer:public Employee
{
private:

public:
    Engineer(double s):Employee(s){}
    virtual double getSalary(){return salary;}
};



int main(){
    Employee* p;
    SaleStuff s(3500);
    Engineer e(5000);
    //test for SaleStuff Engineer
    cout << "销售人员的月薪: " << s.getSalary() << endl;
    cout << "工程师的月薪: " << e.getSalary() << endl;
    //test for Employee*
    p = &s;
    cout << "销售人员的月薪: " << p->getSalary() << endl;
    p = &e;
    cout << "工程师的月薪: " << p->getSalary() << endl;
    system("pause");
    return 0;
}

//������һ����ͬ����Ա���࣬��Ա����������һ���麯������������н����������Ա����͹���ʦ�����зֱ���д����н���麯����
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
    cout << "������Ա����н: " << s.getSalary() << endl;
    cout << "����ʦ����н: " << e.getSalary() << endl;
    //test for Employee*
    p = &s;
    cout << "������Ա����н: " << p->getSalary() << endl;
    p = &e;
    cout << "����ʦ����н: " << p->getSalary() << endl;
    system("pause");
    return 0;
}

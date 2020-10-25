/*
Filename		:7.cpp
Date			:2020/10/16 18:37:27
Author			:ZZC
Description     :
*/
#include <iostream>
using namespace std;

class Employee
{
private:
    int individualEmpNo;    //个人编号
    int grade;              //级别
    float accumPay;        //月薪
public:
    Employee();
    void increaseEmpNo(int step);   //增加编号
    void promote(int increment);    //升级
    void SetaccumPay(float pa); //设置月薪
    int GetindividualEmpNo(){return individualEmpNo;}   //提取编号
    int Getgrade(){return grade;}             //提取级别
    float GetaccumPay(){return accumPay;}        //提取月薪
    void output();
    ~Employee();
};

Employee::Employee()
{
    individualEmpNo = 1000;
    grade = 0;
    accumPay = 0.0;

}
Employee::~Employee()
{
}
void Employee::increaseEmpNo(int step){
    individualEmpNo += step;
}
void Employee::promote(int increment){
    grade += increment;
}
void Employee::SetaccumPay(float pa){
    accumPay = pa;
}
void Employee::output(){
    cout << "编号：" << individualEmpNo << " 级别为: " << grade << "级  本月工资为： " << accumPay << endl;
}


int main(){
    Employee a,b,c;
    cout << "请输入下一个雇员的月薪： ";
    float pa;
    cin >> pa;
    a.increaseEmpNo(0);
    a.promote(3);
    a.SetaccumPay(pa);
    cout << "请输入下一个雇员的月薪： ";
    cin >> pa;
    b.increaseEmpNo(1);
    b.promote(2);
    b.SetaccumPay(pa);
    cout << "请输入下一个雇员的月薪： ";
    cin >> pa;
    c.increaseEmpNo(2);
    c.promote(2);
    c.SetaccumPay(pa);
    a.output();
    b.output();
    c.output();
    system("pause");
    return 0;
}

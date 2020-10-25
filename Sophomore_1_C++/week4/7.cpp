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
    int individualEmpNo;    //���˱��
    int grade;              //����
    float accumPay;        //��н
public:
    Employee();
    void increaseEmpNo(int step);   //���ӱ��
    void promote(int increment);    //����
    void SetaccumPay(float pa); //������н
    int GetindividualEmpNo(){return individualEmpNo;}   //��ȡ���
    int Getgrade(){return grade;}             //��ȡ����
    float GetaccumPay(){return accumPay;}        //��ȡ��н
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
    cout << "��ţ�" << individualEmpNo << " ����Ϊ: " << grade << "��  ���¹���Ϊ�� " << accumPay << endl;
}


int main(){
    Employee a,b,c;
    cout << "��������һ����Ա����н�� ";
    float pa;
    cin >> pa;
    a.increaseEmpNo(0);
    a.promote(3);
    a.SetaccumPay(pa);
    cout << "��������һ����Ա����н�� ";
    cin >> pa;
    b.increaseEmpNo(1);
    b.promote(2);
    b.SetaccumPay(pa);
    cout << "��������һ����Ա����н�� ";
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

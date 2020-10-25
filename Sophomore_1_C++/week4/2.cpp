/*
Filename		:2.cpp
Date			:2020/10/16 14:03:05
Author			:ZZC
Description     :������ʵ��һ��Circle�࣬�г�Ա����radius���뾶������Ա����Getarea()����Ҫ��ʵ�����صĹ��캯�����������캯������������������main()�в��Ը��ࣩ
*/

#include <iostream>
using namespace std;
const double PI = 3.14;
class Circle
{
private:
    double radius;
public:
    Circle();
    Circle(double r):radius(r){cout << "Circle���캯��" << endl;}
    Circle(Circle& c);
    double getArea(){return PI * radius * radius;}
    ~Circle();
};

Circle::Circle(Circle& c){
    radius = c.radius;
    cout << "Circle ��������" << endl;
}

Circle::Circle(){}

Circle::~Circle(){
    cout << "Circle ��������" << endl;
}

int main(){
    Circle c(5);
    Circle a = c;
    cout << "Area: " << c.getArea() << endl;  
    // system("pause");
    return 0;
}

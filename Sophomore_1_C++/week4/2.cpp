/*
Filename		:2.cpp
Date			:2020/10/16 14:03:05
Author			:ZZC
Description     :声明并实现一个Circle类，有成员变量radius（半径）、成员函数Getarea()。（要求实现重载的构造函数、拷贝构造函数、析构函数，并在main()中测试该类）
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
    Circle(double r):radius(r){cout << "Circle构造函数" << endl;}
    Circle(Circle& c);
    double getArea(){return PI * radius * radius;}
    ~Circle();
};

Circle::Circle(Circle& c){
    radius = c.radius;
    cout << "Circle 拷贝函数" << endl;
}

Circle::Circle(){}

Circle::~Circle(){
    cout << "Circle 析构函数" << endl;
}

int main(){
    Circle c(5);
    Circle a = c;
    cout << "Area: " << c.getArea() << endl;  
    // system("pause");
    return 0;
}

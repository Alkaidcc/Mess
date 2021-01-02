//现有直角三角形、正方形和圆形三种图形，求它们的各自面积。请抽象出一个基类，在基类中声明一个虚函数，用来求面积，然后派生出3个子类，在子类中分别重写这个求面积函数。
#include <iostream>
#include <cmath>
using namespace std;
const double PI = 3.1415;
class Shape
{
private:
    
public:
    virtual double getArea() = 0;
};
class Triangle:public Shape
{
private:
    double l1;
    double l2;
    double l3;
public:
    Triangle(double a, double b, double c):l1(a),l2(b),l3(c){}
    virtual double getArea();
};
class Circle:public Shape
{
private:
    double radius;
public:
    Circle(double r):radius(r){}
    virtual double getArea(){return PI * radius * radius;}
};
class Square:public Shape
{
private:
    double l;
public:
    Square(double a):l(a){}
    virtual double getArea(){return l * l;}
};
double Triangle::getArea(){
    double p = (l1 + l2 + l3)*0.5;
    return sqrt(p*(p-l1)*(p-l2)*(p-l3));
}


int main(){
    Shape* p;
    Triangle t(3,4,5);
    Square s(5);
    Circle c(3);
    //test for Triangle Square Circle
    cout << "三角形面积: " << t.getArea() << endl;
    cout << "正方形面积: " << s.getArea() << endl;
    cout << "圆形面积: " << c.getArea() << endl;
    //test for Shape*
    p = &t;
    cout << "三角形面积: " << p->getArea() << endl;
    p = &s;
    cout << "正方形面积: " << p->getArea() << endl;
    p = &c;
    cout << "圆形面积: " << p->getArea() << endl;
    system("pause");
    return 0;
}

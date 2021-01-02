//����ֱ�������Ρ������κ�Բ������ͼ�Σ������ǵĸ��������������һ�����࣬�ڻ���������һ���麯���������������Ȼ��������3�����࣬�������зֱ���д��������������
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
    cout << "���������: " << t.getArea() << endl;
    cout << "���������: " << s.getArea() << endl;
    cout << "Բ�����: " << c.getArea() << endl;
    //test for Shape*
    p = &t;
    cout << "���������: " << p->getArea() << endl;
    p = &s;
    cout << "���������: " << p->getArea() << endl;
    p = &c;
    cout << "Բ�����: " << p->getArea() << endl;
    system("pause");
    return 0;
}

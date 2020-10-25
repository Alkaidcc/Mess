/*
Filename		:5.cpp
Date			:2020/10/16 14:51:08
Author			:ZZC
Description     :������ʵ��һ�������࣬������Ϊ���ε����½������Ͻ������㣬���ܼ�����ε������������Point�࣬���������࣬ע�������Ĺ��캯����
*/

#include <iostream>
using namespace std;

class Point
{
private:
    int x;
    int y;
public:
    Point();
    Point(int px,int py):x(px),y(py){};
    int getX(){return x;}
    int getY(){return y;}
    Point(Point& p);
    ~Point();
};

Point::Point(){}

Point::~Point(){}

Point::Point(Point& p){
    x = p.x;
    y = p.y;
}
class Rectangle
{
private:
    Point p1,p2;
    int l1,l2;
public:
    Rectangle();
    Rectangle(Point a, Point b):p1(a),p2(b){}
    int getArea();
    ~Rectangle();
};

Rectangle::Rectangle()
{
}

Rectangle::~Rectangle()
{
}
int Rectangle::getArea(){
    l1 = abs(p1.getX() - p2.getX());
    l2 = abs(p1.getY() - p2.getY());
    return l1 * l2;
}

int main(){
    Point a(1,2);
    Point b(4,6);
    Rectangle r(a,b);
    cout << "The area: " << r.getArea() << endl;
    system("pause");
    return 0;
}

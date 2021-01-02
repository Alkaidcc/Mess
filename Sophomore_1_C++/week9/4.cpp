//求正方体、球体的（表面积和）体积。请抽象一个公共的基类container为抽象类，在其中定义求（表面积和）体积的纯虚函数（注意：此基类本身是没有表面积和体积可言的。）抽象类中定义一个公共的成员变量radius，可作为正方体的边长、圆的半径。再由此派生出要描述的2个类，在这2个类中重写求表面积和体积的方法。
#include <iostream>
using namespace std;
const double PI = 3.1415;
class container
{
protected:
    double radius;
public:
    container(double r):radius(r){}
    virtual double getArea() = 0;
    virtual double getVolume() = 0;
};
class Cube:public container
{
private:
    
public:
    Cube(double s):container(s){}
    virtual double getArea(){return radius * radius * 6;}
    virtual double getVolume(){return radius * radius * radius;}
};

class Sphere:public container
{
private:
    
public:
    Sphere(double s):container(s){}
    virtual double getArea(){return 4 * PI * radius * radius;}
    virtual double getVolume(){return (4 * PI * radius * radius * radius) / 3.0; }
};



int main(){
    container* p;
    Cube c(3);
    Sphere s(5);
    //test for Cube & Sphere
    cout << "正方体的面积为: " << c.getArea() << endl;
    cout << "正方体的体积为: " << c.getVolume() << endl;
    cout << "球的表面积为: " << s.getArea() << endl;
    cout << "球的体积为: " << s.getVolume() << endl;
    //test for container*
    p = &c;
    cout << "正方体的面积为: " << p->getArea() << endl;
    cout << "正方体的体积为: " << p->getVolume() << endl;
    p = &s;
    cout << "球的表面积为: " << p->getArea() << endl;
    cout << "球的体积为: " << p->getVolume() << endl;
    system("pause");
    return 0;
}

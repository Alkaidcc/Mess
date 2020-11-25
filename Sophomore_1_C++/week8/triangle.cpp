/*
���һ����������Triangle�����������������߳���˽�����ݳ�Ա������һ�������������+������ʵ�������������ζ�������֮�͡�
��Triangle�������һ����Ԫ����operator+(Triangle t1,Triangle t2)�������������"+"������t1��t2���������ε����֮�͡�
*/
#include <iostream>
#include <cmath>
using namespace std;

class Triangle
{
private:
    double l1;
    double l2;
    double l3;
public:
    Triangle(double a = 0, double b = 0, double c = 0):l1(a),l2(b),l3(c){}
    double getArea();
    friend double operator+(Triangle& t1, Triangle& t2);
    friend double operator+(double t, Triangle& t1);
};

double Triangle::getArea(){
    double p = (l1 + l2 + l3)*0.5;
    return sqrt(p*(p-l1)*(p-l2)*(p-l3));
}

double operator+(Triangle& t1, Triangle& t2){
    return (t1.getArea() + t2.getArea()); 
}

double operator+(double t,Triangle& t1){
    return t + t1.getArea();
}


int main(){
    Triangle a(3,4,5);
    cout << "area of a: " << a.getArea() << endl;
    Triangle b(3,3,3);
    cout << "area of b: " << b.getArea() << endl;
    // double c = a + b;
    // cout << c << endl;
    Triangle d(3,6,5);
    cout << "area of d: " << d.getArea() << endl;
    double c = a + b + d;
    cout << c << endl;
    system("pause");
    return 0;
}

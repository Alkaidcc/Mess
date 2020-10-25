/*
Description     :声明并实现一个复数类，使以下代码能够工作
Complex c1(1,2);
Complex c2;
Complex c3(c1);
c3.add(c1);
c3.show();
*/
#include <iostream>
using namespace std;

class Complex
{
private:
    double real;
    double image;
public:
    Complex();
    Complex(double r, double i):real(r),image(i){}
    Complex(Complex& c);
    ~Complex();
    void add(Complex& c);
    void show();
};
Complex::Complex(Complex& c){
    real = c.real;
    image = c.image;
}

Complex::Complex()
{
}

Complex::~Complex()
{
}
void Complex::show(){
    if(abs(image - 0) <0.0001){
        cout << real << endl;
    }else{
        cout << real << " + " << image << "i" << endl;
    }
}

void Complex::add(Complex& c){
    this->real = this->real + c.real;
    this->image = this->image + c.image;
}

int main(){
    Complex c1(1,2);
    Complex c2;
    Complex c3(c1);
    c3.add(c1);
    c3.show();
    system("pause");
    return 0;
}

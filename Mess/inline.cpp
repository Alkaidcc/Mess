//内联函数 空间换时间  每个调用的地方换成代码  不存在调用时间 直接执行
#include<iostream>
using namespace std;
inline double square (double x) {return x * x;}

int main() {
    double a, b;
    double c = 13.0;
    
    a = square (5.0);
    b = square (4.5+7.5);
    cout << "a = " << a << ", b = " << b << endl;
    cout << "c = " << c;
    cout << ", c squared = " << square (c++) << endl;
    cout << "Now c = " << c << endl;
    system ("pause");
    return 0;
}
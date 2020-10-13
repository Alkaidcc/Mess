#include <iostream>
using namespace std;

class A
{
public:
  A()
  {
    cout << "A()" << endl;
  }
  A(int a)//对A()的重载
  {
    cout << "A(int a)" << endl;
  }
};

A a(){
  cout << "Hello World!" << endl;
}

int main(){
A a();//表示声明一个返回值为A类的对象
a();//调用a()函数

system("pause");
return 0;
} 
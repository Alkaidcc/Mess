#include <iostream>
using namespace std;

class A
{
public:
  A()
  {
    cout << "A()" << endl;
  }
  A(int a)//��A()������
  {
    cout << "A(int a)" << endl;
  }
};

A a(){
  cout << "Hello World!" << endl;
}

int main(){
A a();//��ʾ����һ������ֵΪA��Ķ���
a();//����a()����

system("pause");
return 0;
} 
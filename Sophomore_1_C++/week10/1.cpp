#include <iostream>
using namespace std;
typedef void(*Fun)(void);
class Class{
public:
  virtual void f() { cout << "Class::f" << endl; }
  virtual void g() { cout << "Class::g" << endl; }
};
class SubClass:public Class{
  virtual void h() { cout << "SubClass::h" << endl; }
  virtual void p() { cout << "SubClass::p" << endl; }
};

int main(){
    SubClass a;
    cout << "Address of virtual pointer: " << (&a + 0) << endl;
    cout << "Value at virtual pointer or Address of virtual table " << (int*)*(int*)(&a+0) << endl;
    cout << "Value at first entry of virtual table: " << (int*)*(int*)*(int*)(&a+0) << endl;
    cout << "virtual function: " << endl;
    Fun pFun = NULL;
    pFun = (Fun)*((intptr_t*)*(intptr_t*)(&a)+0);
    pFun();
    pFun = (Fun)*((intptr_t*)*(intptr_t*)(&a)+1);
    pFun();
    system("pause");
    return 0;
}

/* 写一个栈模板类，实现相关功能。*/
#include <iostream>
using namespace std;

template<class T>
class Stack
{
private:
    int size;
    int top;
    T* Ptr;
public:
    Stack(int s = 10);
    ~Stack();
    bool isFull()const{return top == size - 1;}
    bool Pop(T& data);
    bool isEmpty()const{return top == -1;};
    bool Push(T& data);
};

template<class T>
Stack<T>::Stack(int s){
    size = s;
    Ptr = new T[size];
    top = -1;
}
template<class T>
Stack<T>::~Stack(){
    delete[] Ptr;
}

template<class T>
bool Stack<T>::Push(T& data){
    if(!isFull()){
        Ptr[++top] = data;
        return true;
    }
    cout << "the Stack is Full!" << endl;
    return false;
}

template<class T>
bool Stack<T>::Pop(T& data){
    if(!isEmpty()){
        data = Ptr[top--];
        return true;
    }
    cout << "the Stack is Empty!" << endl;
    return false;

}

int main(){
    Stack<char> c_stack;
    char c = 'a';
    while(c_stack.Push(c)){
        cout << c << ends;
        c += 1;
    }
    while(c_stack.Pop(c)){
        cout << c << ends;
    }
    system("pause");
    return 0;
}

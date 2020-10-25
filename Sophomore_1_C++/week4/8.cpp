/*
Filename		:8.cpp
Date			:2020/10/16 18:56:00
Author			:ZZC
Description     :实现一个栈类
*/

#include <iostream>
using namespace std;
 
class MyStack
{
public:
	MyStack(int size);
	~MyStack();
	bool stackEmpty();//判空
	bool stackFull();//判满
	void clearStack();//清空
	int stackLength();//长度
	bool push(int element);//压栈
	bool pop(int& element);//出栈
	bool stackTop(int &element);//返回栈顶
	void stackTranverse();//遍历栈
 
private:
	int* m_pStack;//栈指针
	int m_iSize;//栈容量
	int m_iTop;//栈顶
};
 

MyStack::MyStack(int size)
{
	m_iSize = size;
	m_pStack = new int[m_iSize];
	m_iTop = 0;
}

MyStack::~MyStack()
{
	delete m_pStack;
	m_pStack = NULL;
}

bool MyStack::stackEmpty() {//判空
	return m_iTop == 0 ? true : false;
}

bool MyStack::stackFull() {//判满
	return m_iTop == m_iSize ? true : false;
}

int MyStack::stackLength() {//栈长度
	return m_iTop;
}

void MyStack::clearStack() {//清空
	m_iTop = 0;
}

bool MyStack::push(int element) {//压栈
	if (stackFull()) {
		return false;
	}
	else {
		m_pStack[m_iTop++] = element;
		return true;
	}
}

bool MyStack::pop(int& element) {//出栈
	if (stackEmpty())
	{
		return false;
	}
	else {
		element = m_pStack[--m_iTop];
		return true;
	}
}

bool MyStack::stackTop(int& element) {//返回栈顶元素
	if (stackEmpty())
	{
		return false;
	}
	else {
		element = m_pStack[m_iTop-1];
		return true;
	}
}

void MyStack::stackTranverse() {//遍历栈
	int i = 0;
	for (i = 0; i < m_iTop; i++) {
		cout << m_pStack[i] << " ";
	}
    cout << endl;
}

int main(){
    MyStack* my_stack = new MyStack(5);
    my_stack->push(3);
    my_stack->push(7);
    my_stack->push(6);
    my_stack->push(9);
    my_stack->stackTranverse();
    int temp;
    my_stack->pop(temp);
    cout << "出栈元素为: " << temp << endl;
    cout << "栈的长度为：" << my_stack->stackLength() << endl;
    my_stack->stackTranverse();
    my_stack->clearStack();
    my_stack->stackTranverse();
    system("pause");
    return 0; 
}
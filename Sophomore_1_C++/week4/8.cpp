/*
Filename		:8.cpp
Date			:2020/10/16 18:56:00
Author			:ZZC
Description     :ʵ��һ��ջ��
*/

#include <iostream>
using namespace std;
 
class MyStack
{
public:
	MyStack(int size);
	~MyStack();
	bool stackEmpty();//�п�
	bool stackFull();//����
	void clearStack();//���
	int stackLength();//����
	bool push(int element);//ѹջ
	bool pop(int& element);//��ջ
	bool stackTop(int &element);//����ջ��
	void stackTranverse();//����ջ
 
private:
	int* m_pStack;//ջָ��
	int m_iSize;//ջ����
	int m_iTop;//ջ��
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

bool MyStack::stackEmpty() {//�п�
	return m_iTop == 0 ? true : false;
}

bool MyStack::stackFull() {//����
	return m_iTop == m_iSize ? true : false;
}

int MyStack::stackLength() {//ջ����
	return m_iTop;
}

void MyStack::clearStack() {//���
	m_iTop = 0;
}

bool MyStack::push(int element) {//ѹջ
	if (stackFull()) {
		return false;
	}
	else {
		m_pStack[m_iTop++] = element;
		return true;
	}
}

bool MyStack::pop(int& element) {//��ջ
	if (stackEmpty())
	{
		return false;
	}
	else {
		element = m_pStack[--m_iTop];
		return true;
	}
}

bool MyStack::stackTop(int& element) {//����ջ��Ԫ��
	if (stackEmpty())
	{
		return false;
	}
	else {
		element = m_pStack[m_iTop-1];
		return true;
	}
}

void MyStack::stackTranverse() {//����ջ
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
    cout << "��ջԪ��Ϊ: " << temp << endl;
    cout << "ջ�ĳ���Ϊ��" << my_stack->stackLength() << endl;
    my_stack->stackTranverse();
    my_stack->clearStack();
    my_stack->stackTranverse();
    system("pause");
    return 0; 
}
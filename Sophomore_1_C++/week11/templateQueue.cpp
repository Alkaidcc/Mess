/* 写一个队列模板类，实现相关功能。*/
#include <iostream>
using namespace std;

template<class T>
class Queue
{
private:
    int rear;
    int front;
    int maxsize;
    T* element;
public:
    Queue(int sz=10);
    ~Queue();
    bool EnQueue(const T& x);
    bool DeQueue(T& x);
    T getFront();
    bool isEmpty()const{return front == rear;}
    bool isFull()const{return ((rear+1) % maxsize == front);}
    int size()const{return (rear - front + maxsize) % maxsize;}
};
template<class T>
Queue<T>::Queue(int sz){
    rear = front = 0;
    maxsize = sz;
    element = new T[maxsize];
}
template<class T>
Queue<T>::~Queue(){
    delete[] element;
}
template<class T>
bool Queue<T>::EnQueue(const T& x){
    if(!isFull()){
        element[rear] = x;
        rear = (rear+1) % maxsize;
        return true;
    }
    cout << "the Queue is Full!" << endl;
    return false;
}
template<class T>
bool Queue<T>::DeQueue(T& x){
    if(!isEmpty()){
        T temp  = element[front];
        x = temp;
        front = (front+1) % maxsize;
        return true;
    }
    cout << "the Queue is Empty!" << endl;
    return false;
}
template<class T>
T Queue<T>::getFront(){
    if(isEmpty()){
        cout << "the Queue is Empty" << endl;
        return  -1;
    }
    return element[front];
}


int main(){
    Queue<char> c_queue(5);
    char c = 'a';
    cout << "Enqueue" << endl;
    while(c_queue.EnQueue(c)){
        cout << c << ends;
        c = c + 1;
        cout << "the size is: " << c_queue.size() << endl;
    }
    cout << "the front element of the queue is: " << c_queue.getFront() << endl;
    cout << "Dequeue" << endl;
    while(c_queue.DeQueue(c)){
        cout << c << ends;
        cout << "the size is: " << c_queue.size() << endl;
    }

    system("pause");
    return 0;
}

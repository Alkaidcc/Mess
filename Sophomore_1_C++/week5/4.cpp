#include <iostream>
using namespace std;
const int N = 100;
class Queue{
    public:
        Queue();
        ~Queue();

        void add(int t);
        int front();
        int pop();
        int size();
        int is_empty();

    private:
        int *arr;
        int count = 0;
};
Queue::Queue() 
{
    arr = new int[N];   //���䶯̬����
    if (!arr) {
        cout<<"arr malloc error!"<<endl;
    }
}
Queue::~Queue() 
{
    if (arr) {
        delete[] arr;
        arr = NULL;
    }
}
void Queue::add(int t) 
{
    arr[count++] = t;
}

int Queue::front() 
{
    return arr[0];
}
int Queue::pop() 
{
    int i = 0;;
    int ret = arr[0];

    count--;
    while (i++<count)
        arr[i-1] = arr[i];

    return ret;
}

int Queue::size() 
{
    return count;
}

int Queue::is_empty()
{
    return count == 0;
}

int main() {
    int tmp;
    Queue myqueue;

    myqueue.add(10);
    myqueue.add(20);
    myqueue.add(30);
    myqueue.add(50);
    tmp = myqueue.pop();
    cout << "�����У�" << tmp << endl;
    tmp = myqueue.front();
    cout << "��ͷԪ��Ϊ" << tmp << endl;
    myqueue.add(40);
    cout << "�����СΪ" << myqueue.size() << endl;
    cout << "�����ö��У�" << endl;
    while (!myqueue.is_empty())
    {
        tmp = myqueue.pop();
        cout << tmp << endl;
    }
    system("pause");
    return 0;
}
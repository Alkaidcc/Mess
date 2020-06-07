#include<iostream>
#include<cstdlib>
using namespace std;
typedef int QElemType;
const int MAXSIZE = 10;
const int ERROR = 0;
const int OVERFLOW = -2;
const int OK = 1;

class queue {
    public:
        QElemType* base;    
        int front;
        int rear;
        queue() {
            this->base = new QElemType[MAXSIZE];
            this->front = this->rear = 0;
        }
        bool QueueEmpty() {
            if(this->front == this->rear) {
                return true;
            }else {
                return false;
            }
        }
        bool QueueFull() {
            return ((this->rear+1) % MAXSIZE == this->front);
        }
        int QueueLength() {
            return (this->rear - this->front + MAXSIZE) % MAXSIZE;
        }
        QElemType GetHead() {
            return (this->base[this->front]); //
        }
        int EnQueue(QElemType e) {
            if((this->rear + 1) % MAXSIZE == this->front) {
                return ERROR;
            }
            (this->base[this->rear]) = e;
            this->rear = (this->rear + 1) % MAXSIZE;
            return OK;
        }
        int DeQueue() {
            if(this->front == this->rear) {
                return ERROR;
            }
            this->front = (this->front + 1) % MAXSIZE;
            return OK;
        }
        int QueueTraverse() {
            int length = (this->QueueLength());
            int p = this->front;
            for(int i = 0;i < length;i++) {
                cout << (this->base[p++]) << " ";
            }
            cout << endl;
            return OK;
        }
};

int main() {
    queue q =queue();
    int N;
    for(int i = 0 ;i < 8;i++) {
        cin >> N;
        if(N % 2 == 0) {
            q.EnQueue(N);
        }else {
            q.EnQueue(N);
            q.DeQueue();
        }
    }
    q.QueueTraverse();
    system("pause");
    return 0;
}
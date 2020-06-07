//Circular Queue
#include<iostream>
#include<cstdlib>
using namespace std;
const int MAXSIZE = 10;
typedef int QElemType;
const int ERROR = 0;
const int OVERFLOW = -2;
const int OK = 1;
typedef struct SqQueue {
    QElemType* base;    
    int front;
    int rear;
}SqQueue;

//function prototype
int InitQueue(SqQueue& Q);
bool QueueEmpty(SqQueue Q);
bool QueueFull(SqQueue Q);
int QueueLength(SqQueue Q);
QElemType GetHead(SqQueue Q);
int EnQueue(SqQueue& Q,QElemType e);
int DeQueue(SqQueue& Q,QElemType& e);
int QueueTraverse(const SqQueue Q);

int main() {
    SqQueue Q;
    QElemType  e;
    int N;
    InitQueue(Q);
    cout << "Please input the numbers:\n";
    for(int i = 0;i < 8;i++) {
        cin >> N;
        if(N % 2 != 0) {
            EnQueue(Q, N);
        }else {
            EnQueue(Q, N);
            DeQueue(Q,e);
        }
    }
    QueueTraverse(Q);
    system("pause");
    return 0;
}


int InitQueue(SqQueue &Q) {
    Q.base = new QElemType[MAXSIZE];
    if(!Q.base) {
        exit(OVERFLOW);
    }
    Q.front = Q.rear = 0;
    return OK;
}

int QueueLength(SqQueue Q) {
    return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

int EnQueue(SqQueue& Q, QElemType e) {
    if((Q.rear + 1) % MAXSIZE == Q.front) {
        return ERROR;
    }
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXSIZE;
    return OK; 
}

int DeQueue(SqQueue& Q, QElemType& e) {
    if(Q.front == Q.rear) { //
        return ERROR;
    }
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAXSIZE;
    return OK;
}

int QueueTraverse(const SqQueue Q) {
    int length = QueueLength(Q);
    int p = Q.front;
    for(int i = 0;i < length;i++) {
        cout << Q.base[p++] << " ";
    }
    cout << endl;
    return OK;
}

bool QueueEmpty(SqQueue Q) {
    if(Q.front == Q.rear) {
        return true;
    }else {
        return false;
    }
}

bool QueueFull(SqQueue Q) {
    return ((Q.rear + 1) % MAXSIZE ==Q.front);
}
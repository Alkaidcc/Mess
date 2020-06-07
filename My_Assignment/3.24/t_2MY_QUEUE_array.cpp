//Circular Queue
#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
const int MAXSIZE = 10;
const int ERROR = 0;
const int OVERFLOW = -2;
const int OK = 1;
typedef struct QElemType {
    string Id;
    int number;
}QElemType;
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
    SqQueue T,S;
    QElemType e;
    QElemType N;
    InitQueue(T);
    InitQueue(S);
    
    cout << "Please enter the information of teachers:\n";
    for(int i = 0;i < 5;i++) {
        cin >> N.Id >> N.number;
        EnQueue(T,N);

    }
    cout << "Please enter the information of students:\n";
    for(int i = 0;i < 5;i++) {
        cin >> N.Id >> N.number;
        EnQueue(S,N);
    }
    cout << "Queue A: ";
    QueueTraverse(T);
    cout << "Queue B: ";
    QueueTraverse(S);
    cout << endl;
    for(int i = 0;i < 5;i++) {
        DeQueue(T,e);
        cout << e.Id << "," << e.number << " ";
        DeQueue(S,e);
        cout << e.Id << "," << e.number << " ";
    }
    cout << endl;

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

// QElemType GetHead(SqQueue Q) {
//     if(Q.front != Q.rear) {
//         return Q.base[Q.front];
//     }else {
//         return ERROR;
//     }
// }
int QueueTraverse(const SqQueue Q) {
    int length = QueueLength(Q);
    int p = Q.front;
    for(int i = 0;i < length;i++) {
        cout << Q.base[p].Id << "," << Q.base[p].number << " ";
        p++;
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
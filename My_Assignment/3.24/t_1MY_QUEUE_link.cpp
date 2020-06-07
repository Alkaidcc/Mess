#include<iostream>
#include<cstdlib>
using namespace std;
const int MAXSIZE = 100;
typedef int QElemType;
const int ERROR = 0;
const int OVERFLOW = -2;
const int OK = 1;
typedef struct QNode {
    QElemType data;   
    struct QNode* next;
}QNode,*QueuePtr;
typedef struct LinkQueue {
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

//function prototype
int InitQueue(LinkQueue& Q);
bool QueueEmpty(LinkQueue Q);
int QueueLength(LinkQueue Q);
QElemType GetHead(LinkQueue Q);
int EnQueue(LinkQueue& Q,QElemType e);
int DeQueue(LinkQueue& Q,QElemType& e);
int QueueTraverse(const LinkQueue Q);

int main() {
    LinkQueue Q;
    QElemType e;
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

int InitQueue(LinkQueue& Q) {
    Q.front = Q.rear = new QNode;
    Q.front->next = NULL;
    return OK;
}

int EnQueue(LinkQueue& Q,QElemType e) {
    QueuePtr p = new QNode;
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
    return OK;
}

int DeQueue(LinkQueue& Q, QElemType& e) {
    if(Q.front == Q.rear) {
        return ERROR;
    }
    QueuePtr p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if(Q.rear == p) {       //最后一个元素被删除，队尾指针指向头结点
        Q.rear = Q.front;
    }
    delete p;
    return OK;
}

QElemType GetHead(LinkQueue Q) {
    if(Q.front != Q.rear) {
        return Q.front->next->data;
    }else {
        return ERROR;
    }
}

bool QueueEmpty(LinkQueue Q) {
    return (Q.front == Q.rear);
}

int QueueLength(LinkQueue Q) {
    int cnt = 0;
    QueuePtr p = Q.front->next;
    if(!p) {
        return  ERROR;
    }
    while(p) {
        cnt++;
        p = p->next;
    }
    return cnt;
}

int QueueTraverse(const LinkQueue Q) {
    QueuePtr p = Q.front->next;
    if(!p) {
        return ERROR;
    }
    while(p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
    return OK;
}
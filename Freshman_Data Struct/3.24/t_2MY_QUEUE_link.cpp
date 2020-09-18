#include<iostream>
#include<cstdlib>
using namespace std;
const int MAXSIZE = 100;
const int ERROR = 0;
const int OVERFLOW = -2;
const int OK = 1;
typedef struct QElemType {
    string Id;
    int number;
}QElemType;
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
    LinkQueue T,S;
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

// QElemType GetHead(LinkQueue Q) {
//     if(Q.front != Q.rear) {
//         return Q.front->next->data;
//     }else {
//         return ERROR;
//     }
// }

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
        cout << p->data.Id << "," << p->data.number << " ";
        p = p->next;
    }
    cout << endl;
    return OK;
}
#include<iostream>
typedef struct QNode{
    int data;
    struct QNode* next;
}QNode;

typedef struct Queue{
    QNode* front;
    QNode* rear;
}Queue;

void  en_queue(Queue* q,int value);
void  de_queue(Queue* q);
int is_empty(Queue* q);
void print_queue(Queue* q);
Queue* creat_queue();


int main(){
    Queue* q=creat_queue();
    for(int i=1;i<=10;i++)
        en_queue(q,i);
    print_queue(q);
    de_queue(q);
    de_queue(q);
    print_queue(q);
    system("pause");
    return 0;
}

Queue* creat_queue(){
    Queue* q = new Queue;
    if(q == NULL)
        printf("malloc failed!\n");
    q->front = new QNode;
    if(q->front == NULL)
        printf("malloc failed!\n");
    q->rear = q->front;
    return q;
}
void  en_queue(Queue* q,int value){
    QNode* newnode = new QNode;
    if(newnode == NULL)
        printf("malloc failed!\n");
    newnode->data = value;
    newnode->next = NULL;
    q->rear->next = newnode;    //存在头结点
    q->rear = newnode;
}

void  de_queue(Queue* q){
    if(is_empty(q))
        printf("The queue is empty!\n");
    QNode* temp = q->front->next;
    delete q->front;
    q->front = temp;
}

int is_empty(Queue* q){
    return q->front == q->rear;
}

void print_queue(Queue* q){
    if(is_empty(q))
        printf("The queue is empty!\n");
    QNode* currentnode = q->front->next;
    while(currentnode){
        printf("%d ",currentnode->data);
        currentnode = currentnode->next;
    }
    printf("\n");
}
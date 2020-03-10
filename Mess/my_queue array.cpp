#include<iostream>
#define MAXSIZE 10
#define true 1
#define false 0
typedef struct Queue{
    int data[MAXSIZE];
    int front;
    int rear;
}my_queue;

my_queue initial_queue ();
int en_queue (my_queue* q ,int value);
int de_queue (my_queue* q);
int Isempty (my_queue* q);
int traverse (my_queue* q);

int main(){
    my_queue q=initial_queue();
    for(int i=1;i<=10;i++)
        en_queue(&q,i);
    traverse(&q);
    de_queue(&q);
    de_queue(&q);
    traverse(&q);
    system("pause");
    return 0;
}

my_queue initial_queue (){
    my_queue q;
    q.front = q.rear = 0;
    return q; 
}

int en_queue (my_queue* q,int value){
    if(q->rear==MAXSIZE){
        printf("The queue is full!\n");
        return false;
    }
    else{
        q->data[q->rear] = value;
        q->rear += 1;
        return true;
    }
}
int Isempty (my_queue* q){
    return q->front == q->rear;
}
int de_queue (my_queue* q){
    if(Isempty(q)){
        printf("The queue is empty!\n");
        return false;
    }
    else{
        printf("dequeue :%d\n",q->data[q->front]);
        q->front +=1;
    }
}
int traverse (my_queue* q){
    if(q==NULL)
        return false;
    for(int i=q->front;i<q->rear;i++){
        printf("%d ",q->data[i]);
    }
    printf("\n");
    return true;
}
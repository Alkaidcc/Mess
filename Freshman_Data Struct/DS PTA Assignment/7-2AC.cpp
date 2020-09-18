#include<cstdlib>
#include<cstdio>
typedef struct PloyNode{
    int coef;
    int expon;
    PloyNode* next;
}*Polynomial;

//声明
Polynomial ReadPoly();
void Attach(int c,int e,Polynomial*pRear);
Polynomial Add(Polynomial P1,Polynomial P2);
Polynomial Multi(Polynomial P1,Polynomial P2);
void PrintPloy(Polynomial P);
int Compare(int a,int b);


void Attach(int c,int e,Polynomial*pRear){
    Polynomial P;
    P=(Polynomial)malloc(sizeof(struct PloyNode));
    P->coef=c;
    P->expon=e;
    P->next=NULL;
    (*pRear)->next=P;
    *pRear=P;
}

int Compare(int a,int b){
    if(a>b) return 1;
    else if(a<b) return -1;
    else    return 0;
}
Polynomial ReadPoly(){
    Polynomial Rear,t,P;
    int N,c,e;
    scanf("%d",&N);
    P=(Polynomial)malloc(sizeof(struct PloyNode));//链表头空结点
    P->next=NULL;
    Rear=P;
    while(N--){
        scanf("%d %d",&c,&e);
        Attach(c,e,&Rear);
    }
    t=P;    //P在Read里面是第一个空结点
    P=P->next;//让P指向下一个结点
    free(t);
    return P;
}
Polynomial Add(Polynomial P1,Polynomial P2){
    Polynomial P,Rear,t,t1,t2;
    t1=P1;
    t2=P2;
    P=(Polynomial)malloc(sizeof(struct PloyNode));
    Rear=P;
    while (t1&&t2)
    {
        switch (Compare(t1->expon,t2->expon))
        {
        case 1:
            Attach(t1->coef,t1->expon,&Rear);
            t1=t1->next;
            break;
        case -1:
            Attach(t2->coef,t2->expon,&Rear);
            t2=t2->next;
            break;
        case 0:
            if(t1->coef+t2->coef) Attach(t1->coef+t2->coef,t1->expon,&Rear);
            t1=t1->next;
            t2=t2->next;
            break;
        }
    }
    //P1 P2有一个为空 所以把不空的接到后面
    for(;t1;t1=t1->next)
        Attach(t1->coef,t1->expon,&Rear);
    for(;t2;t2=t2->next)
        Attach(t2->coef,t2->expon,&Rear);
    Rear->next=NULL;
    t=P;
    P=P->next;
    free(t);
    return P;
}
void PrintPloy(Polynomial P){
    int flag=0;
    if(!P){
        printf("0 0\n");
        return;
    }
    while (P)
    {
        if(flag==0){
            printf("%d %d",P->coef,P->expon);
            flag=1;
        }
        else
        {
            printf(" %d %d",P->coef,P->expon);
        }
        P=P->next;
    }
    printf("\n");
}
Polynomial Multi(Polynomial P1,Polynomial P2){
    Polynomial t1,t2,P,t,Rear;
    int c,e;
    if(!P1||!P2){
        return NULL;
    }
    t1=P1;
    t2=P2;
    P=(Polynomial)malloc(sizeof(struct PloyNode));
    P->next=NULL;
    Rear=P;
    while (t2)
    {
        Attach(t1->coef*t2->coef,t1->expon+t2->expon,&Rear);
        t2=t2->next;
    }
    t1=t1->next;
    while (t1)
    {
        t2=P2;
        Rear=P;//P为头结点
        while (t2)
        {
            c=t1->coef*t2->coef;
            e=t1->expon+t2->expon;
            while (Rear->next&&Rear->next->expon>e)
                Rear=Rear->next;
            if(Rear->next&&Rear->next->expon==e){
                if(Rear->next->coef+c)
                    Rear->next->coef+=c;
                else{//系数等于0，删除
                    t=Rear->next;
                    Rear->next=t->next;
                    free(t);
                }
            }
            else{//小于的情况 进行插入操作 
                t=(Polynomial)malloc(sizeof(struct PloyNode));  //申请一个新的结点
                t->coef=c;
                t->expon=e;
                t->next=Rear->next;
                Rear->next=t;
                Rear=Rear->next;
            }
            t2=t2->next;
        }
        t1=t1->next;
    }
    t2=P;       //把空的头结点删除
    P=P->next;  //P指向第一个有元素的结点
    free(t2);
    return P;
    
}
//程序框架搭建
int main(){
    Polynomial P1,P2,PS,PP;
    P1=ReadPoly();
    P2=ReadPoly();
    PS=Add(P1,P2);
    PP=Multi(P1,P2);
    PrintPloy(PP);
    PrintPloy(PS);
    system("pause");
    return 0;
}
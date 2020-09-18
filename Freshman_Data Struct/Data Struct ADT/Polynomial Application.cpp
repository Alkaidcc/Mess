//多项式加法运算
#include<cstdio>
struct PloyNode{
    int coef;       //系数(coefficient)[数据域]
    int expon;      //指数（exponent）
    struct PloyNode *link;  //指向下一个结点的指针[指针域]
};
typedef struct PloyNode *Polynomial;
Polynomial P1,P2;

Polynomial PolyAdd(Polynomial P1,Polynomial P2){
    Polynomial front,rear,temp;
    int sum;
    rear=(Polynomial)malloc(sizeof(struct PolyNode));
    front=rear;         //由front记录结果多项式链表头结点
    while(P1&&P2)      //当两个多项式都有非零项待处理
        switch (Compare(P1->expon,P2->expon))
        {
        case 1:     //P1指数大于P2
            Attach(P1->coef,P2->expon,&rear);
            P1=P1->link;
            break;
        case -1:    //P2指数大于P1
            Attach(P2->coef,P2->expon,&rear);
            P2=P2->link;
            break;
        case 0:         //指数相同
            sum=P1->coef+P2->coef;
            if(sum) Attach(sum,P1->expon,&rear);
            P1=P1->link;
            P2=P2->link;
            break;
        }
    //将未处理完的另一个多项式的所有结点依次复制到结果多项式中去
    for(;P1;P1=P1->link)
        Attach(P1->coef,P1->expon,&rear);
    for(;P2;P2=P2->link)
        Attach(P2->coef,P2->expon,&rear);
    rear->link=NULL;
    temp=front;
    front=front->link;  //令front指向结果多项式第一个非零项
    free(temp); //释放联合空表头结点
    return front;
}


//Attach函数
void Attach(int c,int e,Polynomial *pRear){
    Polynomial P;
    P=(Polynomial)malloc(sizeof(struct PolyNode));
    P->coef=c;  //对新结点赋值
    P->expon=e;
    P->link=NULL;
    (*pRear)->link=P;
    *pRear=P;       //修改pRear的值
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
    P->link=NULL;
    Rear=P;
    while (t2)
    {
        Attach(t1->coef*t2->coef,t1->expon+t2->expon,&Rear);
        t2=t2->link;
    }
    t1=t1->link;
    while (t1)
    {
        t2=P2;
        Rear=P;//P为头结点
        while (t2)
        {
            c=t1->coef*t2->coef;
            e=t1->expon+t2->expon;
            while (Rear->link&&Rear->link->expon>e)
                Rear=Rear->link;
            if((Rear->link&&Rear->link->expon==e){
                if(Rear->link->coef+c)
                    Rear->link->coef+=c;
                else{//系数等于0，删除
                    t=Rear->link;
                    Rear->link=t->link;
                    free(t);
                }
            }
            else{//小于的情况 进行插入操作 
                t=(Polynomial)malloc(sizeof(struct PloyNode));  //申请一个新的结点
                t->coef=c;
                t->expon=e;
                t->link=Rear->link;
                Rear->link=t;
                Rear=Rear->link;
            }
            t2=t2->link;
        }
        t1=t1->link;
    }
    t2=P;       //把空的头结点删除
    P=P->link;  //P指向第一个有元素的结点
    free(t2);

    return P;
    
}
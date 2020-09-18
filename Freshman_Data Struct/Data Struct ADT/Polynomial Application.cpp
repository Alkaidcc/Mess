//����ʽ�ӷ�����
#include<cstdio>
struct PloyNode{
    int coef;       //ϵ��(coefficient)[������]
    int expon;      //ָ����exponent��
    struct PloyNode *link;  //ָ����һ������ָ��[ָ����]
};
typedef struct PloyNode *Polynomial;
Polynomial P1,P2;

Polynomial PolyAdd(Polynomial P1,Polynomial P2){
    Polynomial front,rear,temp;
    int sum;
    rear=(Polynomial)malloc(sizeof(struct PolyNode));
    front=rear;         //��front��¼�������ʽ����ͷ���
    while(P1&&P2)      //����������ʽ���з����������
        switch (Compare(P1->expon,P2->expon))
        {
        case 1:     //P1ָ������P2
            Attach(P1->coef,P2->expon,&rear);
            P1=P1->link;
            break;
        case -1:    //P2ָ������P1
            Attach(P2->coef,P2->expon,&rear);
            P2=P2->link;
            break;
        case 0:         //ָ����ͬ
            sum=P1->coef+P2->coef;
            if(sum) Attach(sum,P1->expon,&rear);
            P1=P1->link;
            P2=P2->link;
            break;
        }
    //��δ���������һ������ʽ�����н�����θ��Ƶ��������ʽ��ȥ
    for(;P1;P1=P1->link)
        Attach(P1->coef,P1->expon,&rear);
    for(;P2;P2=P2->link)
        Attach(P2->coef,P2->expon,&rear);
    rear->link=NULL;
    temp=front;
    front=front->link;  //��frontָ��������ʽ��һ��������
    free(temp); //�ͷ����Ͽձ�ͷ���
    return front;
}


//Attach����
void Attach(int c,int e,Polynomial *pRear){
    Polynomial P;
    P=(Polynomial)malloc(sizeof(struct PolyNode));
    P->coef=c;  //���½�㸳ֵ
    P->expon=e;
    P->link=NULL;
    (*pRear)->link=P;
    *pRear=P;       //�޸�pRear��ֵ
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
        Rear=P;//PΪͷ���
        while (t2)
        {
            c=t1->coef*t2->coef;
            e=t1->expon+t2->expon;
            while (Rear->link&&Rear->link->expon>e)
                Rear=Rear->link;
            if((Rear->link&&Rear->link->expon==e){
                if(Rear->link->coef+c)
                    Rear->link->coef+=c;
                else{//ϵ������0��ɾ��
                    t=Rear->link;
                    Rear->link=t->link;
                    free(t);
                }
            }
            else{//С�ڵ���� ���в������ 
                t=(Polynomial)malloc(sizeof(struct PloyNode));  //����һ���µĽ��
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
    t2=P;       //�ѿյ�ͷ���ɾ��
    P=P->link;  //Pָ���һ����Ԫ�صĽ��
    free(t2);

    return P;
    
}
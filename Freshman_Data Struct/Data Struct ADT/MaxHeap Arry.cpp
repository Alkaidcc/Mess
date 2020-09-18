#include<cstdio>
#include<stdlib.h>
#define ERROR -1
typedef struct HNode* Heap;
struct HNode{
    ElementType *Data;  //�洢��Ԫ�ص�����
    int Size;       //�ѵĵ�ǰԪ�ظ���
    int Capacity;   //�ѵ��������
};
typedef Heap MaxHeap;
typedef Heap MinHeap;
// #define MaxData 1000
MaxHeap Creat(int MaxSize){     //����һ���յ�����
    MaxHeap H=malloc(sizeof(struct HNode));
    H->Data=(ElementType*)malloc((MaxSize+1)*sizeof(ElementType));    //Ϊ��������ռ�
    H->Size=0;
    H->Capacity=MaxSize;
    H->Data[0]=MaxData;     //�����ڱ� 
    return H;
}

void Insert(MaxHeap H,ElementType item){    //T(N)=O(logN)
    //��Ԫ��item��������H������H->Data[0]�Ѿ�����Ϊ�ڱ�
    int i;
    if(IsFull(H)){
            printf("��������");
            return;
    }
    i=++H->Size;    //iָ����������һ��Ԫ�ص�λ��
    for(;H->Data[i/2]<item;i/=2)
        H->Data[i]=H->Data[i/2];    //�Ѹ�����ֵ����Ų
    H->Data[i]=item;    //��item����
}

bool IsFull(MaxHeap H){
    return (H->Size==H->Capacity);
}

bool IsEmpty(MaxHeap H){
    return (H->Size==0);
}

ElementType DeleteMax(MaxHeap H){
    //������H��ȡ����ֵΪ����Ԫ�أ���ɾ��һ�����
    int Parent,Child;
    ElementType MaxItem,temp;
    if(IsEmpty(H)){
        printf("������Ϊ��");
        return ERROR;
    }
    MaxItem=H->Data[1]; //ȡ����������ֵ
    //�����������һ��Ԫ�شӸ��ڵ㿪ʼ���Ϲ����²���
    temp=H->Data[H->Size--];    //��ֵ��SizeҪ��һ
    for(Parent=1;Parent*2<=H->Size;Parent=Child){   //�ǲ����������    ��Child��Parent
        Child=Parent*2;//Childָ�������
        if(Child!=H->Size&&H->Data[Child]<H->Data[Child+1]) //������Ҷ��Ӳ����Ҷ��Ӵ��������
            Child++;    //Childָ������
        if(temp>=H->Data[Child])    //temp�����Ҷ������ֵ��Ҫ��
            break;
        else            //�ƶ�tempԪ�ص���һ��
            H->Data[Parent]=H->Data[Child]; //���Ҷ��ӵ����ֵŲ����
    }
    H->Data[Parent]=temp;
    return MaxItem;
}

void PercDown(MaxHeap H,int p){
    //���ˣ���H����H->Data[p]Ϊ�����Ӷѵ�����Ϊ����
    int Parent,Child;
    ElementType X;
    
    X=H->Data[p];   //��Ÿ��ڵ��ֵ
    for(Parent=p;Parent*2<=H->Size;Parent=Child){
        Child=Parent*2;
        if(Child!=H->Size&&H->Data[Child]<H->Data[Child+1])
            Child++;
        if(X>=H->Data[Child])
            break;
        else
            H->Data[Parent]=H->Data[Child];
    }
    H->Data[Parent]=X;
}

void BuildHeap(MaxHeap H){
    //����H->Data[]�е�Ԫ�أ�ʹ�������ѵ�������
    //�����������H->Size��Ԫ���Ѿ�����H->Data[]��
    int i;
    //�����һ�����ĸ���㿪ʼ�������ڵ�1
    for(i=H->Size/2;i>0;i--)
        PercDown(H,i);
}
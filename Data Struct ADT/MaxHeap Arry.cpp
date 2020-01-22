#include<cstdio>
#include<stdlib.h>
#define ERROR -1
typedef struct HNode* Heap;
struct HNode{
    ElementType *Data;  //存储堆元素的数组
    int Size;       //堆的当前元素个数
    int Capacity;   //堆的最大容量
};
typedef Heap MaxHeap;
typedef Heap MinHeap;
// #define MaxData 1000
MaxHeap Creat(int MaxSize){     //创建一个空的最大堆
    MaxHeap H=malloc(sizeof(struct HNode));
    H->Data=(ElementType*)malloc((MaxSize+1)*sizeof(ElementType));    //为数组申请空间
    H->Size=0;
    H->Capacity=MaxSize;
    H->Data[0]=MaxData;     //定义哨兵 
    return H;
}

void Insert(MaxHeap H,ElementType item){    //T(N)=O(logN)
    //将元素item插入最大堆H，其中H->Data[0]已经定义为哨兵
    int i;
    if(IsFull(H)){
            printf("最大堆已满");
            return;
    }
    i=++H->Size;    //i指向插入后堆最后一个元素的位置
    for(;H->Data[i/2]<item;i/=2)
        H->Data[i]=H->Data[i/2];    //把父结点的值往下挪
    H->Data[i]=item;    //将item插入
}

bool IsFull(MaxHeap H){
    return (H->Size==H->Capacity);
}

bool IsEmpty(MaxHeap H){
    return (H->Size==0);
}

ElementType DeleteMax(MaxHeap H){
    //从最大堆H中取出键值为最大的元素，并删除一个结点
    int Parent,Child;
    ElementType MaxItem,temp;
    if(IsEmpty(H)){
        printf("最大堆已为空");
        return ERROR;
    }
    MaxItem=H->Data[1]; //取出根结点最大值
    //用最大堆中最后一个元素从根节点开始向上过滤下层结点
    temp=H->Data[H->Size--];    //赋值后Size要减一
    for(Parent=1;Parent*2<=H->Size;Parent=Child){   //是不是有左儿子    把Child给Parent
        Child=Parent*2;//Child指向左儿子
        if(Child!=H->Size&&H->Data[Child]<H->Data[Child+1]) //如果有右儿子并且右儿子大于左儿子
            Child++;    //Child指向右子
        if(temp>=H->Data[Child])    //temp比左右儿子最大值还要大
            break;
        else            //移动temp元素到下一层
            H->Data[Parent]=H->Data[Child]; //左右儿子的最大值挪上来
    }
    H->Data[Parent]=temp;
    return MaxItem;
}

void PercDown(MaxHeap H,int p){
    //下滤：将H中以H->Data[p]为根的子堆调整成为最大堆
    int Parent,Child;
    ElementType X;
    
    X=H->Data[p];   //存放根节点的值
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
    //调整H->Data[]中的元素，使满足最大堆的有序性
    //这里假设所有H->Size个元素已经存在H->Data[]中
    int i;
    //从最后一个结点的父结点开始，到根节点1
    for(i=H->Size/2;i>0;i--)
        PercDown(H,i);
}
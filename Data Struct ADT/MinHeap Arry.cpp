#include<stdio.h>
#include <stdlib.h>
#include<iostream>

#define MinData -1
#define MaxSize 101
typedef int ElemnetType;
typedef struct HeapStruct{
    ElemnetType *Elements;
    int Size;
    int Capacity;
}*MinHeap;

MinHeap CreateHeap(MinHeap H);
void Insert(MinHeap H,ElemnetType item);
int IsFull(MinHeap H);
int IsEmpty(MinHeap H);
ElemnetType DeleteMin(MinHeap H);

// int main()
// {
//     int arr[]={23,26,46,24,10};
//     MinHeap heap=NULL;

//     heap=CreateHeap(heap);
//     for(int i=0;i<5;i++){
//         Insert(heap,arr[i]);
//     }

//     while(!IsEmpty(heap)){
//         printf("%d, ", DeleteMin(heap));
//     }
//     putchar('\n');

//     system("pause");
//     return 0;
// }

MinHeap CreateHeap(MinHeap H)
{
    H=(MinHeap)malloc(sizeof(struct HeapStruct));
    H->Elements=(ElemnetType *)malloc(sizeof(ElemnetType));
    H->Size=0;
    H->Capacity=MaxSize;
    H->Elements[0]= MinData;

    return H;
}

int IsFull(MinHeap H)
{
    if(H->Size==MaxSize)    return 1;
    else return 0;      
}

int IsEmpty(MinHeap H)
{
    if(H->Size==0)  return 1;
    else return 0;
}

void Insert(MinHeap H,ElemnetType item)
{
    int i;
    if(IsFull(H)){
        printf("Full\n");
    }else{
        i=++H->Size;
        for( ;item<H->Elements[i/2];i/=2)
            H->Elements[i]=H->Elements[i/2];
        H->Elements[i]=item;
    }
}

ElemnetType DeleteMin(MinHeap H)
{
    int parent,child;
    ElemnetType MinItem,temp;
    if(IsEmpty(H)){
        printf("Empty\n");
        return NULL;
    }
    MinItem=H->Elements[1];
    temp=H->Elements[H->Size--];
    for(parent=1;parent*2<H->Size;parent=child){
        child=parent*2;
        if((child!=H->Size)&&(H->Elements[child]>H->Elements[child+1]))
            child++;
        if(temp<H->Elements[child]) break;
        else
            H->Elements[parent]=H->Elements[child];
    }
    H->Elements[parent]=temp;

    return MinItem;
}
#include<cstdio>
#include<stdlib.h>
#define ERROR -1
typedef struct TreeNode* HuffmanTree;
struct TreeNode{
    int Weight; //权值
    HuffmanTree Left;
    HuffmanTree Right;
};

typedef struct HeapStruct{
    ElemnetType *Elements;
    int Size;
    int Capacity;
}*MinHeap;

MinHeap CreateHeap(MinHeap H)
{
    H=(MinHeap)malloc(sizeof(struct HeapStruct));
    H->Elements=(ElemnetType *)malloc(sizeof(ElemnetType));
    H->Size=0;
    H->Capacity=MaxSize;
    H->Elements[0]= MinData;

    return H;
}

int IsEmpty(MinHeap H)
{
    if(H->Size==0)  return 1;
    else return 0;
}

int IsFull(MinHeap H)
{
    if(H->Size==MaxSize)    return 1;
    else return 0;      
}

void Inster(MinHeap H,ElemnetType item)
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

void BuildHeap( MinHeap H ){
/* 调整H->Data[]中的元素，使满足最小堆的有序性  */
/* 这里假设所有H->Size个元素已经存在H->Data[]中 */
    int i;
    for( i = H->Size/2; i>0; i-- ) /* 从最后一个结点的父节点开始，到根结点1 */
        PercDown( H, i );
}

void PercDown( MinHeap H, int p )
{ /* 下滤：将H中以H->Data[p]为根的子堆调整为最大堆 */
    int Parent, Child;
    int X;
    X = H->Data[p]; /* 取出根结点存放的值 */
    for( Parent=p; Parent*2<=H->Size; Parent=Child ) {
        Child = Parent * 2;
        if( (Child!=H->Size) && (H->Data[Child]>H->Data[Child+1]) )
            Child++;  /* Child指向左右子结点的较小者 */
        if( X >= H->Data[Child] ) break; /* 找到了合适位置 */
        else  /* 下滤X */
            H->Data[Parent] = H->Data[Child];
    }
    H->Data[Parent] = X;
}

//----------------------------HuffmanTree------------------------------------------------------

/*哈夫曼树的特点
1.没有度为1的结点
2.n个叶子结点的哈夫曼树共有2n-1个结点
3.哈夫曼树任意非叶结点的左右子树交换后仍是哈夫曼树
*/
//哈夫曼树 O(NlogN)
HuffmanTree Huffman(MinHeap H){
    //假设H->Size个权值已经存在H->Elements[]->Weight里
    int i;
    HuffmanTree T;
    BuildMinHeap(H);    //将H->Elements[]按权值调整为最小堆
    for(i=1;i<H->Size;i++){ //做H->Size-1次合并
        T=malloc(sizeof(struct TreeNode));  //建立新结点
        T->Left=DeleteMin(H);
                            //从最小堆中删除一个结点作为新T的左子结点
        T->Right=DeleteMin(H);
                            //从最小堆中删除一个结点作为新T的右子结点
        T->Weight=T->Left->Weight+T->Right->Weight; //重新计算新权值
        Insert(H,T);        //将新T插入最小堆
    }
    T=DeleteMin(H);
    retrun T;
}
#include<cstdio>
#include<stdlib.h>
#define ERROR -1
typedef struct TreeNode* HuffmanTree;
struct TreeNode{
    int Weight; //Ȩֵ
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
/* ����H->Data[]�е�Ԫ�أ�ʹ������С�ѵ�������  */
/* �����������H->Size��Ԫ���Ѿ�����H->Data[]�� */
    int i;
    for( i = H->Size/2; i>0; i-- ) /* �����һ�����ĸ��ڵ㿪ʼ���������1 */
        PercDown( H, i );
}

void PercDown( MinHeap H, int p )
{ /* ���ˣ���H����H->Data[p]Ϊ�����Ӷѵ���Ϊ���� */
    int Parent, Child;
    int X;
    X = H->Data[p]; /* ȡ��������ŵ�ֵ */
    for( Parent=p; Parent*2<=H->Size; Parent=Child ) {
        Child = Parent * 2;
        if( (Child!=H->Size) && (H->Data[Child]>H->Data[Child+1]) )
            Child++;  /* Childָ�������ӽ��Ľ�С�� */
        if( X >= H->Data[Child] ) break; /* �ҵ��˺���λ�� */
        else  /* ����X */
            H->Data[Parent] = H->Data[Child];
    }
    H->Data[Parent] = X;
}

//----------------------------HuffmanTree------------------------------------------------------

/*�����������ص�
1.û�ж�Ϊ1�Ľ��
2.n��Ҷ�ӽ��Ĺ�����������2n-1�����
3.�������������Ҷ���������������������ǹ�������
*/
//�������� O(NlogN)
HuffmanTree Huffman(MinHeap H){
    //����H->Size��Ȩֵ�Ѿ�����H->Elements[]->Weight��
    int i;
    HuffmanTree T;
    BuildMinHeap(H);    //��H->Elements[]��Ȩֵ����Ϊ��С��
    for(i=1;i<H->Size;i++){ //��H->Size-1�κϲ�
        T=malloc(sizeof(struct TreeNode));  //�����½��
        T->Left=DeleteMin(H);
                            //����С����ɾ��һ�������Ϊ��T�����ӽ��
        T->Right=DeleteMin(H);
                            //����С����ɾ��һ�������Ϊ��T�����ӽ��
        T->Weight=T->Left->Weight+T->Right->Weight; //���¼�����Ȩֵ
        Insert(H,T);        //����T������С��
    }
    T=DeleteMin(H);
    retrun T;
}
/*编写一个主函数main，利用InitList_Sq、LocateElem_Sq、ListInsert_Sq、ListDelete_Sq完成以下功能：
利用InitList_Sq初始化一个线性表，利用 ListInsert_Sq插入10个整数（10个数分别为2，4，6，8，10，12，14，16，18，20）
然后利用ListDelete_Sq删除第6个元素，接着利用 ListInsert_Sq在第4个位置增加22，调用LocateElem函数判断8所在的位置。
再编写printf_Sq(ElemType L)函数，在主函数main中调用把线性表中的元素全部输出。*/
#include<iostream>
using namespace std;
const int MAXSIZE = 100;
const int ERROR = -1;
#define OVERFLOW -2
typedef int ElemType;
typedef struct {
	ElemType *elem; //存储空间的基地址
	int length; //当前长度
} SqList;

//声明
void InitList_Sq(SqList& L);
int ListInsert_Sq(SqList& L,int index,ElemType e);
int ListDelete_Sq(SqList&L,int index);
ElemType LocatedElem_Sq(SqList& L,int e);
void printf_Sq(SqList& L);


int main(){
    SqList L;
    InitList_Sq(L);
    for(int i=2;i<=20;i=i+2)
        ListInsert_Sq(L,L.length+1,i);
    printf_Sq(L);
    ListDelete_Sq(L,6);
    printf_Sq(L);
    ListInsert_Sq(L,4,22);
    int index=LocatedElem_Sq(L,8);
    cout << "The index of 8 is: " << index << endl;
    printf_Sq(L);
    delete [] L.elem;
    system("pause");
    return 0;
}


void InitList_Sq(SqList& L){
    L.elem = new ElemType [MAXSIZE];
    if(!L.elem)
        exit(OVERFLOW);
    L.length = 0;

}

ElemType LocatedElem_Sq(SqList& L,int e){
    for(int i =0;i<L.length;i++)
        if(L.elem[i]==e)
            return i+1;
    return 0;
}

int ListInsert_Sq(SqList& L,int index,ElemType e){
    if(index<1||index>L.length+1)
        return ERROR;
    if(L.length==MAXSIZE)
        return ERROR;
    for(int j=L.length-1;j>=index-1;j--){
        L.elem[j+1]=L.elem[j];
    }
    L.elem[index-1]=e;
    ++L.length;
    return 0;
}

int ListDelete_Sq(SqList&L,int index){
    if(index<1||index>L.length)
        return ERROR;
    for(int j=index;j<=L.length-1;j++){
        L.elem[j-1]=L.elem[j];
    }
    --L.length;
    return 0;
}
void printf_Sq(SqList& L){
    for(int i=0;i<L.length;i++){
        cout << L.elem[i] << " ";
    }
    cout << endl;
}
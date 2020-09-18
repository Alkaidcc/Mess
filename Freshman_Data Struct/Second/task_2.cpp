/*编写一个主函数main，利用InitList_Sq、LocateElem_Sq、ListInsert_Sq、ListDelete_Sq完成以下功能：
利用InitList_Sq初始化一个线性表，利用 ListInsert_Sq插入5个元素（元素是学生信息，定义如下），
然后利用ListDelete_Sq删除第3个元素，
接着利用 ListInsert_Sq在第3个位置增加新元素(20190023，Zhangfan，89，92)，
再编写printf_Sq(ElemType L)函数，在主函数main中调用把线性表中的元素全部输出。*/
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
const int MAXSIZE = 100;
const int ERROR = -1;
#define OVERFLOW -2

typedef struct {
    string no;   //8位图书号
    string name; //书名
    float math;//成绩1
    float cmp; //成绩2
} ElemType;

typedef struct {
	ElemType *elem; //存储空间的基地址
	int length; //当前长度
} SqList;

//声明
void InitList_Sq(SqList& L);
int ListInsert_Sq(SqList& L,int index,ElemType e);
int ListDelete_Sq(SqList&L,int index);
void printf_Sq(SqList& L);


int main(){
    SqList L;
    InitList_Sq(L);
    for(int i=0;i<5;i++){
        ElemType E;
        cin >> E.no >> E.name >> E.math >> E.cmp;
        ListInsert_Sq(L,L.length+1,E);
    }
    cout << endl;
    printf_Sq(L);
    ListDelete_Sq(L,3);
    printf_Sq(L);
    ElemType A={"20190023","Zhangfan",89,92};
    ListInsert_Sq(L,3,A);
    printf_Sq(L);
    system("pause");
    return 0;
}


void InitList_Sq(SqList& L){
    L.elem = new ElemType [MAXSIZE];
    if(!L.elem)
        exit(OVERFLOW);
    L.length = 0;

}

int ListInsert_Sq(SqList& L,int index,ElemType E){
    if(index<1||index>L.length+1)
        return ERROR;
    if(L.length==MAXSIZE)
        return ERROR;
    for(int j=L.length-1;j>=index-1;j--){
        L.elem[j+1]=L.elem[j];
    }
    L.elem[index-1]=E;
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
        cout << L.elem[i].no << "\t\t";
        cout << L.elem[i].name << "\t\t";
        cout << L.elem[i].math << "\t\t";
        cout << L.elem[i].cmp << "\t\t" << endl;
    }
    cout << endl;
}
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
typedef struct{
    int no;
    string name;
    float score;
}ElemType;
typedef struct node{
    ElemType data;
    struct node* next;
}node,*Linklist;

//函数声明
Linklist Union(Linklist L1,Linklist L2);
void TraverseLinklist(Linklist L);
Linklist CreateList_L();
bool LocateElem(Linklist,ElemType value);
Linklist addNode(ElemType value);
void ListInsert_L(Linklist L,ElemType value);
int main(){

    // Linklist L1 = CreateList_L(5);
    Linklist L1 = CreateList_L();
    cout << "Please enter the student information in L1: " << endl;
    for(int i=0;i<4;i++){
        ElemType temp;
        cin >> temp.no >> temp.name >> temp.score;
        ListInsert_L(L1,temp);
    }
    cout << "La= ";
    TraverseLinklist(L1);
    cout << endl;
    Linklist L2 = CreateList_L();
    cout << "Please enter the student information in L2: " << endl;
    for(int i=0;i<3;i++){
        ElemType temp;
        cin >> temp.no >> temp.name >> temp.score;
        ListInsert_L(L2,temp);
    }
    cout << "Lb= ";
    TraverseLinklist(L2);
    cout << endl;
    //合并
    Linklist L3 = Union(L1,L2);
    cout << "La= ";
    TraverseLinklist(L3);
    cout << endl;
    system("pause");
    return 0;

}

Linklist CreateList_L(){
    Linklist head = new node;
    head->next = NULL;
    return head;
}
Linklist Union(Linklist L1,Linklist L2){//合并两个链表
    Linklist head = new node;
    head->next = NULL;
    Linklist p = head;
    Linklist l1 = L1->next;
    Linklist l2 = L2->next;
    while(l1){//遍历链表L1
        p->next = l1;
        l1 = l1->next;
        p  = p->next;
    }
    while(l2){
        if(!LocateElem(L1->next,l2->data)){//判断当前元素在L1中是否存在
            Linklist temp = new node;
            temp->data = l2->data;
            temp->next = NULL;
            p->next = temp;
            l2 = l2->next;
            p = p->next;
        }
        else{
            l2 = l2->next;
        }
    }
    return head;
}


bool LocateElem(Linklist L,ElemType value){
    if(L == NULL){
        cout << "The Linklist is empty!" << endl;
        return false;
    }
    while (L)
    {
        if(L->data.name == value.name && L->data.no == value.no && L->data.score == value.score)
            return true;
        L = L->next;
    }
    return false;
}

void TraverseLinklist(Linklist L){
    if(L == NULL){
        cout << "The Linklist is empty!" << endl;
    }
    Linklist p = L->next;
    cout << "[";
    while(p){
        if(p->next){
            cout << "(";
            cout << p->data.no << "," << p->data.name << "," << p->data.score;
            cout << "),";
            p = p->next;
        }
        else{
            cout << "(";
            cout << p->data.no << "," << p->data.name << "," << p->data.score;
            cout << ")";
            p = p->next;
        }
    }
    cout << "]" << endl;
}
Linklist addNode(ElemType value){
    Linklist temp =new node;
    temp->data.name = value.name;
    temp->data.no = value.no;
    temp->data.score = value.score;
    temp->next = NULL;
    return temp;
}
void ListInsert_L(Linklist L,ElemType value){
    while(L->next != NULL){
        L = L->next;
    }
    L->next = addNode(value);
}
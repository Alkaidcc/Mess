#include<iostream>
using namespace std;

typedef struct node{
    int data;
    struct node* next;
}node,*Linklist;

//��������
Linklist Union(Linklist L1,Linklist L2);
void TraverseLinklist(Linklist L);
Linklist CreateList_L();
bool LocateElem(Linklist,int value);
Linklist addNode(int value);
void ListInsert_L(Linklist L,int value);
int main(){

    // Linklist L1 = CreateList_L(5);
    Linklist L1 = CreateList_L();
    ListInsert_L(L1,7);
    ListInsert_L(L1,5);
    ListInsert_L(L1,3);
    ListInsert_L(L1,11);
    cout << "La= ";
    TraverseLinklist(L1);

    Linklist L2 = CreateList_L();
    ListInsert_L(L2,2);
    ListInsert_L(L2,6);
    ListInsert_L(L2,3);
    cout << "Lb= ";
    TraverseLinklist(L2);
    //�ϲ�
    Linklist L3 = Union(L1,L2);
    cout << "La= ";
    TraverseLinklist(L3);

    system("pause");
    return 0;

}

Linklist CreateList_L(){
    Linklist head = new node;
    head->data = -1;
    head->next = NULL;
    return head;
}
Linklist Union(Linklist L1,Linklist L2){//�ϲ���������
    Linklist head = new node;
    head->data = -1;
    head->next = NULL;
    Linklist p = head;
    Linklist l1 = L1->next;
    Linklist l2 = L2->next;
    while(l1){//��������L1
        p->next = l1;
        l1 = l1->next;
        p  = p->next;
    }
    while(l2){
        if(!LocateElem(L1->next,l2->data)){//�жϵ�ǰԪ����L1���Ƿ����
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


bool LocateElem(Linklist L,int value){
    if(L == NULL){
        cout << "The Linklist is empty!" << endl;
        return false;
    }
    while (L)
    {
        if(L->data == value)
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
    cout << "(";
    while(p){
        if(p->next){
            cout << p->data << ",";
            p = p->next;
        }
        else{
            cout << p->data;
            p = p->next;
        }
    }
    cout << ")" << endl;
}
Linklist addNode(int value){
    Linklist temp =new node;
    temp->data = value;
    temp->next = NULL;
    return temp;
}
void ListInsert_L(Linklist L,int value){
    while(L->next != NULL){
        L = L->next;
    }
    L->next = addNode(value);
}
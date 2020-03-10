#include<iostream>
#include<string>
#include<cstring>
using namespace std;
typedef struct node{
    int data;
    struct node* next;
}node;
typedef node* Linklist;

//声明
void MergeTwoLists(Linklist R1,Linklist R2,Linklist R3);
node* Creatnode(int value);
void Add(Linklist currentnode,int value);
void Print(Linklist currentnode);
void Delete(Linklist R1,Linklist R2,Linklist R3);
void MergeTwoLists(Linklist R1,Linklist R2,Linklist R3){
    
    //工作指针
    Linklist pa = R1->next; 
    Linklist pb = R2->next;
    Linklist pc = R3;

    while(pa && pb){
        if(pa->data < pb->data){
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else if(pa->data > pb->data){
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
        else{
            pc->next = pa;
            pc = pa;
            pa = pa->next;
            pb->data = pb->next->data;
            Linklist temp = pb->next->next;
            delete pb->next;
            pb->next = temp;
        }
    }
    while(pa){
        pc->next = pa;
        pc = pa;
        pa = pa->next;
    }

    while(pb){
        pc->next = pb;
        pc = pb;
        pb = pb->next;
    }

}

node* Creatnode(int value){
    Linklist temp = new node;
    temp->data = value;
    temp->next = NULL;
    return temp;
}

void Add(Linklist currentnode,int value){
    while (currentnode->next){
        currentnode = currentnode->next;
    }
    currentnode->next = Creatnode(value);
}
void Print(Linklist currentnode){
    while(currentnode){
        if(currentnode->next)
            cout << currentnode->data << " -> ";
        else
            cout << currentnode->data << endl;
        currentnode = currentnode->next;
    }
}
void Delete(Linklist R1){
    while(R1){
        Linklist temp = R1->next;
        delete R1;
        R1 = temp;
    }
}
int main(){
    Linklist R1 = new node;
    R1->data = 0;
    R1->next = NULL;
    Linklist R2 = new node;
    R2->next = NULL;
    R2->data = 0;
    Linklist R3 = R1;
    Add(R1,20);
    Add(R1,35);
    Add(R2,15);
    Add(R2,55);
    Add(R2,99);
    MergeTwoLists(R1,R2,R3);
    Print(R3->next);
    Delete(R1); //因为R1把R2的元素串进去了 所以只要删除R1 就可以删除所有的结点 
    system("pause");
    return 0;
}
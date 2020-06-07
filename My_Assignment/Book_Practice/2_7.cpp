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
node* Creatnode(int value);
void Add(Linklist currentnode,int value);
void Print(Linklist currentnode);
void Destroy(Linklist R1,Linklist R2,Linklist R3);
Linklist Reverselink(Linklist currentnode);

Linklist Reverselink(Linklist head){
    Linklist pre = NULL;
    Linklist cur = head;
    while(cur!=NULL){
        Linklist temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }
    return pre;

}


void Destroy(Linklist currentnode){
    while(currentnode){
        Linklist temp = currentnode->next;
        delete currentnode;
        currentnode = temp;
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

int main(){
    Linklist head = new node;
    head->next = NULL;
    head->data = 0;
    Add(head,15);
    Add(head,50);
    Add(head,100);
    Add(head,88);
    Add(head,66);
    Add(head,98);
    Print(head->next);
    Linklist Newhead = Reverselink(head->next); //反转链表
    Print(Newhead);
    // Destroy(Newhead);
    system("pause");
    return 0;
}
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
typedef struct node{
    int data;
    struct node* next;
}node;
typedef node* Linklist;

//ÉùÃ÷
node* Creatnode(int value);
void Add(Linklist currentnode,int value);
void Print(Linklist currentnode);
void Destroy(Linklist R1,Linklist R2,Linklist R3);
void MergeTwoLists(Linklist R1,Linklist R2,Linklist R3);
void DeleteNumber(Linklist currentnode,int value);

void DeleteNumber(Linklist currentnode,int value){
    while(currentnode){
        while(currentnode->data == value){
            currentnode->data = currentnode->next->data;
            Linklist temp = currentnode->next->next;
            delete currentnode->next;
            currentnode->next = temp;
        }
        currentnode = currentnode->next;
    }
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
    head->data = 0;
    head->next =NULL;
    Add(head,15);
    Add(head,50);
    Add(head,66);
    Add(head,88);
    Add(head,66);
    Add(head,98);
    Print(head->next);
    DeleteNumber(head->next,66);
    Print(head->next);
    Destroy(head);
    system("pause");
    return 0;
}
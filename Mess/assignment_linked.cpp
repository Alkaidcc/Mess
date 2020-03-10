#include<iostream>
using namespace std;
typedef struct book{
    int no;
    double price;
    struct book *next;
}book;
//声明
void Add(book *currentnode,int num,double price);
book* Creatnode(int n,double p);
void Print(book *currentnode);
void Deletebook(book* currentnode);
int main()
{
    int no;
    double price;
    book *head = (book*)new(book);
    head->no = -1;
    head->price = -1;
    head->next = NULL;
    for(int i = 0;i < 10;i++){
        cin >> no >> price;
        Add(head,no,price);
    }
    Print(head->next);
    Deletebook(head);
    system("pause");
    return 0;

}
book* Creatnode(int n,double p){//创建结点
    book *temp = (book*)malloc(sizeof(book));
    temp->no = n;
    temp->price = p;
    temp->next = NULL;
}

void Add(book *currentnode,int num,double price){//增加结点
    while (currentnode->next!=NULL){
        currentnode = currentnode->next;
    }
    currentnode->next = Creatnode(num,price);
}

void Print(book *currentnode){//输出函数
    while(currentnode!=NULL){
        cout << currentnode->no << " " << currentnode->price << endl;
        currentnode = currentnode->next;
    }
}

void Deletebook(book* currentnode){
    while(currentnode){
        book* temp=currentnode->next;
        delete(currentnode);
        currentnode=temp;
    }
}
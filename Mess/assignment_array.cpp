#include<iostream>
using namespace std;

typedef struct book{
    int no;
    double price;
    struct book* next=nullptr;
}book;

int main(){
    book *p,*p1,*head;
    p=head=new book;
    cin>>p->no>>p->price;
    for(int i=1;i<10;i++){
        p->next=p1=new book;
        cin>>p1->no>>p1->price;
        p=p1;
    }
    do{
        cout<<head->no<<" "<<head->price<<endl;
    }while(head=head->next);
    system("pause");
}
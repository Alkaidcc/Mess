//输入5本图书的编号，名称，价格，并把这些图书的信息输出，每本书一行
//删除第N本书信息，再一次输出
#include<iostream>
#include<cstring>
#include<string>
using namespace std;

typedef struct book{
    int number;
    string name;
    double price;
    struct book* next;
}book;

//声明
book* Creatbook(int number1,string name1,double price1);
void Add(book* currentbook,int num,string nam,double pri);
void Print(book* currentbook);
void Destroy(book* currentbook);
void deleteBook(book* currentnode,int cnt);

int main(){
    //初始化头结点 
    book* head = new book;
    head->name = " ";
    head->number = -1;
    head->price = -1;
    head->next =NULL;

    int num;
    double pri;
    string nam;
    cout << "Please enter your books information: " << endl;
    //输入信息
    for(int i=0;i<5;i++){
        cin >> num >> nam >> pri;
        Add(head,num,nam,pri);
    }

    Print(head->next);  //输出
    cout << endl;

    deleteBook(head->next,2);   //删除第N本书
    Print(head->next);
    
    Destroy(head);      //收回内存
    system("pause");
    return 0;
}

book* Creatbook(int number1,string name1,double price1)
{   //创建结点
    book* temp = new book;
    temp->name = name1;
    temp->number = number1;
    temp->price = price1;
    temp->next = NULL;
}

void Add(book* currentbook,int num,string nam,double pri)
{   //增加结点
    while(currentbook->next!=NULL)
        currentbook = currentbook->next;
    currentbook->next = Creatbook(num,nam,pri);
}

void Print(book* currentbook)
{   //输出书籍
    cout << "Number\t\t" << "Name\t\t\t" << "Price" << endl;
    while(currentbook!=NULL){
        cout << currentbook->number;
        cout << "\t\t";
        cout << currentbook->name;
        cout << "\t\t";
        cout << currentbook->price << endl;
        currentbook = currentbook->next;
    }
}

void deleteBook(book* currentnode,int cnt){
    //删除第N个结点
    while(--cnt){
        currentnode = currentnode->next;
    }
    currentnode->name = currentnode->next->name;
    currentnode->number = currentnode->next->number;
    currentnode->price = currentnode->next->price;
    book* temp = currentnode->next->next;
    delete currentnode->next;
    currentnode->next = temp;
}

void Destroy(book* currentbook)
{   //收回空间
    while(currentbook){
        book* temp = currentbook->next;
        delete currentbook;
        currentbook = temp;
    }
}
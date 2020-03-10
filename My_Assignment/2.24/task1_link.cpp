//����5��ͼ��ı�ţ����ƣ��۸񣬲�����Щͼ�����Ϣ�����ÿ����һ��
//ɾ����N������Ϣ����һ�����
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

//����
book* Creatbook(int number1,string name1,double price1);
void Add(book* currentbook,int num,string nam,double pri);
void Print(book* currentbook);
void Destroy(book* currentbook);
void deleteBook(book* currentnode,int cnt);

int main(){
    //��ʼ��ͷ��� 
    book* head = new book;
    head->name = " ";
    head->number = -1;
    head->price = -1;
    head->next =NULL;

    int num;
    double pri;
    string nam;
    cout << "Please enter your books information: " << endl;
    //������Ϣ
    for(int i=0;i<5;i++){
        cin >> num >> nam >> pri;
        Add(head,num,nam,pri);
    }

    Print(head->next);  //���
    cout << endl;

    deleteBook(head->next,2);   //ɾ����N����
    Print(head->next);
    
    Destroy(head);      //�ջ��ڴ�
    system("pause");
    return 0;
}

book* Creatbook(int number1,string name1,double price1)
{   //�������
    book* temp = new book;
    temp->name = name1;
    temp->number = number1;
    temp->price = price1;
    temp->next = NULL;
}

void Add(book* currentbook,int num,string nam,double pri)
{   //���ӽ��
    while(currentbook->next!=NULL)
        currentbook = currentbook->next;
    currentbook->next = Creatbook(num,nam,pri);
}

void Print(book* currentbook)
{   //����鼮
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
    //ɾ����N�����
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
{   //�ջؿռ�
    while(currentbook){
        book* temp = currentbook->next;
        delete currentbook;
        currentbook = temp;
    }
}
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
typedef struct Listnode{
    string no;      //编号
    string name;    //书名
    double price;   //价格                       
    struct Listnode* next;
}Listnode,*Linklist;
// function prototypes 
Linklist CreateList_L();
Linklist GetElem_L(Linklist L,int index);
void ListInsert_L(Linklist L,int index);
void ListDelete_L (Linklist L,int index);
void printf_L (const Linklist L);
Linklist expensive(Linklist L);

int main(){
    cout << "Please input the information of books:" << endl;
    Linklist L = CreateList_L();
    printf_L(L);
    Linklist Max = expensive(L);
    cout << "The most expensive: " << Max->no << " " << Max->name << endl;
    Linklist node = GetElem_L(L,3);
    cout << "The element of index 3:" << endl;
    cout << node->no;
    cout << "\t\t";
    cout << node->name;
    cout << "\t\t";
    cout << node->price;
    cout << endl;
    cout << "Enter the information for the insert element:" << endl;
    ListInsert_L(L,1);
    ListDelete_L(L,5);
    cout << "The the fifth element has been delete." << endl;
    printf_L(L);
    system("pause");
    return 0;
}

Linklist CreateList_L(){
    Linklist L = new Listnode;
    L->next = NULL;
    Linklist p= L;
    for(int i = 0; i<6;i++){
        Linklist temp = new Listnode;
        cin >> temp->no >> temp->name >> temp->price;
        temp->next =NULL;
        p->next = temp;
        p = p->next;
    }
    return L;
}

Linklist GetElem_L(Linklist L,int index){
    Linklist p =L->next;
    int counter = 1;
    Listnode temp;
    while(p && counter<index){
        p = p->next;
        counter++;
    }
    if(!p || counter > index)
        printf("Not find\n");
    else
        return p;
}

void ListInsert_L(Linklist L,int index){
    
    Linklist p = L;
    int counter =1;
    while(p && counter < index){
        p = p->next;
        ++counter;
    }
    if(p == NULL || counter > index)
        printf("ERROR");
    else{
        Linklist node = new Listnode;
        cin >> node->no >> node->name >> node->price;
        node->next = p->next;
        p->next = node;
    }
}

void ListDelete_L (Linklist L,int index){
    Linklist p = L->next;
    int counter = 1;
    while(p && counter < index){
        p = p->next;
        counter++;
    }
    if(p == NULL || counter > index)
        printf("ERROR\n");
    else{
        p->no = p->next->no;
        p->name = p->next->name;
        p->price = p->next->price;
        Linklist temp = p->next->next;
        delete p->next;
        p->next = temp;
    }
}

void printf_L (const Linklist L){
    cout << "NO";
    cout << "\t\t";
    cout << "NAME";
    cout << "\t\t\t";
    cout << "PRICE";
    cout << endl;
    Linklist p = L->next;
    while (p){
        cout << p->no;
        cout << "\t\t";
        cout << p->name;
        cout << "\t\t";
        cout << p->price;
        cout << endl;
        p = p->next;
    }
    cout << endl;
}

Linklist expensive (Linklist L){
    Linklist p =L->next;
    Linklist Max = p;
    while(p){
        if(p->price > Max->price)
            Max = p;
        p = p->next;
    }
    return Max;
}
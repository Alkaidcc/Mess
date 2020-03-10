//输入10本图书的编号，名称，价格，并把这些图书的信息输出，每本书一行
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
const int MAXSIZE = 100;
typedef struct book{
    int number;
    string name;
    double price;
}book;
typedef struct myList{
    book *element;
    int length;
}myList;

void initalList(myList &L);
void input(myList &L,int cnt);
void output(myList &L,int cnt);
void listDelete(myList &L,int e);

int main(){
    myList L;
    initalList(L);
    input(L,5);
    cout << endl;
    output(L,5);
    listDelete(L,2);
    output(L,4);
    system("pause");
    return 0;

}

void initalList(myList &L){
    L.element = new book [MAXSIZE];
    L.length = 0;

}

void input(myList &L,int cnt){
    for(int i=0;i<cnt;i++){
        cin >> L.element[i].number >> L.element[i].name >> L.element[i].price;
        L.length++;
    }

}

void output(myList &L,int cnt){
    for(int i=0;i<cnt;i++){
        cout << L.element[i].number << " " << L.element[i].name << " " << L.element[i].price << " " << endl;
    }
    cout << endl;

}

void listDelete(myList &L,int e){
    if(e<1||e>L.length+1)
        cout << " The operation is illegal!" << endl;
    else{
        for(int i = e;i<L.length;i++){
            L.element[i-1]=L.element[i];
        }
        L.length--;
    }
}
//输入10本图书的编号，名称，价格，并把这些图书的信息输出，每本书一行
#include<iostream>
#include<cstring>
#include<string>
using namespace std;

typedef struct book{
    int number;
    string name;
    double price;
}book;

int main(){

    book Allbooks[10]={0,"",0.0};
    int i;
    cout << "Please enter your books information: " << endl;
    
    for(i=0;i<10;i++)
        cin >> Allbooks[i].number >> Allbooks[i].name >> Allbooks[i].price;
    cout << "Number\t\t" << "Name\t\t\t" << "Price" << endl;
    for(i=0;i<10;i++){
        cout << Allbooks[i].number;
        cout << "\t\t";
        cout << Allbooks[i].name;
        cout << "\t\t";
        cout << Allbooks[i].price << endl;
    }
    system("pause");
    return 0;

}

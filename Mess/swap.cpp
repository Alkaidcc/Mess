#include<iostream>
using namespace std;

void swap(int& a,int& b);
void swap(int& a,int& b){
    int temp;
    temp=a;
    a=b;
    b=temp;
}

int main(){
    int n,m;
    cin >> n >> m;
    swap(n,m);
    cout << n << m << endl;
    system("pause");
    return 0;
}
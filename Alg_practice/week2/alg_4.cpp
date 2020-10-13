/*
Filename		:alg_4.cpp
Date			:2020/09/29 19:22:19
Author			:ZZC
Description     :N�ʺ�����
*/
#include <iostream>
#include <vector>
using namespace std;

int array[20];
int num = 0;

int is_valid(int row, int col){   //�жϵ�row�С���col���ܷ����
    int i = 1;
    while(i < row){
        if(array[i] == col || abs(i - row) == abs(array[i] - col))
            return 0;
        i++;
    }
    return 1;
}

void solve(int row, int n){
    int i;
    if(row > n){
        num++;
        cout << "�� " << num << "���⣺";
        for(i = 1;i <= n;i++){
            cout << "( " << i << ", " << array[i] << ") ";
        }
        cout << endl;
    }
    for(i = 1;i <= n;i++){
        if(is_valid(row,i)){
            array[row] = i;
            solve(row + 1, n);
        }
    }
}

int main(){
    int n;
    cout << "n = ";
    while (cin >> n)
    {   
        if(n >= 20){
            cout << "nֵ̫���ˣ�������⣡" << endl;
        }else{
            solve(1,n);
            cout << "n = ";
        }
        num = 0;
        
    }
    system("pause");
    return 0;
}

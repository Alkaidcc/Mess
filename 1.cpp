/*
Filename		:1.cpp
Date			:2020/09/18 08:06:49
Author			:ZZC
Description     :
*/
#include <iostream>
using namespace std;

int square(int x);
int square(int x){
    x = x * x;
    return x;
}

int main(){
    int x;
    cout << "Please input a number: ";
    cin >> x;
    int res = square(x);
    cout << "The number after square is : " << res << endl;  
    system("pause");
   return 0;
}

/*
Filename		:6.cpp
Date			:2020/09/25 09:29:44
Author			:ZZC
Description     :编写一个函数判断一个数是否为水仙花数,水仙花数是指一个 3 位数，它的每个位上的数字的 3次幂之和等于它本身
*/
#include <iostream>

using namespace std;

int main(){
    int n, a, b, c, sum(0);
    cin >> n;
    a = n %10;
    b = n / 10 % 10;
    c = n /100;
    sum += a * a * a + b * b * b + c * c *c;
    if(sum == n){
        cout << "该数是水仙花数 " << endl;
    }else {
        cout << "该数不是水仙花数 " << endl;
    }
    system("pause");
    return 0;
}

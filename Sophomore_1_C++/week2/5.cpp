/*
Filename		:5.cpp
Date			:2020/09/24 18:31:23
Author			:ZZC
Description     :输入两个正整数a，b，将a，b化为二进制数，然后将这两个二进制数作二进制加法运算，再将结果化为十进制数输出
*/
#include <iostream>
#include <deque>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    deque <int> q1;
    deque <int> q2;
    // dec2bin
    while (a||b)
    {
        if(a){
            q1.push_front(a % 2);
            a /= 2;
        }
        if(b){
            q2.push_front(b % 2);
            b /= 2;
        }  
    }
    // fixed
    if(q1.size() <= q2.size()){
        while(q1.size() < q2.size()){
            q1.push_front(0);
        }
    }
    else{
        while(q2.size() < q1.size()){
            q2.push_front(0);
        }
    }
    // add
    int length = q2.size();
    for(int i = length - 1;i >= 0; i--){
        q2[i] = q2[i] + q1[i];
        if(q2[i] > 1){
            q2[i] %= 2;
            if(i == 0)
                q2.push_front(1);
            else
                q2[i - 1] += 1;
        }
    }
    //bin2dec
    int sum = 0;
    while (!q2.empty())
    {
        sum = sum * 2 + (*q2.begin());
        q2.pop_front();
    }
    cout << sum << endl;
    
    system("pause");
    return 0;
}

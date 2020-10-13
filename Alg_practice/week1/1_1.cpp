/*
Filename		:1_1.cpp
Date			:2020/09/22 19:16:20
Author			:ZZC
Description     :测试C++标准库中sort算法的平均运行时间
*/

#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
using namespace std;

void average_time_sort(int n);
void average_time_sort(int n){
    vector<int> myv(n);
    clock_t passed_time = 0;      //累计总时间
    const int times =100;         //定义排序的次数
    for(int i = 0;i < times;i++){
        srand((unsigned)time(NULL));
        for(int i = 0;i < n;i++){
            myv[i] = rand() % n + 1;
        }
        clock_t start_time = clock();   //开始的时间
        sort(myv.begin(), myv.end());   
        clock_t elapsed_time = clock() - start_time;    //单次所用的时间
        passed_time += elapsed_time;                      //累计时间
    }
    cout << fixed << setprecision(6);
    cout << "Time elapsed: " << double(passed_time) / CLOCKS_PER_SEC / times << " seconds." << endl;
}

int main(){
    const int n =100000;
    average_time_sort(n);
    system("pause");
    return 0;
}

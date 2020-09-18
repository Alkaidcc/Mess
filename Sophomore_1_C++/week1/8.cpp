/*
Filename		:8.cpp
Date			:2020/09/18 12:47:52
Author			:ZZC
Description     :统计若干个学生的数学课考试平均分
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int score[10] = {99,92,98,88,79,90,65,94,86,89};
    int sum = 0;
    for(int i = 0;i < 10;i++){
        sum += score[i];
    }
    double average_score = sum /10;
    cout << "The average scores : " << average_score << endl;
    system("pause");
    return 0;
}
/*
Filename		:7.cpp
Date			:2020/09/18 12:25:16
Author			:ZZC
Description     :将一个整型矩阵进行转置
*/
#include <iostream>
using namespace std;

void convert(int matrix[5][5]);
void convert(int matrix[5][5]){
    for(int i = 0;i < 5;i++){
        for(int j = i + 1;j < 5;j++){
            int temp;
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}
int main(){
    int matrix[5][5];
    int num = 0;
    for(int i = 0;i < 5;i++){
        for(int j = 0;j < 5;j++){
            matrix[i][j] = num++;
        }
    }
    cout << "The origin matrix is: " << endl;
    for(int i = 0;i < 5;i++){
        for(int j = 0;j < 5;j++){
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    convert(matrix);
    cout << "The matrix after converting: " << endl;
    for(int i = 0;i < 5;i++){
        for(int j = 0;j < 5;j++){
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}

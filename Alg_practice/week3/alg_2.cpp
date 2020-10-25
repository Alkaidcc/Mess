/*
Description     :设计一个递归算法以生成螺旋矩阵并输出，一个4X4的螺旋矩阵
*/
//matrix第0行和第0列不用
#include <iostream>
#include <string.h>
using namespace std;
int matrix[101][101];
int size;

void solve(int matrixNum, int currentNumber, int matrixLen, int maxNum);
void solve(int matrixNum, int currentNumber, int matrixLen, int maxNum){
    //出口
    if(matrixLen == 1){//如果矩阵长度为1
        matrix[matrixNum][matrixNum] = maxNum;
        return;
    }
    if(matrixLen == 2){//如果矩阵长度为2
        matrix[matrixNum][matrixNum] = currentNumber++;
        matrix[matrixNum][matrixNum + 1] = currentNumber++;
        matrix[matrixNum + 1][matrixNum + 1] = currentNumber++;
        matrix[matrixNum + 1][matrixNum] = currentNumber;
        return;
    }
    //定义当前矩阵的边缘
    int mazeEdge = size + 1 - matrixNum;

    //上边缘
    for(int i = matrixNum; i <= mazeEdge;i++){
        matrix[matrixNum][i] = currentNumber;
        currentNumber++;
    }
    //右边缘
    for(int i = matrixNum + 1; i <= mazeEdge;i++){
        matrix[i][mazeEdge] = currentNumber;
        currentNumber++;
    }
    //下边缘
    for(int i = mazeEdge - 1; i >= matrixNum;i--){
        matrix[mazeEdge][i] = currentNumber;
        currentNumber++;
    }
    //左边缘
    for(int i = mazeEdge - 1; i >= matrixNum + 1; i--){
        matrix[i][matrixNum] = currentNumber;
        currentNumber++;
    }
    //递归
    solve(matrixNum + 1, currentNumber, matrixLen - 2, maxNum);
}

int main(){
    cout << "Please input the size of the Matrix of Maze: ";
    while(cin >> size){
        solve(1, 1, size, size * size);
        for(int i = 1;i <= size;i++){
            for(int j = 1;j <= size;j++){
                cout << matrix[i][j] << "\t";
            }
            cout << endl;
        }
        memset(matrix, 0, sizeof(matrix));
        cout << "Please input the size of the Matrix of Maze: ";
    }
    system("pause");
    return 0;
}
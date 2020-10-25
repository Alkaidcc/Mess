/*
Description     :���һ���ݹ��㷨�������������������һ��4X4����������
*/
//matrix��0�к͵�0�в���
#include <iostream>
#include <string.h>
using namespace std;
int matrix[101][101];
int size;

void solve(int matrixNum, int currentNumber, int matrixLen, int maxNum);
void solve(int matrixNum, int currentNumber, int matrixLen, int maxNum){
    //����
    if(matrixLen == 1){//������󳤶�Ϊ1
        matrix[matrixNum][matrixNum] = maxNum;
        return;
    }
    if(matrixLen == 2){//������󳤶�Ϊ2
        matrix[matrixNum][matrixNum] = currentNumber++;
        matrix[matrixNum][matrixNum + 1] = currentNumber++;
        matrix[matrixNum + 1][matrixNum + 1] = currentNumber++;
        matrix[matrixNum + 1][matrixNum] = currentNumber;
        return;
    }
    //���嵱ǰ����ı�Ե
    int mazeEdge = size + 1 - matrixNum;

    //�ϱ�Ե
    for(int i = matrixNum; i <= mazeEdge;i++){
        matrix[matrixNum][i] = currentNumber;
        currentNumber++;
    }
    //�ұ�Ե
    for(int i = matrixNum + 1; i <= mazeEdge;i++){
        matrix[i][mazeEdge] = currentNumber;
        currentNumber++;
    }
    //�±�Ե
    for(int i = mazeEdge - 1; i >= matrixNum;i--){
        matrix[mazeEdge][i] = currentNumber;
        currentNumber++;
    }
    //���Ե
    for(int i = mazeEdge - 1; i >= matrixNum + 1; i--){
        matrix[i][matrixNum] = currentNumber;
        currentNumber++;
    }
    //�ݹ�
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
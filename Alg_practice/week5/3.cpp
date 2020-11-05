#include<iostream>
#include<algorithm>
#include <climits>
using namespace std;
const int N = 10;
int matrix [N][N];
int temp[N];
int main()
{   
    int cost = 0;
    int num;
    int minCost = INT_MAX;
    cout<<"输入任务个数: ";
    cin>>num;
    cout<<"输入成本矩阵: " << endl;
    for(int i=0;i < num;i++){       //初始化成本矩阵
        for(int j=0;j < num;j++)
            cin>>matrix[i][j];
        temp[i]=i;                  //用于全排列
    }
    do{                             //利用next_permutation函数依次求出数组的全排列
        cost=0;
        //置零
        for(int i = 0;i< num;i++)
            cost += matrix[i][temp[i]];
        if(cost<minCost){
            minCost=cost;
            // for(int i = 0;i < num;i++){
            //     cout << temp[i] + 1 << " ";
            // }
            // cout << endl;
        }
    }while(next_permutation(temp,temp+num));//全排列
    cout<<"最小成本: " << minCost << endl;
    system("pause");
    return 0;
}
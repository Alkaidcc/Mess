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
    cout<<"�����������: ";
    cin>>num;
    cout<<"����ɱ�����: " << endl;
    for(int i=0;i < num;i++){       //��ʼ���ɱ�����
        for(int j=0;j < num;j++)
            cin>>matrix[i][j];
        temp[i]=i;                  //����ȫ����
    }
    do{                             //����next_permutation����������������ȫ����
        cost=0;
        //����
        for(int i = 0;i< num;i++)
            cost += matrix[i][temp[i]];
        if(cost<minCost){
            minCost=cost;
            // for(int i = 0;i < num;i++){
            //     cout << temp[i] + 1 << " ";
            // }
            // cout << endl;
        }
    }while(next_permutation(temp,temp+num));//ȫ����
    cout<<"��С�ɱ�: " << minCost << endl;
    system("pause");
    return 0;
}
#include <iostream>
using namespace std;

typedef struct Components{
    int w;
    int c;
}Components;
Components Com[100][100];//Com[i][j].w �����i������ڵ�j����Ӧ�̵����� Com[i][j].c�����i������ڵ�j����Ӧ�̵ļ۸�
int bestWeight = 1e7;   //��¼������С���� ���Ž�
int tempWeight = 0;     //��¼��ʱ��С����
int tempPro[100];       //��¼��ʱ��Ӧ�̵Ľ�    tempPro[i]�����i������Ĺ�Ӧ��
int bestPro[100];       //��¼���չ�Ӧ�̵Ľ� ���Ž�
int tempCost = 0;
int cost;   //�涨�ļ۸�
int n;      //������
int m;      //��Ӧ����


void dfs(int f){    //n���������
    if(f > n - 1){//�ݹ���ڣ��ﵽҶ�ӽ�㣬��ʾ�Ѿ�ѡ��һ������ʽ�����½�
        bestWeight = tempWeight;
        for(int i = 0;i < n;i++){
            bestPro[i] = tempPro[i];
        }
    }
    else{
        for(int i = 0;i < m;i++){
            if(tempCost + Com[f][i].c <= cost && tempWeight + Com[f][i].w < bestWeight){
                tempPro[f] = i;
                tempCost += Com[f][i].c;
                tempWeight += Com[f][i].w;
                dfs(f + 1);
                tempCost -= Com[f][i].c;
                tempWeight -= Com[f][i].w;
            }
        }
    }
}


int main(){
    cout << "�����벿��������Ӧ�������涨�ļ۸�";
    cin >> n >> m >> cost;
    cout << "�����벿����������" << endl;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> Com[i][j].w;
        }
    }
    cout << "�����벿���۸����" << endl;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> Com[i][j].c;
        }
    }
    dfs(0);
    for(int i = 0;i < n;i++){
        cout << bestPro[i] + 1 << " ";
    }
    cout << endl;
    cout << bestWeight << endl;
    system("pause");
    return 0;
}

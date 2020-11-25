#include <iostream>
using namespace std;
const int M_NUMBER = 2;
int m[M_NUMBER][100]; //ʱ��ɱ����� m[i][j]�����j����ҵ�ڵ�į�����ϴ����ʱ��
int s_time1 = 0;    //��ǰ���������ҵ1����Ҫ����ʱ��
int s_time2[100];    //s_time2[i]����ǰ���������ҵ2����Ҫ����ʱ��
int n;              //��ҵ��
int tempCost = 0;   //��ʱ���ʱ�仨��
int bestCost = 1e7;   //���Ž��ʱ�仨��
int tempSeq[100];   //�����ʱ�������
int bestSeq[100];   //������Ž������


void dfs(int f){    //n���������
    if(f > n - 1){//�ݹ���ڣ��ﵽҶ�ӽ�㣬��ʾ�Ѿ�ѡ��һ������ʽ�����½�
        if(s_time2[n - 1] < bestCost){
            for(int i = 0;i < n;i++){
                bestSeq[i] = tempSeq[i];
            }
            bestCost = s_time2[n - 1];
        }
    }
    else{
        for(int i = f;i < n;i++){
            s_time1 += m[0][tempSeq[i]];  //����s_time1
            s_time2[i] = max(s_time1,s_time2[i - 1]) + m[1][tempSeq[i]];//����s_time2
            if(s_time2[i] < bestCost){//��֦
                swap(tempSeq[i],tempSeq[f]);
                dfs(f + 1);
                swap(tempSeq[f],tempSeq[i]);
            }
            //���� ����
            s_time1 -= m[0][tempSeq[i]];
        }
    }
}

int main(){
    cout << "��������ҵ����";
    cin >> n;
    cout << "������ɱ�����" << endl;
    for(int i = 0;i < 2;i++){   //��ʼ���ɱ�����
        for(int j = 0;j < n;j++){
            cin >> m[i][j];
        }
    }
    for(int i = 0;i < n;i++){
        tempSeq[i] = i;
    }
    dfs(0);
    cout << "���ŵ���˳��Ϊ��"<< endl;
    for(int i = 0;i < 2;i++){
        for(int j = 0;j < n;j++){
            cout << m[i][bestSeq[j]] << " ";
        }
        cout << endl;
    }
    cout << "���Ŵ���ʱ��Ϊ��" << bestCost << endl;

    system("pause");
    return 0;
}

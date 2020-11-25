#include <iostream>
using namespace std;
const int M_NUMBER = 2;
int m[M_NUMBER][100]; //时间成本矩阵 m[i][j]代表第j个作业在第i台机器上处理的时间
int s_time1 = 0;    //当前任务完成作业1所需要的总时长
int s_time2[100];    //s_time2[i]代表当前任务完成作业2所需要的总时长
int n;              //作业数
int tempCost = 0;   //临时解的时间花费
int bestCost = 1e7;   //最优解的时间花费
int tempSeq[100];   //存放临时解的序列
int bestSeq[100];   //存放最优解的序列


void dfs(int f){    //n代表层数，
    if(f > n - 1){//递归出口，达到叶子结点，表示已经选中一种排序方式，更新解
        if(s_time2[n - 1] < bestCost){
            for(int i = 0;i < n;i++){
                bestSeq[i] = tempSeq[i];
            }
            bestCost = s_time2[n - 1];
        }
    }
    else{
        for(int i = f;i < n;i++){
            s_time1 += m[0][tempSeq[i]];  //更新s_time1
            s_time2[i] = max(s_time1,s_time2[i - 1]) + m[1][tempSeq[i]];//更新s_time2
            if(s_time2[i] < bestCost){//剪枝
                swap(tempSeq[i],tempSeq[f]);
                dfs(f + 1);
                swap(tempSeq[f],tempSeq[i]);
            }
            //回溯 撤销
            s_time1 -= m[0][tempSeq[i]];
        }
    }
}

int main(){
    cout << "请输入作业数：";
    cin >> n;
    cout << "请输入成本矩阵：" << endl;
    for(int i = 0;i < 2;i++){   //初始化成本矩阵
        for(int j = 0;j < n;j++){
            cin >> m[i][j];
        }
    }
    for(int i = 0;i < n;i++){
        tempSeq[i] = i;
    }
    dfs(0);
    cout << "最优调度顺序为："<< endl;
    for(int i = 0;i < 2;i++){
        for(int j = 0;j < n;j++){
            cout << m[i][bestSeq[j]] << " ";
        }
        cout << endl;
    }
    cout << "最优处理时间为：" << bestCost << endl;

    system("pause");
    return 0;
}

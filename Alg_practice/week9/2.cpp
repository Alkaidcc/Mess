#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int n = 7;    //任务的数量
int m = 2;  //机器的数量
typedef struct Task
{
    int id; //作业编号
    int time;   //作业所需要的时间
    int machineid;  //作业在哪台机器上被执行
    bool operator<(const Task& t)const{
        return time > t.time;
    }
}Task;
Task A[n];
int main(){
    for(int i = 0;i < n;i++){
        cin >> A[i].time;
        A[i].id = i;
    }
    sort(A, A + n);     //O(nlogn)
    priority_queue<Task> q;
    for(int i = 0;i < m;i++){   //把m个机器先分配任务
        A[i].machineid = i;
        q.push(A[i]);   ////push(x)将令x入队，时间复杂度为O(logN),其中N为当前优先队列中的元素个数。
    }
    for(int j = m;j < n;j++){   //分配剩余的任务
        Task temp = q.top();
        q.pop();        ////pop()令队首元素出队，时间复杂度为O（logN)，其中N为当前优先队列中的元素个数
        A[j].machineid = temp.machineid;
        temp.time +=A[j].time;
        q.push(temp);
    }
    Task res;
    while(!q.empty()){  //取到最后一个任务的时间，即所有任务都完成时的时间花费
        res = q.top();
        q.pop();
    }
    for(int i = 0;i < n;i++){
        cout << "作业编号: " << A[i].id + 1 << "在第 " << A[i].machineid + 1 << " 号机器上加工" << endl;
    }
    cout << "最终时间花费为: " << res.time << endl;
    system("pause");
    return 0;
}

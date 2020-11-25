#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int n = 7;    //���������
int m = 2;  //����������
typedef struct Task
{
    int id; //��ҵ���
    int time;   //��ҵ����Ҫ��ʱ��
    int machineid;  //��ҵ����̨�����ϱ�ִ��
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
    for(int i = 0;i < m;i++){   //��m�������ȷ�������
        A[i].machineid = i;
        q.push(A[i]);   ////push(x)����x��ӣ�ʱ�临�Ӷ�ΪO(logN),����NΪ��ǰ���ȶ����е�Ԫ�ظ�����
    }
    for(int j = m;j < n;j++){   //����ʣ�������
        Task temp = q.top();
        q.pop();        ////pop()�����Ԫ�س��ӣ�ʱ�临�Ӷ�ΪO��logN)������NΪ��ǰ���ȶ����е�Ԫ�ظ���
        A[j].machineid = temp.machineid;
        temp.time +=A[j].time;
        q.push(temp);
    }
    Task res;
    while(!q.empty()){  //ȡ�����һ�������ʱ�䣬�������������ʱ��ʱ�仨��
        res = q.top();
        q.pop();
    }
    for(int i = 0;i < n;i++){
        cout << "��ҵ���: " << A[i].id + 1 << "�ڵ� " << A[i].machineid + 1 << " �Ż����ϼӹ�" << endl;
    }
    cout << "����ʱ�仨��Ϊ: " << res.time << endl;
    system("pause");
    return 0;
}

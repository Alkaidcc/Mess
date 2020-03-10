// ��ͨ�����뽫���б����������У�֮���ö���ͷԪ�صĵ���ʱ������ڵ����ʱ��Աȣ�
// ��Ϊ����˵���ȿ��ǽ��Ĵ��ڣ����Կ��Ա������ڡ�
// ������׵ĵ���ʱ���������ڵ����ʱ��󣬾Ͳ���Ҫ�ȴ�������������ڵĵȴ�ʱ�䣬�����������������һ��
// �����������޷����񣬾����������ڵ�������ʱ�䡣����������ڶ��޷����㣬����Ҫ�ȴ�����������ȴ���ʱ�䲢�����±��¼��
// �����Ҫ�ȴ���ʱ�����ɵ�ʱ�䶼��¼�����������ĿҪ�������������С�
#include <iostream>
#include <cstdio>
#include <queue>
#include<climits>
using namespace std;
struct node
{
    int t, p;
};
int main()
{
    int n;
    cin>>n;
    queue <node> q;
    int i;

    //¼������
    for(i = 0; i < n; i++)
    {
        node tmp;
        cin>>tmp.t>>tmp.p;
        if(tmp.p > 60) tmp.p = 60;
        q.push(tmp);
    }

    int k;
    cin>>k;//��k������

    int win[15] = {0}, num[15] = {0};   //���ʱ��  ��������
    int wait = 0, maxn = 0, sum = 0;    //���εȴ�ʱ��  ��ȴ�ʱ��  �ܵȴ�ʱ��
    
    while(!q.empty())
    {
        int flag = 0;
        int minn = INT_MAX, imin = 0;   //������ʱ�� ������ʱ��Ĵ����±�
        for(i = 0; i < k; i++)
        {
            if(win[i] <= q.front().t)               //���������λ������ʱ������ʱ��󣬾ʹ�����Ҫ�ȴ�
            {
                win[i] = q.front().t + q.front().p; //�������������ɵ�ʱ��
                num[i]++;                           //��������+1
                flag = 1;                           //���һ��  ������Ҫ�ȴ�
                q.pop();                            
                break;
            }
            if(minn > win[i])                       //�����Ҫ�ȴ����ͼ�¼���������������ɵ��Ǹ����ڵ����ʱ�䣬���±�
            {
                minn = win[i];
                imin = i;
            }
        }
        if(flag == 0)                               //K�����ڶ����� ��Ҫ�ȴ�
        {
            wait = win[imin] - q.front().t;         //�ȴ���ʱ�䣬�����ɵ�ʱ���ȥ���е�һ���˵����ʱ��
            win[imin] += q.front().p;               //���µȴ�ʱ�����ٴ��ڵ����ʱ��
            if(wait > maxn) maxn = wait;            //���ϸ��µȴ����ʱ��
            sum += wait;                            //��ȴ�ʱ��ĺ�
            num[imin]++;                            //��Ӧ��������++
            q.pop();
        }
    }
    //ѡ��3������������ʱ����Ϊ�����ɵ�ʱ��
    int last = win[0];
    for(i = 0; i < k; i++)
    {
        if(win[i] > last) last = win[i];
    }

    printf("%.1lf %d %d\n", sum * 1.0 / n * 1.0, maxn, last);
    //���num[]���飬������Ŀ�����
    for(i = 0; i < k; i++)
    {
        cout<<num[i];
        if(i != k - 1) cout<<" ";
        else cout<<endl;
    }
    return 0;
}
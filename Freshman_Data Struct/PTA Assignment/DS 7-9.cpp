// 先通过输入将队列保存在数组中，之后用队列头元素的到达时间跟窗口的完成时间对比，
// 因为题中说优先考虑近的窗口，所以可以遍历窗口。
// 如果队首的到达时间比这个窗口的完成时间大，就不需要等待，更新这个窗口的等待时间，并且这个窗口人数加一，
// 如果这个窗口无法服务，就求出这个窗口的最快完成时间。如果三个窗口都无法满足，就需要等待，并且求出等待的时间并且用下表记录。
// 最后将需要等待的时间和完成的时间都记录下来。最后将题目要求的数据输出就行。
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

    //录入数据
    for(i = 0; i < n; i++)
    {
        node tmp;
        cin>>tmp.t>>tmp.p;
        if(tmp.p > 60) tmp.p = 60;
        q.push(tmp);
    }

    int k;
    cin>>k;//有k个窗口

    int win[15] = {0}, num[15] = {0};   //完成时间  窗口人数
    int wait = 0, maxn = 0, sum = 0;    //单次等待时间  最长等待时间  总等待时间
    
    while(!q.empty())
    {
        int flag = 0;
        int minn = INT_MAX, imin = 0;   //最快完成时间 最快完成时间的窗口下标
        for(i = 0; i < k; i++)
        {
            if(win[i] <= q.front().t)               //如果队列首位，到达时间比完成时间大，就代表不需要等待
            {
                win[i] = q.front().t + q.front().p; //更新这个窗口完成的时间
                num[i]++;                           //窗口人数+1
                flag = 1;                           //标记一下  代表不需要等待
                q.pop();                            
                break;
            }
            if(minn > win[i])                       //如果需要等待，就记录各个窗口里最快完成的那个窗口的完成时间，和下标
            {
                minn = win[i];
                imin = i;
            }
        }
        if(flag == 0)                               //K个窗口都有人 需要等待
        {
            wait = win[imin] - q.front().t;         //等待的时间，最快完成的时间减去队列第一个人到达的时间
            win[imin] += q.front().p;               //更新等待时间最少窗口的完成时间
            if(wait > maxn) maxn = wait;            //不断更新等待的最长时间
            sum += wait;                            //求等待时间的和
            num[imin]++;                            //对应窗口人数++
            q.pop();
        }
    }
    //选出3个窗口中最大的时间作为最后完成的时间
    int last = win[0];
    for(i = 0; i < k; i++)
    {
        if(win[i] > last) last = win[i];
    }

    printf("%.1lf %d %d\n", sum * 1.0 / n * 1.0, maxn, last);
    //输出num[]数组，即服务的客人数
    for(i = 0; i < k; i++)
    {
        cout<<num[i];
        if(i != k - 1) cout<<" ";
        else cout<<endl;
    }
    return 0;
}
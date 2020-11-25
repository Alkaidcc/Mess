#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct Cow{ //牛
    int begin;      //起始时间
    int end;        //终止时间
    int no;         //牛的编号
    bool operator<(const Cow& c) const{
        if(c.end == end){
            return begin < c.begin;
        }else{
            return end < c.end;
        }
    }
}Cow;
Cow c[1000];
struct Fence{   //畜栏
    int end;    //畜栏的结束时间
    int no;     //畜栏的编号
    Fence(int e, int n):end(e),no(n){}
    bool operator<(const Fence& f) const{       //重载优先队列时的排序
        return end > f.end;
    }
    
};
int Position[1000]; //代表i号奶牛去的畜栏编号
int main(){
    int n,total = 0;
    cout << "请输入牛的个数（n）： ";
    cin >> n;
    cout << "请输入n头牛的起始时间和终止时间: " << endl;
    for(int i = 0;i < n;i++){
        cin >> c[i].begin >> c[i].end;
        c[i].no = i;
    }
    sort(c, c + n); //对奶牛排序
    priority_queue<Fence> pr_q; //优先队列 结束时间小的畜栏排在前面
    for(int i = 0;i < n;i++){
        if(pr_q.empty()){       //当前没有畜栏
            total++;            //增加一个畜栏
            pr_q.push(Fence(c[i].end,total)); 
            Position[c[i].no] = total;          //标记牛的畜栏号
        }else{
            Fence f = pr_q.top();
            if(f.end < c[i].begin){     //当前畜栏可用
                pr_q.pop();             //出队
                Position[c[i].no] = f.no;   //把可用的畜栏编号标记
                pr_q.push(Fence(c[i].end, f.no));   
            }else{                      //当前畜栏不可用
                total++;                //增加一个畜栏
                pr_q.push(Fence(c[i].end, total));  
                Position[c[i].no] = total;
            }
        }
    }
    cout << "共分配了 " << total << " 个畜栏" << endl;
    for(int i = 0; i < n;i++){
        cout << "牛编号: " << c[i].no + 1 << "  畜栏编号: " << Position[c[i].no] << endl; 
    } 

    system("pause");
    return 0;
}

//7-2 列车厢调度
#include<iostream>
#include<stack>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

int main(){
    string cab1,cab2;
    vector<int> option; //1:1->2  2:1->3  3:3->2
    stack<char> s1,s2,s3;
    cin >> cab1 >> cab2;
    for(int i=cab1.length()-1;i>=0;i--){
        s1.push(cab1.at(i));
        s2.push(cab2.at(i));
    }
    bool flag = true;
    while(!s2.empty()){
        if(!s1.empty()&&s1.top()==s2.top()){//栈顶元素相同就pop
            s1.pop();
            s2.pop();
            option.push_back(1);
        }
        else if(!s3.empty()&&s3.top()==s2.top()){   //这时s1已经为空了 因为先遍历s1
            s3.pop();
            s2.pop();
            option.push_back(3);
        }
        else if(s1.empty()&&!s3.empty()&&s3.top()!=s2.top()){//s3和s2栈顶元素不相同则是错误的遍历
            flag = false;
            break;
        }
        else{
            //如果不能移动就压栈
            s3.push(s1.top());
            s1.pop();
            option.push_back(2);
        }
        
    }
    if(!flag){
        cout << "Are you kidding me?";
        return 0;

    }
    else{
        int N = option.size();
        for(int i=0;i<N;i++){
            if(option[i]==1)
                cout << "1->2" << endl;
            else if(option[i]==2)
                cout << "1->3" << endl;
            else if(option[i]==3)
                cout << "3->2" << endl;
        }
    }
    system("pause");
    return 0;
    

}
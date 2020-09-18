//7-1 银行业务队列简单模拟
#include<iostream>
#include<queue>
using namespace std;

int main(){
    int N;
    int number;
    queue<int> A;
    queue<int> B;
    cin >> N;
    while(N--){
        cin >> number;
        if(number % 2 != 0) //奇数
            A.push(number);
        else                //偶数
            B.push(number);
    }
    while(!A.empty()&&!B.empty()){
        cout << A.front()<< " ";
        A.pop();
        cout << A.front()<< " ";
        A.pop();
        cout << B.front()<< " ";
        B.pop();
    }
    while(!B.empty()){
        if(B.size()==1)
            cout << B.front();
        else
            cout << B.front() << " ";
        B.pop();
    }
    while(!A.empty()){
        if(A.size()==1)
            cout << A.front();
        else
            cout << A.front() << " ";
        A.pop();
    }
    system("pause");
    return 0;
}
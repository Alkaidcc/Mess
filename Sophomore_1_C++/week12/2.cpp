//ʹ��deque���洢�û������N��С���������δ�ӡ�������ЩС�����ټ���һ�����ǵľ�ֵ
#include <iostream>
#include <numeric>
#include <algorithm>
#include <deque>
using namespace std;

int main(){
    int N;
    cin >> N;
    double temp;
    double average = 0;
    deque<double> dq;
    for(int i = 0;i < N;i++){
        cin >> temp;
        dq.push_back(temp);
    }
    for(auto it:dq){
        cout << it << ends;
    }
    cout << endl;
    average = accumulate(dq.begin(),dq.end(),0.0) / dq.size();
    cout << "average is: " << average << endl;
    system("pause");
    return 0;
}

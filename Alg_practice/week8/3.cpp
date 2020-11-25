#include <iostream>
#include <algorithm>
#include <queue>
#include <sstream>
using namespace std;

deque<int> A;
deque<int> B;

int main(){
    string s1,s2;
    int total = 0;
    cout << "请输入一组会议: " << endl;
    getline(cin,s1);
    istringstream is1(s1);
    int inter;
    while(is1 >> inter){
        A.push_back(inter);
    }

    cout << "请输入一组会议室: " << endl;
    getline(cin, s2);
    istringstream is2(s2);
    while(is2 >> inter){
        B.push_back(inter);
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int i = 0,j = 0;
    while(!B.empty()){
        if(B.front() >= A.front()){
            total++;
            B.pop_front();
            A.pop_front();
        }else{
            B.pop_front();
        }
    }
    cout << total << endl;
    system("pause");
    return 0;
}

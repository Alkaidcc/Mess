#include<iostream>
#include<ctime>
using namespace std;
int main(){
    cout << "Enter the delay time, in seconds: ";
    float secs;
    cin >> secs;
    clock_t delay = secs * CLOCKS_PER_SEC;  //CLOCKS_PER_SEC表示每秒钟包含的系统时间单位数
    cout << "starting\a\n";
    clock_t start = clock();
    while(clock()-start < delay)
    ;
    cout << "done \a\n";
    system("pause");
    return 0; 
}
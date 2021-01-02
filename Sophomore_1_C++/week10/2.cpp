#include <iostream>
using namespace std;

template<class T>
T mean(T x[], int n){
    T sum = 0;
    for(int i = 0;i < n;i++){
        sum += x[i];
    }
    return sum / n;
}

int main(){
    int a[5] = {5,66,84,34,-1};
    cout << mean(a,5) << endl;
    double b[5] = {1.25,3.33,5.78,95.22,45.2};
    cout << mean(b,5) << endl;
    system("pause");
    return 0;
}

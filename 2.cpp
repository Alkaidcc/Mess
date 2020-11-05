#include <iostream>
using namespace std;

long long recursive(long long n){
    if(n == 1)
        return 1;
    return n * recursive(n-1);
}

void Recursive(){
    long long n;
    cout << "ÇëÊäÈën: ";
    cin >> n;
    long long result = 0;
    for(long long i = 1;i <= n;i++){
        result += recursive(i);
    }
    cout << result << endl;
}

void Optimization(){
    long long n;
    cout << "ÇëÊäÈën: ";
    cin >> n;
    long long result = 0,number = 1;
    for(long long i = 1;i <= n;i++){
        number *= i;
        result += number;
    }
    cout << result << endl;
    
}

int main(){
    Recursive();//O(n)
    Optimization();//O(n)
    system("pause");
    return 0;
}

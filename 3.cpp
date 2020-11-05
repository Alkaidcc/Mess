#include <iostream>
using namespace std;

int main(){
    for(int i = 100;i < 1000;i++){
        int a, b, c;
        a = i/100;
        b = (i % 100) / 10;
        c = i % 10;
        if(a > c && c > b && (a + b + c) == a * b *c){
            cout << i << " ";
        }
    }
    system("pause");
    return 0;
}

#include<iostream>
using namespace std;

int main() {
    int n;
    int cnt = 0;
    char num[1000];
    while(cin >> n >> num) {
        n--;
        while(n) {
            if(num[n] == '1') {
                n--;
            }else {
                num[n] = '1';
                for(int i = n-1;i>=0;i--) {
                    if(num[i] == '1')
                        num[i] = '0';
                    else
                        num[i] = '1';
                }
                n--;
                cnt++;
            }
        }
        printf("%d\n",cnt);
        cnt =0;
    }
    system("pause");
    return 0;
}
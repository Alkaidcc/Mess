#include<iostream>
using namespace std;

int gcd(int a,int b)
{
     return b==0?a:gcd(b,a%b);
}
long long f(long long n, long long a, long long b) {
    if(n ==0) {
        return 1;
    }
    long long p=1,q=1,t;
    t = p * a + q * b;
    for(long long i=2;i<=n;i++) {
        t = p * a + q * b;
        t %= (long long)(1e9+7);
        p=q;
        q=t;
    }
    return t;
}

int main() {
    long long x,y,i;
    while(cin >> n >> a >> b){
        n %= (long long)(1e9+7);
        long long r = f(n, a, b);
        printf("%lld",r);
    }
    system("pause");
    return 0;
}
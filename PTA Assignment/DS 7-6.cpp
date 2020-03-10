#include<iostream>
using namespace std;

int main(){
    int N,m,i;
    int a[10000];
    cin >> N >> m;
    for(i=0;i<N;i++)
        cin >> a[i];
    m%=N;
    if(m==N){
        for(i=0;i<N;i++){
            if(i==0)
                cout << a[i];
            else
                cout << " " << a[i];
        }
    }
    else{
        for(i=m;i<N;i++){
            if(i==m)
                cout << a[i];
            else
                cout << " " << a[i];
        }
        for(i=0;i<m;i++){
            cout << " " << a[i];
        }
    }
    return 0;
}
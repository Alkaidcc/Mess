#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
// cin cout太慢了。。。
//用printf才能过。。
using namespace std;

struct node{
    int key;
    int next;
}data[100005];
char flag[10005];
int res[100005];
int del[100005];
int main(){
    int P,N,temp;
    int r=0,d=0;
    cin >> P >> N;
    int cnt = N;
    while(N--){
        cin >> temp;
        cin >> data[temp].key >> data[temp].next;
    }
    memset(flag,0,sizeof(flag));
    for(int i=0;i<cnt&&P!=-1;i++){
        if(!flag[abs(data[P].key)]){

            flag[abs(data[P].key)]=1;
            res[r++]=P;
            P=data[P].next;
        }
        else{
            del[d++]=P;
            P=data[P].next;
        }
    }
    if(r){
        for(int i=0;i<r;i++){
            if(i==0){
                printf("%05d %d",res[i],data[res[i]].key);  
            }  
            else{  
                printf(" %05d\n%05d %d",res[i],res[i],data[res[i]].key);  
            }  
        }  
        printf(" -1\n");
    }
    if(d){
        for(int i=0;i<d;i++){
            if(i==0){
                printf("%05d %d",del[i],data[del[i]].key);  
            }  
            else{  
                printf(" %05d\n%05d %d",del[i],del[i],data[del[i]].key);  
            }  
        }  
        printf(" -1\n");
    }

    system("pause");
    return 0;
}
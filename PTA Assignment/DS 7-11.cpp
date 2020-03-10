#include<iostream>
using namespace std;

typedef struct node{
    int address;
    int data;
    int next;
}node;
node arr[100010];
int a[100010];
int b[100010];
int main(){
    int ad,N;
    int cnt=0;
    int Address,Data,Next;
    scanf("%d %d",&ad,&N);
    for(int i=0;i<N;i++){
        cin >> Address >> Data >> Next;
        arr[Address].address=Address;
        arr[Address].data=Data;
        arr[Address].next=Next;
    }

    while(ad!=-1){
        a[cnt++]=ad;
        ad=arr[ad].next;
    }
    int left=0,right=cnt-1;
    int counter=0;
    while(left<=right){
        if(left==right)
            b[counter++]=a[left++];
        else{
            b[counter++]=a[right--];
            b[counter++]=a[left++];
        }
    }
    for(int i = 0;i<counter-1;i++){
        printf("%05d %d %05d\n",b[i],arr[b[i]].data,b[i+1]);
    }
    printf("%05d %d %d\n",b[counter-1],arr[b[counter-1]].data,-1);
    system("pause");
    return 0;
}
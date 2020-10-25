#include <iostream>
#include <vector>
using namespace std;

void Merge_Sort_Recursive(vector<int>& arr,vector<int> reg,int start,int end);
void Merge_Sort_Recursive(vector<int>& arr,vector<int> reg,int start,int end){
    //递归出口
    if(start >= end)
        return;
    int len = end - start;
    int mid = len/2 + start;
    int start1 = start,start2 = mid+1;
    int end1 = mid,end2 = end;
    int k = start;

    Merge_Sort_Recursive(arr,reg,start1,end1);
    Merge_Sort_Recursive(arr,reg,start2,end2);

    while(start1 <= end1 && start2 <= end2)
        reg[k++]=arr[start1] > arr[start2] ? arr[start1++] : arr[start2++];
    while(start1 <= end1)
        reg[k++] = arr[start1++];
    while(start2 <= end2)
        reg[k++] = arr[start2++];
    for(k=start;k<=end;k++)
        arr[k] = reg[k];
}

int main(){
    cout << "请输入数组大小： ";
    int n;
    while(cin >> n){
        vector<int> my_vec1(n);
        vector<int> my_vec2(n);
        cout << "请输入数组: ";
        for(int i = 0;i < n;i++){
            cin >> my_vec1[i];
        }
        Merge_Sort_Recursive(my_vec1, my_vec2,0,n - 1);
        cout << "归并排序: ";
        for(auto element : my_vec1){
            cout << element << " ";
        }
        cout << endl;
        my_vec1.clear();
        my_vec2.clear();
        cout << "请输入数组大小： ";
    }
    
    system("pause");
    return 0;
}
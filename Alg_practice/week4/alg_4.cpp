#include <iostream>
#include <string.h>
using namespace std;

int array[10001];
int temparray[10001];

int Merge(int arr[], int temp[], int left, int mid, int right);
int Reverse_pair(int arr[],int temp[],int left, int right);

int Merge(int arr[], int temp[], int left, int mid, int right){
    int count = 0;
    int start1 = left;
    int start2 = mid + 1;
    int end1 = mid;
    int end2 = right;
    int k = left;
    while(start1 <= end1 && start2 <= end2){
        if(arr[start1] > arr[start2]){
            temp[k++] = arr[start2++];
            count += mid - start1 + 1;
        }else{
            temp[k++] = arr[start1++];
        }
    }
    while(start1 <= end1){
        temp[k++] = arr[start1++];
    }
    while(start2 <= end2){
        temp[k++] = arr[start2++];
    }
    for(int i = left;i <= right;i++){
        arr[i] = temp[i];
    }
    return count;
}
int Reverse_pair(int arr[],int temp[],int left, int right){
    int count = 0;
    int mid = (left + right) / 2;
    if(left == right){
        return 0;
    }
    count += Reverse_pair(arr, temp, left, mid);
    count += Reverse_pair(arr, temp, mid + 1, right);
    count += Merge(arr, temp, left, mid, right);
    return count;
}


int main(){
    cout << "请输入数组规模： ";
    int N;
    while(cin >> N){
        cout << "请输入该数组: ";
        for(int i = 0;i < N;i++){
            cin >> array[i];
        }
        int reverse_pairs = Reverse_pair(array, temparray, 0, N - 1);
        cout << "存在 " << reverse_pairs << " 个逆序对。" << endl;
        memset(array, 0, sizeof(array));
        memset(temparray, 0, sizeof(temparray));
        cout << "请输入数组规模： ";
    }
    system("pause");
    return 0;
}

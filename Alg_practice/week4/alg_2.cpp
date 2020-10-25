#include <iostream>
#include <vector>
using namespace std;

int BinarySearch(int arr[], int left, int right,int element);
int BinarySearch(int arr[], int left, int right,int element){
    int NotFind = -1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(arr[mid] > element){
            right = mid - 1;
        }
        else if(arr[mid] < element){
            left = mid + 1;
        }
        else{
            if(arr[mid-1] == element){
                int temp[mid];
                for(int i = left;i < mid;i++){
                    temp[i] = arr[i];
                }
                return BinarySearch(temp,left,mid - 1,element);
            }else{
                return mid;
            }
        }
    }
    return NotFind;
}

int main(){
    cout << "�����������ģ��";
    int N;
    while(cin >> N){
        int my_vec[N];
        cout << "����������飺";
        for(int i = 0;i < N;i++){
            cin >> my_vec[i];
        }
        cout << "��������Ҫ���ҵ�Ԫ��: ";
        int k;
        cin >> k;
        int ans = BinarySearch(my_vec, 0 ,N - 1,k);
        if(ans == -1){
            cout << "δ�ҵ���Ԫ��" << endl;
        }
        else{
            cout << "��Ҫ���ҵ�Ԫ���ǣ�" << k;
            cout << "  ��Ԫ���ڵ�" << ans << " λ" << endl;
        }
        cout << "�����������ģ��";
    }
    system("pause");
    return 0;
}

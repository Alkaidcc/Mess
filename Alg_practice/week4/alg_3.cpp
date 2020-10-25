#include <iostream>
#include <vector>
using namespace std;
int FindKth(vector<int> Array, int startIndex,int endIndex,int k);
int FindKth(vector<int> Array, int startIndex,int endIndex,int k){
    if(k < startIndex + 1 ||k > endIndex + 1)
        return -1;
    if(startIndex == endIndex)
        return Array[endIndex];
    int i = startIndex;
    int j = endIndex;
    int pivot = Array[startIndex];
    while (i < j){
        while(i < j && Array[j] >= pivot)
            j--;
        while(i < j && Array[i] <= pivot)
            i++;
        if(i < j){
            swap(Array[i], Array[j]);
        }
    }
    swap(Array[i], Array[startIndex]);
    if(i == k - 1){
        return Array[k - 1];
    }
    else if(i > k - 1){
        return FindKth(Array, startIndex, i - 1, k);
    }
    else{
        return FindKth(Array, i + 1, endIndex, k);
    }
    
}

int main(){
    cout << "请输入数组的规模：";
    int n;
    while(cin >> n){
        vector<int> my_vec(n);
        int k;
        cout << "请输入数组： ";
        for(int i = 0;i < n; i++){
            cin >> my_vec[i];
        }
        cout << "请输入k： ";
        cin >> k;

        int ans = FindKth(my_vec,0,my_vec.size() - 1, k);
        cout << "第k小的元素是： " << ans << endl;
        my_vec.clear();
        cout << "请输入数组的规模：";
    }
    system("pause");
    return 0;
}

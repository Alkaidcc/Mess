/*
Filename		:alg_2.cpp
Date			:2020/09/29 19:19:19
Author			:ZZC
Description     :���ڸ�����һ����n(n>2)�����������飬�����
                ��ʵ��һ���㷨���ж������Ƿ���ڳ��ִ�������
                ����Ԫ��һ���Ԫ�أ��������ӡ�����Ԫ��
*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int find_Num(vector<int>& my_vec){
    map<int,int> my_map;
    for(size_t i = 0;i < my_vec.size();i++){
        my_map[my_vec.at(i)] += 1;
    }
    map<int, int>::iterator it;
    for(it = my_map.begin();it != my_map.end();it++){
        if(unsigned(it->second) > (my_vec.size() / 2))
            return it->first;
    }
    return 0;

}

int main(){
    cout << "Please enter the array size: ";
    int n;
    cin >> n;
    cout << "Please enter 10 integers to fill in the array: " << endl;
    vector<int> my_vec(n);
    for(int i = 0;i < n;i++){
        cout << "a[" << i << "]: ";
        cin >> my_vec[i];
    }
    cout << endl;
    
    int result = find_Num(my_vec);

    cout << "The array is : ";
    for(int i = 0;i < n;i++){
        cout << my_vec[i] << " ";
    }
    cout << endl;
    if(result == 0){
        cout << "No element's occurrance is greater than " << my_vec.size() / 2 << endl;
    }else{
        cout <<"Num counts of " << result << " is greater than " << my_vec.size() / 2 << endl;
    }
    system("pause");
    return 0;
}

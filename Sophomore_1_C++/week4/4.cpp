/*
Filename		:4.cpp
Date			:2020/10/16 14:27:45
Author			:ZZC
Description     :������ʵ��һ�����������࣬�ڲ���װһ����������(int a[10])��Ҫ����˳���ӡ�����еĸ���Ԫ�أ�ͳ�Ƹ���Ԫ��֮�͡���ֵ�����ֵ����Сֵ����ֵ,����main()�в��Ը��ࡣ
*/
#include <iostream>
#include <climits>
#include <algorithm>
#include <ctime>
using namespace std;

class Array
{
private:
    int array[10];
    int array_max;
    int array_min;
public:
    void printArray();
    double getAverage();
    int getMiddle();
    int getSum();
    int getMax();
    int getMin();
    Array();
    ~Array();
};

Array::Array()
{   srand(time(NULL));
    for(int i = 0;i < 10; i++){
        array[i] = rand() % 20 + 1;
    }
}

Array::~Array()
{
}

void Array::printArray(){
    for(int i = 0;i < 10;i++){
        cout << array[i] << " ";
    }
    cout << endl;
}
int Array::getSum(){
    int array_sum = 0;
    for(int i = 0;i < 10;i++){
        array_sum += array[i];
    }
    return array_sum;
}
double Array::getAverage(){
    int sum = getSum();
    return sum / 10.0;

}
int Array::getMax(){
    array_max = INT_MIN;
    for(int i = 0;i < 10;i++){
        if(array[i] >= array_max){
            array_max = array[i];
        }
    }
    return array_max;
}
int Array::getMin(){
    array_min = INT_MAX;
    for(int i = 0;i < 10;i++){
        if(array[i] <= array_min){
            array_min = array[i];
        }
    }
    return array_min;
}
int Array::getMiddle(){
    sort(array, array + 10);
    return array[5];
}
int main(){
    Array a;
    a.printArray();
    cout << "The max of the array: " << a.getMax() << endl;
    cout << "The min of the array: " << a.getMin() << endl;
    cout << "The average of the array: " << a.getAverage() << endl;
    cout << "The sum of the array: " << a.getSum() << endl;
    cout << "The middle of the array: " << a.getMiddle() << endl;
    system("pause");
    return 0;
}

#include <iostream>
#include <ctime>
using namespace std;

class Array
{
private:
    double* A;
    int arr_num;            //存储数组的个数
public:
    Array();
    Array(int m);
    ~Array();
    double getAve();        //返回数组平均值
    double getMax();        //返回数组最大值
    double getMin();        //返回数组最小值
    int getMaxIndex();      //返回数组最大值下标
    int getMinIndex();      //返回数组最小值下标

};

Array::Array()
{
}
Array::Array(int m){
    A = new double[m];
    arr_num = m;
    srand(unsigned(time(NULL)));
    for(int i = 0;i < m;i++){
        A[i] = rand() % 20 + 1;
        cout << A[i] << " ";
    }
    cout << endl;
}
Array::~Array()
{
    delete[] A;
}
double Array::getAve(){
    double sum = 0;
    for(int i = 0;i < arr_num;i++){
        sum += A[i];
    }
    return sum / arr_num;
}

double Array::getMax(){
    int max = -1e6;
    for(int i = 0;i < arr_num;i++){
        if(A[i] > max){
            max = A[i];
        }
    }
    return max;
}

double Array::getMin(){
    int min = 1e6;
    for(int i = 0;i < arr_num;i++){
        if(A[i] < min){
            min = A[i];
        }
    }
    return min;
}

int Array::getMaxIndex(){
    int index = 0;
    for(int i = 1;i < arr_num;i++){
        if(A[i] > A[index]){
            index = i;
        }
    }
    return index;
}

int Array::getMinIndex(){
    int index = 0;
    for(int i = 1;i < arr_num;i++){
        if(A[i] < A[index]){
            index = i;
        }
    }
    return index;
}

int main(){
    Array a(5);
    cout << "数组的均值为: " << a.getAve() << endl;
    cout << "数组的最大值为: " << a.getMax() << endl;
    cout << "数组的最小值为: " << a.getMin() << endl;
    cout << "数组的最大值下标为: " << a.getMaxIndex() << endl;
    cout << "数组的最小值下标为:" << a.getMinIndex() << endl;
    system("pause");
    return 0;
}

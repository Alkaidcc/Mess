/*
Filename		:2.cpp
Date			:2020/10/09 08:31:27
Author			:ZZC
Description     :��дһ���������õݹ�ķ�ʽ��x��y�η���
*/
#include <iostream>
using namespace std;
double my_pow(double x,double y);
double my_pow(double x,double y){
    if( y >= 0){
        if(y == 0){
            return 1;
        }
        if(y == 1){
            return x;
        }
        return x * my_pow(x, y - 1);
    }else{
        double abs = -y;
        return 1.0 / my_pow(x,abs);
    }
    
}

int main(){
    double x,y;
    cin >> x >> y;
    double result = my_pow(x,y);
    cout << result << endl;
    system("pause");
    return 0;
}

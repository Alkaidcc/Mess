#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

const int colum = 5;
class Array
{
private:
    int col;
    int row;
    double (*A)[colum];
public:
    Array();
    Array(const int& r);
    ~Array();
    void getAve();
};

Array::Array()
{
}
Array::Array(const int& r){
    row = r;
    col = colum;
    A = new double[row][colum];
    srand(unsigned(time(NULL)));
    for(int i = 0;i < row;i++){
        for(int j = 0;j < col;j++){
            A[i][j] = rand() % 20 + 1;
            cout << setw(4) << A[i][j] << setw(4);
        }
        cout << endl;
    }
}

Array::~Array()
{
    delete[] A;
}

void Array::getAve(){
    double sum = 0;
    for(int i = 0;i < row;i++){
        for(int j = 0; j < col;j++){
            sum += A[i][j];
        }
    }
    cout << "数组的平均值为: " << sum / (row * col) << endl;
}

int main(){
    Array a(3);
    a.getAve();
    system("pause");
    return 0;
}

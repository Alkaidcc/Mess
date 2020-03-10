#include<iostream>
#include<fstream>
using namespace std;
int main(){
    char automobile[50];
    int year;
    double a_price;
    double d_price;

    ofstream outFile;   //1.创建一个fstream对象
    outFile.open("carinfo.txt");//2.和文件关联起来
    //3.像使用cout那样使用它
    cout << "Enter the make and model of automobile: ";
    cin.getline(automobile,50);
    cout << "Enter the model year: ";
    cin >> year;
    cout << "Enter ther original asking price: ";
    cin >> a_price;
    d_price = 0.913 * a_price;


    cout << fixed;
    cout.precision(2);
    cout.setf(ios_base::showpoint);
    cout << "Make and model: " << automobile << endl;
    cout << "Year: " << year << endl;
    cout << "Was asking $" << a_price << endl;
    cout << "Now asking $" << d_price << endl;

    outFile << fixed;//它表示浮点输出应该以固定点或小数点表示法显示
    outFile.precision(2);//浮点数的精度 控制浮点数的位数
    outFile.setf(ios_base::showpoint);//强制显示小数点
    //fixed 和precision一起用可以控制小数点后面几位
    outFile << "Make and model: " << automobile << endl;
    outFile << "Year: " << year << endl;
    outFile << "Was asking $" << a_price << endl;
    outFile << "Now asking $" << d_price << endl;

    outFile.close();    //记得关闭
    system("pause");
    return 0;





}
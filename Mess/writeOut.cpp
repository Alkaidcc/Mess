#include<iostream>
#include<fstream>
using namespace std;
int main(){
    char automobile[50];
    int year;
    double a_price;
    double d_price;

    ofstream outFile;   //1.����һ��fstream����
    outFile.open("carinfo.txt");//2.���ļ���������
    //3.��ʹ��cout����ʹ����
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

    outFile << fixed;//����ʾ�������Ӧ���Թ̶����С�����ʾ����ʾ
    outFile.precision(2);//�������ľ��� ���Ƹ�������λ��
    outFile.setf(ios_base::showpoint);//ǿ����ʾС����
    //fixed ��precisionһ���ÿ��Կ���С������漸λ
    outFile << "Make and model: " << automobile << endl;
    outFile << "Year: " << year << endl;
    outFile << "Was asking $" << a_price << endl;
    outFile << "Now asking $" << d_price << endl;

    outFile.close();    //�ǵùر�
    system("pause");
    return 0;





}
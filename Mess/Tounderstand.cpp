#include<iostream>
#include<vector>
using namespace std;
const int Max = 5;
int main(){
    double fish[Max];
    int i = 0;
    for(i = 0;i < Max;i++){
        cout << "fish #" << i+1 <<": ";
        while(!(cin >> fish[i])){
            cin.clear();
            while(cin.get()!='\n')
                continue;
            cout << "Please enter a number: ";
        }
    }
    double total = 0.0;
    for(int j = 0;j < Max;j++)
        total += fish[j];
    cout << total / Max << " = average weight of " << i << " fish\n";
    system("pause");
    return 0;

}
#include <iostream>
using namespace std;

int main(){
    string target = "aababcde";
    string pattern = "abcd";
    cout << target.find(pattern) << endl;
    system("pause");
    return 0;
}

#include<iostream>
using namespace std;

int main() {
    int T,M;
    while(cin >> M >> T) {
        int tim = (M/5) * 14;
        if(M%5 >= 3)
            tim = tim + 8;
        if(M >= 3) {
            if(tim >= T) {
                cout << "mjjtcl" << endl;
            }else {
                cout << "mjjtql" << endl;
            }
        }else {
            cout << "mjjtql" << endl;
        }
    }
    system("pause");
    return 0;
}
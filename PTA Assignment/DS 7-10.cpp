#include<iostream>
#include<set>
using namespace std;
int main(){
    int n,tmp;
    set <int> s;
    scanf("%d%d",&n,&tmp);
    s.insert(tmp);
    for(int i = 1;i < n;i++){
        scanf("%d",&tmp);
        if(tmp < *s.rbegin())
            s.erase(s.upper_bound(tmp));
        s.insert(tmp);
    }
    cout << s.size() << endl; 
    system("pause");  
    return 0;
}

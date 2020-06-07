#include <bits/stdc++.h>
using namespace std;
int getnum(int n, int m, int x, int y) {
	int lev = min(min(x, n - 1 - x), min(y, m - 1 - y));
	int D = x + y - lev * 2;
	int St = 2 * lev * (n + m - 2 * lev) + 1;
	if(x == lev || y == m - 1 - lev || (m < n && lev * 2 + 1 == m))
		return St + D;
	int nt = St + (n + m - 4 * lev - 2) * 2;
	return nt - D;
}
int main() {
	int n, m;
	while(cin >> n >> m){ 
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(j!= m-1)
                    cout << getnum(n, m, i, j) << " ";
                else
                    cout << getnum(n, m, i, j);
            }
            cout << endl;
        }
    }
}

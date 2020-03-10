#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int a[200001];
 
int main(){
	int N;
	scanf("%d", &N);
	for(int i = 0; i < 2 * N; ++i)
		scanf("%d", &a[i]);
	sort(a, a + 2 * N);
    cout << a[N-1] << endl;
    system("pause");
	return 0;
}

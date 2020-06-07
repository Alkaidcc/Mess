#include <iostream>
using namespace std;
int arr[5], price[3], ans; 
int main()
{
    while(cin >> arr[1] >> arr[2] >> arr[3] >> arr[4] >> price[1] >> price[2]) {
        if(price[1] > price[2]) 
        {
            while(arr[1] && arr[4]) {
                arr[1]--;
                arr[4]--;
                ans += price[1];
            } 	
            while(arr[2] && arr[3] && arr[4]) {
                arr[2]--;
                arr[3]--;
                arr[4]--;
                ans += price[2];
            } 
        }
        else
        {
            while(arr[2] && arr[3] && arr[4]) {
                arr[2]--;
                arr[3]--;
                arr[4]--;
                ans += price[2];
            }
            while(arr[1] && arr[4]) {
                arr[1]--;
                arr[4]--;
                ans += price[1];
            }
        }
	    printf("%d\n", ans);
        ans = 0;
    }
    system("pause");
}

#include <iostream>
using namespace std;
char a[100001];
int main(){
	char c;
	int count_y = 0;
	int count_d = 0;
	int count_s = 0;
	while(scanf("%c",&c)){
		if(c == '\n')
			break;
		if(c == 'y'){
			count_y++;
		}
		if(c == 'd'){
			count_d++;
		}
		if(c == 's'){
			count_s++;
		}
	}
	while(count_y && count_d && count_s){
		cout << "y";
		count_y--;
		if(count_y){
			cout << "y";
			cout << "d";
			cout << "s";
			count_y--;
			count_d--;
			count_s--;
		}
	}
	if(count_y == 0){
		while(count_d && count_s){
			cout << "ds";
			count_d--;
			count_s--;
		}
		if(count_d == 0){
			while(count_s){
				cout << "s";
				count_s--;
			}
		}
		while(count_d){
			cout << "d";
			count_d--;
		}
	}
	if(count_d == 0){
		if(count_s){
			while(count_y && count_s){
				cout << "y";
				count_y--;
				if(count_y){
					cout << "y";
					cout << "s";
					count_y--;
					count_s--;
				}
			}
			if(count_s == 0){
				while(count_y){
					cout << "y";
					count_y--;
				}
			}
			while(count_s){
				cout << "s";
				count_s--;
			}
		}
	}
	if(count_s == 0){
		if(count_d){
			while(count_y && count_d){
				cout << "y";
				count_y--;
				if(count_y){
					cout << "y";
					cout << "d";
					count_y--;
					count_d--;
				}
			}
			if(count_d == 0){
				while(count_y){
					cout << "y";
					count_y--;
				}
			}
			while(count_d){
				cout << "d";
				count_d--;
			}
		}
	}
	system("pause");
	return 0;
}

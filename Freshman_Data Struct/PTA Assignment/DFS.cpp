#include<stdio.h>
int cnt = 0;
int n, a[50];
void dfs(int number, int n, int location, int sum) {//��һ������Ϊ��ǰ���ӵĴ�С��
	if (sum == n) {
		printf("%d=", n);
		for (int i = 0; i < location; ++i)
			if (i == 0)
				printf("%d", a[i]);					//�жϵڼ���
			else
				printf("+%d", a[i]);
		++cnt;
		if (cnt % 4 != 0 && number != n)			//	����
			printf(";");
		if (cnt % 4 == 0 && cnt != 0)
			printf("\n");
	}
	if (sum > n) return;
	for (int i = number; i <= n; ++i) {
		a[location] = i;
		dfs(i, n, location + 1, sum + i);
	}
}
int main()
{
	scanf("%d", &n);
	dfs(1, n, 0, 0);
}
/*
����������
����N��P��PΪ����������N! Mod P = ? (Mod ������ģ %)
���磺n = 10�� P = 11��10! = 3628800 ��3628800 % 11 = 10
Input
������N,P���м��ÿո������(N < 10000, P < 10^9)
Output
���N! mod P�Ľ����
*/
#include<stdio.h>

int main(void)
{
	int n,p;
	long long tmp = 1;
	scanf("%d %d", &n, &p);
	if (n == 0||n == 1)
	{
		printf("1\n");
		return 0;
	}
	else
	{
		for (int i = 2; i <= n; i++)
		{
			tmp = tmp*i%p;
		}
		printf("%lld\n", tmp);
		return 0;
	}
}
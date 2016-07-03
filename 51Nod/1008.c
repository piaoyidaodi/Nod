/*
问题描述：
输入N和P（P为质数），求N! Mod P = ? (Mod 就是求模 %)
例如：n = 10， P = 11，10! = 3628800 ；3628800 % 11 = 10
Input
两个数N,P，中间用空格隔开。(N < 10000, P < 10^9)
Output
输出N! mod P的结果。
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
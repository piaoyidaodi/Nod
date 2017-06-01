#include<stdio.h>

#define N 10000
#define Base 100000000

long long sum[N] = { 0 };

int factorial(int n)
{
	int i, j, t;
	long long flag;
	t = 0;
	for (i = 1; i <= n; i++)
	{
		flag = 0;
		for (j = 0; j <= t; j++)
		{
			sum[j] = sum[j] * i + flag;
			flag = sum[j] / Base;
			sum[j] %= Base;
		}
		if (flag > 0)
		{
			sum[++t] = flag;
		}
	}
	return t;
}

int main(void)
{
	int n, i, flag, t;
	scanf("%d", &n);
	sum[0] = 1;
	t = factorial(n);

	printf("%lld", sum[t]);
	for (i = t - 1; i >= 0; i--)
	{
			printf("%0.8lld", sum[i]);
	}
	printf("\n");
}
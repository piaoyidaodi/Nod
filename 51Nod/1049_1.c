#include<stdio.h>

#define N 50000








int a[N];

int main(void)
{
	int i, n;
	long long sum, max;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	sum = 0;
	max = 0;
	for (i = 0; i < n; i++)
	{
		if (sum < 0)
			sum = 0;
		sum = sum + a[i];
		max = max > sum ? max : sum;
	}

	printf("%lld\n", max);



	return 0;
}
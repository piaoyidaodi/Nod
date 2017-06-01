#include<stdio.h>

int main(void)
{
	int t, n, k;
	scanf("%d", &t);
	while (t > 0)
	{
		scanf("%d %d", &n, &k);
		if (n % (k + 1) == 0)
		{
			printf("B\n");
		}
		else
		{
			printf("A\n");
		}
	}
	return 0;
}
#include <stdio.h>

int getGCD(int a, int b);

int main(void)
{
	int a, b, gcd;
	long long lcm;
	scanf("%d %d", &a, &b);
	gcd = getGCD(a, b);
	lcm = (long long)a*b/gcd;
	printf("%lld\n", lcm);
	return 0;
}

int getGCD(int a, int b)
{
	int tmp;
	if (a < b)
	{
		tmp = a;
		a = b;
		b = tmp;
	}
	while (b != 0)
	{
		tmp = b;
		b = a%b;
		a = tmp;
	}
	return tmp;
}
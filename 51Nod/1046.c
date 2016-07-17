#include<stdio.h>

int main(void)
{
	int a, b, c, tot, base;
	scanf("%d %d %d", &a, &b, &c);
	tot = 1;
	base = a%c;
	/*for (i = 1;i <= b;i++)
	{
		tot *= a;
		if ((tot / c) != 0)
		{
			tot %= c;
		}
		mod = tot%c;
	}*/
	while (b > 0)
	{
		if (b%2 == 1)
			tot = (tot*base) % c;
		base = (base*base) % c;
		b /= 2;
	}
	printf("%d\n", tot);
}
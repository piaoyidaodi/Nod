#include <stdio.h>

int main()
{
	unsigned int a, b, c, tmp;
	scanf("%u %u", &a, &b);
	if (a == b)
	{
		printf("%u\n", a);
	}
	else
	{
		if (a < b)
			{
				tmp = a;
				a = b;
				b = tmp;
				
			}
		c = a - b;
		while (c != 0)
		{
			if (c >= b)
			{
				a = c;
				c = a - b;
			}
			else
			{
				a = b;
				b = c;
				c = a - b;
			}
		}
		printf("%u\n", a);
	}
	return 0;
}
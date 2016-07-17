#include<stdio.h>
#include<string.h>

#define N 1001


void cha2int(char *tmps, int *tmpi, int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		tmpi[len - i - 1] = (int)(tmps[i] - '0');
	}
}

void int2cha(int *tmpi, char *tmps, int len)
{
	int i;
	for (i = 0; i < len; i++)
		tmps[i] = (char)(tmpi[i] + (int)('0'));
}


int main(void)
{
	char a_t[N], b_t[N], c_t[N], *p;
	int a[N] = { 0 }, b[N] = { 0 }, c[2002] = { 0 }, lena, lenb, lenc, i, j;
	scanf("%s%s", a_t, b_t);
	//printf("%s %s", a, b);
	lena = strlen(a_t);
	lenb = strlen(b_t);
	lenc = lena + lenb;
	cha2int(a_t, a, lena);
	cha2int(b_t, b, lenb);
	for (i = 0; i < lenb; i++)
	{
		for (j = 0; j < lena; j++)
		{
			c[i + j] += b[i] * a[j];
		}
	}
	for (i = 0; i < lenc; i++)
	{
		c[i + 1] += c[i] / 10;
		c[i] = c[i] % 10;
	}
	int2cha(c, c_t, lenc);
	c_t[lenc] = '\0';
	i = lenc - 1;
	p = c_t + i;
	while (i > 0)
	{
		if (*p == '0')
		{
			p--;
			i--;
			continue;
		}
		else
			break;
	}
	while (p != c_t)
	{
		printf("%c", *p);
		p--;
	}
	printf("%c\n", *p);
}
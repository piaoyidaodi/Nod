#include <stdio.h>
#include <string.h>
#include <memory.h>

#define N 1005

char a[N], b[N], r[2005], rt[2005];

int cha2int(char c)
{
	return (int)(c - '0');
}

char int2cha(int i)
{
	return (char)(i + (int)('0'));
}

void add(char *r, char *rt, int j)
{
	int k, tmpr, tmprt, tmp, flag;
	flag = 0;
	tmp = 0;
	for (k = 0; k < 2005; k++)
	{
		tmpr = cha2int(r[k]);
		tmprt = cha2int(rt[k]);
		tmp = tmpr + tmprt + flag;
		flag = tmp / 10;
		tmp = tmp % 10;
		r[k] = int2cha(tmp);
	}
}

void multipli(char *a, char *b, char *r,char *rt, int len_a, int len_b)
{
	int i, j, tmpa, tmpb, tmp,flag,k,kl;
	k = 0;
	for (j = len_b - 1; j >= 0; j--)
	{
		flag = 0;
		tmp = 0;
		kl=k++;
		tmpb = cha2int(b[j]);
		for (i = len_a - 1; i >= 0; i--)
		{
			tmpa = cha2int(a[i]);
			tmp = tmpa*tmpb + flag;
			flag = tmp / 10;
			tmp = tmp % 10;
			rt[kl++] = int2cha(tmp);
		}
		if (flag != 0)
		{
			rt[kl++] = int2cha(flag);
		}
		add(r, rt, j);
		memset(rt, '0', sizeof(char) * 2005);
	}
}

int main(void)
{
	char *p;
	int len_a, len_b, len_r, i;
	scanf("%s", a);
	scanf("%s", b);
	len_a = strlen(a);
	len_b = strlen(b);
	memset(r, '0', sizeof(char) * 2005);
	memset(rt, '0', sizeof(char) * 2005);
	//printf("%s", r);
	p = r;
	multipli(a, b, r, rt, len_a, len_b);
	p = p + 2004;
	while (*p == '0')
		p--;
	p++;
	*p = '\0';
	len_r = strlen(r);
	for (i = len_r - 1; i >= 0; i--)
		printf("%c", r[i]);
	printf("\n");
}
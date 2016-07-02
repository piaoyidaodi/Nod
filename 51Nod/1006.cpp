#include <stdio.h>
#include <string.h>

#define N 1005

char str1[N], str2[N];
int a[N][N], b[N][N],count=0;//大数组定义在main()中，占用堆栈造成溢出；定义为全局变量，使用数据段可比较大。
char lcs[N];

void Lcs(int m, int n);

int main(void)
{
	int len1, len2, i, j;
	scanf("%s", str1);
	scanf("%s", str2);
	/*memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));*/
	len1 = strlen(str1);
	len2 = strlen(str2);

	for ( i = 1; i <= len1; i++)
	{
		for (j = 1; j <= len2; j++)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				a[i][j] = a[i - 1][j - 1] + 1;
				b[i][j] = 1;
			}
			if (str1[i - 1] != str2[j - 1])
			{
				if (a[i-1][j]>a[i][j-1])
				{
					a[i][j] = a[i - 1][j];
					b[i][j] = 2;
				}
				else
				{
					a[i][j] = a[i][j - 1];
					b[i][j] = 3;
				}
			}
		}
	}
	Lcs(len1, len2);
	lcs[count] = '\0';
	if (count == 0)
		return 0;
	count--;
	while (count!=0)
	{
		printf("%c", lcs[count--]);
	}
	printf("%c\n", lcs[count]);
	return 0;
}

void Lcs(int m,int n)
{
	if (m == 0 || n == 0)
	{
		return;
	}
	if (b[m][n] == 1)
	{
		lcs[count++]=str1[m-1];
		Lcs(m - 1, n - 1);
	}
	else if(b[m][n]==2)
	{
		Lcs(m - 1, n);
	}
	else
	{
		Lcs(m, n - 1);
	}
}

#include<stdio.h>
//√∞≈›≈≈–Ú∑® ‘ ‘
#define N 50000

void sort(int* a, int n);
void swap(int* a, int index, int i);

int a[N];

int main(void)
{
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a, n);
	for (i = 0; i < n - 1; i++)
	{
		printf("%d ", a[i]);
	}
	printf("%d\n", a[n-1]);

}

void sort(int* a,int n)
{
	int i, j, big, small, index_b, index_s;
	for (i = 0; i < n/2; i++)
	{
		big = a[i];
		small = a[i];
		index_b = i;
		index_s = i;
		for (j = i + 1; j < n - i; j++)
		{
			if (a[j] >= big)
			{
				big = a[j];
				index_b = j;
			}
			else if(a[j]<= small)
			{
				small = a[j];
				index_s = j;
			}
		}
		if ((index_b == n - i - 1) && (index_s == i))
			continue;
		if ((index_b == i) && (index_s == n - i - 1))
		{
			swap(a, index_b, n - i - 1);
		}
		else if ((index_b != i) && (index_s == n - i - 1))
		{
			swap(a, index_s, i);
			swap(a, index_b, n - i - 1);
		}
		else
		{
			swap(a, index_b, n - i - 1);
			swap(a, index_s, i);
		}
	}
}

void swap(int* a,int index, int i)
{
	if (index == i)
		return;
	int tmp;
	tmp = a[i];
	a[i] = a[index];
	a[index] = tmp;
}
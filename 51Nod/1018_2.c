#include<stdio.h>
//¿ìËÙÅÅĞò
#define N 50000

int arry[N];

void qSort(int*, int, int);
void swap(int* arry, int i, int j);

int main(void)
{
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arry[i]);
	}
	qSort(arry, 0, n-1);
	for (i = 0; i < n; i++)
	{
		printf("%d\n", arry[i]);
	}
}

void qSort(int* arry, int index_s, int index_f)
{
	int i, j, flag, next;
	if (index_s >= index_f)
	{
		return;
	}
	i = index_s;
	j = index_f;
	flag = arry[i];
	
	while (i < j)
	{
		while ((i < j) && (arry[j] > flag))
		{
			j--;
		}
		swap(arry, i, j);
		while ((i < j) && (arry[i] < flag))
		{
			i++;
		}
		swap(arry, i, j);
	}
	next = i;
	qSort(arry, index_s, next - 1);
	qSort(arry, next + 1, index_f);
}
void swap(int* arry, int i, int j)
{
	int tmp;
	tmp = arry[i];
	arry[i] = arry[j];
	arry[j] = tmp;
}
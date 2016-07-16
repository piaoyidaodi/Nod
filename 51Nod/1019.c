#include <stdio.h>

#define N 50000

void merge(int *arry, int*arry_m, int sta_t, int mid_t, int end_t);
void part(int *arry, int *arry_m, int sta, int end);

int count = 0;

int main(void)
{
	int arry[N], i, n, arry_m[N];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arry[i]);
	}
	part(arry, arry_m, 0, n-1);
	printf("%d\n", count);
	return 0;
}

void part(int *arry, int *arry_m, int sta, int end)
{
	if (sta >= end)
		return;
	int sta_t, mid_t, end_t;
	sta_t = sta;
	end_t = end;
	mid_t = (sta_t + end_t) / 2;
	part(arry, arry_m, sta_t, mid_t);
	part(arry, arry_m, mid_t + 1, end_t);
	merge(arry, arry_m, sta_t, mid_t, end_t);
}

void merge(int *arry, int*arry_m, int sta_t, int mid_t, int end_t)
{
	int i, j, k;
	i = sta_t;
	j = mid_t+1;
	k = i;
	while ((i <= mid_t) && (j <= end_t))
	{
		if (arry[i] <= arry[j])
			arry_m[k++] = arry[i++];
		else
		{
			arry_m[k++] = arry[j++];
			count += mid_t + 1 - i;
		}
	}
	while (i <= mid_t)
		arry_m[k++] = arry[i++];
	while (j <= end_t)
		arry_m[k++] = arry[j++];
	i = sta_t;
	k = i;
	j = mid_t + 1;
	while (i <= mid_t)
		arry[i++] = arry_m[k++];
	while (j <= end_t)
		arry[j++] = arry_m[k++];
	return 0;
}
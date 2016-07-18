#include<stdio.h>

#define N 50000



int a[N];

long long max(int *a, int stt, int end)
{
	int i, mid;
	long long leftmax, rightmax, leftsum, rightsum, sum;
	if (stt == end)
		return a[stt];
	mid = (end + stt) / 2;
	leftmax = max(a, stt, mid);
	rightmax = max(a, mid+1, end);
	sum = 0;
	leftsum = 0;
	for (i = mid; i >= stt; i--)
	{
		sum += a[i];
		if (sum > leftsum)
			leftsum = sum;
	}
	sum = 0;
	rightsum = 0;
	for (i = mid + 1; i <= end; i++)
	{
		sum += a[i];
		if (sum > rightsum)
			rightsum = sum;
	}
	sum = leftsum + rightsum;
	if (sum < leftmax)
		sum = leftmax;
	if (sum < rightmax)
		sum = rightmax;
	return sum;
}




int main(void)
{
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("%lld\n",max(a, 0, n-1));
	return 0;
}
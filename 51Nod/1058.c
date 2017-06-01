#include<stdio.h>
#include<math.h>

#define PI 3.1415926
#define e  2.718281828459

int main(void)
{
	int len, n;
	scanf("%d", &n);
	if (n == 1)
		printf("1\n");
	else
	{
		//斯特林公式n!=sqrt(2*PI*n)*(n/e)^n 
		len = 0.5*log10(2.0*PI*n) + n*log10(n*1.0 / e) + 1;
	}
	printf("%d\n", len);
	return 0;
}
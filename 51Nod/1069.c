#include<stdio.h>

int main(void)
{
    int n, num[1005];
    // Initial n and num[]
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }

    if (f(n,num) == 1)
    {
        printf("A");
    }
    else
        printf("B");
    return 0;
}

int f(int n,int* num)
{
    int s = num[0];
    for (int i = 1; i < n; i++)
    {
        s = s^num[i];

    }
    if (s==0)
    {
        return 0;
    }
    return 1;
}
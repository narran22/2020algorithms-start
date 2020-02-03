//开灯问题
#include <iostream>
#include <stdio.h>
#include <string.h>
#define maxn 1005
int a[maxn];
int main()
{
    int n, k;
    memset(a, 0, sizeof(a)); //初始化数组a
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k; i++)
        for (int j = 1; j <= n; j++)
        {
            if (j % i == 0)
            {
                a[j] = !a[j];
            }
        }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 1)
            printf("%d ", i);
    }
    printf("\n");
    system("pause");
    return 0;
}
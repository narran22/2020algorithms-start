//蛇形填数
#include <iostream>
#include <stdio.h>
#include <string.h>
#define maxn 20
#define maxm 30
int a[maxn][maxm];
int main()
{
    int n, x, y;
    memset(a, 0, sizeof(a));
    scanf("%d", &n);
    x = 0;
    y = n;
    int tot = 1;
    while (tot < n * n + 1)
    {
        while (x + 1 <= n && !a[x + 1][y])
            a[++x][y] = tot++;
        while (y - 1 >= 1 && !a[x][y - 1])
            a[x][--y] = tot++;
        while (x - 1 >= 1 && !a[x - 1][y])
            a[--x][y] = tot++;
        while (y + 1 < n && !a[x][y + 1])
            a[x][++y] = tot++;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}
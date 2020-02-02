#include <iostream>
#include <stdio.h>
#define maxn 100000
int main()
{
    int m, n;
    while (scanf("%d%d", &n, &m) == 2 && n != 0 && m != 0)
    {
        double sum = 0;
        for (int i = n; i <= m; i++)
        {
            if (i > maxn)
            {
                break;
            }
            double t = (double)i * i;
            sum = sum + 1.0 / t;
        }
        printf("%.5f", sum);
    }
    system("pause");
    return 0;
}
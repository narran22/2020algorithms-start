#include <iostream>
#include <stdio.h>
#define maxn 1000000
int a[maxn];
main()
{
    int a[maxn];
    int x, n;
    while (scanf("%d", &x) == 1)
    {
        a[n++] = x;
    }
    for (int i = n - 1; i > 0; i--)
        printf("%d ", a[i]);
    printf("%d\n", a[0]);
    system("pause");
    return 0;
}
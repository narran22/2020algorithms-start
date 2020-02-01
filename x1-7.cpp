#define LOCAL
#include <stdio.h>
#define INF 1000000000
int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    int x;
    int n = 0;
    int MAX = -INF;
    int MIN = INF;
    double s = 0;
    while (scanf("%d", &x) == 1)
    {
        s += x;
        if (x < MIN)
            MIN = x;
        if (x > MAX)
            MAX = x;
        n++;
    }
    printf("%d %d %.3f\n", MIN, MAX, (double)s / n);
    return 0;
}
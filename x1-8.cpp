#include <stdio.h>
#define INF 1000000000
int main()
{
    FILE *fin, *fout;
    fin = fopen("data.in", "rb");
    fout = fopen("data.out", "wb");
    int x;
    int n = 0;
    int MAX = -INF;
    int MIN = INF;
    double s = 0;
    while (fscanf(fin, "%d", &x) == 1)
    {
        s += x;
        if (x < MIN)
            MIN = x;
        if (x > MAX)
            MAX = x;
        n++;
    }
    fprintf(fout, "%d %d %.3f\n", MIN, MAX, (double)s / n);
    fclose(fin);
    fclose(fout);
    return 0;
}
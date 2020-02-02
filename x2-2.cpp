#include <stdio.h>
int main()
{
    FILE *fin, *fout;
    fin = fopen("bing.in", "rb");
    fout = fopen("bing.out", "wb");
    int a, b, c;
    int kase = 0;
    while (fscanf(fin, "%d%d%d\n", &a, &b, &c) == 3)
    {
        int flag = 1;
        kase++;
        for (int i = 10; i < 100; i++)
        {
            if (a == i % 3 && b == i % 5 && c == i % 7)
            {
                flag = 0;
                fprintf(fout, "Case %d: %d\n", kase, i);
            }
        }
        if (flag)
            fprintf(fout, "Case %d: No ansewer\n", kase);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
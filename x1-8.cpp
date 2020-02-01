#include <stdio.h>
#define INF 1000000000
int main()
{
    //文件输入输出
    FILE *fin, *fout;
    fin = fopen("data.in", "rb");
    fout = fopen("data.out", "wb");
    int n = 0;
    int kase = 0;
    while (fscanf(fin, "%d", &n) && n) //当n=0的时候 结束输出
    {
        kase++;
        int MAX = -INF;
        int MIN = INF;
        double s = 0;
        int tmp;
        for (int i = 0; i < n; i++)
        {
            fscanf(fin, "%d", &tmp);
            if (tmp < MIN)
                MIN = tmp;
            if (tmp > MAX)
                MAX = tmp;
            s += tmp;
        }
        fprintf(fout, "Case %d：%d %d %.3f\n", kase, MIN, MAX, (double)s / n);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
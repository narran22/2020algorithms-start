#include <iostream>
#include <stdio.h>
#include <time.h>
main()
{
    //数字a
    for (int i = 1; i < 4; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            if (j == i)
                continue;
            for (int q = 1; q < 10; q++)
            {
                if (q == j || q == i)
                    continue;
                //用一个数组保存1-9的数字
                int num[10];
                for (int i = 1; i < 11; i++)
                {
                    num[i] = 1;
                }
                num[i] = 0; //a--i
                num[q] = 0; //c--q
                num[j] = 0; //b--j
                int abc = i * 100 + j * 10 + q;
                //判断2倍的
                int def = 2 * abc;
                int d = def / 100;
                int e = def / 10 % 10;
                int f = def % 10;
                if (num[d] == 0)
                    continue;
                if (num[e] == 0)
                    continue;
                if (num[f] == 0)
                    continue;
                num[d] = 0;
                num[e] = 0;
                num[f] = 0;
                //判断3倍的
                int ghi = 3 * abc;
                int g = ghi / 100;
                int h = ghi / 10 % 10;
                int ii = ghi % 10;
                if (num[g] == 0)
                    continue;
                if (num[h] == 0)
                    continue;
                if (num[ii] == 0)
                    continue;
                printf("%d %d %d\n", abc, def, ghi);
            }
        }
    }
    printf("%.2f\n", (double)clock() / CLOCKS_PER_SEC);
    // system("pause");
    return 0;
}
#include <iostream>
#include <math.h>
#include <stdio.h>
int main()
{
    int a, b, c;
    int kase = 0;
    while (scanf("%d%d%d", &a, &b, &c) && a != 0 && b != 0 && c != 0)
    {
        double rate;
        rate = (double)a / b;
        //整数部分
        int intger = floor(rate);
        //小数部分
        double decimal = rate - intger;
        //存储小数
        int s[100];
        for (int i = 1; i <= c + 1; i++)
        {
            int m = floor(decimal * 10);
            decimal = decimal * 10 - m;
            s[i] = m;
        }
        //四舍五入
        if (s[c + 1] >= 5)
        {
            if (s[c] <= 8)
            {
                s[c]++;
            }
            else
            { //小数进位
                for (int i = c; i > 1; i--)
                {
                    s[i] = 0;
                    s[i - 1]++;
                    if (s[i - 1] <= 9)
                    {
                        break;
                    }
                    //整数进位
                    if (i == 2 && s[1] == 10)
                    {
                        s[1] = 0;
                        intger++;
                    }
                }
            }
        }
        printf("Case %d: %d.", ++kase, intger);
        for (int i = 1; i <= c; i++)
        {
            printf("%d", s[i]);
        }
    }
    system("pause");
    return 0;
}
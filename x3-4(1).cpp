//竖式问题
#include <cstdlib>
#include <sstream>
#include <stdio.h>
#include <string.h>
#define maxn 20
using namespace std;
char s[maxn], buf[99];
//数字转换成字符串 用函数 sprintf
//判断是否在字符串中 用一个函数就行 strchr
int main()
{
    scanf("%s", s);
    int count = 0;
    for (int i = 100; i < 1000; i++)
    {
        for (int j = 10; j < 100; j++)
        {
            int d = j / 10, e = j % 10, multi_res = i * j;
            int s1 = i * d;
            int s2 = i * e;
            sprintf(buf, "%d%d%d%d%d", i, j, multi_res, s1, s2);
            int ok = 1;
            for (int i = 0; i < strlen(buf); i++)
            {
                if (strchr(s, buf[i]) == NULL)
                    ok = 0;
            }
            if (ok)
            {
                count++;
                printf("<%d>\n", count);
                printf("%5d\nX%4d\n-----\n%5d\n%4d\n-----\n%5d\n", i, j, s1, s2, multi_res);
            }
        }
    }
    printf("\nThe number of solutions = %d\n", count);
    system("pause");
    return 0;
}
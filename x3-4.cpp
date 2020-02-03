//竖式问题
#include <cstdlib>
#include <sstream>
#include <stdio.h>
#include <string.h>
#define maxn 20
using namespace std;
char s[maxn], buf;
string num2str(int num) //数字转换成字符串
{
    stringstream ss;
    ss << num;
    return ss.str();
}
//判断是否在字符串中
int inset(int x)
{
    string numstr;
    numstr = num2str(x);
    int i = 0;
    int s_len = strlen(s);
    while (numstr[i] != '\0')
    {
        int j = 0;
        while (s[j] != '\0')
        {
            if (numstr[i] == s[j])
            {
                break;
            }
            j++;
            if (j == s_len)
                return 0;
        }
        i++;
    }
    return 1;
}
int main()
{
    scanf("%s", s);
    int count = 0;
    for (int i = 100; i < 1000; i++)
    {
        for (int j = 10; j < 100; j++)
        {
            int multi_res = i * j;
            int d = j / 10;
            int e = j % 10;
            int s1 = i * d;
            int s2 = i * e;
            if (inset(multi_res) && inset(i) && inset(j) && inset(s1) && inset(s2))
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
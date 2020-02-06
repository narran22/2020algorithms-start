//数数字 Digit Counting
#include <iostream>
#include <stdio.h>
#include <string.h>
#define maxn 10000000
using namespace std;
char str[maxn]; //将大的内存分布放在main的外面，不然会出现段错误。
int main()
{
    int T;
    scanf("%d", &T);
    int t = T;
    int cmp[T][10];
    memset(cmp, 0, sizeof(cmp));
    while (T--)
    {
        int n;
        scanf("%d", &n);
        memset(str, 0, sizeof(str));
        for (int i = 1; i <= n; i++)
        {
            char tmp[5];
            // itoa(i, tmp, 10);
            snprintf(tmp, sizeof(tmp), "%d", i);
            strcat(str, tmp);
        }
        for (int i = 0; i < strlen(str); i++)
        {
            cmp[T][str[i] - '0']++;
        }
    }
    for (int i = t - 1; i >= 0; i--)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j == 9)
            {
                cout << cmp[i][j];
                break;
            }
            cout << cmp[i][j] << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}
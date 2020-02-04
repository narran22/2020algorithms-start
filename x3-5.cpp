//UVa 1585
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#define maxn 100
char s[maxn];
int main()
{
    int n;
    scanf("%d", &n);
    int score[100];
    memset(score, 0, sizeof(score));
    for (int i = 0; i < n; i++)
    {
        scanf("%s", s);
        score[i] = 0;
        int flag = 0;
        int len = strlen(s);
        for (int j = 0; j < len; j++)
        {
            if (s[j] == 'O')
            {
                flag++;
                score[i] = score[i] + flag;
            }
            else
                flag = 0;
        }
    }
    for (int q = 0; q < n; q++)
    {
        printf("%d\n", score[q]);
    }

    system("pause");
    return 0;
}
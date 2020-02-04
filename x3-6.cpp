//UVa 1586 molar mass
#include <cstdlib>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#define maxn 100
using namespace std;
char molecular[maxn];
double mass[maxn];
double itom_mass(char i)
{
    if (i == 'C')
        return 12.01;
    if (i == 'H')
        return 1.008;
    if (i == 'O')
        return 16.0;
    if (i == 'N')
        return 14.01;
    return 0;
}
int itom_num(int index, int len)
{
    int num = 0;
    int t = 0;
    char buf[10];
    for (int i = index + 1; i < len; i++)
    {
        if (isdigit(molecular[i]))
            buf[t++] = molecular[i];
        if (isalpha(molecular[i]))
            break;
    }
    for (int j = t - 1; j >= 0; j--)
    {
        int a = pow(10.0, j);
        int b = buf[t - j - 1] - 48;
        num += a * b;
    }
    return num;
}

int main()
{
    int n;
    scanf("%d", &n);
    memset(mass, 0, sizeof(mass));
    for (int i = 0; i < n; i++)
    {
        scanf("%s", molecular);
        int len = strlen(molecular);
        int flag = 1;
        for (int j = 0; j < len; j++)
        {
            if (isalpha(molecular[j]) && isdigit(molecular[j + 1]))
                mass[i] += itom_mass(molecular[j]) * itom_num(j, len);
            if (isalpha(molecular[j]) && isalpha(molecular[j + 1]))
                mass[i] += itom_mass(molecular[j]);
            if (isalpha(molecular[j]) && molecular[j + 1] == '\0')
                mass[i] += itom_mass(molecular[j]);
            if (isdigit(molecular[j]))
                continue;
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%.3f\n", mass[i]);
    }
    system("pause");
    return 0;
}
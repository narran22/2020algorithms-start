//UVA-202  循环小数
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <string.h>
#define maxn 100000 + 5
using namespace std;
int diver[maxn], rem[maxn]; //存储商 余数
void prt(int stat, int ed)
{
    if (ed - stat < 50)
    {
        cout << "(";
        for (int i = stat; i < ed; i++)
        {
            cout << diver[i];
        }
        cout << ")";
    }
    else
    {
        cout << "(";
        for (int i = stat; i < stat + 50; i++)
        {
            cout << diver[i];
        }
        cout << "...)";
    }
}
void prtl2(int t)
{
    cout << endl;
    cout << "   " << t << " = number of digits in repeating cycle" << endl<<endl;
}
int main()
{
    int a, b, c;
    while (scanf("%d%d", &a, &b) == 2)
    {
        memset(rem, -1, sizeof(rem));
        int cnt = 0;
        cout << a << "/" << b << " = ";
        cout << a / b << ".";
        c = a % b; //整数差
        c *= 10;
        while (rem[c] == -1)
        {
            rem[c] = cnt;
            diver[cnt++] = c / b; //商
            c %= b;               //差
            c *= 10;              //差进10
        }
        //找到起始位置
        int start_pos = rem[c];
        for (int i = 0; i < start_pos; i++)
        {
            cout << diver[i];
        }
        prt(start_pos, cnt);
        prtl2(cnt - start_pos);
    }
    return 0;
}

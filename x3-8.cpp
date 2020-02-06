#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char grid[5][6][6];

struct pos
{
    int x = 0;
    int y = 0;
};
pos p[5];
void swap(char *a, char *b)
{
    char *t;
    t = a;
    a = b;
    b = a;
}
bool changeposition(int cnt, char a)
{
    int x = p[cnt].x;
    int y = p[cnt].y;
    if (a == 'A')
    {
        int t = x - 1;
        if (t > 0 && t < 6)
        {
            swap(grid[cnt][x][y], grid[cnt][t][y]);
            p[cnt].x = t;
            return true;
        }
        else
            return false;
    }
    if (a == 'B')
    {
        int t = x + 1;
        if (t > 0 && t < 6)
        {
            swap(grid[cnt][x][y], grid[cnt][t][y]);
            p[cnt].x = t;
            return true;
        }
        else
            return false;
    }
    if (a == 'L')
    {
        int t = y - 1;
        if (t > 0 && t < 6)
        {
            swap(grid[cnt][x][y], grid[cnt][x][t]);
            p[cnt].y = t;
            return true;
        }
        else
            return false;
    }

    if (a == 'R')
    {
        int t = y + 1;
        if (t > 0 && t < 6)
        {
            swap(grid[cnt][x][y], grid[cnt][x][t]);
            p[cnt].y = t;
            return true;
        }
        else
            return false;
    }
}
int main()
{
    int wro[10];
    memset(wro, 0, sizeof(wro));
    char t;
    int cnt = 0;
    while ((t = getchar()) != 'Z')
    {
        cnt++;
        grid[cnt][1][1] = t;
        int flag = 1; //空格标记
        //空格在第一个的情况
        if (t == ' ')
        {
            p[cnt].x = 1;
            p[cnt].y = 1;
            flag = 0;
        }
        //读取puzzle
        for (int i = 1; i < 6; i++)
        {
            for (int j = 1; j < 6; j++)
            {
                if (i == 1 && j == 1)
                    continue;
                char TMP = getchar();
                if (TMP == '\n')
                {
                    if (j == 5)
                    {
                        p[cnt].x = i;
                        p[cnt].y = j;
                        flag = 0;
                        grid[cnt][i][j] = ' ';
                        continue;
                    }
                    else
                    {
                        j--;
                        continue;
                    }
                }
                grid[cnt][i][j] = TMP;
                //读取空格所在位置
                if (flag && grid[cnt][i][j] == ' ')
                {
                    p[cnt].x = i;
                    p[cnt].y = j;
                    flag = 0;
                }
            }
        }
        //读取移动方向序列
        char order;
        order = getchar();
        while (order != '0' && order != 'Z')
        {
            order = getchar();
            if (order != '\n' && order != '0')
            {
                if (!changeposition(cnt, order)) //不能交换位置
                    wro[cnt] = 1;
                // else
                //     changeposition(cnt, order);
            }
        }
        char end = getchar();
    }
    grid[++cnt][1][1] = 'Z'; //中止

    for (int i = 1; i <= cnt; i++)
    {
        if (grid[i][1][1] == 'Z')
        {
            break;
        }

        if (wro[i])
        {
            cout << "Puzzle #" << i << ":" << endl;
            cout << "This puzzle has no final configuration." << endl;
            continue;
        }
        cout << "Puzzle #" << i << ":" << endl;
        for (int j = 1; j < 6; j++)
        {
            for (int k = 1; k < 6; k++)
            {
                if (k == 5)
                {
                    cout << grid[i][j][k];
                }
                else
                    cout << grid[i][j][k] << " ";
            }
            if (j != 5)
                cout << endl;
        }
        cout << endl
             << endl;
    }
    system("pause");
}
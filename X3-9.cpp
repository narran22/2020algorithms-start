//纵横字谜的答案 UVA-232
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

char Crosswords[11][11];
int Across[11][11];
int main()
{
    int kase = 1;
    for (;;)
    {
        int r, c;
        cin >> r;
        if (r == 0)
            break;
        if (kase - 1)
        {
            cout << endl;
        }

        int cnt = 1;
        cin >> c;
        getchar();                          //吞掉最后的换行符
        fgets(Crosswords[0], c + 2, stdin); //读取第一行
        memset(Across, 0, sizeof(Across));
        //读取字符并且每一行编号
        for (int i = 0; i < c; i++) //第一行全部编号
        {
            if (Crosswords[0][i] != '*')
                Across[0][i] = cnt++;
        }
        for (int i = 1; i < r; i++) //第二行之后
        {
            fgets(Crosswords[i], c + 2, stdin); //读取一行，包括换行符和终止符
            if (Crosswords[i][0] != '*')        //第一列全部编号
                Across[i][0] = cnt++;
            for (int j = 1; j < c; j++) //找eligible白格
            {
                if (Crosswords[i][j] != '*')
                {
                    if (Crosswords[i - 1][j] == '*' || Crosswords[i][j - 1] == '*')
                        Across[i][j] = cnt++;
                }
            }
        }
        cout << "puzzle #" << kase++ << ":" << endl;
        int flag = 1;
        cout << "Across" << endl;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (Across[i][j] && flag)
                { //标0表示黑格
                    flag = 0;
                    cout << setw(3) << Across[i][j] << "."; //输出编号
                    int k;
                    for (k = j; k < c; k++) //输出字谜
                    {
                        if (Crosswords[i][k] != '*')
                            cout << Crosswords[i][k];
                        else
                            break;
                    }
                    j = k;
                    cout << endl;
                    flag = 1;
                }
            }
        }
        cout << "Down" << endl;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (Across[i][j] && flag)
                { //标0表示黑格
                    flag = 0;
                    cout << setw(3) << Across[i][j] << "."; //输出编号
                    int k;
                    for (k = i; k < r; k++) //输出字谜
                    {
                        if (Crosswords[k][j] != '*')
                        {
                            cout << Crosswords[k][j];
                            Across[k][j] = 0;
                        }
                        else
                            break;
                    }
                    // j = k;
                    cout << endl;
                    flag = 1;
                }
            }
        }
    }

    system("pause");
    return 0;
}

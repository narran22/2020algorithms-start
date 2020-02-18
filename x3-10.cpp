//NDA序列 UVA-1368
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

// char DNA[50][1000];
int main()
{
    int T;
    cin >> T;
    for (int kase = 0; kase < T; T++)
    {
        int m, n;
        cin >> m >> n;
        int nucleotides[4][n];
        char gene[n];
        int sum = 0;
        memset(nucleotides, 0, sizeof(nucleotides));
        for (int i = 0; i < m; i++) //读入数据  A T G C
        {
            getchar();
            for (int j = 0; j < n; j++)
            {
                char c = getchar();
                if (c == 'A')
                    nucleotides[0][j]++;
                if (c == 'T')
                    nucleotides[1][j]++;
                if (c == 'G')
                    nucleotides[2][j]++;
                if (c == 'C')
                    nucleotides[3][j]++;
            }
        }
        for (int k = 0; k < n; k++)
        {
            int t = 0;
            for (int p = 0; p < 4; p++)
            {
                if (t < nucleotides[p][k])
                {
                    t = nucleotides[p][k];
                    switch (p)
                    {
                    case 0:
                        gene[k] = 'A';
                        break;
                    case 1:
                        gene[k] = 'T';
                        break;
                    case 2:
                        gene[k] = 'G';
                        break;
                    case 3:
                        gene[k] = 'C';
                        break;
                    }
                }
            }
            sum += t;
        }
        for (int q = 0; q < n; q++)
        {
            cout << gene[q];
        }
        cout << endl
             << m * n - sum << endl;
    }
    system("pause");
    return 0;
}

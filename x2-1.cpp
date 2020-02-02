#include <iostream>
#include <stdio.h>
#include <time.h>
int main()
{
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            for (int q = 0; q <= 9; q++)
            {
                int abc = i * 100 + j * 10 + q;
                int sum = i * i * i + j * j * j + q * q * q;
                if (sum == abc)
                    printf("%d\n", abc);
            }
        }
    }
    printf("%.2f\n", (double)clock() / CLOCKS_PER_SEC);
    system("pause");
    return 0;
}
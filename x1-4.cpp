#include <iostream>
int main()
{
    bool a, b, c;
    for (int i = 0; i < 2; i++)
    {
        a = i;
        for (int j = 0; j < 2; j++)
        {
            b = j;
            for (int q = 0; q < 2; q++)
            {
                c = j;
                printf("a = %d   b = %d   c = %d   时,a&&b||c 为：%d  (a&&b)||c 为：%d  a&&(b||c) 为：%d  \n", i, j, q, a && b || c, (a && b) || c, a && (b || c));
            }
        }
    }
    system("pause");
    return 0;
}
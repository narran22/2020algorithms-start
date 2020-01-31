#include <iostream>
int main()
{
    for (int i = 0;; i++)
    {
        int n = i * i;
        if (n < 999)
            continue;
        if (n > 10000)
            break;
        int a1 = n / 1000;
        int a2 = n / 100 % 10;
        int b1 = n % 100 / 10;
        int b2 = n % 10;
        if (a1 == a2 && b1 == b2)
            printf("%d\n", n);
    }
    system("pause");
    return 0;
}
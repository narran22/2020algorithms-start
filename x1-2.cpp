#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    printf("%.70f\n", 1.0 / 3.0);
    string str = "333333333333333314829616256247390992939472198486328125";
    int len = str.length();
    int num = 0;
    for (int i = 0; i < len; i++)
    {
        if (str[i] == '3')
        {
            num++;
        }
        else
        {
            break;
        }
    }
    printf("最后一共有数字：%d位\n精确到小数点后面：%d位\n", len, num);
    system("pause");
    return 0;
}
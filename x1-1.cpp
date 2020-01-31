#include <cstdlib>
#include <math.h>
#include <sstream>
#include <stdio.h>
#include <string>
using namespace std;
const double pi = 2 * acos(0.0);
string num2str(double num) //数字转换成字符串
{
    stringstream ss;
    ss.precision(100);
    ss << pi;
    return ss.str();
}
int main()
{
    string res = num2str(pi);
    printf("%s\n", res.c_str());
    int num = res.length() - 2;
    printf("%d\n", num); //浮点数精确到小数点后多少位
    system("pause");
    return 0;
}

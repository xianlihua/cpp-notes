/**
 * 描述
 * 判断某年是否是闰年。
 *
 * 输入
 * 输入只有一行，包含一个整数a(0 < a < 3000)
 *
 * 输出
 * 一行，如果公元a年是闰年输出Y，否则输出N
 *
 * 样例输入
 * 2006
 *
 * 样例输出
 * N
 *
 * 提示
 * 公历纪年法中，能被4整除的大多是闰年，但能被100整除而不能被400整除的年份不是闰年， 能被3200整除的也不是闰年，如1900年是平年，2000年是闰年，3200年不是闰年。
 */
#include <iostream>
using namespace std;
char isyun (int);

int main () {
    int year = 0;
    cin >> year;
    cout << isyun(year) << endl;
    return 0;
}

char isyun (int year) {
    if (year % 100 == 0 && year % 400 != 0 || year % 3200 == 0) {
        return 'N';
    }
    if (year % 4 == 0) {
        return 'Y';
    }
    return 'N';
}
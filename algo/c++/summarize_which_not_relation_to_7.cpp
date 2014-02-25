/**
 * 题目描述：
 *
 *     一个正整数,如果它能被7整除,或者它的十进制表示法中某个位数上的数字为7,
 *     则称其为与7相关的数.现求所有小于等于n(n<100)的与7无关的正整数的平方和。
 *
 * 输入：
 *
 *     案例可能有多组。对于每个测试案例输入为一行,正整数n,(n<100)
 *
 * 输出：
 *
 *     对于每个测试案例输出一行，输出小于等于n的与7无关的正整数的平方和。
 *
 * 样例输入：
 *
 *     21
 *
 * 样例输出：
 *
 *     2336
 */
#include <iostream>
using namespace std;
bool is7 (int);

int main () {
    int n = 0;
    int sum = 0;
    cin >> n;
    for (int i = 1; i < n; i++) {
        if (is7(i)) {
            continue;
        }
        sum += i * i;
    }
    cout << sum << endl;
    return 0;
}

bool is7 (int number) {
    if (number % 7 == 0) {
        return true;
    }
    while (number > 0) {
        if (number % 10 == 7) {
            return true;
        }
        number /= 10;
    }
    return false;
}
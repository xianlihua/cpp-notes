/**
 * 计算非负整数 m 到 n（包括m 和 n ）之间的所有奇数的和，其中，m 不大于 n，且n 不大于300。例如 m=3, n=12, 其和则为：3+5+7+9+11=35
 *
 * 输入
 * 两个数 m 和 n，两个数以空格间隔，其中 0 <= m <= n <= 300 。
 *
 * 输出
 * 奇数之和
 */
#include <iostream>
using namespace std;
int main () {
    int a = 0, b = 0, sum = 0;
    cin >> a >> b;
    for (int i = a; i <=b; i++) {
        if (i % 2 == 0) {
            continue;
        }
        sum += i;
    }
    cout << sum << endl;
    return 0;
}

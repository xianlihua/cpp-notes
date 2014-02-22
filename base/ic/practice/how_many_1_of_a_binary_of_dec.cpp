/**
 * 描述
 * 给定一个十进制整数N，求其对应2进制数中1的个数
 *
 * 输入
 * 第一个整数表示有N组测试数据，其后N行是对应的测试数据，每行为一个整数。
 *
 * 输出
 * N行，每行输出对应一个输入。
 *
 * 样例输入
 * 4
 * 2
 * 100
 * 1000
 * 66
 *
 * 样例输出
 * 1
 * 3
 * 6
 * 2
**/
#include <iostream>
using namespace std;
short num (int);

int main () {
    short N = 0;
    int a[10] = {0};
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    cout << endl;
    for (int i = 0; i < N; i++) {
        cout << num(a[i]) << endl;
    }
    return 0;
}

// 循环思路
short num (int n) {
    short result = 0;
    while (n > 0) {
        if (n % 2) {
            result++;
        }
        n /= 2;
    }
    return result;
}

// 递归
// short num (int n) {
//     short result = 0;
//     if (n / 2 == 0) {
//         return 1;
//     } else {
//         return num(n /= 2) + n % 2;
//     }
// }
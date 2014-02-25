/**
 * 给定一个十进制整数N，求其对应2进制数中1的个数
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

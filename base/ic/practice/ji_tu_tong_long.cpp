/**
 * 描述
 * 一个笼子里面关了鸡和兔子（鸡有2只脚，兔子有4只脚，没有例外）。已经知道了笼子里面脚的总数a，问笼子里面至少有多少只动物，至多有多少只动物
 *
 * 输入
 * 第1行是测试数据的组数n，后面跟着n行输入。每组测试数据占1行，每行一个正整数a (a < 32768)
 *
 * 输出
 * 输出包含n行，每行对应一个输入,包含两个正整数，第一个是最少的动物数，第二个是最多的动物数，两个正整数用一个空格分开
 * 如果没有满足要求的答案，则输出两个0。
 *
 * 样例输入
 * 2
 * 3
 * 20
 *
 * 样例输出
 * 0 0
 * 5 10
 */
#include <iostream>
using namespace std;
int main () {
    int group = 0, foots[100] = {0}, min = 0, max = 0;
    cin >> group;
    for (int i = 0; i < group; i++) {
        cin >> foots[i];
    }
    cout << endl;
    for (int i = 0; i < group; i++) {
        if (foots[i] > 1 && foots[i] % 2 == 0) {
            max = foots[i] / 2;
            min = foots[i] / 4 + foots[i] % 4 / 2;
        } else {
            min = max = 0;
        }
        cout << min << " " << max << endl;
    }
    return 0;
}

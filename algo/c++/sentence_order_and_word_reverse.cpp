#include <iostream>
using namespace std;
int main () {
    char sentence[] = "sentence order and word reverse";

    char *index = sentence;
    char *start = sentence;
    char *end = sentence;

    while (true) {
        start = index;
        for (; *index != ' ' && *index != '\0'; index++);
        end = index - 1;
        for (char tmp; start < end; start++, end--) {
            tmp = *start;
            *start = *end;
            *end = tmp;
        }
        if (*index++ == '\0') break;
    }

    cout << sentence << endl;

    return 0;
}

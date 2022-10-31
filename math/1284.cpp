/*
 * Title: House Numbers
 * Link: https://www.acmicpc.net/problem/1284
 */

#include <stdio.h>

using namespace std;

constexpr int MAX_DIGIT = 4;

int ans;
char num[MAX_DIGIT + 1];

int main(int argc, char** argv) {
    while (true) {
        scanf("%s", num);

        if ('0' == num[0]) {
            break;
        }

        ans = 1;
        for (int i = 0; '\0' != num[i]; ++i) {
            if ('0' == num[i]) {
                ans += 5;
            }
            else if ('1' == num[i]) {
                ans += 3;
            }
            else {
                ans += 4;
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
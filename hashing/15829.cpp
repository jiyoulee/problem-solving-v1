/*
 * Title: 15829
 * Link: https://www.acmicpc.net/problem/15829
 */

#include <cstdio>

using namespace std;

constexpr int MAX_L = 50;
constexpr int DIV = 1234567891;

long long ans;
int L;
char str[MAX_L + 1];

int main(int argc, char** argv) {
    scanf("%d%s", &L, str);

    for (int i = L - 1; 0 <= i; --i) {
        ans *= 31;
        ans += str[i] - 'a' + 1;
        ans %= DIV;
    }

    printf("%lld", ans);

    return 0;
}
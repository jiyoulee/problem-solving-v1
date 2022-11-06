/*
 * Title: 피보나치 함수
 * Link: https://www.acmicpc.net/problem/1003
 */

#include <cstdio>

using namespace std;

constexpr int MAX_N = 40;

int T, N;
int cnt[2][1 + MAX_N];

int main(int argc, char** argv) {
    cnt[0][2] = cnt[0][0] = 1;
    cnt[1][1] = 1;
    for (int i = 2; MAX_N >= i; ++i) {
        cnt[0][i] = cnt[0][i - 1] + cnt[0][i - 2];
        cnt[1][i] = cnt[1][i - 1] + cnt[1][i - 2];
    }

    scanf("%d", &T);

    while (T--) {
        scanf("%d", &N);

        printf("%d %d\n", cnt[0][N], cnt[1][N]);
    }

    return 0;
}

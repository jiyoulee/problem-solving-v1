/*
 * Problem: Stickers
 * Tags: dynamic-programming
 * Link: https://www.acmicpc.net/problem/9465
 *
 * Author: jiyoulee
 * Solved: 2023-02-18
 */

#include <cstdio>
#include <algorithm>

using namespace std;

constexpr int MAX_N = 100000;

int T;
int N;
int dp[2][1 + MAX_N];

int main() {
    for (scanf("%d", &T); T--; ) {
        /*
         * Input.
         */
        scanf("%d", &N);

        for (int i = 0; 1 >= i; ++i) {
            for (int j = 1; N >= j; ++j) {
                scanf("%d", &dp[i][j]);
            }
        }

        /*
         * Compute.
         */
        for (int i = 1; N >= i; ++i) {
            dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + dp[0][i]);
            dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] + dp[1][i]);
        }

        /*
         * Output.
         */
        printf("%d\n", max(dp[0][N], dp[1][N]));
    }

    return 0;
}
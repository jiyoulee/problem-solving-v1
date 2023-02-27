/*
 * Problem: 다리 놓기
 * Tags: mathematics, dynamic-programming, combinatorics
 * Link: https://www.acmicpc.net/problem/1010
 *
 * Author: jiyoulee
 * Solved: 2023-02-27
 */

#include <cstdio>

using namespace std;

constexpr int MAX_M = 30;

int T, N, M;
int dp[MAX_M][MAX_M];

int main() {
    /*
     * Preset.
     */
    for (int i = 1; MAX_M > i; ++i) {
        dp[i][i] = dp[i][0] = 1;

        for (int j = 1; i > j; ++j) {
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
        }
    }

    /*
     * Input and Output.
     */
    for (scanf("%d", &T); T--; ) {
        scanf("%d%d", &N, &M);
        
        printf("%d\n", dp[M][N]);
    }

    return 0;
}
/*
 * Problem: 평범한 배낭
 * Tags: dynamic-programming, knapsack
 * Link: https://www.acmicpc.net/problem/12865
 *
 * Author: jiyoulee
 * Solved: 2023-02-24
 */

#include <cstdio>
#include <algorithm>

using namespace std;

int constexpr MAX_K = 100000;

int N, K;
int dp[2][MAX_K + 10];
int x = 0;

int main() {
    /*
     * Input.
     */
    scanf("%d%d", &N, &K);

    /*
     * Compute.
     */
    for (int i = 0, W, V; N > i; ++i, x ^= 1) {
        scanf("%d%d", &W, &V);

        for (int j = 1; K >= j; ++j) {
            dp[x ^ 1][j] = (W > j ? dp[x][j] : max(dp[x][j], dp[x][j - W] + V));
        }
    }

    /*
     * Output.
     */
    printf("%d", dp[x][K]);

    return 0;
}
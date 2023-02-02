/*
 * Problem: 조합
 * Tags: mathematics, combinatorics, arbitrary-precision, big-integers
 * Link: https://www.acmicpc.net/problem/2407
 *
 * Author: jiyoulee
 * Solved: 2023-02-02
 */

#include <cstdio>

using namespace std;

constexpr int MAX_N = 100;
constexpr int MAX_M = 100;
constexpr long long int VAL = 1000000000000000000;

int N, M;
long long int dp1[1 + MAX_N][1 + MAX_M];
long long int dp2[1 + MAX_N][1 + MAX_M];

int main() {
    /*
     * Input.
     */
    scanf("%d%d", &N, &M);

    /*
     * Compute.
     */
    for (int i = 1; N >= i; ++i) {
        dp2[i][i] = dp2[i][0] = 1;
    }

    for (int i = 2; N >= i; ++i) {
        for (int j = 1; M >= j; ++j) {
            dp2[i][j] = dp2[i - 1][j - 1] + dp2[i - 1][j];

            if (VAL <= dp2[i][j]) {
                dp2[i][j] -= VAL;
                dp1[i][j] += 1;
            }

            dp1[i][j] += dp1[i - 1][j - 1] + dp1[i - 1][j];
        }
    }

    /*
     * Output.
     */
    if (dp1[N][M]) {
        printf("%lld%18lld", dp1[N][M], dp2[N][M]);
    }
    else {
        printf("%lld", dp2[N][M]);
    }

    return 0;
}
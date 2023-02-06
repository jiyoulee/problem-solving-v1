/*
 * Problem: 가장 긴 증가하는 부분 수열
 * Tags: dynamic-programming
 * Link: https://www.acmicpc.net/problem/11053
 *
 * Author: jiyoulee
 * Solved: 2023-02-06
 */

#include <cstdio>

using namespace std;

constexpr int MAX_N = 1000;

int N;
int A[1 + MAX_N];
int dp[1 + MAX_N];

int main() {
    /*
     * Input.
     */
    scanf("%d", &N);

    for (int i = 1; N >= i; ++i) {
        scanf("%d", &A[i]);
    }

    /*
     * Compute.
     */
    for (int i = N, tmp; 0 <= i; --i) {
        for (int j = i + 1; N >= j; ++j) {
            if (A[i] < A[j] && dp[i] < dp[j]) {
                dp[i] = dp[j];
            }
        }
        ++dp[i];
    }        

    /*
     * Output.
     */
    printf("%d", dp[0] - 1);

    return 0;
}
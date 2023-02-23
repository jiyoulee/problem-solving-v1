/*
 * Problem: LCS
 * Tags: dynamic-programming, string
 * Link: https://www.acmicpc.net/problem/9251
 *
 * Author: jiyoulee
 * Solved: 2023-02-23
 */

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

constexpr int MAX_STR_LENGTH = 1000;
int dp[MAX_STR_LENGTH + 10][MAX_STR_LENGTH + 10];
char A[MAX_STR_LENGTH + 10];
char B[MAX_STR_LENGTH + 10];

int main() {
    /*
     * Input.
     */
    scanf("%s%s", A + 1, B + 1);

    /*
     * Compute;
     */
    for (int i = 1; B[i]; ++i) {
        for (int j = 1; A[j]; ++j) {
            dp[i][j] = (B[i] == A[j] ? dp[i - 1][j - 1] + 1 : max(dp[i - 1][j], dp[i][j - 1]));
        }
    }

    /*
     * Output.
     */
    printf("%d", dp[strlen(B + 1)][strlen(A + 1)]);     

    return 0;
}
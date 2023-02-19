/*
 * Problem: 구긴 힙 구하기 5
 * Tags: dynamic-programming, prefix-sum
 * Link: https://www.acmicpc.net/problem/11660
 *
 * Author: jiyoulee
 * Solved: 2023-02-19, 2021-10-15
 */

#include <cstdio>

using namespace std;

constexpr int MAX_N = 1024;

int N, M;
int A[1 + MAX_N][1 + MAX_N];
int x1, x2, y1, y2;

int main() {
    /*
     * Input and Preset.
     */
    scanf("%d%d", &N, &M);

    for (int i = 1; N >= i; ++i) {
        for (int j = 1; N >= j; ++j) {
            scanf("%d", &A[i][j]);

            A[i][j] += A[i - 1][j] + A[i][j - 1] - A[i - 1][j - 1];
        }
    }

    /*
     * Output.
     */
    while (M--) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

        printf("%d\n", A[x2][y2] - A[x2][y1 - 1] - A[x1 - 1][y2] + A[x1 - 1][y1 - 1]);
    }

    return 0;
}
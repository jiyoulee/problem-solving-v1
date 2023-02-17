/*
 * Problem: The Triangle
 * Tags: dynamic-programming
 * Link: https://www.acmicpc.net/problem/1932
 *
 * Author: jiyoulee
 * Solved: 2023-02-17
 */

#include <cstdio>
#include <algorithm>

using namespace std;

constexpr int MAX_N = 500;

int answer;
int N;
int A[1 + MAX_N][1 + MAX_N + 1];

int main() {
    /*
     * Input and Compute.
     */
    scanf("%d", &N);

    for (int i = 1; N >= i; ++i) {
        for (int j = 1; i >= j; ++j) {
            scanf("%d", &A[i][j]);

            A[i][j] += max(A[i - 1][j - 1], A[i - 1][j]);
        }
    }

    /*
     * Output.
     */
    for (int i = 1; N >= i; ++i) {
        if (A[N][i] > answer) {
            answer = A[N][i];
        }
    }

    printf("%d", answer);

    return 0;
}
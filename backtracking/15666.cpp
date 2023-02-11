/*
 * Problem: N과 M (12)
 * Tags: backtracking
 * Link: https://www.acmicpc.net/problem/15666
 *
 * Author: jiyoulee
 * Solved: 2023-02-11
 */

#include <cstdio>
#include <algorithm>

using namespace std;

constexpr int MAX_M = 8;

int answer[MAX_M];
int N, M;
int A[MAX_M];

void go(int index, int depth);

int main() {
    /*
     * Input.
     */
    scanf("%d%d", &N, &M);

    for (int i = 0; N > i; ++i) {
        scanf("%d", &A[i]);
    }

    /*
     * Compute.
     */
    sort(A, A + N);

    /*
     * Output.
     */
    go(0, 0);

    return 0;
}

void go(int index, int depth) {
    if (M == depth) {
        for (int i = 0; M > i; ++i) {
            printf("%d ", answer[i]);
        }
        printf("\n");

        return;
    }

    for (int i = index, val = 0; N > i; ++i) {
        if (val != A[i]) {
            val = answer[depth] = A[i];

            go(i, depth + 1);
        }
    }

    return;
}
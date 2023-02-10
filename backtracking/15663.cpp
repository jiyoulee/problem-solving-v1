/*
 * Problem: N과 M (9)
 * Tags: backtracking
 * Link: https://www.acmicpc.net/problem/15663
 *
 * Author: jiyoulee
 * Solved: 2023-02-10
 */

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int MAX_M = 8;

int answer[MAX_M];
int N, M;
pair<int,int> A[MAX_M + 1];

void go(int depth);

int main() {
    /*
     * Input.
     */
    scanf("%d%d", &N, &M);

    for (int tmp, i = 0, j; N--; ) {
        scanf("%d", &tmp);

        for (j = 0; i > j; ++j) {
            if (tmp == A[j].first) {
                ++A[j].second;

                break;
            }
        }

        if (i == j) {
            A[i].first = tmp;
            A[i].second = 1;
            ++i;
        }
    }

    /*
     * Compute.
     */
    for (int i = 0; A[i].first; ++i, ++N) {
        if (M < A[i].second) {
            A[i].second = M;
        }
    }

    sort(A, A + N + 1);

    /*
     * Output.
     */
    go(0);

    return 0;
}

void go(int depth) {
    if (M == depth) {
        for (int i = 0; M > i; ++i) {
            printf("%d ", answer[i]);
        }
        printf("\n");

        return;
    }

    for (int i = 0; A[i].first; ++i) {
        if (A[i].second) {
            answer[depth] = A[i].first;
            --A[i].second;

            go(depth + 1);

            ++A[i].second;
        }
    }

    return;
}
/*
 * Problem: N과 M (5)
 * Tags: backtracking
 * Link: https://www.acmicpc.net/problem/15654
 *
 * Author: jiyoulee
 * Solved: 2023-02-04
 */

#include <cstdio>
#include <algorithm>

using namespace std;

constexpr int MAX_N = 8;
constexpr int MAX_M = 8;

int answer[MAX_M];
int N, M;
int A[MAX_N];
bool visited[MAX_N];

void go(int depth);

int main() {
    /*
     * Input.
     */
    scanf("%d%d", &N, &M);

    for (int i = 0; N > i; ++i) {
        scanf("%d", &A[i]);
    }

    /*
     * Compute and Output.
     */
    sort(A, A + N);

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

    for (int i = 0; N > i; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            answer[depth] = A[i];

            go(depth + 1);
            
            visited[i] = false;
        }
    }

    return;
}
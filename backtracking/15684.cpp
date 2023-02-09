/*
 * Problem: 사다리 조작
 * Tags: implementation, brute-forcing, backtracking
 * Link: https://www.acmicpc.net/problem/15684
 *
 * Author: jiyoulee
 * Solved: 2023-02-09
 */

#include <cstdio>

using namespace std;

constexpr int INF = 4;
constexpr int MAX_N = 10;
constexpr int MAX_H = 30;

int answer = INF;
int N, M, H;
bool G[1 + MAX_H][1 + MAX_N + 1];

void go(int a, int b, int depth);

int main() {
    /*
     * Input.
     */
    scanf("%d%d%d", &N, &M, &H);

    for (int A, B; M--; ) {
        scanf("%d%d", &A, &B);

        G[A][B] = true;
    }

    /*
     * Compute.
     */
    go(1, 1, 0);

    /*
     * Output.
     */
    printf("%d", (3 < answer) ? -1 : answer);

    return 0;
}

void go(int a, int b, int depth) {
    bool is_valid = true;

    for (int i = 1, val = i; N >= i && is_valid; val = ++i) {
        for (int j = 1; H >= j; ++j) {
            if (G[j][val - 1]) {
                --val;
            }
            else if (G[j][val]) {
                ++val;
            }
        }

        if (val != i) {
            is_valid = false;
        }
    }

    if (is_valid && depth < answer) {
        answer = depth;
    }

    if (3 > depth) {
        for (int j = b, tmp; N > j; ++j) {
            if (!(G[a][j - 1] || G[a][j] || G[a][j + 1])) {
                G[a][j] = true;

                go(a, j + 1, depth + 1);

                G[a][j] = false;
            }
        }

        for (int i = a + 1, tmp; H >= i; ++i) {
            for (int j = 1; N > j; ++j) {
                if (!(G[i][j - 1] || G[i][j] || G[i][j + 1])) {
                    G[i][j] = true;

                    go(i, j + 1, depth + 1);

                    G[i][j] = false;
                }
            }
        }
    }

    return;
}
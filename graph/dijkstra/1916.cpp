/*
 * Problem: 최소비용 구하기
 * Tags: graph-theory, dijkstra
 * Link: https://www.acmicpc.net/problem/1916
 *
 * Author: jiyoulee
 * Solved: 2023-02-20, 2021-10-15
 */

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int INF = 1000000001;
constexpr int MAX_N = 1000;
constexpr int MAX_M = 100000;

int N, M, U, V;
int cost[1 + MAX_N][1 + MAX_N];
int dp[1 + MAX_N];
int visited[1 + MAX_N];

int main() {
    /*
     * Input.
     */
    scanf("%d%d", &N, &M);
    
    for (int i = 1; N >= i; ++i) {
        for (int j = 1; N >= j; ++j) {
            cost[i][j] = INF;
        }
    }

    for (int i = 0; N >= i; ++i) {
        cost[i][i] = 0;
        dp[i] = INF;
    }

    for (int C; M--; ) {
        scanf("%d%d%d", &U, &V, &C);

        if (cost[U][V] > C) {
            cost[U][V] = C;
        }
    }

    /*
     * Compute.
     */
    scanf("%d%d", &U, &V);

    dp[U] = 0;

    for (int i = 0, node = U, node_next; N > i; node = node_next, ++i) {
        visited[node] = true;

        node_next = 0;

        for (int i = 1; N >= i; ++i) {
            if (!visited[i]) {
                dp[i] = min(dp[i], dp[node] + cost[node][i]);

                if (dp[node_next] > dp[i]) {
                    node_next = i;
                }
            }
        }
    }

    /*
     * Output.
     */
    printf("%d", dp[V]);

    return 0;
}

/*
 * Problem: 최단경로
 * Tags: graph-theory, dijkstra
 * Link: https://www.acmicpc.net/problem/1753
 *
 * Author: jiyoulee
 * Solved: 2023-02-28, 2021-10-15
 */

#include <cstdio>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

constexpr int MAX_V = 20000;
constexpr int MAX_W = 10;
constexpr int INF = 1 << 18;

int V, E, K;
vector<pair<int,int>> G[1 + MAX_V];
int dp[1 + MAX_V];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min_pq;

int main() {
    /*
     * Input.
     */
    scanf("%d%d%d", &V, &E, &K);

    for (int u, v, w; E--; ) {
        scanf("%d%d%d", &u, &v, &w);

        G[u].emplace_back(v, w);
    }

    /*
     * Compute.
     */
    for (int i = 1; MAX_V >= i; ++i) {
        dp[i] = INF;
    }

    dp[K] = 0;
    min_pq.emplace(0, K);

    while (!min_pq.empty()) {
        auto [c, u] = min_pq.top();

        if (c == dp[u]) {
            for (auto& [v, w] : G[u]) {
                if (c + w < dp[v]) {
                    dp[v] = c + w;
                    min_pq.emplace(dp[v], v);
                }
            }
        }

        min_pq.pop();
    }

    /*
     * Output.
     */
    for (int i = 1; V >= i; ++i) {
        if (INF == dp[i]) {
            printf("INF\n");
        }
        else {
            printf("%d\n", dp[i]);
        }
    }

    return 0;
}
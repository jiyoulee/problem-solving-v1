/*
 * Title: ACM Craft
 * Link: https://www.acmicpc.net/problem/1005
 */

#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

constexpr int MAX_N = 1000;

int T, N, K, X, Y, W;
int D[1 + MAX_N];
int dp[1 + MAX_N];
vector<int> graph[1 + MAX_N];

int go(int n) {
    if (-1 != dp[n]) {
        return dp[n];
    }

    /*
     * In the event n is the starting node, look no further.
     */
    if (graph[n].empty()) {
        return dp[n] = D[n];
    }

    for (auto& node : graph[n]) {
        dp[n] = max(dp[n], go(node));
    }
    return dp[n] += D[n];
}

int main(int argc, char** argv) {
    scanf("%d", &T);

    while (T--) {
        /*
         * Get building rules and costs.
         */
        scanf("%d%d", &N, &K);
        for (int i = 1; N >= i; ++i) {
            scanf("%d", &D[i]);
        }
        while (K--) {
            scanf("%d%d", &X, &Y);
            graph[Y].emplace_back(X);
        }

        /*
         * Find minimum building cost.
         */
        scanf("%d", &W);
        memset(dp, -1, sizeof(dp));
        printf("%d\n", go(W));

        /*
         * Reset data structures.
         */
        memset(D, 0, sizeof(D));
        for (int i = 1; N >= i; ++i) {
            graph[i].clear();
        }
    }

    return 0;
}
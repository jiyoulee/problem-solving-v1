#include <bits/stdc++.h>
using namespace std;

#define INF 987654321

int TC, N, M, K, U, V, W;
int dist[501];
bool good;

int main() {
	scanf("%d", &TC);

	while (TC--) {
		vector<pair<int, int>> g[501];

		/*
		 * Create graph.
		 */
		scanf("%d%d%d", &N, &M, &K);
		for (int c = M; c >= 1; c--) {
			scanf("%d%d%d", &U, &V, &W);
			g[U].push_back({W, V});
			g[V].push_back({W, U});
		}
		for (int c = K; c >= 1; c--) {
			scanf("%d%d%d", &U, &V, &W);
			g[U].push_back({-W, V});
		}

		/*
		 * Test for negative cycle using Bellman Ford algorithm.
		 */
		fill(dist + 1, dist + N + 1, INF);
		for (int c = N - 1; c >= 1; c--) {
			for (int u = 1; u <= N; u++) {
				for (auto [w, v] : g[u]) {
					dist[v] = min(dist[v], dist[u] + w);
				}
			}
		}

		for (int u = 1; u <= N; u++) {
			for (auto [w, v] : g[u]) {
				if (dist[v] > dist[u] + w) {
					good = true;
				}
			}
		}

		if (!good) {
			printf("NO\n");
		}
		else {
			printf("YES\n");
			good = false;
		}
	}

	return 0;
}
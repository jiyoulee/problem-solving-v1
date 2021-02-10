#include <bits/stdc++.h>
using namespace std;

#define INF 987654321

int N, M, U, V, W;
vector<pair<int, int>> g[501];
long long dist[501];									// Cf. Bellman Ford algorithm requires underflow consideration.
bool locked[501];

void dfs(int u) {
	locked[u] = true;
	
	for (auto [w,v] : g[u]) {
		if(!locked[v]) {
			dfs(v);
		}
	}
	
	return;
}

int main() {
	/*
	 * Create graph.
	 */
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= M; i++) {
		scanf("%d%d%d", &U, &V, &W);
		g[U].push_back({W, V});
	}

	/*
	 * Find least-cost-path using Bellman Ford algorithm.
	 */
	fill(dist + 1, dist + N + 1, INF);
	dist[1] = 0;
	for (int c = N - 1; c >= 1; c--) {
		for (int u = 1; u <= N; u++) {
			for (auto [w,v] : g[u]) {
				dist[v] = min(dist[v], dist[u] + w);
			}
		}
	}

	/*
	 * Test endpoint reachability.
	 * Cf. Bellman Ford Algorithm requires endpoint to be reachable.
	 */
	dfs(1);

	for (int u = 1; u <= N; u++) {
		for (auto [w, v] : g[u]) {
			if (locked[v] && dist[v] > dist[u] + w) {	// Endpoint is reachable, and its least-cost-path has a negative cycle.
				printf("-1");
				
				return 0;
			}
		}
	}

	for (int u = 2; u <= N; u++) {
		if (!locked[u]) {
			printf("-1\n");
		}
		else {
			printf("%d\n", dist[u]);
		}
	}
	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int T, N, K, U, V, W, qlen, u;
int cost[1001];
vector<int> g[1001];
int indegree[1001];
queue<int> q;
int ans[1001];

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &N, &K);
		for (int i = 1; i <= N; i++) {
			scanf("%d", cost + i);
		}
		for (int i = 1; i <= K; i++) {
			scanf("%d%d", &U, &V);
			g[U].push_back(V);
			indegree[V] += 1;
		}
		scanf("%d", &W);

		/*
		 * Create base.
		 */
		for (int i = 1; i <= N; i++) {
			if (0 == indegree[i]) {
				ans[i] = cost[i];
				q.push(i);
			}
		}
		
		/*
		 * Update and memo (multiple options using topological sort).
		 */
		while (!q.empty()) {
			u = q.front();
			q.pop();
			
			for (auto e : g[u]) {
				ans[e] = max(ans[e], ans[u] + cost[e]);
				indegree[e] -= 1;
				
				if (0 == indegree[e]) {
					q.push(e);
				}
			}
		}

		printf("%d\n", ans[W]);

		/*
		 * (Reset global variables.)
		 */
		for (int i = 1; i <= N; i++) {
			g[i].clear();
		}
		fill(ans, ans + N + 1, 0);
	}

	return 0;
}
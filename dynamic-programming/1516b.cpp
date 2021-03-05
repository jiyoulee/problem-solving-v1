#include <bits/stdc++.h>
using namespace std;

#define INF 987654321

int N, v, u;
int w[501];
int indegree[501];
vector<int> g[501];
queue<int> q;
int m[501]; 								// m[i] is the shortest time taken to build building i.

int main() {
	scanf("%d", &N);
	for (u = 1; u <= N; u++) {
		scanf("%d", w + u);
		while (true) {
			scanf("%d", &v);
			if (-1 == v) break;
			else {
				g[v].push_back(u);
				indegree[u] += 1;
			}
		}
	}

	/*
	 * Create base.
	 */
	for (u = 1; u <= N; u++) {
		if (0 == indegree[u]) {
			m[u] = w[u];
			q.push(u);
		}
	}
	
	/*
	 * Update and memo (multiple options using topological sort).
	 */
	while (!q.empty()) {
		u = q.front();
		q.pop();
		for (auto v : g[u]) {
			m[v] = max(m[v], m[u] + w[v]);
			indegree[v] -= 1;
			if (0 == indegree[v]) {
				q.push(v);
			}
		}
	}

	for (u = 1; u <= N; u++) {
		printf("%d\n", m[u]);
	}

	return 0;
}
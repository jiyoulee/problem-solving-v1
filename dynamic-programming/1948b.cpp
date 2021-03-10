#include <bits/stdc++.h>
using namespace std;

int N, M, U, V, W, S, E, u, c;
vector<pair<int,int>> g1[10001];
vector<pair<int,int>> g2[10001];
int indegree[10001];
queue<int> q;
int m[10001];
bool locked[10001];

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= M; i++) {
		scanf("%d%d%d", &U, &V, &W);
		
		g1[U].push_back({V, W});
		indegree[V]++;
		g2[V].push_back({U, W});
	}
	scanf("%d%d", &S, &E);

	/*
	 * Find greatest-cost.
	 */
	q.push(S);
	while (!q.empty()) {
		u = q.front();
		q.pop();
		
		for (auto [v, w] : g1[u]) {
			m[v] = max(m[v], m[u] + w);

			indegree[v]--;
			if (0 == indegree[v]) {
				q.push(v);
			}
		}
	}

	/*
	 * Find set of edges that compose greatest-cost paths.
	 */
	q.push(E);
	while (!q.empty()) {
		u = q.front();
		q.pop();

		if (locked[u]) {
			continue;
		}

		locked[u] = true;
		for (auto [v,w] : g2[u]) {
			if (m[u] != m[v] + w) {
				continue;
			}				

			c++;
			q.push(v);
		}
	}

	printf("%d\n%d", m[E], c);

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int N, M, U, V, u;
vector<int> g[32001];
int indegree[32001];
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= M; i++) {
		scanf("%d%d", &U, &V);
		
		g[U].push_back(V);
		indegree[V] += 1;
	}

	/*
	 * Topologically sort nodes using a max priority queue.
	 */
	for (u = 1; u <= N; u++) {
		if (0 == indegree[u]) {
			pq.push(u);
		}
	}
	while (!pq.empty()) {
		u = pq.top();
		pq.pop();
		
		printf("%d ", u);
		
		for (auto v : g[u]) {
			indegree[v] -= 1;
			
			if (0 == indegree[v]) {
				pq.push(v);
			}
		}
	}
	
	return 0;
}
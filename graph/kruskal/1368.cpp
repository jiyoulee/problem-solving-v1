#include <bits/stdc++.h>
using namespace std;

int N, C, ans;
int p[301];
vector<tuple<int, int, int>> g;

int find(int u) {
	if (p[u] == u) {
		return u;
	}
	
	return p[u] = find(p[u]);
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);
	
	p[v] = u;
}

int main() {
	/*
	 * Build graph.
	 */
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &C);
		
		g.push_back({C, 0, i});						// View the root node of MST as node 0, and the cost of creating a new well at node i as the weight of an edge from node 0 to node i.
	}
	for (int v = 1; v <= N; v++) {
		for (int h = 1; h <= N; h++) {
			scanf("%d", &C);
			
			if (0 >= (v - h) && 0 < C) {
				g.push_back({C, v, h});
			}
		}
	}
	
	/*
	 * Satisfy Kruskal's algorithm's hypotheses.
	 */
	for (int i = 0; i <= N; i++) {
		p[i]=i;
	}
	sort(g.begin(), g.end());

	/*
	 * Find least cost path using Kruskal's algorithm.
	 */
	for (auto e : g) {
		if (find(get<1>(e)) != find(get<2>(e))) {
			ans += get<0>(e);
			merge(get<1>(e), get<2>(e));
		}
	}

	printf("%d", ans);
	
	return 0;
}
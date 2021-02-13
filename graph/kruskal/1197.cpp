#include <bits/stdc++.h>
using namespace std;

int V, E, A, B, C;
int cost;
int parent[10001];
tuple<int, int, int> g[100001];

int find(int u) {
	if (u == parent[u]) {
		return u;
	}
	
	return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);
	
	if (u != v) {
		parent[v] = u;
	}
}

int main() {
	scanf("%d%d", &V, &E);
	for (int i = 1; i <= E; i++) {
		scanf("%d%d%d", &get<1>(g[i]), &get<2>(g[i]), &get<0>(g[i]));
	}

	/*
	 * Initialize union-find.
	 */
	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}

	/*
	 * Satisfy Kruskal's algorithm condition.
	 */
	sort(g + 1, g + E + 1);
	
	/*
	 * Find minimum spanning tree using Kruskal's algorithm.
	 */	
	for (int i = 1; i <= E; i++) {
		if (find(get<1>(g[i])) != find(get<2>(g[i]))) {
			cost += get<0>(g[i]);
			merge(get<1>(g[i]), get<2>(g[i]));
		}
	}

	printf("%d", cost);

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int N, M;
int cost;
char gender[1002];
int parent[1001];
tuple<int, int, int> g[10001];

int find(int u) {
	if (u==parent[u]) return u;
	return parent[u]=find(parent[u]);
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);
	
	if (u != v) {
		parent[v] = u;
	}
	
	return;
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%s", gender + i);
	}
	for (int i = 1; i <= M; i++) {
		scanf("%d%d%d", &get<1>(g[i]), &get<2>(g[i]), &get<0>(g[i]));
	}
	
	/*
	 * Initialize union-find.
	 */
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
	
	/*
	 * Satisfy Kruskal's algorithm condition.
	 */
	sort(g + 1, g + M + 1);
	
	/*
	 * Find minimum spanning tree using Kruskal's algorithm.
	 */
	for (int i = 1; i <= M; i++) {
		if (find(get<1>(g[i])) != find(get<2>(g[i])) && gender[get<1>(g[i])] != gender[get<2>(g[i])]) {
			cost += get<0>(g[i]);
			merge(get<1>(g[i]), get<2>(g[i]));
		}
	}

	for (int i = 1; i < N; i++) {
		if (find(i) != find(i + 1)) {
			printf("-1");
			return 0;
		}
	}
	
	printf("%d", cost);
	return 0;
}

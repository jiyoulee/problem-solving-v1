#include <bits/stdc++.h>
using namespace std;

int N, X, Y, Z;
long long ans;
pair<int, int> x[100001];
pair<int, int> y[100001];
pair<int, int> z[100001];
vector<tuple<int, int, int>> g;
int p[100001];

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
	 * Project nodes onto xy, yz, zx planes.
	 */
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d%d%d", &X, &Y, &Z);
		x[i] = {X, i};
		y[i] = {Y, i};
		z[i] = {Z, i};
	}

	/*
	 * Create edges.
	 */
	sort(x + 1, x + N + 1);
	sort(y + 1, y + N + 1);
	sort(z + 1, z + N + 1);
	for (int i = 1; i < N; i++) {
		g.push_back({x[i + 1].first - x[i].first, x[i].second, x[i + 1].second});
	}
	for (int i = 1; i < N; i++) {
		g.push_back({y[i + 1].first - y[i].first, y[i].second, y[i + 1].second});
	}
	for (int i = 1; i < N; i++) {
		g.push_back({z[i + 1].first - z[i].first, z[i].second, z[i + 1].second});
	}

	/*
	 * Run Kruskal's algorithm.
	 */
	for (int i = 1; i <= N; i++) {
		p[i] = i;
	}
	sort(g.begin(), g.end());
	for (auto e : g) {
		if (find(get<1>(e)) != find(get<2>(e))) {
			ans += get<0>(e);
			merge(get<1>(e), get<2>(e));
		}
	}

	printf("%lld", ans);

	return 0;
}
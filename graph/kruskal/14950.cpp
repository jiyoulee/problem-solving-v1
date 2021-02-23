#include <bits/stdc++.h>
using namespace std;

int N, M, T, U, V, W, t, ans;
int p[10001];
tuple<int, int, int> g[30001];

int find(int u) {										// O(Ackermann number * N)
	if (p[u] == u) {
		return u;
	}
	
	return p[u] = find(p[u]);
}

void merge(int u, int v) {								// O(Ackermann number * N)
	u = find(u);
	v = find(v);
	
	p[v] = u;
}

int main() {
	scanf("%d%d%d", &N, &M, &T);
	for (int i = 1; i <= M; i++) {
		scanf("%d%d%d", &U, &V, &W);
		g[i] = {W, U, V};
	}

	for (int i = 1; i <= N; i++) {
		p[i] = i;
	}
	sort(g + 1, g + M + 1);

	for (int i = 1; i <= M; i++) {							// O(M * log(M))
		if (find(get<1>(g[i])) != find(get<2>(g[i]))) {
			ans += get<0>(g[i]) + t;
			merge(get<1>(g[i]), get<2>(g[i]));
			t += T;
		}
	}

	printf("%d", ans);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int N, M, tmp1, tmp2;
int p[201];

int find(int u) {
	if (u == p[u]) {
		return u;
	}
	
	return p[u] = find(p[u]); 
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);
	
	if (u!=v) {
		p[v] = u;
	}
}

int main() {
	scanf("%d%d", &N, &M);
	
	/*
	 * Initialize union-find.
	 */
	for (int i = 1; i <= N; i++) {
		p[i] = i;
	}
	
	/*
	 * Get all disjoint sets.
	 */
	for (int v = 1; v <= N; v++) {
		for (int h = 1; h <= N; h++) {
			scanf("%d", &tmp1);
			
			if (1 == tmp1) {
				merge(v,h);
			}
		}
	}

	scanf("%d", &tmp1);						// Cf. In order for traveling to be possible, all locations must be accessible from the start location.
	for (int i = 1; i < M; i++) {
		scanf("%d", &tmp2);
		if (find(tmp1) != find(tmp2)) {		// Location tmp2 cannot be accessed from the start location.
			printf("NO");
			
			return 0;
		}
	}
	printf("YES");
	
	return 0;
}
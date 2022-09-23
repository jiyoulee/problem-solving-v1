#include <bits/stdc++.h>
using namespace std;

int N, X, u;
vector<int> g[101];
bool locked[101];
int ans[101][101];

void dfs(int n) {
	for (auto v : g[n]) {
		if (!locked[v]) {							// v is reachable from u.
			ans[u][v] = 1;
			locked[v] = true;
			dfs(v);
		}
	}
	
	return 0;
}

int main() {
	scanf("%d", &N);
	for (int v = 1; v <= N; v++) {
		for (int h = 1; h <= N; h++) {
			scanf("%d", &X);
			
			if (1 == X) {
				g[v].push_back(h);
			}
		}
	}

	/*
	 * Check each node for reachability using depth-first-search.
	 */
	for (u = 1; u <= N; u++) {
		fill(locked + 1, locked + N + 1, false);
		dfs(u);
	}

	for (int v = 1; v <= N; v++) {
		for (int h = 1; h <= N; h++) {
			printf("%d ", ans[v][h]);
		}
		puts("");
	}
	
	return 0;
}
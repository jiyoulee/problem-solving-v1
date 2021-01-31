#include <bits/stdc++.h>
using namespace std;

int P, NS, T, u, v, w;
vector<int> g[5001];
vector<int> st;

/*
 * A brute force way of search on permutation of possible paths.
 */
void track(int x) {
	/*
	 * Check for leaf nodes and other end conditions.
	 */
	if (T == x) {
		printf("%d\n", st.size());
		for (int e : st) {
			printf("%d\n", e);
		}
		
		return;
	}
	if (g[x].empty()) {
		return;
	}

	/*
	 * Search subtree.
	 */
	for (int e : g[x]) {
		st.push_back(e);
		track(e);
		st.pop_back();
	}

	return;
}

int main() {
	scanf("%d%d%d", &P, &NS, &T);
	for (int i = 1; i <= NS; i++) {
		scanf("%d%d%d", &u, &v, &w);
		
		g[u].push_back(v);
		g[u].push_back(w);
	}

	g[0].push_back(1);
	track(0);
	
	return 0;
}
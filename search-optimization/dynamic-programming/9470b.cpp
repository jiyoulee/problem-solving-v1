#include <bits/stdc++.h>
using namespace std;

int T, K, M, P, A, B, u;
vector<int> g[1001];
int indegree[1001];
int m[1001];													// m[i] is the Strahler order of node i. 
bool strahler[1001];
queue<int> q;

int main() {													// Cf. Topological sorting can be used to search a tree data structure from leaves up.
	scanf("%d", &T);
	
	while (T--) {
		scanf("%d%d%d", &K, &M, &P);
		for (int i = 1; i <= P; i++) {
			scanf("%d%d", &A, &B);
			g[A].push_back(B);
			indegree[B] += 1;
		}

		/*
		 * Create base.
		 */
		for (u = 1; u <= M; u++) {
			if (0 == indegree[u]) {
				m[u] = 1;
				q.push(u);
			}
		}
		
		/*
		 * Update and memo (multiple options using topological sort).
		 */
		while(!q.empty()) {
			u = q.front();
			q.pop();
			for (int v : g[u]) {
				if (0<m[u] - m[v]) {							// A child node whose Strahler order is higher than the current highest Strahler order found is found.
					m[v] = m[u];
					strahler[v]=true;
				}
				else if (strahler[v] && 0 == m[u] - m[v]) {		// Another child node whose Strahler order is the same as the current highest Strahler order found is found.
					m[v] += 1;
					strahler[v] = false;
				}
				
				indegree[v] -= 1;
				if (0 == indegree[v]) {
					q.push(v);
				}
			}
		}

		printf("%d %d\n", K, m[M]);

		/*
		 * Reset global variables.
		 */
		for (u = 1; u <= M; u++) {
			g[u].clear();
		}
		fill(indegree + 1, indegree + M + 1, 0);
		fill(m + 1, m + M + 1, 0);
		fill(strahler + 1, strahler + M + 1, false);
	}

	return 0;
}
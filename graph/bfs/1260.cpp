#include <bits/stdc++.h>
using namespace std;

#define MAX_NODE_CNT 1001

int N, M, V;
int u, v, n;								// For reading in nodes, use 'u', 'v'.
vector<int> g[MAX_NODE_CNT];				// For representing a graph, use 'g'.
bool key[MAX_NODE_CNT];						// For representing the acquisition of a "key" that grants access to its corresponding node, use 'key'.

void dfs(int n) {							// (Implemented using either 1) recursive function or 2) stack.)
	key[n] = true;							// Acquire key to node.
	
	printf("%d ",n);						// Access node using key. 
	
	for (int c : g[n]) {					// Select first child node whose key has not been acquired.
		if (!key[c]) {
			dfs(c);
		}
	}
	
	return;
}

void bfs(int s) {							// (Implemented using queue.)
	queue<int> q;							// A queue of keys that have been acquired.
	
	key[s] = true;							// Acquire key to starting node.
	q.push(s);								// Queue key.
	
	while (!q.empty()) {
		n = q.front();						// Access node using key.		
		printf("%d ", n);		
		q.pop();
		
		for (int c : g[n]) {				// Acquire keys to child nodes and queue them.
			if (!key[c]) {
				key[c] = true;
				q.push(c);
			}
		}
	}
	
	return;
}

int main() {
	scanf("%d%d%d", &N, &M, &V);
	
	/*
	 * Create graph.
	 * If graph is given as input, create using a vector.
	 * If graph needs to be formed (ex. Cartesian coordinates), declare an array.
	 */
	for (int i = 1; i <= M; i++) {
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= N; i++) {
		sort(g[i].begin(), g[i].end());
	}
	
	dfs(V);
	puts("");
	
	fill(key + 1, key + 1 + N, false);		// (Reset acquired keys.)
	bfs(V);
	
	return 0;
}
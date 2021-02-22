#include <bits/stdc++.h>
using namespace std;

int L, N, M, U, V, c;
vector<int> g[1001];
int indegree[1001];
queue<int> q;
vector<int> v;								// Task completion order.

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= M; i++) {
		scanf("%d%d", &L, &U);
		
		for (int i = 1; i <= L - 1; i++) {
			scanf("%d", &V);
			
			g[U].push_back(V);
			indegree[V] += 1;
			
			U = V;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (0 == indegree[i]) {
			q.push(i);
		}
	}

	while (!q.empty()) {					// O(N + M)
		U = q.front();
		
		c += 1;								// Count tasks considered.
		v.push_back(U);						// Add finished task to order.
		
		q.pop();
		
		for (auto u : g[U]) {
			indegree[u] -= 1;				// Notify completion of task. 
			
			if (0 == indegree[u]) {			// All prerequesite tasks have been completed.
				q.push(u);					// Add task to the to-be-considered-queue.
			}
		}
	}

	if (N != c) {							// Some task who's some prerequisite task has not yet been complete exists.
		printf("0");
	}
	else for (auto u : v) {
		printf("%d\n", u);
	}

	return 0;
}
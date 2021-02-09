#include <bits/stdc++.h>
using namespace std;

#define INF 987654321

int N, u, M, S, U, V, W;
vector<pair<int,int>> g[20001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int dist[20001];
int locked[20001];

int main() {
	scanf("%d%d%d", &N, &M, &S);
	for (int i = 1; i <= M; i++) {
		scanf("%d%d%d", &U, &V, &W);
		g[U].push_back({W, V});
	}
	fill(dist + 1, dist + N + 1, INF);
	
	dist[S] = 0;
	pq.push({dist[S], S});
	while (!pq.empty()) {
		u = get<1>(pq.top());
		pq.pop();
		
		if (!locked[u]) {
			locked[u] = true;
			
			for (auto [w,v] : g[u]) {
				dist[v] = min(dist[v], dist[u] + w);
				pq.push({dist[v], v});
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (INF == dist[i]) {
			printf("INF\n");
		}
		else {
			printf("%d\n", dist[i]);
		}
	}
	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define INF 987654321

int N, M, U, V, W, S, E, u;
vector<pair<int, int>> g[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
bool locked[1001];
int dist[1001];

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= M; i++) {
		scanf("%d%d%d", &U, &V, &W);
		g[U].push_back(make_pair(W, V));
	}
	scanf("%d%d",&S, &E);

	fill(dist + 1, dist + 1000 + 1, INF);
	dist[S]=0;
	
	pq.push(make_pair(dist[S], S));
	while (!pq.empty()) {
		u = get<1>(pq.top());
		pq.pop();
		
		if (!locked[u]) {
			locked[u] = true;
			
			for (auto [w,v] : g[u]) {
				dist[v] = min(dist[v], dist[u] + w);
				pq.push(make_pair(dist[v], v));
			}			
		}
	}
	
	printf("%d", dist[E]);
	
	return 0;
}
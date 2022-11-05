/* 
 * Title: 최소 스패닝 트리
 * Link: https://www.acmicpc.net/problem/1197
 */

#include <cstdio>
#include <algorithm>
#include <tuple>
#include <cstring>

using namespace std;

constexpr int MAX_V = 10000;
constexpr int MAX_E = 100000;

int ans;
int V, E, A, B, C;
int parents[1 + MAX_V];
int edges_cnt;
tuple<int, int, int> edges[MAX_E];

int find(int n) {
	if (-1 == parents[n]) {
		return n;
	}

	return parents[n] = find(parents[n]);
}

bool merge(int a, int b) {
	int set_a = find(a);
	int set_b = find(b);

	if (set_a != set_b) {
		parents[set_b] = set_a;
	}
	
	return set_a != set_b;
}

int main(int argc, char** argv) {
	scanf("%d%d", &V, &E);
	memset(parents, -1, sizeof(int) * (1 + V));

	/*
	 * Get edges, sorted in non-decreasing order.
	 */
	for (int i = 0; E > i; ++i) {
		scanf("%d%d%d", &A, &B, &C);

		get<0>(edges[i]) = C;
		get<1>(edges[i]) = A;
		get<2>(edges[i]) = B;
	}
	sort(edges, edges + E);

	/*
	 * Run Kruskal's algorithm.
	 */
	int v = V - 1;
	for (int i = 0; v > edges_cnt; ++i) {
		C = get<0>(edges[i]);
		A = get<1>(edges[i]);
		B = get<2>(edges[i]);

		if (merge(A, B)) {
			ans += C;
			++edges_cnt;
		}
	}

	printf("%d", (1 == V) ? get<0>(edges[0]) : ans);

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int N, M, nv, nh, ans;
char A[1000][1000];
int parent[1000000];
int [1000000];
int dv[4]={0, 1, 0, -1};
int dh[4]={1, 0, -1, 0};
vector<int> s;

int find_root(int u) {
	if (parent[u] == u) {
		return u;
	}
	
	return parent[u] = find_set(parent[u]);
}

void merge(int u, int v) {
	u = find1(u);
	v = find1(v);
	
	if (u != v) {
		parent[v] = u;
	}
}

int main() {
	scanf("%d%d", &N, &M);

	for (int v = 0; v < N; v++) {
		scanf("%s", &A[v][0]);
	}
	
	/*
	 * Get all disjoint sets.
	 */
	for (int i = 0; i < N*M; i++) {
		parent[i] = i;
	}
	for (int v = 0; v < N; v++) {
		for (int h = 0; h < M; h++) {
			if ('0' == A[v][h]) {														// Location does not have a wall (i.e., accessible).
				for (int i = 0; i < 4; i++) {
					nv = v + dv[i];
					nh = h + dh[i];
					if (0 <= nv && N > nv && 0 <= nh && M > nh && '0' == A[nv][nh]) {	// Adjacent locations also does not have a wall (i.e., accessible).
						merge(v * M + h, nv * M + nh);									// Place two locations into the same disjoint set.
					}
				}
			}
		}
	}

	/*
	 * Count number of locations per disjoint set.
	 */
	for (int v = 0; v < N; v++) {
		for (int h = 0; h < M; h++) {
			if ('0' == A[v][h]) {
				b[find1(v * M + h)]++;
			}
		}
	}
	
	for (int v = 0; v < N; v++) {
		for (int h = 0; h < M; h++) {
			if ('0' == A[v][h]) {
				printf("0");
			}
			else {																											// Location has a wall.
				for (int i = 0; i < 4; i++) {
					nv = v + dv[i];
					nh = h + dh[i];
					if (0 <= nv && N > nv && 0 <= nh && M > nh && find(s.begin(),s.end(),find1(nv * M + nh)) == s.end()) {	// Adjacent location does not have a wall and forms an independent disjoint set.
						ans += b[find1(nv * M + nh)];
						s.push_back(find1(nv * M + nh));
					}
				}
				printf("%d", (ans + 1) % 10);
				
				while (!s.empty()) {
					s.pop_back();
				}
				ans = 0;
			}
		}
		
		puts("");
	}

	return 0;
}
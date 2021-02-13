#include <bits/stdc++.h>
using namespace std;

int N, M, U, V;
int parent[500000];

int find(int x) {
	if (x == parent[x]) {
		return x;
	}
	
	return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	
	parent[b] = a;
}

int main() {
	scanf("%d%d", &N, &M);
	
	/*
	 * Initialize union-find.
	 */
	for (int i = 0; i < N; i++) {
		parent[i] = i;
	}
	
	for (int i = 1; i <= M; i++) {
		scanf("%d%d", &U, &V);
		
		if (find(U) == find(V)) {
			printf("%d", i);
			return 0;
		}
		
		merge(U, V);
	}
	printf("0");
	
	return 0;
}
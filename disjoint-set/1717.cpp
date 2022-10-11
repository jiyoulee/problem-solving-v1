#include <bits/stdc++.h>
using namespace std;

int N, M, K, A, B;
int parent[1000001];

int find(int x) {
	if (x == parent[x]) {
		return x;
	}
	
	return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	
	if (a != b) {
		parent[b] = a;
	}
	
	return;
}

int main() {
	scanf("%d%d", &N, &M);
	
	/*
	 * Initialize union-find.
	 */
	for (int i = 0; i <= N; i++) {
		parent[i] = i;
	}
	
	while (M--) {
		scanf("%d%d%d", &K, &A, &B);
		
		if (0 == K) {
			merge(A, B);
		}
		else {
			if (find(A) == find(B)) {
				printf("YES\n");
			}
			else printf("NO\n");
		}
	}
	
	return 0;
}
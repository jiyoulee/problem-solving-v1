#include <bits/stdc++.h>
using namespace std;

int N, M, V1, H1, V2, H2;
int a[1025][1025];

int main() {																			// O(N)
	scanf("%d%d", &N, &M);
	for (int v = 1; v <= N; v++) {
		for (int h = 1; h <= N; h++) {
			scanf("%d", &a[v][h]);
			
			a[v][h] += a[v][h - 1] + a[v - 1][h] - a[v - 1][h - 1];						// Calculate prefix-sum.
		}
	}

	for (int c = 1; c <= M; c++) {
		scanf("%d%d%d%d", &V1, &H1, &V2, &H2);
		
		printf("%d\n", a[V2][H2] - a[V2][H1 - 1] - a[V1 - 1][H2] + a[V1 - 1][H1 - 1]);	// Use prefix-sum.
	}
	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int N, M, I, J;
int a[100001];

int main() {
	scanf("%d%d", &N, &M);
	
	for (int i = 1; i <= N; i++) {
		scanf("%d", a + i);
		
		a[i] += a[i - 1];					// Calculate prefix-sum.
	}
	
	for (int c = M; c >= 1; c--) {
		scanf("%d%d", &I, &J);
		
		printf("%d\n", a[J] - a[I - 1]);	// Use prefix-sum.
	}
	
	return 0;
}
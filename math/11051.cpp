#include <bits/stdc++.h>
using namespace std;

#define M 10007;

int N, K;
int m[1001][1001];

int main() {												// O(N^2)
	scanf("%d%d", &N, &K);
	
	// Create base.
	for (int i = 0; i <= N; i++) {
		m[i][0] = 1;
		m[i][i] = 1;
	}
	
	// Update and memo (single option).
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= i - 1; j++) {
			m[i][j] = (m[i - 1][j - 1] + m[i - 1][j]) % M;
		}
	}
	
	printf("%d", m[N][K]);
	
	return 0;
}
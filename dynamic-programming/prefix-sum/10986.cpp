#include <bits/stdc++.h>
using namespace std;

int N, M;
long long ans;
long long prefix_sum[1000001];
long long rem[1000];

/*
 * Cf. (A - B) % M == 0 <=> (A % M) == 0 && (B % M) == 0.
 */
int main() {
	scanf("%d%d", &N, &M);
	
	for (int c = 1; c <= N; c++) {
		scanf("%lld", prefix_sum + c);
		
		prefix_sum[c] += prefix_sum[c - 1];	// Calculate prefix sum.
		rem[prefix_sum[c] % M]++;			// Update remainder count.
	}
											// Calculate interval count.
	ans += rem[0];							// I == J.
	for (int c = 0; c < M; c++) {			// I != J.
		ans += rem[c] * (rem[c] - 1) / 2;
	}
	
	printf("%lld", ans);
	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int N, K, ans;
int a[11];

int main() {
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%d", a + i);
	}
	
	/*
	 * 1. Since Ai = k * Ai-1, no more than k Ai-1 coins should be used.
	 * 2. If coins are accounted for in value-decreasing order, each accounted coin shoud be used as much as possible.
	 */
	sort(a + 1, a + 1 + N);
	for (int i = N; i >= 1; i--) { // i is the index of the ith most valueable coin.
		ans += K / a[i];
		K %= a[i];
	}
	
	printf("%d", ans);
	return 0;
}

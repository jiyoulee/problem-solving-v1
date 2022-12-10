#include <bits/stdc++.h>
using namespace std;

int N, K;
long long a[300000];
long long ans;

/*
 * 1. The number of activated stones at a given time must always be as many as possible.
 * 2. Quests must be completed in order of least points to most points.
 */
int main() {
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", a + i);
	}
	
	sort(a, a + N);
	for (int i = 0; i < K; i++) {
		ans += i * a[i];
	}
	for (int i = K; i < N; i++) {
		ans += K * a[i];
	}
	
	printf("%lld", ans);
	return 0;
}
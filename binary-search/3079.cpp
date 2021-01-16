#include <bits/stdc++.h>
using namespace std;

int N, M;
int a[100001];

/*
 * x represents the minimum time taken to complete all passport checks.
 * Given x, the maximum number of passport checks possible within x the number of checks possible within x when all stations are fully utilized.
 */
bool good(long long x) {
	long long cnt = 0;
	
	for (int i = 1; i <= N; i++) {
		cnt += x/a[i];
		
		if (cnt >= M) {
			return true;
		}
	}
	
	return false;
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%d", a + i);
	}
	
	// Do binary search (l xxxooo r).
	long long l = 1;
	long long r = 1e18;
	long long h;	
	while (l <= r) {
		h = (l + r) / 2;
		if (good(h)) {
			r = h - 1;
		}
		else {
			l = h + 1;
		}
	}
	
	printf("%lld", l);
	return 0;
}

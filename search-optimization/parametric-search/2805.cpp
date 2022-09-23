#include <bits/stdc++.h>
using namespace std;

int N;
long long M;
long long l = 0, r = 1e9, h;
long long a[1000001];

/*
 * Decides whether cutting at height x is valid.
 */
bool candidate(int x) {
	long long sum = 0LL;
	
	for (int i = 1; i <= N; i++) {
		sum += max(0LL, a[i] - x);		// max(tree height is smaller than or equal to x, tree height is larger than x)
	}
	
	return sum >= M;
}

int main() {
	scanf("%d%lld", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%d", a+i);
	}
	
	// Do binary search.
	while (l <= r) {					// Check whether range is valid.
		h = (l + r) / 2;				// Get halfway point of range.
		if (candidate(h)) {				// Halfway point is a candidate.
			l = h + 1;
		}
		else {							// Halfway point is not a candidate.
			r = h - 1;
		}
	}
	
	printf("%d",r);						// Answer is at r.
	
	return 0;
}
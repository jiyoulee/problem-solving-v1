#include <bits/stdc++.h>
using namespace std;

int N;
int v[300001];

bool good(long long x) { // x is the initial speed at Earth.
	for (int i = 1;i <= N && 0 < x; i++) {
		if (0 == x % v[i]) {
			continue;
		}
		else {
			x -= x % v[i];
		}
	}
	
	if (x) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d",v+i);
	}
	
	// Do binary search (l xxxx oooo r).
	long long l = 0;
	long long r = 3*1e14;
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
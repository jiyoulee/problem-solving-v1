#include <bits/stdc++.h>
using namespace std;

int N, M;
int a[1000001];

int good(long long x) { // x is the time taken to make all balloons.
	long long cnt=0;
	for (int i = 1; i <= N; i++) {
		cnt += x/a[i];
	}
	return M <= cnt;
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1;i <= N; i++) {
		scanf("%d", a + i);
	}
	
	// Do binary search (l xxxooo r).
	long long l = 0;
	long long r = 1e12;
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
	
	printf("%lld",l);
	
	return 0;
}
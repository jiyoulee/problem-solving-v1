#include <bits/stdc++.h>
using namespace std;

int N, M, L, cnt;
int a[102];

/*
 * x represents the maximum length of the distance between two resting stations.
 * Given x, the maximum number of resting stations that can be built is the number of resting stations that can be built when building per space of x.
 */
bool good(int x) {
	cnt = 0;
	
	for (int i = 1; i <= N + 1; i++) {
		cnt += a[i] / x;
	}
	
	return cnt <= M;
}

int main() {
	scanf("%d%d%d", &N, &M, &L);
	for (int i = 1; i <= N; i++) {
		scanf("%d", a + i);
	}
	sort(a + 1, a + 1 + N);
	a[N + 1] = L - a[N] - 1;
	for (int i = N; i >= 1; i--) {
		a[i] -= a[i - 1] + 1;
	}
	
	// Do binary search (l xxxooo r).
	int l = 1;
	int	r = L - 2;
	int	h;
	while (l <= r) {
		h = (l + r) / 2;
		if (good(h)) {
			r = h - 1;
		}
		else {
			l = h + 1;
		}
	}
	
	printf("%d", l);
	
	return 0;
}
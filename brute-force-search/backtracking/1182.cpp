#include <bits/stdc++.h>
using namespace std;

#define UPPER_BOUND 21

int N, S, ans;
int a[UPPER_BOUND];

void track(int n, int s) {
	if (0 < n && S == s) {
		ans++;
	}
	
	/*
	 * If count is full (i.e. has reached end of number sequence),
	 * 2. Return.
	 */
	if (N == n) {
		return;
	}

	/* Else,
	 * 2. Explore subtree.
	 */
	for (int i = n + 1; i <= N; i++) {
		track(i, s + a[i]);
	}

	return;
}

int main() {
	scanf("%d%d", &N, &S);
	for (int i = 1; i <= N; i++) {
		scanf("%d", a + i);
	}
	
	track(0,0);
	
	printf("%d", ans);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int N, M, l, r, sum, ans;
int a[10002];

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%d", a + i);
	}
	
	/*
	 * Initialize.
	 */
	l = 1;
	r = 1;
	sum = a[1];
	
	/*
	 * Search.
	 */
	while (r <= N) {
		if (M == sum) {
			ans++;
		}
		
		if (M >= sum) {
			r += 1;
			sum += a[r];
		}
		else {
			sum -= a[l];
			l += 1;
		}
	}
	
	printf("%d", ans);
	
	return 0;
}
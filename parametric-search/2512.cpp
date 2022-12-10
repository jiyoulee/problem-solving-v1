#include <bits/stdc++.h>
using namespace std;

int N, M;
long long sum;
int a[10001];

bool good(int x) { // x is the upper limit enforced on the suburb budgets.
	sum = 0;
	
	for (int i = 1; i <= N; i++) {
		if (x <= a[i]) {
			sum += x;
		}
		else {
			sum += a[i];
		}
	}
	
	return M >= sum;
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", a + i);
	}
	scanf("%d", &M);
	
	// Do binary search (l oooxxx r).
	int l = 1;
	int r = *max_element(a + 1, a + N + 1);
	int h;
	while (l <= r) {
		h = (l + r) / 2;
		
		if (good(h)) {
			l = h + 1;
		}
		else {
			r = h - 1;
		}
	}
	
	printf("%d", r);
	
	return 0;
}
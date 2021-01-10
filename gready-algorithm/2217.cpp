#include <bits/stdc++.h>
using namespace std;

int ans;
int N;
int a[100001];

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", a+i);
	}
	
	/*
	 * 1) The maximum mass a chosen set of x ropes with y being the smallest rope length, connected, can support is x * y.
	 * 2) The maximum mass a chosen set of ropes with y being the smallest rope length, connected, is max(x) * y = (number of ropes whose length is greater than or equal to y) * y.
	 */
	sort(a + 1, a + 1 + N);
	for (int i = N; i >= 1; i--) {
		ans = max(ans, a[i] * (N - i + 1));
	}
	
	printf("%d", ans);
	
	return 0;
}
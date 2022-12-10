#include <bits/stdc++.h>
using namespace std;

int N, tmp = 1, ans = 1;
int a[5001];

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", a + i);
	}
	
	/*
	 * 1. The length of a sequence that begins at a[n] and ends at a[i] is i-n+1.
	 * 1. The maximum length of a sequence that ends at a[i] is the length of the sequence with minimum n (i.e. that begins at the left-most possible a[n]).
	 */
	for (int n = 2; n <= N - 1; n++) { // n is the index of the beginning of a sequence.
		tmp++;
		if ((N - 1) == n) {
			if (!(a[N - 2] <= a[N - 1] && a[N - 1] <= a[N]) && !(a[N - 2] >= a[N - 1] && a[N - 1] >= a[N])) {
				tmp++;
			}
			ans = max(ans, tmp);
		}
		else {
			if ((a[n - 1] <= a[n] && a[n] <= a[n + 1]) || (a[n - 1] >= a[n] && a[n] >= a[n + 1])) {
				ans = max(ans, tmp);
				tmp = 1;
			}
		}
	}
	
	printf("%d", ans);
	
	return 0;
}

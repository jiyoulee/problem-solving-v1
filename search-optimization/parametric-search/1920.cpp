#include <bits/stdc++.h>
using namespace std;

int N, M, x
int l, r, h;
int ans;
int a[100001];

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", a + i);
	}
	
	// Sort array before binary search.
	sort(a + 1, a + 1 + N);
	
	scanf("%d", &M);
	while (M--) {
		scanf("%d", &x);
		
		// Do binary search.
		l = 1;						// Reset left end.
		r = N;						// Reset right end.
		ans = 0;					// Reset answer.
		
		while (l <= r) {			// Check if range is valid.
			h = (l + r) / 2;		// Get halfway point of range.
			if (a[h] == x) {		// Halfway point is equal to the number we are searching for.
				ans = 1;
				break;
			}
			else if (a[h] < x) {	// Halfway point is smaller than the nubmer we are searching for.
				l = h + 1;
			}
			else {					// Halfway point is greater than the nubmer we are searching for.
				r = h - 1;
			}				
		}
		
		printf("%d\n", ans);
	}
	
	return 0;
}
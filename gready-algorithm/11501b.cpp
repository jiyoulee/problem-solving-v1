#include <bits/stdc++.h>
using namespace std;

int T, N;
long long ans;
int a[1000001];
int b[1000001];
int c[10001];

int main() {
	scanf("%d", &T);
	
	while (T--) {
		ans = 0;
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) {
			scanf("%d", a + i);
		}
		for (int i = 1; i <= N; i++) {
			b[i] = a[i];
			c[b[i]]++;
		}
		sort(b + 1, b + 1 + N);
		
		int n = 1;
		for (int i = N; i >= 1; i--) {
			if (0 < c[b[i]]) {
				while(n <= N) {
					if (a[n] == b[i]) {
						c[b[i]]--;
						n++;
						break;
					}
					ans += b[i] - a[n];
					c[a[n]]--;
					n++;
				}
			}
		}
		
		printf("%lld\n", ans);
	}
	
	return 0;
}
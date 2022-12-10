#include <bits/stdc++.h>
using namespace std;

int T, N, M;
long long ans;
int a[1000001];

int main() {
	scanf("%d", &T);
	
	while (T--) {
		ans = 0;
		M = 0;
		scanf("%d",&N);
		for (int i = 1; i <= N; i++) {
			scanf("%d", a + i);
		}
		
		for (int i = N; i >= 1; i--) {
			M = max(M, a[i]);
			ans += M - a[i];
		}
		
		printf("%lld\n", ans);
	}
	
	return 0;
}
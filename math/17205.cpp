#include <bits/stdc++.h>
using namespace std;

int N, alen;
long long ans;
char a[11];
long long p[10];

int main() {
	scanf("%d%s", &N, a + 1);
	for (int i = N - 1; i >= 0; i--) {
		p[i] = pow(26, i);
	}
	
	alen = strlen(a + 1);
	for (int i = 1; i <= alen; i++) {
		for (int j = 0; j <= N - i; j++) {
			ans += (a[i] - 'a') * p[j];
			ans += 1;
		}
	}
	
	printf("%lld\n", ans);

	return 0;
}
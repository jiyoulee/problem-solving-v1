#include <bits/stdc++.h>
using namespace std;

#define M 1000000007

long N;
long long ans = 1;

int main() {
	scanf("%d", &N);
	
	/*
	 * For each array of cups, the ith unswapped cup is swapped with a cup out of N - 2 * i + 1 cups.
	 */
	for (int i = 1; i <= N / 2; i++) {
		ans = (ans * ((N - 2 * i + 1) % M)) % M;
	}
	
	printf("%lld", ans);
	
	return 0;
}
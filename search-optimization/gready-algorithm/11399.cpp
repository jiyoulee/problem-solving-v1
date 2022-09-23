#include <bits/stdc++.h>
using namespace std;

int N, sum, ans;
int a[1001];

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", a + i);
	}
	
	/*
	 * The total time taken given a list of N times is sigma(sum from the first time to the ith time) = sigma((N - i + 1) * ith time).
	 * The maximum total time taken given a list of N times is the total time taken after sorting the given list in increasing order.
	 */
	sort(a + 1, a + 1 + N);
	for (int i = 1; i <= N; i++) { // i is the index of the ith largest time
		sum += a[i];
		ans += sum;
	}
	
	printf("%d", ans);
	
	return 0;
}
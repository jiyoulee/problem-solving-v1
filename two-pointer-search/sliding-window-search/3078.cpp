#include <bits/stdc++.h>
using namespace std;

int N, K;
long long ans;
char A[21];
int name_length[300001];
long long name_length_count[21];

int main() {
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%s", A + 1);
		name_length[i] = strlen(A + 1);
	}

	/*
	 * Calculate for first window.
	 */
	for (int i = 1; i < K; i++) {
		name_length_count[name_length[i]] += 1;
	}
	for (int i = 2; i <= 20; i++) {
		ans += name_length_count[i] * (name_length_count[i] - 1) / 2;
	}

	/*
	 * Calculate for rest of windows.
	 */
	for (int i = K; i <= N; i++) {
		ans += name_length_count[name_length[i]];
		
		name_length_count[name_length[i]] += 1;							//    [ --- ][X]
		name_length_count[name_length[i-K]] -= 1;						// [X][ --- ]
	}

	printf("%lld", ans);

	return 0;
}
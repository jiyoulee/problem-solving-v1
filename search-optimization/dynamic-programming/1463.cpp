/*
 * Title: 1로 만들기
 * Link: https://www.acmicpc.net/problem/1463
 */

#include <cstdio>
#include <algorithm>

using namespace std;

constexpr int MAX_N = 1000000;

int N;
int dp[1 + MAX_N];

int main(int argc, char** argv) {
	scanf("%d", &N);

	dp[3] = dp[2] = 1;
	for (int i = 4; N >= i; ++i) {
		dp[i] = dp[i - 1] + 1;
		if (0 == i % 3) {
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
		if (0 == i % 2) {
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}
	}

	printf("%d", dp[N]);

	return 0;
}
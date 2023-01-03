/*
 * Title: 2xn 타일링 2
 * Link: https://www.acmicpc.net/problem/11727
 */

#include <cstdio>

using namespace std;

constexpr int MAX_N = 1000;
constexpr int DIV = 10007;

int N;
int dp[1 + MAX_N];

int main() {
	/*
	 * Input.
	 */
	scanf("%d\n", &N);

	/* 
	 * Compute (memoization).
	 */
	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; N >= i; ++i) {
	   dp[i] = (dp[i - 1] + (2 * dp[i - 2]) % DIV) % DIV;
	}

	/*
	 * Output.
	 */
	printf("%d", dp[N]);

    return 0;
}
/*
 * Title: 동전 0
 * Link: https://www.acmicpc.net/problem/11047
 */

#include <cstdio>

using namespace std;

constexpr int MAX_N = 10;

int ans;
int N, K;
int A[MAX_N];

int main() {
	scanf("%d%d", &N, &K);
    for (int i = 0; N > i; ++i) {
        scanf("%d", &A[i]);
    }

    for (int i = N - 1; 0 <= i; --i) {
        ans += K / A[i];
        K %= A[i];
    }

    printf("%d", ans);

	return 0;
}
/*
 * Title: Subsequence
 * Link: https://www.acmicpc.net/problem/1806
 */

#include <cstdio>
#include <algorithm>

using namespace std;

constexpr int MAX_N = 100000;
constexpr int INF = 987654321;

int ans = INF, val;
int N, S;
int A[MAX_N];

int main() {
    scanf("%d%d", &N, &S);

	int j = 0;
    for (int i = 0; N > i; ++i) {
		scanf("%d", &A[i]);
		
		val += A[i];

		if (val >= S) {
			while (val >= S) {
				val -= A[j++];
			}
			val += A[--j];

			ans = min(ans, i - j + 1);
		}
    }

	printf("%d", (INF == ans) ? 0 : ans);

	return 0;
}
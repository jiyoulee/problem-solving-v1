/*
 * Title: Padovan Sequence
 * Link: https://www.acmicpc.net/problem/9461
 */

#include <cstdio>

using namespace std;

constexpr int MAX_N = 100;

int T, N;
long long dp[1 + MAX_N];

int main(int argc, char** argv) {
   dp[1] = 1;
   dp[2] = 1;
   dp[3] = 1;
   dp[4] = 2;
   dp[5] = 2;

   for (int i = 6; MAX_N >= i; ++i) {
      dp[i] = dp[i - 1] + dp[i - 5];
   }

   scanf("%d", &T);

   while (T--) {
      scanf("%d", &N);

      printf("%lld\n", dp[N]);
   }

   return 0;
}
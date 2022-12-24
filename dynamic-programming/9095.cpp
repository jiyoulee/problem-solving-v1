/*
 * Title: Adding 1s, 2s, and 3s
 * Link: https://www.acmicpc.net/problem/9095
 */

#include <cstdio>

using namespace std;

constexpr int MAX_INT = 10;

int T, N;
int dp[1 + MAX_INT];

int main(int argc, char** argv) {
   dp[1] = 1;
   dp[2] = 2;
   dp[3] = 4;
   for (int i = 4; MAX_INT >= i; ++i) {
      dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
   }

   scanf("%d", &T);

   while (T--) {
      scanf("%d", &N);

      printf("%d\n", dp[N]);
   }

   return 0;
}
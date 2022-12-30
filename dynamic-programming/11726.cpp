/*
 * Title: 2xn 타일링
 * Link: https://www.acmicpc.net/problem/11726
 */

#include <cstdio>

using namespace std;

constexpr int MAX_N = 1000;
constexpr int DIV = 10007;

int answer;
int N;
int dp[1 + MAX_N][1 + MAX_N];

int main(int argc, char** argv) {
   /*
    * Precompute (memoization).
    */
   for (int i = 1; MAX_N >= i; ++i) {
      dp[i][i] = dp[i][0] = 1;

      for (int j = 1; i > j; ++j) {
         dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % DIV;
      }
   }

   /*
    * Input.
    */
   scanf("%d", &N);

   /*
    * Compute.
    */
   for (int i = N, j = 0; i >= j; i--, j++) {
      answer += dp[i][j];
      answer %= DIV;
   }

   /*
    * Output.
    */
   printf("%d", answer);

   return 0;
}
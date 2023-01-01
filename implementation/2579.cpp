/*
 * Title: 계단 오르기
 * Link: https://www.acmicpc.net/problem/2579
 */

#include <cstdio>
#include <algorithm>

using namespace std;

constexpr int MAX_N = 300;

int N;
int A[1 + MAX_N];
int dp[1 + MAX_N];

int main() {
   /*
    * Input.
    */
   scanf("%d", &N);

   for (int i = 1; N >= i; ++i) {
      scanf("%d", &A[i]);
   }

   /*
    * Compute.
    */
   dp[1] = A[1];
   dp[2] = A[1] + A[2];

   for (int i = 3; N >= i; ++i) {
      dp[i] = max(dp[i - 2], dp[i - 3] + A[i - 1]) + A[i];
   }

   /*
    * Output.
    */
   printf("%d", dp[N]);

   return 0;
}
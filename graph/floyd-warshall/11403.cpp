/*
 * Problem: 경로 찾기
 * Tags: graph-theory, graph-traversal, floyd-warshall
 * Link: https://www.acmicpc.net/problem/11403
 *
 * Author: jiyoulee
 * Solved: 2023-01-08
 */

#include <cstdio>
#include <algorithm>

using namespace std;

constexpr int INF = 987654321;
constexpr int MAX_N = 100;

int N;
int dp[MAX_N][MAX_N];

int main() {
   /*
    * Input.
    */
   scanf("%d", &N);

   for (int i = 0; N > i; ++i) {
      for (int j = 0; N > j; ++j) {
         scanf("%d", &dp[i][j]);

         if (!dp[i][j]) {
            dp[i][j] = INF;
         }
      }
   }

   /*
    * Compute.
    */
   for (int k = 0; N > k; ++k) {
      for (int i = 0; N > i; ++i) {
         for (int j = 0; N > j; ++j) {
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
         }
      }
   }

   /*
    * Output.
    */
   for (int i = 0; N > i; ++i) {
      for (int j = 0; N > j; ++j) {
         if (INF == dp[i][j]) {
            printf("0 ");
         }
         else {
            printf("1 ");
         }
      }
      printf("\n");
   }

   return 0;
}
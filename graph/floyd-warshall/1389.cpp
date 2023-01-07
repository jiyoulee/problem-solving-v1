/*
 * Problem: 케빈 베이컨의 6단게 법칙
 * Tags: graph-theory, graph-traversal, breadth-first-search, floyd-warshall
 * Link: https://www.acmicpc.net/problem/1389
 *
 * Author: jiyoulee
 * Solved: 2023-01-04
 */

#include <cstdio>
#include <algorithm>

using namespace std;

constexpr int MAX_N = 100;
constexpr int MAX_M = 5000;
constexpr int INF = 987654321;

int answer, glb_sum = INF;
int N, M;
int G[1 + MAX_N][1 + MAX_N];

int main() {
   /*
    * Input.
    */
   scanf("%d%d", &N, &M);

   for (int u, v; M--; ) {
      scanf("%d%d", &u, &v);

      G[u][v] = 1;
      G[v][u] = 1;
   }

   /*
    * Compute.
    */
   for (int i = 1; N >= i; ++i) {
      for (int j = 1; N >= j; ++j) {
         if (i != j && !G[i][j]) {
            G[i][j] = INF;
         }
      }
   }
   for (int k = 1; N >= k; ++k) {
      for (int i = 1; N >= i; ++i) {
         for (int j = 1; N >= j; ++j) {
            G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
         }
      }
   }

   /*
    * Output.
    */
   for (int i = N, loc_sum; i; --i) {
      loc_sum = 0;
      for (int j = 1; N >= j; ++j) {
         loc_sum += G[i][j];
      }

      if (loc_sum <= glb_sum) {
         glb_sum = loc_sum;
         answer = i;
      }
   }
   printf("%d", answer);

   return 0;
}
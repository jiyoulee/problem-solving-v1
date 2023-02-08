/*
 * Problem: 종이의 개수
 * Tags: divide-and-conquer, recursion
 * Link: https://www.acmicpc.net/problem/1780
 *
 * Author: jiyoulee
 * Solved: 2023-01-04
 */

#include <cstdio>

using namespace std;

constexpr int MAX_N = 2187;

int answer[3];
int N;
int G[MAX_N][MAX_N];

void dc(int x, int y, int n); // (x, y): coordinates of upper-left-most point of search space, n: length of side of search space

int main() {
   /*
    * Input.
    */
   scanf("%d", &N);

   for (int i = 0; N > i; ++i) {
      for (int j = 0; N > j; ++j) {
         scanf("%d", &G[i][j]);
      }
   }

   /*
    * Compute.
    */
   dc(0, 0, N);

   /*
    * Output.
    */
   for (int i = 0; 3 > i; ++i) {
      printf("%d\n", answer[i]);
   }

   return 0;
}

void dc(int x, int y, int n) {
   for (int i = x, endi = x + n; endi > i; ++i) {
      for (int j = y, endj = y + n; endj > j; ++j) {
         if (G[x][y] != G[i][j]) {
            int m = n / 3;

            for (int p = 0; 3 > p; ++p) {
               for (int q = 0; 3 > q; ++q) {
                  dc(x + p * m, y + q * m, m);
               }
            }

            return;
         }
      }
   }

   ++answer[G[x][y] + 1];

   return;
}
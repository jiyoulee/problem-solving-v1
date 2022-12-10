/*
 * Title: N과 M (2)
 * Link: https://www.acmicpc.net/problem/15650
 */

#include <cstdio>

using namespace std;

constexpr int MAX_M = 8;

int N, M;
int track[MAX_M];

void go(int m, int k) {
   if (M == m) {
      for (int i = 0; M > i; ++i) {
         printf("%d ", track[i]);
      }
      printf("\n");

      return;
   }

   for (int i = k; N >= i; ++i) {
      track[m] = i;
      go(m + 1, i + 1);
   }

   return;
}

int main(int argc, char** argv) {
   scanf("%d%d", &N, &M);

   go(0, 1);

   return 0;
}
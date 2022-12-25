/*
 * Title: 통계학
 * Link: https://www.acmicpc.net/problem/2108
 */

#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

constexpr int MAX_N = 500000;
constexpr int MAX_A = 4000;

int N;
int A[MAX_N];
int cnt[1 + 2 * MAX_A];
int val, max_cnt = -1;

int main(int argc, char** argv) {
   /*
    * Input.
    */
   scanf("%d", &N);

   for (int i = 0; N > i; ++i) {
      scanf("%d", &A[i]);
      val += A[i];
      ++cnt[MAX_A + A[i]];
   }

   /*
    * Compute (arithmetic) mean.
    */
   printf("%d\n", (int)round((double)val / N));

   /*
    * Compute median.
    */
   sort(A, A + N);
   printf("%d\n", A[N / 2]);

   /*
    * Compute mode.
    */
   val = 0;
   for (int i = MAX_A + A[N - 1], end = MAX_A + A[0]; end <= i; --i) {
      if (cnt[i] >= max_cnt) {
         max_cnt = cnt[i];
         val = i;
      }
   }
   for (int i = MAX_A + A[0], end = MAX_A + A[N - 1]; end >= i; ++i) {
      if (max_cnt == cnt[i] && val != i) {
         val = i;
         break;
      }
   }
   printf("%d\n", val - MAX_A);

   /*
    * Compute range.
    */
   printf("%d\n", A[N - 1] - A[0]);

   return 0;
}
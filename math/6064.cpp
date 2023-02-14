/*
 * Problem: Cain Calendar
 * Tags: mathematics, number-theory, chinese-remainder-theorem
 * Link: https://www.acmicpc.net/problem/6064
 *
 * Author: jiyoulee
 * Solved: 2023-01-07
 */

#include <cstdio>
#include <algorithm>

using namespace std;

int T;
int answer = -1;
int M, N, X, Y;

int gcd(int a, int b);

int main() {
   scanf("%d", &T);

   while (T--) {
      /*
       * Input.
       */
      scanf("%d%d%d%d", &M, &N, &X, &Y);

      /*
       * Compute.
       */
      if (M < N) {
         swap(M, N);
         swap(X, Y);
      }

      for (int i = 0, lcm = M / gcd(M, N) * N; lcm >= (M * i + X) && -1 == answer; ++i) {
         if (0 == (((M * i + X) - Y) % N)) {
            answer = M * i + X;
         }
      }

      /*
       * Output.
       */
      printf("%d\n", answer);

      /*
       * Reset.
       */
      answer = -1;
   }

   return 0;
}

int gcd(int a, int b) {
   if (b == 0) {
      return a;
   }

   return gcd(b, a % b);
}
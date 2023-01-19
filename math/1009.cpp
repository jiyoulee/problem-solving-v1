/*
 * Problem: 분산처리
 * Tags: mathematics, implementation
 * Link: https://www.acmicpc.net/problem/1009
 *
 * Author: jiyoulee
 * Solved: 2023-01-19
 */

#include <cstdio>

using namespace std;

int answer;
int T;
int A, B;

int main() {
   scanf("%d", &T);

   while (T--) {
      /*
       * Input.
       */
      scanf("%d%d", &A, &B);

      /*
       * Compute.
       */
      for (answer = 1; B--;) {
         answer *= A;
         answer %= 10;
      }

      /*
       * Output.
       */
      printf("%d\n", answer ? answer : 10);
   }

   return 0;
}
/*
 * Problem: 수 정렬하기 3
 * Tags: sorting
 * Link: https://www.acmicpc.net/problem/10989
 *
 * Author: jiyoulee
 * Solved: 2022-12-25
 */

#include <cstdio>

constexpr int MAX_VAL = 10000;

int N;
int cnt[1 + MAX_VAL];

int main(int argc, char** argv) {
   /*
    * Input.
    */
   scanf("%d", &N);

   /*
    * Compute.
    */
   for (int i = 0, val; N > i; ++i) {
      scanf("%d", &val);

      ++cnt[val];
   }

   /*
    * Output.
    */
   for (int i = 1; MAX_VAL >= i; ++i) {
      for (int j = 0; cnt[i] > j; ++j) {
         printf("%d\n", i);
      }
   }

   return 0;
}
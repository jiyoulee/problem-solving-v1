/*
 * Problem: 하얀 칸
 * Tags: implementation, string
 * Link: https://www.acmicpc.net/problem/1100
 *
 * Author: jiyoulee
 * Solved: 2023-01-23
 */

#include <cstdio>

using namespace std;

int answer;
char C;
int G_LEN = 8;

int main() {
   for (int i = 0; G_LEN > i; ++i) {
      for (int j = 0; G_LEN > j; ++j) {
         /*
          * Input.
          */
         scanf(" %c", &C);

         /*
          * Compute.
          */
         if (!((i & 1) ^ (j & 1)) && 'F' == C) {
            ++answer;
         }
      }
   }

   /*
    * Output.
    */
   printf("%d", answer);

   return 0;
}
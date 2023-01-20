/*
 * Problem: 팰린드롬 만들기
 * Tags: implementation, string, greedy
 * Link: https://www.acmicpc.net/problem/1213
 *
 * Author: jiyoulee
 * Solved: 2023-01-20
 */

#include <cstdio>
#include <cstring>

using namespace std;

constexpr int MAX_STR_LEN = 50;

char answer[MAX_STR_LEN + 1];
char A[MAX_STR_LEN + 1];
int cnt[26];

int main() {
   /*
    * Input.
    */
   scanf("%s", A);

   /*
    * Compute.
    */
   for (int i = 0; A[i]; ++i) {
      ++cnt[A[i] - 'A'];
   }

   for (int i = 0, is_valid = 0; 26 > i; ++i) {
      if (cnt[i] & 1) {
         ++is_valid;
      }

      if (1 < is_valid) {
         printf("I'm Sorry Hansoo");

         return 0;
      }
   }

   for (int i = 0, j = 0, l = strlen(A) - 1; 26 > i; ++i) {
      while (0 < cnt[i]) {
         if (1 == cnt[i]) {
            answer[l / 2] = 'A' + i;
         }
         else {
            answer[l - j] = answer[j] = 'A' + i;
            ++j;
         }

         cnt[i] -= 2;
      }
   }

   /*
    * Output.
    */
   printf("%s", answer);

   return 0;
}
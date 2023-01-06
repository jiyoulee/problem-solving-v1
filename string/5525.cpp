/*
 * Problem: IOIOI
 * Tags: string
 * Link: https://www.acmicpc.net/problem/5525
 *
 * Author: jiyoulee
 * Solved: 2023-01-06
 */

 #include <cstdio>
#include <cstring>

using namespace std;

constexpr int MAX_M = 1000000;
constexpr int MAX_N = 1000000;

int answer;
int N, M;
char str[MAX_M + 2];
int p[1 + MAX_N];

int main() {
   /*
    * Input.
    */
   scanf("%d%d%s", &N, &M, str);

   /*
    * Compute.
    */
   str[M + 1] = '\0';

   for (int i = 0, tmp; str[i]; ) {
      if ('I' == str[i++]) {
         for (tmp = 0; str[i] && 'O' == str[i] && 'I' == str[i + 1]; ++tmp, i += 2) {}

         if (tmp) {
            ++p[tmp];
         }
      }
   }

   /*
    * Output.
    */
   for (int i = N; MAX_N >= i; ++i) {
      if (p[i]) {
         answer += p[i] * (i - N + 1);
      }
   }
   printf("%d", answer);

   return 0;
} 
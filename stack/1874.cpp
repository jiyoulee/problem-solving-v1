/*
 * Problem: 스택 수열
 * Tags: data-structures, stack
 * Link: https://www.acmicpc.net/problem/1874
 *
 * Author: jiyoulee
 * Solved: 2022-12-25
 */

#include <cstdio>

using namespace std;

constexpr int MAX_N = 100000;

char answer[2 * MAX_N];
int N;
int stack[1 + MAX_N];
int top;
int cnt;

int main(int argc, char** argv) {
   /*
    * Input.
    */
   scanf("%d", &N);

   /*
    * Computation.
    */
   for (int i = 0, A, val = 1; N > i; ++i) {
      scanf("%d", &A);

      while (val <= A) {
         stack[++top] = val++;
         answer[cnt++] = '+';
      }

      /*
       * Output (failed).
       */
      if (!top || stack[top] != A) {
         printf("NO");

         return 0;
      }

      --top;
      answer[cnt++] = '-';
   }

   /*
    * Output (successful).
    */
   for (int i = 0; cnt > i; ++i) {
      printf("%c\n", answer[i]);
   }

   return 0;
}
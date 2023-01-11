/*
 * Title: 영화감독 숌
 * Tags: brute-forcing
 * Link: https://www.acmicpc.net/problem/1436
 *
 * Author: jiyoulee
 * Solved: 2022-12-25
 */

#include <cstdio>

using namespace std;

constexpr int NUMBER_OF_THE_BEAST = 666;

int N;
int i = NUMBER_OF_THE_BEAST, cnt = 0;

int main(int argc, char** argv) {
   /*
    * Input.
    */
   scanf("%d", &N);

   /*
    * Compute.
    */
   for (int k; N != cnt; ++i) {
      k = i;

      while (k) {
         if (NUMBER_OF_THE_BEAST == k % 1000) {
            ++cnt;
            break;
         }

         k /= 10;
      }
   }

   /*
    * Output.
    */
   printf("%d", i - 1);

   return 0;
}
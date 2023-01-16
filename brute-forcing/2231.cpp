/*
 * Problem: Digit Generator
 * Tags: brute-forcing
 * Link: https://www.acmicpc.net/problem/2231
 *
 * Author: jiyoulee
 * Solved: 2022-12-25
 */

#include <cstdio>

using namespace std;

constexpr int INF = 1987654321;
constexpr int MAX_N = 1000000;

int answer = INF;
int N;

int main(int argc, char** argv) {
	/*
	 * Input.
	 */
   scanf("%d", &N);

   /*
    * Compute.
    */
   for (int i = 1, n, tmp; N >= i; ++i) {
      tmp = i;

      for (n = i; n; n /= 10) {
         tmp += n % 10;
      }

      if (N == tmp) {
         if (tmp < answer) {
            answer = i;
         }
      }
   }

   /*
    * Output.
    */
   printf("%d", (INF == answer) ? 0 : answer);

   return 0;
}
/*
 * Problem: Pyramids
 * Tags: mathematics, implementation, arithmetic
 * Link: https://www.acmicpc.net/problem/5341
 *
 * Author: jiyoulee
 * Solved: 2023-01-17
 */

#include <cstdio>

using namespace std;

long long N;

int main() {
   for (scanf("%lld", &N); N; scanf("%lld", &N)) {
      printf("%lld\n", N * (N + 1) / 2);
   }

   return 0;
}
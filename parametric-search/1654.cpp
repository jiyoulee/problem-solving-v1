/*
 * Problem: 랜선 자르기
 * Tags: binary-search, parametric-search
 * Link: https://www.acmicpc.net/problem/1654
 *
 * Author: jiyoulee
 * Solved: 2022-12-25
 */

#include <cstdio>
#include <cmath>

using namespace std;

constexpr int MAX_K = 10000;

int answer;
int K, N;
int A[MAX_K];
long long l, r, m;

bool f(int length);

int main(int argc, char** argv) {
   /*
    * Input.
    */
   scanf("%d%d", &K, &N);

   for (int i = 0; K > i; ++i) {
      scanf("%d", &A[i]);
   }

   /*
    * Compute.
    */
   l = -1, r = pow(2, 31) - 1;

   while (l != r) {
      m = r - (r - l) / 2;
      f(m) ? l = m : r = m - 1;
   }

   /*
    * Output.
    */
   printf("%lld", r);

   return 0;
}

bool f(int length) {
   long long cnt = 0;

   for (int i = 0; K > i && N > cnt; ++i) {
      cnt += A[i] / length;
   }

   return N <= cnt;
}

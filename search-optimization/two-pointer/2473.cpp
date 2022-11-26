/*
 * Title: 세 용액
 * Link: https://www.acmicpc.net/problem/2473
 */

#include <cstdio>
#include <algorithm>

using namespace std;

constexpr int MAX_N= 5000;
constexpr long long MAX_VAL = 3000000001;

long long answer[3];
int N;
long long val = MAX_VAL, tmp;
int l, r;
long long A[MAX_N];

int main(int argc, char** argv) {
   scanf("%d", &N);

   for (int i = 0; N > i; ++i) {
      scanf("%lld", &A[i]);
   }
   sort(A, A + N);

   for (int i = 0; N > i; ++i) {
      l = i + 1;
      r = N - 1;

      while (l < r) {
         tmp = A[i] + A[l] + A[r];

         if (0 == tmp) {
            printf("%lld %lld %lld", A[i], A[l], A[r]);

            return 0;
         }

         if (val > abs(tmp)) {
            val = abs(tmp);
            answer[0] = A[i];
            answer[1] = A[l];
            answer[2] = A[r];
         }

         if (0 > tmp) {
            ++l;
         }
         else {
            --r;
         }

      }
   }

   printf("%lld %lld %lld", answer[0], answer[1], answer[2]);

   return 0;
}
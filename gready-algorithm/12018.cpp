/*
 * Title: Yonsei TOTO
 * Link: https://www.acmicpc.net/problem/12018
 */

#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

constexpr int MAX_N = 100;
constexpr int MAX_P = 100;

int answer;
int N, M, P, L;
int A[MAX_P];
int B[MAX_N];

int main(int argc, char** argv) {
   scanf("%d%d", &N, &M);

   for (int i = 0; N > i; ++i) {
      scanf("%d%d", &P, &L);

      if (L > P) {
         for (int j = 0; P > j; ++j) {
            scanf("%d", &A[0]);
         }

         B[i] = 1;
      }
      else {
         for (int j = 0; P > j; ++j) {
            scanf("%d", &A[j]);
         }
         sort(A, A + P, greater<int>());

         B[i] = A[L - 1];
      }
   }
   sort(B, B + N);

   for (int i = 0; N > i && M >= B[i]; ++i) {
      ++answer;

      M -= B[i];
   }
   printf("%d", answer);

   return 0;
}
/*
 * Title: 트로피 진열
 * Link: https://www.acmicpc.net/problem/1668
 */

#include <cstdio>
#include <algorithm>

using namespace std;

constexpr int MAX_N = 50;

int answer;
int N;
int trophy;
int trophies[50];

int main(int argc, char** argv) {
   scanf("%d", &N);

   for (int i = 0; N > i; ++i) {
      scanf("%d", &trophies[i]);
   }

   answer = 1;
   trophy = trophies[0];
   for (int i = 1; N > i; ++i) {
      if (trophy < trophies[i]) {
         ++answer;
         trophy = trophies[i];
      }
   }
   printf("%d ", answer);

   answer = 1;
   trophy = trophies[N - 1];
   for (int i = N - 2; 0 <= i; --i) {
      if (trophy < trophies[i]) {
         ++answer;
         trophy = trophies[i];
      }
   }
   printf("%d", answer);   

   return 0;
}
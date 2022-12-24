/*
 * Title: 연결 요소의 개수
 * Link: https://www.acmicpc.net/problem/11724
 */

#include <cstdio>

using namespace std;

constexpr int MAX_N = 1000;

int answer;
int N, M;
int u, v;
int parents[1 + MAX_N];

int find(int n) {
   if (!parents[n]) {
      return n;
   }

   return parents[n] = find(parents[n]);
}

void merge(int a, int b) {
   int A = find(a);
   int B = find(b);

   if (B != A) {
      parents[B] = A;
   }

   return;
}

int main(int argc, char** argv) {
   scanf("%d%d", &N, &M);

   while (M--) {
      scanf("%d%d", &u, &v);

      merge(u,v);
   }

   for (int i = 1; N >= i; ++i) {
      if (!parents[i]) {
         ++answer;
      }
   }

   printf("%d", answer);

   return 0;
}
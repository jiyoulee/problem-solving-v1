/*
 * Title: Four Squares
 * Link: https://www.acmicpc.net/problem/17626
 */

#include <cstdio>

using namespace std;

constexpr int MAX_K = 223;

int answer = 4;
int N;
int endk = 1;
int K[1 + MAX_K];

void dfs(int pos, int sum, int depth);

int main() {
   /*
    * Input.
    */
   scanf("%d", &N);

   /*
    * Compute.
    */
   for (; N >= endk * endk; ++endk) {
      K[endk] = endk * endk;
   }
   --endk;

   dfs(1, 0, 0);

   /*
    * Output.
    */
   printf("%d", answer);

   return 0;
}

void dfs(int pos, int sum, int depth) {
   if (N == sum) {
      if (depth < answer) {
         answer = depth;
      }

      return;
   }
   if (3 == depth || endk < pos) {
      return;
   }

   for (int i = pos; endk >= i; ++i) {
      dfs(i, sum + K[i], depth + 1);
   }

   return;
}
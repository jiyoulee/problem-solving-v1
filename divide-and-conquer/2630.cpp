/*
 * Title: 색종이 만들기
 * Link: https://www.acmicpc.net/problem/2630
 */

#include <cstdio>

using namespace std;

constexpr int MAX_N = 128;

int answer[2];
int N;
int G[MAX_N][MAX_N];

void dc(int x, int y, int n); // (x, y): coordinates of upper-left-most point of square, n: length of side of square

int main() {
   /*
    * Input.
    */
   scanf("%d", &N);

   for (int i = 0; N > i; ++i) {
      for (int j = 0; N > j; ++j) {
         scanf("%d", &G[i][j]);
      }
   }

   /*
    * Compute.
    */
   dc(0, 0, N);

   /*
    * Output.
    */
   printf("%d\n%d", answer[0], answer[1]);

   return 0;
}

void dc(int x, int y, int n) {
   for (int i = x, endi = x + n; endi > i; ++i) {
      for (int j = y, endj = y + n; endj > j; ++j) {
         if (G[x][y] != G[i][j]) {
            dc(x, y, n / 2);
            dc(x + n / 2, y, n / 2);
            dc(x, y + n / 2, n / 2);
            dc(x + n / 2, y + n / 2, n / 2);

            return;
         }
      }
   }
   
   ++answer[G[x][y]];

   return;
}
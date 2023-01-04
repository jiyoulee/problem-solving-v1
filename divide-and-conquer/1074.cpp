/*
 * Title: Z
 * Link: https://www.acmicpc.net/problem/1074
 */

#include <cstdio>

using namespace std;

int answer;
int N, R, C;

bool dc(int x, int y, int n); // (x, y): coordinates of upper-left-most point of search space, n: length of side of search space

int main() {
   /*
    * Input.
    */
   scanf("%d%d%d", &N, &R, &C);

   /*
    * Compute.
    */
   dc(0, 0, 1 << N);

   /*
    * Output.
    */
   printf("%d", answer);

   return 0;
}

bool dc(int x, int y, int n) {
   if (R == x && C == y) {
      return true;
   }
   if (R >= x && R < x + n && C >= y && C < y + n) {
      return dc(x, y, n >> 1) || dc(x, y + (n >> 1), n >> 1) || dc(x + (n >> 1), y, n >> 1) || dc(x + (n >> 1), y + (n >> 1), (n >> 1));
   }
   
   answer += n * n;

   return false;
}
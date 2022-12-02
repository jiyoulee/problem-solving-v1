/*
 * Title: 투명
 * Link: https://www.acmicpc.net/problem/1531
 */

#include <cstdio>

using namespace std;

constexpr int P_LENGTH = 100;

int answer;
int N, M;
int x1, x2, y1, y2;
int P[1 + P_LENGTH][1 + P_LENGTH];

int main(int argc, char** argv) {
   scanf("%d%d", &N, &M);

   while (N--) {
      scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

      for (int i = x1; x2 >= i; ++i) {
         for (int j = y1; y2 >= j; ++j) {
            ++P[i][j];
         }
      }
   }

   for (int i = 1; P_LENGTH >= i; ++i) {
      for (int j = 1; P_LENGTH >= j; ++j) {
         if (M < P[i][j]) {
            ++answer;
         }
      }
   }
   printf("%d", answer);

   return 0;
}
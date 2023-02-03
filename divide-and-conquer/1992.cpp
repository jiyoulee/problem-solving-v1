/*
 * Problem: 쿼드트리
 * Tags: divide-and-conquer, recursion
 * Link: https://www.acmicpc.net/problem/1992
 *
 * Author: jiyoulee
 * Solved: 2023-01-05
 */

#include <cstdio>
#include <vector>

using namespace std;

constexpr int MAX_N = 64;

int N;
char G[MAX_N][MAX_N + 1];
vector<char> stack;

void dc(int x, int y, int n);

int main() {
   /*
    * Input.
    */
   scanf("%d", &N);

   for (int i = 0; N > i; ++i) {
      scanf("%s", G[i]);
   }

   /*
    * Compute.
    */
   dc(0, 0, N);

   /*
    * Output.
    */
   for (auto& element : stack) {
      printf("%c", element);
   }

   return 0;
}

void dc(int x, int y, int n) {
   for (int i = x, endi = x + n; endi > i; ++i) {
      for (int j = y, endj = y + n; endj > j; ++j) {
         if (G[x][y] != G[i][j]) {
            int m = n / 2;

            stack.emplace_back('(');
            for (int p = 0; 2 > p; ++p) {
               for (int q = 0; 2 > q; ++q) {
                  dc(x + p * m, y + q * m, m);
               }
            }
            stack.emplace_back(')');
            
            return;
         }
      }
   }

   stack.emplace_back(G[x][y]);

   return;
}
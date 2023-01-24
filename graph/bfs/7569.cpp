/*
 * Problem: 토마토
 * Tags: graph-theory, graph-traversal, breadth-first-search
 * Link: https://www.acmicpc.net/problem/7569
 *
 * Author: jiyoulee
 * Solved: 2023-01-24
 */

#include <cstdio>
#include <tuple>
#include <queue>
#include <cstring>

using namespace std;

constexpr int MAX_M = 100;
constexpr int MAX_N = 100;
constexpr int MAX_H = 100;
constexpr int dz[6] = {1, -1, 0, 0, 0, 0};
constexpr int dx[6] = {0, 0, 0, 0, 1, -1};
constexpr int dy[6] = {0, 0, -1, 1, 0, 0};

int answer;
int M, N, H;
int G[1 + MAX_H + 1][1 + MAX_M + 1][1 + MAX_N + 1];
queue<tuple<int, int, int>> q;

int main() {
   /*
    * Preset.
    */
   memset(G, -1, sizeof(G));

   /*
    * Input.
    */
   scanf("%d%d%d", &M, &N, &H);

   for (int z = 1; H >= z; ++z) {
      for (int x = 1; N >= x; ++x) {
         for (int y = 1; M >= y; ++y) {
            scanf("%d", &G[z][x][y]);

            if (1 == G[z][x][y]) {
               q.emplace(z, x, y);
            }
         }
      }
   }

   /*
    * Compute.
    */
   for (int z, x, y, nz, nx, ny; !q.empty(); ++answer) {
      for (int i = 0, endi = q.size(); endi > i; ++i) {
         z = get<0>(q.front());
         x = get<1>(q.front());
         y = get<2>(q.front());

         q.pop();

         for (int j = 0; 6 > j; ++j) {
            nz = z + dz[j];
            nx = x + dx[j];
            ny = y + dy[j];

            if (0 == G[nz][nx][ny]) {
               G[nz][nx][ny] = 1;
               q.emplace(nz, nx, ny);
            }
         }
      }
   }


   /*
    * Output.
    */
   for (int z = 1; H >= z; ++z) {
      for (int x = 1; N >= x; ++x) {
         for (int y = 1; M >= y; ++y) {
            if (0 == G[z][x][y]) {
               printf("-1");

               return 0;
            }
         }
      }
   }

   printf("%d", answer - 1);

   return 0;
}
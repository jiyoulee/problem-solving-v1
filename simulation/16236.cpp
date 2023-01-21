/*
 * Problem: 아기 상어
 * Tags: implementation, graph-theory, graph-traversal, breadth-first-search, simulation
 * Link: https://www.acmicpc.net/problem/16236
 *
 * Author: jiyoulee
 * Solved: 2023-01-21
 */

#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

constexpr int MAX_N = 20;
constexpr int dx[4] = {-1, 0, 0, 1};
constexpr int dy[4] = {0, -1, 1, 0};

int answer;
int N;
int X, Y, NX, NY;
int G[1 + MAX_N + 1][1 + MAX_N + 1];
int size = 2, cnt, d = 1;
queue<pair<int,int>> q;
bool fish, has_eaten;
bool visited[1 + MAX_N + 1][1 + MAX_N + 1];

int main() {
   /*
    * Preset.
    */
   memset(G, -1, sizeof(G));

   /*
    * Input.
    */
   scanf("%d", &N);
   NY = NX = N + 1;

   for (int i = 1; N >= i; ++i) {
      for (int j = 1; N >= j; ++j) {
         scanf("%d", &G[i][j]);

         if (9 == G[i][j]) {
            X = i;
            Y = j;

            G[i][j] = 0;
         }
      }
   }

   /*
    * Compute.
    */
   while (true) {
      visited[X][Y] = true;
      q.emplace(X, Y);

      for (int x, y, nx, ny; !q.empty() && !has_eaten; ++d) {
         /*
          * Find fish to eat at distance d.
          */
         for (int i = 0, endi = q.size(); endi > i; ++i) {
            x = q.front().first;
            y = q.front().second;

            q.pop();

            for (int k = 0; 4 > k; ++k) {
               nx = x + dx[k];
               ny = y + dy[k];

               if (0 <= G[nx][ny] && !visited[nx][ny] && size >= G[nx][ny]) {
                  if (0 != G[nx][ny] && size != G[nx][ny]) {
                     if (NX > nx || (NX == nx && NY > ny)) {
                        NX = nx;
                        NY = ny;
                     }

                     fish = true;
                  }
                  else {
                     visited[nx][ny] = true;
                     q.emplace(nx, ny);
                  }
               }
            }
         }

         /*
          * Move and eat fish if found.
          */
         if (fish) {
            answer += d;

            X = NX;
            Y = NY;
            G[NX][NY] = 0;
            has_eaten = true;

            if (size == ++cnt) {
               ++size;
               cnt = 0;
            }
         }
      }

      if (!has_eaten) {
         break;
      }

      NY = NX = N + 1;
      d = 1;
      has_eaten = fish = false;
      q = queue<pair<int,int>>();
      memset(visited, false, sizeof(visited));
   }

   /*
    * Output.
    */
   printf("%d", answer);

   return 0;
}
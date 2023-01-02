/*
 * Title: 미로 탐색
 * Link: https://www.acmicpc.net/problem/2178
 */

#include <cstdio>
#include <queue>
#include <tuple>

using namespace std;

constexpr int MAX_N = 100;
constexpr int MAX_M = 100;
constexpr int dx[4] = {0, 0, -1, 1};
constexpr int dy[4] = {1, -1, 0, 0};

int N, M;
char G[1 + MAX_N + 1][1 + MAX_M + 1];
queue<tuple<int,int,int>> q;
int visited[1 + MAX_N + 1][1 + MAX_M + 1];

int main() {
   /*
    * Input.
    */
   scanf("%d%d", &N, &M);

   for (int i = 1; N >= i; ++i) {
      scanf("%s", G[i] + 1);
   }

   /*
    * Compute.
    */
   q.emplace(1, 1, 1);
   visited[1][1] = true;

   for (int nx, ny; !q.empty() && !(N == get<0>(q.front()) && M == get<1>(q.front())); ) {
      for (int i = 0, x, y, t, endi = q.size(); endi > i && !(N == get<0>(q.front()) && M == get<1>(q.front())); ++i) {
         x = get<0>(q.front());
         y = get<1>(q.front());
         t = get<2>(q.front());
         
         for (int j = 0, nx, ny; 4 > j; ++j) {
            nx = x + dx[j];
            ny = y + dy[j];

            if (!visited[nx][ny] && '1' == G[nx][ny]) {
               visited[nx][ny] = true;
               q.emplace(nx, ny, t + 1);
            }
         }

         q.pop();
      }
   }

   /*
    * Output.
    */
   printf("%d",  get<2>(q.front()));

   return 0;
}
/*
 * Title: 유기농 배추
 * Link: https://www.acmicpc.net/problem/1012
 */

#include <cstdio>
#include <cstring>

using namespace std;

constexpr int MAX_M = 50;
constexpr int MAX_N = 50;
constexpr int dx[4] = {-1, 1, 0, 0};
constexpr int dy[4] = {0, 0, -1, 1};

int answer;
int T, M, N, K;
bool cabbages[MAX_M][MAX_N];
bool visited[MAX_M][MAX_N];

void dfs(int x, int y) {
   visited[x][y] = true;

   for (int i = 0, nx, ny; 4 > i; ++i) {
      nx = x + dx[i];
      ny = y + dy[i];

      if (0 <= nx && M > nx && 0 <= ny && N > ny && cabbages[nx][ny] && !visited[nx][ny]) {
         dfs(nx, ny);
      }
   }

   return;
}

int main(int argc, char** argv) {
   scanf("%d", &T);

   while (T--) {
      scanf("%d%d%d", &M, &N, &K);

      for (int i = 0, x, y; K > i; ++i) {
         scanf("%d%d", &x, &y);

         cabbages[x][y] = true;
      }

      for (int i = 0; M > i; ++i) {
         for (int j = 0; N > j; ++j) {
            if (cabbages[i][j] && !visited[i][j]) {
               answer++;

               dfs(i, j);
            }
         }
      }

      printf("%d\n", answer);

      answer = 0;
      memset(cabbages, false, sizeof(cabbages));
      memset(visited, false, sizeof(visited));
   }

   return 0;
}
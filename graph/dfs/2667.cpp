/*
 * Problem: 단지번호붙이기
 * Tags: graph-theory, graph-traversal, breadth-first-search, depth-first-search
 * Link: https://www.acmicpc.net/problem/2667
 *
 * Author: jiyoulee
 * Solved: 2023-01-02
 */

#include <cstdio>
#include <algorithm>

using namespace std;

constexpr int MAX_N = 25;
constexpr int dx[4] = {-1, 1, 0, 0};
constexpr int dy[4] = {0, 0, -1, 1};

int N;
char G[1 + MAX_N + 1][1 + MAX_N + 1];
bool visited[1 + MAX_N + 1][1 + MAX_N + 1];
int block_cnt, house_cnt;
int houses[MAX_N * MAX_N];

void dfs(int x, int y);

int main() {
   /*
    * Input.
    */
   scanf("%d", &N);

   for (int i = 1; N >= i; ++i) {
      scanf("%s", &G[i][1]);
   }

   /*
    * Compute.
    */
   for (int i = 1; N >= i; ++i) {
      for (int j = 1; N >= j; ++j, house_cnt = 0) {
         if (!visited[i][j] && '1' == G[i][j]) {
            dfs(i, j);

            houses[block_cnt++] = house_cnt;
         }
      }
   }

   /*
    * Output.
    */
   sort(houses, houses + block_cnt);

   printf("%d\n", block_cnt);
   for (int i = 0; block_cnt > i; ++i) {
      printf("%d\n", houses[i]);
   }

   return 0;
}

void dfs(int x, int y) {
   ++house_cnt;

   visited[x][y] = true;

   for (int i = 0, nx, ny; 4 > i; ++i) {
      nx = x + dx[i];
      ny = y + dy[i];

      if (!visited[nx][ny] && '1' == G[nx][ny]) {
         dfs(nx, ny);
      }
   }

   return;
}
/*
 * Title: Cow Art
 * Link: https://www.acmicpc.net/problem/10026
 */

#include <cstdio>
#include <cstring>

using namespace std;

constexpr int MAX_N = 100;
constexpr int dx[4] = {-1, 1, 0, 0};
constexpr int dy[4] = {0, 0, -1, 1};

int answer;
int N;
char G[MAX_N + 2][MAX_N + 2];
bool is_valid[MAX_N + 2][MAX_N + 2];

void dfs(int x, int y) {
   is_valid[x][y] = true;

   for (int i = 0, nx, ny; 4 > i; ++i) {
      nx = x + dx[i];
      ny = y + dy[i];

      if (!is_valid[nx][ny] && G[x][y] == G[nx][ny]) {
         dfs(nx, ny);
      }
   }  

   return;
}   

int main(int argc, char** argv) {
   scanf("%d", &N);

   for (int i = 1; N >= i; ++i) {
      scanf("%s", &G[i][1]);
   }

   /*
    * Count regions viewed by human.
    */
   for (int i = 1; N >= i; ++i) {
      for (int j = 1; N >= j; ++j) {
         if (!is_valid[i][j]) {
            ++answer;

            dfs(i, j);
         }
      }
   }

   printf("%d ", answer);

   answer = 0;
   for (int i = 1; N >= i; ++i) {
      for (int j = 1; N >= j; ++j) {
         if ('R' == G[i][j]) {
            G[i][j] = 'G';
         }
      }
   }
   memset(is_valid, false, sizeof(is_valid));

   /*
    * Count regions viewed by cow.
    */
   for (int i = 1; N >= i; ++i) {
      for (int j = 1; N >= j; ++j) {
         if (!is_valid[i][j]) {
            ++answer;

            dfs(i, j);
         }
      }
   }

   printf("%d", answer);

   return 0;
}
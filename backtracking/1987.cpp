/*
 * Title: Letters
 * Link: https://www.acmicpc.net/problem/1987
 */

#include <cstdio>

using namespace std;

constexpr int MAX_R = 20;
constexpr int MAX_C = 20;
constexpr int dx[4] = {-1, 1, 0, 0};
constexpr int dy[4] = {0, 0, -1, 1};

int answer;
int R, C;
char tmp;
int G[MAX_R][MAX_C];
bool visited[26];

void go(int x, int y, int cnt) {
   int nx, ny;
   
   for (int i = 0; 4 > i; ++i) {
      nx = x + dx[i];
      ny = y + dy[i];

      if (0 <= nx && R > nx && 0 <= ny && C > ny) {
         if (visited[G[nx][ny]]) {
            if (answer < cnt) {
               answer = cnt;
            }
         }
         else {
            visited[G[nx][ny]] = true;
            go(nx, ny, cnt + 1);
            visited[G[nx][ny]] = false;
         }
      }
   }

   return;
}

int main(int argc, char** argv) {
   scanf("%d%d", &R, &C);

   for (int i = 0; R > i; ++i) {
      for (int j = 0; C > j; ++j) {
         scanf(" %c", &tmp);

         G[i][j] = tmp - 'A';
      }
   }

   visited[G[0][0]] = true;
   go(0, 0, 0);

   printf("%d", answer + 1);

   return 0;
}
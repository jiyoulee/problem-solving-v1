/*
 * Problem: 킹
 * Tags: implementation, simulation
 * Link: https://www.acmicpc.net/problem/1063
 *
 * Author: jiyoulee
 * Solved: 2023-01-15
 */

#include <cstdio>

using namespace std;

constexpr int dx[8] = {0, 0, -1, 1, 1, 1, -1, -1};
constexpr int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

char L[2][3];
int N;
int kx, ky, sx, sy;
char cmd[3];

void move(int dir);

int main() {
   /*
    * Input.
    */
   scanf("%s %s%d", L[0], L[1], &N);
   
   /*
    * Compute.
    */
   kx = L[0][1] - '0';
   ky = L[0][0] - 'A' + 1;
   sx = L[1][1] - '0';
   sy = L[1][0] - 'A' + 1;

   while (N--) {
      scanf("%s", cmd);

      if ('\0' == cmd[1]) {
         if ('R' == cmd[0]) {
            move(0);
         }
         else if ('L' == cmd[0]) {
            move(1);
         }
         else if ('B' == cmd[0]) {
            move(2);
         }
         else {
            move(3);
         }
      }
      else {
         if ('R' == cmd[0] && 'T' == cmd[1]) {
            move(4);
         }
         else if ('L' == cmd[0] && 'T' == cmd[1]) {
            move(5);
         }
         else if ('R' == cmd[0] && 'B' == cmd[1]) {
            move(6);
         }
         else {
            move(7);
         }
      }
   }

   /*
    * Output.
    */
   L[0][1] = kx + '0';
   L[0][0] = ky + 'A' - 1;
   L[1][1] = sx + '0';
   L[1][0] = sy + 'A' - 1;

   printf("%s\n%s", L[0], L[1]);

   return 0;
}

void move(int dir) {
   int knx = kx + dx[dir];
   int kny = ky + dy[dir];

   if (knx == sx && kny == sy) {
      int snx = sx + dx[dir];
      int sny = sy + dy[dir];

      if (1 <= snx && 8 >= snx && 1 <= sny && 8 >= sny) {
         kx = knx;
         ky = kny;
         sx = snx;
         sy = sny;
      }
   }
   else {
      if (1 <= knx && 8 >= knx && 1 <= kny && 8 >= kny) {
         kx = knx;
         ky = kny;
      }
   }

   return;
}
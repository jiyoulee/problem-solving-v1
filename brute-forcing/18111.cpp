/*
 * Problem: 마인크래프트
 * Tags: implementation, brute-forcing
 * Link: https://www.acmicpc.net/problem/18111
 *
 * Author: jiyoulee
 * Solved: 2022-12-24
 */

#include <cstdio>

using namespace std;

constexpr int INF = 1987654321;
constexpr int INF_MINUS = -1987654321;
constexpr int MAX_N = 500;
constexpr int MAX_M = 500;
constexpr int MAX_HEIGHT = 256;

int N, M, B;
int min_time = INF, max_height = INF_MINUS;
int heights[MAX_N * MAX_M];

int main(int argc, char** argv) {
   /*
    * Input.
    */
   scanf("%d%d%d", &N, &M, &B);

   int NM = N * M;

   for (int i = 0; NM > i; ++i) {
      scanf("%d", &heights[i]);
   }

   /*
    * Compute.
    */
   for (int i = 0, time, b; MAX_HEIGHT >= i; ++i) {
      time = 0, b = B;

      for (int j = 0, val; NM > j && time <= min_time; ++j) {
         val = heights[j] - i;

         b += val;
         if (0 <= val) {
            time += 2 * val;
         }
         else {
            time -= val;
         }
      }

      if (0 <= b) {
         if (time < min_time) {
            min_time = time;
            max_height = i;
         }
         else if (time == min_time) {
            if (i > max_height) {
               max_height = i;
            }
         }
      }
   }

   /*
    * Output.
    */
   printf("%d %d", min_time, max_height);

   return 0;
}
/*
 * Title: Rugby Club
 * Tags: implementation
 * Link: https://www.acmicpc.net/problem/2083
 *
 * Author: jiyoulee
 * Solved: 2023-01-22
 */

#include <cstdio>

using namespace std;

constexpr int NAME_MAX_LEN = 10;

char name[NAME_MAX_LEN + 1];
int age, weight;

int main() {
   while (true) {
      /*
       * Input.
       */
      scanf("%s%d%d", name, &age, &weight);

      if (!age) {
         break;
      }

      /*
       * Output.
       */
      printf("%s %s\n", name, (17 < age || 80 <= weight) ? "Senior" : "Junior");
   }

   return 0;
}
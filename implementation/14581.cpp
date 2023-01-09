/*
 * Problem: 팬들에게 둘러싸인 홍준
 * Tags: implementation
 * Link: https://www.acmicpc.net/problem/14581
 *
 * Author: jiyoulee
 * Solved: 2023-01-09
 */

#include <cstdio>

using namespace std;

constexpr int MAX_LEN_A = 20;

char A[MAX_LEN_A + 1];

int main() {
   /*
    * Input.
    */
   scanf("%s", A);

   /*
    * Output.
    */
   printf(":fan::fan::fan:\n:fan::%s::fan:\n:fan::fan::fan:", A);

   return 0;
}
/*
 * Title: RIJEČI
 * Link: https://www.acmicpc.net/problem/9625
 */

#include <cstdio>
#include <algorithm>

using namespace std;

int answer[2] = {0, 1};
int K;

int main(int argc, char** argv) {
   scanf("%d", &K);

   while (--K) {
      swap(answer[0], answer[1]);
      answer[1] += answer[0];
   }

   printf("%d %d", answer[0], answer[1]);

   return 0;
}
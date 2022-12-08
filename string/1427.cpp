/*
 * Title: 소트인사이드
 * Link: https://www.acmicpc.net/problem/1427
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>

using namespace std;

constexpr int MAX_DIGIT_CNT = 10;

char N[MAX_DIGIT_CNT + 1];
int digit_cnt;

int main(int argc, char** argv) {
   scanf("%s", N);

   digit_cnt = strlen(N);

   sort(N, N + digit_cnt, greater<int>());
   
   for (int i = 0; digit_cnt > i; ++i) {
      printf("%c", N[i]);
   }

   return 0;
}
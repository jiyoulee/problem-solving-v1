/*
 * Title: 눈 치우기
 * Link: https://www.acmicpc.net/problem/26215
 */

#include <cstdio>
#include <queue>

using namespace std;

constexpr int MAX_ANSWER = 1440;

int answer;
int N;
int a1, a2;
priority_queue<int> max_pq;

int main(int argc, char** argv) {
   scanf("%d", &N);

   for (int i = 1, tmp; N >= i; ++i) {
      scanf("%d", &tmp);

      max_pq.emplace(tmp);
   }

   while (!max_pq.empty() && MAX_ANSWER >= answer) {
      if (1 == max_pq.size()) {
         answer += max_pq.top();
         
         max_pq.pop();
      }
      else {
         ++answer;

         a1 = max_pq.top() - 1;
         max_pq.pop();
         a2 = max_pq.top() - 1;
         max_pq.pop();
         if (a1) {
            max_pq.emplace(a1);
         }
         if (a2) {
            max_pq.emplace(a2);
         }
      }
   }

   printf("%d", (MAX_ANSWER < answer) ? -1 : answer);

   return 0;
}
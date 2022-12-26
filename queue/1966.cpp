/*
 * Title: Printer Queue
 * Link: https://www.acmicpc.net/problem/1966
 */

#include <cstdio>
#include <queue>

using namespace std;

int answer = 1;
int T;
int N, M;
queue<pair<int,int>> q;
priority_queue<int> max_pq;

int main(int argc, char** argv) {
   scanf("%d", &T);

   while (T--) {
      /*
       * Input.
       */
      scanf("%d%d", &N, &M);

      for (int i = 0, val; N > i; ++i) {
         scanf("%d", &val);

         q.emplace(val, i);
         max_pq.emplace(val);
      }

      /*
       * Compute.
       */
      while (true) {
         if (max_pq.top() == q.front().first) {
            if (M == q.front().second) {
               break;
            }

            max_pq.pop();
            ++answer;
         }
         else {
            q.emplace(q.front().first, q.front().second);
         }

         q.pop();
      }
      
      /*
       * Output.
       */
      printf("%d\n", answer);

      /*
       * Reset.
       */
      answer = 1;
      q = queue<pair<int,int>>();
      max_pq = priority_queue<int>();
   }

   return 0;
}
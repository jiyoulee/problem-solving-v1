/*
 * Title: 절댓값 힙
 * Link: https://www.acmicpc.net/problem/11286
 */

#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp {
   bool operator() (const int a, const int b) const {
      if (abs(a) == abs(b)) {
         return a > b;
      }

      return abs(a) > abs(b);
   }
};

int N;
int x;
priority_queue<int,vector<int>,cmp> min_pq;

int main(int argc, char** argv) {
   scanf("%d", &N);

   while (N--) {
      scanf("%d", &x);

      if (x) {
         min_pq.emplace(x);
      }
      else {
         if (min_pq.empty()) {
            printf("0\n");
         }
         else {
            printf("%d\n", min_pq.top());

            min_pq.pop();
         }
      }
   } 

   return 0;
}
/*
 * Problem: Dual Priority Queue
 * Tags: data-structures, set/map-by-trees, priority-queue
 * Link: https://www.acmicpc.net/problem/7662
 *
 * Author: jiyoulee
 * Solved: 2022-12-29
 */

#include <cstdio>
#include <queue>
#include <functional>
#include <cstring>

using namespace std;

constexpr int MAX_K = 1000000;

int T, K;
char cmd;
int cnt, val;
priority_queue<pair<int,int>> max_pq;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min_pq;
bool is_valid[MAX_K];

int main() {
  scanf("%d", &T);

  while (T--) {
    /*
     * Input.
     */
    scanf("%d", &K);

    /*
     * Compute.
     */
    while(K--) {
      scanf(" %c%d", &cmd, &val);
      
      if ('I' == cmd) {
        max_pq.emplace(val, cnt);
        min_pq.emplace(val, cnt);

        is_valid[cnt++] = true;
      }
      else {
        if (1 == val) {
          while (!max_pq.empty() && !is_valid[max_pq.top().second]) {
            max_pq.pop();
          }

          if (!max_pq.empty()) {
            is_valid[max_pq.top().second] = false;
            max_pq.pop();
          }
        }
        else {
          while (!min_pq.empty() && !is_valid[min_pq.top().second]) {
            min_pq.pop();
          }

          if (!min_pq.empty()) {
            is_valid[min_pq.top().second] = false;
            min_pq.pop();
          }
        }
      }
    }

    /*
     * Output.
     */
    while (!max_pq.empty() && !is_valid[max_pq.top().second]) {
      max_pq.pop();
    }

    if (max_pq.empty()) {
      printf("EMPTY\n");
    }
    else {
      while (!min_pq.empty() && !is_valid[min_pq.top().second]) {
        min_pq.pop();
      }

      printf("%d %d\n", max_pq.top().first, min_pq.top().first);

      max_pq = priority_queue<pair<int,int>>();
      min_pq = priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>();
    }
    
    /*
     * Reset
     */
    cnt = 0;
    memset(is_valid, false, sizeof(bool) * cnt);
  }

  return 0;
}
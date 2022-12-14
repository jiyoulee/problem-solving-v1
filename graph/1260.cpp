/*
 * Title: DFS와 BFS
 * Link: https://www.acmicpc.net/problem/1260
 */

#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

constexpr int MAX_N = 1000;

int N, M, V;
vector<int> G[1 + MAX_N];
int visited[1 + MAX_N];
queue<int> q;

void dfs(int n) {
   printf("%d ", n);
   visited[n] = true;

   for (auto& c : G[n]) {
      if (!visited[c]) {
         dfs(c);
      }
   }

   return;
}

int main(int argc, char** argv) {
   scanf("%d%d%d", &N, &M, &V);

   for (int i = 0, U, V; M > i; ++i) {
      scanf("%d%d", &U, &V);

      G[U].emplace_back(V);
      G[V].emplace_back(U);
   }
   for (int i = 1; N >= i; ++i) {
      sort(G[i].begin(), G[i].end());
   }

   dfs(V);
   
   printf("\n");
   memset(visited, false, sizeof(visited));

   /*
    * bfs(V)
    */
   q.emplace(V);
   visited[V] = true;
   while (!q.empty()) {
      printf("%d ", q.front());

      for (auto& c : G[q.front()]) {
         if (!visited[c]) {
            visited[c] = true;

            q.emplace(c);
         }
      }

      q.pop();
   }

   return 0;
}
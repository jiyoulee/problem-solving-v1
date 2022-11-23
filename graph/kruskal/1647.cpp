/*
 * Title: 도시 분할 계획
 * Link: https://www.acmicpc.net/problem/1647
 */

#include <cstdio>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

constexpr int MAX_N = 100000;
constexpr int MAX_M = 1000000;

int answer;
int max_C;
int N, M, A, B, C;
vector<tuple<int, int, int>> edges;
int parents[1 + MAX_N];

int find(int n) {
   if (!parents[n]) {
      return n;
   }

   return parents[n] = find(parents[n]);
}

bool merge(int a, int b) {
   int A = find(a);
   int B = find(b);

   if (A != B) {
      parents[B] = A;
   }

   return A != B;
}

int main(int argc, char** argv) {
   scanf("%d%d", &N, &M);

   for (int i = 0; M > i; ++i) {
      scanf("%d%d%d", &A, &B, &C);

      edges.emplace_back(C, A, B);
   }

   sort(edges.begin(), edges.end());

   for (auto& edge : edges) {
      if (merge(get<1>(edge), get<2>(edge))) {
         answer += get<0>(edge);
         
         if (max_C < get<0>(edge)) {
            max_C = get<0>(edge);
         }
      }
   }

   printf("%d", answer - max_C);

   return 0;
}
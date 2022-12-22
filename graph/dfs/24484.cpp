/*
 * Title: 알고리즘 수업 - 깊이 우선 탐색 6
 * Link: https://www.acmicpc.net/problem/24484
 */

#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

constexpr int MAX_N = 100000;

long long answer;
int N, M, R;
long long t = 1;
vector<int> G[1 + MAX_N];
bool visited[1 + MAX_N];

void dfs(int n, int d) {
    answer += t++ * d;
    visited[n] = true;

    sort(G[n].begin(), G[n].end(), greater<int>());

    for (auto& c : G[n]) {
        if (!visited[c]) {
            dfs(c, d + 1);
        }
    }

    return;
}

int main(int argc, char** argv) {
    scanf("%d%d%d", &N, &M, &R);

    for (int i = 0, u, v; M > i; ++i) {
        scanf("%d%d", &u, &v);

        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    dfs(R, 0);

    printf("%lld", answer);

    return 0;
}
/*
 * Problem: 트리의 부모 찾기
 * Tags: graph-theory, graph-traversal, tree, breadth-first-search, depth-first-search
 * Link: https://www.acmicpc.net/problem/11725
 *
 * Author: jiyoulee
 * Solved: 2023-02-07
 */

#include <cstdio>
#include <vector>

using namespace std;

constexpr int MAX_N = 100000;

int answer[1 + MAX_N];
int N;
vector<int> G[1 + MAX_N];
bool visited[1 + MAX_N];

void dfs(int n);

int main() {
    /*
     * Input.
     */
    scanf("%d", &N);

    for (int i = 0, U, V; N > i; ++i) {
        scanf("%d%d", &U, &V);

        G[U].emplace_back(V);
        G[V].emplace_back(U);
    }

    /*
     * Compute.
     */
    dfs(1);

    /*
     * Output.
     */
    for (int i = 2; N >= i; ++i) {
        printf("%d\n", answer[i]);
    }

    return 0;
}

void dfs(int n) {
    visited[n] = true;

    for (auto& e : G[n]) {
        if (!visited[e]) {
            answer[e] = n;
            dfs(e);
        }
    }

    return;
}
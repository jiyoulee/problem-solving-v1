/*
 * Problem: 숨바꼭질
 * Tags: graph-theory, graph-traversal, breadth-first-search, dijkstra, 0-1-breadth-first-search
 * Link: https://www.acmicpc.net/problem/13549
 *
 * Author: jiyoulee
 * Solved: 2023-02-25
 */

#include <cstdio>
#include <queue>
#include <functional>

using namespace std;

constexpr int MAX_X = 100000;
constexpr int MIN_X = 0;

int N, K;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min_pq;
bool visited[MAX_X + 10];

int main() {
    /*
     * Input.
     */
    scanf("%d%d", &N, &K);

    /*
     * Compute.
     */
    if (K >= N) {
        min_pq.emplace(0, N);
        visited[N] = true;

        for (int node, ts; !min_pq.empty() && K != min_pq.top().second; ) {
            ts = min_pq.top().first;
            node = min_pq.top().second;

            min_pq.pop();

            if (MAX_X >= (node << 1) && !visited[node << 1]) {
                visited[node << 1] = true;
                min_pq.emplace(ts, node << 1);
            }
            if (MAX_X >= node + 1 && !visited[node + 1]) {
                visited[node + 1] = true;
                min_pq.emplace(ts + 1, node + 1);
            }
            if (MIN_X <= node - 1 && !visited[node - 1]) {
                visited[node - 1] = true;
                min_pq.emplace(ts + 1, node - 1);
            }
        }
    }

    /*
     * Output.
     */
    printf("%d", (K < N) ? (N - K) : min_pq.top().first);

    return 0;
}
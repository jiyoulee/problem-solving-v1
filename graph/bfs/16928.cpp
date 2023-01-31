/*
 * Problem: 뱀과 사다리 게임
 * Tags: graph-theory, graph-traversal, breadth-first-search
 * Link: https://www.acmicpc.net/problem/16928
 *
 * Author: jiyoulee
 * Solved: 2023-01-31
 */

#include <cstdio>
#include <queue>

using namespace std;

constexpr int INF = 101;
constexpr int MAX_SQUARE_NUM = 100;

int N, M;
int roads[1 + MAX_SQUARE_NUM];
queue<pair<int,int>> q;
bool visited[1 + MAX_SQUARE_NUM];

int main() {
    /*
     * Input.
     */
    scanf("%d%d", &N, &M);

    for (int U, V, i = N + M; i; --i) {
        scanf("%d%d", &U, &V);

        roads[U] = V;
    }

    /*
     * Compute and Output.
     */
    q.emplace(1, 0);

    for (int pos, npos, nts; !q.empty(); ) {
        pos = q.front().first;
        nts = q.front().second + 1;

        q.pop();

        for (int i = 1; 6 >= i; ++i) {
            npos = pos + i;

            if (MAX_SQUARE_NUM == npos) {
                printf("%d", nts);

                return 0;
            }

            if (MAX_SQUARE_NUM > npos) {
                if (roads[npos]) {
                    npos = roads[npos];
                }

                if (!visited[npos]) {
                    visited[npos] = true;
                    q.emplace(npos, nts);
                }
            }
        }
    }

    return 0;
}
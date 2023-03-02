/*
 * Problem: 치킨 배달
 * Tags: implementation, brute-forcing, backtracking
 * Link: https://www.acmicpc.net/problem/15686
 *
 * Author: jiyoulee
 * Solved: 2023-03-02
 */

#include <cstdio>
#include <vector>
#include <algorithm>

#define TARGET 1
#define SOURCE 2

using namespace std;

constexpr int INF = 1 << 30;
constexpr int MAX_M = 13;

int answer = INF;
int N, M;
vector<pair<int,int>> nodes[3];
pair<int,int> list[MAX_M];

void go(int index, int depth);

int main() {
    /*
     * Input.
     */
    scanf("%d%d", &N, &M);

    for (int i = 1, tmp; N >= i; ++i) {
        for (int j = 1; N >= j; ++j) {
            scanf("%d", &tmp);

            if (tmp) {
                nodes[tmp].emplace_back(i, j);
            }
        }
    }

    /*
     * Compute.
     */
    go(0, 0);

    /*
     * Output.
     */
    printf("%d", answer);

    return 0;
}

void go(int index, int depth) {
    if (M == depth) {
        int tmp_answer = 0, tmp_dist;

        for (auto& [x, y] : nodes[TARGET]) {
            tmp_dist = INF;

            for (int i = 0; M > i; ++i) {
                tmp_dist = min(tmp_dist, abs(x - list[i].first) + abs(y - list[i].second));
            }

            tmp_answer += tmp_dist;
        }

        if (tmp_answer < answer) {
            answer = tmp_answer;
        }

        return;
    }

    for (int i = index, endi = nodes[SOURCE].size(); endi > i; ++i) {
        list[depth] = nodes[SOURCE][i];

        go(i + 1, depth + 1);
    }

    return;
}
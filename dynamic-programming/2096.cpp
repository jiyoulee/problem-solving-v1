/*
 * Problem: 내려가기
 * Tags: dynamic-programming, sliding-window
 * Link: https://www.acmicpc.net/problem/2096
 *
 * Author: jiyoulee
 * Solved: 2023-02-21
 */

#include <cstdio>
#include <algorithm>

using namespace std;

constexpr int INF = 1987654321;
constexpr int MAX_N = 100000;
constexpr int MAX_ROW = 2;
constexpr int MAX_COL = 3;

int answer[MAX_ROW][1 + MAX_COL + 1];
int N;

int main() {
    /*
     * Input.
     */
    scanf("%d", &N);

    /*
     * Compute.
     */
    answer[0][MAX_COL + 1] = answer[0][0] = INF;

    for (int tmp[MAX_ROW][1 + MAX_COL + 1], val; N--; ) {
        for (int i = 1; MAX_COL >= i; ++i) {
            tmp[0][i] = min({answer[0][i - 1], answer[0][i], answer[0][i + 1]});
            tmp[1][i] = max({answer[1][i - 1], answer[1][i], answer[1][i + 1]});
        }

        for (int j = 1; MAX_COL >= j; ++j) {
            scanf("%d", &val);

            for (int i = 0; MAX_ROW > i; ++i) {
                answer[i][j] = tmp[i][j] + val;
            }
        }
    }

    /*
     * Output.
     */
    printf("%d %d", max({answer[1][1], answer[1][2], answer[1][3]}), min({answer[0][1], answer[0][2], answer[0][3]}));

    return 0;
}
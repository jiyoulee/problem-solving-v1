/*
 * Title: 스타트와 링크
 * Link: https://www.acmicpc.net/problem/14889
 */

#include <cstdio>
#include <algorithm>

using namespace std;

constexpr int MAX_N = 20;
constexpr int MAX_M = 10;
constexpr int INF = 987654321;

int ans = INF, new_ans;
int N, M;
int S[MAX_N][MAX_N];
bool visited[MAX_N];
int tmp;

void go(int depth, int cur) {
    /*
     * In the event a team formation is completed, update answer.
     */
    if (M == depth) {
        int new_ans = 0;

        for (int i = 0; N > i; ++i) {
            for (int j = i + 1; N > j; ++j) {
                if (visited[i] && visited[j]) {
                    new_ans += S[i][j];
                    new_ans += S[j][i];
                }
                else if (!visited[i] && !visited[j]) {
                    new_ans -= S[i][j];
                    new_ans -= S[j][i];
                }
            }
        }

        ans = min(ans, abs(new_ans));

        return;
    }

    /*
     * Continue building the teams.
     */
    for (int i = cur; N > i; ++i) {
        visited[i] = true;
        go(depth + 1, i + 1);
        visited[i] = false;
    }

    return;
}

int main(int argc, char** argv) {
    /*
     * Get input.
     */
    scanf("%d", &N);
    M = N / 2;
    for (int i = 0; N > i; ++i) {
        for (int j = 0; N > j; ++j) {
            scanf("%d", &S[i][j]);
        }
    }

    /*
     * Review all possible team formations.
     */
    visited[0] = true;
    go(1, 1);

    printf("%d", ans);
    printf(" %d", tmp);

    return 0;
}
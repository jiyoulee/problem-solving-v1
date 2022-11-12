/*
 * Title: RGB거리 2
 * Link: https://www.acmicpc.net/problem/17404
 */

#include <cstdio>
#include <algorithm>

using namespace std;

constexpr int MAX_N = 1000;
constexpr int INF = MAX_N * MAX_N + 1;

int answer = INF;
int N;
int cost[1 + MAX_N][3];
int dp[1 + MAX_N][3];

int main(int argc, char** argv) {
    /*
     * Get painting costs.
     */
    scanf("%d", &N);
    for (int i = 1; N >= i; ++i) {
        for (int j = 0; 2 >= j; ++j) {
            scanf("%d", &cost[i][j]);
        }
    }

    /*
     * Tabulate with color of first house fixed.
     */
    for (int k = 0; 2 >= k; ++k) {
        for (int i = 0; 2 >= i; ++i) {
            if (k == i) {
                dp[1][i] = cost[1][k];
            }
            else {
                dp[1][i] = INF;
            }
        }
        
        for (int i = 2; N >= i; ++i) {
            for (int j = 0; 2 >= j; ++j) {
                dp[i][j] = min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + cost[i][j];
            }
        }
        
        for (int i = 0; 2 >= i; ++i) {
            if (k != i) {
                answer = min(answer, dp[N][i]);
            }
        }
    }

    /*
     * Output answer.
     */
    printf("%d", answer);

    return 0;
}
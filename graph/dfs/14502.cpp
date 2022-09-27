/*
 * Title: 연구소
 * Link: https://www.acmicpc.net/problem/14502
 */

#include <cstdio>
#include <algorithm>

using namespace std;

constexpr int MAX_N = 8;
constexpr int MAX_M = 8;
constexpr int MIN_VIRUS_CNT = 2;
constexpr int MAX_VIRUS_CNT = 10;

int answer, new_answer;
int N, M;
int grid[MAX_N][MAX_M];
int temp_grid[MAX_N][MAX_M];
int safe_squares_cnt, virus_squares_cnt;
int safe_squares[MAX_N * MAX_M - MIN_VIRUS_CNT][2];
int virus_squares[MAX_VIRUS_CNT][2];

void dfs(int x, int y) {
    if (0 <= x - 1 && 0 == temp_grid[x - 1][y]) {
        temp_grid[x - 1][y] = 2;
        dfs(x - 1, y);
    }
    if (N > x + 1 && 0 == temp_grid[x + 1][y]) {
        temp_grid[x + 1][y] = 2;
        dfs(x + 1, y);
    }
    if (0 <= y - 1 && 0 == temp_grid[x][y - 1]) {
        temp_grid[x][y - 1] = 2;
        dfs(x, y - 1);
    }
    if (M > y + 1 && 0 == temp_grid[x][y + 1]) {
        temp_grid[x][y + 1] = 2;
        dfs(x, y + 1);
    }

    return;
}

int main(int argc, char** argv) {
    /*
     * Identify safe squares and virus squares.
     */
    scanf("%d%d", &N, &M);
    for (int i = 0; N > i; ++i) {
        for (int j = 0; M > j; ++j) {
            scanf("%d", &grid[i][j]);
            if (0 == grid[i][j]) {
                safe_squares[safe_squares_cnt][0] = i;
                safe_squares[safe_squares_cnt++][1] = j;
            }
            else if (2 == grid[i][j]) {
                virus_squares[virus_squares_cnt][0] = i;
                virus_squares[virus_squares_cnt++][1] = j;
            }
        }
    }

    /*
     * Review all possible permutations.
     */
    for (int i = 0; safe_squares_cnt > i; ++i) {
        for (int j = i + 1; safe_squares_cnt > j; ++j) {
            for (int k = j + 1; safe_squares_cnt > k; ++k) {
                /*
                 * Generate new permutation.
                 */
                for (int u = 0; N > u; ++u) {
                    for (int v = 0; M > v; ++v) {
                        temp_grid[u][v] = grid[u][v];
                    }
                }
                ++temp_grid[safe_squares[i][0]][safe_squares[i][1]];
                ++temp_grid[safe_squares[j][0]][safe_squares[j][1]];
                ++temp_grid[safe_squares[k][0]][safe_squares[k][1]];
                
                /*
                 * Let the virus spread.
                 */
                for (int t = 0; virus_squares_cnt > t; ++t) {
                    dfs(virus_squares[t][0], virus_squares[t][1]);   
                }

                /*
                 * Count remaining safe squares.
                 */
                new_answer = 0;
                for (int u = 0; N > u; ++u) {
                    for (int v = 0; M > v; ++v) {
                        if (0 == temp_grid[u][v]) {
                            ++new_answer;
                        }
                    }
                }

                /*
                 * If permutation is more optimal, update answer.
                 */
                answer = max(answer, new_answer);
            }
        }
    }

    printf("%d", answer);

    return 0;
}
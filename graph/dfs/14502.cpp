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
constexpr int dx[4] = {0,0,-1,1};
constexpr int dy[4] = {1,-1,0,0};

int answer, new_answer;
int N, M;
int nx, ny;
int grid[MAX_N][MAX_M];
int temp_grid[MAX_N][MAX_M];
int safe_squares_cnt, virus_squares_cnt;
int safe_squares[MAX_N * MAX_M - MIN_VIRUS_CNT][2];
int virus_squares[MAX_VIRUS_CNT][2];

void dfs(int x, int y) {
    for (int i = 0; 4 > i; ++i) {
        nx = x + dx[i];
        ny = y + dy[i];

        if (0 <= nx && N > nx && 0 <= ny && M > ny && 0 == temp_grid[nx][ny]) {
            temp_grid[nx][ny] = 2;
            dfs(nx, ny);
        }
    }

    return;
}

int main(int argc, char** argv) {
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

    for (int i = 0; safe_squares_cnt > i; ++i) {
        for (int j = i + 1; safe_squares_cnt > j; ++j) {
            for (int k = j + 1; safe_squares_cnt > k; ++k) {
                for (int u = 0; N > u; ++u) {
                    for (int v = 0; M > v; ++v) {
                        temp_grid[u][v] = grid[u][v];
                    }
                }

                ++temp_grid[safe_squares[i][0]][safe_squares[i][1]];
                ++temp_grid[safe_squares[j][0]][safe_squares[j][1]];
                ++temp_grid[safe_squares[k][0]][safe_squares[k][1]];
                for (int t = 0; virus_squares_cnt > t; ++t) {
                    dfs(virus_squares[t][0], virus_squares[t][1]);   
                }

                new_answer = 0;
                for (int u = 0; N > u; ++u) {
                    for (int v = 0; M > v; ++v) {
                        if (0 == temp_grid[u][v]) {
                            ++new_answer;
                        }
                    }
                }
                answer = max(answer, new_answer);
            }
        }
    }

    printf("%d", answer);

    return 0;
}
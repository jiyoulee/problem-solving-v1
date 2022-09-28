/*
 * Title: 로봇 청소기
 * Link: https://www.acmicpc.net/problem/14503
 */

#include <cstdio>
#include <algorithm>

constexpr int MAX_N = 50;
constexpr int MAX_M = 50;
constexpr int dr[4] = {-1, 0, 1, 0};
constexpr int dc[4] = {0, 1, 0, -1};
constexpr int conjugate[4] = {2, 3, 0, 1};

int answer;
int N, M, r, c, d;
int attempt_cnt;
int grid[MAX_N][MAX_N];

int main(int argc, char** argv) {
    /*
     * Get robot into position.
     */
    scanf("%d%d%d%d%d", &N, &M, &r, &c, &d);
    for (int i = 0; N > i; ++i) {
        for (int j = 0; M > j; ++j) {
            scanf("%d", &grid[i][j]);
        }
    }

    /*
     * Move the robot according to the rules.
     */
    while(1) {
        /*
         * Rule 1.
         */
        if (0 == grid[r][c]) {
            grid[r][c] = -1;
            ++answer;
        }

        /*
         * Rule 2-1, 2-2.
         */
        for (attempt_cnt = 0; 4 > attempt_cnt; ++attempt_cnt) {
            d += 3;
            d %= 4;

            if (0 == grid[r + dr[d]][c + dc[d]]) {
                break;
            }
        }
        if (4 != attempt_cnt) {
            r += dr[d];
            c += dc[d];
            continue;
        }

        /*
         * Rule 2-3.
         */
        if (1 != grid[r + dr[conjugate[d]]][c + dc[conjugate[d]]]) {
            r += dr[conjugate[d]];
            c += dc[conjugate[d]];
            continue;
        }

        /*
         * Rule 2-4.
         */
        break;
    }

    printf("%d", answer);

    return 0;
}
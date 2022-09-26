/*
 * Title: 토마토
 * Link: https://www.acmicpc.net/problem/7576
 */

#include <cstdio>
#include <queue>

using namespace std;

constexpr int MAX_N = 1000;
constexpr int MAX_M = 1000;
constexpr int DIRECTION_CNT = 4;
constexpr int dx[DIRECTION_CNT] = {-1, 1, 0, 0};
constexpr int dy[DIRECTION_CNT] = {0, 0, -1, 1};

int answer;
int M, N;
int x, y, nx, ny;
int grid[MAX_N][MAX_M];
queue<pair<int,int>> ripe_tomatoes;

int main(int argc, char** argv) {
    /*
     * Get list of originally ripe tomatoes.
     */
    scanf("%d%d", &M, &N);
    for (int i = 0; N > i; ++i) {
        for (int j = 0; M > j; ++j) {
            scanf("%d", &grid[i][j]);
            if (1 == grid[i][j]) {
                ripe_tomatoes.emplace(i, j);
            }
        }
    }

    /*
     * Let ripening take effect.
     */
    while (!ripe_tomatoes.empty()) {
        x = ripe_tomatoes.front().first;
        y = ripe_tomatoes.front().second;
        ripe_tomatoes.pop();

        for (int i = 0; DIRECTION_CNT > i; ++i) {
            nx = x + dx[i];
            ny = y + dy[i];
            if (0 <= nx && N > nx && 0 <= ny && M > ny && 0 == grid[nx][ny]) {
                grid[nx][ny] = grid[x][y] + 1;
                ripe_tomatoes.emplace(nx, ny);
            }
        }
    }

    /*
     * Decide if all the tomatos have been ripened, and if so, how long it took.
     */
    for (int i = 0; N > i; ++i) {
        for (int j = 0; M > j; ++j) {
            if (0 == grid[i][j]) {
                printf("-1");
                return 0;
            }

            answer = max(answer, grid[i][j]);
        }
    }
    printf("%d", answer - 1);

    return 0;
}
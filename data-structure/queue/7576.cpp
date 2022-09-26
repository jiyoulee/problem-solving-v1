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

struct Tomato {
    int x;
    int y;
} tomato_pool[MAX_N * MAX_M + 10];

int answer;
int M, N;
int x, y, nx, ny;
int grid[MAX_N][MAX_M];
int tomato_idx;
queue<Tomato> ripe_tomatoes;

int main(int argc, char** argv) {
    scanf("%d%d", &M, &N);
    for (int i = 0; N > i; ++i) {
        for (int j = 0; M > j; ++j) {
            scanf("%d", &grid[i][j]);
            if (1 == grid[i][j]) {
                tomato_pool[tomato_idx].x = i;
                tomato_pool[tomato_idx].y = j;
                ripe_tomatoes.emplace(tomato_pool[tomato_idx++]);
            }
        }
    }

    while (!ripe_tomatoes.empty()) {
        x = ripe_tomatoes.front().x;
        y = ripe_tomatoes.front().y;
        ripe_tomatoes.pop();

        for (int i = 0; DIRECTION_CNT > i; ++i) {
            nx = x + dx[i];
            ny = y + dy[i];
                if (0 <= nx && N > nx && 0 <= ny && M > ny && 0 == grid[nx][ny]) {
                grid[nx][ny] = grid[x][y] + 1;
                tomato_pool[tomato_idx].x = nx;
                tomato_pool[tomato_idx].y = ny;
                ripe_tomatoes.emplace(tomato_pool[tomato_idx++]);
            }
        }
    }

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
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
constexpr int END_OF_DAY = -1;

struct Tomato {
    int x;
    int y;
} tomato_pool[MAX_N * MAX_M + 10];

int answer;
int M, N;
int nx, ny;
int ripe_square_cnt, empty_square_cnt;
int grid[MAX_N][MAX_M];
int tomato_idx;
Tomato tomato;
queue<Tomato> ripe_tomatoes;

int main(int argc, char** argv) {
    scanf("%d%d", &M, &N);
    for (int i = 0; N > i; ++i) {
        for (int j = 0; M > j; ++j) {
            scanf("%d", &grid[i][j]);
            if (1 == grid[i][j]) {
                ++ripe_square_cnt;
            }
            else if (-1 == grid[i][j]) {
                ++empty_square_cnt;
            }
        }
    }
    
    if (N * M == ripe_square_cnt + empty_square_cnt) {
        printf("0");
        return 0;
    }

    for (int i = 0; N > i; ++i) {
        for (int j = 0; M > j; ++j) {
            if (1 == grid[i][j]) {
                tomato_pool[tomato_idx].x = i;
                tomato_pool[tomato_idx].y = j;
                ripe_tomatoes.emplace(tomato_pool[tomato_idx++]);
            }
        }
    }
    tomato_pool[tomato_idx].x = END_OF_DAY;
    tomato_pool[tomato_idx].y = END_OF_DAY;
    ripe_tomatoes.emplace(tomato_pool[tomato_idx++]);

    while (!ripe_tomatoes.empty()) {
        tomato = ripe_tomatoes.front();
        ripe_tomatoes.pop();

        if (END_OF_DAY == tomato.x) {
            ++answer;

            if (!ripe_tomatoes.empty()) {
                ripe_tomatoes.emplace(tomato);
            }
        }
        else {
            for (int i = 0; DIRECTION_CNT > i; ++i) {
                nx = tomato.x + dx[i];
                ny = tomato.y + dy[i];

                if (0 <= nx && N > nx && 0 <= ny && M > ny && 0 == grid[nx][ny]) {
                    ++grid[nx][ny];
                    tomato_pool[tomato_idx].x = nx;
                    tomato_pool[tomato_idx].y = ny;
                    ripe_tomatoes.emplace(tomato_pool[tomato_idx++]);
                }
            }
        }
    }

    bool is_valid = true;
    for (int i = 0; N > i; ++i) {
        for (int j = 0; M > j; ++j) {
            if (0 == grid[i][j]) {
                is_valid = false;
                break;
            }
        }
    }

    if (is_valid) {
        printf("%d", answer - 1);
    }
    else {
        printf("-1");
    }

    return 0;
}
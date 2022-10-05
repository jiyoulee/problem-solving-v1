/*
 * Title: 감시
 * Link: https://www.acmicpc.net/problem/15683
 */

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

constexpr int MAX_N = 8;
constexpr int MAX_M = 8;
constexpr int MAX_CCTV_CNT = 8;
constexpr int EMPTY = 0;
constexpr int WALL = 6;
constexpr int dx[4] = {-1, 0, 1, 0};
constexpr int dy[4] = {0, 1, 0, -1};

struct CCTV {
    int x;
    int y;
    int type;
    int dir;
} cctvs[MAX_CCTV_CNT];

int ans = 65;
int N, M;
int cctv_cnt, blindspot_cnt, temp_cnt;
int grid[MAX_N][MAX_M];

void survey(int x, int y, int dir) {
    for (x += dx[dir], y += dy[dir]; 0 <= x && N > x && 0 <= y && M > y && WALL != grid[x][y]; x += dx[dir], y += dy[dir]) {
        if (!grid[x][y]) {
            grid[x][y] = 1;
            ++temp_cnt;
        }
    }

    return;
}

void go(int depth, int cnt) {
    if (cctv_cnt == depth) {
        ans = min(ans, blindspot_cnt - cnt);

        return;
    }
    
    int& dir = cctvs[depth].dir;
    for (dir = 0; 4 > dir; ++dir) {
        if (2 == cctvs[depth].type && 1 < dir) {
            break;
        }
        if (5 == cctvs[depth].type && 0 < dir) {
            break;
        }
        int temp[MAX_N][MAX_N];

        memcpy(temp, grid, sizeof(grid));

        temp_cnt = 0;
        int x = cctvs[depth].x;
        int y = cctvs[depth].y;
        int type = cctvs[depth].type;

        survey(x, y, dir);
        if (1 != type && 2 != type) {
            survey(x, y, (dir + 1) % 4);
        }
        if (2 == type || 5 == type) {
            survey(x, y, (dir + 2) % 4);
        }
        if (4 == type || 5 == type) {
            survey(x, y, (dir + 3) % 4);
        }

        go(depth + 1, cnt + temp_cnt);

        memcpy(grid, temp, sizeof(grid));
    }   

    return;
}

int main(int argc, char** argv) {
    scanf("%d%d", &N, &M);
    for (int i = 0; N > i; ++i) {
        for (int j = 0; M > j; ++j) {
            scanf("%d", &grid[i][j]);

            if (!grid[i][j]) {
                ++blindspot_cnt;
            }
            else if (WALL != grid[i][j]) {
                cctvs[cctv_cnt++] = {i, j, grid[i][j]};
            }
        }
    }

    go(0, 0);

    printf("%d", ans);

    return 0;
}
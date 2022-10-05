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
int temp[MAX_N][MAX_N];

void survey(int x, int y, int dir) {
    for (x += dx[dir], y += dy[dir]; 0 <= x && N > x && 0 <= y && M > y && WALL != temp[x][y]; x += dx[dir], y += dy[dir]) {
        if (!temp[x][y]) {
            temp[x][y] = 1;
            ++temp_cnt;
        }
    }

    return;
}

void go(int depth) {
    if (cctv_cnt == depth) {
        memcpy(temp, grid, sizeof(grid));

        temp_cnt = 0;
        int type, dir;
        for (int k = 0; cctv_cnt > k; ++k) {
            type = cctvs[k].type;
            dir = cctvs[k].dir;

            survey(cctvs[k].x, cctvs[k].y, dir);
            if (1 != type && 2 != type) {
                survey(cctvs[k].x, cctvs[k].y, (dir + 1) % 4);
            }
            if (2 == type || 5 == type) {
                survey(cctvs[k].x, cctvs[k].y, (dir + 2) % 4);
            }
            if (4 == type || 5 == type) {
                survey(cctvs[k].x, cctvs[k].y, (dir + 3) % 4);
            }
        }

        ans = min(ans, blindspot_cnt - temp_cnt);

        return;
    }
    
    for (cctvs[depth].dir = 0; 4 > cctvs[depth].dir; ++cctvs[depth].dir) {
        go(depth + 1);
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

    go(0);

    printf("%d", ans);

    return 0;
}
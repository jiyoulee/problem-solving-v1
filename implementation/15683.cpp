/*
 * Title: 감시
 * Link: https://www.acmicpc.net/problem/15683
 */

#include <cstdio>
#include <algorithm>

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

int ans, cnt;
int N, M;
int cctv_cnt;
int grid[MAX_N][MAX_M];
int temp[MAX_N][MAX_N];

void go(int depth) {
    if (cctv_cnt == depth) {
        for (int i = 0; N > i; ++i) {
            for (int j = 0; M > j; ++j) {
                temp[i][j] = grid[i][j];
            }
        }

        int temp_cnt = 0;
        for (int k = 0; cctv_cnt > k; ++k) {
            if (5 != cctvs[k].type) {
                int dir = cctvs[k].dir;

                for (int x = cctvs[k].x + dx[dir], y = cctvs[k].y + dy[dir]; 0 <= x && N > x && 0 <= y && M > y && WALL != temp[x][y]; x += dx[dir], y += dy[dir]) {
                    if (!temp[x][y]) {
                        temp[x][y] = 1;
                        ++temp_cnt;
                    }
                }                

                switch(cctvs[k].type) {
                    case 2:
                        dir = (cctvs[k].dir + 2) % 4;
                        for (int x = cctvs[k].x + dx[dir], y = cctvs[k].y + dy[dir]; 0 <= x && N > x && 0 <= y && M > y && WALL != temp[x][y]; x += dx[dir], y += dy[dir]) {
                            if (!temp[x][y]) {
                                temp[x][y] = 1;
                                ++temp_cnt;
                            }
                        }
                        break;      
                    case 4:
                        dir = (cctvs[k].dir + 3) % 4;
                        for (int x = cctvs[k].x + dx[dir], y = cctvs[k].y + dy[dir]; 0 <= x && N > x && 0 <= y && M > y && WALL != temp[x][y]; x += dx[dir], y += dy[dir]) {
                            if (!temp[x][y]) {
                                temp[x][y] = 1;
                                ++temp_cnt;
                            }
                        }
                    case 3:
                        dir = (cctvs[k].dir + 1) % 4;
                        for (int x = cctvs[k].x + dx[dir], y = cctvs[k].y + dy[dir]; 0 <= x && N > x && 0 <= y && M > y && WALL != temp[x][y]; x += dx[dir], y += dy[dir]) {
                            if (!temp[x][y]) {
                                temp[x][y] = 1;
                                ++temp_cnt;
                            }
                        }
                        break;
                    default:
                        break;
                }
            }
        }

        cnt = max(cnt, temp_cnt);

        return;
    }

    for (int i = 0; 4 > i; ++i) {
        cctvs[depth].dir = i;
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
                ++ans;
            }
            else if (WALL != grid[i][j]) {
                cctvs[cctv_cnt].x = i;
                cctvs[cctv_cnt].y = j;
                cctvs[cctv_cnt++].type = grid[i][j];
            }
        }
    }

    for (int k = 0; cctv_cnt > k; ++k) {
        if (5 == cctvs[k].type) {
            int x = cctvs[k].x;
            int y = cctvs[k].y;

            for (int i = -1; 0 <= (x + i) && WALL != grid[x + i][y]; --i) {
                if (!grid[x + i][y]) {
                    grid[x + i][y] = 1;
                    --ans;
                }
            }
            for (int i = 1; M > (y + i) && WALL != grid[x][y + i]; ++i) {
                if (!grid[x][y + i]) {
                    grid[x][y + i] = 1;
                    --ans;
                }
            }
            for (int i = 1; N > (x + i) && WALL != grid[x + i][y]; ++i) {
                if (!grid[x + i][y]) {
                    grid[x + i][y] = 1;
                    --ans;
                }
            }
            for (int i = -1; 0 <= (y + i) && WALL != grid[x][y + i]; --i) {
                if (!grid[x][y + i]) {
                    grid[x][y + i] = 1;
                    --ans;
                }
            }
        }
    }

    go(0);

    printf("%d", ans - cnt);

    return 0;
}
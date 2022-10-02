#include <cstdio>
#include <cmath>

using namespace std;

constexpr int MAX_N = 100;

int ans;
int N, L;
int prev, cnt;
bool is_valid;
bool row[MAX_N];
bool col[MAX_N];
int grid[MAX_N][MAX_N];

int main(int argc, char** argv) {
    scanf("%d%d", &N, &L);
    for (int i = 0; N > i; ++i) {
        for (int j = 0; N > j; ++j) {
            scanf("%d", &grid[i][j]);
        }
    }

    for (int R = 0; N > R; ++R) {
        prev = grid[R][0];
        cnt = 1;
        is_valid = true;

        for (int c = 1; N > c;) {
            if (prev == grid[R][c]) {
                ++cnt;
                ++c;
                continue;
            }
            if (-1 == prev - grid[R][c]) {
                if (L <= cnt) {
                    prev = grid[R][c++];
                    cnt = 1;
                    continue;
                }
            }
            if (1 == prev - grid[R][c]) {
                if (N != c + L && grid[R][c] < grid[R][c + L]) {
                    is_valid = false;
                    break;
                }

                for (int i = 1; L > i; ++i) {
                    if (grid[R][c] != grid[R][c + i]) {
                        is_valid = false;
                        break;
                    }
                }
                if (!is_valid) {
                    break;
                }

                prev = grid[R][c];
                c += L;
                cnt = 0;
                continue;
            }

            is_valid = false;
            break;
        }

        if (is_valid) {
            ++ans;
        }
    }

    for (int C = 0; N > C; ++C) {
        prev = grid[0][C];
        cnt = 1;
        is_valid = true;

        for (int r = 1; N > r;) {
            if (prev == grid[r][C]) {
                ++cnt;
                ++r;
                continue;
            }
            if (-1 == prev - grid[r][C]) {
                if (L <= cnt) {
                    prev = grid[r++][C];
                    cnt = 1;
                    continue;
                }
            }
            if (1 == prev - grid[r][C]) {
                if (N != r + L && grid[r][C] < grid[r + L][C]) {
                    is_valid = false;
                    break;
                }

                for (int i = 1; L > i; ++i) {
                    if (grid[r][C] != grid[r + i][C]) {
                        is_valid = false;
                        break;
                    }
                }
                if (!is_valid) {
                    break;
                }

                prev = grid[r][C];
                r += L;
                cnt = 0;
                continue;
            }
            
            is_valid = false;
            break;
        }

        if (is_valid) {
            ++ans;
        }
    }

    printf("%d", ans);

    return 0;
}
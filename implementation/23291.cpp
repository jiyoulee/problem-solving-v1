/*
 * Title: 어항 정리
 * Link: https://www.acmicpc.net/problem/23291
 */

#include <cstdio>
#include <algorithm>

using namespace std;

constexpr int MAX_N = 100;

int ans;
int N, K, W, H;
int max_fish = -1, min_fish = 10001;
int fishtanks[1 + MAX_N];
int temp[1 + MAX_N];
int snail[MAX_N][MAX_N];
int quarter[4][MAX_N / 4];
int deltas[1 + MAX_N];

void get_snail(int cnt, int w, int h);
void get_quarter(int col);
void get_delta(int a, int b);
void get_delta_quarter(int a, int b);

int main(int argc, char** argv) {
    scanf("%d%d", &N, &K); 
    for (int i = 1; N >= i; ++i) {
        scanf("%d", &fishtanks[i]);
        max_fish = max(max_fish, fishtanks[i]);
        min_fish = min(min_fish, fishtanks[i]);
    }

    for (int i = 1; 10 >= i; ++i) {
        if (N < i * i) {
            W = i - 1;
            H = i;
            break;
        }
        if (N < i * (i + 1)) {
            W = i;
            H = i;
            break;
        }
    }

    get_snail(W * H, W, H - 1);
    get_quarter(N / 4);

    while (K < max_fish - min_fish) {
        for (int i = 1; N >= i; ++i) {
            if (min_fish == fishtanks[i]) {
                ++fishtanks[i];
            }
        }

        for (int i = 0; H > i; ++i) {
            for (int j = 0; W > j; ++j) {
                if (i) {
                    get_delta(snail[i][j], snail[i - 1][j]);
                }
                if (j) {
                    get_delta(snail[i][j], snail[i][j - 1]);
                }
            }
        }
        for (int i = W * H + 1; N >= i; ++i) {
            get_delta(i, i - 1);
        }

        int k = 1;
        for (int i = W - 1; 0 <= i; --i) {
            for (int j = 0; H > j; ++j) {
                temp[k++] = fishtanks[snail[j][i]] + deltas[snail[j][i]];
                deltas[snail[j][i]] = 0;
            }
        }
        for (int i = W * H + 1; N >= i; ++i) {
            temp[k++] = fishtanks[i] + deltas[i];
            deltas[i] = 0;
        }

        for (int i = 0; 4 > i; ++i) {
            for (int j = 0; N / 4 > j; ++j) {
                if (i) {
                    get_delta_quarter(quarter[i][j], quarter[i - 1][j]);
                }
                if (j) {
                    get_delta_quarter(quarter[i][j], quarter[i][j - 1]);
                }
            }
        }

        k = 1;
        max_fish = -1;
        min_fish = 10001;
        for (int i = N / 4 - 1; 0 <= i; --i) {
            for (int j = 0; 4 > j; ++j) {
                fishtanks[k] = temp[quarter[j][i]] + deltas[quarter[j][i]];
                deltas[quarter[j][i]] = 0;
                max_fish = max(max_fish, fishtanks[k]);
                min_fish = min(min_fish, fishtanks[k++]);
            }
        }

        ++ans;
    }

    printf("%d", ans);

    return 0;
}

/*
 *
 */

void get_snail(int cnt, int w, int h) {
    int r = 0, c = -1;
    int k = 1;
    while (cnt) {
        for (int i = 1; w >= i; ++i) {
            snail[r][c += k] = cnt--;
        }
        --w;
        if (!cnt) {
            break;
        }

        for (int i = 1; h >= i; ++i) {
            snail[r += k][c] = cnt--;
        }
        --h;
        k = -k;
    }

    return;
}

void get_quarter(int col) {
    int cnt = N;

    for (int i = 0; col > i; ++i) {
        quarter[0][i] = cnt--;
    }
    for (int i = col - 1; 0 <= i; --i) {
        quarter[3][i] = cnt--;
    }
    for (int i = 0; col > i; ++i) {
        quarter[2][i] = cnt--;
    }
    for (int i = col - 1; 0 <= i; --i) {
        quarter[1][i] = cnt--;
    }

    return;
}

void get_delta(int a, int b) {
    if (fishtanks[a] < fishtanks[b]) {
        swap(a, b);
    }
    
    int delta = (fishtanks[a] - fishtanks[b]) / 5;
    deltas[a] -= delta;
    deltas[b] += delta;

    return;
}

void get_delta_quarter(int a, int b) {
    if (temp[a] < temp[b]) {
        swap(a, b);
    }
    
    int delta = (temp[a] - temp[b]) / 5;
    deltas[a] -= delta;
    deltas[b] += delta;

    return;
}
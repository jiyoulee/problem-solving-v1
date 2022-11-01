/*
 * Title: 1로 만들기 2
 * Link: https://www.acmicpc.net/problem/12852
 */

#include <stdio.h>
#include <algorithm>

using namespace std;

constexpr int MAX_PATH_LENGTH = 1000001;

int cnt, idx;
int N;
int cnt[MAX_PATH_LENGTH];
int path[MAX_PATH_LENGTH];

int main(int argc, char** argv) {
    scanf("%d", &N);

    cnt[3] = cnt[2] = 1;
    path[3] = path[2] = 1;
    for (int i = 4; N >= i; ++i) {
        cnt[i] = cnt[i - 1] + 1;
        path[i] = i - 1;
        if (0 == i % 3) {
            if (cnt[i / 3] + 1 < cnt[i]) {
                cnt[i] = cnt[i / 3] + 1;
                path[i] = i / 3;
            }
        }
        if (0 == i % 2) {
            if (cnt[i / 2] + 1 < cnt[i]) {
                cnt[i] = cnt[i / 2] + 1;
                path[i] = i / 2;
            }
        }
    }

    printf("%d\n", cnt[N]);
    while (N) {
        printf("%d ", N);
        N = path[N];
    }

    return 0;
}
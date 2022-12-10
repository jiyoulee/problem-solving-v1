/*
 * Title: ATM
 * Link: https://www.acmicpc.net/problem/11399
 */

#include <cstdio>
#include <algorithm>

using namespace std;

constexpr int MAX_N = 1000;

int ans;
int N;
int P[MAX_N];

int main(int argc, char** argv) {
    scanf("%d", &N);
    for (int i = 0; N > i; ++i) {
        scanf("%d", &P[i]);
    }

    sort(P, P + N);

    for (int i = 0; N > i; ++i) {
        ans += (N - i) * P[i];
    }

    printf("%d", ans);

    return 0;
}
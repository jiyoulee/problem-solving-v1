/*
 * Title: 이항 계수 1
 * Link: https://www.acmicpc.net/problem/11050
 */

#include <cstdio>

using namespace std;

int N, K;

int go(int n, int k) {
    if (0 == k || n == k) {
        return 1;
    }
    if (1 == k) {
        return n;
    }

    return go(n - 1, k) + go(n - 1, k - 1);
}

int main(int argc, char** argv) {
    scanf("%d%d", &N, &K);

    printf("%d", go(N, K));

    return 0;
}
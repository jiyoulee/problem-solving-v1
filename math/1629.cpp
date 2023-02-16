/*
 * Problem: 곱셈
 * Tags: mathematics, exponentiation-by-squaring
 * Link: https://www.acmicpc.net/problem/1629
 *
 * Author: jiyoulee
 * Solved: 2023-02-16
 */

#include <cstdio>

using namespace std;

long long int A, B, C;

long long int dfs(int b);

int main() {
    /*
     * Input.
     */
    scanf("%lld%lld%lld", &A, &B, &C);

    /*
     * Compute.
     */
    A %= C;

    /*
     * Output.
     */
    printf("%lld", dfs(B));

    return 0;
}

long long int dfs(int b) {
    if (1 == b) {
        return A;
    }

    long long int ret = (b & 1 ? dfs((b - 1) >> 1) : dfs(b >> 1));

    ret *= ret;
    ret %= C;

    if (b & 1) {
        ret *= A;
        ret %= C;
    }

    return ret;
}
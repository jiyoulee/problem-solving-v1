/*
 * Problem: 리모컨
 * Tags: brute-forcing
 * Link: https://www.acmicpc.net/problem/1107
 *
 * Author: jiyoulee
 * Solved: 2023-01-30
 */

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

constexpr int LIMIT = 1000000;
constexpr int BASELINE = 100;

int answer;
int N, M;
bool is_broken[10];
int A;

int main() {
    /*
     * Input.
     */
    scanf("%d%d", &N, &M);

    for (int i = 0, tmp; M > i; ++i) {
        scanf("%d", &tmp);

        is_broken[tmp] = true;
    }

    /*
     * Compute.
     */
    answer = abs(N - BASELINE);

    if (10 != M) {
        if (!is_broken[0]) {
            answer = min(answer, 1 + N);
        }

        for (int i = 1, tmp; LIMIT >= i; ++i) {
            for (tmp = i; tmp && !is_broken[tmp % 10]; tmp /= 10) {};

            if (!tmp) {
                answer = min(answer, (int)(log10(i)) + 1 + abs(i - N));
            }
        }
    }

    /*
     * Output.
     */
    printf("%d", answer);

    return 0;
}
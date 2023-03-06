/*
 * Problem: 한 줄로 서기
 * Tags: implementation
 * Link: https://www.acmicpc.net/problem/1138
 *
 * Author: jiyoulee
 * Solved: 2023-03-06
 */

#include <cstdio>

using namespace std;

constexpr int MAX_N = 10;

int answer[1 + MAX_N];
int N;
int A[1 + MAX_N];

int main() {
    /*
     * Input.
     */
    scanf("%d", &N);

    for (int i = 1; N >= i; ++i) {
        scanf("%d", &A[i]);
    }

    /*
     * Compute.
     */
    for (int i = 1, pos; N >= i; ++i) {
        for (pos = 1; A[i]; ++pos) {
            if (!answer[pos]) {
                --A[i];
            }
        }

        while (answer[pos]) {
            ++pos;
        }

        answer[pos] = i;
    }

    /*
     * Output.
     */
    for (int i = 1; N >= i; ++i) {
        printf("%d ", answer[i]);
    }

    return 0;
}
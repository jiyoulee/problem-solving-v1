/*
 * Problem: 별 찍기 - 12
 * Tags: implementation
 * Link: https://www.acmicpc.net/problem/2522
 *
 * Author: jiyoulee
 * Solved: 2023-01-29
 */

#include <cstdio>

using namespace std;

int N;

int main() {
    /*
     * Input.
     */
    scanf("%d", &N);

    /*
     * Output.
     */
    for (int i = 1; N >= i; ++i) {
        for (int j = N - i; j; --j) {
            printf(" ");
        }
        for (int j = 1; i >= j; ++j) {
            printf("*");
        }
        printf("\n");
    }

    for (int i = N - 1; i; --i) {
        for (int j = N - i; j; --j) {
            printf(" ");
        }
        for (int j = 1; i >= j; ++j) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
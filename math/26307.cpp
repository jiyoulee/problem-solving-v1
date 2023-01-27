/*
 * Problem: Correct
 * Tags: mathematics, arithmetic
 * Link: https://www.acmicpc.net/problem/26307
 *
 * Author: jiyoulee
 * Solved: 2023-01-27
 */

#include <cstdio>

using namespace std;

int HH, MM;

int main() {
    /*
     * Input.
     */
    scanf("%d%d", &HH, &MM);

    /*
     * Output.
     */
    printf("%d", (HH - 9) * 60 + MM);

    return 0;
}
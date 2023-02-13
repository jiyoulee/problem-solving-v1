/*
 * Problem: A -> B
 * Tags: graph-theory, greedy, graph-traversal, breadth-first-search
 * Link: https://www.acmicpc.net/problem/16953
 *
 * Author: jiyoulee
 * Solved: 2023-02-13
 */

#include <cstdio>

using namespace std;

int answer = 1;
int A, B;

int main() {
    /*
     * Input.
     */
    scanf("%d%d", &A, &B);

    /*
     * Compute.
     */
    for (; A < B; answer++) {
        if (1 == (B % 10)) {
            B /= 10;
        }
        else if (!(B & 1)) {
            B >>= 1;
        }
        else {
            break;
        }
    }

    /*
     * Output.
     */
    printf("%d", A == B ? answer : -1);

    return 0;
}
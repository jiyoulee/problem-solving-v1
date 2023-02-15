/*
 * Problem: RGB거리
 * Tags: dynamic-programming
 * Link: https://www.acmicpc.net/problem/1149
 *
 * Author: jiyoulee
 * Solved: 2023-02-15
 */

#include <cstdio>
#include <algorithm>

using namespace std;

constexpr int MAX_N = 1000;

int N;
int A[1 + MAX_N][3];

int main() {
    /*
     * Input and Compute.
     */
    scanf("%d", &N);

    for (int i = 1; N >= i; ++i) {
        for (int j = 0; 3 > j; ++j) {
            scanf("%d", &A[i][j]);
            
            A[i][j] += min(A[i - 1][(j + 1) % 3], A[i - 1][(j + 2) % 3]); 
        }
    }

    /*
     * Output.
     */
     printf("%d", min({A[N][0], A[N][1], A[N][2]}));

    return 0;
}
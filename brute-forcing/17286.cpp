/*
 * Problem: 유미
 * Tags: brute-forcing, geometry, pythagoras-theorem
 * Link: https://www.acmicpc.net/problem/17286
 *
 * Author: jiyoulee
 * Solved: 2022-12-17
 */

#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

constexpr int INF = 1987654321;

double answer = INF;
double tmp;
int C[4][2];
int sequence[4] = {0, 1, 2, 3};

int main(int argc, char** argv) {
    /*
     * Input.
     */
    for (int i = 0; 4 > i; ++i) {
        scanf("%d%d", &C[i][0], &C[i][1]);
    }

    /*
     * Compute.
     */
    do {
        tmp = 0;
        
        for (int i = 1; 4 > i; ++i) {
            tmp += sqrt(pow(C[sequence[i]][0] - C[sequence[i - 1]][0], 2) + pow(C[sequence[i]][1] - C[sequence[i - 1]][1], 2));
        }

        if (answer > tmp) {
            answer = tmp;
        }
    } while (next_permutation(sequence, sequence + 4) && 0 == sequence[0]);
    
    /*
     * Output.
     */
    printf("%d", (int)answer);

    return 0;
}
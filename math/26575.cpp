/*
 * Problem: Pups
 * Tags: mathematics, arithmetic
 * Link: https://www.acmicpc.net/problem/26575
 *
 * Author: jiyoulee
 * Solved: 2023-03-07
 */

#include <cstdio>
#include <cmath>

using namespace std;

int N;
double D, F, P;

int main() {
    for (scanf("%d", &N); N--; ) {
    	/*
    	 * Input.
    	 */
        scanf("%lf%lf%lf", &D, &F, &P);

        /*
         * Output.
         */
        printf("$%.2lf\n", round(D * F * P * 100) / 100);
    }

    return 0;
}
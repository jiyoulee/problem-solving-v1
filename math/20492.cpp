/*
 * Problem: 세금
 * Tags: mathematics, arithmetic
 * Link: https://www.acmicpc.net/problem/20492
 *
 * Author: jiyoulee
 * Solved: 2023-01-14
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
	printf("%d %d", int(N * 0.78), int(N * (0.80 + 0.20 * 0.78)));

	return 0;
}
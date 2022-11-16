/*
 * Title: Shares
 * Link: https://www.acmicpc.net/problem/3733
 */

#include <cstdio>

using namespace std;

int N, S;

int main(int argc, char** argv) {
	while (2 == scanf("%d%d", &N, &S)) {
		printf("%d\n", S / (N + 1));
	}

	return 0;
}
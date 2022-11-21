/*
 * Title: 제리와 톰
 * Link: https://www.acmicpc.net/problem/16430
 */

#include <cstdio>

using namespace std;

int A, B;

int main(int argc, char** argv) {
	scanf("%d%d", &A, &B);
	
	printf("%d %d", B - A, B);

	return 0;
}
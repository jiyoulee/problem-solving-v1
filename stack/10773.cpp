/*
 * Title: Zero That Out
 * Link: https://www.acmicpc.net/problem/10773
 */

#include <cstdio>

using namespace std;

constexpr int MAX_STACK_SIZE = 100000;

int K, N;
int stack_size;
int stack[1 + MAX_STACK_SIZE];

int main(int argc, char** argv) {
	int answer = 0;
	
	scanf("%d", &K);
	while (K--) {
		scanf("%d", &N);

		if (0 == N) {
			if (stack_size) {
				answer -= stack[stack_size--];
			}
		}
		else {
			answer += N;
			stack[++stack_size] = N;
		}
	}

	printf("%d", answer);

	return 0;
}
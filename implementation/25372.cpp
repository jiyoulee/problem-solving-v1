/*
 * Title: 성택이의 은밀한 비밀번호
 * Link: https://www.acmicpc.net/problem/25372
 */

#include <cstdio>
#include <cstring>

using namespace std;

constexpr int MAX_PW_LENGTH = 20;

int N;
char pw[MAX_PW_LENGTH + 1];

int main(int argc, char** argv) {
	scanf("%d", &N);

	for (int i = 0; N > i; ++i) {
		scanf("%s", pw);

		if (6 <= strlen(pw) && 9 >= strlen(pw)) {
			printf("yes\n");
		}
		else {
			printf("no\n");
		}
	}

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int M, cnt;

int main() {
	scanf("%d", &M);

	if (0 == M % 3) {
		printf("%d ", M / 3);
	}
	else {
		printf("%d ", M / 3 + 1);
	}

	if (1 == M) {
		printf("1");
	}
	else {
		while (0 == M % 4) {
			M /= 4;
			cnt++;			
		}
		for (int i = 2; i * i <= M; i++) {
			while (0 == M % i) {
				M /= i;
				cnt++;
			}
		}
		if (1 == M) {
			printf("%d", cnt);
		}
		else {
			printf("%d", cnt + 1);
		}
	}

	return 0;
}
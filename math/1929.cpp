#include <bits/stdc++.h>
using namespace std;

int M, N;
int locked[1000001];

int main() {														// N * log(log(N))
	scanf("%d%d", &M, &N);
	
	locked[1] = true;
	for (int i = 2; i * i <= N; i++) {
		if (locked[i]) {
			continue;
		}
		for (int j = i * i; j <= N; j += i) {
			if (!locked[j]) {
				locked[j] = true;
			}
		}
	}
	
	for (int i = M; i <= N; i++) {
		if (!locked[i]) {
			printf("%d\n", i);
		}
	}
	
	return 0;
}
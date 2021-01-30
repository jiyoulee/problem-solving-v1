#include <bits/stdc++.h>
using namespace std;

int N;

int main() {							// O(sqrt(N))
	scanf("%d", &N);
	
	for (int i = 2; i * i <=N; i++) {
		while (0 == N % i) {
			printf("%d\n", i);
			N /= i;
		}
	}
	if (1 != N) printf("%d", N);
	
	return 0;
}
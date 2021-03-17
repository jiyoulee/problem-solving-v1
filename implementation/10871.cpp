#include <bits/stdc++.h>
using namespace std;

int N, X, A;

int main() {
	scanf("%d%d", &N, &X);
	
	for (int i = 1; i <= N; i++) {
		scanf("%d", &A);
		
		if (A < X) {
			printf("%d ", A);
		}
	}
	
	return 0;
}
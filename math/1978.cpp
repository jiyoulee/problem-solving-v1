#include <bits/stdc++.h>
using namespace std;

int N, A, ans;
bool good = true;

int main() {								// O(N * sqrt(N))
	scanf("%d", &N);
	
	while (N--) {
		scanf("%d", &A);
		
		if (1 == A) {						// 1 is not a prime number.
			continue;
		}
		for (int i = 2; i * i <= A; i++) {
			if (0 == A % i) {				// A is not a prime number.
				good = false;
				break;
			}
		}
		
		if (good) {
			ans++;
		}
		else {
			good = true;					// (Reset global variable.)
		}
	}
	
	printf("%d", ans);
	
	return 0;
}
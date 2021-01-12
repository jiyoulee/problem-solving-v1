#include <bits/stdc++.h>
using namespace std;

int T, N, n, S, s, B, b;
int i, j, k, ans;
int x[3];
bool y[1000];

int main() {
	fill(y, y + 1000, true);
	
	// Eliminate numbers that have repeated digits.
	for (i = 1; i <= 9; i++) {
		for (j = 1; j <= 9; j++) {
			for (k = 1; k <= 9; k++) {
				if (i != j && j != k && k != i) {
					continue;
				}
				y[i * 100 + j * 10 + k] = false;
			}
		}
	}
	
	scanf("%d", &T);

	while (T--) {
		scanf("%d%d%d", &N, &S, &B);
		
		// Parse input number.
		x[0] = N / 100;
		x[1] = (N % 100) / 10;
		x[2] = N % 10;
		
		// Do brute force search.
		for (i = 1; i <= 9; i++) {
			for (j = 1; j <= 9; j++) {
				for (k = 1; k <= 9; k++) {
					n = i * 100 + j * 10 + k;
					
					// Test whether n can be a candidate by checking number of strikes and balls n makes with N.
					if (y[n]) {
						if (i == x[0]) {
							s++;
						}
						else if (i == x[1] || i == x[2]) {
							b++;
						}
						
						if (j == x[1]) {
							s++;
						}
						else if (j == x[0] || j == x[2]) {
							b++;
						}
						
						if (k == x[2]) {
							s++;
						}
						else if (k == x[0] || k == x[1]) {
							b++;
						}
						
						if (S != s || B != b) {
							y[n] = false;
						}
						
						// (Reset global variables.)
						s = 0;
						b = 0;
			}
		}
	}
	
	for (i = 1; i <= 9; i++) {
		for (j = 1; j <= 9; j++) {
			for (k = 1; k <= 9; k++) {
				if (y[i * 100 + j * 10 + k]) {
					ans++;
				}
			}
		}
	}
	printf("%d", ans);

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int N, logged;
bool locked[1000001];
vector<int> v;

int main() {
	/*
	 * Find all odd prime numbers less than or equal to 1000000.
	 */
	for (int i = 2; i * i <= 1000000; i++) {
		if (!locked[i]) {
			for (int j = i * i; j <= 1000000; j += i) {
				if (!locked[j]) {
					locked[j] = true;
				}
			}
		}
	}
	
	/*
	 * Make a list of all odd prime numbers less than or equal to 1000000 (so as to decrease time complexity).
	 */
	for (int i = 3; i <= 1000000; i++) {
		if (!locked[i]) {
			v.push_back(i);
		}
	}
	
	while (1) {
		scanf("%d", &N);
		if (0 == N) {
			break;
		}
		
		for (int e : v) {
			if (2 * e > N) {							// All possible e's have been checked.
				break;
			}
			
			if (!locked[N - e]) {						// Both e and N - e are prime numbers.
				printf("%d = %d + %d\n", N, e, N - e);
				logged = true;
				break;
			}
		}		
		if (!logged) {									// e is a prime number, but N - e is not.
			printf("Goldbach's conjecture is wrong.\n");
		}
		else {											// (Reset global variables.)
			logged = false;
		}
	}
	
	return 0;
}
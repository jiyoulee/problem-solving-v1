#include <bits/stdc++.h>
using namespace std;

int slen, odd = -1;
char A[51];
int a[26];

int main() {
	scanf("%s", A);
	slen = strlen(A);
	for (int i = 0; i < slen; i++) {
		a[A[i] - 'A']++;
	}
	
	/*
	 * Check if the name can be made into a palindrome.
	 */
	for (int i = 0; i < 26; i++) {
		if (0 == a[i] % 2) continue;
		
		/*
		 * The name cannot be made into a palindrome (i.e., the name has more than two alphabets of an odd count).
		 */
		if (0 <= odd) {
			printf("I'm Sorry Hansoo");
			return 0;
		}
		
		odd = i;
	}
	
	/*
	 * Since the name can be made into a palindrome, print the alphabetically first made palindrome.
	 */
	for (int i = 0; i < 26; i++) {
		for (int j = 1; j <= a[i] / 2; j++) {
			printf("%c",i + 'A');
		}
	}
	if (0 <= odd) {
		printf("%c", odd + 'A');
	}
	for (int i = 25; i >= 0; i--) {
		for (int j = 1; j <= a[i] / 2; j++) {
			printf("%c", i + 'A');
		}
	}
	
	return 0;
}
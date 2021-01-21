#include <bits/stdc++.h>
using namespace std;

int N1, N2, T;
char a[27];											// An array for alphabets.
int b[27];											// An array for indicators that tell which alphabets to swap.

int main() {
	scanf("%d%d", &N1, &N2);
	
	scanf("%s", a + 1);
	reverse(a + 1, a + N1 + 1);
	fill(b + 1, b + N1 + 1, 1);
	
	scanf("%s",a + N1 + 1);
	
	scanf("%d", &T);
	
	while (T--) {
		for (int i = 1; i <= N1 + N2 - 1; i++) {
			if (1 == b[i] && 0 == b[i + 1]) {		// Set needs to be swapped.
				swap(b[i], b[i + 1]);				// Swap indicators.
				swap(a[i], a[i + 1]);				// Swap alphabets.
				i++;								// Check the next set.
			}
			else {									// Set does not need to be swapped.
													// Do nothing (leave as is).
			}
		}
	}
	
	printf("%s\n", a + 1);
	return 0;
}

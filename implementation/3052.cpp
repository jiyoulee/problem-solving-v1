#include <bits/stdc++.h>
using namespace std;

int A, ans;
bool locked[42];

/*
 * For handling duplicates,
 * 1. If the expected total number of results is below 10^9, create a boolean array and do a list check off.
 * 2. Otherwise, create a vector, push results to it, sort it, then run unique and resize.
 */
int main() {
	for (int i = 1; i <= 10; i++) {
		scanf("%d", &A);
		A %= 42;
		
		if (locked[A]) {
			continue;
		}
		
		locked[A] = true;
		ans++;
	}
	
	printf("%d", ans);
	
	return 0;
}
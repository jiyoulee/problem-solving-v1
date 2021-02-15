#include <bits/stdc++.h>
using namespace std;

int a[10];
int locked[10];
int r1, r2, r3, c1, c2, c3, d1, d2;
int ans = INT_MAX;

bool is_magic_square() {
	if (a[1]+a[2]+a[3]!=15) return false;
	if (a[4]+a[5]+a[6]!=15) return false;
	if (a[7]+a[8]+a[9]!=15) return false;
	if (a[1]+a[4]+a[7]!=15) return false;
	if (a[2]+a[5]+a[8]!=15) return false;
	if (a[3]+a[6]+a[9]!=15) return false;
	if (a[1]+a[5]+a[9]!=15) return false;
	if (a[3]+a[5]+a[7]!=15) return false;
	return true;
}

void track(int l, int cost) { // Do brute force search on permunation of 3x3 squares.
	// 1. Do something: check for magic square.
	if (is_magic_square()) ans = min(ans, cost);
	
	/* 
	 * If count is full (i.e. all numbers have been considered for manipulation),
	 * 2. Return.
	 */ 
	if (10 == l) return;

	int n = a[l];

	/*
	 * Else,
	 * 2. Explore subtree.
	 */
	for (int i = 1;i <= 9; i++) {
		if (!locked[i]) {
			a[l] = i;
			
			// (1. Lock after selecting a child.)
			locked[i] = true;
			
			
			track(l + 1, cost + abs(n - i));
			
			// (3. Unlock after returning from a child.)
			a[l]=n;
			locked[i] = false;
		}
	}

	return;
}

int main() {
	for (int i = 1; i <= 9; i++) {
		scanf("%d", a + i);
	}
	
	track(1, 0);
	
	printf("%d", ans);
	
	return 0;
}

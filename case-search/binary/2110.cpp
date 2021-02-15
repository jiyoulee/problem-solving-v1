#include <bits/stdc++.h>
using namespace std;

int N, C;
int a[200001];

bool good(int x) { // x is the minimum value of the distance between two adjacent router-installed locations, given a list of router-installed locations.
	int n = 1;
	int	cnt = 0;
	
	while (1) {
		int space = x;
		
		while (n <= (N - 1) && 0 < space) {
			space -= (a[n+1] - a[n]);
			n++;
		}
		
		if (n > (N - 1) && 0 < space) {			// All distance between two adjacent router-installed locations have been taken into account, and the last space is less than x.
												// Do not take the last space into account.
			break;
		}
		else if (n > (N - 1) && 0 >= space) {	// All distance between two adjacent router-installed locations have been taken into account, and the last space is greater than or equal to x.
			cnt++;								// Take the last space into account.
			break;
		}
		else {									// Some distance between two adjacent router-installed locations have yet to be taken into account.
			cnt++;
		}
	}
	
	return cnt >= C - 1;
}

int main() {
	scanf("%d%d", &N, &C);
	for (int i = 1; i <= N; i++) {
		scanf("%d", a + i);
	}

	// Since locations are not given in order, sort to find distance between directly adjacent locations.
	sort(a + 1, a + 1 + N);
	
	// Do binary search (l oooxxx r).
	int l = 1;
	int r = 1e9;
	int h;
	while (l <= r) {
		h = (l + r) / 2;
		if (good(h)) {
			l = h + 1;
		}
		else {
			r = h - 1;
		}
	}
	
	printf("%d", r);
	
	return 0;
}
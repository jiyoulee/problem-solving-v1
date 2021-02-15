#include <bits/stdc++.h>
using namespace std;

int N, M;
int a[100001];

/*
 * If after all the lessons have been successfully recorded, the total number of disks used is less than M, returns true.
 */
bool good(int x) { // x is the size of one disk.
	int n = 1;
	int cnt = 0;
	
	while (n <= N) {
		if (x < a[n]) {
			break;
		}
		
		int size = x;
		while (size - a[n] >= 0) {
			size -= a[n++];
		}
		cnt++;
	}
	
	return n > N && cnt <= M;
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%d", a + i);
	}
		
	// Do binary search (l xxxooo r).
	int l = 0;
	int r = 1e9;
	int h;
	while (l <= r) {
		h = (l + r) / 2;
		if (good(h)) {
			r = h - 1;
		}
		else {
			l = h + 1;
		}
	}
	
	printf("%d", l);
	
	return 0;
}
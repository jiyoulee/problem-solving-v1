#include <bits/stdc++.h>
using namespace std;

int N, L, cnt=1;
float endpoint;
int a[1002];

int main() {
	scanf("%d%d", &N, &L);
	for (int i = 1; i <= N; i++) {
		scanf("%d", a + i);
	}
	
	/*
	 * Minimizing the number of tapes used is equivalent to maximazing the use of each tape used.
	 * 1. The maximum use of a tape is possible iff taping is started at -0.5 of the first uncovered node at the time.
	 */
	sort(a + 1, a + 1 + N);
	endpoint = a[1] - 0.5 + L;
	for (int i = 1; i <= N; i++) {
		if (a[i] + 0.5 > endpoint) {
			cnt++;
			endpoint = a[i] - 0.5 + L;
		}
	}
	
	printf("%d", cnt);
	
	return 0;
}
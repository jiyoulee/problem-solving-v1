#include <bits/stdc++.h>
using namespace std;

int N, M, Hi, ans;

/*
 * 1. Given the starting dates of the N schedules, the total amount of melancholy felt is fixed.
 * 2. The maximum total amount of melancholy felt is the total amount of melancholy felt when the N schedules are distributed as "evenly" as possible (i.e. when the lengths of each consecutive days melancholy is felt is as similiar to each other as possible).
 */
int main() {
	scanf("%d%d", &N, &M);
	
	for (int i = 1; i <= N; i++) {
		scanf("%d", &Hi);
		M -= (Hi + 1);
	}
	
	if (M <= 0) {
		printf("0");
		
		return 0;
	}
	else {
		int q = M / (N + 1);
		int r = M % (N + 1);
		
		for (int i = 1; i <= q; i++) {
			ans += i * i * (N + 1);
		}
		ans += (q + 1) * (q + 1) * r;
		
		printf("%d", ans);
		
		return 0;
	}
}
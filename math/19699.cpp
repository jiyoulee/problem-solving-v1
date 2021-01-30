#include <bits/stdc++.h>
using namespace std;

int N, M, sum, vlen;
int a[10];
bool locked[9001];
vector<int> v;

void track(int l, int n) { // Do brute force search on combination of M weights of cows.
	/* If level is maximum (i.e. M weights of cows have been added to form the sum),
	 * 1. Do something: validate, and if needed record, sum.
	 * 2. Return.
	 */
	if (M == l) {
		if (!locked[sum]) {
			v.push_back(sum);
		}
		
		return;
	}
	
	/*
	 * Else,
	 * 2. Explore subtree.
	 */
	for (int i = n + 1; i <= N; i++) {
		sum += a[i];
		track(l + 1, i);
		sum -= a[i];
	}
	
	return;
}

int main() {
	/*
	 * Find all prime numbers up to and including maximum possible sum of weight of cows.
	 */
	locked[0] = 1;
	locked[1] = 1;
	for (int i = 2; i * i <= 9000; i++) {
		if (!locked[i]) {
			for (int j = i * i; j <= 9000; j += i) {
				if (!locked[j]) {
					locked[j] = 1;
				}
			}
		}
	}

	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%d", a + i);
	}
	
	/*
	 * Find all sum of weight of cows that are prime numbers.
	 */
	track(0, 0);
	
	/*
	 * If no sum of weight of cows that are prime numbers are found, log -1.
	 * Otherwise, log sum of weight of cows in increasing order.
	 */
	if (v.empty()) {
		printf("-1");
	}
	else {
		sort(v.begin(), v.end());
		
		printf("%d ", v[0]);
		vlen = v.size();
		for (int i = 1; i < vlen; i++) {
			if (v[i] != v[i - 1]) {
				printf("%d ", v[i]);
			}
		}
	}
	
	return 0;
}
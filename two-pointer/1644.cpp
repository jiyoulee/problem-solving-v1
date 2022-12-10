#include <bits/stdc++.h>
using namespace std;

int N, l, r, sum, ans, vlen;
bool locked[4000001];
vector<int> v;

int main() {
	scanf("%d", &N);

	/*
	 * Find prime numbers.
	 */
	for (int i = 2; i * i <= N; i++) {
		if (!locked[i]) {
			for (int j = 2 * i; j <= N; j += i) {
				locked[j] = true;
			}
		}
	}
	for (int i = 2; i <= N; i++) {
		if (!locked[i]) {
			v.push_back(i);
		}
	}

	/*
	 * Initialize.
	 */
	l = 0;
	r = 0;
	sum = v[0];
	vlen = v.size();
	v.resize(N + 1);								// Cf. Two pointer search requires array overflow consideration due to while loop end condition (i.e., r).
	
	/*
	 * Search.
	 */
	while (r < vlen) {
		if (N == sum) {
			ans++;
		}

		if (N >= sum) {
			sum += v[++r];
		}
		else {
			sum -= v[l++];
		}
	}

	printf("%d", ans);

	return 0;
}
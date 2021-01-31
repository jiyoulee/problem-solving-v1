#include <bits/stdc++.h>
using namespace std;

int K, N, n, alen, good;
tuple<int,int,int> a[21];
vector<int> v;

int main() {
	scanf("%d%d", &K, &N);
	
	/*
	 * Count initial vote.
	 */
	scanf("%d", &n);
	a[1] = (make_tuple(1, 1, n));
	alen = 1;
	
	/*
	 * Carry on counting votes.
	 */
	for (int i = 2; i <= N; i++) {
		scanf("%d", &n);
		
		for (int i = 1; i <= alen; i++) {
			if (get<2>(a[i]) == n) {												// The picture of candidate #n has already been posted.
				a[i] = make_tuple(get<0>(a[i]) + 1, get<1>(a[i]), get<2>(a[i]));
				good = true;
				break;
			}
		}
		
		if (!good) {																// The picture of candidate #n must be posted, and...
			if (K <= alen) {														// all picture frames are already occupied.
				sort(a + 1, a + K + 1);
				a[1] = (make_tuple(1, i, n));
			}
			else {																	// at least one picture frame is not occupied.
				a[++alen] = (make_tuple(1, i, n));
			}
		}
		else {																		// (Reset global variables.)
			good = false;
		}
	}

	/*
	 * Log final candidates in increasing order.
	 */
	for (int i = 1; i <= alen; i++) {
		v.push_back(get<2>(a[i]));
	}
	sort(v.begin(), v.end());
	for (int e : v) {
		printf("%d ", e);
	}
	
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define UPPER_BOUND 15

int N, ans;
/*
 * When dealing with diagonals, always think 0-based.
 * locked[1]: column
 * locked[2]: diagonal starting at lower left and ending at upper right.
 * locked[3]: diagonal starting at upper left and ending at lower right.
 */
int locked[3][2 * UPPER_BOUND];

/*
 * Implemented using DFS on tree.
 * Therefore, one does not need to worry about "keys", but only "locks".
 */
void track(int v, int h, int cnt) {	// Do brute force search on combination of queen locations.
	/* If count is full (i.e. all queens have been placed),
	 * 1. Do something: record.
	 * 2. Return.
	 */
	if (N == cnt) {
		ans++;
		return;
	}

	/*
	 * Else,
	 * (1. Lock.)
	 * 2. Explore subtree.
	 * (3. Unlock.)
	 */
	locked[0][h] = true;
	locked[1][v+h] = true;
	locked[2][v-h+N-1] = true;

	for (int nh = 0; nh < N; nh++) {
		if (!locked[0][nh] && !locked[1][v + 1 + nh] && !locked[2][v + 1 - nh + N - 1]) {
			track(v + 1, nh, cnt + 1);
		}
	}

	locked[0][h] = false;
	locked[1][v + h] = false;
	locked[2][v - h + N - 1] = false;

	return;
}

int main() {
	scanf("%d", &N);
	
	for (int h = 0; h < N; h++) {	// Because there are N queens and N rows, exactly one queen must be placed per row. (This fact allows for escaping redundancies.)
		track(0, h, 1);
	}
	
	printf("%d", ans);
	
	return 0;
}
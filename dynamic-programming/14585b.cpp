#include <bits/stdc++.h>
using namespace std;

int N, M, candy;
vector<pair<int,int>> v;
int m[301]; // m[i] is the largest possible number of candy that can be eaten after traveling up to and including v[i].

int main() {
	scanf("%d %d", &N, &M);
	v.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		scanf("%d%d", &v[i].first, &v[i].second);
	}
	
	sort(v.begin(), v.end());
	
	// Create base (not needed because m is global array).
	
	// Update and memo (multiple options).
	for (int i = 1; i < N + 1; i++) {
		// Initialize (not needed because m is global array).
		
		// Update and memo.
		candy = M - v[i].first - v[i].second;
		for (int j = 0; j < i; j++) {
			if (v[i].second >= v[j].second) {
				m[i] = max(m[i], m[j]+candy);
			}
		}
	}
	
	printf("%d", *max_element(m, m + N + 1));
	
	return 0;
}
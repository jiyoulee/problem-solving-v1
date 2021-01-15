#include <bits/stdc++.h>
using namespace std;

int N, s, e, ans = 1;
vector<pair<int,int>> v;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &s, &e);
		v.push_back(make_pair(e, s));
	}
	
	/*
	 * 1. Scheduling should happen at the earliest moment possible (i.e. at the moment each meeting ends).
	 * 2. When scheduling is possible, the meeting with the earliest end time must be scheduled.
	 */
	 
	// Sort in meeting end time descending order.
	sort(v.begin(), v.end(), greater<pair<int,int>>());
	
	// Initialize.
	s = v.back().second;
	e = v.back().first;
	if (e == s) ans = 0;
	
	while (1) {						// v.back() is the meeting currently being considered for scheduling.
		if (e <= s) {				// Scheduling can, and should be done.
			ans++;
			e = v.back().first;
			v.pop_back();
			if (v.empty()) {
				break;
			}
			s = v.back().second;
		}
		else {						// Scheduling cannot be done.
			v.pop_back();
			if (v.empty()) {
				break;
			}
			s = v.back().second;
		}
	}
	
	printf("%d", ans);
	
	return 0;
}

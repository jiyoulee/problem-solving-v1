#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int row_number, standing_number, ans=0;
int d[100001];
int h[100001];
int cnt[100001];

struct cmp {
	/*
	 * If second argument is parent and first argument is child, returns true.
	 */
	bool operator()(tuple<int,int,int,int> t1, tuple<int,int,int,int> t2) {
		if (get<0>(t1) != get<0>(t2)) {		// D(t1) and D(t2) are different.
			return get<0>(t1) < get<0>(t2);
		}
		if (get<1>(t1) != get<1>(t2)) {		// D(t1) and D(t2) are same, but H(t1) and H(t2) are different.
			return get<1>(t1) < get<1>(t2);
		}
		return get<2>(t1) > get<2>(t2);		// D(t1) and D(t2) are same, and H(t1) and H(t2) are same.
	}
};

int main() {
	priority_queue<tuple<int,int,int,int>, vector<tuple<int,int,int,int>>, cmp> leaders;
	// Element: (D, H, row number, standing number)
	
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%d%d", d + i, h + i);
	}
	for (int i = 1; i <= N && i <= M; i++) {
		leaders.push(make_tuple(d[i], h[i], i, i));
		cnt[i]++;
	}
	
	while ((K + 1) != get<3>(leaders.top())) {
		row_number = get<2>(leaders.top());
		leaders.pop();
		standing_number = cnt[row_number] * M + row_number;
		if (standing_number <= N) {
			leaders.push(make_tuple(d[standing_number], h[standing_number], row_number, standing_number));
			cnt[row_number]++;
		}
		ans++;
	}
	
	printf("%d",ans);
	
	return 0;
}
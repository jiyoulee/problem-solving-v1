#include <bits/stdc++.h>
using namespace std;

int N, idx, Ml, Mr, ans;
int a[258];
bool locked[258];
vector<pair<int,int>> v;

int main() {
	scanf("%d", &N);
	locked[0] = true;
	locked[N + 1] = true;
	for (int i = 1; i <= N; i++) {
		scanf("%d", a + i);
		v.push_back(make_pair(a[i], i));
	}
	sort(v.begin(), v.end());
	
	for (auto e: v) {
		Ml = N + 1;
		Mr = N + 1;
		
		idx = e.second;
		for (int i = idx - 1; !locked[i]; i--) {
			Ml = min(Ml, a[i]);
		}
		for (int i = idx + 1; !locked[i]; i++) {
			Mr = min(Mr, a[i]);
		}
		if (N + 1 > Ml && N + 1 == Mr) {
			ans += Ml - a[idx];
		}
		else if (N + 1 == Ml && N + 1 > Mr) {
			ans += Mr - a[idx];
		}
		else if (N + 1 > Ml && N + 1 > Mr) {
			ans += Ml + Mr - 2*a[idx];
		}
		locked[idx] = true;
	}
	
	printf("%d", ans);
	
	return 0;
}
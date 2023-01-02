#include <bits/stdc++.h>
using namespace std;

int N, sum, ans;
vector<int> v;

int main() {
	scanf("%d", &N);
	
	v.push_back(1);
	do {
		v.push_back(v[ans] + 6 * ans);	// Calculate prefix-sum.
	} while (N > v[++ans]);

	printf("%d", ans);
	
	return 0;
}
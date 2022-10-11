#include <bits/stdc++.h>
using namespace std;

int N, n;
int a[500001];
vector<int> v;

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", a + i);
	}
	
	/*
	 * Stack can ensure...
	 * 1. O(N)
	 * 2. All previous elements are in non increasing order.
	 */
	for (int i = 1; i <= N; i++) {
		while (!v.empty() && a[v.back()] < a[i]) {
			v.pop_back();
		}
		
		if (v.empty()) {
			printf("0 ");
		}
		else {
			printf("%d ", v.back());
		}
		
		v.push_back(i);
	}
	
	return 0;
}
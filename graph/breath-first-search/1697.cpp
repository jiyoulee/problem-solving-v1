#include <bits/stdc++.h>
using namespace std;

int N, n, K;
int a[100001];
int key[100001];
queue<int> q;

int main() {
	scanf("%d%d", &N, &K);
	
	key[N] = true;								// Acquire key to starting node.
	q.push(N);									// Queue key.
	
	while (!q.empty()) {
		n = q.front();							// Access node using key.
		q.pop();
		if (K == n) {
			break;
		}
		
		if (!key[n - 1] && 0 <= n - 1) {		// Acquire keys to child nodes and queue them.
			key[n - 1] = true;
			a[n - 1] = a[n] + 1;
			q.push(n - 1);
		}
		if (!key[n + 1] && 100000 >= n + 1) {
			key[n + 1] = true;
			a[n + 1] = a[n] + 1;
			q.push(n + 1);
		}
		if (!key[n * 2] && 100000 >= n * 2) {
			key[n * 2] = true;
			a[n * 2] = a[n] + 1;
			q.push(n * 2);
		}
	}
	
	printf("%d", a[K]);
	
	return 0;
}
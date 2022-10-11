#include <bits/stdc++.h>
using namespace std;

int N, x;
priority_queue<int> pq;

int main() {
	scanf("%d", &N);
	
	while (N--) {
		scanf("%d", &x);
		
		if (0 == x) {
			if (pq.empty()) {				// x is 0 and priority queue is empty.
				printf("0\n");
			}
			else {							// x is 0 and priority queue is not empty.
				printf("%d\n", pq.top());
				pq.pop();
			}
		}
		else {								// x is not 0.
			pq.push(x);
		}
	}
	
	return 0;
}
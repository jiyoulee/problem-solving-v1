#include <bits/stdc++.h>
using namespace std;

int N,tmp;
priority_queue<int> pq;

int main() {
	scanf("%d", &N);
	
	while (N--) {
		scanf("%d", &tmp);
		
		if (0 == tmp) {
			if (pq.empty()) {				// Input is 0 and priority queue is empty.
				printf("0\n");
			}
			else {
				printf("%d\n", pq.top());	// Input is 0 and priority queue is not empty.
				pq.pop();
			}
		}
		else {								// Input is not 0.
			pq.push(tmp);
		}
	}
	
	return 0;
}
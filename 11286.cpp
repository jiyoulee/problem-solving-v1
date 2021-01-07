#include <bits/stdc++.h>
using namespace std;

int N, x;
priority_queue<int> max_pq;								// Maximum priority queue for negative integers.
priority_queue<int,vector<int>,greater<int>> min_pq;	// Minimum priority queue for positive integers. 

int main() {
	scanf("%d", &N);
	
	while (N--) {
		scanf("%d", &x);
		
		if (0 == x) {									// Print.
			if (max_pq.empty() && min_pq.empty()) {		// Both priorities queues are empty.
				printf("0\n");
			}
			else if (max_pq.empty() || (!max_pq.empty() && !min_pq.empty() && abs(max_pq.top()) > min_pq.top())) {
														// No negative integers in the "array".
														// or
														// Value of smallest positive integer is less than absolute value of largest negative integer. 
				printf("%d\n", min_pq.top());
				min_pq.pop();
			}
			else if (min_pq.empty() || (!max_pq.empty() && !min_pq.empty() && abs(max_pq.top()) <= min_pq.top())) {
														// No positive integers in the "array".
														// or
														// Absolute value of largest negative integer is less than the value of smallest positive integer.
														// or
														// Absolute value the two integers are the same.
				printf("%d\n", max_pq.top());
				max_pq.pop();
			}
			else {
														// Do nothing.
			}
		}
		else {											// Push.
			if (0<x) {
				min_pq.push(x);
			}
			else {
				max_pq.push(x);
			}
		}
	}
	
	return 0;
}
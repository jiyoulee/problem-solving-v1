#include <bits/stdc++.h>
using namespace std;

int N,idx;
int t[1500001];
int p[1500001];
int m[1500001]; // m[i] is the most optimized schedule taking into consideration from the nth day down to (and including) the ith day.

int main() {
	scanf("%d",&N);
	for (int i=1;i<=N;i++) {scanf("%d",t+i); scanf("%d",p+i);}
	
	// Create base.
	for (idx=N;idx>=1;idx--) {
		if ((N+1)>=(idx+t[idx])) {m[idx]=p[idx]; break;}
	}
	
	// Update and memo (single option + multiple option).
	for (int i=idx-1;i>=1;i--) {
		if ((N+1)<(i+t[i])) m[i]=m[i+1];
		else m[i]=max(m[i+1],p[i]+m[i+t[i]]);
	}
	
	printf("%d",m[1]);
	
	return 0;
}
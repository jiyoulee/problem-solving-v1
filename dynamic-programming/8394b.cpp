#include <bits/stdc++.h>
using namespace std;

int n;
int m[10000001]; // m[i] is the number of possible ways to handshake between people up to (and including) the ith person.

int main() {
	scanf("%d",&n);
	
	// Create base.
	m[1]=1;
	m[2]=2;

	// Update and memo (single option).
	for (int i=3;i<=n;i++) {
		m[i]=(m[i-2]+m[i-1])%10;
	}
	
	printf("%d",m[n]);
	
	return 0;
}
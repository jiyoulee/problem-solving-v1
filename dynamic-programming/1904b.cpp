#include <bits/stdc++.h>
using namespace std;

int n;
int m[1000000]; // m[i] is the number possible of numbers of length i.

int main() {
	scanf("%d",&n);
	
	// Create base.
	m[1]=1;
	m[2]=2;
	
	// Update and memo (single option).
	for (int i=3;i<=n;i++) {
		m[i]=(m[i-2]+m[i-1])%15746;
	}
	
	printf("%d",m[n]);
	
	return 0;
}